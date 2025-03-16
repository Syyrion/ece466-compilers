#ifndef DECLARATIONS_API_INCLUDED
#define DECLARATIONS_API_INCLUDED

#include "types.h"

void ds_init(declaration_specifiers_t *ds);
void ds_add_type_specifier(declaration_specifiers_t *ds, type_specifier_t type_specifier);
void ds_add_type_qualifier(declaration_specifiers_t *ds, int type_qualifiers);
void ds_add_storage_class(declaration_specifiers_t *ds, int storage_class);
void ds_add_function_specifier(declaration_specifiers_t *ds, int function_specifier);

void dl_init(declarator_list_t *list);
void dl_add(declarator_list_t *list, declarator_helper_t declarator);

#endif