#ifndef AST_API_INCLUDED
#define AST_API_INCLUDED

#include "types.h"

typedef enum
{
    AST_IDENT,
    AST_STRINGLIT,
    AST_NUMBERLIT,

    AST_UNARY_OP,
    AST_BINARY_OP,
    AST_TERNARY_OP,
    AST_MEMBER_ACCESS,
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

    AST_COMPOUND,
    AST_EXPRESSION,
    AST_IF,
    AST_SWITCH,
    AST_CASE,
    AST_WHILE,
    AST_DO_WHILE,
    AST_FOR,
    AST_GOTO,
    AST_CONTINUE,
    AST_BREAK,
    AST_RETURN,

    AST_LABEL,

    AST_TEMPORARY,

    // AST_TYPEDEF_NAME, // not implemented
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

struct ast_member_access
{
    ast_node_t *operand;
    char *ident;
};

struct ast_struct_or_union
{
    char *name;
    ast_node_list_t *members;
    char used;
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
    char used;
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
    ast_node_t *definition;         // a compound statement
};

struct ast_type
{
    type_specifier_t specifier;
    type_qualifier_t qualifier;
};

struct ast_compound
{
    ast_node_list_t *sub_statements;
};

struct ast_expression
{
    ast_node_t *expression;
};

struct ast_if_else
{
    ast_node_t *condition;
    ast_node_t *true_branch;
    ast_node_t *false_branch;
};

struct ast_switch
{
    unsigned long : sizeof(char *) * 8;
    unsigned long : sizeof(char *) * 8;

    ast_node_t *expression;
    ast_node_list_t *cases;
    ast_node_t *default_case;
    ast_node_t *statement;
};

struct ast_switch_case
{
    ast_node_t *constant_expression;
    ast_node_t *statement;
};

struct ast_while
{
    unsigned long : sizeof(char *) * 8;
    unsigned long : sizeof(char *) * 8;
    void *extra;

    ast_node_t *condition;
    ast_node_t *statement;
};

struct ast_for
{
    unsigned long : sizeof(char *) * 8;
    unsigned long : sizeof(char *) * 8;
    void *extra;

    ast_node_t *init;
    ast_node_t *condition;
    ast_node_t *final;
    ast_node_t *statement;
};

union ast_goto
{
    char *label_name;
    ast_node_t *statement;
};

struct ast_continue
{
    ast_node_t *association;
};

struct ast_break
{
    ast_node_t *association;
};

struct ast_return
{
    ast_node_t *expression;
};

struct ast_label
{
    char *name;
    ast_node_t *statement;
};

struct ast_temporary
{
    unsigned long : sizeof(char *) * 8;
    ast_node_t *isa;
    unsigned long num;
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
            void *extra;
        };
        string_t stringlit;
        number_t numberlit;

        struct ast_unary_op unary_op;
        struct ast_binary_op binary_op;
        struct ast_ternary_op ternary_op;
        struct ast_type_cast type_cast;
        struct ast_member_access member_access;
        struct ast_function_call function_call;

        struct ast_struct_or_union structure;
        struct ast_member member;

        struct ast_variable variable;
        struct ast_pointer pointer;
        struct ast_array array;
        struct ast_function function;
        struct ast_type type;

        struct ast_compound compound_statement;
        struct ast_expression expression_statement;
        struct ast_if_else if_statement;
        struct ast_switch switch_statement;
        struct ast_switch_case switch_case;
        struct ast_while while_statement;
        struct ast_for for_statement;
        union ast_goto goto_statement;
        struct ast_continue continue_statement;
        struct ast_break break_statement;
        struct ast_return return_statement;
        struct ast_label label;
        struct ast_temporary temporary;
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
ast_node_t *ast_new_member_access(ast_node_t *operand, char *ident);
void ast_free_expression(ast_node_t *node);
void ast_resolve_expression_variables(ast_node_t **node, char ignore_on_failure);
long ast_evaluate_constant_expression(ast_node_t *expr);
unsigned long ast_get_sizeof_value(ast_node_t *node);

ast_node_t *ast_new_struct_or_union(int kind, char *name, ast_node_list_t *members);
ast_node_t *ast_add_struct_or_union_members(ast_node_t *node, ast_node_list_t *members);
ast_node_t *ast_ident_to_member(ast_node_t *node, ast_node_t *bit_width);
ast_node_t *ast_new_padding_member(ast_node_t *bit_width);
void ast_free_struct(ast_node_t *node);

ast_node_t *ast_ident_to_variable(ast_node_t *node, storage_class_specifier_t storage_class_specifier);
ast_node_t *ast_new_pointer(int type_qualifier);
ast_node_t *ast_new_array(ast_node_t *size);
ast_node_t *ast_new_function(ast_node_list_t *paramter_list);
ast_node_t *ast_new_type(type_specifier_t type_specifier, type_qualifier_t type_qualifier);
void ast_free_variable(ast_node_t *var);

int ast_are_variables_compatible(ast_node_t *a, ast_node_t *b);
void ast_merge_into_variable(ast_node_t *a, ast_node_t *b);
int ast_is_array(ast_node_t *var);
int ast_is_pointer(ast_node_t *var);

ast_node_t *ast_new_compound_statement(ast_node_list_t *statements);
ast_node_t *ast_new_expression_statement(ast_node_t *expr);
ast_node_t *ast_new_if_statement(ast_node_t *condition, ast_node_t *true_statement, ast_node_t *false_statement);
ast_node_t *ast_new_switch_statement(ast_node_t *expression, ast_node_t *statement);
ast_node_t *ast_new_switch_case(ast_node_t *constant_expression, ast_node_t *statement);
ast_node_t *ast_new_while_statement(int kind, ast_node_t *condition, ast_node_t *statement);
ast_node_t *ast_new_for_statement(ast_node_t *init, ast_node_t *condition, ast_node_t *final, ast_node_t *statement);
ast_node_t *ast_new_goto_statement(char *label);
ast_node_t *ast_new_continue_statement(ast_node_t *assocoation);
ast_node_t *ast_new_break_statement(ast_node_t *assocoation);
ast_node_t *ast_new_return_statement(ast_node_t *expr);
ast_node_t *ast_new_label(char *label, ast_node_t *statement);

void ast_print_expression(ast_node_t *node, const unsigned int depth);
void ast_print_variable(ast_node_t *node, unsigned int depth);
void ast_print_struct_or_union(ast_node_t *node);
void ast_print_declarator(ast_node_t *node, unsigned int depth);
void ast_print_statement(ast_node_t *statement, int depth);

#endif
