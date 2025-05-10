#include <stdio.h>
#include <ctype.h>
#include "expression_operators.h"

void print_expression_operator(yytoken_kind_t op)
{
    if (isprint(op))
    {
        fputc(op, stdout);
        return;
    }
    switch (op)
    {
    case SHL:
        printf("<<");
        break;
    case SHR:
        printf(">>");
        break;
    case LTEQ:
        printf("<=");
        break;
    case GTEQ:
        printf(">=");
        break;
    case EQEQ:
        printf("==");
        break;
    case NOTEQ:
        printf("!=");
        break;
    case LOGAND:
        printf("&&");
        break;
    case LOGOR:
        printf("||");
        break;
    case PLUSEQ:
        printf("+=");
        break;
    case MINUSEQ:
        printf("-=");
        break;
    case TIMESEQ:
        printf("*=");
        break;
    case DIVEQ:
        printf("/=");
        break;
    case MODEQ:
        printf("%=");
        break;
    case SHLEQ:
        printf("<<=");
        break;
    case SHREQ:
        printf(">>=");
        break;
    case ANDEQ:
        printf("&=");
        break;
    case XOREQ:
        printf("^=");
        break;
    case OREQ:
        printf("|=");
        break;
    case SIZEOF:
        printf("sizeof");
        break;
    case ALIGNOF:
        printf("alignof");
        break;
    case PLUSPLUS:
        printf("++");
        break;
    case MINUSMINUS:
        printf("--");
        break;
    default:
        fprintf(stderr, "attempted to print operator with unknown id %d", op);
        printf("<unknown operator %d>", op);
        break;
    }
}