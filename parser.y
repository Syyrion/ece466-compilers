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

/* postfix unary operators have priority over prefix */

%type <string> IDENT STRINGLIT CHARLIT
%type <number> NUMBERLIT
%nterm 
    <node> primary_expression
    <node> postfix_expression
    <node> unary_expression
    <node> cast_expression
    <node> multiplicative_expression
    <node> additive_expression
    <node> shift_expression
    <node> relational_expression
    <node> equality_expression
    <node> and_expression
    <node> xor_expression
    <node> or_expression
    <node> logical_and_expression
    <node> logical_or_expression
    <node> conditional_expression
    <node> assignment_expression
    <node> expression
    <node> constant_expression

%destructor { } <number>
%destructor {free($$.buffer);} <string>
%destructor {ast_free($$);} <node>

%%

external_declaration:
    function_definition
    | declaration
    ;

function_definition:
    declaration_specifiers declarator compound_statement
    | declaration_specifiers declarator declaration_list compound_statement
    ;

declaration_list:
    declaration
    | declaration_list declaration
    ;

compound_statement:
    '{' block_item_list '}'
    '{' '}'
    ;

block_item_list:
    block_item
    | block_item_list block_item
    ;

block_item:
    declaration
    | statement
    ;

// ## STATEMENTS

statement:
    compound_statement
    | expression_statement
    ;

expression_statement:
    expression ';'
    | ';'
    ;

// ## EXPRESSIONS

primary_expression:
    IDENT {$$ = ast_new_ident($1.buffer);}
    | CHARLIT {$$ = ast_new_charlit($1.buffer[0]);}
    | STRINGLIT {$$ = ast_new_stringlit($1);}
    | NUMBERLIT {$$ = ast_new_numberlit($1);}
    | '(' expression ')' {$$ = $2;}
    ;


postfix_expression:
    primary_expression
    | postfix_expression '[' expression ']'
    | postfix_expression '(' ')'
    | postfix_expression '(' argument_expression_list ')'
    | postfix_expression '.' IDENT {$$ = ast_new_binary_op('.', $1, $3);}
    | postfix_expression "->" IDENT {$$ = ast_new_binary_op('.', ast_new_unary_op('*', $1), $3);}
    | postfix_expression "++" {$$ = ast_new_unary_op(PLUSPLUS, $1);}
    | postfix_expression "--" {$$ = ast_new_unary_op(MINUSMINUS, $1);}
    ;

argument_expression_list:
    assignment_expression
    | argument_expression_list ',' assignment_expression
    ;

unary_expression:
    postfix_expression
    | "++" unary_expression
    | "--" unary_expression
    | '&' cast_expression {$$ = }
    | '*' cast_expression {$$ = }
    | '+' cast_expression {$$ = }
    | '-' cast_expression {$$ = }
    | '~' cast_expression {$$ = }
    | '!' cast_expression {$$ = }
    | SIZEOF unary_expression {$$ = }
    | ALIGNOF unary_expression {$$ = }
    /* | SIZEOF '(' type_name ')' */
    ;

cast_expression:
    unary_expression
    /* | '(' type_name ')' cast_expression */
    ;

multiplicative_expression:
    cast_expression
    | multiplicative_expression '*' cast_expression {$$ = ast_new_binary_op('*', $1, $3);}
    | multiplicative_expression '/' cast_expression {$$ = ast_new_binary_op('/', $1, $3);}
    | multiplicative_expression '%' cast_expression {$$ = ast_new_binary_op('%', $1, $3);}
    ;

additive_expression:
    multiplicative_expression
    | additive_expression '+' multiplicative_expression {$$ = ast_new_binary_op('+', $1, $3);}
    | additive_expression '-' multiplicative_expression {$$ = ast_new_binary_op('-', $1, $3);}
    ;

shift_expression:
    additive_expression
    | shift_expression "<<" additive_expression {$$ = ast_new_binary_op(SHL, $1, $3);}
    | shift_expression ">>" additive_expression {$$ = ast_new_binary_op(SHR, $1, $3);}
    ;

relational_expression:
    shift_expression
    | relational_expression '<' shift_expression {$$ = ast_new_binary_op('<', $1, $3);}
    | relational_expression "<=" shift_expression {$$ = ast_new_binary_op(LTEQ, $1, $3);}
    | relational_expression '>' shift_expression {$$ = ast_new_binary_op('>', $1, $3);}
    | relational_expression "<=" shift_expression {$$ = ast_new_binary_op(GTEQ, $1, $3);}
    ;

equality_expression:
    relational_expression
    | equality_expression "==" relational_expression {$$ = ast_new_binary_op(EQEQ, $1, $3);}
    | equality_expression "!=" relational_expression {$$ = ast_new_binary_op(NOTEQ, $1, $3);}
    ;

and_expression:
    equality_expression
    | and_expression '&' equality_expression {$$ = ast_new_binary_op('&', $1, $3);}
    ;
xor_expression:
    and_expression
    | xor_expression '^' and_expression {$$ = ast_new_binary_op('^', $1, $3);}
    ;
or_expression:
    xor_expression
    | or_expression '|' xor_expression {$$ = ast_new_binary_op('|', $1, $3);}
    ;

logical_and_expression:
    or_expression
    | logical_and_expression "&&" or_expression {$$ = ast_new_binary_op(LOGAND, $1, $3);}
    ;

logical_or_expression:
    logical_and_expression
    | logical_or_expression "||" logical_and_expression {$$ = ast_new_binary_op(LOGOR, $1, $3);}
    ;

conditional_expression:
    logical_or_expression
    | logical_or_expression '?' expression ':' conditional_expression {$$ = ast_new_ternary_op($1, $3, $5);}
    ;

assignment_expression:
    conditional_expression
    | unary_expression '=' assignment_expression {$$ = ast_new_binary_op('=', $1, $3);}
    | unary_expression "*=" assignment_expression {$$ = ast_new_binary_op(PLUSEQ, $1, $3);}
    | unary_expression "/=" assignment_expression {$$ = ast_new_binary_op(MINUSEQ, $1, $3);}
    | unary_expression "%=" assignment_expression {$$ = ast_new_binary_op(TIMESEQ, $1, $3);}
    | unary_expression "+=" assignment_expression {$$ = ast_new_binary_op(DIVEQ, $1, $3);}
    | unary_expression "-=" assignment_expression {$$ = ast_new_binary_op(MODEQ, $1, $3);}
    | unary_expression "<<=" assignment_expression {$$ = ast_new_binary_op(SHLEQ, $1, $3);}
    | unary_expression ">>=" assignment_expression {$$ = ast_new_binary_op(SHREQ, $1, $3);}
    | unary_expression "&=" assignment_expression {$$ = ast_new_binary_op(ANDEQ, $1, $3);}
    | unary_expression "^=" assignment_expression {$$ = ast_new_binary_op(XOREQ, $1, $3);}
    | unary_expression "|=" assignment_expression {$$ = ast_new_binary_op(OREQ, $1, $3);}
    ;
expression:
    assignment_expression
    | expression ',' assignment_expression {$$ = ast_new_binary_op(',', $1, $3);}
    ;

constant_expression:
    conditional_expression
    ;


// ## DECLARATIONS
declaration:
    declaration_specifiers init_declarator_list ';'
    ;

declaration_specifiers:
    storage_class_specifier
    | declaration_specifiers storage_class_specifier
    | type_specifier
    | declaration_specifiers type_specifier
    | type_qualifier
    | declaration_specifiers type_qualifier
    | function_specifier
    | declaration_specifiers function_specifier
    ;

init_declarator_list:
    init_declarator
    init_declarator_list ',' init_declarator
    ;

init_declarator:
    declarator
    | declarator '=' initializer
    ;

storage_class_specifier:
    TYPEDEF
    | EXTERN
    | STATIC
    | AUTO
    | REGISTER
    ;

type_specifier:
    VOID
    | CHAR
    | SHORT
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | SIGNED
    | UNSIGNED
    | _BOOL
    | _COMPLEX
    | struct_or_union_specifier
    | enum_specifier
    | typedef_name
    ;

// ## STRUCTS AND UNIONS
struct_or_union_specifier:
    struct_or_union '{' struct_declaration_list '}'
    | struct_or_union IDENT '{' struct_declaration_list '}'
    | struct_or_union IDENT
    ;

struct_or_union:
    STRUCT
    | UNION
    ;

struct_declaration_list:
    struct_declaration
    | struct_declaration_list struct_declaration
    ;

struct_declaration:
    specifier_qualifier_list struct_declarator_list ';'
    ;

specifier_qualifier_list:
    type_specifier
    | specifier_qualifier_list type_specifier
    | type_qualifier
    | specifier_qualifier_list type_qualifier
    ;

struct_declarator_list:
    struct_declarator
    | struct_declarator_list ',' struct_declarator
    ;

struct_declarator:
    declarator
    | ':' constant_expression
    | declarator ':' constant_expression
    ;

// ## ENUMS

enum_specifier:
    ENUM IDENT
    | ENUM '{' enumerator_list '}'
    | ENUM IDENT '{' enumerator_list '}'
    | ENUM '{' enumerator_list ',' '}'
    | ENUM IDENT '{' enumerator_list ',' '}'
    ;

enumerator_list:
    enumerator
    | enumerator_list ',' enumerator
    ;

enumerator:
    enumeration_constant
    | enumeration_constant '=' constant_expression
    ;

enumeration_constant:
    IDENT
    ;

type_qualifier:
    CONST
    | RESTRICT
    | VOLATILE
    ;

function_specifier:
    INLINE
    ;

declarator:
    direct_declarator
    | pointer direct_declarator
    ;

direct_declarator:
    IDENT
    | '(' declarator ')'
    | direct_declarator '[' ']'
    | direct_declarator '[' type_qualifier_list ']'
    | direct_declarator '[' assignment_expression ']'
    | direct_declarator '[' type_qualifier_list assignment_expression ']'
    | direct_declarator '[' STATIC assignment_expression ']'
    | direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
    | direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
    | direct_declarator '[' type_qualifier_list '*' ']'
    | direct_declarator '[' '*' ']'
    | direct_declarator '(' parameter_type_list ')'
    | direct_declarator '(' identifier_list ')'
    | direct_declarator '(' ')'
    ;

pointer:
    '*'
    | '*' type_qualifier_list
    | '*' pointer
    | '*' type_qualifier_list pointer
    ;

type_qualifier_list:
    type_qualifier
    | type_qualifier_list type_qualifier
    ;

parameter_type_list:
    parameter_list
    | parameter_list ',' "..."
    ;

parameter_list:
    parameter_declaration
    | parameter_list ',' parameter_declaration
    ;

parameter_declaration:
    declaration_specifiers declarator
    | declaration_specifiers
    | declaration_specifiers abstract_declarator
    ;

identifier_list:
    IDENT
    | identifier_list ',' IDENT
    ;

type_name:
    specifier_qualifier_list
    | specifier_qualifier_list abstract_declarator
    ;

abstract_declarator:
    pointer
    | direct_abstract_declarator
    | pointer direct_abstract_declarator
    ;

direct_abstract_declarator:
    '(' abstract_declarator ')'
    | '[' ']'
    | direct_abstract_declarator '[' ']'
    | '[' assignment_expression ']'
    | direct_abstract_declarator '[' assignment_expression ']'
    | '[' '*' ']'
    | direct_abstract_declarator '[' '*' ']'
    | '(' ')'
    | direct_abstract_declarator '(' ')'
    | '(' parameter_type_list ')'
    | direct_abstract_declarator '(' parameter_type_list ')'
    ;

typedef_name:
    IDENT
    ;

initializer:
    assignment_expression
    ;

%%
