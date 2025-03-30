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

static symbol_table_t *__label_namespace_root = 0;
symbol_table_t *NS_LABEL = 0;

void st_init(void)
{
    if (__variable_namespace_root)
    {
        fprintf(stderr, "root symbol table has already been initialized");
        exit(89);
    }
    __variable_namespace_root = NS_VARIABLE = st_new(0);
    __struct_namespace_root = NS_STRUCT = st_new(0);
    __label_namespace_root = NS_LABEL = st_new(0);
}

// pushes a new symbol table
void st_push(void)
{
    NS_VARIABLE = st_new(NS_VARIABLE);
    NS_STRUCT = st_new(NS_STRUCT);
    NS_LABEL = st_new(NS_LABEL);
}

// pops the top symbol table.
namespace_group_t st_pop(void)
{
    if (__variable_namespace_root == NS_VARIABLE)
    {
        fprintf(stderr, "cannot pop the root symbol table");
        exit(87);
    }
    symbol_table_t *temp_var = NS_VARIABLE;
    symbol_table_t *temp_str = NS_STRUCT;
    symbol_table_t *temp_lab = NS_LABEL;
    NS_VARIABLE = NS_VARIABLE->parent;
    NS_STRUCT = NS_STRUCT->parent;
    NS_LABEL = NS_LABEL->parent;

    return (namespace_group_t){
        .variable_list = st_unpack(temp_var),
        .struct_list = st_unpack(temp_str),
        .label_list = st_unpack(temp_lab)};
}

int st_is_at_root(void)
{
    return __variable_namespace_root == NS_VARIABLE;
}

// makes a new symbol table
symbol_table_t *st_new(symbol_table_t *parent)
{
    symbol_table_t *new_inst = malloc(sizeof(symbol_table_t));
    new_inst->entries = ast_list_new();
    new_inst->parent = parent;
    return new_inst;
}

// frees a symbol table while returning the list inside
ast_node_list_t *st_unpack(symbol_table_t *st)
{
    ast_node_list_t *temp_entries = st->entries;
    free(st);
    return temp_entries;
}

// adds an ast_node to the symbol table
symbol_table_t *st_add(symbol_table_t *st, ast_node_t *entry)
{
    ast_list_add(st->entries, entry);
    return st;
}

// finds an ast_node in a symbol table while descending
ast_node_t *st_find(symbol_table_t *st, char *name)
{
    if (!name)
    {
        fprintf(stderr, "null was passed as a name to st_find, ignoring");
        return 0;
    }

    symbol_table_t *current_st = st;
    do
    {
        ast_node_t *node = st_find_local(current_st, name);
        if (node)
            return node;
        current_st = current_st->parent;
    } while (current_st != 0);

    return 0;
}

// finds an ast_node without descending
ast_node_t *st_find_local(symbol_table_t *st, char *name)
{
    if (!name)
    {
        fprintf(stderr, "null was passed as a name to st_find, ignoring");
        return 0;
    }

    for (int i = st->entries->node_count - 1; i >= 0; i--)
    {
        ast_node_t *node = st->entries->nodes[i];
        if (node->name // the identifier may not exist for struct padding
            && strcmp(name, node->name) == 0)
            return node;
    }

    return 0;
}
