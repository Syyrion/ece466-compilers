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

%left ','
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

/* TODO alignof and friends */
/* postfix unary operators have priority over prefix */



%type <string> IDENT STRINGLIT CHARLIT
%type <number> NUMBERLIT
%nterm <node> expr

%destructor { } <number>
%destructor {free($$.buffer);} <string>
%destructor {ast_free($$);} <node>

%%

statement_sequence:
    statement                       {}
    | statement_sequence statement  {}

statement:
    expr ';'                        {printf("%% EXPR %%\n\n"); ast_print($1, 0); ast_free($1); printf("\n");}

expr:
    IDENT                           {$$ = ast_new_ident($1.buffer);}
    | CHARLIT                       {$$ = ast_new_charlit($1.buffer[0]);}
    | STRINGLIT                     {$$ = ast_new_stringlit($1);}
    | NUMBERLIT                     {$$ = ast_new_numberlit($1);}
    | '(' expr ')'                  {$$ = $2;}

    | expr '*' expr                 {$$ = ast_new_binary_op('*', $1, $3);}
    | expr '/' expr                 {$$ = ast_new_binary_op('/', $1, $3);}
    | expr '%' expr                 {$$ = ast_new_binary_op('%', $1, $3);}

    | expr '+' expr                 {$$ = ast_new_binary_op('+', $1, $3);}
    | expr '-' expr                 {$$ = ast_new_binary_op('-', $1, $3);}

    | expr "<<" expr                {$$ = ast_new_binary_op(SHL, $1, $3);}
    | expr ">>" expr                {$$ = ast_new_binary_op(SHR, $1, $3);}

    | expr '<' expr                 {$$ = ast_new_binary_op('<', $1, $3);}
    | expr "<=" expr                {$$ = ast_new_binary_op(LTEQ, $1, $3);}
    | expr '>' expr                 {$$ = ast_new_binary_op('>', $1, $3);}
    | expr ">=" expr                {$$ = ast_new_binary_op(GTEQ, $1, $3);}

    | expr "==" expr                {$$ = ast_new_binary_op(EQEQ, $1, $3);}
    | expr "!=" expr                {$$ = ast_new_binary_op(NOTEQ, $1, $3);}

    | expr '&' expr                 {$$ = ast_new_binary_op('&', $1, $3);}
    | expr '^' expr                 {$$ = ast_new_binary_op('^', $1, $3);}
    | expr '|' expr                 {$$ = ast_new_binary_op('|', $1, $3);}
    
    | expr "&&" expr                {$$ = ast_new_binary_op(LOGAND, $1, $3);}
    | expr "||" expr                {$$ = ast_new_binary_op(LOGOR, $1, $3);}

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

    | expr ',' expr                 {$$ = ast_new_binary_op(',', $1, $3);}




/*
    | expr index
    | function_call


index:
    '[' expr ']'

function_call:
    IDENT '(' argument_list ')'

argument_list:
    %empty
    | expr
    | argument_list ',' expr
*/
%%