#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"
#include "types.h"

symbol_table_t __root = {0};
symbol_table_t *st_top = &__root;

// pushes a new symbol table
void st_push(void)
{
    symbol_table_t *new_inst = malloc(sizeof(symbol_table_t));
    new_inst->entries = ast_list_new(); 
    new_inst->parent = st_top;
    st_top = new_inst;
}

// pops the top symbol table and returns the ast_node_list contained inside
ast_node_list_t *st_pop(void)
{
    symbol_table_t *temp = st_top;
    ast_node_list_t *temp_entries = st_top->entries;
    st_top = st_top->parent;
    free(temp);
    return temp_entries;
}

// adds an ast_node to the symbol table
void st_add(ast_node_t *entry)
{
    ast_list_add(st_top->entries, entry);
}

// finds an ast_node in the symbol tables
ast_node_t *st_find(symbol_table_t *st, char *name)
{
    symbol_table_t *current_st = st;
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
