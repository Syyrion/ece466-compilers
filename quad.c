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

ast_node_t *new_immediate(int n)
{
    return ast_new_number_literal((number_t){.integer = n});
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
        errorf("there is already an available function");

    current_function = basic_block_list_new();
    basic_block_list_add(current_function, basic_block_new());
    current_function->temp_var_count = 0;
    current_function->variable_count = 0;
    current_function->argument_count = 0;
    current_function->string_literal_list = ast_node_list_new();
    current_block_index = 0;
}

ast_node_t *new_temp_var(void)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_TEMPORARY;
    new_inst->temporary.num = current_function->temp_var_count++;
    new_inst->temporary.isa = 0;
    return new_inst;
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

char allow_quad_addition = 1;
void disable_quad_addition(void)
{
    allow_quad_addition = 0;
}
void enable_quad_addition(void)
{
    allow_quad_addition = 1;
}
void add_quad_to_current_function(int index, bquad_t *q)
{
    if (allow_quad_addition)
        basic_block_add(current_function->items[index], q);
}

bquad_t *emit_pointer_plus_minus_const(int index, ast_node_t *dest, enum quad_op op, ast_node_t *pvar, ast_node_t *constant)
{
    bquad_t *q;

    // this temp var shouldn't need a type assigned to it
    ast_node_t *t1 = new_temp_var();
    add_quad_to_current_function(index, new_quad((bquad_t){
                                            .dest = t1,
                                            .op = MUL,
                                            .arg1 = constant,
                                            .arg2 = new_immediate(ast_get_sizeof_value(pvar->next->next)),
                                        }));
    add_quad_to_current_function(index, q = new_quad((bquad_t){
                                            .dest = dest,
                                            .op = op,
                                            .arg1 = pvar,
                                            .arg2 = t1,
                                        }));

    if (dest->kind == AST_VARIABLE)
    {
        if (dest->next->kind != AST_POINTER)
            errorf("pointer plus const dest must be a pointer");
    }
    else if (dest->kind == AST_TEMPORARY)
        dest->next = pvar->next;
    else
        errorf("dest must be a (temp) variable");

    return q;
}

bquad_t *emit_pointer_minus_pointer(int index, ast_node_t *dest, ast_node_t *pvar1, ast_node_t *pvar2)
{
    unsigned long size;

    if ((size = ast_get_sizeof_value(pvar1->next->next)) != ast_get_sizeof_value(pvar2->next->next))
        errorf("can't subtract two pointers of different size objects");

    bquad_t *q;

    // this temp var shouldn't need a type assigned to it
    ast_node_t *t1 = new_temp_var();
    add_quad_to_current_function(index, new_quad((bquad_t){
                                            .dest = t1,
                                            .op = SUB,
                                            .arg1 = pvar1,
                                            .arg2 = pvar2,
                                        }));
    add_quad_to_current_function(index, q = new_quad((bquad_t){
                                            .dest = dest,
                                            .op = DIV,
                                            .arg1 = t1,
                                            .arg2 = new_immediate(size),
                                        }));
    if (dest->kind == AST_VARIABLE)
    {
        if (dest->next->kind != AST_TYPE)
            errorf("pointer minus pointer dest must be an integer");
    }
    else if (dest->kind == AST_TEMPORARY)
        dest->next = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_INT}, .custom = 0}, (type_qualifier_t){0});
    else
        errorf("dest must be a (temp) variable");

    return q;
}

// emits a new quad to a basic block
// prev == 0: emit to latest created block
// prev < 0: emit to previous created blocks
// returns a pointer to the emitted quad
bquad_t *emit(int prev, ast_node_t *dest, enum quad_op op, ast_node_t *arg1, ast_node_t *arg2, int jump_target)
{
    int index;

#define DEST_ADD_METHOD                                                         \
    do                                                                          \
    {                                                                           \
        if (arg1->next->kind == AST_POINTER && arg2->next->kind == AST_POINTER) \
            errorf("ADD can't be done on 2 pointers");                          \
                                                                                \
        if (arg1->next->kind == AST_POINTER && arg2->next->kind == AST_TYPE)    \
            return emit_pointer_plus_minus_const(index, dest, ADD, arg1, arg2); \
                                                                                \
        if (arg1->next->kind == AST_TYPE && arg2->next->kind == AST_POINTER)    \
            return emit_pointer_plus_minus_const(index, dest, ADD, arg2, arg1); \
    } while (0)

#define DEST_SUB_METHOD                                                         \
    do                                                                          \
    {                                                                           \
        if (arg1->next->kind == AST_POINTER && arg2->next->kind == AST_POINTER) \
            return emit_pointer_minus_pointer(index, dest, arg1, arg2);         \
                                                                                \
        if (arg1->next->kind == AST_POINTER && arg2->next->kind == AST_TYPE)    \
            return emit_pointer_plus_minus_const(index, dest, SUB, arg1, arg2); \
                                                                                \
        if (arg1->next->kind == AST_TYPE && arg2->next->kind == AST_POINTER)    \
            errorf("can't do constant minus pointer");                          \
    } while (0)

    if (!current_function)
        errorf("there is no available basic block");

    if (prev > 0 || (index = current_block_index + prev) < 0)
        errorf("cannot emit quad to block at index %d", prev);

    ast_node_t *t1;

    // do type propagation/checking to destination
    if (dest)
    {
        switch (dest->kind)
        {
        case AST_TEMPORARY:

            if (dest->temporary.isa)
                errorf("temporary variable was written to twice");
            switch (op)
            {
            case MOV:
                dest->next = arg1->next;
                break;

            case SETP:
            case SETNP:
            case SETM:
            case SETNM:
            case SETZ:
            case SETNZ:
                dest->next = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_INT}, .custom = 0}, (type_qualifier_t){0});
                break;

            case LEA:
                if (arg1->next->kind == AST_ARRAY)
                {
                    dest->next = ast_new_pointer(0);
                    dest->next->next = arg1->next->next;
                }
                else
                {
                    dest->next = ast_new_pointer(0);
                    dest->next->next = arg1->next;
                }
                break;
            case LOAD:
                if (arg1->next->kind != AST_POINTER)
                    errorf("[temp] must load from pointer");
                dest->next = arg1->next->next;
                break;

            case ADD:
                DEST_ADD_METHOD;
                goto pm1;
            case SUB:
                DEST_SUB_METHOD;
                goto pm1;
            case MUL:
            case DIV:
            case MOD:
            case AND:
            case OR:
            case XOR:
                if (arg1->next->kind != AST_TYPE || arg2->next->kind != AST_TYPE)
                    errorf("can only perform MUL/DIV/MOD/AND/OR/XOR on integers");
            pm1:
                dest->next = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_INT}, .custom = 0}, (type_qualifier_t){0});
                break;

            case NEG:
            case SL:
            case SR:
            case CPL:
                if (arg1->next->kind != AST_TYPE)
                    errorf("can only perform NEG/SL/SR/CPL on integers");
                dest->next = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_INT}, .custom = 0}, (type_qualifier_t){0});
                break;

            case CALL:
                dest->next = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_INT}, .custom = 0}, (type_qualifier_t){0});
                break;

            default:
                errorf("unknown instruction while transferring type to temp variable");
                break;
            }
            break;
        case AST_VARIABLE:

            switch (op)
            {
            case MOV:
                if (dest->next->kind != arg1->next->kind)
                    errorf("can't MOV incompatible variables");
                break;

            case SETP:
            case SETNP:
            case SETM:
            case SETNM:
            case SETZ:
            case SETNZ:
                if (dest->next->kind != AST_TYPE)
                    errorf("NEG/SL/SR/CPL can only store to integers");
                break;

            case LEA:
                if (dest->next->kind != AST_POINTER || dest->next->kind != AST_ARRAY)
                    errorf("variable destination of LEA isn't a pointer");
                break;
            case LOAD:
                if (arg1->next->kind != AST_POINTER)
                    errorf("[var] must load from pointer");

            case ADD:
                DEST_ADD_METHOD;
                goto pm2;
            case SUB:
                DEST_SUB_METHOD;
                goto pm2;
            case MUL:
            case DIV:
            case MOD:
            case AND:
            case OR:
            case XOR:
                if (arg1->next->kind != AST_TYPE || arg2->next->kind != AST_TYPE)
                    errorf("can only perform MUL/DIV/MOD/AND/OR/XOR on integers");
            pm2:
                if (dest->next->kind != AST_TYPE)
                    errorf("MUL/DIV/MOD/AND/OR/XOR can only store to integers");
                break;

            case NEG:
            case SL:
            case SR:
            case CPL:
                if (arg1->next->kind != AST_TYPE)
                    errorf("can only perform NEG/SL/SR/CPL on integers");
                if (dest->next->kind != AST_TYPE)
                    errorf("NEG/SL/SR/CPL can only store to integers");
                break;

            case CALL:
                break;

            default:
                errorf("unknown instruction while checking destination variable compatibility");
                break;
            }
            break;
        default:
            errorf("destination can only be a temporary or variable");
            break;
        }
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

    add_quad_to_current_function(index, q);

    // mark this block as exit if there's a return
    if (op == RET)
        current_function->items[index]->is_exit = 1;

    return q;
}

void *add_local_variable(ast_node_t *var)
{
    if (var->variable.used != 2)
    {
        if (var->variable.is_argument)
            var->variable.num = current_function->argument_count++;
        else
            var->variable.num = current_function->variable_count++;
        var->variable.used = 2;
    }
}

unsigned long add_string_literal(ast_node_t *string)
{
    string->string_literal.num = current_function->string_literal_list->count;
    ast_node_list_add(current_function->string_literal_list, string);
}

// returns the finished function
basic_block_list_t *end_function(void)
{
    if (!current_function)
        errorf("there is no available function");

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

    char is_direct = 0;

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

#define BIN_COMPARE(op)                                 \
    do                                                  \
    {                                                   \
        T;                                              \
        t1 = generate_rvalue(node->binary_op.left, 0);  \
        t2 = generate_rvalue(node->binary_op.right, 0); \
        emit(0, 0, CMP, t1, t2, 0);                     \
        emit(0, target, op, 0, 0, 0);                   \
        return target;                                  \
    } while (0)

    switch (node->kind)
    {
    case AST_IDENT:
        errorf("unresolved identifier");

    case AST_VARIABLE:
        if (!node->variable.name)
            errorf("variable has no name");

        if (node->variable.storage_class == SC_AUTO)
            add_local_variable(node);

        if (node->variable.isa->kind == AST_ARRAY)
        {
            // the rvalue of an array is its address which is a pointer to the first element of the array
            T;
            emit(0, target, LEA, node, 0, 0);
            return target;
        }
        else
        {
            // other variables just return themselves
            return node;
        }

    case AST_NUMBER_LITERAL:
        if (node->number_literal.isa->type.specifier.scalar.full != TS_INT)
            errorf("only integers are supported");
        return node;

    case AST_STRING_LITERAL:
        add_string_literal(node);

        T;
        emit(0, target, LEA, node, 0, 0);
        return target;

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
        case '+':
            BIN(ADD);
        case '-':
            BIN(SUB);
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
            BIN_COMPARE(SETM);
        case LTEQ:
            BIN_COMPARE(SETNP);
        case '>':
            BIN_COMPARE(SETP);
        case GTEQ:
            BIN_COMPARE(SETNM);
        case EQEQ:
            BIN_COMPARE(SETZ);
        case NOTEQ:
            BIN_COMPARE(SETNZ);

        case LOGAND:
        case LOGOR:
        default:
            errorf("encountered invalid or unsupported binary op kind %d while generating rvalue", node->binary_op.kind);
        }
        break;

    case AST_UNARY_OP:
        switch (node->unary_op.kind)
        {
        case '&':
            T;
            t1 = generate_rvalue(node->unary_op.operand, 0);
            emit(0, target, LEA, t1, 0, 0);
            return target;
        case '*':
            t1 = new_temp_var();
            t1 = generate_rvalue(node->unary_op.operand, 0);

            if (t1->next->kind == AST_POINTER && t1->next->next->kind == AST_ARRAY)
            {
                t1->next->next = t1->next->next->next;
                printf("# %%T%d's type changed to (", t1->temporary.num);
                ast_print_compact_declarator(t1->next);
                printf(")\n");

                if (target)
                    emit(0, target, MOV, t1, 0, 0);

                return t1;
            }
            T;
            emit(0, target, LOAD, t1, 0, 0);
            return target;
        case PLUSPLUS:
            T;
            t1 = generate_lvalue(node->unary_op.operand, &is_direct);
            emit(0, target, MOV, t1, 0, 0);
            emit(0, t1, ADD, t1, new_immediate(1), 0);
            return target;
        case MINUSMINUS:
            T;
            t1 = generate_lvalue(node->unary_op.operand, &is_direct);
            emit(0, target, MOV, t1, 0, 0);
            emit(0, t1, SUB, t1, new_immediate(1), 0);
            return target;
        case '!':
            T;
            emit(0, 0, CMP, generate_rvalue(node->unary_op.operand, 0), new_immediate(0), 0);
            emit(0, target, SETZ, new_immediate(1), 0, 0);
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
        default:
            errorf("encountered invalid or unsupported unary op kind %d while generating rvalue", node->unary_op.kind);
        }
        break;
    case AST_FUNCTION_CALL:
        T;
        return generate_function_call(node, target);
    case AST_TYPE_CAST:
    case AST_TERNARY_OP:
    case AST_MEMBER_ACCESS:
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
        emit(0, 0, STORE, value, dest, 0);
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
        emit(0, 0, STORE, t2, dest, 0);
        return t2;
    }
}

// Returns a target lvalue variable. Returns 0 if the node cannot become an lvalue
ast_node_t *generate_lvalue(ast_node_t *node, char *is_direct)
{
    switch (node->kind)
    {
    case AST_VARIABLE:
        add_local_variable(node);
        *is_direct = 1;
        return node;
    case AST_UNARY_OP:
        if (node->unary_op.kind == '*')
        {
            *is_direct = 0;
            ast_node_t *v = generate_rvalue(node->unary_op.operand, 0);

            if (v->next->kind != AST_POINTER)
                return 0;
            return v;
        }
    default:
        return 0;
    }
}

ast_node_t *generate_function_call(ast_node_t *node, ast_node_t *target)
{
    if (node->kind != AST_FUNCTION_CALL)
    {
        errorf("wrong node type for generate_function_call %d", node->kind);
    }
    ast_node_list_t *params = ast_node_list_new();
    emit(0, 0, ARGBEGIN, 0, 0, 0);

    ENUMERATE(node->function_call.args, i, {
        ast_node_list_add(params, generate_rvalue(node->function_call.args->items[i], 0));
    });
    for (int i = params->count - 1; i >= 0; i--)
        emit(0, 0, ARG, params->items[i], 0, 0);

    emit(0, target, CALL, node->function_call.name, 0, 0);
    return target;
}

ast_node_t *generate_sizeof(ast_node_t *node, ast_node_t *target)
{
    ast_node_t *t1;
    switch (node->kind)
    {
    case AST_TEMPORARY:
    case AST_VARIABLE:
        emit(0, target, MOV, new_immediate((int)ast_get_sizeof_value(node->next)), 0, 0);
        break;
    case AST_BINARY_OP:
    case AST_UNARY_OP:
        // this temporary is only used for it's type
        disable_quad_addition();
        t1 = generate_rvalue(node, 0);
        enable_quad_addition();
        emit(0, target, MOV, new_immediate((int)ast_get_sizeof_value(t1->next)), 0, 0);
        break;
    case AST_NUMBER_LITERAL:
        emit(0, target, MOV, new_immediate(4), 0, 0);
        break;
    default:
        errorf("wrong node type for generate_sizeof %d", node->kind);
    }
    return target;
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

void print_quad_component(ast_node_t *val)
{
    if (!val)
        return;
    printf("{ ");
    switch (val->kind)
    {
    case AST_TEMPORARY:
        printf("%%T%d ", val->temporary.num);
        break;
    case AST_VARIABLE:
        printf("%s (%d) ", val->variable.name, val->variable.num);
        if (val->variable.is_argument)
            printf("arg ");
        print_storage_class(val->variable.storage_class);
        break;
    case AST_NUMBER_LITERAL:
        printf("$%d ", val->number_literal.integer);
        break;
    case AST_STRING_LITERAL:
        printf("\"");
        ast_print_string_literal(val);
        printf("\" (%d) ", val->string_literal.num);
        break;
    case AST_IDENT:
        printf("%s (ident)", val->name);
        return;
    default:
        errorf("can't print quad argument/destination %d", val->kind);
    }

    if (val->next)
        ast_print_compact_declarator(val->next);
    else
        printf("(missing type)");
    printf(" }");
}

void print_quad(bquad_t q)
{
    print_quad_component(q.dest);
    printf("    ");
    printf("%s", op_names[q.op]);
    printf("    ");
    if (q.op >= JP)
        printf("BB%d", q.jump_target);
    else if (q.op == CALL)
        printf("%s", q.arg1->name);
    else
        print_quad_component(q.arg1);
    printf("    ");
    print_quad_component(q.arg2);
}

void print_basic_block_list(basic_block_list_t *bbl)
{
    printf("total arguments = %ld\n", bbl->argument_count);
    printf("total local variables = %ld\n", bbl->variable_count);
    printf("total temp variables = %ld\n", bbl->temp_var_count);
    printf("total string literals = %ld\n", bbl->string_literal_list->count);
    ENUMERATE(bbl, i, {
        basic_block_t *bb = bbl->items[i];
        if (bb->is_exit)
            printf("(exit) ");
        printf("BB%d:\n", i);
        ENUMERATE(bb, j, {
            printf("    ");
            print_quad(*bb->items[j]);
            printf("\n");
        });
    });
}
