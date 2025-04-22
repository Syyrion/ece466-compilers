#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "types.h"
#include "ast.h"
#include "parser.tab.h"
#include "location.h"

// keeps track of all created type nodes
static ast_node_list_t *type_list;

void ast_init(void)
{
    type_list = ast_list_new();
}

void ast_deinit(void)
{
    // TODO free stuff left behind
}

// Makes a new generic ast list
ast_node_list_t *ast_list_new(void)
{
    ast_node_list_t *new_inst = calloc(1, sizeof(ast_node_list_t));
    return new_inst;
}

// Appends an ast node to an ast list
ast_node_list_t *ast_list_add(ast_node_list_t *list, ast_node_t *node)
{
    if (list->nodes)
    {
        if (list->node_count == list->capacity)
            list->nodes = realloc(list->nodes, (list->capacity *= 2) * sizeof(ast_node_t *));
    }
    else
    {
        list->capacity = 1;
        list->nodes = malloc(sizeof(ast_node_t *));
    }
    list->nodes[list->node_count++] = node;
    return list;
}

// Frees a node list. Does not free any contained nodes.
void ast_list_free(ast_node_list_t *list)
{
    if (list->nodes)
        free(list->nodes);
    free(list);
}

// ## EXPRESSIONS

ast_node_t *ast_new_ident(char *name)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_IDENT;
    new_inst->name = name;
    return new_inst;
}

ast_node_t *ast_new_charlit(char c)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_NUMBERLIT;
    new_inst->numberlit.integer = c;
    new_inst->numberlit.type.full = TS_CHAR;
    return new_inst;
}

ast_node_t *ast_new_stringlit(string_t string)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_STRINGLIT;
    new_inst->stringlit = string;
    return new_inst;
}

ast_node_t *ast_new_numberlit(number_t number)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_NUMBERLIT;
    new_inst->numberlit = number;
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
    new_inst->type_cast.type;
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
    case AST_NUMBERLIT:
        // these are stored inside the node itself so there's nothing to do
        break;
    case AST_IDENT:
        free(node->name);
        break;
    case AST_STRINGLIT:
        free(node->stringlit.buffer);
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
        for (int i = 0; i < node->function_call.args->node_count; i++)
            ast_free_expression(node->function_call.args->nodes[i]);
        ast_list_free(node->function_call.args);
        break;
    case AST_TYPE_CAST:
        ast_free_expression(node->type_cast.operand);
        ast_free_variable(node->type_cast.type);
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
void ast_resolve_expression_variables(ast_node_t **node)
{
    switch ((*node)->kind)
    {
    case AST_IDENT:
        ast_node_t *var = st_find(NS_VARIABLE, (*node)->name);
        if (var)
        {
            free((*node)->name);
            free((*node));
            ast_mark_variable_as_used(var);
            *node = var;
            var->variable.used = 1;
        }
        else
        {
            fprintf(stderr, "%s:%d: the variable %s doesn't exist\n", filename, line_num, (*node)->name);
            exit(EXIT_FAILURE);
        }
        break;
    case AST_UNARY_OP:
        ast_resolve_expression_variables(&(*node)->unary_op.operand);
        break;
    case AST_BINARY_OP:
        ast_resolve_expression_variables(&(*node)->binary_op.left);
        ast_resolve_expression_variables(&(*node)->binary_op.right);
        break;
    case AST_TERNARY_OP:
        ast_resolve_expression_variables(&(*node)->ternary_op.condition);
        ast_resolve_expression_variables(&(*node)->ternary_op.true_branch);
        ast_resolve_expression_variables(&(*node)->ternary_op.false_branch);
        break;
    case AST_TYPE_CAST:
        ast_resolve_expression_variables(&(*node)->type_cast.operand);
        break;
    case AST_MEMBER_ACCESS:
        ast_resolve_expression_variables(&(*node)->member_access.operand);
        break;
    case AST_FUNCTION_CALL:
        ast_resolve_expression_variables(&(*node)->function_call.name);
        for (int i = 0; i < (*node)->function_call.args->node_count; i++)
            ast_resolve_expression_variables(&(*node)->function_call.args->nodes[i]);

    case AST_STRINGLIT:
    case AST_NUMBERLIT:
        break;
    default:
        fprintf(stderr, "failed to resolve expression %d\n", (*node)->kind);
        exit(EXIT_FAILURE);
        break;
    }
}

// ## STRUCTS

// Makes a new struct. Set members to 0 for an incomplete struct
ast_node_t *ast_new_struct_or_union(int kind, char *name, ast_node_list_t *members)
{
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
    for (int i = 0; i < node->structure.members->node_count; i++)
    {
        ast_node_t *m = node->structure.members->nodes[i];
        if (m->member.bit_width)
            ast_free_expression(m->member.bit_width);
        if (m->member.isa)
            ast_free_variable(m->member.isa);
        if (m->member.name)
            free(m->member.name);
    }
    ast_list_free(node->structure.members);
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
    ast_list_add(type_list, new_inst);
    return new_inst;
}

// Frees a variable. Doesn't free the AST_TYPE at the end since other variables might be using it.
void ast_free_variable(ast_node_t *var)
{
    ast_node_t *current = var, *temp;

    while (current->kind != AST_TYPE)
    {
        switch (current->kind)
        {
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
                for (int i = 0; i < current->function.parameters->node_count; i++)
                    ast_free_variable(current->function.parameters->nodes[i]);
            break;
        default:
            fprintf(stderr, "can't free node kind %d for variable\n", current->kind);
            exit(EXIT_FAILURE);
            break;
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
                if (current_a->function.parameters->node_count != current_b->function.parameters->node_count)
                    return 0;
                for (int i = 0; i < current_a->function.parameters->node_count; i++)
                    if (!ast_are_variables_compatible(current_a->function.parameters->nodes[i], current_b->function.parameters->nodes[i]))
                        return 0;
            }
            break;
        default:
            fprintf(stderr, "cannot check compatibility");
            exit(EXIT_FAILURE);
            break;
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
                for (int i = 0; i < current_a->function.parameters->node_count; i++)
                    ast_merge_into_variable(current_a->function.parameters->nodes[i], current_b->function.parameters->nodes[i]);
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
            fprintf(stderr, "cannot merge");
            exit(EXIT_FAILURE);
            break;
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
    new_inst->switch_statement.cases = ast_list_new();
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

#define TAB_PAD(depth)                  \
    {                                   \
        for (int i = 0; i < depth; i++) \
            printf("    ");             \
    }

void ast_print_expression(ast_node_t *node, const unsigned int depth)
{

#define SUBSECTION(name, where)                 \
    {                                           \
        TAB_PAD(depth);                         \
        printf(".%s\n", name);                  \
        ast_print_expression(where, depth + 1); \
    }

    TAB_PAD(depth);
    switch (node->kind)
    {
    case AST_IDENT:
        printf("IDENT \"%s\"\n", node->name);
        break;
    case AST_STRINGLIT:
        printf("STRINGLIT \"");
        print_stringlit(node->stringlit);
        printf("\"\n");
        break;
    case AST_NUMBERLIT:
        printf("NUMBERLIT    ");
        print_numberlit(node->numberlit);
        printf("\n");
        break;
    case AST_UNARY_OP:
        printf("UNARY_OP \"");
        print_operator(node->unary_op.kind);
        printf("\"\n");
        SUBSECTION("operand", node->unary_op.operand);
        break;
    case AST_MEMBER_ACCESS:
        printf("MEMBER_ACCESS %s\n", node->member_access.ident);
        SUBSECTION("operand", node->member_access.operand);
        break;
    case AST_BINARY_OP:
        printf("BINARY_OP \"");
        print_operator(node->binary_op.kind);
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
        for (int i = 0; i < node->function_call.args->node_count; i++)
        {
            char b[16];
            snprintf(b, sizeof(b), "arg[%d]", i);
            SUBSECTION(b, node->function_call.args->nodes[i]);
        }
        break;
    case AST_TYPE_CAST:
        printf("TYPE_CAST");
        TAB_PAD(depth);
        printf(".type\n");
        ast_print_declarator(node->type_cast.type, depth + 1);
        SUBSECTION("operand", node->type_cast.operand);
        break;
    case AST_VARIABLE:
        printf("VARIABLE (resolved) \"%s\"\n", node->name);
        break;
    default:
        fprintf(stderr, "can't print node kind %d for expression\n", node->kind);
        exit(EXIT_FAILURE);
        break;
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
                for (unsigned int i = 0, j = current_node->function.parameters->node_count; i < j; i++)
                {
                    ast_print_variable(current_node->function.parameters->nodes[i], depth + 1);
                }
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
        for (int i = 0; i < node->structure.members->node_count; i++)
        {
            print_member(node->structure.members->nodes[i], 1);
        }
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
        for (int i = 0; i < statement->compound_statement.sub_statements->node_count; i++)
            ast_print_statement(statement->compound_statement.sub_statements->nodes[i], depth + 1);
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
        fprintf(stderr, "unknown statement %d\n", statement->kind);
        exit(EXIT_FAILURE);
        break;
    }
}
