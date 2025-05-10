#ifndef JUMP_ASSOCIATION_H
#define JUMP_ASSOCIATION_H

#include "ast.h"

void ja_push(ast_node_t *statement);
void ja_pop(void);
ast_node_t *ja_get_break_association(void);
ast_node_t *ja_get_continue_association(void);

void ja_add_switch_case(ast_node_t *constant_expression, ast_node_t *statement);
void ja_add_switch_default(ast_node_t *statement);

#endif