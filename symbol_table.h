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

extern symbol_table_t __root;
extern symbol_table_t *st_top;

void st_push(void);
ast_node_list_t *st_pop(void);
void st_add(ast_node_t *entry);
ast_node_t *st_find(symbol_table_t *st, char *name);

#endif