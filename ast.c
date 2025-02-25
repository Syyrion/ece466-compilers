#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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
    default:
        fprintf(stderr, "invalid ast node kind %d", node->kind);
        exit(88);
        break;
    }
    free(node);
}

// Returns a null terminated array of ast nodes made by unreducing a left sided tree of equivalent binary operations.
// All branches should exist.
ast_node_t **ast_left_unreduce(ast_node_t *node)
{
    // unreduce only works on binary operations
    if (node->kind != AST_BINARY_OP)
        return 0;

    // the operator we're unreducing
    const int op = node->binary_op.kind;

    // a reversed list of nodes
    int node_index = 0;
    int reverse_list_size = 2;
    ast_node_t **reverse_list = malloc(sizeof(ast_node_t *) * reverse_list_size);

    ast_node_t *current_node = node;
    do
    {
        // add the right side to the list
        reverse_list[node_index++] = current_node->binary_op.right;
        if (node_index == reverse_list_size)
            reverse_list = realloc(reverse_list, reverse_list_size *= 2);

        // check the left node to see if we can continue
        current_node = current_node->binary_op.left;
    } while (current_node && current_node->kind == AST_BINARY_OP && current_node->binary_op.kind == op);

    // if not then add the left to the reverse_list
    reverse_list[node_index++] = current_node;

    // make a forward_list
    ast_node_t **forward_list = malloc(sizeof(ast_node_t *) * node_index + 1);
    for (int i = 0, j = node_index - 1; i < node_index; i++, j--)
        forward_list[i] = reverse_list[j];
    forward_list[node_index] = 0;

    free(reverse_list);
    return forward_list;
}

static void print_stringlit(string_t string)
{
    const char *s = string.buffer;
    for (int i = 0; i < string.length; i++)
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

static void print_numberlit(number_t number)
{
    if (number.is_real)
    {
        printf(
            "REAL    %Lg    %s",
            number.real,
            number.type == 0   ? "FLOAT"
            : number.type == 1 ? "DOUBLE"
                               : "LONG DOUBLE");
    }
    else
    {
        printf(
            "INTEGER    %lld    %s%s",
            number.integer,
            number.is_unsigned ? "UNSIGNED " : "",
            number.type == 0   ? "INT"
            : number.type == 1 ? "LONG"
                               : "LONG LONG");
    }
}

static void print_operator(int op)
{
    if (isprint(op))
    {
        fputc(op, stdout);
        return;
    }
    switch (op)
    {
    case SHL:
        printf("<<");
        break;
    case SHR:
        printf(">>");
        break;
    case LTEQ:
        printf("<=");
        break;
    case GTEQ:
        printf(">=");
        break;
    case EQEQ:
        printf("==");
        break;
    case NOTEQ:
        printf("!=");
        break;
    case LOGAND:
        printf("&&");
        break;
    case LOGOR:
        printf("||");
        break;
    case PLUSEQ:
        printf("+=");
        break;
    case MINUSEQ:
        printf("-=");
        break;
    case TIMESEQ:
        printf("*=");
        break;
    case DIVEQ:
        printf("/=");
        break;
    case MODEQ:
        printf("%=");
        break;
    case SHLEQ:
        printf("<<=");
        break;
    case SHREQ:
        printf(">>=");
        break;
    case ANDEQ:
        printf("&=");
        break;
    case XOREQ:
        printf("^=");
        break;
    case OREQ:
        printf("|=");
        break;
    case SIZEOF:
        printf("sizeof");
        break;
    case ALIGNOF:
        printf("alignof");
        break;
    case PLUSPLUS:
        printf("++");
        break;
    case MINUSMINUS:
        printf("--");
        break;
    case FUNCTION_CALL:
        printf("()");
        break;
    default:
        fprintf(stderr, "attempted to print operator with unknown id %d", op);
        printf("<unknown operator %d>", op);
        break;
    }
}

void ast_print(ast_node_t *node, const unsigned int depth)
{
#define TAB_PAD                         \
    {                                   \
        for (int i = 0; i < depth; i++) \
            printf("    ");             \
    }

#define SUBSECTION(name, where)      \
    {                                \
        TAB_PAD;                     \
        printf(".%s\n", name);       \
        ast_print(where, depth + 1); \
    }

    TAB_PAD;
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
        // binary operations handle function calls too
        if (node->binary_op.kind == FUNCTION_CALL)
        {
            printf("FUNCTION_CALL\n");
            SUBSECTION("name", node->binary_op.left);
            char tag[128];
            ast_node_t **args = ast_left_unreduce(node->binary_op.right);
            for (int i = 0; args[i] != 0; i++)
            {
                snprintf(tag, sizeof(tag), "arg[%d]", i);
                SUBSECTION(tag, args[i]);
            }
        }
        else
        {
            printf("BINARY_OP \"");
            print_operator(node->binary_op.kind);
            printf("\"\n");
            SUBSECTION("left", node->binary_op.left);
            SUBSECTION("right", node->binary_op.right);
        }
        break;
    case AST_TERNARY_OP:
        printf("TERNARY_OP\n");
        SUBSECTION("condition", node->ternary_op.condition);
        SUBSECTION("true_branch", node->ternary_op.true_branch);
        SUBSECTION("false_branch", node->ternary_op.false_branch);
        break;
    default:
        fprintf(stderr, "invalid ast node kind %d", node->kind);
        exit(88);
        break;
    }

#undef SUBSECTION
#undef TAB_PAD
}
