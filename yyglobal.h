typedef union
{
    char *string_literal;
    long long integer;
    long double real;
} YYSTYPE;

extern YYSTYPE yylval;

extern char *yytext;
extern int yyleng;
