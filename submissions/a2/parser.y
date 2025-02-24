%debug

%{
    // what the hell is happening

    #include <stdlib.h>
    #include <stdio.h>
    #include "lexer.h"
    #include "ast.h"

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s:%d: %s\n", filename, line_num, s);
    }

%}

%code requires{
    #include "types.h"
}

%union{
    string_t string;
    number_t number;
    ast_node_t *node;
}

%token
    IDENT
    CHARLIT
    STRINGLIT
    NUMBERLIT
    INDSEL "->"
    PLUSPLUS "++"
    MINUSMINUS "--"
    SHL "<<"
    SHR ">>"
    LTEQ "<="
    GTEQ ">="
    EQEQ "=="
    NOTEQ "!="
    LOGAND "&&"
    LOGOR "||"
    ELLIPSIS "..."
    TIMESEQ "*="
    DIVEQ "/="
    MODEQ "%="
    PLUSEQ "+="
    MINUSEQ "-="
    SHLEQ "<<="
    SHREQ ">>="
    ANDEQ "&="
    OREQ "|="
    XOREQ "^="
    AUTO
    ALIGNOF
    BREAK
    CASE
    CHAR
    CONST
    CONTINUE
    DEFAULT
    DO
    DOUBLE
    ELSE
    ENUM
    EXTERN
    FLOAT
    FOR
    GOTO
    IF
    INLINE
    INT
    LONG
    REGISTER
    RESTRICT
    RETURN
    SHORT
    SIGNED
    SIZEOF
    STATIC
    STRUCT
    SWITCH
    TYPEDEF
    UNION
    UNSIGNED
    VOID
    VOLATILE
    WHILE
    _BOOL
    _COMPLEX
    _IMAGINARY

/* precedence ordered from lowest to highest priority */
/* postfix unary operators have priority over prefix */

%left ',' /* commas are special since their meaning changes for function calls */
%right '=' "+=" "-=" "*=" "/=" "%=" "<<=" ">>=" "&=" "^=" "|="
%right '?' ':' /* all ternaries are evaluated like  ? ( ) : */
%left "||"
%left "&&"
%left '|'
%left '^'
%left '&'
%left "==" "!="
%left '<' "<=" '>' ">="
%left "<<" ">>"
%left '+' '-'
%left '*' '/' '%'
%right '!' '~' SIZEOF ALIGNOF
%left "++" "--" '(' '[' '.' "->"

/* not an actual token but used in AST_BINARY_OP to denote a function call */
%token FUNCTION_CALL

%type <string> IDENT STRINGLIT CHARLIT
%type <number> NUMBERLIT
%nterm <node> expr expr_list

%destructor { } <number>
%destructor {free($$.buffer);} <string>
%destructor {ast_free($$);} <node>

%%

statement_sequence:
    statement                       {}
    | statement_sequence statement  {}

statement:
    expr_list ';'                   {
                                        if ($1)
                                        {
                                            printf("%% EXPR %%\n\n");
                                            ast_print($1, 0);
                                            ast_free($1);
                                            printf("\n");
                                        }
                                        else
                                        {
                                            printf("%% NOP %%\n\n");
                                        }
                                    }

expr_list:
    %empty                          {$$ = 0;}
    | expr                          {$$ = $1;}
    | expr_list ',' expr            {$$ = ast_new_binary_op(',', $1, $3);}

expr:
    IDENT                           {$$ = ast_new_ident($1.buffer);}
    | CHARLIT                       {$$ = ast_new_charlit($1.buffer[0]);}
    | STRINGLIT                     {$$ = ast_new_stringlit($1);}
    | NUMBERLIT                     {$$ = ast_new_numberlit($1);}
    | '(' expr ')'                  {$$ = $2;}

    | expr '=' expr                 {$$ = ast_new_binary_op('=', $1, $3);}
    | expr "+=" expr                {$$ = ast_new_binary_op(PLUSEQ, $1, $3);}
    | expr "-=" expr                {$$ = ast_new_binary_op(MINUSEQ, $1, $3);}
    | expr "*=" expr                {$$ = ast_new_binary_op(TIMESEQ, $1, $3);}
    | expr "/=" expr                {$$ = ast_new_binary_op(DIVEQ, $1, $3);}
    | expr "%=" expr                {$$ = ast_new_binary_op(MODEQ, $1, $3);}
    | expr "<<=" expr               {$$ = ast_new_binary_op(SHLEQ, $1, $3);}
    | expr ">>=" expr               {$$ = ast_new_binary_op(SHREQ, $1, $3);}
    | expr "&=" expr                {$$ = ast_new_binary_op(ANDEQ, $1, $3);}
    | expr "^=" expr                {$$ = ast_new_binary_op(XOREQ, $1, $3);}
    | expr "|=" expr                {$$ = ast_new_binary_op(OREQ, $1, $3);}

    | expr '?' expr_list ':' expr   {$$ = ast_new_ternary_op($1, $3, $5);}

    | expr "&&" expr                {$$ = ast_new_binary_op(LOGAND, $1, $3);}
    | expr "||" expr                {$$ = ast_new_binary_op(LOGOR, $1, $3);}

    | expr '&' expr                 {$$ = ast_new_binary_op('&', $1, $3);}
    | expr '^' expr                 {$$ = ast_new_binary_op('^', $1, $3);}
    | expr '|' expr                 {$$ = ast_new_binary_op('|', $1, $3);}

    | expr "==" expr                {$$ = ast_new_binary_op(EQEQ, $1, $3);}
    | expr "!=" expr                {$$ = ast_new_binary_op(NOTEQ, $1, $3);}

    | expr '<' expr                 {$$ = ast_new_binary_op('<', $1, $3);}
    | expr "<=" expr                {$$ = ast_new_binary_op(LTEQ, $1, $3);}
    | expr '>' expr                 {$$ = ast_new_binary_op('>', $1, $3);}
    | expr ">=" expr                {$$ = ast_new_binary_op(GTEQ, $1, $3);}

    | expr "<<" expr                {$$ = ast_new_binary_op(SHL, $1, $3);}
    | expr ">>" expr                {$$ = ast_new_binary_op(SHR, $1, $3);}

    | expr '+' expr                 {$$ = ast_new_binary_op('+', $1, $3);}
    | expr '-' expr                 {$$ = ast_new_binary_op('-', $1, $3);}

    | expr '*' expr                 {$$ = ast_new_binary_op('*', $1, $3);}
    | expr '/' expr                 {$$ = ast_new_binary_op('/', $1, $3);}
    | expr '%' expr                 {$$ = ast_new_binary_op('%', $1, $3);}    

    | "++" expr                     {$$ = ast_new_binary_op(PLUSEQ, $2, ast_new_numberlit((number_t){.integer = 1, .full_type = NT_INT}));} %prec SIZEOF
    | "--" expr                     {$$ = ast_new_binary_op(MINUSEQ, $2, ast_new_numberlit((number_t){.integer = 1, .full_type = NT_INT}));} %prec SIZEOF
    | '+' expr                      {$$ = ast_new_unary_op('+', $2);} %prec SIZEOF
    | '-' expr                      {$$ = ast_new_unary_op('-', $2);} %prec SIZEOF
    | '!' expr                      {$$ = ast_new_unary_op('!', $2);}
    | '~' expr                      {$$ = ast_new_unary_op('~', $2);}
    /* TODO type cast */
    | '*' expr                      {$$ = ast_new_unary_op('*', $2);} %prec SIZEOF
    | '&' expr                      {$$ = ast_new_unary_op('&', $2);} %prec SIZEOF
    | SIZEOF expr                   {$$ = ast_new_unary_op(SIZEOF, $2);}
    | ALIGNOF expr                  {$$ = ast_new_unary_op(ALIGNOF, $2);}

    | expr "++"                     {$$ = ast_new_unary_op(PLUSPLUS, $1);}
    | expr "--"                     {$$ = ast_new_unary_op(MINUSMINUS, $1);}
    | expr '(' expr_list ')'        {$$ = ast_new_binary_op(FUNCTION_CALL, $1, $3);}
    | expr '[' expr ']'             {$$ = ast_new_unary_op('*', ast_new_binary_op('+', $1, $3));}
    | expr '.' expr                 {$$ = ast_new_binary_op('.', $1, $3);}
    | expr "->" expr                {$$ = ast_new_binary_op('.', ast_new_unary_op('*', $1), $3);}

%%
