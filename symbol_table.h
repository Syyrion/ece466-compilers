#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include "ast.h"

typedef struct symbol_table symbol_table_t;

extern symbol_table_t *NS_VARIABLE;
extern symbol_table_t *NS_STRUCT;

struct symbol_table
{
    symbol_table_t *parent;
    ast_node_list_t *entries;
};

void st_init(void);
void st_push(void);
ast_node_t* st_pop(void);

symbol_table_t *st_new(symbol_table_t *parent);
ast_node_list_t *st_unpack(symbol_table_t *st);
symbol_table_t *st_add(symbol_table_t *st, ast_node_t *entry);
ast_node_t *st_find(symbol_table_t *st, char *name);
ast_node_t *st_find_local(symbol_table_t *st, char *name);
void st_add_label(char *name, ast_node_t *statement);
void st_add_statement(ast_node_t *statement);

#endif