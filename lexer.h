#ifndef LEXER_GLOBALS_INCLUDED
#define LEXER_GLOBALS_INCLUDED

extern char *filename;
extern int line_num;

// provided by flex
extern char *yytext;
extern int yyleng;
extern int yylex(void);

#endif