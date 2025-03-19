#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "types.h"
#include "location.h"

static symbol_table_t *__variable_namespace_root = 0;
symbol_table_t *NS_VARIABLE = 0;

static symbol_table_t *__struct_namespace_root = 0;
symbol_table_t *NS_STRUCT = 0;

void st_init(void)
{
    if (__variable_namespace_root)
    {
        fprintf(stderr, "root symbol table has already been initialized");
        exit(89);
    }
    __variable_namespace_root = NS_VARIABLE = st_new(0);
    __struct_namespace_root = NS_STRUCT = st_new(0);
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
    NS_VARIABLE = st_new(NS_VARIABLE);
    NS_STRUCT = st_new(NS_STRUCT);
}

// pops the top symbol table.
pop_result_t st_pop(void)
{
    symbol_table_t *temp_var = NS_VARIABLE;
    symbol_table_t *temp_str = NS_STRUCT;
    NS_VARIABLE = NS_VARIABLE->parent;
    NS_STRUCT = NS_STRUCT->parent;

    return (pop_result_t){.variable_list = st_unpack(NS_VARIABLE), .struct_list = st_unpack(NS_STRUCT)};
}

// adds an ast_node to the symbol table
void st_add(symbol_table_t *st, ast_node_t *entry)
{
    ast_list_add(st->entries, entry);
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
            if (node->ident // the identifier may not exist for struct padding
                && strcmp(name, node->ident) == 0)
                return node;
        }
        current_st = current_st->parent;
    } while (current_st != 0);

    return 0;
}

int st_is_at_root(void)
{
    return __variable_namespace_root == NS_VARIABLE;
}
