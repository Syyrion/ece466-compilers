#ifndef QUAD_API_INCLUDED
#define QUAD_API_INCLUDED

#include "ast.h"

// apparently quad_t is already reserved by something else.
struct quad;
typedef struct quad bquad_t;

struct basic_block;
typedef struct basic_block basic_block_t;

struct basic_block_list;
typedef struct basic_block_list basic_block_list_t;

enum quad_op
{
    NOP,
    MOV,    // move
    CMOVP,  // move if plus
    CMOVM,  // move if minus
    CMOVZ,  // move if zero
    CMOVNZ, // move if not zero
    LEA,    // load effective address
    LOAD,   // load from address
    STORE,  // store to address
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
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

struct quad
{
    ast_node_t *dest;
    union
    {
        void *arg1;
        int jump_target;
    };
    void *arg2;
    enum quad_op op;
};

struct basic_block
{
    unsigned long capacity;
    unsigned long quad_count;
    bquad_t **quads;
    char is_exit;
};

struct basic_block_list
{
    unsigned long capacity;
    unsigned long block_count;
    basic_block_t **blocks;
};

basic_block_list_t *generate_function_quads(ast_node_t *compound);
void print_basic_block_list(basic_block_list_t *bbl);

#endif