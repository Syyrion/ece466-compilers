#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    fprintf(stderr, "%% yyparse returned: %d %%\n", yyparse());
    return 0;
}
