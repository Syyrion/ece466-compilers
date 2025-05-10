#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "errorf.h"

int main()
{
    log("%% yyparse returned: %d %%", yyparse());
    return 0;
}
