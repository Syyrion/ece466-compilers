#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"

int main()
{
    fprintf(stderr, "%% yyparse returned: %d %%\n", yyparse());
    return 0;
}
