
#include <stdlib.h>
#include <stdio.h>
#include "jump_association.h"
#include "location.h"
#include "errorf.h"

static ast_node_t *top = 0;

void ja_push(ast_node_t *statement)
{
    switch (statement->kind)
    {
    case AST_FOR:
    case AST_WHILE:
    case AST_DO_WHILE:
    case AST_SWITCH:
        break;

    default:
        errorf("only for, while, and switch statements can be used here");
    }
    statement->next = top;
    top = statement;
}

void ja_pop(void)
{
    top = top->next;
}

ast_node_t *ja_get_break_association(void)
{
    if (top == 0)
    {
        errorf("%s:%d: break cannot be used outside of for, while, or switch", filename, line_num);
    }
    return top;
}

ast_node_t *ja_get_continue_association(void)
{
    ast_node_t *current = top;
    while (current != 0 && current->kind == AST_SWITCH)
        current = current->next;
    if (current == 0)
    {
        errorf("%s:%d: continue cannot be used outside of for or while", filename, line_num);
    }
    return current;
}

void ja_add_switch_case(ast_node_t *constant_expression, ast_node_t *statement)
{
    if (top->kind != AST_SWITCH)
    {
        errorf("%s:%d: switch case cannot be used here", filename, line_num);
    }

    ast_node_list_add(top->switch_statement.cases, ast_new_switch_case(constant_expression, statement));
}

void ja_add_switch_default(ast_node_t *statement)
{
    if (top->kind != AST_SWITCH)
    {
        errorf("%s:%d: switch default cannot be used here", filename, line_num);
    }

    top->switch_statement.default_case = ast_new_switch_case(0, statement);
}
