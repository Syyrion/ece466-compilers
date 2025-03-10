#ifndef SYMBOL_TABLE_API_INCLUDED
#define SYMBOL_TABLE_API_INCLUDED

#include "ast.h"

typedef struct
{
    symbol_table_t *parent;
    unsigned long entry_capacity;
    unsigned long entry_count;
    ast_node_t **entries;
} symbol_table_t;

extern symbol_table_t __root = {0};
extern symbol_table_t *root = &__root;

symbol_table_t *st_new(symbol_table_t *parent);
symbol_table_t *st_add(symbol_table_t *st, ast_node_t *entry);
ast_node_t *st_find(symbol_table_t *st, char *name);
void st_free(symbol_table_t *st);

#endif