/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 28 "parser.y" /* yacc.c:1909  */

    #include "declarations.h"
    #include "types.h"
    #include "ast.h"
    #include "symbol_table.h"

#line 51 "parser.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENT = 258,
    CHARLIT = 259,
    STRINGLIT = 260,
    NUMBERLIT = 261,
    INDSEL = 262,
    PLUSPLUS = 263,
    MINUSMINUS = 264,
    SHL = 265,
    SHR = 266,
    LTEQ = 267,
    GTEQ = 268,
    EQEQ = 269,
    NOTEQ = 270,
    LOGAND = 271,
    LOGOR = 272,
    ELLIPSIS = 273,
    TIMESEQ = 274,
    DIVEQ = 275,
    MODEQ = 276,
    PLUSEQ = 277,
    MINUSEQ = 278,
    SHLEQ = 279,
    SHREQ = 280,
    ANDEQ = 281,
    OREQ = 282,
    XOREQ = 283,
    AUTO = 284,
    ALIGNOF = 285,
    BREAK = 286,
    CASE = 287,
    CHAR = 288,
    CONST = 289,
    CONTINUE = 290,
    DEFAULT = 291,
    DO = 292,
    DOUBLE = 293,
    ELSE = 294,
    ENUM = 295,
    EXTERN = 296,
    FLOAT = 297,
    FOR = 298,
    GOTO = 299,
    IF = 300,
    INLINE = 301,
    INT = 302,
    LONG = 303,
    REGISTER = 304,
    RESTRICT = 305,
    RETURN = 306,
    SHORT = 307,
    SIGNED = 308,
    SIZEOF = 309,
    STATIC = 310,
    STRUCT = 311,
    SWITCH = 312,
    TYPEDEF = 313,
    UNION = 314,
    UNSIGNED = 315,
    VOID = 316,
    VOLATILE = 317,
    WHILE = 318,
    _BOOL = 319,
    _COMPLEX = 320,
    _IMAGINARY = 321
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 35 "parser.y" /* yacc.c:1909  */

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

#line 155 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
