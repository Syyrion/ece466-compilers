#include <stdio.h>
#include <ctype.h>
#include "literal.h"

void print_stringlit(string_t string)
{
    const char *s = string.buffer;
    for (int i = 0; i < string.length; i++)
    {
        if (s[i] == '\x07')
            printf("\\a");
        else if (s[i] == '\x08')
            printf("\\b");
        else if (s[i] == '\x0c')
            printf("\\f");
        else if (s[i] == '\x0a')
            printf("\\n");
        else if (s[i] == '\x0d')
            printf("\\r");
        else if (s[i] == '\x09')
            printf("\\t");
        else if (s[i] == '\x0b')
            printf("\\v");
        else if (s[i] == '\\')
            printf("\\\\");
        else if (s[i] == '\'')
            printf("\\\'");
        else if (s[i] == '"')
            printf("\\\"");
        else if (s[i] == 0)
            printf("\\0");
        else if (isprint(s[i]))
            fputc(s[i], stdout);
        else
            printf("\\%03o", (unsigned char)s[i]);
    }
}

void print_numberlit(number_t number)
{
    if (number.type.full & TS_REAL)
    {
        printf(
            "REAL    %Lg    %s",
            number.real,
            number.type.long_bit     ? "LONG DOUBLE"
            : number.type.double_bit ? "DOUBLE"
                                     : "FLOAT");
    }
    else
    {
        printf(
            "INTEGER    %lld    %s%s",
            number.integer,
            number.type.unsigned_bit ? "UNSIGNED " : "",
            number.type.long2_bit       ? "LONG LONG"
            : number.type.long_bit == 1 ? "LONG"
                                        : "INT");
    }
}
