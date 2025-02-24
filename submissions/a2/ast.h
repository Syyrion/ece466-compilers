#ifndef AST_API_INCLUDED
#define AST_API_INCLUDED

#include "types.h"
#include "parser.tab.h"
#include "ast.h"

typedef enum
{
    AST_IDENT,
    AST_CHARLIT,
    AST_STRINGLIT,
    AST_NUMBERLIT,
    AST_UNARY_OP,
    AST_BINARY_OP,
    AST_TERNARY_OP,
    AST_FUNCTION_CALL,
} ast_node_kind_t;

struct ast_unary_op
{
    yytoken_kind_t kind;
    ast_node_t *operand;
};

struct ast_binary_op
{
    yytoken_kind_t kind;
    ast_node_t *left;
    ast_node_t *right;
};

struct ast_ternary_op
{
    ast_node_t *condition;
    ast_node_t *true_branch;
    ast_node_t *false_branch;
};

struct ast_node
{
    ast_node_kind_t kind;
    union
    {
        struct ast_unary_op unary_op;
        struct ast_binary_op binary_op;
        struct ast_ternary_op ternary_op;

        char *ident;
        char charlit;
        string_t stringlit;
        number_t numberlit;
    };
};

ast_node_t *ast_new_ident(char *name);
ast_node_t *ast_new_charlit(char c);
ast_node_t *ast_new_stringlit(string_t string);
ast_node_t *ast_new_numberlit(number_t number);
ast_node_t *ast_new_unary_op(yytoken_kind_t kind, ast_node_t *operand);
ast_node_t *ast_new_binary_op(yytoken_kind_t kind, ast_node_t *left, ast_node_t *right);
ast_node_t *ast_new_ternary_op(ast_node_t *condition, ast_node_t *true_branch, ast_node_t *false_branch);
void ast_free(ast_node_t *node);
void ast_print(ast_node_t *node, const unsigned int depth);

#endif
