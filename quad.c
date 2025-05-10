#include <stdio.h>
#include <stdlib.h>
#define LIST_IMPLEMENT
#include "quad.h"
#undef LIST_IMPLEMENT
// location doesn't work at this point since we've already parsed the file and forgotten about it
// #include "location.h"
#include "parser.tab.h"
#include "errorf.h"

void generate_quads(ast_node_t *statement);
ast_node_t *generate_rvalue(ast_node_t *node, ast_node_t *target);
ast_node_t *generate_lvalue(ast_node_t *node, char *is_direct);
ast_node_t *generate_assignment(ast_node_t *node);
ast_node_t *generate_compound_assignment(ast_node_t *node, int kind);
ast_node_t *generate_function_call(ast_node_t *node, ast_node_t *target);
ast_node_t *generate_sizeof(ast_node_t *node, ast_node_t *target);
ast_node_t *generate_if_statement(ast_node_t *statement);
ast_node_t *generate_while_statement(ast_node_t *statement);
ast_node_t *generate_for_statement(ast_node_t *statement);

static unsigned long temp_var_counter = 0;

ast_node_t *new_temp_var()
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_TEMPORARY;
    new_inst->temporary.num = temp_var_counter++;
    new_inst->temporary.isa = 0;
    return new_inst;
}

ast_node_t *new_immediate(int n)
{
    return ast_new_numberlit((number_t){.integer = n});
}

bquad_t *new_quad(bquad_t quad)
{
    bquad_t *new_inst = malloc(sizeof(bquad_t));
    *new_inst = quad;
    return new_inst;
}

struct jump_metadata
{
    basic_block_t *continue_quads;
    basic_block_t *break_quads;
};

struct jump_metadata *new_jump_metadata(void)
{
    struct jump_metadata *new_inst = malloc(sizeof(struct jump_metadata));
    new_inst->break_quads = basic_block_new();
    new_inst->continue_quads = basic_block_new();
    return new_inst;
}

void add_continue_metadata(struct jump_metadata *data, bquad_t *ref)
{
    basic_block_add(data->continue_quads, ref);
}

void add_break_metadata(struct jump_metadata *data, bquad_t *ref)
{
    basic_block_add(data->break_quads, ref);
}

void free_jump_metadata(struct jump_metadata *data)
{
    basic_block_free(data->break_quads);
    basic_block_free(data->continue_quads);
    free(data);
}

void resolve_break_metadata(struct jump_metadata *data, int jump_target)
{
    ENUMERATE(data->break_quads, i, {
        data->break_quads->items[i]->jump_target = jump_target;
    });
}

void resolve_continue_metadata(struct jump_metadata *data, int jump_target)
{
    ENUMERATE(data->continue_quads, i, {
        data->continue_quads->items[i]->jump_target = jump_target;
    });    
}

static int current_block_index = 0;
static basic_block_list_t *current_function = 0;

// begins a new function
void begin_new_function(void)
{
    if (current_function)
    {
        errorf("there is already an available function");
    }

    current_function = basic_block_list_new();
    basic_block_list_add(current_function, basic_block_new());
    current_block_index = 0;
}

// adds a new basic block to the current function
void add_new_basic_block_to_function(void)
{
    if (!current_function)
    {
        errorf("there is no available function");
    }

    basic_block_list_add(current_function, basic_block_new());
    current_block_index++;
}

// emits a new quad to a basic block
// prev == 0: emit to latest created block
// prev < 0: emit to previous created blocks
// returns a pointer to the emitted quad
bquad_t *emit(int prev, ast_node_t *dest, enum quad_op op, void *arg1, void *arg2, int jump_target)
{
    if (!current_function)
    {
        errorf("there is no available basic block");
    }

    if (prev > 0 || current_block_index + prev < 0)
    {
        errorf("cannot emit quad to block at index %d", prev);
    }
    bquad_t *q;
    if (op >= JP)
    {
        q = new_quad((bquad_t){
            .dest = 0,
            .op = op,
            .jump_target = jump_target,
            .arg2 = 0,
        });
    }
    else
    {
        q = new_quad((bquad_t){
            .dest = dest,
            .op = op,
            .arg1 = arg1,
            .arg2 = arg2,
        });
    }
    basic_block_add(current_function->items[current_block_index + prev], q);
    if (op == RET)
        current_function->items[current_block_index + prev]->is_exit = 1;

    return q;
}

// returns the finished function
basic_block_list_t *end_function(void)
{
    if (!current_function)
    {
        errorf("there is no available function");
    }
    if (!current_function->items[current_block_index]->is_exit)
    {
        emit(0, 0, RET, 0, 0, 0);
    }
    basic_block_list_t *temp = current_function;
    current_function = 0;
    return temp;
}

// * Generate quads entrypoint
basic_block_list_t *generate_function_quads(ast_node_t *compound)
{
    if (compound->kind != AST_COMPOUND)
    {
        errorf("generate_function_quads requires a compound statement");
    }

    begin_new_function();
    generate_quads(compound);
    return end_function();
}

void generate_quads(ast_node_t *statement)
{
    ast_node_t *target;
    bquad_t *q;
    switch (statement->kind)
    {
    case AST_EXPRESSION:
        if (statement->expression_statement.expression)
            target = generate_rvalue(statement->expression_statement.expression, 0);
        break;
    case AST_COMPOUND:
        ENUMERATE(statement->compound_statement.sub_statements, i, {
            generate_quads(statement->compound_statement.sub_statements->items[i]);
        });
        break;
    case AST_IF:
        generate_if_statement(statement);
        break;
    case AST_WHILE:
    case AST_DO_WHILE:
        generate_while_statement(statement);
        break;
    case AST_FOR:
        generate_for_statement(statement);
        break;
    case AST_CONTINUE:
        q = emit(0, 0, JP, 0, 0, -1);
        add_continue_metadata(statement->continue_statement.association->extra, q);
        add_new_basic_block_to_function();
        break;
    case AST_BREAK:
        q = emit(0, 0, JP, 0, 0, -2);
        add_break_metadata(statement->continue_statement.association->extra, q);
        add_new_basic_block_to_function();
        break;
    case AST_RETURN:
        emit(0, 0, RET, generate_rvalue(statement->return_statement.expression, 0), 0, 0);
        break;
    default:
        errorf("can't generate quads for statement of kind %d", statement->kind);
        break;
    }
}

// Return value is the destination node. i.e. whatever variable the result of the node would be placed in.
// If target is NULL, we are expected to create a temporary
ast_node_t *generate_rvalue(ast_node_t *node, ast_node_t *target)
{
    ast_node_t *t1;
    ast_node_t *t2;
    ast_node_t *t3;

#define T        \
    if (!target) \
    target = new_temp_var()

#define UN(op)                                                                 \
    do                                                                         \
    {                                                                          \
        T;                                                                     \
        emit(0, target, op, generate_rvalue(node->unary_op.operand, 0), 0, 0); \
        return target;                                                         \
    } while (0)

#define BIN(op)                                         \
    do                                                  \
    {                                                   \
        T;                                              \
        t1 = generate_rvalue(node->binary_op.left, 0);  \
        t2 = generate_rvalue(node->binary_op.right, 0); \
        emit(0, target, op, t1, t2, 0);                 \
        return target;                                  \
    } while (0)

#define BIN_COMPARE(op, predicate, value)                     \
    do                                                        \
    {                                                         \
        T;                                                    \
        emit(0, target, MOV, new_immediate(predicate), 0, 0); \
        t1 = generate_rvalue(node->binary_op.left, 0);        \
        t2 = generate_rvalue(node->binary_op.right, 0);       \
        emit(0, 0, CMP, t1, t2, 0);                           \
        emit(0, target, op, new_immediate(value), 0, 0);      \
        return target;                                        \
    } while (0)

    switch (node->kind)
    {
    case AST_IDENT:
        errorf("unresolved identifier");

    case AST_VARIABLE:
        if (node->variable.isa->kind == AST_ARRAY)
        {
            T;
            emit(0, target, LEA, node, 0, 0);
            if (target->kind == AST_TEMPORARY)
                ;
            {
                target->temporary.isa = ast_new_pointer(0);
                target->temporary.isa->pointer.to = node->next->next;
            }
            return target;
        }
        else
            return node;

    case AST_NUMBERLIT:
        if (node->numberlit.type.full & TS_REAL)
        {
            errorf("real number literals are not supported");
        }
        return node;

    case AST_BINARY_OP:
        switch (node->binary_op.kind)
        {
        case PLUSEQ:
            return generate_compound_assignment(node, ADD);
        case MINUSEQ:
            return generate_compound_assignment(node, SUB);
        case TIMESEQ:
            return generate_compound_assignment(node, MUL);
        case DIVEQ:
            return generate_compound_assignment(node, DIV);
        case MODEQ:
            return generate_compound_assignment(node, MOD);
        case SHLEQ:
            return generate_compound_assignment(node, SL);
        case SHREQ:
            return generate_compound_assignment(node, SR);
        case ANDEQ:
            return generate_compound_assignment(node, AND);
        case XOREQ:
            return generate_compound_assignment(node, XOR);
        case OREQ:
            return generate_compound_assignment(node, OR);
        case '=':
            return generate_assignment(node);
        case '*':
            BIN(MUL);
        case '/':
            BIN(DIV);
        case '%':
            BIN(MOD);

        // There definitly a better way to do this pointer arithmetic stuff
        case '+':

            T;
            t1 = generate_rvalue(node->binary_op.left, 0);
            t2 = generate_rvalue(node->binary_op.right, 0);

            // check for temp values and variables that are pointers
            if ((t1->kind == AST_TEMPORARY || t1->kind == AST_VARIABLE) && t1->next && t1->next->kind == AST_POINTER)
            {
                if ((t2->kind == AST_TEMPORARY || t2->kind == AST_VARIABLE) && t2->next && t2->next->kind == AST_POINTER)
                {
                    errorf("pointer + pointer not allowed");
                }

                t3 = new_temp_var();
                emit(0, t3, MUL, t2, new_immediate((int)ast_get_sizeof_value(t1->next->next)), 0);
                emit(0, target, ADD, t1, t3, 0);
                if (target->kind == AST_TEMPORARY)
                    target->next = t1->next;
                return target;
            }

            if ((t2->kind == AST_TEMPORARY || t2->kind == AST_VARIABLE) && t2->next && t2->next->kind == AST_POINTER)
            {
                t3 = new_temp_var();
                emit(0, 0, MUL, t1, new_immediate((int)ast_get_sizeof_value(t2->next->next)), 0);
                emit(0, target, ADD, t3, t2, 0);
                if (target->kind == AST_TEMPORARY)
                    target->next = t1->next;
                return target;
            }

            emit(0, target, ADD, t1, t2, 0);
            return target;

        case '-':
            T;
            t1 = generate_rvalue(node->binary_op.left, 0);
            t2 = generate_rvalue(node->binary_op.right, 0);

            // check for temp values and variables that are pointers
            if ((t1->kind == AST_TEMPORARY || t1->kind == AST_VARIABLE) && t1->next && t1->next->kind == AST_POINTER)
            {
                if ((t2->kind == AST_TEMPORARY || t2->kind == AST_VARIABLE) && t2->next && t2->next->kind == AST_POINTER)
                {
                    int size1 = (int)ast_get_sizeof_value(t1->next->next);
                    int size2 = (int)ast_get_sizeof_value(t2->next->next);
                    if (size1 != size2)
                    {
                        errorf("pointer - pointer incompatible sizes");
                    }
                    t3 = new_temp_var();
                    emit(0, t3, SUB, t1, t2, 0);
                    emit(0, target, DIV, t3, new_immediate(size1), 0);
                    return target;
                }

                t3 = new_temp_var();
                emit(0, t3, MUL, t2, new_immediate((int)ast_get_sizeof_value(t1->next->next)), 0);
                emit(0, target, SUB, t1, t3, 0);
                if (target->kind == AST_TEMPORARY)
                    target->next = t1->next;
                return target;
            }

            if ((t2->kind == AST_TEMPORARY || t2->kind == AST_VARIABLE) && t2->next && t2->next->kind == AST_POINTER)
            {
                t3 = new_temp_var();
                emit(0, 0, MUL, t1, new_immediate((int)ast_get_sizeof_value(t2->next->next)), 0);
                emit(0, target, SUB, t3, t2, 0);
                if (target->kind == AST_TEMPORARY)
                    target->next = t1->next;
                return target;
            }

            emit(0, target, SUB, t1, t2, 0);
            return target;
        case SHL:
            BIN(SL);
        case SHR:
            BIN(SR);
        case '&':
            BIN(AND);
        case '^':
            BIN(XOR);
        case '|':
            BIN(OR);
        case '<':
            BIN_COMPARE(CMOVM, 0, 1);
        case LTEQ:
            BIN_COMPARE(CMOVP, 1, 0);
        case '>':
            BIN_COMPARE(CMOVP, 0, 1);
        case GTEQ:
            BIN_COMPARE(CMOVM, 1, 0);
        case EQEQ:
            BIN_COMPARE(CMOVZ, 0, 1);
        case NOTEQ:
            BIN_COMPARE(CMOVNZ, 0, 1);

        case LOGAND:
        case LOGOR:
        default:
            errorf("encountered invalid or unsupported binary op kind %d while generating rvalue", node->binary_op.kind);
            break;
        }
        break;

    case AST_UNARY_OP:
        switch (node->unary_op.kind)
        {
        case '*':
            if (node->unary_op.operand->kind == AST_VARIABLE && ast_is_array(node->unary_op.operand))
                return generate_rvalue(node->unary_op.operand, 0);
            T;
            emit(0, target, LOAD, generate_rvalue(node->unary_op.operand, 0), 0, 0);
            return target;
        case '!':
            T;
            emit(0, target, MOV, new_immediate(0), 0, 0);
            emit(0, 0, CMP, generate_rvalue(node->unary_op.operand, 0), new_immediate(0), 0);
            emit(0, target, CMOVZ, new_immediate(1), 0, 0);
            return target;
        case '~':
            UN(CPL);
        case '+':
            // if everything is an int then it doesn't do anything I guess
            return generate_rvalue(node->unary_op.operand, 0);
        case '-':
            UN(NEG);
        case SIZEOF:
            T;
            return generate_sizeof(node->unary_op.operand, target);
        }
        break;
    case AST_FUNCTION_CALL:
        T;
        return generate_function_call(node, target);
    case AST_TYPE_CAST:
    case AST_TERNARY_OP:
    case AST_MEMBER_ACCESS:
    case AST_STRINGLIT:
    default:
        errorf("can't generate quad for node type %d in expression", node->kind);
        break;
    }
}

ast_node_t *generate_assignment(ast_node_t *node)
{
    char is_direct = 0;
    ast_node_t *dest = generate_lvalue(node->binary_op.left, &is_direct);
    ast_node_t *value;
    if (!dest)
    {
        errorf("LHS of assignment is not an lvalue");
    }
    value = generate_rvalue(node->binary_op.right, dest);
    if (is_direct)
    {
        // sometimes generate_rvalue returns just a variable or number literal.
        // in these cases, no operation is emitted that writes to the destination so we have to do it ourselves.
        if (value != dest)
            emit(0, dest, MOV, value, 0, 0);
        return dest;
    }
    else
    {
        emit(0, 0, STORE, dest, value, 0);
        return value;
    }
}

ast_node_t *generate_compound_assignment(ast_node_t *node, int kind)
{
    char is_direct = 0;
    ast_node_t *dest = generate_lvalue(node->binary_op.left, &is_direct);
    ast_node_t *value;
    if (!dest)
    {
        errorf("LHS of assignment is not an lvalue");
    }
    value = generate_rvalue(node->binary_op.right, dest);
    if (is_direct)
    {
        emit(0, dest, kind, dest, value, 0);
        return dest;
    }
    else
    {
        ast_node_t *t1 = new_temp_var();
        ast_node_t *t2 = new_temp_var();
        emit(0, t1, LOAD, dest, 0, 0);
        emit(0, t2, kind, t1, value, 0);
        emit(0, 0, STORE, dest, t2, 0);
        return t2;
    }
}

// Returns a target lvalue variable. Returns 0 if the node cannot become an lvalue
ast_node_t *generate_lvalue(ast_node_t *node, char *is_direct)
{
    switch (node->kind)
    {
    case AST_VARIABLE:
        *is_direct = 1;
        return node;
    case AST_UNARY_OP:
        if (node->unary_op.kind == '*')
        {
            *is_direct = 0;
            ast_node_t *v = generate_rvalue(node->unary_op.operand, 0);
            if (v->kind == AST_NUMBERLIT)
                return 0;
            return v;
        }
    default:
        return 0;
    }
}

ast_node_t *generate_function_call(ast_node_t *node, ast_node_t *target)
{
    ast_node_t *t1;
    if (node->kind != AST_FUNCTION_CALL)
    {
        errorf("wrong node type for generate_function_call %d", node->kind);
    }
    emit(0, 0, ARGBEGIN, 0, 0, 0);
    ENUMERATE(node->function_call.args, i, {
        t1 = generate_rvalue(node->function_call.args->items[i], 0);
        emit(0, 0, ARG, t1, 0, 0);
    });
    emit(0, target, CALL, node->function_call.name, 0, 0);
    return target;
}

ast_node_t *generate_sizeof(ast_node_t *node, ast_node_t *target)
{
    switch (node->kind)
    {
    case AST_TEMPORARY:
    case AST_VARIABLE:
        emit(0, target, MOV, new_immediate((int)ast_get_sizeof_value(node->next)), 0, 0);
        return target;
    case AST_NUMBERLIT:
        emit(0, target, MOV, new_immediate(4), 0, 0);
        return target;
    case AST_BINARY_OP:
    case AST_UNARY_OP:
        generate_rvalue(node, 0);
        return target;
    default:
        errorf("wrong node type for generate_sizeof %d", node->kind);
        break;
    }
}

ast_node_t *generate_if_statement(ast_node_t *statement)
{
    ast_node_t *t1;
    if (statement->kind != AST_IF)
    {
        errorf("wrong node type for generate_if_statement %d", statement->kind);
    }

    if (statement->if_statement.false_branch)
    {
        // leading block
        t1 = generate_rvalue(statement->if_statement.condition, 0);
        emit(0, 0, CMP, t1, new_immediate(0), 0);
        int leading = current_block_index;

        // true block
        add_new_basic_block_to_function();
        generate_quads(statement->if_statement.true_branch);
        int t = current_block_index;

        // false block
        add_new_basic_block_to_function();
        generate_quads(statement->if_statement.false_branch);
        emit(leading - current_block_index, 0, JPZ, 0, 0, current_block_index);

        // trailing block
        add_new_basic_block_to_function();
        emit(t - current_block_index, 0, JP, 0, 0, current_block_index);
    }
    else
    {
        // leading block
        t1 = generate_rvalue(statement->if_statement.condition, 0);
        emit(0, 0, CMP, t1, new_immediate(0), 0);
        int leading = current_block_index;

        // true block
        add_new_basic_block_to_function();
        generate_quads(statement->if_statement.true_branch);

        // trailing block
        add_new_basic_block_to_function();
        emit(leading - current_block_index, 0, JPZ, 0, 0, current_block_index); // add a jump from the leading block to here
    }
}

ast_node_t *generate_while_statement(ast_node_t *statement)
{
    ast_node_t *t1;
    if (!(statement->kind == AST_WHILE || statement->kind == AST_DO_WHILE))
    {
        errorf("wrong node type for generate_while_statement %d", statement->kind);
    }

    // leading block
    int leading = current_block_index;

    // body block
    add_new_basic_block_to_function();
    int body = current_block_index;
    // add metadata struct to while statement so any breaks/continues can add their addresses here
    statement->while_statement.extra = new_jump_metadata();
    generate_quads(statement->while_statement.statement);

    // condition block (continue goes here)
    add_new_basic_block_to_function();
    // resolve continue statements
    resolve_continue_metadata((struct jump_metadata *)statement->while_statement.extra, current_block_index);
    // make the leading block skip to the condition block but only if it's a while loop
    if (statement->kind == AST_WHILE)
        emit(leading - current_block_index, 0, JP, 0, 0, current_block_index);
    t1 = generate_rvalue(statement->while_statement.condition, 0);
    emit(0, 0, CMP, t1, new_immediate(0), 0);
    emit(0, 0, JPNZ, 0, 0, body);

    // trailing block (break goes here)
    add_new_basic_block_to_function();

    // resolve break statements
    resolve_break_metadata((struct jump_metadata *)statement->while_statement.extra, current_block_index);

    free_jump_metadata((struct jump_metadata *)statement->while_statement.extra);
    statement->while_statement.extra = 0;
}

ast_node_t *generate_for_statement(ast_node_t *statement)
{
    ast_node_t *t1;
    if (statement->kind != AST_FOR)
    {
        errorf("wrong node type for generate_for_statement %d", statement->kind);
    }

    // leading block
    int leading = current_block_index;
    generate_rvalue(statement->for_statement.init, 0);

    // body block
    add_new_basic_block_to_function();
    int body = current_block_index;
    statement->for_statement.extra = new_jump_metadata();
    generate_quads(statement->for_statement.statement);

    // increment block (continue goes here)
    add_new_basic_block_to_function();
    // resolve continue statements
    resolve_continue_metadata((struct jump_metadata *)statement->for_statement.extra, current_block_index);
    generate_rvalue(statement->for_statement.final, 0);

    // condition block
    add_new_basic_block_to_function();
    emit(leading - current_block_index, 0, JP, 0, 0, current_block_index);
    t1 = generate_rvalue(statement->for_statement.condition, 0);
    emit(0, 0, CMP, t1, new_immediate(0), 0);
    emit(0, 0, JPNZ, 0, 0, body);

    // trailing block (break goes here)
    add_new_basic_block_to_function();

    // resolve break statements
    resolve_break_metadata((struct jump_metadata *)statement->for_statement.extra, current_block_index);

    free_jump_metadata((struct jump_metadata *)statement->for_statement.extra);
    statement->for_statement.extra = 0;
}

// ## Functions for printing

void print_quad(bquad_t q)
{
    if (q.dest)
    {
        if (q.dest)
        {
            if (q.dest->kind == AST_TEMPORARY)
            {
                if (q.dest->temporary.isa)
                    printf("(%%T%d)", q.dest->temporary.num);
                else
                    printf("%%T%d", q.dest->temporary.num);
            }
            else if (q.dest->kind == AST_VARIABLE)
            {
                printf("%s{ ", q.dest->variable.name);
                print_storage_class(q.dest->variable.storage_class);
                printf("}");
            }
            else
            {
                errorf("invalid quad destination %d", q.dest->kind);
            }
        }
    }

    printf("    ");
    printf("%s", op_names[q.op]);
    printf("    ");

    if (q.arg1)
    {
        if (q.op >= JP)
        {
            printf("BB%d", q.jump_target);
        }
        else
        {
            ast_node_t *arg1 = (ast_node_t *)q.arg1;
            if (arg1->kind == AST_TEMPORARY)
            {
                if (arg1->temporary.isa)
                    printf("(%%T%d)", arg1->temporary.num);
                else
                    printf("%%T%d", arg1->temporary.num);
            }
            else if (arg1->kind == AST_VARIABLE)
            {
                printf("%s{ ", arg1->variable.name);
                print_storage_class(arg1->variable.storage_class);
                printf("}");
            }
            else if (arg1->kind == AST_NUMBERLIT)
            {
                printf("%d", arg1->numberlit.integer);
            }
            else if (arg1->kind == AST_IDENT)
            {
                printf("%s (ident)", arg1->name);
            }
            else
            {
                errorf("invalid quad arg1 %d", arg1->kind);
            }
        }
    }

    printf("    ");

    if (q.arg2)
    {
        ast_node_t *arg2 = (ast_node_t *)q.arg2;
        if (arg2->kind == AST_TEMPORARY)
        {
            if (arg2->temporary.isa)
                printf("(%%T%d)", arg2->temporary.num);
            else
                printf("%%T%d", arg2->temporary.num);
        }
        else if (arg2->kind == AST_VARIABLE)
        {
            printf("%s{ ", arg2->variable.name);
            print_storage_class(arg2->variable.storage_class);
            printf("}");
        }
        else if (arg2->kind == AST_NUMBERLIT)
        {
            printf("%d", arg2->numberlit.integer);
        }
        else
        {
            errorf("invalid quad arg2");
        }
    }
}

void print_basic_block_list(basic_block_list_t *bbl)
{
    ENUMERATE(bbl, i, {
        basic_block_t *bb = bbl->items[i];
        if (bb->is_exit)
            printf("(exit)");
        printf("BB%d:\n", i);
        ENUMERATE(bb, j, {
            printf("    ");
            print_quad(*bb->items[j]);
            printf("\n");
        });
    });    
}
