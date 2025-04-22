/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
#line 28 "parser.y"

    #include "declarations.h"
    #include "types.h"
    #include "ast.h"
    #include "symbol_table.h"

#line 56 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENT = 258,                   /* IDENT  */
    CHARLIT = 259,                 /* CHARLIT  */
    STRINGLIT = 260,               /* STRINGLIT  */
    NUMBERLIT = 261,               /* NUMBERLIT  */
    INDSEL = 262,                  /* "->"  */
    PLUSPLUS = 263,                /* "++"  */
    MINUSMINUS = 264,              /* "--"  */
    SHL = 265,                     /* "<<"  */
    SHR = 266,                     /* ">>"  */
    LTEQ = 267,                    /* "<="  */
    GTEQ = 268,                    /* ">="  */
    EQEQ = 269,                    /* "=="  */
    NOTEQ = 270,                   /* "!="  */
    LOGAND = 271,                  /* "&&"  */
    LOGOR = 272,                   /* "||"  */
    ELLIPSIS = 273,                /* "..."  */
    TIMESEQ = 274,                 /* "*="  */
    DIVEQ = 275,                   /* "/="  */
    MODEQ = 276,                   /* "%="  */
    PLUSEQ = 277,                  /* "+="  */
    MINUSEQ = 278,                 /* "-="  */
    SHLEQ = 279,                   /* "<<="  */
    SHREQ = 280,                   /* ">>="  */
    ANDEQ = 281,                   /* "&="  */
    OREQ = 282,                    /* "|="  */
    XOREQ = 283,                   /* "^="  */
    AUTO = 284,                    /* AUTO  */
    ALIGNOF = 285,                 /* ALIGNOF  */
    BREAK = 286,                   /* BREAK  */
    CASE = 287,                    /* CASE  */
    CHAR = 288,                    /* CHAR  */
    CONST = 289,                   /* CONST  */
    CONTINUE = 290,                /* CONTINUE  */
    DEFAULT = 291,                 /* DEFAULT  */
    DO = 292,                      /* DO  */
    DOUBLE = 293,                  /* DOUBLE  */
    ELSE = 294,                    /* ELSE  */
    ENUM = 295,                    /* ENUM  */
    EXTERN = 296,                  /* EXTERN  */
    FLOAT = 297,                   /* FLOAT  */
    FOR = 298,                     /* FOR  */
    GOTO = 299,                    /* GOTO  */
    IF = 300,                      /* IF  */
    INLINE = 301,                  /* INLINE  */
    INT = 302,                     /* INT  */
    LONG = 303,                    /* LONG  */
    REGISTER = 304,                /* REGISTER  */
    RESTRICT = 305,                /* RESTRICT  */
    RETURN = 306,                  /* RETURN  */
    SHORT = 307,                   /* SHORT  */
    SIGNED = 308,                  /* SIGNED  */
    SIZEOF = 309,                  /* SIZEOF  */
    STATIC = 310,                  /* STATIC  */
    STRUCT = 311,                  /* STRUCT  */
    SWITCH = 312,                  /* SWITCH  */
    TYPEDEF = 313,                 /* TYPEDEF  */
    UNION = 314,                   /* UNION  */
    UNSIGNED = 315,                /* UNSIGNED  */
    VOID = 316,                    /* VOID  */
    VOLATILE = 317,                /* VOLATILE  */
    WHILE = 318,                   /* WHILE  */
    _BOOL = 319,                   /* _BOOL  */
    _COMPLEX = 320,                /* _COMPLEX  */
    _IMAGINARY = 321               /* _IMAGINARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "parser.y"

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

#line 164 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
