#ifndef TYPES_INCLUDED
#define TYPES_INCLUDED

struct number;
typedef struct number number_t;

struct string;
typedef struct string string_t;

struct ast_node;
typedef struct ast_node ast_node_t;


#define NT_UNSIGNED 0b1000
#define NT_INT 0b0000
#define NT_LONG 0b0001
#define NT_LONG_LONG 0b0010
#define NT_FLOAT 0b0100
#define NT_DOUBLE 0b0101
#define NT_LONG_DOUBLE 0b0110

struct string {
    char *buffer;
    unsigned long long length;
    unsigned long long size;
};

struct number {
    union {
        unsigned long long integer;
        long double real;
    };
    union
    {
        char full_type;
        struct
        {
            char type : 2;
            char is_real : 1;
            char is_unsigned : 1;
        };
    };
};

#endif