#ifndef DECLARATIONS_H
#define DECLARATIONS_H

struct ast_node;
typedef struct ast_node ast_node_t;

// scalar types
#define TS_VOID 0b00000000000001
#define TS_CHAR 0b00000000000010
#define TS_SHORT 0b00000000000100
#define TS_INT 0b00000000001000
#define TS_LONG 0b00000000010000
#define TS_LONG2 0b00000000100000
#define TS_FLOAT 0b00000001000000
#define TS_DOUBLE 0b00000010000000
#define TS_SIGNED 0b00000100000000
#define TS_UNSIGNED 0b00001000000000
#define TS_BOOL 0b00010000000000
#define TS_COMPLEX 0b00100000000000
#define TS_STRUCT_OR_UNION 0b01000000000000
#define TS_ENUM 0b10000000000000
#define TS_CUSTOM (TS_STRUCT_OR_UNION | TS_ENUM)
#define TS_REAL (TS_FLOAT | TS_DOUBLE)

// encoded semantic rules for type specifiers
static const unsigned short TS_VALID[] = {
    // giga-pain

    TS_VOID,

    TS_CHAR,
    TS_SIGNED | TS_CHAR,
    TS_UNSIGNED | TS_CHAR,

    TS_SHORT,
    TS_SIGNED | TS_SHORT,
    TS_SHORT | TS_INT,
    TS_SIGNED | TS_SHORT | TS_INT,

    TS_UNSIGNED | TS_SHORT,
    TS_UNSIGNED | TS_SHORT | TS_INT,

    TS_INT,
    TS_SIGNED,
    TS_SIGNED | TS_INT,

    TS_UNSIGNED,
    TS_UNSIGNED | TS_INT,

    TS_LONG,
    TS_SIGNED | TS_LONG,
    TS_LONG | TS_INT,
    TS_SIGNED | TS_LONG | TS_INT,

    TS_UNSIGNED | TS_LONG,
    TS_UNSIGNED | TS_LONG | TS_INT,

    TS_LONG | TS_LONG2,
    TS_SIGNED | TS_LONG | TS_LONG2,
    TS_LONG | TS_LONG2 | TS_INT,
    TS_SIGNED | TS_LONG | TS_LONG2 | TS_INT,

    TS_UNSIGNED | TS_LONG | TS_LONG2,
    TS_UNSIGNED | TS_LONG | TS_LONG2 | TS_INT,

    TS_FLOAT,
    TS_DOUBLE,
    TS_LONG | TS_DOUBLE,

    TS_BOOL,

    TS_FLOAT | TS_COMPLEX,
    TS_DOUBLE | TS_COMPLEX,
    TS_LONG | TS_DOUBLE | TS_COMPLEX,

    TS_STRUCT_OR_UNION,
    TS_ENUM,
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

// type_specifier
typedef struct
{
    scalar_t scalar;
    ast_node_t *custom; // only used by struct, unions, and enums
} type_specifier_t;

// type qualifiers
#define TQ_CONST 0b001
#define TQ_RESTRICT 0b010
#define TQ_VOLATILE 0b100

typedef union
{
    unsigned char full;
    struct
    {
        int is_const : 1;
        int is_restrict : 1;
        int is_volatile : 1;
    };
} type_qualifier_t;

// storage classes
typedef enum
{
    SC_EXTERN = 1,
    SC_STATIC,
    SC_AUTO,
    SC_REGISTER,
    SC_IMPLICIT_EXTERN,
} storage_class_specifier_t;

// function specifiers
typedef enum
{
    FS_INLINE = 1,
} function_specifier_t;

// all declaration specifiers
typedef struct
{
    type_specifier_t type_specifier;
    type_qualifier_t type_qualifier;
    storage_class_specifier_t storage_class;
    function_specifier_t function_specifier;
} declaration_specifiers_t;

// holds the representation of a declarator
typedef struct
{
    ast_node_t *oldest; // first created declarator element
    ast_node_t *newest; // newest created declarator element
    union
    {
        ast_node_t *initializer;
        ast_node_t *bit_width;
    };
} declarator_helper_t;

// list of declarator helpers with declaration specifiers
typedef struct
{
    declaration_specifiers_t declaration_specifiers;
    unsigned long capacity;
    unsigned long declarator_count;
    declarator_helper_t *declarators;
} declaration_package_t;

void declspec_init(declaration_specifiers_t *ds);
void declspec_add_type_specifier(declaration_specifiers_t *ds, type_specifier_t type_specifier);
void declspec_add_type_qualifier(declaration_specifiers_t *ds, int type_qualifiers);
void declspec_add_storage_class(declaration_specifiers_t *ds, int storage_class);
void declspec_add_function_specifier(declaration_specifiers_t *ds, int function_specifier);
scalar_t declspec_normalize_scalar(scalar_t scalar);
storage_class_specifier_t declspec_normalize_parameter_storage_class(storage_class_specifier_t storage_class);

void declpkg_init(declaration_package_t *list);
void declpkg_add_declarator(declaration_package_t *list, declarator_helper_t declarator);

void print_storage_class(storage_class_specifier_t storage_class);
void print_type_qualifier(type_qualifier_t type_qualifier);
void print_scalar(scalar_t scalar);

#endif