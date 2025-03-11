#ifndef AST_API_INCLUDED
#define AST_API_INCLUDED

#include "types.h"

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

    AST_VARIABLE,
    AST_STRUCT,
    AST_UNION,
    AST_MEMBER,
    AST_LABEL,        // not implemented
    AST_TYPEDEF_NAME, // not implemented
} ast_node_kind_t;

struct ast_unary_op
{
    int kind;
    ast_node_t *operand;
};

struct ast_binary_op
{
    int kind;
    ast_node_t *left;
    ast_node_t *right;
};

struct ast_ternary_op
{
    ast_node_t *condition;
    ast_node_t *true_branch;
    ast_node_t *false_branch;
};

struct ast_function_call
{
    ast_node_t *name;
    ast_node_list_t *args;
};

struct ast_variable
{
    ast_node_t *type;
    type_specifier_t type_specifier;
    type_qualifier_t type_qualifier;
    storage_class_specifier_t storage_class;
    function_specifier_t function_specifier;
    char sc_is_set;
};

struct ast_struct_or_union
{
    unsigned long member_capacity;
    unsigned long member_count;
    ast_node_t **members;
};

struct ast_member
{
    type_specifier_t type_specifier;
    type_qualifier_t type_qualifier;
};

struct ast_node
{
    ast_node_kind_t kind;
    char *ident; // also used as a name for symbol table lookup
    union
    {
        struct ast_unary_op unary_op;
        struct ast_binary_op binary_op;
        struct ast_ternary_op ternary_op;
        struct ast_function_call function_call;

        struct ast_variable variable;
        struct ast_struct_or_union struct_or_union;
        struct ast_member member;

        char charlit;
        string_t stringlit;
        number_t numberlit;
    };
};

// generic list of ast_node_t
struct ast_node_list
{
    unsigned long capacity;
    unsigned long node_count;
    ast_node_t **nodes;
};

ast_node_t *ast_new_ident(char *name);
ast_node_t *ast_new_charlit(char c);
ast_node_t *ast_new_stringlit(string_t string);
ast_node_t *ast_new_numberlit(number_t number);
ast_node_t *ast_new_unary_op(int kind, ast_node_t *operand);
ast_node_t *ast_new_binary_op(int kind, ast_node_t *left, ast_node_t *right);
ast_node_t *ast_new_ternary_op(ast_node_t *condition, ast_node_t *true_branch, ast_node_t *false_branch);
ast_node_t *ast_new_function_call(ast_node_t *name, ast_node_list_t *args);

ast_node_t *ast_new_variable();
ast_node_t *ast_add_variable_type_qualifier(ast_node_t *variable, char type_qualifiers);
ast_node_t *ast_set_variable_storage_class(ast_node_t *variable, storage_class_specifier_t storage_class);
ast_node_t *ast_set_variable_function_specifier(ast_node_t * variable, function_specifier_t function_specifier);
ast_node_t *ast_add_variable_type_specifier(ast_node_t *variable, type_specifier_t type_specifier);

ast_node_list_t *ast_list_new(void);
ast_node_list_t *ast_list_add(ast_node_list_t *list, ast_node_t* node);
void ast_list_free(ast_node_list_t *list);

void ast_free(ast_node_t *node);
void ast_print(ast_node_t *node, const unsigned int depth);

#endif
