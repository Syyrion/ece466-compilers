#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tokens-manual.h"
#include "lexer.h"

void uniform_print(const char *s, const int amount)
{
    for (int i = 0; i < amount; i++)
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

void print_token_name(int);

int main()
{
    int t;
    filename = (char *)malloc(8);
    strcpy(filename, "<stdin>");

    while (t = yylex())
    {
        printf("%s\t%d\t", filename, line_num);
        print_token_name(t);

        switch (yylval_type)
        {
        case LV_NUMBER:
            printf("\t");
            if (yylval_num_type.is_real)
            {
                printf(
                    "REAL\t%Lg\t%s",
                    yylval.real,
                    yylval_num_type.type == 0   ? "FLOAT"
                    : yylval_num_type.type == 1 ? "DOUBLE"
                                                : "LONG DOUBLE");
            }
            else
            {
                printf(
                    "INTEGER\t%lld\t%s%s",
                    yylval.integer,
                    yylval_num_type.is_unsigned ? "UNSIGNED " : "",
                    yylval_num_type.type == 0   ? "INT"
                    : yylval_num_type.type == 1 ? "LONG"
                                                : "LONG LONG");
            }
            break;
        case LV_STRING:
            printf("\t");
            uniform_print(yylval.string_literal, yylval_strlen);
            free(yylval.string_literal);
            break;

        case LV_NONE:
        default:
            break;
        }

        printf("\n");
        yylval_type = LV_NONE;
    }
    free(filename);
    return 0;
}

void print_token_name(int t)
{
    if (t <= 255)
    {
        printf("%c", (char)t);
        return;
    }

    switch (t)
    {
    case TOKEOF:
        printf("TOKEOF");
        break;
    case IDENT:
        printf("IDENT");
        break;
    case CHARLIT:
        printf("CHARLIT");
        break;
    case STRING:
        printf("STRING");
        break;
    case NUMBER:
        printf("NUMBER");
        break;
    case INDSEL:
        printf("INDSEL");
        break;
    case PLUSPLUS:
        printf("PLUSPLUS");
        break;
    case MINUSMINUS:
        printf("MINUSMINUS");
        break;
    case SHL:
        printf("SHL");
        break;
    case SHR:
        printf("SHR");
        break;
    case LTEQ:
        printf("LTEQ");
        break;
    case GTEQ:
        printf("GTEQ");
        break;
    case EQEQ:
        printf("EQEQ");
        break;
    case NOTEQ:
        printf("NOTEQ");
        break;
    case LOGAND:
        printf("LOGAND");
        break;
    case LOGOR:
        printf("LOGOR");
        break;
    case ELLIPSIS:
        printf("ELLIPSIS");
        break;
    case TIMESEQ:
        printf("TIMESEQ");
        break;
    case DIVEQ:
        printf("DIVEQ");
        break;
    case MODEQ:
        printf("MODEQ");
        break;
    case PLUSEQ:
        printf("PLUSEQ");
        break;
    case MINUSEQ:
        printf("MINUSEQ");
        break;
    case SHLEQ:
        printf("SHLEQ");
        break;
    case SHREQ:
        printf("SHREQ");
        break;
    case ANDEQ:
        printf("ANDEQ");
        break;
    case OREQ:
        printf("OREQ");
        break;
    case XOREQ:
        printf("XOREQ");
        break;
    case AUTO:
        printf("AUTO");
        break;
    case BREAK:
        printf("BREAK");
        break;
    case CASE:
        printf("CASE");
        break;
    case CHAR:
        printf("CHAR");
        break;
    case CONST:
        printf("CONST");
        break;
    case CONTINUE:
        printf("CONTINUE");
        break;
    case DEFAULT:
        printf("DEFAULT");
        break;
    case DO:
        printf("DO");
        break;
    case DOUBLE:
        printf("DOUBLE");
        break;
    case ELSE:
        printf("ELSE");
        break;
    case ENUM:
        printf("ENUM");
        break;
    case EXTERN:
        printf("EXTERN");
        break;
    case FLOAT:
        printf("FLOAT");
        break;
    case FOR:
        printf("FOR");
        break;
    case GOTO:
        printf("GOTO");
        break;
    case IF:
        printf("IF");
        break;
    case INLINE:
        printf("INLINE");
        break;
    case INT:
        printf("INT");
        break;
    case LONG:
        printf("LONG");
        break;
    case REGISTER:
        printf("REGISTER");
        break;
    case RESTRICT:
        printf("RESTRICT");
        break;
    case RETURN:
        printf("RETURN");
        break;
    case SHORT:
        printf("SHORT");
        break;
    case SIGNED:
        printf("SIGNED");
        break;
    case SIZEOF:
        printf("SIZEOF");
        break;
    case STATIC:
        printf("STATIC");
        break;
    case STRUCT:
        printf("STRUCT");
        break;
    case SWITCH:
        printf("SWITCH");
        break;
    case TYPEDEF:
        printf("TYPEDEF");
        break;
    case UNION:
        printf("UNION");
        break;
    case UNSIGNED:
        printf("UNSIGNED");
        break;
    case VOID:
        printf("VOID");
        break;
    case VOLATILE:
        printf("VOLATILE");
        break;
    case WHILE:
        printf("WHILE");
        break;
    case _BOOL:
        printf("_BOOL");
        break;
    case _COMPLEX:
        printf("_COMPLEX");
        break;
    case _IMAGINARY:
        printf("_IMAGINARY");
        break;
    }
}
