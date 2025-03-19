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

    AST_POINTER,
    AST_ARRAY,
    AST_FUNCTION,
    AST_SCALAR,
    
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

struct ast_node
{
    ast_node_kind_t kind;
    char *ident; // also used as a name for symbol table lookup
    ast_node_t *next; // generic "next" pointer used by declarators
    union
    {
        struct ast_unary_op unary_op;
        struct ast_binary_op binary_op;
        struct ast_ternary_op ternary_op;
        struct ast_function_call function_call;

        
        ast_node_list_t *members; // used by AST_STRUCT or AST_UNION
        ast_node_t *bit_width; // used by AST_MEMBER

        storage_class_specifier_t storage_class; // used by AST_VARIABLE
        
        ast_node_t *array_size; // used by AST_ARRAY
        
        struct { // used by AST_FUNCTION
            ast_node_list_t *function_arguments;
            function_specifier_t function_specifier;
        };

        struct { // used by AST_SCALAR
            scalar_t scalar; // primitive scalars. structs, unions, and enums are found in the "next" field
            type_qualifier_t type_qualifier; // used by AST_POINTER also ;)
        };

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

ast_node_t *ast_new_pointer(int type_qualifier);
ast_node_t *ast_new_array(ast_node_t *size);
ast_node_t *ast_new_scalar(type_specifier_t type_specifier, type_qualifier_t type_qualifier);
ast_node_t *ast_ident_to_variable(ast_node_t *node, storage_class_specifier_t storage_class_specifier);

ast_node_t *ast_new_struct_or_union(int kind, char *name, ast_node_list_t *members);
ast_node_t *ast_add_struct_or_union_members(ast_node_t *node, ast_node_list_t *members);
ast_node_t *ast_ident_to_member(ast_node_t *node, ast_node_t *bit_width);
ast_node_t *ast_new_padding_member(ast_node_t *bit_width);

ast_node_list_t *ast_list_new(void);
ast_node_list_t *ast_list_add(ast_node_list_t *list, ast_node_t *node);
void ast_list_free(ast_node_list_t *list);

void ast_free(ast_node_t *node);
void ast_print_expression(ast_node_t *node, const unsigned int depth);
void ast_print_variable(ast_node_t *node);
void ast_print_struct_or_union(ast_node_t *node);

#endif
