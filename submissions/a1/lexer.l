%option noyywrap

%{
    // the spaghetti is strong with this one

    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "tokens-manual.h"
    #include "yyglobal.h"
    #include <ctype.h>

    #define INITIAL_SIZE 256

    YYSTYPE yylval;

    char *filename;
    int line_num = -1;

    enum yylval_type {
        LV_NONE,
        LV_STRING,
        LV_NUMBER,
    };

    enum yylval_type yylval_type = LV_NONE;

    // string attributes
    int yylval_len;
    int yylval_size;

    // bit-packed number type stuff
    #define NT_UNSIGNED        0b1000
    #define NT_INT             0b0000
    #define NT_LONG            0b0001
    #define NT_LONG_LONG       0b0010
    #define NT_FLOAT           0b0100
    #define NT_DOUBLE          0b0101
    #define NT_LONG_DOUBLE     0b0110

    union {
        char whole;
        struct {
            char type:2;
            char is_real:1;
            char is_unsigned:1;
        } bit;
    } yylval_num_type;

    // string lvalue stuff
    void begin_str()
    {
        yylval_type = LV_STRING;
        yylval_size = INITIAL_SIZE;
        yylval_len = 0;
        yylval.string_literal = malloc(yylval_size);
    }

    void append_char(const char c)
    {
        yylval.string_literal[yylval_len] = c;
        yylval.string_literal[yylval_len + 1] = 0;
        if (++yylval_len == yylval_size - 1) // size - 1 because of null byte
            yylval.string_literal = realloc(yylval.string_literal, yylval_size *= 2);
    }

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
                printf("\\%03o", (unsigned char) s[i]);
        }
    }

    char get_float_type(char *n)
    {
        int i = strlen(n) - 1;
        char t = n[i] | 0b100000;
        if (t == 'f')
        {
            n[i] = 0;
            return NT_FLOAT;
        }
        if (t == 'l')
        {
            n[i] = 0;
            return NT_LONG_DOUBLE;
        }
        return NT_DOUBLE;
    }

    char get_int_type(char *n)
    {
        char type = 0;
        int i = strlen(n) - 1;
        char c;
        while ((c = n[i] | 0b100000) == 'l' || c == 'u')
        {
            if (c == 'u')
                type |= NT_UNSIGNED;
            else
                type++;
            i--;
        }
        n[i + 1] = 0;
        return type;
    }
    
%}

%x strlit
%x charlit

/* number suffix stuff */
UNSIGNED        (u|U)
LLONG           (l{1,2}|L{1,2})
INT_SUFFIX      (({UNSIGNED}?{LLONG}?)|({LLONG}?{UNSIGNED}?))
FLOAT_SUFFIX    ([fFlL]?)

%%

#.+\n           {
                    char *str = yytext + 2;

                    line_num = atoi(strtok(str, " \n"));

                    char *f = strtok(NULL, " \n") + 1;
                    f[strlen(f) - 1] = 0;

                    free(filename);
                    filename = strdup(f);
                }

\n              {line_num++;}
[ \t]           /* ignore whitespace */

auto            {return AUTO;}
break           {return BREAK;}
case            {return CASE;}
char            {return CHAR;}
const           {return CONST;}
continue        {return CONTINUE;}
default         {return DEFAULT;}
do              {return DO;}
double          {return DOUBLE;}
else            {return ELSE;}
enum            {return ENUM;}
extern          {return EXTERN;}
float           {return FLOAT;}
for             {return FOR;}
goto            {return GOTO;}
if              {return IF;}
inline          {return INLINE;}
int             {return INT;}
long            {return LONG;}
register        {return REGISTER;}
restrict        {return RESTRICT;}
return          {return RETURN;}
short           {return SHORT;}
signed          {return SIGNED;}
sizeof          {return SIZEOF;}
static          {return STATIC;}
struct          {return STRUCT;}
switch          {return SWITCH;}
typedef         {return TYPEDEF;}
union           {return UNION;}
unsigned        {return UNSIGNED;}
void            {return VOID;}
volatile        {return VOLATILE;}
while           {return WHILE;}
_Bool           {return _BOOL;}
_Complex        {return _COMPLEX;}
_Imaginary      {return _IMAGINARY;}

;               {return ';';}
~               {return '~';}
,               {return ',';}
!               {return '!';}

:               {return ':';}
\?              {return '?';}

\(              {return '(';}
\)              {return ')';}
\[              {return '[';}
\]              {return ']';}
\{              {return '{';}
\}              {return '}';}

\.              {return '.';}
\->             {return INDSEL;}

=               {return '=';}

\+=             {return PLUSEQ;}
\-=             {return MINUSEQ;}
\*=             {return TIMESEQ;}
\/=             {return DIVEQ;}
%=              {return MODEQ;}

&=              {return ANDEQ;}
\|=             {return OREQ;}
\^=             {return XOREQ;}

\<\<=           {return SHLEQ;}
>>=             {return SHREQ;}


&               {return '&';}
\|              {return '|';}
\^              {return '^';}

&&              {return LOGAND;}
\|\|            {return LOGOR;}

==              {return EQEQ;}
\<              {return '<';}
\<=             {return LTEQ;}
>               {return '>';}
>=              {return GTEQ;}
!=              {return NOTEQ;}

\+\+            {return PLUSPLUS;}
\-\-            {return MINUSMINUS;}

\+              {return '+';}
\-              {return '-';}
\*              {return '*';}
\/              {return '/';}
%               {return '%';}

\<\<            {return SHL;}
>>              {return SHR;}

\.{3}           {return ELLIPSIS;}

[A-Za-z_][A-Za-z0-9_]*      {
                                yylval_type = LV_STRING;
                                yylval.string_literal = strdup(yytext);
                                yylval_len = strlen(yylval.string_literal);
                                return IDENT;
                            }


    /* 
        huge pain in the ass
        (this seems to work but probably will mess up in some random corner case)
        TODO It's functional for now but probably should make better later.
    */
0[xX][0-9A-Fa-f]+p[\+\-]?[0-9]+{FLOAT_SUFFIX}                   |
[0-9]+e[\+\-]?[0-9]+{FLOAT_SUFFIX}                              |
(([0-9]*\.[0-9]+)|([0-9]+\.))(e[\+\-]?[0-9]+)?{FLOAT_SUFFIX}    {
                                                                    yylval_num_type.whole = get_float_type(yytext);
                                                                    yylval.real = strtold(yytext, NULL);
                                                                    yylval_type = LV_NUMBER;
                                                                    return NUMBER;
                                                                }

0[xX][0-9A-Fa-f]+{INT_SUFFIX}                                   {
                                                                    yylval_num_type.whole = get_int_type(yytext);
                                                                    yylval.integer = strtoll(yytext + 2, NULL, 16);
                                                                    yylval_type = LV_NUMBER;
                                                                    return NUMBER;
                                                                }
0[bB][01]+{INT_SUFFIX}                                          {   // binary too
                                                                    yylval_num_type.whole = get_int_type(yytext);
                                                                    yylval.integer = strtoll(yytext + 2, NULL, 2);
                                                                    yylval_type = LV_NUMBER;
                                                                    return NUMBER;
                                                                }
[0-9]+{INT_SUFFIX}                                              {
                                                                    yylval_num_type.whole = get_int_type(yytext);
                                                                    yylval.integer = strtoll(yytext, NULL, yytext[0] == '0' ? 8 : 10);
                                                                    yylval_type = LV_NUMBER;
                                                                    return NUMBER;
                                                                }

L?\"                                BEGIN strlit; begin_str();
L?\'                                BEGIN charlit; begin_str();
<charlit,strlit>\\a                 append_char('\x07');
<charlit,strlit>\\b                 append_char('\x08');
<charlit,strlit>\\f                 append_char('\x0c');
<charlit,strlit>\\n                 append_char('\x0a');
<charlit,strlit>\\r                 append_char('\x0d');
<charlit,strlit>\\t                 append_char('\x09');
<charlit,strlit>\\v                 append_char('\x0b');
<charlit,strlit>\\\\                append_char('\\');
<charlit,strlit>\\\'                append_char('\'');
<charlit,strlit>\\\"                append_char('"');
<charlit,strlit>\\\?                append_char('?');
<charlit,strlit>\\[0-7]{1,3}        append_char((char) strtol(yytext + 1, NULL, 8)); // this covers \0 too
<charlit,strlit>\\x[0-9A-Fa-f]*     {
                                        if (yyleng == 2)
                                        {
                                            fprintf(stderr, "%s:%d: Error: \\x used with no following hex digits\n", filename, line_num);
                                        }
                                        else
                                        {
                                            char *conv;
                                            if (yyleng > 4)
                                            {
                                                fprintf(stderr, "%s:%d: Warning: hex escape sequence out of range\n", filename, line_num);
                                                conv = yytext + (yyleng - 2);
                                            }
                                            else
                                            {
                                                conv = yytext + 2;
                                            }
                                            append_char((char) strtol(conv, NULL, 16));
                                        }

                                        
                                    }
<charlit,strlit>\\.                 {
                                        fprintf(stderr, "%s:%d: Warning: unknown escape sequence %s\n", filename, line_num, yytext);
                                        append_char(yytext[1]);
                                    }
<strlit>\"                          BEGIN INITIAL; return STRING;
<charlit>\'                         {
                                        BEGIN INITIAL;
                                        if (yylval_len == 0)
                                        {
                                            fprintf(stderr, "%s:%d: Error: empty character constant\n", filename, line_num);
                                        }
                                        else if (yylval_len > 1)
                                        {
                                            fprintf(stderr, "%s:%d: Warning: Unsupported multibyte character literal truncated to first byte\n", filename, line_num);
                                            yylval.string_literal[1] = 0;
                                            yylval_len = 1;
                                            return CHARLIT;
                                        }
                                        else
                                        {
                                            return CHARLIT;
                                        }
                                    }
<charlit,strlit>.                   append_char(yytext[0]);

.                                   fprintf(stderr, "%s:%d: Error: unknown token %s\n", filename, line_num, yytext);
%%


void print_token_name(int);

int main()
{
    int t;
    filename = (char *)malloc(8);
    strcpy(filename, "<stdin>");

    while (t=yylex())
    {
        printf("%s\t%d\t", filename, line_num);
        print_token_name(t);

        switch(yylval_type)
        {
            case LV_NUMBER:
                printf("\t");
                if (yylval_num_type.bit.is_real)
                {
                    printf(
                        "REAL\t%Lg\t%s",
                        yylval.real,
                        yylval_num_type.bit.type == 0 ? "FLOAT"
                        : yylval_num_type.bit.type == 1 ? "DOUBLE"
                        : "LONG DOUBLE"
                    );
                }
                else
                {
                    printf(
                        "INTEGER\t%lld\t%s%s",
                        yylval.integer,
                        yylval_num_type.bit.is_unsigned ? "UNSIGNED " : "",
                        yylval_num_type.bit.type == 0 ? "INT"
                        : yylval_num_type.bit.type == 1 ? "LONG"
                        : "LONG LONG"
                    );
                }
                break;
            case LV_STRING:
                printf("\t");
                uniform_print(yylval.string_literal, yylval_len);
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
