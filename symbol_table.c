#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "types.h"
#include "location.h"

static symbol_table_t *st_root = 0;
static symbol_table_t *st_top = 0;

void st_init(void)
{
    if (st_root)
    {
        fprintf(stderr, "root symbol table has already been initialized");
        exit(89);
    }
    st_top = st_root = st_new(0);
}

symbol_table_t *st_new(symbol_table_t *parent)
{
    symbol_table_t *new_inst = malloc(sizeof(symbol_table_t));
    new_inst->entries = ast_list_new();
    new_inst->parent = parent;
    return new_inst;
}

ast_node_list_t *st_unpack(symbol_table_t *st)
{
    ast_node_list_t *temp_entries = st->entries;
    free(st);
    return temp_entries;
}

// pushes a new symbol table
void st_push(void)
{
    symbol_table_t *new_inst = st_new(st_top);
    st_top = new_inst;
}

// pops the top symbol table and returns the ast_node_list contained inside
ast_node_list_t *st_pop(void)
{
    symbol_table_t *temp = st_top;
    st_top = st_top->parent;
    return st_unpack(temp);
}

// adds an ast_node to the symbol table
void st_add(symbol_table_t *st, ast_node_t *entry)
{
    ast_list_add((st ? st : st_top)->entries, entry);
}

// finds an ast_node in the symbol tables
ast_node_t *st_find(symbol_table_t *st, char *name)
{
    symbol_table_t *current_st = st ? st : st_top;
    do
    {
        for (int i = 0; i < current_st->entries->node_count; i++)
        {
            ast_node_t *node = current_st->entries->nodes[i];
            if (strcmp(name, node->ident) == 0)
                return node;
        }
        current_st = current_st->parent;
    } while (current_st != 0);

    return 0;
}

int st_is_at_root(void)
{
    return st_root == st_top;
}
