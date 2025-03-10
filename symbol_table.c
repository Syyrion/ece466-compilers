#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

symbol_table_t *st_new(symbol_table_t *parent)
{
    symbol_table_t *new_inst = malloc(sizeof(symbol_table_t));
    new_inst->parent = parent;
    new_inst->entry_capacity = 0;
    new_inst->entry_count = 0;
    new_inst->entries = 0;
    return new_inst;
}

symbol_table_t *st_add(symbol_table_t *st, ast_node_t *entry)
{
    if (st->entries)
    {
        if (st->entry_count == st->entry_capacity)
            st->entries = realloc(st->entries, st->entry_capacity *= 2);
    }
    else
    {
        st->entry_capacity = 1;
        st->entries = malloc(sizeof(ast_node_t *));
    }
    st->entries[st->entry_count++] = entry;
    return st;
}

ast_node_t *st_find(symbol_table_t *st, char *name)
{
    symbol_table_t *current_st = st;
    do
    {
        for (int i = 0; i < current_st->entry_count; i++)
        {
            ast_node_t *node = &(current_st->entries[i]);
            if (strcmp(name, node->ident) == 0)
                return node;
        }
        current_st = current_st->parent;
    } while (current_st != 0);
    return 0;
}

void st_free(symbol_table_t *st)
{
    if (st->entries)
    {
        for (int i = 0; i < st->entry_count; i++)
            ast_free(st->entries[i]);
        free(st->entries);
    }
    free(st);
}
