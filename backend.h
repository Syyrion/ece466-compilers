#include <stdio.h>
#include "quad.h"

extern FILE *backend_file;

void backend_begin(void);
void backend_write_global(ast_node_t *var);
void backend_write_function(basic_block_list_t *fn);
void backend_end(void);