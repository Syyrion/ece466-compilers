#include <stdio.h>
#include <stdlib.h>
#include "parser.tab.h"
#include "errorf.h"
#include "backend.h"

int main()
{
    backend_begin();
    log("%% yyparse returned: %d %%", yyparse());
    backend_end();
    return 0;
}
