#ifndef QUAD_H
#define QUAD_H

struct ast_node;
typedef struct ast_node ast_node_t;

enum quad_op
{
    NOP,      // no operation
    MOV,      // move
    CMOVP,    // move if plus
    CMOVM,    // move if minus
    CMOVZ,    // move if zero
    CMOVNZ,   // move if not zero
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
    CPL,      // ones complement
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
    JPM,      // jump if minus (<)
    JPZ,      // jump if zero (==)
    JPNZ,     // jump if not zero (!=)
};

static const char op_names[][16] = {
    "NOP",
    "MOV",
    "CMOVP",
    "CMOVM",
    "CMOVZ",
    "CMOVNZ",
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
    "JPM",
    "JPZ",
    "JPNZ",
};

// apparently quad_t is already reserved by something else.
typedef struct
{
    ast_node_t *dest;
    union
    {
        void *arg1;
        int jump_target;
    };
    void *arg2;
    enum quad_op op;
} bquad_t;

#define LIST_NAME basic_block
#define LIST_CONTENT_TYPE bquad_t *
#define LIST_ADDITIONAL_MEMBERS \
    char is_exit;
#include "list.inl"

#define LIST_NAME basic_block_list
#define LIST_CONTENT_TYPE basic_block_t *
#include "list.inl"

basic_block_list_t *generate_function_quads(ast_node_t *compound);
void print_basic_block_list(basic_block_list_t *bbl);

#endif