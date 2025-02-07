// Test file for playing with syntax

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

union yylval_num_type{
    char whole;
    struct {
        char is_unsigned:1;
        char is_real:1;
        char type:2;
    } bit;
};

union yylval_num_type yylval_num_type;

int main()
{

    yylval_num_type.bit.is_unsigned = 1;
    yylval_num_type.bit.type = 3;

    printf("%x\n", yylval_num_type.whole, 1Ul, sizeof(long double));
    // realloc()
    return 0;
}