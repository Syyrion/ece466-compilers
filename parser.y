%debug

%{
    // so much bread

    #include <stdlib.h>
    #include <stdio.h>
    #include "lexer.h"
    #include "location.h"
    #include "ast.h"
    #include "symbol_table.h"

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s:%d: %s\n", filename, line_num, s);
    }

    symbol_table_t *add_members_to_symbol_table(symbol_table_t *member_table, declaration_package_t declaration_package);
%}

%initial-action
{
    st_init();
}

%code requires{
    #include "declarations.h"
    #include "types.h"
    #include "ast.h"
    #include "symbol_table.h"
}

%union{
    int integer;

    string_t string;
    number_t number;

    type_specifier_t type_specifier;
    int type_qualifier;
    storage_class_specifier_t storage_class_specifier;
    function_specifier_t function_specifier;

    ast_node_t *node;
    ast_node_list_t *node_list;

    declaration_specifiers_t declaration_specifiers;
    declarator_helper_t declarator_helper;
    declaration_package_t declaration_package;

    symbol_table_t *symbol_table;
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
    <node_list> argument_expression_list
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
    <integer> assignment_operator
    <node> expression
    <node> constant_expression

    <node> initializer

    <declaration_specifiers> declaration_specifiers
    <storage_class_specifier> storage_class_specifier
    <function_specifier> function_specifier
    <type_qualifier> type_qualifier
    <type_specifier> type_specifier

    <declaration_package> init_declarator_list
    <declarator_helper> init_declarator
    <declarator_helper> declarator
    <declarator_helper> direct_declarator
    <declarator_helper> pointer

    <declarator_helper> abstract_declarator
    <declarator_helper> direct_abstract_declarator

    <symbol_table> struct_declaration_list
    <declaration_package> struct_declaration
    <declaration_package> struct_declarator_list
    <declaration_specifiers> specifier_qualifier_list
    <declarator_helper> struct_declarator

    <node_list> identifier_list

    <type_qualifier> type_qualifier_list
    <integer> struct_or_union
    <node> struct_or_union_specifier
    <node> enum_specifier

%destructor { } <number>
%destructor {free($$.buffer);} <string>
%destructor {ast_free($$);} <node>

%%
translation_unit:
    external_declaration
    | translation_unit external_declaration
    ;

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
    | '{' '}'
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
    expression ';' {ast_print_expression($1, 0);} // ! debug
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
    | postfix_expression '(' ')' {$$ = ast_new_function_call($1, ast_list_new());}
    | postfix_expression '(' argument_expression_list ')' {$$ = ast_new_function_call($1, $3);}
    | postfix_expression '.' identifier {$$ = ast_new_binary_op('.', $1, $3);}
    | postfix_expression "->" identifier {$$ = ast_new_binary_op('.', ast_new_unary_op('*', $1), $3);}
    | postfix_expression "++" {$$ = ast_new_unary_op(PLUSPLUS, $1);}
    | postfix_expression "--" {$$ = ast_new_unary_op(MINUSMINUS, $1);}
    ;

argument_expression_list:
    assignment_expression {$$ = ast_list_add(ast_list_new(), $1);}
    | argument_expression_list ',' assignment_expression {$$ = ast_list_add($1, $3);}
    ;

unary_expression:
    postfix_expression
    | "++" unary_expression {$$ = ast_new_binary_op(PLUSEQ, $2, ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
    | "--" unary_expression {$$ = ast_new_binary_op(MINUSEQ, $2, ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
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
    | '(' type_name ')' cast_expression
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
    '=' {$$ = '=';}
    | "*=" {$$ = PLUSEQ;}
    | "/=" {$$ = MINUSEQ;}
    | "%=" {$$ = TIMESEQ;}
    | "+=" {$$ = DIVEQ;}
    | "-=" {$$ = MODEQ;}
    | "<<=" {$$ = SHLEQ;}
    | ">>=" {$$ = SHREQ;}
    | "&=" {$$ = ANDEQ;}
    | "^=" {$$ = XOREQ;}
    | "|=" {$$ = OREQ;}
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
    {
        declspec_verify_scalar(&$1.type_specifier.scalar);

        if (!$1.storage_class)
        {
            if (st_is_at_root())
                $1.storage_class = SC_EXTERN;
            else
                $1.storage_class = SC_AUTO;
        }

        ast_node_t *end_scalar = ast_new_scalar($1.type_specifier, $1.type_qualifier);

        for (int i = 0; i < $2.declarator_count ; i++)
        {
            ast_node_t *var = ast_ident_to_variable($2.declarators[i].oldest, $1.storage_class);
            if (st_find(NS_VARIABLE, var->ident))
            {
                fprintf(stderr, "%s:%d: Error: variable `%s` has already been declared\n", filename, line_num, var->ident);
                exit(80);
            }
            st_add(NS_VARIABLE, var);
            $2.declarators[i].newest->next = end_scalar;

            // ! debug
            ast_print_variable(var);
        }
    }
    | declaration_specifiers ';' // if this is a struct without a name then it goes unused (should be freed probably)
    ;

declaration_specifiers:
    type_specifier {declspec_init(&$$); declspec_add_type_specifier(&$$, $1);}
    | type_qualifier {declspec_init(&$$); declspec_add_type_qualifier(&$$, $1);}
    | storage_class_specifier {declspec_init(&$$); declspec_add_storage_class(&$$, $1);}
    | function_specifier {declspec_init(&$$); declspec_add_function_specifier(&$$, $1);}
    | declaration_specifiers type_specifier {declspec_add_type_specifier(&$1, $2); $$ = $1;}
    | declaration_specifiers type_qualifier {declspec_add_type_qualifier(&$1, $2); $$ = $1;}
    | declaration_specifiers storage_class_specifier {declspec_add_storage_class(&$1, $2); $$ = $1;}
    | declaration_specifiers function_specifier {declspec_add_function_specifier(&$1, $2); $$ = $1;}
    ;

init_declarator_list:
    init_declarator {declpkg_init(&$$); declpkg_add_declarator(&$$, $1);}
    | init_declarator_list ',' init_declarator {declpkg_add_declarator(&$1, $3); $$ = $1;}
    ;

init_declarator:
    declarator {$1.initializer = 0; $$ = $1;}
    | declarator '=' initializer {$1.initializer = $3; $$ = $1;}
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
    VOID {$$ = (type_specifier_t){.scalar = TS_VOID};}
    | CHAR {$$ = (type_specifier_t){.scalar = TS_CHAR};}
    | SHORT {$$ = (type_specifier_t){.scalar = TS_SHORT};}
    | INT {$$ = (type_specifier_t){.scalar = TS_INT};}
    | LONG {$$ = (type_specifier_t){.scalar = TS_LONG};}
    | FLOAT {$$ = (type_specifier_t){.scalar = TS_FLOAT};}
    | DOUBLE {$$ = (type_specifier_t){.scalar = TS_DOUBLE};}
    | SIGNED {$$ = (type_specifier_t){.scalar = TS_SIGNED};}
    | UNSIGNED {$$ = (type_specifier_t){.scalar = TS_UNSIGNED};}
    | _BOOL {$$ = (type_specifier_t){.scalar = TS_BOOL};}
    | _COMPLEX {$$ = (type_specifier_t){.scalar = TS_COMPLEX};}
    | struct_or_union_specifier {$$ = (type_specifier_t){.scalar = TS_STRUCT_OR_UNION, .custom = $1};}
    | enum_specifier {$$ = (type_specifier_t){.scalar = TS_ENUM, .custom = $1};}
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
    struct_or_union '{' struct_declaration_list '}' {$$ = ast_new_struct_or_union($1, 0, st_unpack($3));}
    | struct_or_union IDENT '{'
        {
            // midrule action since the struct needs to be installed before we see the members
            ast_node_t *node = st_find(NS_STRUCT, $2.buffer); // check if a struct declaration already exists
            if (node)
            {
                if (node->kind == $1)
                {
                    if (node->members == 0)
                    {
                        $<node>$ = node; // put it on the stack
                    }
                    else
                    {
                        fprintf(stderr, "%s:%d: Error: `%s` is already complete\n", filename, line_num, $2.buffer);
                        exit(80);
                    }
                }
                else
                {
                    fprintf(stderr, "%s:%d: Error: a struct or union `%s` has already been declared\n", filename, line_num, $2.buffer);
                    exit(80);
                }
            }
            else
            {
                st_add(NS_STRUCT, $<node>$ = ast_new_struct_or_union($1, $2.buffer, 0));
            }
        }
        struct_declaration_list '}' {$$ = ast_add_struct_or_union_members($<node>4, st_unpack($5)); ast_print_struct_or_union($$);}
    | struct_or_union IDENT
        {
            ast_node_t *node = st_find(NS_STRUCT, $2.buffer); // check if a struct declaration already exists
            if (node)
            {
                $$ = node;
            }
            else
            {
                st_add(NS_STRUCT, $$ = ast_new_struct_or_union($1, $2.buffer, 0));
                ast_print_struct_or_union($$);
            }
        }
    ;

struct_or_union:
    STRUCT {$$ = AST_STRUCT;}
    | UNION {$$ = AST_UNION;}
    ;

struct_declaration_list:
    struct_declaration {$$ = add_members_to_symbol_table(st_new(0), $1);}
    | struct_declaration_list struct_declaration {$$ = add_members_to_symbol_table($1, $2);}
    ;

struct_declaration:
    specifier_qualifier_list struct_declarator_list ';'
        {declspec_verify_scalar(&$1.type_specifier.scalar); $2.declaration_specifiers = $1; $$ = $2;}
    ;

specifier_qualifier_list:
    type_specifier {declspec_init(&$$); declspec_add_type_specifier(&$$, $1);}
    | type_qualifier {declspec_init(&$$); declspec_add_type_qualifier(&$$, $1);}
    | specifier_qualifier_list type_specifier {declspec_add_type_specifier(&$1, $2); $$ = $1;}
    | specifier_qualifier_list type_qualifier {declspec_add_type_qualifier(&$1, $2); $$ = $1;}
    ;

struct_declarator_list:
    struct_declarator {declpkg_init(&$$); declpkg_add_declarator(&$$, $1);}
    | struct_declarator_list ',' struct_declarator {declpkg_add_declarator(&$1, $3); $$ = $1;}
    ;

struct_declarator:
    declarator {$1.bit_width = 0; $$ = $1;}
    | ':' constant_expression {$$ = (declarator_helper_t){.oldest = 0, .newest = 0, .bit_width = $2};}
    | declarator ':' constant_expression {$1.bit_width = $3; $$ = $1;}
    ;

// ## ENUMS

// TODO save for later
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
    direct_declarator {$$ = $1;}
    | pointer direct_declarator {$2.newest->next = $1.oldest; $$.oldest = $2.oldest; $$.newest = $1.newest;}
    ;

direct_declarator:
    identifier {$$.oldest = $$.newest = $1;}
    | '(' declarator ')' {$$ = $2;}
    | direct_declarator '[' ']' {$$.newest = $1.newest->next = ast_new_array(0); $$.oldest = $1.oldest;}
    | direct_declarator '[' assignment_expression ']' {$$.newest = $1.newest->next = ast_new_array($3); $$.oldest = $1.oldest;}
//  | direct_declarator '[' type_qualifier_list ']'
//  | direct_declarator '[' type_qualifier_list assignment_expression ']'
//  | direct_declarator '[' STATIC assignment_expression ']'
//  | direct_declarator '[' STATIC type_qualifier_list assignment_expression ']'
//  | direct_declarator '[' type_qualifier_list STATIC assignment_expression ']'
//  | direct_declarator '[' type_qualifier_list '*' ']'
//  | direct_declarator '[' '*' ']'
    | direct_declarator '(' parameter_type_list ')' {fprintf(stderr, "dd12\n");}
    | direct_declarator '(' identifier_list ')' {fprintf(stderr, "dd13\n");}
    | direct_declarator '(' ')' {fprintf(stderr, "dd14\n");}
    ;

pointer:
    '*' {$$.oldest = $$.newest = ast_new_pointer(0);}
    | '*' type_qualifier_list {$$.oldest = $$.newest = ast_new_pointer($2);}
    | '*' pointer {$$.newest = $2.newest->next = ast_new_pointer(0); $$.oldest = $2.oldest;}
    | '*' type_qualifier_list pointer {$$.newest = $3.newest->next = ast_new_pointer($2); $$.oldest = $3.oldest;}
    ;

type_qualifier_list:
    type_qualifier {$$ = $1;}
    | type_qualifier_list type_qualifier {$$ = $1 | $2;}
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
    identifier {$$ = ast_list_add(ast_list_new(), $1);}
    | identifier_list ',' identifier {$$ = ast_list_add($1, $3);}
    ;

type_name:
    specifier_qualifier_list
    | specifier_qualifier_list abstract_declarator
    ;

abstract_declarator:
    pointer {$$ = $1;}
    | direct_abstract_declarator {$$ = $1;}
    | pointer direct_abstract_declarator {$2.newest->next = $1.oldest; $$.oldest = $2.oldest; $$.newest = $1.newest;}
    ;

direct_abstract_declarator:
    '(' abstract_declarator ')' {$$ = $2;}
    | '[' ']' {$$.oldest = $$.newest = ast_new_array(0);}
    | '[' assignment_expression ']' {$$.oldest = $$.newest = ast_new_array($2);}
    | direct_abstract_declarator '[' ']' {$$.newest = $1.newest->next = ast_new_array(0); $$.oldest = $1.oldest;}
    | direct_abstract_declarator '[' assignment_expression ']' {$$.newest = $1.newest->next = ast_new_array($3); $$.oldest = $1.oldest;}
//  | '[' '*' ']'
//  | direct_abstract_declarator '[' '*' ']'
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


// for structs and unions only
symbol_table_t *add_members_to_symbol_table(symbol_table_t *member_table, declaration_package_t declaration_package)
{
    ast_node_t *end_scalar = ast_new_scalar(
        declaration_package.declaration_specifiers.type_specifier,
        declaration_package.declaration_specifiers.type_qualifier);

    unsigned short is_custom = end_scalar->scalar.full & TS_CUSTOM;

    for (int i = 0; i < declaration_package.declarator_count; i++)
    {
        declarator_helper_t *declarator = &(declaration_package.declarators[i]);
        if (!declarator->oldest)
        {
            // padding bit field
            st_add(member_table, ast_new_padding_member(declarator->bit_width));
        }
        else
        {
            ast_node_t *member = ast_ident_to_member(declarator->oldest, declarator->bit_width);

            if (
                is_custom                                   // scalar is a struct or union
                && declarator->newest == declarator->oldest // not a pointer, array, or function
                && end_scalar->next->members == 0           // no members
            )
            {
                fprintf(stderr, "%s:%d: Error: member `%s` is incomplete\n", filename, line_num, member->ident);
                exit(81);
            }

            if (declarator->oldest->next && declarator->oldest->next->kind == AST_ARRAY && declarator->oldest->next->array_size == 0)
            {
                fprintf(stderr, "%s:%d: Error: member `%s` cannot be an array of unknown size\n", filename, line_num, member->ident);
                exit(81);
            }

            declarator->newest->next = end_scalar;

            if (st_find(member_table, member->ident))
            {
                fprintf(stderr, "%s:%d: Error: member `%s` has already been declared\n", filename, line_num, member->ident);
                exit(80);
            }

            st_add(member_table, member);
        }
    }

    return member_table;
}