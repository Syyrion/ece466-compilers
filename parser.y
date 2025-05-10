%debug

%{
    // * probably full of memory leaks *

    #include <stdlib.h>
    #include <stdio.h>
    #include "lexer.h"
    #include "location.h"
    #include "ast.h"
    #include "symbol_table.h"
    #include "jump_association.h"
    #include "quad.h"

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s:%d: %s\n", filename, line_num, s);
    }

    symbol_table_t *add_members_to_symbol_table(symbol_table_t *member_table, declaration_package_t declaration_package);
%}

%initial-action
{
    st_init();
    ast_init();
}

%code requires{
    #include "literal.h"
    #include "ast.h"
    #include "declarations.h"
    #include "symbol_table.h"
}

%union{
    // generic integer
    int integer;

    // literal values
    string_t string;
    number_t number;

    // ast objects
    ast_node_t *node;
    ast_node_list_t *node_list;

    // decl spec categories
    type_specifier_t type_specifier;
    int type_qualifier;
    storage_class_specifier_t storage_class_specifier;
    function_specifier_t function_specifier;

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

%left IF
%left ELSE

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

//  <node> initializer

    <declaration_specifiers> declaration_specifiers
    <storage_class_specifier> storage_class_specifier
    <function_specifier> function_specifier
    <type_qualifier> type_qualifier
    <type_specifier> type_specifier

    <declaration_package> declaration
    <declaration_package> init_declarator_list
    <declarator_helper> init_declarator
    <declarator_helper> declarator
    <declarator_helper> direct_declarator
    <declarator_helper> pointer

    <node> type_name
    <declarator_helper> abstract_declarator
    <declarator_helper> direct_abstract_declarator

    <symbol_table> struct_declaration_list
    <declaration_package> struct_declaration
    <declaration_package> struct_declarator_list
    <declaration_specifiers> specifier_qualifier_list
    <declarator_helper> struct_declarator

    <symbol_table> identifier_list
    <symbol_table> parameter_type_list
    <symbol_table> parameter_list
    <node> parameter_declaration

    <type_qualifier> type_qualifier_list
    <integer> struct_or_union
    <node> struct_or_union_specifier
    // <node> enum_specifier

    <node> optional_expression

    <node> statement
    <node> compound_statement
    <node> expression_statement
    <node> selection_statement
    <node> iteration_statement
    <node> jump_statement
    // <node> labeled_statement

%%
translation_unit:
    external_declaration
    | translation_unit external_declaration
    ;

external_declaration:
    function_definition
    | declaration
    {
        // alias for declaration specs
        declaration_specifiers_t *ds = &$1.declaration_specifiers;

        // apply extern if needed since this is an external declaration
        if (!ds->storage_class)
            ds->storage_class = SC_EXTERN;

        ast_node_t *type = ast_new_type(ds->type_specifier, ds->type_qualifier);

        for (int i = 0; i < $1.declarator_count ; i++)
        {
            ast_node_t *var = ast_ident_to_variable($1.declarators[i].oldest, ds->storage_class);
            $1.declarators[i].newest->next = type;

            ast_node_t *other = st_find_local(NS_VARIABLE, var->variable.name);


            if (other)
            {
                if (ast_are_variables_compatible(other, var))
                {
                    ast_merge_into_variable(other, var);
                    var = other;
                }
                else
                {
                    fprintf(stderr, "%s:%d: Error: conflicting type on already existing variable `%s`\n", filename, line_num, other->name);
                    exit(EXIT_FAILURE);
                }
            }
            else
                st_add(NS_VARIABLE, var);

            // ! debug
            printf("EXTERNAL DECLARATION: ");
            ast_print_variable(var, 0);
            printf("\n");
        }
    }
    ;

function_definition:
    declaration_specifiers declarator
    {
        if (!$1.storage_class)
            $1.storage_class = SC_EXTERN;

        ast_node_t *type = ast_new_type($1.type_specifier, $1.type_qualifier);
        ast_node_t *fn = ast_ident_to_variable($2.oldest, $1.storage_class);
        $2.newest->next = type;

        if (fn->next->kind != AST_FUNCTION)
        {
            fprintf(stderr, "%s:%d: Error: expected a ';'\n");
            exit(EXIT_FAILURE);
        }

        ast_node_t *other = st_find_local(NS_VARIABLE, fn->variable.name);

        if (other)
        {
            if (ast_are_variables_compatible(other, fn))
            {
                ast_merge_into_variable(other, fn);
                fn = other;
            }
            else
            {
                fprintf(stderr, "%s:%d: Error: conflicting type on already existing variable `%s`\n", filename, line_num, other->name);
                exit(EXIT_FAILURE);
            }
        }
        else
            st_add(NS_VARIABLE, fn);

        // push a new scope
        st_push();
        
        // add parameters as variables in the new scope
        if (fn->next->function.parameters)
        {
            ENUMERATE(fn->next->function.parameters, i, {
                // * mark the parameters as used or else they'll get thrown away after the compound statement
                fn->next->function.parameters->items[i]->variable.used = 1;
                st_add(NS_VARIABLE, fn->next->function.parameters->items[i]);
            });
        }

        $<node>$ = fn;
    }
    compound_statement
    {
        $<node>3->next->function.definition = $4;
        // ! debug
        printf("FUNCTION DEFINITION: ");
        ast_print_variable($<node>3, 0);
        ast_print_statement($4, 0);
        printf("\n");
        print_basic_block_list(generate_function_quads($4));

    }
    // TODO this is just a copy of above for now. It also needs to be fixed.
/*
    | declaration_specifiers declarator declaration_list
    {
        if (!$1.storage_class)
            $1.storage_class = SC_EXTERN;

        ast_node_t *type = ast_new_type($1.type_specifier, $1.type_qualifier);
        ast_node_t *fn = ast_ident_to_variable($2.oldest, $1.storage_class);
        $2.newest->next = type;

        if (fn->next->kind != AST_FUNCTION)
        {
            fprintf(stderr, "%s:%d: Error: expected a ';'\n");
            exit(EXIT_FAILURE);
        }

        ast_node_t *other = st_find_local(NS_VARIABLE, fn->variable.name);

        if (other)
        {
            if (ast_are_variables_compatible(other, fn))
            {
                ast_merge_into_variable(other, fn);
                fn = other;
            }
            else
            {
                fprintf(stderr, "%s:%d: Error: conflicting type on already existing variable `%s`\n", filename, line_num, other->name);
                exit(EXIT_FAILURE);
            }
        }
        else
            st_add(NS_VARIABLE, fn);

        st_push();

        for (int i = 0; i < fn->next->function.parameters->node_count; i++)
            st_add(NS_VARIABLE, fn->next->function.parameters->nodes[i]);

        $<node>$ = fn;
    }
    compound_statement
    {
        $<node>3->next->function.definition = (function_definition_t){.namespaces = st_pop();}
        // ! debug
        printf("FUNCTION DEFINITION (2): ");
        ast_print_variable($<node>4, 0);
    }
    ;

declaration_list:
    declaration
    | declaration_list declaration
    ;
*/

block_item_list:
    block_item
    | block_item_list block_item
    ;

block_item:
    declaration
    {
        // alias for declaration specs
        declaration_specifiers_t *ds = &$1.declaration_specifiers;

        // apply auto if needed
        if (!ds->storage_class)
            ds->storage_class = SC_AUTO;

        ast_node_t *type = ast_new_type(ds->type_specifier, ds->type_qualifier);

        for (int i = 0; i < $1.declarator_count ; i++)
        {
            ast_node_t *var = ast_ident_to_variable($1.declarators[i].oldest, ds->storage_class);
            $1.declarators[i].newest->next = type;

            ast_node_t *other = st_find_local(NS_VARIABLE, var->variable.name);

            if (other)
            {
                if (ast_are_variables_compatible(other, var))
                {
                    ast_merge_into_variable(other, var);
                    var = other;
                }
                else
                {
                    fprintf(stderr, "%s:%d: Error: conflicting type on already existing variable `%s`\n", filename, line_num, other->name);
                    exit(EXIT_FAILURE);
                }
            }
            else
                st_add(NS_VARIABLE, var);

            // ! debug
            printf("DECLARATION: ");
            ast_print_variable(var, 0);
        }
    }
    | statement {st_add_statement($1);}
    ;

// ## STATEMENTS
    statement:
        {st_push();} compound_statement {$$ = $2;}
        | expression_statement 
        | selection_statement
        | iteration_statement
        | jump_statement
//      | labeled_statement
        ;

    compound_statement:
        '{' optional_block_item_list '}' {$$ = st_pop();}
        ;
    
    optional_block_item_list:
        block_item_list
        | %empty
        ;

    expression_statement:
        expression ';' {ast_resolve_expression_variables(&$1, 0); $$ = ast_new_expression_statement($1);}
        | ';' {$$ = ast_new_expression_statement(0);}
        ;

    selection_statement:
        IF '(' expression ')' statement
        {
            ast_resolve_expression_variables(&$3, 0);
            $$ = ast_new_if_statement($3, $5, 0);
        } %prec IF
        | IF '(' expression ')' statement ELSE statement
        {
            ast_resolve_expression_variables(&$3, 0);
            $$ = ast_new_if_statement($3, $5, $7);
        } %prec ELSE
//      | SWITCH '(' expression ')' statement
        ;

    iteration_statement:
        WHILE '(' expression ')'
        {
            ast_resolve_expression_variables(&$3, 0);
            ja_push($<node>$ = ast_new_while_statement(AST_WHILE, $3, 0));
        }
        statement
        {
            ja_pop();
            $<node>5->while_statement.statement = $6;
            $$ = $<node>5;
        }
        | DO
        {
            ja_push($<node>$ = ast_new_while_statement(AST_DO_WHILE, 0, 0));
        }
        statement WHILE '(' expression ')' ';'
        {
            ast_resolve_expression_variables(&$6, 0);
            ja_pop();
            $<node>2->while_statement.condition = $6;
            $<node>2->while_statement.statement = $3;
            $$ = $<node>2;
        }
        | FOR '(' optional_expression ';' optional_expression ';' optional_expression ')'
        {
            if ($3)
                ast_resolve_expression_variables(&$3, 0);
            if ($5)
                ast_resolve_expression_variables(&$5, 0);
            if ($7)
                ast_resolve_expression_variables(&$7, 0);
            ja_push($<node>$ = ast_new_for_statement($3, $5, $7, 0));
        }
        statement
        {
            ja_pop();
            $<node>9->for_statement.statement = $10;
            $$ = $<node>9;
        }
        // not going to allow declarations in the first for clause
        ;

    optional_expression:
        expression {$$ = $1;}
        | %empty {$$ = 0;}
        ;

    jump_statement:
        CONTINUE ';' {$$ = ast_new_continue_statement(ja_get_continue_association());}
        | BREAK ';' {$$ = ast_new_break_statement(ja_get_break_association());}
        | RETURN optional_expression ';' {    
            if ($2)
                ast_resolve_expression_variables(&$2, 0);
            $$ = ast_new_return_statement($2);
        }
//      | GOTO IDENT ';' {$$ = ast_new_goto_statement($2.buffer);}
        ;

//  labeled_statement:
//      IDENT ':' statement {st_add_label($1.buffer, $3); $$ = $3;}
//      | CASE constant_expression ':' statement
//      | DEFAULT ':' statement
        ;

//

// ## EXPRESSIONS
    identifier:
        IDENT {$$ = ast_new_ident($1.buffer);}
        ;

    string_literal:
        STRINGLIT {$$ = ast_new_stringlit($1);}
        ;

    constant:
        CHARLIT {$$ = ast_new_charlit($1.buffer[0]); free($1.buffer);}
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
        | postfix_expression '(' ')' {$$ = ast_new_function_call($1, ast_node_list_new());}
        | postfix_expression '(' argument_expression_list ')' {$$ = ast_new_function_call($1, $3);}
        | postfix_expression '.' IDENT {$$ = ast_new_member_access($1, $3.buffer);}
        | postfix_expression "->" IDENT {$$ = ast_new_member_access(ast_new_unary_op('*', $1), $3.buffer);}
        | postfix_expression "++" {$$ = ast_new_unary_op(PLUSPLUS, $1);}
        | postfix_expression "--" {$$ = ast_new_unary_op(MINUSMINUS, $1);}
        ;

    argument_expression_list:
        assignment_expression {$$ = ast_node_list_add(ast_node_list_new(), $1);}
        | argument_expression_list ',' assignment_expression {$$ = ast_node_list_add($1, $3);}
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
        | SIZEOF '(' type_name ')' {$$ = ast_new_unary_op(SIZEOF, $3);}
        | ALIGNOF unary_expression {$$ = ast_new_unary_op(ALIGNOF, $2);}
        ;

    cast_expression:
        unary_expression
        | '(' type_name ')' cast_expression {$$ = ast_new_type_cast($4, $2);}
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
        | "+=" {$$ = PLUSEQ;}
        | "-=" {$$ = MINUSEQ;}
        | "*=" {$$ = TIMESEQ;}
        | "/=" {$$ = DIVEQ;}
        | "%=" {$$ = MODEQ;}
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
//

// ## DECLARATIONS
// man, they really messed this standard up

declaration:
    declaration_specifiers init_declarator_list ';'
    {
        $1.type_specifier.scalar = declspec_normalize_scalar($1.type_specifier.scalar);
        $2.declaration_specifiers = $1;
        $$ = $2;
    }
    | declaration_specifiers ';' // TODO if this is a struct without a name then it goes unused (should be freed probably)
    ;


    // ## DECLARATION SPECIFIERS
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
            // | enum_specifier {$$ = (type_specifier_t){.scalar = TS_ENUM, .custom = $1};}
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
    //

init_declarator_list:
    init_declarator {declpkg_init(&$$); declpkg_add_declarator(&$$, $1);}
    | init_declarator_list ',' init_declarator {declpkg_add_declarator(&$1, $3); $$ = $1;}
    ;

init_declarator:
    declarator {$1.initializer = 0; $$ = $1;}
//  | declarator '=' initializer {$1.initializer = $3; $$ = $1;}
    ;

declarator:
    direct_declarator {$$ = $1;}
    | pointer direct_declarator {$2.newest->next = $1.oldest; $$.oldest = $2.oldest; $$.newest = $1.newest;}
    ;

direct_declarator:
    identifier {$$.oldest = $$.newest = $1;}
    | '(' declarator ')' {$$ = $2;}
    | direct_declarator '[' ']' {$$.newest = $1.newest->next = ast_new_array(0); $$.oldest = $1.oldest;}
    | direct_declarator '[' constant_expression ']' {$$.newest = $1.newest->next = ast_new_array($3); $$.oldest = $1.oldest;}
    | direct_declarator '(' ')' {$$.newest = $1.newest->next = ast_new_function(0); $$.oldest = $1.oldest;}
// TODO K&R not supported yet
    | direct_declarator '(' identifier_list ')' {$$.newest = $1.newest->next = ast_new_function(st_unpack($3)); $$.oldest = $1.oldest;}
    | direct_declarator '(' parameter_type_list ')' {$$.newest = $1.newest->next = ast_new_function(st_unpack($3)); $$.oldest = $1.oldest;}
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

// TODO function declarations like f(void)
parameter_type_list:
    parameter_list {$$ = $1;}
//  | parameter_list ',' "..."
    ;

parameter_list:
    parameter_declaration {$$ = st_add(st_new(0), $1);}
    | parameter_list ',' parameter_declaration
    {
        if ($3->name && st_find_local($1, $3->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, $3->name);
            exit(EXIT_FAILURE);
        }
        $$ = st_add($1, $3);
    }
    ;

parameter_declaration:
    declaration_specifiers declarator
    {
        $1.storage_class = declspec_normalize_parameter_storage_class($1.storage_class);

        ast_node_t *var = ast_ident_to_variable($2.oldest, $1.storage_class);
        $2.newest->next = ast_new_type($1.type_specifier, $1.type_qualifier);
        $$ = var;
    }
    | declaration_specifiers {
        $1.storage_class = declspec_normalize_parameter_storage_class($1.storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), $1.storage_class);
        var->next = ast_new_type($1.type_specifier, $1.type_qualifier);
        $$ = var;
    }
    | declaration_specifiers abstract_declarator
    {
        $1.storage_class = declspec_normalize_parameter_storage_class($1.storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), $1.storage_class);
        var->next = $2.oldest;
        $2.newest->next = ast_new_type($1.type_specifier, $1.type_qualifier);
        $$ = var;
    }
    ;

identifier_list:
    identifier {$$ = st_add(st_new(0), $1);}
    | identifier_list ',' identifier
    {
        if (st_find_local($1, $3->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, $3->name);
            exit(EXIT_FAILURE);
        }
        $$ = st_add($1, $3);
    }
    ;

type_name:
    specifier_qualifier_list {
        ast_node_t *tn = ast_ident_to_variable(ast_new_ident(0), 0);
        tn->next = ast_new_type($1.type_specifier, $1.type_qualifier);
        $$ = tn;
    }
    | specifier_qualifier_list abstract_declarator
    {
        $2.newest->next = ast_new_type($1.type_specifier, $1.type_qualifier);
        ast_node_t *tn = ast_ident_to_variable(ast_new_ident(0), 0);
        tn->next = $2.oldest;
        $$ = tn;
    }
    ;

abstract_declarator:
    pointer {$$ = $1;}
    | direct_abstract_declarator {$$ = $1;}
    | pointer direct_abstract_declarator {$2.newest->next = $1.oldest; $$.oldest = $2.oldest; $$.newest = $1.newest;}
    ;

direct_abstract_declarator:
    '(' abstract_declarator ')' {$$ = $2;}
    | '[' ']' {$$.oldest = $$.newest = ast_new_array(0);}
    | '[' constant_expression ']' {$$.oldest = $$.newest = ast_new_array($2);}
    | direct_abstract_declarator '[' ']' {$$.newest = $1.newest->next = ast_new_array(0); $$.oldest = $1.oldest;}
    | direct_abstract_declarator '[' constant_expression ']' {$$.newest = $1.newest->next = ast_new_array($3); $$.oldest = $1.oldest;}
    | '(' ')' {$$.oldest = $$.newest = ast_new_function(0);}
    | direct_abstract_declarator '(' ')' {$$.newest = $1.newest->next = ast_new_function(0); $$.oldest = $1.oldest;}
    | '(' parameter_type_list ')' {$$.oldest = $$.newest = ast_new_function(st_unpack($2));}
    | direct_abstract_declarator '(' parameter_type_list ')' {$$.newest = $1.newest->next = ast_new_function(st_unpack($3)); $$.oldest = $1.oldest;}
    ;

// typedef_name:
//     IDENT
//     ;

// initializer:
//     assignment_expression
//     ;

// ## STRUCTS AND UNIONS
    struct_or_union_specifier:
        struct_or_union '{' struct_declaration_list '}' {$$ = ast_new_struct_or_union($1, 0, st_unpack($3));}
        | struct_or_union IDENT '{'
            {
                // midrule action since the struct needs to be installed before we see the members
                ast_node_t *node = st_find_local(NS_STRUCT, $2.buffer); // check if a struct declaration already exists
                if (node)
                {
                    if (node->kind == $1)
                    {
                        if (node->structure.members == 0)
                        {
                            $<node>$ = node; // put it on the stack
                        }
                        else
                        {
                            fprintf(stderr, "%s:%d: Error: `%s` is already complete\n", filename, line_num, $2.buffer);
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {
                        fprintf(stderr, "%s:%d: Error: a struct or union `%s` has already been declared\n", filename, line_num, $2.buffer);
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    st_add(NS_STRUCT, $<node>$ = ast_new_struct_or_union($1, $2.buffer, 0));
                }
            }
            struct_declaration_list '}'
            {
                $$ = ast_add_struct_or_union_members($<node>4, st_unpack($5));
                ast_print_struct_or_union($$); // ! debug
            }
        | struct_or_union IDENT
            {
                ast_node_t *node = st_find_local(NS_STRUCT, $2.buffer); // check if a struct declaration already exists
                if (node)
                {
                    $$ = node;
                }
                else
                {
                    st_add(NS_STRUCT, $$ = ast_new_struct_or_union($1, $2.buffer, 0));
                    ast_print_struct_or_union($$); // ! debug
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
        {
            $1.type_specifier.scalar = declspec_normalize_scalar($1.type_specifier.scalar);
            $2.declaration_specifiers = $1;
            $$ = $2;
        }
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
//

// ## ENUMS
    // TODO save for later
    /*
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
    */
//

%%

// for structs and unions only
symbol_table_t *add_members_to_symbol_table(symbol_table_t *member_table, declaration_package_t declaration_package)
{
    ast_node_t *type = ast_new_type(
        declaration_package.declaration_specifiers.type_specifier,
        declaration_package.declaration_specifiers.type_qualifier);

    unsigned short is_custom = type->type.specifier.scalar.full & TS_CUSTOM;

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
                is_custom                                               // scalar is a struct or union
                && declarator->newest == declarator->oldest             // not a pointer, array, or function
                && type->type.specifier.custom->structure.members == 0  // no members
            )
            {
                fprintf(stderr, "%s:%d: Error: member `%s` is incomplete\n", filename, line_num, member->name);
                exit(EXIT_FAILURE);
            }

            if (declarator->oldest->next && declarator->oldest->next->kind == AST_ARRAY && declarator->oldest->next->array.size == 0)
            {
                fprintf(stderr, "%s:%d: Error: member `%s` cannot be an array of unknown size\n", filename, line_num, member->name);
                exit(EXIT_FAILURE);
            }

            declarator->newest->next = type;

            if (st_find_local(member_table, member->name))
            {
                fprintf(stderr, "%s:%d: Error: member `%s` has already been declared\n", filename, line_num, member->name);
                exit(EXIT_FAILURE);
            }

            st_add(member_table, member);
        }
    }

    return member_table;
}
