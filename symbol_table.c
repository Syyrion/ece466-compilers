#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "location.h"
#include "errorf.h"

// oh no, more globals

// -1 means uninitialized
// 0 means at global scope
// 1 means at root of function
static int depth = -1;

// not really a symbol table but somewhere to put all of the statement nodes
static symbol_table_t *FN_STATEMENTS = 0;

symbol_table_t *NS_VARIABLE = 0;

symbol_table_t *NS_STRUCT = 0;

static symbol_table_t *NS_LABEL = 0;

void st_init(void)
{
    if (depth >= 0)
    {
        errorf("symbol tables have already been initialized");
    }

    NS_VARIABLE = st_new(0);
    NS_STRUCT = st_new(0);
    depth = 0;
}

// pushes a new symbol table
void st_push(void)
{

    NS_VARIABLE = st_new(NS_VARIABLE);
    NS_STRUCT = st_new(NS_STRUCT);

    if (depth == 0)
    {
        FN_STATEMENTS = st_new(0);
        NS_LABEL = st_new(0);
    }
    else
        FN_STATEMENTS = st_new(FN_STATEMENTS);

    depth++;
}

static void resolve_goto_statements(ast_node_t *statement)
{
    ast_node_t *label;
    switch (statement->kind)
    {
    case AST_GOTO:
        label = st_find_local(NS_LABEL, statement->goto_statement.label_name);
        if (!label)
        {
            errorf("undefined label");
        }
        free(statement->goto_statement.label_name);
        statement->goto_statement.label_name = 0;

        statement->goto_statement.statement = label->label.statement;
        break;
    case AST_COMPOUND:
        ENUMERATE(statement->compound_statement.sub_statements, i, {
            resolve_goto_statements(statement->compound_statement.sub_statements->items[i]);
        });
        break;
    case AST_IF:
        resolve_goto_statements(statement->if_statement.true_branch);
        if (statement->if_statement.false_branch)
            resolve_goto_statements(statement->if_statement.false_branch);
        break;
    case AST_WHILE:
    case AST_DO_WHILE:
        resolve_goto_statements(statement->while_statement.statement);
        break;
    case AST_FOR:
        resolve_goto_statements(statement->for_statement.statement);
        break;
    case AST_SWITCH:
        resolve_goto_statements(statement->switch_statement.statement);
        break;
    case AST_EXPRESSION:
    case AST_CONTINUE:
    case AST_BREAK:
    case AST_RETURN:
        // do nothing
        break;
    default:
        errorf("unknown statement %d", statement->kind);
        break;
    }
}

// pops the top symbol table. returns a compound statement
ast_node_t *st_pop(void)
{
    if (depth == 0)
    {
        errorf("cannot pop the root symbol table");
    }

    symbol_table_t *st_statements = FN_STATEMENTS;
    symbol_table_t *st_variables = NS_VARIABLE;
    symbol_table_t *st_structs = NS_STRUCT;

    FN_STATEMENTS = FN_STATEMENTS->parent;
    NS_VARIABLE = NS_VARIABLE->parent;
    NS_STRUCT = NS_STRUCT->parent;

    ast_node_t *statements = ast_new_compound_statement(st_unpack(st_statements));

    ast_node_list_t *variables = st_unpack(st_variables);
    ast_node_list_t *structs = st_unpack(st_structs);

    ENUMERATE(variables, i, {
        if (!variables->items[i]->variable.used)
            ast_free_variable_like_node(variables->items[i]);
    });
    ast_node_list_free(variables);

    ENUMERATE(structs, i, {
        if (!structs->items[i]->structure.used)
            ast_free_struct(structs->items[i]);
    });
    ast_node_list_free(structs);

    if (depth == 1)
    {
        resolve_goto_statements(statements);

        ast_node_list_t *labels = st_unpack(NS_LABEL);
        ENUMERATE(labels, i, {
            free(labels->items[i]->label.name);
            free(labels->items[i]);
        });
        ast_node_list_free(labels);

        NS_LABEL = 0;
    }

    depth--;

    return statements;
}

// makes a new symbol table
symbol_table_t *st_new(symbol_table_t *parent)
{
    symbol_table_t *new_inst = malloc(sizeof(symbol_table_t));
    new_inst->entries = ast_node_list_new();
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
    ast_node_list_add(st->entries, entry);
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

    for (int i = st->entries->count - 1; i >= 0; i--)
    {
        ast_node_t *node = st->entries->items[i];
        if (node->name // the identifier may not exist for struct padding
            && strcmp(name, node->name) == 0)
            return node;
    }

    return 0;
}

// adds a label to the label namespace for lookup later
void st_add_label(char *name, ast_node_t *statement)
{
    st_add(NS_LABEL, ast_new_label(name, statement));
}

// adds a statement
void st_add_statement(ast_node_t *statement)
{
    st_add(FN_STATEMENTS, statement);
}