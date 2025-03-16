#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "types.h"

symbol_table_t *st_top;

symbol_table_t *st_new(symbol_table_t *parent)
{
    symbol_table_t *new_inst = malloc(sizeof(symbol_table_t));
    new_inst->entries = ast_list_new();
    new_inst->parent = parent;
    return new_inst;
}

ast_node_list_t *st_free(symbol_table_t *st)
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
    return st_free(temp);
}

// adds an ast_node to the symbol table
void st_add(ast_node_t *entry)
{
    ast_list_add(st_top->entries, entry);
}
#include <stdio.h>

// finds an ast_node in the symbol tables
ast_node_t *st_find(symbol_table_t *st, char *name)
{
    symbol_table_t *current_st = st ? st : st_top;
    do
    {
        for (int i = 0; i < current_st->entries->node_count; i++)
        {
            // fprintf(stderr, "h\n");
            ast_node_t *node = current_st->entries->nodes[i];
            if (strcmp(name, node->ident) == 0)
                return node;
        }
        current_st = current_st->parent;
    } while (current_st != 0);
    
    return 0;
}
