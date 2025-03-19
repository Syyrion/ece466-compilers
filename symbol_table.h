#ifndef SYMBOL_TABLE_API_INCLUDED
#define SYMBOL_TABLE_API_INCLUDED

#include "types.h"
#include "ast.h"

typedef struct symbol_table symbol_table_t;

extern symbol_table_t *NS_VARIABLE;
extern symbol_table_t *NS_STRUCT;

struct symbol_table
{
    symbol_table_t *parent;
    ast_node_list_t *entries;
};

typedef struct
{
    ast_node_list_t *variable_list;
    ast_node_list_t *struct_list;
} pop_result_t;

void st_init(void);
symbol_table_t *st_new(symbol_table_t *parent);
ast_node_list_t *st_unpack(symbol_table_t *st);
void st_push(void);
pop_result_t st_pop(void);
void st_add(symbol_table_t *st, ast_node_t *entry);
ast_node_t *st_find(symbol_table_t *st, char *name);
int st_is_at_root(void);

#endif