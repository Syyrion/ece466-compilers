
#include <stdlib.h>
#include <stdio.h>
#include "jump_association.h"
#include "location.h"
// #include "parser.tab.h"

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
        fprintf(stderr, "only for, while, and switch statements can be used here\n");
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "%s:%d: break cannot be used outside of for, while, or switch\n", filename, line_num);
        exit(EXIT_FAILURE);
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
        fprintf(stderr, "%s:%d: continue cannot be used outside of for or while\n", filename, line_num);
        exit(EXIT_FAILURE);
    }
    return current;
}

void ja_add_switch_case(ast_node_t *constant_expression, ast_node_t *statement)
{
    if (top->kind != AST_SWITCH)
    {
        fprintf(stderr, "%s:%d: switch case cannot be used here\n", filename, line_num);
        exit(EXIT_FAILURE);
    }

    ast_node_list_add(top->switch_statement.cases, ast_new_switch_case(constant_expression, statement));
}

void ja_add_switch_default(ast_node_t *statement)
{
    if (top->kind != AST_SWITCH)
    {
        fprintf(stderr, "%s:%d: switch default cannot be used here\n", filename, line_num);
        exit(EXIT_FAILURE);
    }

    top->switch_statement.default_case = ast_new_switch_case(0, statement);
}
