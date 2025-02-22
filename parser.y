%debug

%{
    // what the hell is happening

    #include <stdlib.h>
    #include <stdio.h>

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s\n", s);
    }

%}

%code requires{
    extern char *filename;
    extern int line_num;

    // provided by flex
    extern char *yytext;
    extern int yyleng;   
    extern int yylex(void);

    #define NT_UNSIGNED 0b1000
    #define NT_INT 0b0000
    #define NT_LONG 0b0001
    #define NT_LONG_LONG 0b0010
    #define NT_FLOAT 0b0100
    #define NT_DOUBLE 0b0101
    #define NT_LONG_DOUBLE 0b0110
}

%union{
    char *string;
    unsigned long long strlen;
    unsigned long long strsize;

    unsigned long long integer;
    long double real;

    union
    {
        char nt_full;
        struct
        {
            char type : 2;
            char is_real : 1;
            char is_unsigned : 1;
        };
    };
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
    ';'

/* TODO alignof and friends */
%left '*' '/' '%'
%left '+' '-'
%left "<<" ">>"
%left '<' "<=" '>' ">="
%left "==" "!="
%left '&'
%left '^'
%left '|'
%left "&&"
%left "||"
%right '?' ':' /* all ternaries are evaluated like  ? ( ) : */
%right '=' "+=" "-=" "*=" "/=" "%=" "<<=" ">>=" "&=" "^=" "|="
%left ','

%type <string> IDENT

%%

statement_sequence:
    statement
    | statement_sequence statement

statement:
    expr ';'

expr:
    IDENT                           {printf("%d", ($1)[0]);}
    | CHARLIT
    | STRINGLIT
    | NUMBERLIT
    | '(' expr ')'

    | expr '*' expr
    | expr '/' expr
    | expr '%' expr

    | expr '+' expr
    | expr '-' expr

    | expr ">>" expr
    | expr "<<" expr

    | expr '<' expr
    | expr "<=" expr
    | expr '>' expr
    | expr ">=" expr

    | expr "==" expr
    | expr "!=" expr

    | expr '&' expr
    | expr '^' expr
    | expr '|' expr
    
    | expr "&&" expr
    | expr "||" expr

    | expr '=' expr
    | expr "+=" expr
    | expr "-=" expr
    | expr "*=" expr
    | expr "/=" expr
    | expr "%=" expr
    | expr "<<=" expr
    | expr ">>=" expr
    | expr "&=" expr
    | expr "^=" expr
    | expr "|=" expr

    | expr ',' expr




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