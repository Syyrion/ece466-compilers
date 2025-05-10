#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "location.h"
#include "declarations.h"
#include "errorf.h"

void declspec_init(declaration_specifiers_t *declspec)
{
    memset(declspec, 0, sizeof(declaration_specifiers_t));
}

void declspec_add_type_specifier(declaration_specifiers_t *declspec, type_specifier_t type_specifier)
{
    unsigned short current_scalar = declspec->type_specifier.scalar.full;
    unsigned short new_scalar = type_specifier.scalar.full;

    // if a long was already encountered, try using long2
    if (current_scalar & TS_LONG && new_scalar == TS_LONG)
        new_scalar = TS_LONG2;

    // duplicate type specifiers aren't allowed (except for long)
    if (current_scalar & new_scalar)
    {
        errorf("%s:%d: Error: invalid combination of type specifiers", filename, line_num);
    }

    if (new_scalar & TS_CUSTOM)
        declspec->type_specifier.custom = type_specifier.custom;

    declspec->type_specifier.scalar.full |= new_scalar;
}

void declspec_add_type_qualifier(declaration_specifiers_t *declspec, int type_qualifiers)
{
    declspec->type_qualifier.full |= type_qualifiers;
}

void declspec_add_storage_class(declaration_specifiers_t *declspec, int storage_class)
{
    if (declspec->storage_class)
    {
        errorf("%s:%d: Error: storage class has already been specified", filename, line_num);
    }
    declspec->storage_class = storage_class;
};

void declspec_add_function_specifier(declaration_specifiers_t *declspec, int function_specifier)
{
    declspec->function_specifier = function_specifier;
}

static scalar_t simplify_scalar(scalar_t scalar)
{
    switch (scalar.full)
    {
    case TS_VOID:
        return (scalar_t){.full = TS_VOID};

    case TS_CHAR:
    case TS_SIGNED | TS_CHAR:
        return (scalar_t){.full = TS_CHAR};

    case TS_UNSIGNED | TS_CHAR:
        return (scalar_t){.full = TS_UNSIGNED | TS_CHAR};

    case TS_SHORT:
    case TS_SIGNED | TS_SHORT:
    case TS_SHORT | TS_INT:
    case TS_SIGNED | TS_SHORT | TS_INT:
        return (scalar_t){.full = TS_SHORT};

    case TS_UNSIGNED | TS_SHORT:
    case TS_UNSIGNED | TS_SHORT | TS_INT:
        return (scalar_t){.full = TS_UNSIGNED | TS_SHORT};

    case TS_INT:
    case TS_SIGNED:
    case TS_SIGNED | TS_INT:
        return (scalar_t){.full = TS_INT};

    case TS_UNSIGNED:
    case TS_UNSIGNED | TS_INT:
        return (scalar_t){.full = TS_UNSIGNED | TS_INT};

    case TS_LONG:
    case TS_SIGNED | TS_LONG:
    case TS_LONG | TS_INT:
    case TS_SIGNED | TS_LONG | TS_INT:
        return (scalar_t){.full = TS_LONG};

    case TS_UNSIGNED | TS_LONG:
    case TS_UNSIGNED | TS_LONG | TS_INT:
        return (scalar_t){.full = TS_UNSIGNED | TS_LONG};

    case TS_LONG | TS_LONG2:
    case TS_SIGNED | TS_LONG | TS_LONG2:
    case TS_LONG | TS_LONG2 | TS_INT:
    case TS_SIGNED | TS_LONG | TS_LONG2 | TS_INT:
        return (scalar_t){.full = TS_LONG | TS_LONG2};

    case TS_UNSIGNED | TS_LONG | TS_LONG2:
    case TS_UNSIGNED | TS_LONG | TS_LONG2 | TS_INT:
        return (scalar_t){.full = TS_UNSIGNED | TS_LONG | TS_LONG2};

    case TS_FLOAT:
        return (scalar_t){.full = TS_FLOAT};

    case TS_DOUBLE:
        return (scalar_t){.full = TS_DOUBLE};

    case TS_LONG | TS_DOUBLE:
        return (scalar_t){.full = TS_LONG | TS_DOUBLE};

    case TS_BOOL:
        return (scalar_t){.full = TS_BOOL};

    case TS_FLOAT | TS_COMPLEX:
        return (scalar_t){.full = TS_FLOAT | TS_COMPLEX};

    case TS_DOUBLE | TS_COMPLEX:
        return (scalar_t){.full = TS_DOUBLE | TS_COMPLEX};

    case TS_LONG | TS_DOUBLE | TS_COMPLEX:
        return (scalar_t){.full = TS_LONG | TS_DOUBLE | TS_COMPLEX};

    case TS_STRUCT_OR_UNION:
        return (scalar_t){.full = TS_STRUCT_OR_UNION};

    case TS_ENUM:
        return (scalar_t){.full = TS_ENUM};

    default:
        errorf("cannot simplify invalid scalar");
        break;
    }
}

scalar_t declspec_normalize_scalar(scalar_t scalar)
{
    if (scalar.full == 0)
    {
        fprintf(stderr, "%s:%d: Warning: declaration with no type specifiers treated as int\n", filename, line_num);
        scalar.full |= TS_INT;
        return simplify_scalar(scalar);
    }

    for (int i = 0, j = sizeof(TS_VALID) / sizeof(*TS_VALID); i < j; i++)
        if (scalar.full == TS_VALID[i])
            return simplify_scalar(scalar);

    errorf("%s:%d: Error: invalid combination of type specifiers", filename, line_num);
}

storage_class_specifier_t declspec_normalize_parameter_storage_class(storage_class_specifier_t storage_class)
{
    if (storage_class && storage_class != SC_REGISTER)
    {
        errorf("%s:%d: Error: invalid parameter storage class ", filename, line_num);
    }
    return SC_AUTO;
}

void declpkg_init(declaration_package_t *declpkg)
{
    memset(declpkg, 0, sizeof(declaration_package_t));
}

void declpkg_add_declarator(declaration_package_t *declpkg, declarator_helper_t declarator)
{
    if (declpkg->declarators)
    {
        if (declpkg->declarator_count == declpkg->capacity)
            declpkg->declarators = realloc(declpkg->declarators, (declpkg->capacity *= 2) * sizeof(declarator_helper_t));
    }
    else
    {
        declpkg->capacity = 1;
        declpkg->declarators = malloc(sizeof(declarator_helper_t));
    }
    declpkg->declarators[declpkg->declarator_count++] = declarator;
}

void print_storage_class(storage_class_specifier_t storage_class)
{
    switch (storage_class)
    {
    case SC_EXTERN:
        printf("EXTERN ");
        break;
    case SC_AUTO:
        printf("AUTO ");
        break;
    case SC_STATIC:
        printf("STATIC ");
        break;
    case SC_REGISTER:
        printf("REGISTER ");
        break;
    default:
        printf("unknown ");
        break;
    }
}

void print_type_qualifier(type_qualifier_t type_qualifier)
{
    if (type_qualifier.is_const)
        printf("CONST ");
    if (type_qualifier.is_restrict)
        printf("RESTRICT ");
    if (type_qualifier.is_volatile)
        printf("VOLATILE ");
}

void print_scalar(scalar_t scalar)
{
    if (scalar.void_bit)
        printf("VOID ");
    if (scalar.char_bit)
        printf("CHAR ");
    if (scalar.short_bit)
        printf("SHORT ");
    if (scalar.int_bit)
        printf("INT ");
    if (scalar.long_bit)
        printf("LONG ");
    if (scalar.long2_bit)
        printf("LONG ");
    if (scalar.float_bit)
        printf("FLOAT ");
    if (scalar.double_bit)
        printf("DOUBLE ");
    if (scalar.signed_bit)
        printf("SIGNED ");
    if (scalar.unsigned_bit)
        printf("UNSIGNED ");
    if (scalar.bool_bit)
        printf("BOOL ");
    if (scalar.complex_bit)
        printf("COMPLEX ");
    if (scalar.struct_or_union_bit)
        printf("STRUCT_OR_UNION ");
    if (scalar.enum_bit)
        printf("ENUM ");
}
