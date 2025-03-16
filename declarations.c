#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "declarations.h"
#include "ast.h"

// ## DECLARATION SPECIFIERS

void ds_init(declaration_specifiers_t *ds)
{
    memset(ds, 0, sizeof(declaration_specifiers_t));
}

void ds_add_type_specifier(declaration_specifiers_t *ds, type_specifier_t type_specifier)
{
    unsigned short current_scalar = ds->type_specifier.scalar.full;
    unsigned short new_scalar = type_specifier.scalar.full;

    // if a long was already encountered, try using long2
    if (current_scalar & TS_LONG && new_scalar == TS_LONG)
        new_scalar = TS_LONG2;

    // duplicate type specifiers aren't allowed (except for long)
    if (current_scalar & new_scalar)
    {
        fprintf(stderr, "invalid combination of type specifiers");
        exit(80);
    }

    if (new_scalar & TS_CUSTOM)
        ds->type_specifier.custom = type_specifier.custom;

    ds->type_specifier.scalar.full |= new_scalar;
}

void ds_add_type_qualifier(declaration_specifiers_t *ds, int type_qualifiers)
{
    ds->type_qualifier.full |= type_qualifiers;
}

void ds_add_storage_class(declaration_specifiers_t *ds, int storage_class)
{
    if (ds->storage_class)
    {
        fprintf(stderr, "storage class has already been specified");
        exit(80);
    }
    ds->storage_class = storage_class;
};

void ds_add_function_specifier(declaration_specifiers_t *ds, int function_specifier)
{
    ds->function_specifier = function_specifier;
};

// ## DECLARATORS

void dl_init(declarator_list_t *list)
{
    memset(list, 0, sizeof(declarator_list_t));
}

void dl_add(declarator_list_t *list, declarator_helper_t declarator)
{
    if (list->declarators)
    {
        if (list->declarator_count == list->capacity)
            list->declarators = realloc(list->declarators, (list->capacity *= 2) * sizeof(declarator_helper_t));
    }
    else
    {
        list->capacity = 1;
        list->declarators = malloc(sizeof(declarator_helper_t));
    }
    list->declarators[list->declarator_count++] = declarator;
}