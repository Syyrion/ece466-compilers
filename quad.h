#ifndef QUAD_H
#define QUAD_H

#include "literal.h"

struct ast_node;
typedef struct ast_node ast_node_t;

// preprocessor jank
#ifdef LIST_IMPLEMENT
#undef LIST_IMPLEMENT
#include "ast.h"
#define LIST_IMPLEMENT
#else
#include "ast.h"
#endif

enum quad_op
{
    NOP,      // no operation
    MOV,      // move
    SETP,     // set if plus (>)
    SETNP,    // set if not plus (<=)
    SETM,     // set if minus (<)
    SETNM,    // set if not minus (>=)
    SETZ,     // set if zero (==)
    SETNZ,    // set if not zero (!=)
    LEA,      // load effective address
    LOAD,     // load from address
    STORE,    // store to address
    ADD,      // add
    SUB,      // subtract
    MUL,      // multiply
    DIV,      // divide
    MOD,      // modulo
    NEG,      // two's complement
    SL,       // shift left
    SR,       // shift right
    CPL,      // one's complement
    AND,      // bitwise and
    OR,       // bitwise or
    XOR,      // bitwise xor
    CMP,      // compare
    ARGBEGIN, // begin arguments
    ARG,      // add an argument
    CALL,     // call a function
    RET,      // return from a function
    JP,       // unconditional jump
    JPP,      // jump if plus (>)
    JPNP,     // jump if plus (<=)
    JPM,      // jump if minus (<)
    JPNM,     // jump if minus (>=)
    JPZ,      // jump if zero (==)
    JPNZ,     // jump if not zero (!=)
};

static const char op_names[][16] = {
    "NOP",
    "MOV",
    "SETP",
    "SETNP",
    "SETM",
    "SETNM",
    "SETZ",
    "SETNZ",
    "LEA",
    "LOAD",
    "STORE",
    "ADD",
    "SUB",
    "MUL",
    "DIV",
    "MOD",
    "NEG",
    "SL",
    "SR",
    "CPL",
    "AND",
    "OR",
    "XOR",
    "CMP",
    "ARGBEGIN",
    "ARG",
    "CALL",
    "RET",
    "JP",
    "JPP",
    "JPNP",
    "JPM",
    "JPNM",
    "JPZ",
    "JPNZ",
};

// apparently quad_t is already reserved by something else.
typedef struct
{
    ast_node_t *dest;
    union
    {
        ast_node_t *arg1;
        int jump_target;
    };
    ast_node_t *arg2;
    enum quad_op op;
} bquad_t;

#define LIST_NAME basic_block
#define LIST_CONTENT_TYPE bquad_t *
#define LIST_ADDITIONAL_MEMBERS \
    char is_exit;
#include "list.inl"

#define LIST_NAME basic_block_list
#define LIST_CONTENT_TYPE basic_block_t *
#define LIST_ADDITIONAL_MEMBERS           \
    unsigned long temp_var_count;         \
    unsigned long variable_count;         \
    unsigned long argument_count;         \
    ast_node_list_t *string_literal_list; \
    char *name;
#include "list.inl"

basic_block_list_t *generate_function_quads(ast_node_t *compound);
void print_basic_block_list(basic_block_list_t *bbl);

#endif