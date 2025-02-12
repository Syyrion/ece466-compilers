%option noyywrap

%{
    // the spaghetti is strong with this one

    #include <string.h>
    #include <stdlib.h>
    #include <ctype.h>
    #include "tokens-manual.h"
    #include "lexer.h"

    char *filename;
    int line_num = -1;

    YYSTYPE yylval;
    yylval_t yylval_type = LV_NONE;

    // string attributes
    int yylval_strlen;
    int yylval_strsize;

    yylval_num_t yylval_num_type;

    #define INITIAL_SIZE 256

    // string lvalue stuff
    void begin_str()
    {
        yylval_type = LV_STRING;
        yylval_strsize = INITIAL_SIZE;
        yylval_strlen = 0;
        yylval.string_literal = malloc(yylval_strsize);
    }

    void append_char(const char c)
    {
        yylval.string_literal[yylval_strlen] = c;
        yylval.string_literal[yylval_strlen + 1] = 0;
        if (++yylval_strlen == yylval_strsize - 1) // size - 1 because of null byte
            yylval.string_literal = realloc(yylval.string_literal, yylval_strsize *= 2);
    }

    char get_float_type(char *n)
    {
        int i = strlen(n) - 1;
        char t = tolower(n[i]);
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
        while ((c = tolower(n[i])) == 'l' || c == 'u')
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
                                yylval_strlen = strlen(yylval.string_literal);
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
                                                                    yylval_num_type.all = get_float_type(yytext);
                                                                    yylval.real = strtold(yytext, NULL);
                                                                    yylval_type = LV_NUMBER;
                                                                    return NUMBER;
                                                                }

0[xX][0-9A-Fa-f]+{INT_SUFFIX}                                   {
                                                                    yylval_num_type.all = get_int_type(yytext);
                                                                    yylval.integer = strtoull(yytext + 2, NULL, 16);
                                                                    yylval_type = LV_NUMBER;
                                                                    return NUMBER;
                                                                }
0[bB][01]+{INT_SUFFIX}                                          {   // binary too
                                                                    yylval_num_type.all = get_int_type(yytext);
                                                                    yylval.integer = strtoull(yytext + 2, NULL, 2);
                                                                    yylval_type = LV_NUMBER;
                                                                    return NUMBER;
                                                                }
[0-9]+{INT_SUFFIX}                                              {
                                                                    yylval_num_type.all = get_int_type(yytext);
                                                                    yylval.integer = strtoull(yytext, NULL, yytext[0] == '0' ? 8 : 10);
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
                                        if (yylval_strlen == 0)
                                        {
                                            fprintf(stderr, "%s:%d: Error: empty character constant\n", filename, line_num);
                                        }
                                        else if (yylval_strlen > 1)
                                        {
                                            fprintf(stderr, "%s:%d: Warning: Unsupported multibyte character literal truncated to first byte\n", filename, line_num);
                                            yylval.string_literal[1] = 0;
                                            yylval_strlen = 1;
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
