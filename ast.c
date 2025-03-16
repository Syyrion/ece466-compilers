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
    new_inst->pointer_qualifiers.full = (char)type_qualifier;
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

ast_node_t *ast_new_scalar(scalar_t scalar)
{
    ast_node_t *new_inst = malloc(sizeof(ast_node_t));
    new_inst->kind = AST_SCALAR;
    new_inst->scalar = scalar;
    return new_inst;
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
    if (number.type.full & TS_REAL)
    {
        printf(
            "REAL    %Lg    %s",
            number.real,
            number.type.long_bit     ? "LONG DOUBLE"
            : number.type.double_bit ? "DOUBLE"
                                     : "FLOAT");
    }
    else
    {
        printf(
            "INTEGER    %lld    %s%s",
            number.integer,
            number.type.unsigned_bit ? "UNSIGNED " : "",
            number.type.long2_bit       ? "LONG LONG"
            : number.type.long_bit == 1 ? "LONG"
                                        : "INT");
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
#undef TAB_PAD
}
