/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 3 "parser.y"

    // * definitly full of memory leaks *

    #include <stdlib.h>
    #include <stdio.h>
    #include "lexer.h"
    #include "location.h"
    #include "ast.h"
    #include "symbol_table.h"
    #include "jump_association.h"
    #include "errorf.h"
    #include "quad.h"
    #include "backend.h"

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s:%d: %s\n", filename, line_num, s);
    }

    symbol_table_t *add_members_to_symbol_table(symbol_table_t *member_table, declaration_package_t declaration_package);

#line 93 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENT = 3,                      /* IDENT  */
  YYSYMBOL_CHARLIT = 4,                    /* CHARLIT  */
  YYSYMBOL_STRINGLIT = 5,                  /* STRINGLIT  */
  YYSYMBOL_NUMBERLIT = 6,                  /* NUMBERLIT  */
  YYSYMBOL_INDSEL = 7,                     /* "->"  */
  YYSYMBOL_PLUSPLUS = 8,                   /* "++"  */
  YYSYMBOL_MINUSMINUS = 9,                 /* "--"  */
  YYSYMBOL_SHL = 10,                       /* "<<"  */
  YYSYMBOL_SHR = 11,                       /* ">>"  */
  YYSYMBOL_LTEQ = 12,                      /* "<="  */
  YYSYMBOL_GTEQ = 13,                      /* ">="  */
  YYSYMBOL_EQEQ = 14,                      /* "=="  */
  YYSYMBOL_NOTEQ = 15,                     /* "!="  */
  YYSYMBOL_LOGAND = 16,                    /* "&&"  */
  YYSYMBOL_LOGOR = 17,                     /* "||"  */
  YYSYMBOL_ELLIPSIS = 18,                  /* "..."  */
  YYSYMBOL_TIMESEQ = 19,                   /* "*="  */
  YYSYMBOL_DIVEQ = 20,                     /* "/="  */
  YYSYMBOL_MODEQ = 21,                     /* "%="  */
  YYSYMBOL_PLUSEQ = 22,                    /* "+="  */
  YYSYMBOL_MINUSEQ = 23,                   /* "-="  */
  YYSYMBOL_SHLEQ = 24,                     /* "<<="  */
  YYSYMBOL_SHREQ = 25,                     /* ">>="  */
  YYSYMBOL_ANDEQ = 26,                     /* "&="  */
  YYSYMBOL_OREQ = 27,                      /* "|="  */
  YYSYMBOL_XOREQ = 28,                     /* "^="  */
  YYSYMBOL_AUTO = 29,                      /* AUTO  */
  YYSYMBOL_ALIGNOF = 30,                   /* ALIGNOF  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_CASE = 32,                      /* CASE  */
  YYSYMBOL_CHAR = 33,                      /* CHAR  */
  YYSYMBOL_CONST = 34,                     /* CONST  */
  YYSYMBOL_CONTINUE = 35,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 36,                   /* DEFAULT  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_DOUBLE = 38,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_ENUM = 40,                      /* ENUM  */
  YYSYMBOL_EXTERN = 41,                    /* EXTERN  */
  YYSYMBOL_FLOAT = 42,                     /* FLOAT  */
  YYSYMBOL_FOR = 43,                       /* FOR  */
  YYSYMBOL_GOTO = 44,                      /* GOTO  */
  YYSYMBOL_IF = 45,                        /* IF  */
  YYSYMBOL_INLINE = 46,                    /* INLINE  */
  YYSYMBOL_INT = 47,                       /* INT  */
  YYSYMBOL_LONG = 48,                      /* LONG  */
  YYSYMBOL_REGISTER = 49,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 50,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 51,                    /* RETURN  */
  YYSYMBOL_SHORT = 52,                     /* SHORT  */
  YYSYMBOL_SIGNED = 53,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 54,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 55,                    /* STATIC  */
  YYSYMBOL_STRUCT = 56,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 57,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 58,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 59,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 60,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 61,                      /* VOID  */
  YYSYMBOL_VOLATILE = 62,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 63,                     /* WHILE  */
  YYSYMBOL__BOOL = 64,                     /* _BOOL  */
  YYSYMBOL__COMPLEX = 65,                  /* _COMPLEX  */
  YYSYMBOL__IMAGINARY = 66,                /* _IMAGINARY  */
  YYSYMBOL_67_ = 67,                       /* '{'  */
  YYSYMBOL_68_ = 68,                       /* '}'  */
  YYSYMBOL_69_ = 69,                       /* ';'  */
  YYSYMBOL_70_ = 70,                       /* '('  */
  YYSYMBOL_71_ = 71,                       /* ')'  */
  YYSYMBOL_72_ = 72,                       /* '['  */
  YYSYMBOL_73_ = 73,                       /* ']'  */
  YYSYMBOL_74_ = 74,                       /* ','  */
  YYSYMBOL_75_ = 75,                       /* '&'  */
  YYSYMBOL_76_ = 76,                       /* '*'  */
  YYSYMBOL_77_ = 77,                       /* '+'  */
  YYSYMBOL_78_ = 78,                       /* '-'  */
  YYSYMBOL_79_ = 79,                       /* '~'  */
  YYSYMBOL_80_ = 80,                       /* '!'  */
  YYSYMBOL_81_ = 81,                       /* '/'  */
  YYSYMBOL_82_ = 82,                       /* '%'  */
  YYSYMBOL_83_ = 83,                       /* '<'  */
  YYSYMBOL_84_ = 84,                       /* '>'  */
  YYSYMBOL_85_ = 85,                       /* '^'  */
  YYSYMBOL_86_ = 86,                       /* '|'  */
  YYSYMBOL_87_ = 87,                       /* '?'  */
  YYSYMBOL_88_ = 88,                       /* ':'  */
  YYSYMBOL_89_ = 89,                       /* '='  */
  YYSYMBOL_YYACCEPT = 90,                  /* $accept  */
  YYSYMBOL_translation_unit = 91,          /* translation_unit  */
  YYSYMBOL_external_declaration = 92,      /* external_declaration  */
  YYSYMBOL_function_definition = 93,       /* function_definition  */
  YYSYMBOL_94_1 = 94,                      /* @1  */
  YYSYMBOL_block_item_list = 95,           /* block_item_list  */
  YYSYMBOL_block_item = 96,                /* block_item  */
  YYSYMBOL_statement = 97,                 /* statement  */
  YYSYMBOL_98_2 = 98,                      /* $@2  */
  YYSYMBOL_compound_statement = 99,        /* compound_statement  */
  YYSYMBOL_optional_block_item_list = 100, /* optional_block_item_list  */
  YYSYMBOL_expression_statement = 101,     /* expression_statement  */
  YYSYMBOL_selection_statement = 102,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 103,      /* iteration_statement  */
  YYSYMBOL_104_3 = 104,                    /* @3  */
  YYSYMBOL_105_4 = 105,                    /* @4  */
  YYSYMBOL_106_5 = 106,                    /* @5  */
  YYSYMBOL_optional_expression = 107,      /* optional_expression  */
  YYSYMBOL_jump_statement = 108,           /* jump_statement  */
  YYSYMBOL_identifier = 109,               /* identifier  */
  YYSYMBOL_string_literal = 110,           /* string_literal  */
  YYSYMBOL_constant = 111,                 /* constant  */
  YYSYMBOL_primary_expression = 112,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 113,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 114, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 115,         /* unary_expression  */
  YYSYMBOL_cast_expression = 116,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 117, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 118,      /* additive_expression  */
  YYSYMBOL_shift_expression = 119,         /* shift_expression  */
  YYSYMBOL_relational_expression = 120,    /* relational_expression  */
  YYSYMBOL_equality_expression = 121,      /* equality_expression  */
  YYSYMBOL_and_expression = 122,           /* and_expression  */
  YYSYMBOL_xor_expression = 123,           /* xor_expression  */
  YYSYMBOL_or_expression = 124,            /* or_expression  */
  YYSYMBOL_logical_and_expression = 125,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 126,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 127,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 128,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 129,      /* assignment_operator  */
  YYSYMBOL_expression = 130,               /* expression  */
  YYSYMBOL_constant_expression = 131,      /* constant_expression  */
  YYSYMBOL_declaration = 132,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 133,   /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 134,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 135,           /* type_specifier  */
  YYSYMBOL_type_qualifier = 136,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 137,       /* function_specifier  */
  YYSYMBOL_init_declarator_list = 138,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 139,          /* init_declarator  */
  YYSYMBOL_declarator = 140,               /* declarator  */
  YYSYMBOL_direct_declarator = 141,        /* direct_declarator  */
  YYSYMBOL_pointer = 142,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 143,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 144,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 145,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 146,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 147,          /* identifier_list  */
  YYSYMBOL_type_name = 148,                /* type_name  */
  YYSYMBOL_abstract_declarator = 149,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 150, /* direct_abstract_declarator  */
  YYSYMBOL_struct_or_union_specifier = 151, /* struct_or_union_specifier  */
  YYSYMBOL_152_6 = 152,                    /* @6  */
  YYSYMBOL_struct_or_union = 153,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 154,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 155,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 156, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 157,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 158         /* struct_declarator  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  33
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1201

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  69
/* YYNRULES -- Number of rules.  */
#define YYNRULES  199
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  311

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   321


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    80,     2,     2,     2,    82,    75,     2,
      70,    71,    76,    77,    74,    78,     2,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    88,    69,
      83,    89,    84,    87,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    85,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    86,    68,    79,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   206,   206,   207,   211,   212,   258,   257,   378,   379,
     383,   424,   429,   429,   430,   431,   432,   433,   438,   442,
     443,   447,   448,   452,   457,   467,   466,   478,   477,   490,
     489,   509,   510,   514,   515,   516,   534,   538,   542,   543,
     547,   548,   549,   550,   554,   555,   556,   557,   560,   561,
     565,   566,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   585,   586,   590,   591,   592,   593,
     597,   598,   599,   603,   604,   605,   609,   610,   611,   612,
     613,   617,   618,   619,   623,   624,   627,   628,   631,   632,
     636,   637,   641,   642,   646,   647,   651,   652,   656,   657,
     658,   659,   660,   661,   662,   663,   664,   665,   666,   670,
     671,   675,   683,   689,   695,   696,   697,   698,   699,   700,
     701,   702,   707,   708,   709,   710,   716,   717,   718,   719,
     720,   721,   722,   723,   724,   725,   726,   727,   734,   735,
     736,   741,   746,   747,   751,   756,   757,   761,   762,   763,
     764,   765,   767,   768,   772,   773,   774,   775,   779,   780,
     785,   790,   791,   802,   810,   817,   829,   830,   841,   846,
     856,   857,   858,   862,   863,   864,   865,   866,   867,   868,
     869,   870,   883,   885,   884,   916,   932,   933,   937,   938,
     942,   951,   952,   953,   954,   958,   959,   963,   964,   965
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENT", "CHARLIT",
  "STRINGLIT", "NUMBERLIT", "\"->\"", "\"++\"", "\"--\"", "\"<<\"",
  "\">>\"", "\"<=\"", "\">=\"", "\"==\"", "\"!=\"", "\"&&\"", "\"||\"",
  "\"...\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"+=\"", "\"-=\"", "\"<<=\"",
  "\">>=\"", "\"&=\"", "\"|=\"", "\"^=\"", "AUTO", "ALIGNOF", "BREAK",
  "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE",
  "ENUM", "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG",
  "REGISTER", "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "_BOOL", "_COMPLEX", "_IMAGINARY", "'{'", "'}'", "';'", "'('",
  "')'", "'['", "']'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "$accept",
  "translation_unit", "external_declaration", "function_definition", "@1",
  "block_item_list", "block_item", "statement", "$@2",
  "compound_statement", "optional_block_item_list", "expression_statement",
  "selection_statement", "iteration_statement", "@3", "@4", "@5",
  "optional_expression", "jump_statement", "identifier", "string_literal",
  "constant", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "xor_expression", "or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "assignment_operator", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "function_specifier", "init_declarator_list", "init_declarator",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "struct_or_union_specifier", "@6",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-197)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-21)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1037,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,   894,  -197,  -197,  -197,   767,  -197,  -197,  -197,
    -197,  -197,    80,  -197,  -197,  -197,  -197,    44,   134,  -197,
    -197,  -197,  -197,  -197,   -31,  -197,   -34,   -14,    45,    13,
    1136,   -26,  -197,  -197,   134,  -197,    44,    67,   855,   500,
     -14,  -197,  -197,  -197,  1070,  -197,   201,  -197,  -197,  -197,
    -197,  -197,   264,  -197,  -197,  -197,   815,     1,    49,  -197,
     -19,  -197,  -197,  -197,   619,   619,   619,   647,   420,  -197,
     675,   675,   675,   675,   675,   675,  -197,  -197,  -197,  -197,
     156,  -197,  -197,    85,   -13,   181,   132,   180,    73,    75,
     120,   173,     4,  -197,   135,  1136,  -197,  -197,   675,  -197,
    -197,   133,    -1,  -197,   153,   154,  -197,   155,   162,   675,
     163,  -197,   342,  -197,  -197,    67,   170,  -197,  -197,  -197,
    -197,   260,  -197,  -197,    89,  -197,   767,   727,   535,  -197,
      26,  -197,    84,  -197,  1037,  -197,   237,   675,  -197,  -197,
    -197,   420,  -197,     5,   171,   963,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,  -197,   563,   675,   675,   675,   675,   675,
     675,   675,   675,   675,   675,   675,   675,   675,   675,   675,
     675,   675,   675,   675,   675,  -197,  1103,  -197,   675,  -197,
      25,  -197,  -197,   483,   675,   675,   172,   176,   675,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
    -197,  -197,  -197,   675,  -197,   675,  -197,   174,   175,  -197,
     179,    84,  1003,   591,  -197,  -197,   184,  -197,   675,   928,
     103,  -197,  -197,    56,  -197,   124,  -197,  -197,  -197,    85,
      85,   -13,   -13,   181,   181,   181,   181,   132,   132,   180,
      73,    75,   120,   173,   -35,  -197,  -197,  -197,   193,   178,
     100,  -197,   114,  -197,  -197,  -197,  -197,  -197,  -197,   187,
    -197,   186,  -197,  -197,  -197,   675,  -197,   675,   194,   675,
     483,  -197,  -197,  -197,  -197,  -197,   675,   205,   236,   483,
     116,   675,   483,  -197,   207,   219,  -197,  -197,  -197,   483,
    -197
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   124,   127,   138,   132,   122,   131,   141,   129,   130,
     125,   139,   128,   133,   123,   186,   187,   134,   126,   140,
     135,   136,     0,     2,     4,     5,     0,   116,   114,   115,
     117,   137,     0,     1,     3,    36,   113,     0,   154,   147,
     120,   118,   119,   121,     0,   142,   144,   145,     0,   185,
       0,     0,   158,   156,   155,   112,     0,     0,     0,     0,
     146,   183,   191,   192,     0,   188,     0,   148,   159,   157,
     143,   144,    12,     7,   151,   166,   164,     0,   160,   161,
       0,    38,    37,    39,     0,     0,     0,     0,     0,   149,
       0,     0,     0,     0,     0,     0,    40,    42,    41,    44,
      52,    64,    66,    70,    73,    76,    81,    84,    86,    88,
      90,    92,    94,   111,     0,     0,   182,   189,     0,   193,
     194,   197,     0,   195,     0,     0,    27,     0,     0,    32,
       0,    22,    12,     8,    11,     0,     0,    14,    15,    16,
      17,    64,    96,   109,     0,    10,     0,     0,     0,   163,
     170,   165,   171,   153,     0,   152,     0,     0,    53,    54,
      63,     0,    61,     0,     0,   168,    55,    56,    57,    58,
      59,    60,    48,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   150,     0,   198,     0,   190,
       0,    34,    33,    12,    32,     0,     0,    31,     0,     9,
      13,    18,   101,   102,   103,    99,   100,   104,   105,   106,
     108,   107,    98,     0,    21,     0,   178,     0,     0,   174,
       0,   172,     0,     0,   162,   167,     0,    43,     0,     0,
     170,   169,    46,     0,    50,     0,    67,    68,    69,    71,
      72,    74,    75,    78,    80,    77,    79,    82,    83,    85,
      87,    89,    91,    93,     0,   184,   199,   196,     0,     0,
       0,    35,     0,    97,   110,   180,   173,   175,   179,     0,
     176,     0,    62,    65,    47,     0,    45,     0,     0,    32,
      12,    25,   181,   177,    51,    95,     0,     0,    23,    12,
       0,    32,    12,    26,     0,     0,    24,    28,    29,    12,
      30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -197,  -197,   222,  -197,  -197,  -197,   146,  -140,  -197,   157,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -196,  -197,    -7,
    -197,  -197,  -197,  -197,  -197,   -72,   -68,    20,    30,    -3,
      32,   102,   106,   109,   111,   115,  -197,   -56,  -139,  -197,
     -87,   -98,   -61,     9,    -9,    11,    40,     6,  -197,   248,
     -22,   -38,   -36,  -197,   -53,  -197,   167,  -197,   161,   -40,
    -143,  -197,  -197,  -197,   215,   -58,   -42,  -197,   131
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    22,    23,    24,    57,   132,   133,   134,   135,    73,
     136,   137,   138,   139,   299,   203,   309,   206,   140,    96,
      97,    98,    99,   100,   243,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   142,   143,   223,
     144,   114,    25,    76,    27,    28,    29,    30,    44,    45,
      51,    47,    48,    54,   227,    78,    79,    80,   164,   228,
     152,    31,   115,    32,    64,    65,    66,   122,   123
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     141,   163,    53,   113,    46,    77,   117,   231,   269,    26,
      60,   145,   158,   159,   160,   162,   141,    40,    69,    39,
     197,   193,   166,   167,   168,   169,   170,   171,    35,    35,
      39,    26,    43,    -6,    71,   244,   151,    41,    55,   225,
     150,    39,   207,    56,   121,    67,   165,    35,    35,    39,
     230,    75,   155,   287,   149,   156,    58,   141,    59,    39,
     141,    62,   113,   268,   179,   180,    42,    40,   199,    39,
     163,   145,   153,   200,   163,    62,   237,   119,    52,   225,
      61,   146,    43,    49,   273,   141,   274,    41,   245,   141,
      63,   194,   113,   297,    68,    37,   147,   231,   148,    62,
     266,    38,   141,   141,    63,   305,   120,   264,   246,   247,
     248,   150,    60,   118,    37,    37,    42,   207,   270,   165,
      38,   272,   141,   154,    71,   241,    62,   284,    63,   240,
     285,   141,   141,   141,    72,   281,   141,    40,   117,    39,
      39,   146,   113,    39,   183,   184,   294,    50,   189,   235,
     298,   141,    43,   141,   232,    63,   233,    41,   224,   303,
     190,   176,   306,   225,   172,   173,   177,   178,     3,   310,
     283,   290,    62,   239,   225,   148,   119,   113,   121,   279,
     253,   254,   255,   256,    11,   291,    42,   304,   225,   192,
     225,   181,   182,    39,   187,   188,    19,   286,   225,   249,
     250,    63,   207,   240,    35,   120,   191,    62,   195,   300,
      38,   251,   252,   141,   207,   185,   186,   141,   141,   257,
     258,   198,   201,   202,   141,   204,   174,   141,   175,   141,
     141,   295,   205,   208,     2,     3,    63,   141,   211,     4,
      35,   271,   238,     6,    34,   275,   276,   289,     8,     9,
     225,    11,   277,    12,    13,   282,   288,    15,   292,   293,
      16,    17,    18,    19,   296,    20,    21,    35,    81,    82,
      83,    37,    84,    85,   301,   302,   307,    38,   209,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   118,
     308,   259,   210,     1,    86,   124,   260,     2,     3,   125,
     261,   126,     4,   262,    70,     5,     6,   127,   263,   128,
       7,     8,     9,    10,    11,   129,    12,    13,    87,    14,
      15,   234,   236,    16,    17,    18,    19,   130,    20,    21,
     196,   267,   -20,   131,    88,     0,     0,     0,     0,    90,
      91,    92,    93,    94,    95,    35,    81,    82,    83,   222,
      84,    85,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     1,    86,   124,     0,     2,     3,   125,     0,   126,
       4,     0,     0,     5,     6,   127,     0,   128,     7,     8,
       9,    10,    11,   129,    12,    13,    87,    14,    15,     0,
       0,    16,    17,    18,    19,   130,    20,    21,     0,     0,
     -19,   131,    88,     0,     0,     0,     0,    90,    91,    92,
      93,    94,    95,    35,    81,    82,    83,     0,    84,    85,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      86,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       0,     0,     6,     0,     0,     0,     0,     8,     9,     0,
      11,     0,    12,    13,    87,     0,    15,     0,     0,    16,
      17,    18,    19,     0,    20,    21,    35,    81,    82,    83,
      88,    84,    85,     0,     0,    90,    91,    92,    93,    94,
      95,     0,     0,    35,    81,    82,    83,     0,    84,    85,
       0,     0,     0,    86,   124,     0,     0,     0,   125,     0,
     126,     0,     0,     0,     0,     0,   127,     0,   128,     0,
      86,     0,     0,     0,   129,     0,     0,    87,    35,    81,
      82,    83,     0,    84,    85,     0,   130,     0,     0,     0,
       0,     0,   131,    88,    87,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,    86,    35,    81,    82,    83,
      88,    84,    85,    89,     0,    90,    91,    92,    93,    94,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    87,
       0,     0,     0,    86,    35,    81,    82,    83,     0,    84,
      85,     0,     0,     0,     0,    88,     0,     0,   229,     0,
      90,    91,    92,    93,    94,    95,     0,    87,     0,     0,
       0,    86,    35,    81,    82,    83,     0,    84,    85,     0,
       0,     0,     0,    88,   242,     0,     0,     0,    90,    91,
      92,    93,    94,    95,     0,    87,     0,     0,     0,    86,
      35,    81,    82,    83,     0,    84,    85,     0,     0,     0,
       0,    88,     0,     0,   280,     0,    90,    91,    92,    93,
      94,    95,     0,    87,     0,     0,     0,    86,    35,    81,
      82,    83,     0,    84,    85,     0,     0,     0,     0,   157,
       0,     0,     0,     0,    90,    91,    92,    93,    94,    95,
       0,    87,     0,     0,     0,    86,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
       0,     0,    90,    91,    92,    93,    94,    95,     0,    87,
      35,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    88,     0,     0,     0,     0,
      90,    91,    92,    93,    94,    95,     1,     0,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     0,     5,     6,
      35,     0,     0,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    14,    15,     0,     0,    16,    17,    18,    19,
       0,    20,    21,     0,     0,     0,     1,   147,   226,   148,
       2,     3,     0,    38,     0,     4,     0,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,    35,    12,
      13,     0,    14,    15,     0,     0,    16,    17,    18,    19,
       0,    20,    21,     0,     0,     0,    36,    37,     0,     0,
       0,     0,     0,    38,     1,     0,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     0,     5,     6,    35,     0,
       0,     7,     8,     9,    10,    11,     0,    12,    13,     0,
      14,    15,     0,     0,    16,    17,    18,    19,     0,    20,
      21,     0,     0,     0,     1,   147,     0,   148,     2,     3,
       0,    38,     0,     4,    33,     0,     5,     6,     0,     0,
       0,     7,     8,     9,    10,    11,     0,    12,    13,     0,
      14,    15,     0,     0,    16,    17,    18,    19,     0,    20,
      21,     0,     0,     1,     0,     0,    74,     2,     3,     0,
       0,     0,     4,     0,     0,     5,     6,     0,     0,     0,
       7,     8,     9,    10,    11,     0,    12,    13,     0,    14,
      15,     0,     0,    16,    17,    18,    19,     1,    20,    21,
       0,     2,     3,     0,     0,     0,     4,     0,     0,     5,
       6,     0,     0,     0,     7,     8,     9,    10,    11,     0,
      12,    13,     0,    14,    15,     0,     0,    16,    17,    18,
      19,     0,    20,    21,     0,     0,     2,     3,   239,   226,
     148,     4,     0,     0,    38,     6,     0,     0,     0,     0,
       8,     9,     0,    11,     0,    12,    13,     0,     0,    15,
       0,     0,    16,    17,    18,    19,     0,    20,    21,     0,
       0,     0,     1,   239,     0,   148,     2,     3,     0,    38,
       0,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       8,     9,    10,    11,     0,    12,    13,     0,    14,    15,
       0,     0,    16,    17,    18,    19,     1,    20,    21,     0,
       2,     3,     0,     0,   278,     4,     0,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    14,    15,     0,     0,    16,    17,    18,    19,
       0,    20,    21,     2,     3,     0,     0,     0,     4,     0,
       0,     0,     6,     0,     0,     0,     0,     8,     9,     0,
      11,     0,    12,    13,     0,     0,    15,     0,     0,    16,
      17,    18,    19,     0,    20,    21,     2,     3,   116,     0,
       0,     4,     0,     0,     0,     6,     0,     0,     0,     0,
       8,     9,     0,    11,     0,    12,    13,     0,     0,    15,
       0,     0,    16,    17,    18,    19,     0,    20,    21,     2,
       3,   265,     0,     0,     4,     0,     0,     0,     6,     0,
       0,     0,     0,     8,     9,     0,    11,     0,    12,    13,
       0,     0,    15,     0,     0,    16,    17,    18,    19,     0,
      20,    21
};

static const yytype_int16 yycheck[] =
{
      72,    88,    38,    59,    26,    58,    64,   150,   204,     0,
      48,    72,    84,    85,    86,    87,    88,    26,    54,    26,
     118,    17,    90,    91,    92,    93,    94,    95,     3,     3,
      37,    22,    26,    67,    56,   174,    76,    26,    69,    74,
      76,    48,   129,    74,    66,    71,    88,     3,     3,    56,
     148,    58,    71,    88,    76,    74,    70,   129,    72,    66,
     132,    50,   118,   203,    77,    78,    26,    76,    69,    76,
     157,   132,    71,    74,   161,    64,    71,    66,    38,    74,
      67,    72,    76,     3,   223,   157,   225,    76,   175,   161,
      50,    87,   148,   289,    54,    70,    70,   240,    72,    88,
     198,    76,   174,   175,    64,   301,    66,   194,   176,   177,
     178,   147,   150,    88,    70,    70,    76,   204,   205,   161,
      76,   208,   194,    74,   146,   165,   115,    71,    88,   165,
      74,   203,   204,   205,    67,   233,   208,   146,   196,   146,
     147,   132,   198,   150,    12,    13,   285,    67,    75,   156,
     290,   223,   146,   225,    70,   115,    72,   146,    69,   299,
      85,    76,   302,    74,     8,     9,    81,    82,    34,   309,
     238,    71,   161,    70,    74,    72,   165,   233,   200,   232,
     183,   184,   185,   186,    50,    71,   146,    71,    74,    16,
      74,    10,    11,   200,    14,    15,    62,    73,    74,   179,
     180,   161,   289,   239,     3,   165,    86,   196,    73,   296,
      76,   181,   182,   285,   301,    83,    84,   289,   290,   187,
     188,    88,    69,    69,   296,    70,    70,   299,    72,   301,
     302,   287,    70,    70,    33,    34,   196,   309,    68,    38,
       3,    69,    71,    42,    22,    71,    71,    69,    47,    48,
      74,    50,    73,    52,    53,    71,    63,    56,    71,    73,
      59,    60,    61,    62,    70,    64,    65,     3,     4,     5,
       6,    70,     8,     9,    69,    39,    69,    76,   132,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    88,
      71,   189,   135,    29,    30,    31,   190,    33,    34,    35,
     191,    37,    38,   192,    56,    41,    42,    43,   193,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,   154,   161,    59,    60,    61,    62,    63,    64,    65,
     115,   200,    68,    69,    70,    -1,    -1,    -1,    -1,    75,
      76,    77,    78,    79,    80,     3,     4,     5,     6,    89,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    29,    30,    31,    -1,    33,    34,    35,    -1,    37,
      38,    -1,    -1,    41,    42,    43,    -1,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    75,    76,    77,
      78,    79,    80,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,
      50,    -1,    52,    53,    54,    -1,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65,     3,     4,     5,     6,
      70,     8,     9,    -1,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    30,    31,    -1,    -1,    -1,    35,    -1,
      37,    -1,    -1,    -1,    -1,    -1,    43,    -1,    45,    -1,
      30,    -1,    -1,    -1,    51,    -1,    -1,    54,     3,     4,
       5,     6,    -1,     8,     9,    -1,    63,    -1,    -1,    -1,
      -1,    -1,    69,    70,    54,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    30,     3,     4,     5,     6,
      70,     8,     9,    73,    -1,    75,    76,    77,    78,    79,
      80,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    30,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    70,    -1,    -1,    73,    -1,
      75,    76,    77,    78,    79,    80,    -1,    54,    -1,    -1,
      -1,    30,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    70,    71,    -1,    -1,    -1,    75,    76,
      77,    78,    79,    80,    -1,    54,    -1,    -1,    -1,    30,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    73,    -1,    75,    76,    77,    78,
      79,    80,    -1,    54,    -1,    -1,    -1,    30,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    75,    76,    77,    78,    79,    80,
      -1,    54,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    79,    80,    -1,    54,
       3,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,
      75,    76,    77,    78,    79,    80,    29,    -1,    -1,    -1,
      33,    34,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
       3,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    -1,    29,    70,    71,    72,
      33,    34,    -1,    76,    -1,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,     3,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    -1,    69,    70,    -1,    -1,
      -1,    -1,    -1,    76,    29,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    38,    -1,    -1,    41,    42,     3,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      65,    -1,    -1,    -1,    29,    70,    -1,    72,    33,    34,
      -1,    76,    -1,    38,     0,    -1,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      65,    -1,    -1,    29,    -1,    -1,    71,    33,    34,    -1,
      -1,    -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    59,    60,    61,    62,    29,    64,    65,
      -1,    33,    34,    -1,    -1,    -1,    38,    -1,    -1,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    -1,    -1,    33,    34,    70,    71,
      72,    38,    -1,    -1,    76,    42,    -1,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,
      -1,    -1,    59,    60,    61,    62,    -1,    64,    65,    -1,
      -1,    -1,    29,    70,    -1,    72,    33,    34,    -1,    76,
      -1,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    59,    60,    61,    62,    29,    64,    65,    -1,
      33,    34,    -1,    -1,    71,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,
      50,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65,    33,    34,    68,    -1,
      -1,    38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,
      -1,    -1,    59,    60,    61,    62,    -1,    64,    65,    33,
      34,    68,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,
      -1,    -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    33,    34,    38,    41,    42,    46,    47,    48,
      49,    50,    52,    53,    55,    56,    59,    60,    61,    62,
      64,    65,    91,    92,    93,   132,   133,   134,   135,   136,
     137,   151,   153,     0,    92,     3,    69,    70,    76,   109,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     3,
      67,   140,   136,   142,   143,    69,    74,    94,    70,    72,
     141,    67,   135,   136,   154,   155,   156,    71,   136,   142,
     139,   140,    67,    99,    71,   109,   133,   144,   145,   146,
     147,     4,     5,     6,     8,     9,    30,    54,    70,    73,
      75,    76,    77,    78,    79,    80,   109,   110,   111,   112,
     113,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   131,   152,    68,   155,    88,   135,
     136,   140,   157,   158,    31,    35,    37,    43,    45,    51,
      63,    69,    95,    96,    97,    98,   100,   101,   102,   103,
     108,   115,   127,   128,   130,   132,   133,    70,    72,   140,
     142,   149,   150,    71,    74,    71,    74,    70,   115,   115,
     115,    70,   115,   130,   148,   156,   116,   116,   116,   116,
     116,   116,     8,     9,    70,    72,    76,    81,    82,    77,
      78,    10,    11,    12,    13,    83,    84,    14,    15,    75,
      85,    86,    16,    17,    87,    73,   154,   131,    88,    69,
      74,    69,    69,   105,    70,    70,   107,   130,    70,    96,
      99,    68,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    89,   129,    69,    74,    71,   144,   149,    73,
     131,   150,    70,    72,   146,   109,   148,    71,    71,    70,
     142,   149,    71,   114,   128,   130,   116,   116,   116,   117,
     117,   118,   118,   119,   119,   119,   119,   120,   120,   121,
     122,   123,   124,   125,   130,    68,   131,   158,    97,   107,
     130,    69,   130,   128,   128,    71,    71,    73,    71,   144,
      73,   131,    71,   116,    71,    74,    73,    88,    63,    69,
      71,    71,    71,    73,   128,   127,    70,   107,    97,   104,
     130,    69,    39,    97,    71,   107,    97,    69,    71,   106,
      97
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    92,    92,    94,    93,    95,    95,
      96,    96,    98,    97,    97,    97,    97,    97,    99,   100,
     100,   101,   101,   102,   102,   104,   103,   105,   103,   106,
     103,   107,   107,   108,   108,   108,   109,   110,   111,   111,
     112,   112,   112,   112,   113,   113,   113,   113,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   117,   117,
     118,   118,   118,   119,   119,   119,   120,   120,   120,   120,
     120,   121,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   130,
     130,   131,   132,   132,   133,   133,   133,   133,   133,   133,
     133,   133,   134,   134,   134,   134,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     136,   137,   138,   138,   139,   140,   140,   141,   141,   141,
     141,   141,   141,   141,   142,   142,   142,   142,   143,   143,
     144,   145,   145,   146,   146,   146,   147,   147,   148,   148,
     149,   149,   149,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   151,   152,   151,   151,   153,   153,   154,   154,
     155,   156,   156,   156,   156,   157,   157,   158,   158,   158
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     0,     4,     1,     2,
       1,     1,     0,     2,     1,     1,     1,     1,     3,     1,
       0,     2,     1,     5,     7,     0,     6,     0,     8,     0,
      10,     1,     0,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     3,     4,     2,     2,
       1,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     2,     1,     4,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     5,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     2,     1,     1,     1,     1,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     2,     1,     3,     3,
       4,     3,     4,     4,     1,     2,     2,     3,     1,     2,
       1,     1,     3,     2,     1,     2,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     4,     0,     6,     2,     1,     1,     1,     2,
       3,     1,     1,     2,     2,     1,     3,     1,     2,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */


/* User initialization code.  */
#line 26 "parser.y"
{
    st_init();
    ast_init();
}

#line 1472 "parser.tab.c"

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* external_declaration: declaration  */
#line 213 "parser.y"
    {
        // alias for declaration specs
        declaration_specifiers_t *ds = &(yyvsp[0].declaration_package).declaration_specifiers;

        // apply extern if needed since this is an external declaration
        if (!ds->storage_class)
            ds->storage_class = SC_IMPLICIT_EXTERN;

        ast_node_t *type = ast_new_type(ds->type_specifier, ds->type_qualifier);

        for (int i = 0; i < (yyvsp[0].declaration_package).declarator_count ; i++)
        {
            ast_node_t *var = ast_ident_to_variable((yyvsp[0].declaration_package).declarators[i].oldest, ds->storage_class);
            (yyvsp[0].declaration_package).declarators[i].newest->next = type;

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
                    errorf("%s:%d: Error: conflicting type on already existing variable `%s`", filename, line_num, other->name);
                }
            }
            else
                st_add(NS_VARIABLE, var);

            // ! debug
            printf("EXTERNAL DECLARATION: ");
            ast_print_variable(var, 0);
            printf("\n");

            backend_write_global(var);
        }
    }
#line 1715 "parser.tab.c"
    break;

  case 6: /* @1: %empty  */
#line 258 "parser.y"
    {
        if (!(yyvsp[-1].declaration_specifiers).storage_class)
            (yyvsp[-1].declaration_specifiers).storage_class = SC_EXTERN;

        ast_node_t *type = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        ast_node_t *fn = ast_ident_to_variable((yyvsp[0].declarator_helper).oldest, (yyvsp[-1].declaration_specifiers).storage_class);
        (yyvsp[0].declarator_helper).newest->next = type;

        if (fn->next->kind != AST_FUNCTION)
        {
            errorf("%s:%d: Error: expected a ';'");
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
                errorf("%s:%d: Error: conflicting type on already existing variable `%s`", filename, line_num, other->name);
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
                fn->next->function.parameters->items[i]->variable.is_argument = 1;
                st_add(NS_VARIABLE, fn->next->function.parameters->items[i]);
            });
        }

        (yyval.node) = fn;
    }
#line 1766 "parser.tab.c"
    break;

  case 7: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 305 "parser.y"
    {
        (yyvsp[-1].node)->next->function.definition = (yyvsp[0].node);
        // ! debug
        printf("FUNCTION DEFINITION: ");
        ast_print_variable((yyvsp[-1].node), 0);
        ast_print_statement((yyvsp[0].node), 0);
        printf("\n");

        basic_block_list_t *bbl = generate_function_quads((yyvsp[0].node));
        print_basic_block_list(bbl);

        bbl->name = (yyvsp[-1].node)->name;

        fflush(stdout);

        backend_write_function(bbl);
    }
#line 1788 "parser.tab.c"
    break;

  case 10: /* block_item: declaration  */
#line 384 "parser.y"
    {
        // alias for declaration specs
        declaration_specifiers_t *ds = &(yyvsp[0].declaration_package).declaration_specifiers;

        // apply auto if needed
        if (!ds->storage_class)
            ds->storage_class = SC_AUTO;

        if (ds->storage_class == SC_EXTERN)
            errorf("local variable cannot have storage class extern");

        ast_node_t *type = ast_new_type(ds->type_specifier, ds->type_qualifier);

        for (int i = 0; i < (yyvsp[0].declaration_package).declarator_count ; i++)
        {
            ast_node_t *var = ast_ident_to_variable((yyvsp[0].declaration_package).declarators[i].oldest, ds->storage_class);
            (yyvsp[0].declaration_package).declarators[i].newest->next = type;

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
                    errorf("%s:%d: Error: conflicting type on already existing variable `%s`", filename, line_num, other->name);
                }
            }
            else
                st_add(NS_VARIABLE, var);

            // ! debug
            printf("DECLARATION: ");
            ast_print_variable(var, 0);
        }
    }
#line 1833 "parser.tab.c"
    break;

  case 11: /* block_item: statement  */
#line 424 "parser.y"
                {st_add_statement((yyvsp[0].node));}
#line 1839 "parser.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 429 "parser.y"
        {st_push();}
#line 1845 "parser.tab.c"
    break;

  case 13: /* statement: $@2 compound_statement  */
#line 429 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1851 "parser.tab.c"
    break;

  case 18: /* compound_statement: '{' optional_block_item_list '}'  */
#line 438 "parser.y"
                                         {(yyval.node) = st_pop();}
#line 1857 "parser.tab.c"
    break;

  case 21: /* expression_statement: expression ';'  */
#line 447 "parser.y"
                       {ast_resolve_expression_variables(&(yyvsp[-1].node), 0); (yyval.node) = ast_new_expression_statement((yyvsp[-1].node));}
#line 1863 "parser.tab.c"
    break;

  case 22: /* expression_statement: ';'  */
#line 448 "parser.y"
              {(yyval.node) = ast_new_expression_statement(0);}
#line 1869 "parser.tab.c"
    break;

  case 23: /* selection_statement: IF '(' expression ')' statement  */
#line 453 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-2].node), 0);
            (yyval.node) = ast_new_if_statement((yyvsp[-2].node), (yyvsp[0].node), 0);
        }
#line 1878 "parser.tab.c"
    break;

  case 24: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 458 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-4].node), 0);
            (yyval.node) = ast_new_if_statement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1887 "parser.tab.c"
    break;

  case 25: /* @3: %empty  */
#line 467 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-1].node), 0);
            ja_push((yyval.node) = ast_new_while_statement(AST_WHILE, (yyvsp[-1].node), 0));
        }
#line 1896 "parser.tab.c"
    break;

  case 26: /* iteration_statement: WHILE '(' expression ')' @3 statement  */
#line 472 "parser.y"
        {
            ja_pop();
            (yyvsp[-1].node)->while_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1906 "parser.tab.c"
    break;

  case 27: /* @4: %empty  */
#line 478 "parser.y"
        {
            ja_push((yyval.node) = ast_new_while_statement(AST_DO_WHILE, 0, 0));
        }
#line 1914 "parser.tab.c"
    break;

  case 28: /* iteration_statement: DO @4 statement WHILE '(' expression ')' ';'  */
#line 482 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-2].node), 0);
            ja_pop();
            (yyvsp[-6].node)->while_statement.condition = (yyvsp[-2].node);
            (yyvsp[-6].node)->while_statement.statement = (yyvsp[-5].node);
            (yyval.node) = (yyvsp[-6].node);
        }
#line 1926 "parser.tab.c"
    break;

  case 29: /* @5: %empty  */
#line 490 "parser.y"
        {
            if ((yyvsp[-5].node))
                ast_resolve_expression_variables(&(yyvsp[-5].node), 0);
            if ((yyvsp[-3].node))
                ast_resolve_expression_variables(&(yyvsp[-3].node), 0);
            if ((yyvsp[-1].node))
                ast_resolve_expression_variables(&(yyvsp[-1].node), 0);
            ja_push((yyval.node) = ast_new_for_statement((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), 0));
        }
#line 1940 "parser.tab.c"
    break;

  case 30: /* iteration_statement: FOR '(' optional_expression ';' optional_expression ';' optional_expression ')' @5 statement  */
#line 500 "parser.y"
        {
            ja_pop();
            (yyvsp[-1].node)->for_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1950 "parser.tab.c"
    break;

  case 31: /* optional_expression: expression  */
#line 509 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1956 "parser.tab.c"
    break;

  case 32: /* optional_expression: %empty  */
#line 510 "parser.y"
                 {(yyval.node) = 0;}
#line 1962 "parser.tab.c"
    break;

  case 33: /* jump_statement: CONTINUE ';'  */
#line 514 "parser.y"
                     {(yyval.node) = ast_new_continue_statement(ja_get_continue_association());}
#line 1968 "parser.tab.c"
    break;

  case 34: /* jump_statement: BREAK ';'  */
#line 515 "parser.y"
                    {(yyval.node) = ast_new_break_statement(ja_get_break_association());}
#line 1974 "parser.tab.c"
    break;

  case 35: /* jump_statement: RETURN optional_expression ';'  */
#line 516 "parser.y"
                                         {    
            if ((yyvsp[-1].node))
                ast_resolve_expression_variables(&(yyvsp[-1].node), 0);
            (yyval.node) = ast_new_return_statement((yyvsp[-1].node));
        }
#line 1984 "parser.tab.c"
    break;

  case 36: /* identifier: IDENT  */
#line 534 "parser.y"
              {(yyval.node) = ast_new_ident((yyvsp[0].string).buffer);}
#line 1990 "parser.tab.c"
    break;

  case 37: /* string_literal: STRINGLIT  */
#line 538 "parser.y"
                  {(yyval.node) = ast_new_string_literal((yyvsp[0].string));}
#line 1996 "parser.tab.c"
    break;

  case 38: /* constant: CHARLIT  */
#line 542 "parser.y"
                {(yyval.node) = ast_new_char_literal((yyvsp[0].string).buffer[0]); free((yyvsp[0].string).buffer);}
#line 2002 "parser.tab.c"
    break;

  case 39: /* constant: NUMBERLIT  */
#line 543 "parser.y"
                    {(yyval.node) = ast_new_number_literal((yyvsp[0].number));}
#line 2008 "parser.tab.c"
    break;

  case 43: /* primary_expression: '(' expression ')'  */
#line 550 "parser.y"
                             {(yyval.node) = (yyvsp[-1].node);}
#line 2014 "parser.tab.c"
    break;

  case 45: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 555 "parser.y"
                                                {(yyval.node) = ast_new_unary_op('*', ast_new_binary_op('+', (yyvsp[-3].node), (yyvsp[-1].node)));}
#line 2020 "parser.tab.c"
    break;

  case 46: /* postfix_expression: postfix_expression '(' ')'  */
#line 556 "parser.y"
                                     {(yyval.node) = ast_new_function_call((yyvsp[-2].node), ast_node_list_new());}
#line 2026 "parser.tab.c"
    break;

  case 47: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 557 "parser.y"
                                                              {(yyval.node) = ast_new_function_call((yyvsp[-3].node), (yyvsp[-1].node_list));}
#line 2032 "parser.tab.c"
    break;

  case 48: /* postfix_expression: postfix_expression "++"  */
#line 560 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(PLUSPLUS, (yyvsp[-1].node));}
#line 2038 "parser.tab.c"
    break;

  case 49: /* postfix_expression: postfix_expression "--"  */
#line 561 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(MINUSMINUS, (yyvsp[-1].node));}
#line 2044 "parser.tab.c"
    break;

  case 50: /* argument_expression_list: assignment_expression  */
#line 565 "parser.y"
                              {(yyval.node_list) = ast_node_list_add(ast_node_list_new(), (yyvsp[0].node));}
#line 2050 "parser.tab.c"
    break;

  case 51: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 566 "parser.y"
                                                             {(yyval.node_list) = ast_node_list_add((yyvsp[-2].node_list), (yyvsp[0].node));}
#line 2056 "parser.tab.c"
    break;

  case 53: /* unary_expression: "++" unary_expression  */
#line 571 "parser.y"
                                {(yyval.node) = ast_new_binary_op(PLUSEQ, (yyvsp[0].node), ast_new_number_literal((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 2062 "parser.tab.c"
    break;

  case 54: /* unary_expression: "--" unary_expression  */
#line 572 "parser.y"
                                {(yyval.node) = ast_new_binary_op(MINUSEQ, (yyvsp[0].node), ast_new_number_literal((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 2068 "parser.tab.c"
    break;

  case 55: /* unary_expression: '&' cast_expression  */
#line 573 "parser.y"
                              {(yyval.node) = ast_new_unary_op('&', (yyvsp[0].node));}
#line 2074 "parser.tab.c"
    break;

  case 56: /* unary_expression: '*' cast_expression  */
#line 574 "parser.y"
                              {(yyval.node) = ast_new_unary_op('*', (yyvsp[0].node));}
#line 2080 "parser.tab.c"
    break;

  case 57: /* unary_expression: '+' cast_expression  */
#line 575 "parser.y"
                              {(yyval.node) = ast_new_unary_op('+', (yyvsp[0].node));}
#line 2086 "parser.tab.c"
    break;

  case 58: /* unary_expression: '-' cast_expression  */
#line 576 "parser.y"
                              {(yyval.node) = ast_new_unary_op('-', (yyvsp[0].node));}
#line 2092 "parser.tab.c"
    break;

  case 59: /* unary_expression: '~' cast_expression  */
#line 577 "parser.y"
                              {(yyval.node) = ast_new_unary_op('~', (yyvsp[0].node));}
#line 2098 "parser.tab.c"
    break;

  case 60: /* unary_expression: '!' cast_expression  */
#line 578 "parser.y"
                              {(yyval.node) = ast_new_unary_op('!', (yyvsp[0].node));}
#line 2104 "parser.tab.c"
    break;

  case 61: /* unary_expression: SIZEOF unary_expression  */
#line 579 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(SIZEOF, (yyvsp[0].node));}
#line 2110 "parser.tab.c"
    break;

  case 62: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 580 "parser.y"
                                   {(yyval.node) = ast_new_unary_op(SIZEOF, (yyvsp[-1].node));}
#line 2116 "parser.tab.c"
    break;

  case 63: /* unary_expression: ALIGNOF unary_expression  */
#line 581 "parser.y"
                                   {(yyval.node) = ast_new_unary_op(ALIGNOF, (yyvsp[0].node));}
#line 2122 "parser.tab.c"
    break;

  case 65: /* cast_expression: '(' type_name ')' cast_expression  */
#line 586 "parser.y"
                                            {(yyval.node) = ast_new_type_cast((yyvsp[0].node), (yyvsp[-2].node));}
#line 2128 "parser.tab.c"
    break;

  case 67: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 591 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('*', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2134 "parser.tab.c"
    break;

  case 68: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 592 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('/', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2140 "parser.tab.c"
    break;

  case 69: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 593 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('%', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2146 "parser.tab.c"
    break;

  case 71: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 598 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op('+', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2152 "parser.tab.c"
    break;

  case 72: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 599 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op('-', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2158 "parser.tab.c"
    break;

  case 74: /* shift_expression: shift_expression "<<" additive_expression  */
#line 604 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2164 "parser.tab.c"
    break;

  case 75: /* shift_expression: shift_expression ">>" additive_expression  */
#line 605 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2170 "parser.tab.c"
    break;

  case 77: /* relational_expression: relational_expression '<' shift_expression  */
#line 610 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op('<', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2176 "parser.tab.c"
    break;

  case 78: /* relational_expression: relational_expression "<=" shift_expression  */
#line 611 "parser.y"
                                                      {(yyval.node) = ast_new_binary_op(LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2182 "parser.tab.c"
    break;

  case 79: /* relational_expression: relational_expression '>' shift_expression  */
#line 612 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op('>', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2188 "parser.tab.c"
    break;

  case 80: /* relational_expression: relational_expression ">=" shift_expression  */
#line 613 "parser.y"
                                                      {(yyval.node) = ast_new_binary_op(GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2194 "parser.tab.c"
    break;

  case 82: /* equality_expression: equality_expression "==" relational_expression  */
#line 618 "parser.y"
                                                         {(yyval.node) = ast_new_binary_op(EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2200 "parser.tab.c"
    break;

  case 83: /* equality_expression: equality_expression "!=" relational_expression  */
#line 619 "parser.y"
                                                         {(yyval.node) = ast_new_binary_op(NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2206 "parser.tab.c"
    break;

  case 85: /* and_expression: and_expression '&' equality_expression  */
#line 624 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('&', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2212 "parser.tab.c"
    break;

  case 87: /* xor_expression: xor_expression '^' and_expression  */
#line 628 "parser.y"
                                            {(yyval.node) = ast_new_binary_op('^', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2218 "parser.tab.c"
    break;

  case 89: /* or_expression: or_expression '|' xor_expression  */
#line 632 "parser.y"
                                           {(yyval.node) = ast_new_binary_op('|', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2224 "parser.tab.c"
    break;

  case 91: /* logical_and_expression: logical_and_expression "&&" or_expression  */
#line 637 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(LOGAND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2230 "parser.tab.c"
    break;

  case 93: /* logical_or_expression: logical_or_expression "||" logical_and_expression  */
#line 642 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op(LOGOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2236 "parser.tab.c"
    break;

  case 95: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 647 "parser.y"
                                                                          {(yyval.node) = ast_new_ternary_op((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2242 "parser.tab.c"
    break;

  case 97: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 652 "parser.y"
                                                                     {(yyval.node) = ast_new_binary_op((yyvsp[-1].integer), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2248 "parser.tab.c"
    break;

  case 98: /* assignment_operator: '='  */
#line 656 "parser.y"
            {(yyval.integer) = '=';}
#line 2254 "parser.tab.c"
    break;

  case 99: /* assignment_operator: "+="  */
#line 657 "parser.y"
               {(yyval.integer) = PLUSEQ;}
#line 2260 "parser.tab.c"
    break;

  case 100: /* assignment_operator: "-="  */
#line 658 "parser.y"
               {(yyval.integer) = MINUSEQ;}
#line 2266 "parser.tab.c"
    break;

  case 101: /* assignment_operator: "*="  */
#line 659 "parser.y"
               {(yyval.integer) = TIMESEQ;}
#line 2272 "parser.tab.c"
    break;

  case 102: /* assignment_operator: "/="  */
#line 660 "parser.y"
               {(yyval.integer) = DIVEQ;}
#line 2278 "parser.tab.c"
    break;

  case 103: /* assignment_operator: "%="  */
#line 661 "parser.y"
               {(yyval.integer) = MODEQ;}
#line 2284 "parser.tab.c"
    break;

  case 104: /* assignment_operator: "<<="  */
#line 662 "parser.y"
                {(yyval.integer) = SHLEQ;}
#line 2290 "parser.tab.c"
    break;

  case 105: /* assignment_operator: ">>="  */
#line 663 "parser.y"
                {(yyval.integer) = SHREQ;}
#line 2296 "parser.tab.c"
    break;

  case 106: /* assignment_operator: "&="  */
#line 664 "parser.y"
               {(yyval.integer) = ANDEQ;}
#line 2302 "parser.tab.c"
    break;

  case 107: /* assignment_operator: "^="  */
#line 665 "parser.y"
               {(yyval.integer) = XOREQ;}
#line 2308 "parser.tab.c"
    break;

  case 108: /* assignment_operator: "|="  */
#line 666 "parser.y"
               {(yyval.integer) = OREQ;}
#line 2314 "parser.tab.c"
    break;

  case 110: /* expression: expression ',' assignment_expression  */
#line 671 "parser.y"
                                               {(yyval.node) = ast_new_binary_op(',', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2320 "parser.tab.c"
    break;

  case 112: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 684 "parser.y"
    {
        (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_normalize_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
        (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
        (yyval.declaration_package) = (yyvsp[-1].declaration_package);
    }
#line 2330 "parser.tab.c"
    break;

  case 114: /* declaration_specifiers: type_specifier  */
#line 695 "parser.y"
                           {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2336 "parser.tab.c"
    break;

  case 115: /* declaration_specifiers: type_qualifier  */
#line 696 "parser.y"
                             {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2342 "parser.tab.c"
    break;

  case 116: /* declaration_specifiers: storage_class_specifier  */
#line 697 "parser.y"
                                      {declspec_init(&(yyval.declaration_specifiers)); declspec_add_storage_class(&(yyval.declaration_specifiers), (yyvsp[0].storage_class_specifier));}
#line 2348 "parser.tab.c"
    break;

  case 117: /* declaration_specifiers: function_specifier  */
#line 698 "parser.y"
                                 {declspec_init(&(yyval.declaration_specifiers)); declspec_add_function_specifier(&(yyval.declaration_specifiers), (yyvsp[0].function_specifier));}
#line 2354 "parser.tab.c"
    break;

  case 118: /* declaration_specifiers: declaration_specifiers type_specifier  */
#line 699 "parser.y"
                                                    {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2360 "parser.tab.c"
    break;

  case 119: /* declaration_specifiers: declaration_specifiers type_qualifier  */
#line 700 "parser.y"
                                                    {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2366 "parser.tab.c"
    break;

  case 120: /* declaration_specifiers: declaration_specifiers storage_class_specifier  */
#line 701 "parser.y"
                                                             {declspec_add_storage_class(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].storage_class_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2372 "parser.tab.c"
    break;

  case 121: /* declaration_specifiers: declaration_specifiers function_specifier  */
#line 702 "parser.y"
                                                        {declspec_add_function_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].function_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2378 "parser.tab.c"
    break;

  case 122: /* storage_class_specifier: EXTERN  */
#line 707 "parser.y"
                   {(yyval.storage_class_specifier) = SC_EXTERN;}
#line 2384 "parser.tab.c"
    break;

  case 123: /* storage_class_specifier: STATIC  */
#line 708 "parser.y"
                     {(yyval.storage_class_specifier) = SC_STATIC;}
#line 2390 "parser.tab.c"
    break;

  case 124: /* storage_class_specifier: AUTO  */
#line 709 "parser.y"
                   {(yyval.storage_class_specifier) = SC_AUTO;}
#line 2396 "parser.tab.c"
    break;

  case 125: /* storage_class_specifier: REGISTER  */
#line 710 "parser.y"
                       {(yyval.storage_class_specifier) = SC_REGISTER;}
#line 2402 "parser.tab.c"
    break;

  case 126: /* type_specifier: VOID  */
#line 716 "parser.y"
                 {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_VOID};}
#line 2408 "parser.tab.c"
    break;

  case 127: /* type_specifier: CHAR  */
#line 717 "parser.y"
                   {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_CHAR};}
#line 2414 "parser.tab.c"
    break;

  case 128: /* type_specifier: SHORT  */
#line 718 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SHORT};}
#line 2420 "parser.tab.c"
    break;

  case 129: /* type_specifier: INT  */
#line 719 "parser.y"
                  {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_INT};}
#line 2426 "parser.tab.c"
    break;

  case 130: /* type_specifier: LONG  */
#line 720 "parser.y"
                   {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_LONG};}
#line 2432 "parser.tab.c"
    break;

  case 131: /* type_specifier: FLOAT  */
#line 721 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_FLOAT};}
#line 2438 "parser.tab.c"
    break;

  case 132: /* type_specifier: DOUBLE  */
#line 722 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_DOUBLE};}
#line 2444 "parser.tab.c"
    break;

  case 133: /* type_specifier: SIGNED  */
#line 723 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SIGNED};}
#line 2450 "parser.tab.c"
    break;

  case 134: /* type_specifier: UNSIGNED  */
#line 724 "parser.y"
                       {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_UNSIGNED};}
#line 2456 "parser.tab.c"
    break;

  case 135: /* type_specifier: _BOOL  */
#line 725 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_BOOL};}
#line 2462 "parser.tab.c"
    break;

  case 136: /* type_specifier: _COMPLEX  */
#line 726 "parser.y"
                       {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_COMPLEX};}
#line 2468 "parser.tab.c"
    break;

  case 137: /* type_specifier: struct_or_union_specifier  */
#line 727 "parser.y"
                                        {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_STRUCT_OR_UNION, .custom = (yyvsp[0].node)};}
#line 2474 "parser.tab.c"
    break;

  case 138: /* type_qualifier: CONST  */
#line 734 "parser.y"
                  {(yyval.type_qualifier) = TQ_CONST;}
#line 2480 "parser.tab.c"
    break;

  case 139: /* type_qualifier: RESTRICT  */
#line 735 "parser.y"
                       {(yyval.type_qualifier) = TQ_RESTRICT;}
#line 2486 "parser.tab.c"
    break;

  case 140: /* type_qualifier: VOLATILE  */
#line 736 "parser.y"
                       {(yyval.type_qualifier) = TQ_VOLATILE;}
#line 2492 "parser.tab.c"
    break;

  case 141: /* function_specifier: INLINE  */
#line 741 "parser.y"
                   {(yyval.function_specifier) = FS_INLINE;}
#line 2498 "parser.tab.c"
    break;

  case 142: /* init_declarator_list: init_declarator  */
#line 746 "parser.y"
                    {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 2504 "parser.tab.c"
    break;

  case 143: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 747 "parser.y"
                                               {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 2510 "parser.tab.c"
    break;

  case 144: /* init_declarator: declarator  */
#line 751 "parser.y"
               {(yyvsp[0].declarator_helper).initializer = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2516 "parser.tab.c"
    break;

  case 145: /* declarator: direct_declarator  */
#line 756 "parser.y"
                      {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2522 "parser.tab.c"
    break;

  case 146: /* declarator: pointer direct_declarator  */
#line 757 "parser.y"
                                {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2528 "parser.tab.c"
    break;

  case 147: /* direct_declarator: identifier  */
#line 761 "parser.y"
               {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = (yyvsp[0].node);}
#line 2534 "parser.tab.c"
    break;

  case 148: /* direct_declarator: '(' declarator ')'  */
#line 762 "parser.y"
                         {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2540 "parser.tab.c"
    break;

  case 149: /* direct_declarator: direct_declarator '[' ']'  */
#line 763 "parser.y"
                                {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2546 "parser.tab.c"
    break;

  case 150: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 764 "parser.y"
                                                    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2552 "parser.tab.c"
    break;

  case 151: /* direct_declarator: direct_declarator '(' ')'  */
#line 765 "parser.y"
                                {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2558 "parser.tab.c"
    break;

  case 152: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 767 "parser.y"
                                                {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2564 "parser.tab.c"
    break;

  case 153: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 768 "parser.y"
                                                    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2570 "parser.tab.c"
    break;

  case 154: /* pointer: '*'  */
#line 772 "parser.y"
        {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer(0);}
#line 2576 "parser.tab.c"
    break;

  case 155: /* pointer: '*' type_qualifier_list  */
#line 773 "parser.y"
                              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer((yyvsp[0].type_qualifier));}
#line 2582 "parser.tab.c"
    break;

  case 156: /* pointer: '*' pointer  */
#line 774 "parser.y"
                  {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer(0); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2588 "parser.tab.c"
    break;

  case 157: /* pointer: '*' type_qualifier_list pointer  */
#line 775 "parser.y"
                                      {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer((yyvsp[-1].type_qualifier)); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2594 "parser.tab.c"
    break;

  case 158: /* type_qualifier_list: type_qualifier  */
#line 779 "parser.y"
                   {(yyval.type_qualifier) = (yyvsp[0].type_qualifier);}
#line 2600 "parser.tab.c"
    break;

  case 159: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 780 "parser.y"
                                         {(yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier);}
#line 2606 "parser.tab.c"
    break;

  case 160: /* parameter_type_list: parameter_list  */
#line 785 "parser.y"
                   {(yyval.symbol_table) = (yyvsp[0].symbol_table);}
#line 2612 "parser.tab.c"
    break;

  case 161: /* parameter_list: parameter_declaration  */
#line 790 "parser.y"
                          {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2618 "parser.tab.c"
    break;

  case 162: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 792 "parser.y"
    {
        if ((yyvsp[0].node)->name && st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            errorf("%s:%d: Error: parameter %s was already declared", filename, line_num, (yyvsp[0].node)->name);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2630 "parser.tab.c"
    break;

  case 163: /* parameter_declaration: declaration_specifiers declarator  */
#line 803 "parser.y"
    {
        (yyvsp[-1].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[-1].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable((yyvsp[0].declarator_helper).oldest, (yyvsp[-1].declaration_specifiers).storage_class);
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2642 "parser.tab.c"
    break;

  case 164: /* parameter_declaration: declaration_specifiers  */
#line 810 "parser.y"
                             {
        (yyvsp[0].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[0].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[0].declaration_specifiers).storage_class);
        var->next = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2654 "parser.tab.c"
    break;

  case 165: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 818 "parser.y"
    {
        (yyvsp[-1].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[-1].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[-1].declaration_specifiers).storage_class);
        var->next = (yyvsp[0].declarator_helper).oldest;
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2667 "parser.tab.c"
    break;

  case 166: /* identifier_list: identifier  */
#line 829 "parser.y"
               {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2673 "parser.tab.c"
    break;

  case 167: /* identifier_list: identifier_list ',' identifier  */
#line 831 "parser.y"
    {
        if (st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            errorf("%s:%d: Error: parameter %s was already declared", filename, line_num, (yyvsp[0].node)->name);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2685 "parser.tab.c"
    break;

  case 168: /* type_name: specifier_qualifier_list  */
#line 841 "parser.y"
                             {
        ast_node_t *tn = ast_ident_to_variable(ast_new_ident(0), 0);
        tn->next = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);
        (yyval.node) = tn;
    }
#line 2695 "parser.tab.c"
    break;

  case 169: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 847 "parser.y"
    {
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        ast_node_t *tn = ast_ident_to_variable(ast_new_ident(0), 0);
        tn->next = (yyvsp[0].declarator_helper).oldest;
        (yyval.node) = tn;
    }
#line 2706 "parser.tab.c"
    break;

  case 170: /* abstract_declarator: pointer  */
#line 856 "parser.y"
            {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2712 "parser.tab.c"
    break;

  case 171: /* abstract_declarator: direct_abstract_declarator  */
#line 857 "parser.y"
                                 {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2718 "parser.tab.c"
    break;

  case 172: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 858 "parser.y"
                                         {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2724 "parser.tab.c"
    break;

  case 173: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 862 "parser.y"
                                {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2730 "parser.tab.c"
    break;

  case 174: /* direct_abstract_declarator: '[' ']'  */
#line 863 "parser.y"
              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array(0);}
#line 2736 "parser.tab.c"
    break;

  case 175: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 864 "parser.y"
                                  {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array((yyvsp[-1].node));}
#line 2742 "parser.tab.c"
    break;

  case 176: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 865 "parser.y"
                                         {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2748 "parser.tab.c"
    break;

  case 177: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 866 "parser.y"
                                                             {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2754 "parser.tab.c"
    break;

  case 178: /* direct_abstract_declarator: '(' ')'  */
#line 867 "parser.y"
              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(0);}
#line 2760 "parser.tab.c"
    break;

  case 179: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 868 "parser.y"
                                         {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2766 "parser.tab.c"
    break;

  case 180: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 869 "parser.y"
                                  {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(st_unpack((yyvsp[-1].symbol_table)));}
#line 2772 "parser.tab.c"
    break;

  case 181: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 870 "parser.y"
                                                             {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2778 "parser.tab.c"
    break;

  case 182: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 883 "parser.y"
                                                        {(yyval.node) = ast_new_struct_or_union((yyvsp[-3].integer), 0, st_unpack((yyvsp[-1].symbol_table)));}
#line 2784 "parser.tab.c"
    break;

  case 183: /* @6: %empty  */
#line 885 "parser.y"
            {
                // midrule action since the struct needs to be installed before we see the members
                ast_node_t *node = st_find_local(NS_STRUCT, (yyvsp[-1].string).buffer); // check if a struct declaration already exists
                if (node)
                {
                    if (node->kind == (yyvsp[-2].integer))
                    {
                        if (node->structure.members == 0)
                        {
                            (yyval.node) = node; // put it on the stack
                        }
                        else
                        {
                            errorf("%s:%d: Error: `%s` is already complete", filename, line_num, (yyvsp[-1].string).buffer);
                        }
                    }
                    else
                    {
                        errorf("%s:%d: Error: a struct or union `%s` has already been declared", filename, line_num, (yyvsp[-1].string).buffer);
                    }
                }
                else
                {
                    st_add(NS_STRUCT, (yyval.node) = ast_new_struct_or_union((yyvsp[-2].integer), (yyvsp[-1].string).buffer, 0));
                }
            }
#line 2815 "parser.tab.c"
    break;

  case 184: /* struct_or_union_specifier: struct_or_union IDENT '{' @6 struct_declaration_list '}'  */
#line 912 "parser.y"
            {
                (yyval.node) = ast_add_struct_or_union_members((yyvsp[-2].node), st_unpack((yyvsp[-1].symbol_table)));
                ast_print_struct_or_union((yyval.node)); // ! debug
            }
#line 2824 "parser.tab.c"
    break;

  case 185: /* struct_or_union_specifier: struct_or_union IDENT  */
#line 917 "parser.y"
            {
                ast_node_t *node = st_find_local(NS_STRUCT, (yyvsp[0].string).buffer); // check if a struct declaration already exists
                if (node)
                {
                    (yyval.node) = node;
                }
                else
                {
                    st_add(NS_STRUCT, (yyval.node) = ast_new_struct_or_union((yyvsp[-1].integer), (yyvsp[0].string).buffer, 0));
                    ast_print_struct_or_union((yyval.node)); // ! debug
                }
            }
#line 2841 "parser.tab.c"
    break;

  case 186: /* struct_or_union: STRUCT  */
#line 932 "parser.y"
               {(yyval.integer) = AST_STRUCT;}
#line 2847 "parser.tab.c"
    break;

  case 187: /* struct_or_union: UNION  */
#line 933 "parser.y"
                {(yyval.integer) = AST_UNION;}
#line 2853 "parser.tab.c"
    break;

  case 188: /* struct_declaration_list: struct_declaration  */
#line 937 "parser.y"
                           {(yyval.symbol_table) = add_members_to_symbol_table(st_new(0), (yyvsp[0].declaration_package));}
#line 2859 "parser.tab.c"
    break;

  case 189: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 938 "parser.y"
                                                     {(yyval.symbol_table) = add_members_to_symbol_table((yyvsp[-1].symbol_table), (yyvsp[0].declaration_package));}
#line 2865 "parser.tab.c"
    break;

  case 190: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 943 "parser.y"
        {
            (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_normalize_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
            (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
            (yyval.declaration_package) = (yyvsp[-1].declaration_package);
        }
#line 2875 "parser.tab.c"
    break;

  case 191: /* specifier_qualifier_list: type_specifier  */
#line 951 "parser.y"
                       {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2881 "parser.tab.c"
    break;

  case 192: /* specifier_qualifier_list: type_qualifier  */
#line 952 "parser.y"
                         {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2887 "parser.tab.c"
    break;

  case 193: /* specifier_qualifier_list: specifier_qualifier_list type_specifier  */
#line 953 "parser.y"
                                                  {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2893 "parser.tab.c"
    break;

  case 194: /* specifier_qualifier_list: specifier_qualifier_list type_qualifier  */
#line 954 "parser.y"
                                                  {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2899 "parser.tab.c"
    break;

  case 195: /* struct_declarator_list: struct_declarator  */
#line 958 "parser.y"
                          {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 2905 "parser.tab.c"
    break;

  case 196: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 959 "parser.y"
                                                       {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 2911 "parser.tab.c"
    break;

  case 197: /* struct_declarator: declarator  */
#line 963 "parser.y"
                   {(yyvsp[0].declarator_helper).bit_width = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2917 "parser.tab.c"
    break;

  case 198: /* struct_declarator: ':' constant_expression  */
#line 964 "parser.y"
                                  {(yyval.declarator_helper) = (declarator_helper_t){.oldest = 0, .newest = 0, .bit_width = (yyvsp[0].node)};}
#line 2923 "parser.tab.c"
    break;

  case 199: /* struct_declarator: declarator ':' constant_expression  */
#line 965 "parser.y"
                                             {(yyvsp[-2].declarator_helper).bit_width = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 2929 "parser.tab.c"
    break;


#line 2933 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 992 "parser.y"


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
                errorf("%s:%d: Error: member `%s` is incomplete", filename, line_num, member->name);
            }

            if (declarator->oldest->next && declarator->oldest->next->kind == AST_ARRAY && declarator->oldest->next->array.size == 0)
            {
                errorf("%s:%d: Error: member `%s` cannot be an array of unknown size", filename, line_num, member->name);
            }

            declarator->newest->next = type;

            if (st_find_local(member_table, member->name))
            {
                errorf("%s:%d: Error: member `%s` has already been declared", filename, line_num, member->name);
            }

            st_add(member_table, member);
        }
    }

    return member_table;
}
