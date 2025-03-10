#ifndef TYPES_INCLUDED
#define TYPES_INCLUDED

struct number;
typedef struct number number_t;

struct string;
typedef struct string string_t;

struct ast_node;
typedef struct ast_node ast_node_t;

// scalar types
#define SCLR_VOID 0b00000000000001
#define SCLR_CHAR 0b00000000000010
#define SCLR_SHORT 0b00000000000100
#define SCLR_INT 0b00000000001000
#define SCLR_LONG 0b00000000010000
#define SCLR_LONG2 0b00000000100000
#define SCLR_FLOAT 0b00000001000000
#define SCLR_DOUBLE 0b00000010000000
#define SCLR_SIGNED 0b00000100000000
#define SCLR_UNSIGNED 0b00001000000000
#define SCLR_BOOL 0b00010000000000
#define SCLR_COMPLEX 0b00100000000000
#define SCLR_STRUCT_OR_UNION 0b01000000000000
#define SCLR_ENUM 0b10000000000000
#define SCLR_CUSTOM SCLR_STRUCT_OR_UNION | SCLR_ENUM
#define SCLR_REAL SCLR_FLOAT | SCLR_DOUBLE

// encoded semantic rules for type specifiers
static const unsigned short SCLR_VALID[] = {
    // giga-pain

    SCLR_VOID,

    SCLR_CHAR,
    SCLR_SIGNED | SCLR_CHAR,
    SCLR_UNSIGNED | SCLR_CHAR,

    SCLR_SHORT,
    SCLR_SIGNED | SCLR_SHORT,
    SCLR_SHORT | SCLR_INT,
    SCLR_SIGNED | SCLR_SHORT | SCLR_INT,

    SCLR_UNSIGNED | SCLR_SHORT,
    SCLR_UNSIGNED | SCLR_SHORT | SCLR_INT,

    SCLR_INT,
    SCLR_SIGNED,
    SCLR_SIGNED | SCLR_INT,

    SCLR_UNSIGNED,
    SCLR_UNSIGNED | SCLR_INT,

    SCLR_LONG,
    SCLR_SIGNED | SCLR_LONG,
    SCLR_LONG | SCLR_INT,
    SCLR_SIGNED | SCLR_LONG | SCLR_INT,

    SCLR_UNSIGNED | SCLR_LONG,
    SCLR_UNSIGNED | SCLR_LONG | SCLR_INT,

    SCLR_LONG | SCLR_LONG2,
    SCLR_SIGNED | SCLR_LONG | SCLR_LONG2,
    SCLR_LONG | SCLR_LONG2 | SCLR_INT,
    SCLR_SIGNED | SCLR_LONG | SCLR_LONG2 | SCLR_INT,

    SCLR_UNSIGNED | SCLR_LONG | SCLR_LONG,
    SCLR_UNSIGNED | SCLR_LONG | SCLR_LONG | SCLR_INT,

    SCLR_FLOAT,
    SCLR_DOUBLE,
    SCLR_LONG | SCLR_DOUBLE,

    SCLR_BOOL,

    SCLR_FLOAT | SCLR_COMPLEX,
    SCLR_DOUBLE | SCLR_COMPLEX,
    SCLR_LONG | SCLR_DOUBLE | SCLR_COMPLEX,
};

typedef union
{
    unsigned short full;
    struct
    {
        int void_bit : 1;
        int char_bit : 1;
        int short_bit : 1;
        int int_bit : 1;

        int long_bit : 1;
        int long2_bit : 1;
        int float_bit : 1;
        int double_bit : 1;

        int signed_bit : 1;
        int unsigned_bit : 1;
        int bool_bit : 1;
        int complex_bit : 1;

        int struct_or_union_bit : 1;
        int enum_bit : 1;
    };
} scalar_t;

// string literal value
struct string
{
    char *buffer;
    unsigned long long length;
    unsigned long long size;
};

// number literal value
struct number
{
    union
    {
        unsigned long long integer;
        long double real;
    };
    scalar_t type;
};

// storage classes
typedef enum
{
    SC_IMPLICIT_EXTERN,
    SC_EXTERN,
    SC_STATIC,
    SC_AUTO,
    SC_REGISTER,
} storage_class_t;

// function specifiers
typedef enum
{
    FS_NONE,
    FS_INLINE,
} function_specifier_t;

// type qualifiers
#define TQ_CONST 0b001
#define TQ_RESTRICT 0b010
#define TQ_VOLATILE 0b100

typedef union
{
    char full;
    struct
    {
        char is_const : 1;
        char is_restrict : 1;
        char is_volatile : 1;
    };
} type_qualifier_t;

// type_specifier
typedef struct
{
    scalar_t scalar;
    ast_node_t *custom;
} type_specifier_t;

#endif
