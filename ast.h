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
    AST_TYPE_CAST,
    AST_FUNCTION_CALL,

    AST_STRUCT,
    AST_UNION,
    AST_MEMBER,

    AST_VARIABLE,
    AST_POINTER,
    AST_ARRAY,
    AST_FUNCTION,
    AST_TYPE,

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

struct ast_type_cast
{
    ast_node_t *operand;
    ast_node_t *type;
};

struct ast_struct_or_union
{
    char *name;
    ast_node_list_t *members;
};

struct ast_member
{
    char *name;
    ast_node_t *isa;
    ast_node_t *bit_width;
};

struct ast_variable
{
    char *name;
    ast_node_t *isa;
    storage_class_specifier_t storage_class;
};

struct ast_pointer
{
    unsigned long : sizeof(char *) * 8;
    ast_node_t *to;
    type_qualifier_t type_qualifier;
};

struct ast_array
{
    unsigned long : sizeof(char *) * 8;
    ast_node_t *of;
    ast_node_t *size;
};

struct ast_function
{
    unsigned long : sizeof(char *) * 8;
    ast_node_t *returns;
    ast_node_list_t *parameters;
    function_specifier_t specifier; // not fully implemented
    function_definition_t definition;
};

struct ast_type
{
    type_specifier_t specifier;
    type_qualifier_t qualifier;
};

struct ast_node
{
    ast_node_kind_t kind;
    union
    {
        struct // generic members
        {
            char *name;
            ast_node_t *next;
        };
        char charlit;
        string_t stringlit;
        number_t numberlit;

        struct ast_unary_op unary_op;
        struct ast_binary_op binary_op;
        struct ast_ternary_op ternary_op;
        struct ast_type_cast type_cast;
        struct ast_function_call function_call;

        struct ast_struct_or_union structure;
        struct ast_member member;

        struct ast_variable variable;
        struct ast_pointer pointer;
        struct ast_array array;
        struct ast_function function;
        struct ast_type type;
    };
};

// generic list of ast_node_t
struct ast_node_list
{
    unsigned long capacity;
    unsigned long node_count;
    ast_node_t **nodes;
};

void ast_init(void);
void ast_deinit(void);

ast_node_list_t *ast_list_new(void);
ast_node_list_t *ast_list_add(ast_node_list_t *list, ast_node_t *node);
void ast_list_free(ast_node_list_t *list);

ast_node_t *ast_new_ident(char *name);
ast_node_t *ast_new_charlit(char c);
ast_node_t *ast_new_stringlit(string_t string);
ast_node_t *ast_new_numberlit(number_t number);
ast_node_t *ast_new_unary_op(int kind, ast_node_t *operand);
ast_node_t *ast_new_binary_op(int kind, ast_node_t *left, ast_node_t *right);
ast_node_t *ast_new_ternary_op(ast_node_t *condition, ast_node_t *true_branch, ast_node_t *false_branch);
ast_node_t *ast_new_function_call(ast_node_t *name, ast_node_list_t *args);
ast_node_t *ast_new_type_cast(ast_node_t *operand, ast_node_t *type);
void ast_free_expression(ast_node_t *node);

ast_node_t *ast_new_struct_or_union(int kind, char *name, ast_node_list_t *members);
ast_node_t *ast_add_struct_or_union_members(ast_node_t *node, ast_node_list_t *members);
ast_node_t *ast_ident_to_member(ast_node_t *node, ast_node_t *bit_width);
ast_node_t *ast_new_padding_member(ast_node_t *bit_width);

ast_node_t *ast_ident_to_variable(ast_node_t *node, storage_class_specifier_t storage_class_specifier);
ast_node_t *ast_new_pointer(int type_qualifier);
ast_node_t *ast_new_array(ast_node_t *size);
ast_node_t *ast_new_function(ast_node_list_t *paramter_list);
ast_node_t *ast_new_type(type_specifier_t type_specifier, type_qualifier_t type_qualifier);
void ast_free_variable(ast_node_t *var);

int ast_are_variables_compatible(ast_node_t *a, ast_node_t *b);
void ast_merge_into_variable(ast_node_t *a, ast_node_t *b);

void ast_print_expression(ast_node_t *node, const unsigned int depth);
void ast_print_variable(ast_node_t *node, unsigned int depth);
void ast_print_struct_or_union(ast_node_t *node);
void ast_print_declarator(ast_node_t *node, unsigned int depth);

#endif
