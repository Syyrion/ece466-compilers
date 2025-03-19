#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "location.h"
#include "declarations.h"
#include "ast.h"

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
        fprintf(stderr, "%s:%d: Error: invalid combination of type specifiers\n", filename, line_num);
        exit(80);
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
        fprintf(stderr, "%s:%d: Error: storage class has already been specified\n", filename, line_num);
        exit(80);
    }
    declspec->storage_class = storage_class;
};

void declspec_add_function_specifier(declaration_specifiers_t *declspec, int function_specifier)
{
    declspec->function_specifier = function_specifier;
}

void declspec_verify_scalar(scalar_t *scalar)
{
    if (scalar->full == 0)
    {
        fprintf(stderr, "%s:%d: Warning: declaration with no type specifiers treated as int\n", filename, line_num);
        scalar->full |= TS_INT;
        return;
    }
    for (int i = 0, j = sizeof(TS_VALID) / sizeof(*TS_VALID); i < j; i++)
        if (scalar->full == TS_VALID[i])
            return;
    fprintf(stderr, "%s:%d: Error: invalid combination of type specifiers\n", filename, line_num);
    exit(80);
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
