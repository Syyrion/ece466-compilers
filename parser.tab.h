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
#line 16 "parser.y"

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

#line 67 "parser.tab.h"

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
    BREAK = 285,                   /* BREAK  */
    CASE = 286,                    /* CASE  */
    CHAR = 287,                    /* CHAR  */
    CONST = 288,                   /* CONST  */
    CONTINUE = 289,                /* CONTINUE  */
    DEFAULT = 290,                 /* DEFAULT  */
    DO = 291,                      /* DO  */
    DOUBLE = 292,                  /* DOUBLE  */
    ELSE = 293,                    /* ELSE  */
    ENUM = 294,                    /* ENUM  */
    EXTERN = 295,                  /* EXTERN  */
    FLOAT = 296,                   /* FLOAT  */
    FOR = 297,                     /* FOR  */
    GOTO = 298,                    /* GOTO  */
    IF = 299,                      /* IF  */
    INLINE = 300,                  /* INLINE  */
    INT = 301,                     /* INT  */
    LONG = 302,                    /* LONG  */
    REGISTER = 303,                /* REGISTER  */
    RESTRICT = 304,                /* RESTRICT  */
    RETURN = 305,                  /* RETURN  */
    SHORT = 306,                   /* SHORT  */
    SIGNED = 307,                  /* SIGNED  */
    SIZEOF = 308,                  /* SIZEOF  */
    STATIC = 309,                  /* STATIC  */
    STRUCT = 310,                  /* STRUCT  */
    SWITCH = 311,                  /* SWITCH  */
    TYPEDEF = 312,                 /* TYPEDEF  */
    UNION = 313,                   /* UNION  */
    UNSIGNED = 314,                /* UNSIGNED  */
    VOID = 315,                    /* VOID  */
    VOLATILE = 316,                /* VOLATILE  */
    WHILE = 317,                   /* WHILE  */
    _BOOL = 318,                   /* _BOOL  */
    _COMPLEX = 319,                /* _COMPLEX  */
    _IMAGINARY = 320               /* _IMAGINARY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 34 "parser.y"

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

#line 169 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
