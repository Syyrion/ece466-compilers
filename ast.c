#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "ast.h"
#include "parser.tab.h"

ast_node_t *ast_new_ident(char *name)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_IDENT;
    new_inst->ident = name;
    return new_inst;
}
ast_node_t *ast_new_charlit(char c)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_CHARLIT;
    new_inst->charlit = c;
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

ast_node_t *ast_new_struct_or_union(int kind, char *name)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = kind;
    new_inst->ident = name;
    new_inst->struct_or_union.complete = 0;
    new_inst->struct_or_union.members = ast_list_new();
    return new_inst;
}

ast_node_t *ast_new_pointer(int type_qualifier)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_POINTER;
    new_inst->type_qualifier.full = (char)type_qualifier;
    new_inst->next = 0;
    return new_inst;
};

ast_node_t *ast_new_array(ast_node_t *size)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_ARRAY;
    new_inst->array_size = size;
    new_inst->next = 0;
    return new_inst;
};

ast_node_t *ast_new_scalar(type_specifier_t type_specifier, type_qualifier_t type_qualifier)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_SCALAR;
    new_inst->scalar = type_specifier.scalar;
    new_inst->next = type_specifier.custom;
    new_inst->type_qualifier = type_qualifier;
    return new_inst;
}

// converts an identifier into a variable
ast_node_t *ast_ident_to_variable(ast_node_t *node, storage_class_specifier_t storage_class_specifier)
{
    node->kind = AST_VARIABLE;
    node->storage_class = storage_class_specifier;
    return node;
}

ast_node_list_t *ast_list_new(void)
{
    ast_node_list_t *new_inst = calloc(1, sizeof(ast_node_list_t));
    return new_inst;
}

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

// ## Other stuff below

// recursively frees an ast_node
void ast_free(ast_node_t *node)
{
    switch (node->kind)
    {
    case AST_CHARLIT:
    case AST_NUMBERLIT:
        // these are stored inside the node itself so there's nothing to do
        break;
    case AST_IDENT:
        free(node->ident);
        break;
    case AST_STRINGLIT:
        free(node->stringlit.buffer);
        break;
    case AST_UNARY_OP:
        ast_free(node->unary_op.operand);
        break;
    case AST_BINARY_OP:
        ast_free(node->binary_op.left);
        ast_free(node->binary_op.right);
        break;
    case AST_TERNARY_OP:
        ast_free(node->ternary_op.condition);
        ast_free(node->ternary_op.true_branch);
        ast_free(node->ternary_op.false_branch);
        break;
    case AST_FUNCTION_CALL:
        ast_free(node->function_call.name);
        for (int i = 0; i < node->function_call.args->node_count; i++)
            ast_free(node->function_call.args->nodes[i]);
        ast_list_free(node->function_call.args);
        break;
    default:
        fprintf(stderr, "invalid ast node kind %d\n", node->kind);
        exit(88);
        break;
    }
    free(node);
}

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
        printf("IDENT \"%s\"\n", node->ident);
        break;
    case AST_CHARLIT:
        printf("CHARLIT \"%c\"\n", node->charlit);
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
    default:
        fprintf(stderr, "invalid ast node kind %d", node->kind);
        exit(88);
        break;
    }

#undef SUBSECTION
}

void ast_print_variable(ast_node_t *node)
{
    printf("The variable `%s` has storage class ", node->ident);
    print_storage_class(node->storage_class);
    printf("and is a(n)\n");
    int depth = 1;
    ast_node_t *current_node = node->next;

    while (current_node->kind != AST_SCALAR)
    {
        TAB_PAD(depth);
        switch (current_node->kind)
        {
        case AST_POINTER:
            print_type_qualifier(current_node->type_qualifier);
            printf("pointer to a(n)\n");
            /* code */
            break;

        case AST_ARRAY:
            if (current_node->array_size)
            {
                printf("array with size\n");
                TAB_PAD(depth);
                printf("[\n");
                ast_print_expression(current_node->array_size, depth + 1);
                TAB_PAD(depth);
                printf("]\n");
                TAB_PAD(depth);
            }
            else
            {
                printf("array with unknown size ");
            }
            printf("containing\n");
            break;

        default:
            printf("unknown");
            break;
        }
        current_node = current_node->next;
        depth++;
    }
    TAB_PAD(depth);
    print_type_qualifier(current_node->type_qualifier);
    print_scalar(current_node->scalar);
    printf("\n");
}
