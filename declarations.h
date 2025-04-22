#ifndef DECLARATIONS_API_INCLUDED
#define DECLARATIONS_API_INCLUDED

#include "types.h"

void declspec_init(declaration_specifiers_t *ds);
void declspec_add_type_specifier(declaration_specifiers_t *ds, type_specifier_t type_specifier);
void declspec_add_type_qualifier(declaration_specifiers_t *ds, int type_qualifiers);
void declspec_add_storage_class(declaration_specifiers_t *ds, int storage_class);
void declspec_add_function_specifier(declaration_specifiers_t *ds, int function_specifier);
scalar_t declspec_normalize_scalar(scalar_t scalar);
storage_class_specifier_t declspec_normalize_parameter_storage_class(storage_class_specifier_t storage_class);

void declpkg_init(declaration_package_t *list);
void declpkg_add_declarator(declaration_package_t *list, declarator_helper_t declarator);

#endif