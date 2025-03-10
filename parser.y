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
    int integer;
    int type_qualifier;
    type_specifier_t type_specifier;
    storage_class_t storage_class_specifier;
    function_specifier_t function_specifier;
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
    <node> identifier string_literal constant
    <node> primary_expression
    <node> postfix_expression
    <node> argument_expression_list
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
    <node> declaration_specifiers
    <integer> assignment_operator
    <type_qualifier> type_qualifier
    <type_qualifier> type_qualifier_list
    <storage_class_specifier> storage_class_specifier
    <function_specifier> function_specifier
    <type_specifier> type_specifier
    <node> struct_or_union_specifier
    <node> enum_specifier

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
    /* TODO all other statements */
    ;

expression_statement:
    expression ';'
    | ';'
    ;

// ## EXPRESSIONS


identifier:
    IDENT {$$ = ast_new_ident($1.buffer);}
    ;

string_literal:
    STRINGLIT {$$ = ast_new_stringlit($1);}
    ;

constant:
    CHARLIT {$$ = ast_new_charlit($1.buffer[0]);}
    | NUMBERLIT {$$ = ast_new_numberlit($1);}
    ;

primary_expression:
    identifier
    | constant
    | string_literal
    | '(' expression ')' {$$ = $2;}
    ;


postfix_expression:
    primary_expression
    | postfix_expression '[' expression ']' {$$ = ast_new_unary_op('*', ast_new_binary_op('+', $1, $3));}
    | postfix_expression '(' ')' {$$ = ast_add_function_call_name(ast_new_function_call(), $1);}
    | postfix_expression '(' argument_expression_list ')' {$$ = ast_add_function_call_name($3, $1);}
    | postfix_expression '.' identifier {$$ = ast_new_binary_op('.', $1, $3);}
    | postfix_expression "->" identifier {$$ = ast_new_binary_op('.', ast_new_unary_op('*', $1), $3);}
    | postfix_expression "++" {$$ = ast_new_unary_op(PLUSPLUS, $1);}
    | postfix_expression "--" {$$ = ast_new_unary_op(MINUSMINUS, $1);}
    ;

argument_expression_list:
    assignment_expression {$$ = ast_add_function_call_argument(ast_new_function_call(), $1);}
    | argument_expression_list ',' assignment_expression {$$ = ast_add_function_call_argument($1, $3);}
    ;

unary_expression:
    postfix_expression
    | "++" unary_expression {$$ = ast_new_binary_op(PLUSEQ, $2, ast_new_numberlit((number_t){.integer = 1, .full_type = NT_INT}));}
    | "--" unary_expression {$$ = ast_new_binary_op(MINUSEQ, $2, ast_new_numberlit((number_t){.integer = 1, .full_type = NT_INT}));}
    | '&' cast_expression {$$ = ast_new_unary_op('&', $2);}
    | '*' cast_expression {$$ = ast_new_unary_op('*', $2);}
    | '+' cast_expression {$$ = ast_new_unary_op('+', $2);}
    | '-' cast_expression {$$ = ast_new_unary_op('-', $2);}
    | '~' cast_expression {$$ = ast_new_unary_op('~', $2);}
    | '!' cast_expression {$$ = ast_new_unary_op('!', $2);}
    | SIZEOF unary_expression {$$ = ast_new_unary_op(SIZEOF, $2);}
    | SIZEOF '(' type_name ')'
    | ALIGNOF unary_expression {$$ = ast_new_unary_op(ALIGNOF, $2);}
    ;

cast_expression:
    unary_expression
    '(' type_name ')' cast_expression
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
    | relational_expression ">=" shift_expression {$$ = ast_new_binary_op(GTEQ, $1, $3);}
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
    | unary_expression assignment_operator assignment_expression {$$ = ast_new_binary_op($2, $1, $3);}
    ;

assignment_operator:
    '=' {$$ = '='}
    | "*=" {$$ = PLUSEQ}
    | "/=" {$$ = MINUSEQ}
    | "%=" {$$ = TIMESEQ}
    | "+=" {$$ = DIVEQ}
    | "-=" {$$ = MODEQ}
    | "<<=" {$$ = SHLEQ}
    | ">>=" {$$ = SHREQ}
    | "&=" {$$ = ANDEQ}
    | "^=" {$$ = XOREQ}
    | "|=" {$$ = OREQ}
    ;

expression:
    assignment_expression
    | expression ',' assignment_expression {$$ = ast_new_binary_op(',', $1, $3);}
    ;

constant_expression:
    conditional_expression
    ;



// ## DECLARATIONS
// man, they really messed this standard up

declaration:
    declaration_specifiers init_declarator_list ';'
    ;

declaration_specifiers:
    storage_class_specifier {$$ = ast_set_variable_storage_class(ast_new_variable(), $1);}
    | type_specifier {$$ = ast_add_variable_type_specifier(ast_new_variable(), $1);}
    | type_qualifier {$$ = ast_add_variable_type_qualifier(ast_new_variable(), $1);}
    | function_specifier {$$ = ast_set_variable_function_specifier(ast_new_variable(), $1);}
    | declaration_specifiers storage_class_specifier {$$ = ast_set_variable_storage_class($1, $2);}
    | declaration_specifiers type_specifier {$$ = ast_add_variable_type_specifier($1, $2);}
    | declaration_specifiers type_qualifier {$$ = ast_add_variable_type_qualifier($1, $2);}
    | declaration_specifiers function_specifier {$$ = ast_set_variable_function_specifier($1, $2);}
    ;

init_declarator_list:
    init_declarator
    | init_declarator_list ',' init_declarator
    ;

init_declarator:
    declarator
    | declarator '=' initializer
    ;

// No more than one allowed per declaration
storage_class_specifier:
    EXTERN {$$ = SC_EXTERN;}
    | STATIC {$$ = SC_STATIC;}
    | AUTO {$$ = SC_AUTO;}
    | REGISTER {$$ = SC_REGISTER;}
    // | TYPEDEF
    ;

// At least one needed per declaration
type_specifier:
    VOID {$$ = (type_specifier_t){.scalar = SCLR_VOID};}
    | CHAR {$$ = (type_specifier_t){.scalar = SCLR_CHAR};}
    | SHORT {$$ = (type_specifier_t){.scalar = SCLR_SHORT};}
    | INT {$$ = (type_specifier_t){.scalar = SCLR_INT};}
    | LONG {$$ = (type_specifier_t){.scalar = SCLR_LONG};}
    | FLOAT {$$ = (type_specifier_t){.scalar = SCLR_FLOAT};}
    | DOUBLE {$$ = (type_specifier_t){.scalar = SCLR_DOUBLE};}
    | SIGNED {$$ = (type_specifier_t){.scalar = SCLR_SIGNED};}
    | UNSIGNED {$$ = (type_specifier_t){.scalar = SCLR_UNSIGNED};}
    | _BOOL {$$ = (type_specifier_t){.scalar = SCLR_BOOL};}
    | _COMPLEX {$$ = (type_specifier_t){.scalar = SCLR_COMPLEX};}
    | struct_or_union_specifier {$$ = (type_specifier_t){.scalar = SCLR_STRUCT_OR_UNION, .custom = $1};}
    | enum_specifier {$$ = (type_specifier_t){.scalar = SCLR_ENUM, .custom = $1};}
    // | typedef_name
    ;

// Any combination allowed. Repeated instances are treated as if there was only one.
type_qualifier:
    CONST {$$ = TQ_CONST;}
    | RESTRICT {$$ = TQ_RESTRICT;}
    | VOLATILE {$$ = TQ_VOLATILE;}
    ;

// Repeated instances are treated as if there was only one.
function_specifier:
    INLINE {$$ = FS_INLINE;}
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
    ENUM identifier
    | ENUM '{' enumerator_list '}'
    | ENUM identifier '{' enumerator_list '}'
    | ENUM '{' enumerator_list ',' '}' 
    | ENUM identifier '{' enumerator_list ',' '}'
    ;

enumerator_list:
    enumerator
    | enumerator_list ',' enumerator
    ;

enumerator:
    identifier
    | identifier '=' constant_expression
    ;

declarator:
    direct_declarator
    | pointer direct_declarator
    ;

direct_declarator:
    identifier
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
    '*' {}
    | '*' type_qualifier_list
    | '*' pointer
    | '*' type_qualifier_list pointer
    ;

type_qualifier_list:
    type_qualifier {$$ = $1;}
    | type_qualifier_list type_qualifier {$$ |= $1;}
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
    identifier
    | identifier_list ',' identifier
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

// typedef_name:
//     IDENT
//     ;

initializer:
    assignment_expression
    ;

%%
