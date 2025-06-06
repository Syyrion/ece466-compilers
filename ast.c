#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIST_IMPLEMENT
#include "ast.h"
#undef LIST_IMPLEMENT

#include "location.h"
#include "parser.tab.h"
#include "expression_operators.h"
#include "errorf.h"

// keeps track of all created type nodes
static ast_node_list_t *type_list;

void ast_init(void)
{
    type_list = ast_node_list_new();
}

void ast_deinit(void)
{
    // TODO free stuff left behind
}

// ## EXPRESSIONS

ast_node_t *ast_new_ident(char *name)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_IDENT;
    new_inst->name = name;
    return new_inst;
}

ast_node_t *ast_new_char_literal(char c)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_NUMBER_LITERAL;
    new_inst->number_literal.integer = c;
    new_inst->number_literal.isa = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_INT}, .custom = 0}, (type_qualifier_t){0});
    return new_inst;
}

ast_node_t *ast_new_string_literal(string_t string)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_STRING_LITERAL;
    new_inst->string_literal.buffer = string.buffer;
    new_inst->string_literal.isa = ast_new_array(ast_new_number_literal((number_t){.integer = string.length + 1, .type.full = TS_INT}));
    new_inst->string_literal.isa->array.of = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_CHAR}, .custom = 0}, (type_qualifier_t){0});
    return new_inst;
}

ast_node_t *ast_new_number_literal(number_t number)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_NUMBER_LITERAL;
    new_inst->number_literal.integer = number.integer;
    new_inst->number_literal.isa = new_inst->number_literal.isa = ast_new_type((type_specifier_t){.scalar = (scalar_t){.full = TS_INT}, .custom = 0}, (type_qualifier_t){0});
    return new_inst;
}

ast_node_t *ast_new_unary_op(int kind, ast_node_t *operand)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_UNARY_OP;
    new_inst->unary_op.kind = kind;
    new_inst->unary_op.operand = operand;
    return new_inst;
}

ast_node_t *ast_new_binary_op(int kind, ast_node_t *left, ast_node_t *right)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_BINARY_OP;
    new_inst->binary_op.kind = kind;
    new_inst->binary_op.left = left;
    new_inst->binary_op.right = right;
    return new_inst;
}

ast_node_t *ast_new_ternary_op(ast_node_t *condition, ast_node_t *true_branch, ast_node_t *false_branch)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_TERNARY_OP;
    new_inst->ternary_op.condition = condition;
    new_inst->ternary_op.true_branch = true_branch;
    new_inst->ternary_op.false_branch = false_branch;
    return new_inst;
}

ast_node_t *ast_new_function_call(ast_node_t *name, ast_node_list_t *args)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_FUNCTION_CALL;
    new_inst->function_call.name = name;
    new_inst->function_call.args = args;
    return new_inst;
}

ast_node_t *ast_new_type_cast(ast_node_t *operand, ast_node_t *type)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_TYPE_CAST;
    new_inst->type_cast.operand = operand;
    new_inst->type_cast.type = type;
    return new_inst;
}

ast_node_t *ast_new_member_access(ast_node_t *operand, char *ident)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_MEMBER_ACCESS;
    new_inst->member_access.operand = operand;
    new_inst->member_access.ident = ident;
    return new_inst;
}

// recursively frees an expression
void ast_free_expression(ast_node_t *node)
{
    switch (node->kind)
    {
    case AST_NUMBER_LITERAL:
        ast_free_variable_like_node(node->number_literal.isa);
        break;
    case AST_IDENT:
        free(node->name);
        break;
    case AST_STRING_LITERAL:
        ast_free_variable_like_node(node->string_literal.isa);
        free(node->string_literal.buffer);
        break;
    case AST_UNARY_OP:
        ast_free_expression(node->unary_op.operand);
        break;
    case AST_BINARY_OP:
        ast_free_expression(node->binary_op.left);
        ast_free_expression(node->binary_op.right);
        break;
    case AST_TERNARY_OP:
        ast_free_expression(node->ternary_op.condition);
        ast_free_expression(node->ternary_op.true_branch);
        ast_free_expression(node->ternary_op.false_branch);
        break;
    case AST_FUNCTION_CALL:
        ast_free_expression(node->function_call.name);
        ENUMERATE(node->function_call.args, i, {
            ast_free_expression(node->function_call.args->items[i]);
        });
        ast_node_list_free(node->function_call.args);
        break;
    case AST_TYPE_CAST:
        ast_free_expression(node->type_cast.operand);
        ast_free_variable_like_node(node->type_cast.type);
        break;
    default:
        // don't proceed if a part of the tree isn't part of the expression
        return;
    }
    free(node);
}

// Recursively checks if a expression. i.e. has no function calls or variables
int ast_is_expression_constant(ast_node_t *node)
{
    switch (node->kind)
    {
    case AST_IDENT:
    case AST_VARIABLE:
    case AST_FUNCTION_CALL:
        return 0;

    case AST_UNARY_OP:
        return ast_is_expression_constant(node->unary_op.operand);
    case AST_BINARY_OP:
        return ast_is_expression_constant(node->binary_op.left) &&
               ast_is_expression_constant(node->binary_op.right);
    case AST_TERNARY_OP:
        return ast_is_expression_constant(node->ternary_op.condition) &&
               ast_is_expression_constant(node->ternary_op.false_branch) &&
               ast_is_expression_constant(node->ternary_op.true_branch);
    case AST_TYPE_CAST:
        return ast_is_expression_constant(node->type_cast.operand);

    default:
        return 1;
    }
}

// I should probably have written this a long while ago

long ast_evaluate_constant_expression(ast_node_t *expr)
{
    switch (expr->kind)
    {
    case AST_NUMBER_LITERAL:
        return expr->number_literal.integer;
    case AST_BINARY_OP:
        switch (expr->binary_op.kind)
        {
        case '*':
            return ast_evaluate_constant_expression(expr->binary_op.left) * ast_evaluate_constant_expression(expr->binary_op.right);
        case '/':
            return ast_evaluate_constant_expression(expr->binary_op.left) / ast_evaluate_constant_expression(expr->binary_op.right);
        case '%':
            return ast_evaluate_constant_expression(expr->binary_op.left) % ast_evaluate_constant_expression(expr->binary_op.right);
        case '+':
            return ast_evaluate_constant_expression(expr->binary_op.left) + ast_evaluate_constant_expression(expr->binary_op.right);
        case '-':
            return ast_evaluate_constant_expression(expr->binary_op.left) - ast_evaluate_constant_expression(expr->binary_op.right);
        case SHL:
            return ast_evaluate_constant_expression(expr->binary_op.left) << ast_evaluate_constant_expression(expr->binary_op.right);
        case SHR:
            return ast_evaluate_constant_expression(expr->binary_op.left) >> ast_evaluate_constant_expression(expr->binary_op.right);
        case '<':
            return ast_evaluate_constant_expression(expr->binary_op.left) < ast_evaluate_constant_expression(expr->binary_op.right);
        case LTEQ:
            return ast_evaluate_constant_expression(expr->binary_op.left) <= ast_evaluate_constant_expression(expr->binary_op.right);
        case '>':
            return ast_evaluate_constant_expression(expr->binary_op.left) > ast_evaluate_constant_expression(expr->binary_op.right);
        case GTEQ:
            return ast_evaluate_constant_expression(expr->binary_op.left) >= ast_evaluate_constant_expression(expr->binary_op.right);
        case EQEQ:
            return ast_evaluate_constant_expression(expr->binary_op.left) == ast_evaluate_constant_expression(expr->binary_op.right);
        case NOTEQ:
            return ast_evaluate_constant_expression(expr->binary_op.left) != ast_evaluate_constant_expression(expr->binary_op.right);
        case '&':
            return ast_evaluate_constant_expression(expr->binary_op.left) & ast_evaluate_constant_expression(expr->binary_op.right);
        case '^':
            return ast_evaluate_constant_expression(expr->binary_op.left) ^ ast_evaluate_constant_expression(expr->binary_op.right);
        case '|':
            return ast_evaluate_constant_expression(expr->binary_op.left) | ast_evaluate_constant_expression(expr->binary_op.right);
        case LOGAND:
            return ast_evaluate_constant_expression(expr->binary_op.left) && ast_evaluate_constant_expression(expr->binary_op.right);
        case LOGOR:
            return ast_evaluate_constant_expression(expr->binary_op.left) || ast_evaluate_constant_expression(expr->binary_op.right);
        default:
            errorf("ast_evaluate_constant_expression encountered unknown binary op %d", expr->binary_op.kind);
        }
        break;
    case AST_UNARY_OP:
        switch (expr->unary_op.kind)
        {
        case '+':
            return +ast_evaluate_constant_expression(expr->unary_op.operand);
        case '-':
            return -ast_evaluate_constant_expression(expr->unary_op.operand);
        case '~':
            return ~ast_evaluate_constant_expression(expr->unary_op.operand);
        case '!':
            return !ast_evaluate_constant_expression(expr->unary_op.operand);
        default:
            errorf("ast_evaluate_constant_expression encountered unknown unary op %d", expr->unary_op.kind);
        }
        break;

    default:
        errorf("ast_evaluate_constant_expression cannot evaluate %d", expr->kind);
    }
}

unsigned long ast_get_sizeof_value(ast_node_t *node)
{
    long size;
    switch (node->kind)
    {
    case AST_TYPE:
    case AST_POINTER:
    case AST_FUNCTION:
        // assumes everything is an int
        return 4;
    case AST_ARRAY:
        size = ast_evaluate_constant_expression(node->array.size);
        if (size <= 0)
            errorf("invalid array size");
        return size * ast_get_sizeof_value(node->array.of);
    default:
        errorf("unknown variable type %d", node->variable.isa->kind);
    }
}

static void ast_mark_variable_as_used(ast_node_t *var)
{
    var->variable.used = 1;
    ast_node_t *p = var->next;
    while (p->kind != AST_TYPE)
        p = p->next;
    if (p->type.specifier.scalar.full & TS_CUSTOM)
        p->type.specifier.custom->structure.used = 1;
}

// replaces AST_IDENT nodes in an expression with literal variables in-place
void ast_resolve_expression_variables(ast_node_t **node, char ignore_on_failure)
{
    ast_node_t *var;
    switch ((*node)->kind)
    {
    case AST_IDENT:
        var = st_find(NS_VARIABLE, (*node)->name);
        if (var)
        {
            free((*node)->name);
            free((*node));
            ast_mark_variable_as_used(var);
            *node = var;
            var->variable.used = 1;
            break;
        }
        if (ignore_on_failure)
            break;
        errorf("%s:%d: the variable %s doesn't exist", filename, line_num, (*node)->name);
    case AST_UNARY_OP:
        ast_resolve_expression_variables(&(*node)->unary_op.operand, 0);
        break;
    case AST_BINARY_OP:
        ast_resolve_expression_variables(&(*node)->binary_op.left, 0);
        ast_resolve_expression_variables(&(*node)->binary_op.right, 0);
        break;
    case AST_TERNARY_OP:
        ast_resolve_expression_variables(&(*node)->ternary_op.condition, 0);
        ast_resolve_expression_variables(&(*node)->ternary_op.true_branch, 0);
        ast_resolve_expression_variables(&(*node)->ternary_op.false_branch, 0);
        break;
    case AST_TYPE_CAST:
        ast_resolve_expression_variables(&(*node)->type_cast.operand, 0);
        break;
    case AST_MEMBER_ACCESS:
        ast_resolve_expression_variables(&(*node)->member_access.operand, 0);
        break;
    case AST_FUNCTION_CALL:
        ast_resolve_expression_variables(&(*node)->function_call.name, 1);
        ENUMERATE((*node)->function_call.args, i, {
            ast_resolve_expression_variables(&(*node)->function_call.args->items[i], 0);
        });

    case AST_STRING_LITERAL:
    case AST_NUMBER_LITERAL:
    case AST_TYPE:
    case AST_VARIABLE:
        break;
    default:
        errorf("failed to resolve expression %d", (*node)->kind);
    }
}

// ## STRUCTS

// Makes a new struct. Set members to 0 for an incomplete struct
ast_node_t *ast_new_struct_or_union(ast_node_kind_t kind, char *name, ast_node_list_t *members)
{
    if (!(kind == AST_STRUCT || kind == AST_UNION))
        errorf("argument 1 of ast_new_struct_or_union was not AST_STRUCT or AST_UNION");

    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = kind;
    new_inst->structure.name = name;
    new_inst->structure.members = members;
    new_inst->structure.used = 0;
    return new_inst;
}

// Adds a list of members to a struct
ast_node_t *ast_add_struct_or_union_members(ast_node_t *node, ast_node_list_t *members)
{
    node->structure.members = members;
    return node;
}

// Converts an identifier to a struct or union member
ast_node_t *ast_ident_to_member(ast_node_t *node, ast_node_t *bit_width)
{
    node->kind = AST_MEMBER;
    node->member.bit_width = bit_width;
    return node;
}

// Makes a new padding struct or union member
ast_node_t *ast_new_padding_member(ast_node_t *bit_width)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_MEMBER;
    new_inst->member.name = 0;
    new_inst->member.isa = 0; // TODO there should technically be a type here
    new_inst->member.bit_width = bit_width;
    return new_inst;
}

void ast_free_struct(ast_node_t *node)
{
    ENUMERATE(node->structure.members, i, {
        ast_node_t *m = node->structure.members->items[i];
        if (m->member.bit_width)
            ast_free_expression(m->member.bit_width);
        if (m->member.isa)
            ast_free_variable_like_node(m->member.isa);
        if (m->member.name)
            free(m->member.name);
    });

    ast_node_list_free(node->structure.members);
    free(node->structure.members);
    free(node);
}

// ## VARIABLES

// converts an identifier into a variable
ast_node_t *ast_ident_to_variable(ast_node_t *node, storage_class_specifier_t storage_class_specifier)
{
    node->kind = AST_VARIABLE;
    node->variable.storage_class = storage_class_specifier;
    node->variable.used = 0;
    node->variable.num = 0;
    node->variable.is_argument = 0;
    return node;
}

ast_node_t *ast_new_pointer(int type_qualifier)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_POINTER;
    new_inst->pointer.type_qualifier.full = (char)type_qualifier;
    new_inst->pointer.to = 0;
    return new_inst;
};

ast_node_t *ast_new_array(ast_node_t *size)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_ARRAY;
    new_inst->array.size = size;
    new_inst->array.of = 0;
    return new_inst;
};

ast_node_t *ast_new_function(ast_node_list_t *paramter_list)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_FUNCTION;
    new_inst->function.parameters = paramter_list;
    new_inst->function.returns = 0;
    return new_inst;
}

ast_node_t *ast_new_type(type_specifier_t type_specifier, type_qualifier_t type_qualifier)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_TYPE;
    new_inst->type.specifier = type_specifier;
    new_inst->type.qualifier = type_qualifier;
    ast_node_list_add(type_list, new_inst);
    return new_inst;
}

// Frees a variable like node.
void ast_free_variable_like_node(ast_node_t *var)
{
    ast_node_t *current = var, *temp;

    while (current->kind != AST_TYPE)
    {
        switch (current->kind)
        {
        case AST_STRING_LITERAL:
            free(current->string_literal.buffer);
            break;
        case AST_NUMBER_LITERAL:
            // nothing to do
            break;
        case AST_TEMPORARY:
            // nothing to do
            break;
        case AST_VARIABLE:
            if (current->variable.name)
                free(current->variable.name);
            break;
        case AST_POINTER:
            // nothing to do
            break;
        case AST_ARRAY:
            if (current->array.size)
                ast_free_expression(current->array.size);
            break;
        case AST_FUNCTION:
            if (current->function.parameters)
                ENUMERATE(current->function.parameters, i, {
                    ast_free_variable_like_node(current->function.parameters->items[i]);
                });
            break;
        default:
            errorf("can't free node kind %d for variable", current->kind);
        }

        temp = current;
        current = current->next;
        free(temp);
    }
    free(current);
}

int ast_are_variables_compatible(ast_node_t *a, ast_node_t *b)
{
    ast_node_t *current_a = a, *current_b = b;

    while (current_a->kind != AST_TYPE || current_b->kind != AST_TYPE)
    {
        if (current_a->kind != current_b->kind)
            return 0;

        switch (current_a->kind)
        {
        case AST_VARIABLE:
            if (current_a->variable.storage_class != current_b->variable.storage_class)
                return 0;
            break;
        case AST_POINTER:
            break;
        case AST_ARRAY:
            // TODO array size comparison not implemented yet (reports incompatible for now)
            if (current_a->array.size && current_b->array.size)
                return 0;
            break;
        case AST_FUNCTION:
            if (current_a->function.parameters && current_b->function.parameters)
            {
                if (current_a->function.parameters->count != current_b->function.parameters->count)
                    return 0;

                ENUMERATE(current_a->function.parameters, i, {
                    if (!ast_are_variables_compatible(current_a->function.parameters->items[i], current_b->function.parameters->items[i]))
                        return 0;
                });
            }
            break;
        default:
            errorf("cannot check compatibility");
        }
        current_a = current_a->next, current_b = current_b->next;
    }
    // we've reached at least one variable's final AST_TYPE node

    if (                                                                                  // Variables are incompatible if
        current_a->kind != current_b->kind ||                                             // they aren't both AST_TYPE, or
        current_a->type.qualifier.full != current_b->type.qualifier.full ||               // have non-equivalent type qualifiers, or
        current_a->type.specifier.scalar.full != current_b->type.specifier.scalar.full || // have non-equivalent scalars, or
        (current_a->type.specifier.scalar.full & TS_CUSTOM &&                             // if scalars are custom and
         current_a->type.specifier.custom != current_b->type.specifier.custom))           // don't refer to same custom structure.
        return 0;

    return 1;
}

// Merges variable b into variable a in place. Variable name is ignored. Variable b is destroyed.
// Assumes variables have already been checked for compatibility.
void ast_merge_into_variable(ast_node_t *a, ast_node_t *b)
{
    ast_node_t *current_a = a, *current_b = b;
    ast_node_t *temp;

    while (current_a->kind != AST_TYPE)
    {
        switch (current_a->kind)
        {
        case AST_VARIABLE:
            // variable b's name replaces variable a's
            // this is done because of function parameter names, which take on the latest encountered name
            if (current_a->variable.name)
                free(current_a->variable.name);
            current_a->variable.name = current_b->variable.name;
            break;
        case AST_POINTER:
            // merge qualifiers
            current_a->pointer.type_qualifier.full |= current_b->pointer.type_qualifier.full;
            break;
        case AST_ARRAY:
            // if variable a has no size copy variable b's size
            // if variable b also has no size, this operation has no effects
            if (!current_a->array.size)
                current_a->array.size = current_b->array.size;
            break;
        case AST_FUNCTION:
            if (current_a->function.parameters && current_b->function.parameters)
            // both variables have known parameters
            {
                // merge function parameters
                ENUMERATE(current_a->function.parameters, i, {
                    ast_merge_into_variable(current_a->function.parameters->items[i], current_b->function.parameters->items[i]);
                });
            }
            else
            // one variable has unknown parameters
            {
                // if variable a has no size copy variable b's size
                // if variable b also has no size, this operation has no effects
                if (!current_a->function.parameters)
                    current_a->function.parameters = current_b->function.parameters;
            }
            break;
        default:
            errorf("cannot merge");
        }

        // free variable b's node
        temp = current_b->next;
        free(current_b);
        current_a = current_a->next, current_b = temp;
    }
}

// ## STATEMENTS

ast_node_t *ast_new_compound_statement(ast_node_list_t *statements)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_COMPOUND;
    new_inst->compound_statement.sub_statements = statements;
    return new_inst;
}

ast_node_t *ast_new_expression_statement(ast_node_t *expr)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_EXPRESSION;
    new_inst->expression_statement.expression = expr;
    return new_inst;
}

ast_node_t *ast_new_if_statement(ast_node_t *condition, ast_node_t *true_statement, ast_node_t *false_statement)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_IF;
    new_inst->if_statement.condition = condition;
    new_inst->if_statement.true_branch = true_statement;
    new_inst->if_statement.false_branch = false_statement;
    return new_inst;
}

ast_node_t *ast_new_switch_statement(ast_node_t *expression, ast_node_t *statement)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_SWITCH;
    new_inst->switch_statement.expression = expression;
    new_inst->switch_statement.statement = statement;
    new_inst->switch_statement.cases = ast_node_list_new();
    new_inst->switch_statement.default_case = 0;
    new_inst->next = 0;
    return new_inst;
}

ast_node_t *ast_new_switch_case(ast_node_t *constant_expression, ast_node_t *statement)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_CASE;
    new_inst->switch_case.constant_expression = constant_expression;
    new_inst->switch_case.statement = statement;
    return new_inst;
}

ast_node_t *ast_new_while_statement(int kind, ast_node_t *condition, ast_node_t *statement)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = kind;
    new_inst->while_statement.condition = condition;
    new_inst->while_statement.statement = statement;
    new_inst->next = 0;
    return new_inst;
}

ast_node_t *ast_new_for_statement(ast_node_t *init, ast_node_t *condition, ast_node_t *final, ast_node_t *statement)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_FOR;
    new_inst->for_statement.init = init;
    new_inst->for_statement.condition = condition;
    new_inst->for_statement.final = final;
    new_inst->for_statement.statement = statement;
    new_inst->next = 0;
    return new_inst;
}

ast_node_t *ast_new_goto_statement(char *label)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_GOTO;
    new_inst->goto_statement.label_name = label;
    return new_inst;
}

ast_node_t *ast_new_continue_statement(ast_node_t *association)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_CONTINUE;
    new_inst->continue_statement.association = association;
    return new_inst;
}

ast_node_t *ast_new_break_statement(ast_node_t *association)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_BREAK;
    new_inst->break_statement.association = association;
    return new_inst;
}

ast_node_t *ast_new_return_statement(ast_node_t *expr)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_RETURN;
    new_inst->return_statement.expression = expr;
    return new_inst;
}

ast_node_t *ast_new_label(char *label, ast_node_t *statement)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_LABEL;
    new_inst->label.name = label;
    new_inst->label.statement = statement;
    return new_inst;
}

// ## Functions for printing below

void ast_print_string_literal(ast_node_t *string)
{
    const char *s = string->string_literal.buffer;
    for (int i = 0; s[i] != 0; i++)
    {
        if (s[i] == '\x07')
            printf("\\a");
        else if (s[i] == '\x08')
            printf("\\b");
        else if (s[i] == '\x0c')
            printf("\\f");
        else if (s[i] == '\x0a')
            printf("\\n");
        else if (s[i] == '\x0d')
            printf("\\r");
        else if (s[i] == '\x09')
            printf("\\t");
        else if (s[i] == '\x0b')
            printf("\\v");
        else if (s[i] == '\\')
            printf("\\\\");
        else if (s[i] == '\'')
            printf("\\\'");
        else if (s[i] == '"')
            printf("\\\"");
        else if (s[i] == 0)
            printf("\\0");
        else if (isprint(s[i]))
            fputc(s[i], stdout);
        else
            printf("\\%03o", (unsigned char)s[i]);
    }
}

void ast_print_number_literal(ast_node_t *number)
{
    scalar_t type = number->number_literal.isa->type.specifier.scalar;
    if (type.full & TS_REAL)
    {
        printf(
            "REAL    %Lg    %s",
            number->number_literal.real,
            type.long_bit     ? "LONG DOUBLE"
            : type.double_bit ? "DOUBLE"
                              : "FLOAT");
    }
    else
    {
        printf(
            "INTEGER    %lld    %s%s",
            number->number_literal.integer,
            type.unsigned_bit ? "UNSIGNED " : "",
            type.long2_bit       ? "LONG LONG"
            : type.long_bit == 1 ? "LONG"
                                 : "INT");
    }
}

#define TAB_PAD(depth)                  \
    {                                   \
        for (int i = 0; i < depth; i++) \
            printf("    ");             \
    }

void ast_print_expression(ast_node_t *node, const unsigned int depth)
{

#define SUBSECTION(name, where)                 \
    do                                          \
    {                                           \
        TAB_PAD(depth);                         \
        printf(".%s\n", name);                  \
        ast_print_expression(where, depth + 1); \
    } while (0)

    TAB_PAD(depth);
    switch (node->kind)
    {
    case AST_IDENT:
        printf("IDENT \"%s\"\n", node->name);
        break;
    case AST_STRING_LITERAL:
        printf("STRINGLIT \"");
        ast_print_string_literal(node);
        printf("\"\n");
        break;
    case AST_NUMBER_LITERAL:
        printf("NUMBERLIT    ");
        ast_print_number_literal(node);
        printf("\n");
        break;
    case AST_UNARY_OP:
        printf("UNARY_OP \"");
        print_expression_operator(node->unary_op.kind);
        printf("\"\n");
        if (node->unary_op.kind == SIZEOF && node->unary_op.operand->kind == AST_VARIABLE && node->unary_op.operand->name == 0)
        {
            TAB_PAD(depth);
            printf(".%s\n", "operand");
            ast_print_variable(node->unary_op.operand, depth + 1);
        }
        else
            SUBSECTION("operand", node->unary_op.operand);
        break;
    case AST_MEMBER_ACCESS:
        printf("MEMBER_ACCESS %s\n", node->member_access.ident);
        SUBSECTION("operand", node->member_access.operand);
        break;
    case AST_BINARY_OP:
        printf("BINARY_OP \"");
        print_expression_operator(node->binary_op.kind);
        printf("\"\n");
        SUBSECTION("left", node->binary_op.left);
        SUBSECTION("right", node->binary_op.right);
        break;
    case AST_TERNARY_OP:
        printf("TERNARY_OP\n");
        SUBSECTION("condition", node->ternary_op.condition);
        SUBSECTION("true_branch", node->ternary_op.true_branch);
        SUBSECTION("false_branch", node->ternary_op.false_branch);
        break;
    case AST_FUNCTION_CALL:
        printf("FUNCTION_CALL");
        SUBSECTION("name", node->function_call.name);
        ENUMERATE(node->function_call.args, i, {
            char b[16];
            snprintf(b, sizeof(b), "arg[%d]", i);
            SUBSECTION(b, node->function_call.args->items[i]);
        });
        break;
    case AST_TYPE_CAST:
        printf("TYPE_CAST");
        TAB_PAD(depth);
        printf(".type\n");
        ast_print_variable(node->type_cast.type, depth + 1);
        SUBSECTION("operand", node->type_cast.operand);
        break;
    case AST_VARIABLE:
        printf("VARIABLE (resolved) \"%s\"\n", node->name);
        break;
    default:
        errorf("can't print node kind %d for expression", node->kind);
    }

#undef SUBSECTION
}

void ast_print_declarator(ast_node_t *node, unsigned int depth)
{
    ast_node_t *current_node = node;

    while (current_node->kind != AST_TYPE)
    {
        TAB_PAD(depth);
        switch (current_node->kind)
        {
        case AST_POINTER:
            print_type_qualifier(current_node->pointer.type_qualifier);
            printf("pointer to a(n)\n");
            current_node = current_node->pointer.to;
            break;

        case AST_ARRAY:
            if (current_node->array.size)
            {
                printf("array with size\n");
                TAB_PAD(depth);
                printf("[\n");
                ast_print_expression(current_node->array.size, depth + 1);
                TAB_PAD(depth);
                printf("]\n");
                TAB_PAD(depth);
            }
            else
            {
                printf("array with unknown size ");
            }
            printf("containing\n");
            current_node = current_node->array.of;
            break;

        case AST_FUNCTION:

            if (current_node->function.parameters)
            {
                printf("function taking parameters\n");
                TAB_PAD(depth);
                printf("(\n");
                ENUMERATE(current_node->function.parameters, i, {
                    ast_print_variable(current_node->function.parameters->items[i], depth + 1);
                });
                TAB_PAD(depth);
                printf(")\n");
                TAB_PAD(depth);
            }
            else
            {
                printf("function with unknown parameters ");
            }
            printf("returning\n");
            current_node = current_node->function.returns;
            break;
        default:
            printf("unknown %d", current_node->kind);
            return;
        }
        depth++;
    }
    TAB_PAD(depth);
    print_type_qualifier(current_node->type.qualifier);
    print_scalar(current_node->type.specifier.scalar);
    if (current_node->type.specifier.scalar.full & TS_CUSTOM)
        printf("with name %s (%s)",
               current_node->type.specifier.custom->name ? current_node->type.specifier.custom->name : "<unnamed>",
               current_node->type.specifier.custom->structure.members ? "complete" : "incomplete");
    printf("\n");
}

void ast_print_compact_declarator(ast_node_t *node)
{
    char a[256] = "";
    char b[256] = "";
    char *pt;
    char *pa = a;
    char *pb = b;

    ast_node_t *current_node = node;
    while (current_node->kind != AST_TYPE)
    {
        switch (current_node->kind)
        {
        case AST_POINTER:
            snprintf(pb, 256, "*%s", pa);
            break;
        case AST_ARRAY:
            snprintf(pb, 256, "%s[%d]", pa, ast_evaluate_constant_expression(current_node->array.size));
            break;
        case AST_FUNCTION:
            snprintf(pb, 256, "%s()", pa);
            break;
        default:
            printf("ast_print_compact_declarator unknown %d", current_node->kind);
            return;
        }

        // swap buffers
        pt = pb;
        pb = pa;
        pa = pt;
        current_node = current_node->next;
    }
    print_scalar(current_node->type.specifier.scalar);
    printf(pa);
}

void ast_print_variable(ast_node_t *node, unsigned int depth)
{
    TAB_PAD(depth);
    printf("The variable `%s` has storage class ", node->variable.name ? node->variable.name : "<no-name>");
    print_storage_class(node->variable.storage_class);
    printf("and is a(n)\n");
    ast_print_declarator(node->variable.isa, depth + 1);
}

static void print_member(ast_node_t *node, const unsigned int depth)
{
    if (node->member.name)
    {
        TAB_PAD(depth);
        printf(".%s ", node->member.name);

        printf("with type:\n");
        ast_print_declarator(node->member.isa, depth + 1);
        if (node->member.bit_width)
        {
            TAB_PAD(depth);
            printf("with bit width:\n");
            ast_print_expression(node->member.bit_width, depth + 1);
        }
    }
    else
    {
        TAB_PAD(depth);
        printf("PADDING, with bit width:\n");
        ast_print_expression(node->member.bit_width, depth + 1);
    }
    printf("\n");
}

void ast_print_struct_or_union(ast_node_t *node)
{
    printf("> %s %s has been declared ",
           node->kind == AST_STRUCT ? "STRUCT" : "UNION",
           node->structure.name);

    if (node->structure.members)
    {
        printf("with members\n");
        printf("{\n");
        ENUMERATE(node->structure.members, i, {
            print_member(node->structure.members->items[i], 1);
        });
        printf("}");
    }
    else
    {
        printf("but is incomplete");
    }
    printf("\n");
}

void ast_print_statement(ast_node_t *statement, int depth)
{
    TAB_PAD(depth);
    printf("%p : ", statement);
    switch (statement->kind)
    {
    case AST_GOTO:
        printf("goto %p\n", statement->goto_statement.statement);
        break;
    case AST_COMPOUND:
        printf("compound\n");
        TAB_PAD(depth);
        printf("{\n");
        ENUMERATE(statement->compound_statement.sub_statements, i, {
            ast_print_statement(statement->compound_statement.sub_statements->items[i], depth + 1);
        });
        TAB_PAD(depth);
        printf("}\n");
        break;
    case AST_IF:
        printf("if\n");
        TAB_PAD(depth);
        printf("(\n");
        ast_print_expression(statement->if_statement.condition, depth + 1);
        TAB_PAD(depth);
        printf(")\n");
        TAB_PAD(depth);
        printf("then\n");
        ast_print_statement(statement->if_statement.true_branch, depth + 1);
        if (statement->if_statement.false_branch)
        {
            TAB_PAD(depth);
            printf("else\n");
            ast_print_statement(statement->if_statement.false_branch, depth + 1);
        }
        break;
        /*
            case AST_SWITCH:
                printf("switch\n");
                TAB_PAD(depth);
                printf("(\n");
                ast_print_expression(statement->switch_statement.expression, depth + 1);
                TAB_PAD(depth);
                printf(") == [\n");

                for (int i = 0; i < statement->switch_statement.cases->node_count; i++)
                {
                    TAB_PAD(depth + 1);
                    printf("case\n");
                    ast_print_expression(statement->switch_statement.cases->nodes[i]->switch_case.constant_expression, depth + 2);
                    TAB_PAD(depth + 1);
                    printf(": %p\n", statement->switch_statement.cases->nodes[i]->switch_case.statement);
                }

                if (statement->switch_statement.default_case)
                {
                    TAB_PAD(depth + 1);
                    printf("default : %p\n", statement->switch_statement.default_case);
                }
                TAB_PAD(depth);
                printf("]\n");
                TAB_PAD(depth);
                printf("then\n");
                ast_print_statement(statement->switch_statement.statement, depth + 1);
                break;
        */
    case AST_WHILE:
        printf("while\n");
        TAB_PAD(depth);
        printf("(\n");
        ast_print_expression(statement->while_statement.condition, depth + 1);
        TAB_PAD(depth);
        printf(")\n");
        TAB_PAD(depth);
        printf("do\n");
        ast_print_statement(statement->while_statement.statement, depth + 1);
        break;

    case AST_DO_WHILE:
        printf("do\n");
        ast_print_statement(statement->while_statement.statement, depth + 1);
        TAB_PAD(depth);
        printf("while\n");
        TAB_PAD(depth);
        printf("(\n");
        ast_print_expression(statement->while_statement.condition, depth + 1);
        TAB_PAD(depth);
        printf(")\n");
        break;
    case AST_FOR:
        printf("for\n");
        TAB_PAD(depth);
        printf("(\n");
        if (statement->for_statement.init)
            ast_print_expression(statement->for_statement.init, depth + 1);
        TAB_PAD(depth);
        printf(";\n");
        if (statement->for_statement.condition)
            ast_print_expression(statement->for_statement.condition, depth + 1);
        TAB_PAD(depth);
        printf(";\n");
        if (statement->for_statement.final)
            ast_print_expression(statement->for_statement.final, depth + 1);
        TAB_PAD(depth);
        printf(")\n");
        TAB_PAD(depth);
        printf("do\n");
        ast_print_statement(statement->for_statement.statement, depth + 1);
        break;

    case AST_EXPRESSION:
        if (statement->expression_statement.expression)
        {
            printf("expression\n");
            ast_print_expression(statement->expression_statement.expression, depth + 1);
        }
        else
            printf("nop\n");
        break;
    case AST_CONTINUE:
        printf("continue (%p)\n", statement->break_statement.association);
        break;
    case AST_BREAK:
        printf("break (%p)\n", statement->break_statement.association);
        break;
    case AST_RETURN:
        printf("return\n");
        if (statement->return_statement.expression)
            ast_print_expression(statement->return_statement.expression, depth + 1);
        break;
    default:
        errorf("unknown statement %d", statement->kind);
    }
}
