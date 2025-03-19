#ifndef SYMBOL_TABLE_API_INCLUDED
#define SYMBOL_TABLE_API_INCLUDED

#include "types.h"
#include "ast.h"

typedef struct symbol_table symbol_table_t;

struct symbol_table
{
    symbol_table_t *parent;
    ast_node_list_t *entries;
};

void st_init(void);
symbol_table_t *st_new(symbol_table_t *parent);
ast_node_list_t *st_unpack(symbol_table_t *st);
void st_push(void);
ast_node_list_t *st_pop(void);
void st_add(symbol_table_t *st, ast_node_t *entry);
ast_node_t *st_find(symbol_table_t *st, char *name);
int st_is_at_root(void);

#endif