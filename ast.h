#include "parser.tab.h"

typedef enum {
    AST_UNARYOP,
    AST_BINARYOP,
    AST_TERNARYOP,
    AST_NUM,
    AST_IDENT,
} ast_node_t;




struct ast_unary_op
{
    yytoken_kind_t kind;
};

struct ast_binary_op
{
    
};

struct ast_ternary_op
{
    
};

struct ast_num
{
    
};

struct ast_ident
{
    /* data */
};


typedef struct {
    ast_node_t type;
    union
    {
        struct ast_unary_op as_unaryop;
    };
} ast_node;


