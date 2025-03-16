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

    // so much bread

    #include <stdlib.h>
    #include <stdio.h>
    #include "lexer.h"
    #include "ast.h"
    #include "location.h"
    #include "symbol_table.h"

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s:%d: %s\n", filename, line_num, s);
    }

#line 87 "parser.tab.c"

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
  YYSYMBOL_74_ = 74,                       /* '.'  */
  YYSYMBOL_75_ = 75,                       /* ','  */
  YYSYMBOL_76_ = 76,                       /* '&'  */
  YYSYMBOL_77_ = 77,                       /* '*'  */
  YYSYMBOL_78_ = 78,                       /* '+'  */
  YYSYMBOL_79_ = 79,                       /* '-'  */
  YYSYMBOL_80_ = 80,                       /* '~'  */
  YYSYMBOL_81_ = 81,                       /* '!'  */
  YYSYMBOL_82_ = 82,                       /* '/'  */
  YYSYMBOL_83_ = 83,                       /* '%'  */
  YYSYMBOL_84_ = 84,                       /* '<'  */
  YYSYMBOL_85_ = 85,                       /* '>'  */
  YYSYMBOL_86_ = 86,                       /* '^'  */
  YYSYMBOL_87_ = 87,                       /* '|'  */
  YYSYMBOL_88_ = 88,                       /* '?'  */
  YYSYMBOL_89_ = 89,                       /* ':'  */
  YYSYMBOL_90_ = 90,                       /* '='  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_external_declaration_list = 92, /* external_declaration_list  */
  YYSYMBOL_external_declaration = 93,      /* external_declaration  */
  YYSYMBOL_function_definition = 94,       /* function_definition  */
  YYSYMBOL_declaration_list = 95,          /* declaration_list  */
  YYSYMBOL_compound_statement = 96,        /* compound_statement  */
  YYSYMBOL_block_item_list = 97,           /* block_item_list  */
  YYSYMBOL_block_item = 98,                /* block_item  */
  YYSYMBOL_statement = 99,                 /* statement  */
  YYSYMBOL_expression_statement = 100,     /* expression_statement  */
  YYSYMBOL_identifier = 101,               /* identifier  */
  YYSYMBOL_string_literal = 102,           /* string_literal  */
  YYSYMBOL_constant = 103,                 /* constant  */
  YYSYMBOL_primary_expression = 104,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 105,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 106, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 107,         /* unary_expression  */
  YYSYMBOL_cast_expression = 108,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 109, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 110,      /* additive_expression  */
  YYSYMBOL_shift_expression = 111,         /* shift_expression  */
  YYSYMBOL_relational_expression = 112,    /* relational_expression  */
  YYSYMBOL_equality_expression = 113,      /* equality_expression  */
  YYSYMBOL_and_expression = 114,           /* and_expression  */
  YYSYMBOL_xor_expression = 115,           /* xor_expression  */
  YYSYMBOL_or_expression = 116,            /* or_expression  */
  YYSYMBOL_logical_and_expression = 117,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 118,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 119,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 120,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 121,      /* assignment_operator  */
  YYSYMBOL_expression = 122,               /* expression  */
  YYSYMBOL_constant_expression = 123,      /* constant_expression  */
  YYSYMBOL_declaration = 124,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 125,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 126,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 127,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 128,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 129,           /* type_specifier  */
  YYSYMBOL_type_qualifier = 130,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 131,       /* function_specifier  */
  YYSYMBOL_struct_or_union_specifier = 132, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 133,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 134,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 135,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 136, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 137,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 138,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 139,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 140,          /* enumerator_list  */
  YYSYMBOL_enumerator = 141,               /* enumerator  */
  YYSYMBOL_declarator = 142,               /* declarator  */
  YYSYMBOL_direct_declarator = 143,        /* direct_declarator  */
  YYSYMBOL_pointer = 144,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 145,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 146,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 147,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 148,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 149,          /* identifier_list  */
  YYSYMBOL_type_name = 150,                /* type_name  */
  YYSYMBOL_abstract_declarator = 151,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 152, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 153               /* initializer  */
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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  63
/* YYNRULES -- Number of rules.  */
#define YYNRULES  196
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  295

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
       2,     2,     2,    81,     2,     2,     2,    83,    76,     2,
      70,    71,    77,    78,    75,    79,    74,    82,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    89,    69,
      84,    90,    85,    88,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    72,     2,    73,    86,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    87,    68,    80,     2,     2,     2,
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
       0,   167,   167,   168,   171,   172,   176,   177,   181,   182,
     186,   187,   191,   192,   196,   197,   203,   204,   209,   210,
     216,   220,   224,   225,   229,   230,   231,   232,   237,   238,
     239,   240,   241,   242,   243,   244,   248,   249,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     268,   269,   273,   274,   275,   276,   280,   281,   282,   286,
     287,   288,   292,   293,   294,   295,   296,   300,   301,   302,
     306,   307,   310,   311,   314,   315,   319,   320,   324,   325,
     329,   330,   334,   335,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   353,   354,   358,   366,   398,
     399,   400,   401,   402,   403,   404,   405,   409,   410,   414,
     415,   420,   421,   422,   423,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   447,   448,
     449,   454,   459,   461,   463,   467,   468,   472,   473,   477,
     481,   482,   483,   484,   488,   489,   493,   494,   495,   501,
     502,   503,   504,   505,   509,   510,   514,   515,   519,   520,
     524,   525,   526,   527,   535,   536,   537,   541,   542,   543,
     544,   548,   549,   553,   554,   558,   559,   563,   564,   565,
     569,   570,   574,   575,   579,   580,   581,   585,   586,   587,
     588,   589,   592,   593,   594,   595,   603
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
  "')'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'",
  "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='",
  "$accept", "external_declaration_list", "external_declaration",
  "function_definition", "declaration_list", "compound_statement",
  "block_item_list", "block_item", "statement", "expression_statement",
  "identifier", "string_literal", "constant", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "xor_expression", "or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "function_specifier", "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-126)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1114,  -126,  -126,  -126,  -126,    48,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   857,  -126,  -126,  -126,   778,  -126,  -126,
    -126,  -126,  -126,    53,  -126,  -126,    26,   -47,  -126,  -126,
       1,   116,  -126,    71,  -126,  -126,  -126,  -126,  -126,   891,
     110,    24,    44,  1180,   -21,   -49,  -126,    26,    43,  -126,
    -126,   116,  -126,     1,   262,   554,  1077,  -126,  -126,   778,
     818,   433,   110,  1180,  -126,  -126,   624,  -126,   199,   554,
    -126,    50,     2,  -126,  -126,  -126,  -126,    47,  -126,  -126,
    -126,   633,   633,   633,   645,  -126,  -126,   420,   554,   554,
     554,   554,   554,   554,  -126,   341,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,    93,   258,  -126,    62,   -34,   164,    12,
     192,    92,   114,    94,   132,    -2,  -126,  -126,    72,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,   738,   127,   129,  -126,
     -41,  -126,   138,  1147,  -126,  -126,   554,  -126,  -126,    95,
    -126,   131,  -126,  -126,  -126,  -126,  -126,  -126,    58,   554,
    -126,  -126,  -126,   420,  -126,    61,  1003,   151,  -126,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,    26,  -126,  -126,   512,
     554,    26,  -126,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,  -126,  -126,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   554,   554,   554,   554,   554,   554,   554,   554,
     554,   554,   554,  -126,   554,   698,   524,  -126,    40,  -126,
     122,  -126,   970,  -126,    26,  -126,  -126,  -126,  -126,    10,
     554,  -126,   152,  -126,   930,   125,  -126,   554,  -126,  -126,
     112,  -126,   126,  -126,  -126,  -126,  -126,  -126,    62,    62,
     -34,   -34,   164,   164,   164,   164,    12,    12,   192,    92,
     114,    94,   132,    54,  -126,  -126,   159,   160,  -126,   161,
     122,  1043,   541,  -126,  -126,  -126,  -126,  -126,  -126,  -126,
    -126,   554,  -126,   554,  -126,  -126,  -126,  -126,   165,  -126,
     162,  -126,  -126,  -126,  -126
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   113,   116,   128,   121,     0,   111,   120,   131,   118,
     119,   114,   129,   117,   122,   112,   135,   136,   123,   115,
     130,   124,   125,     0,     2,     4,     5,     0,   101,    99,
     100,   102,   126,     0,   127,    20,     0,   149,     1,     3,
       0,   167,   160,     0,   107,   105,   103,   104,   106,   109,
     158,     0,   134,     0,   156,     0,   154,     0,     0,   171,
     169,   168,    98,     0,     0,     0,     0,     6,     8,     0,
       0,     0,   159,     0,   140,   142,     0,   137,     0,     0,
     150,     0,     0,   161,   172,   170,   108,   109,    22,    21,
      23,     0,     0,     0,     0,    11,    19,     0,     0,     0,
       0,     0,     0,     0,    16,     0,    12,    15,    17,    24,
      26,    25,    28,    38,    50,    52,    56,    59,    62,    67,
      70,    72,    74,    76,    78,    80,    82,    95,     0,    14,
     196,   110,     7,     9,   166,   180,   178,     0,   173,   175,
       0,   162,     0,     0,   132,   138,     0,   141,   143,     0,
     144,   146,    50,    97,   157,   152,   155,   151,     0,     0,
      39,    40,    49,     0,    47,     0,   182,     0,    41,    42,
      43,    44,    45,    46,    10,    13,     0,    34,    35,     0,
       0,     0,    85,    86,    87,    88,    89,    90,    91,    92,
      94,    93,    84,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,   177,   184,   179,
     185,   164,     0,   165,     0,   163,   133,   147,   139,     0,
       0,   153,     0,    27,     0,   184,   183,     0,    33,    30,
       0,    36,     0,    32,    83,    53,    54,    55,    57,    58,
      60,    61,    64,    66,    63,    65,    68,    69,    71,    73,
      75,    77,    79,     0,    96,   192,     0,     0,   188,     0,
     186,     0,     0,   174,   176,   181,   145,   148,    48,    51,
      31,     0,    29,     0,   194,   187,   189,   193,     0,   190,
       0,    37,    81,   195,   191
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,   215,  -126,  -126,    57,  -126,   135,  -126,  -126,
      -5,  -126,  -126,  -126,  -126,  -126,   -55,   -10,    11,    16,
     -13,    23,    35,    36,    34,    46,    39,  -126,   -78,   -60,
    -126,   -50,  -125,     8,    17,  -126,   190,   -20,    82,     6,
      -9,  -126,  -126,   181,   -48,   -56,  -126,    28,  -126,   205,
     -73,   -15,   -45,   -38,  -126,   -68,  -126,    51,  -126,   109,
    -104,  -101,  -126
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    23,    24,    25,    66,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   240,   152,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     193,   165,   154,    26,   136,    43,    44,    28,    29,    30,
      31,    32,    33,    76,    77,    78,   149,   150,    34,    55,
      56,    58,    50,    51,    61,   266,   138,   139,   140,   167,
     267,   220,   131
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,   153,   137,    60,    35,   130,    72,    45,   156,   114,
     114,   142,    49,    35,   128,   211,   114,    27,    48,    80,
      57,   227,    42,    85,   201,   202,    81,    35,   145,    35,
     223,    54,   219,    47,   224,    42,   160,   161,   162,   164,
      27,   166,   114,    35,   197,   198,    42,    59,    87,    45,
     114,    35,    54,    35,    87,   128,    52,    68,    42,    75,
      48,    35,   236,   151,    42,   135,    69,    84,   153,    79,
     157,    40,   129,    42,   133,    47,    54,   158,    41,    75,
      40,    69,    75,    69,   148,   156,   212,    41,   168,   169,
     170,   171,   172,   173,    40,   145,   203,   204,   218,   146,
     176,   177,   178,    75,   114,   277,    67,   166,   114,    46,
     215,    73,   216,   129,    83,    36,    45,   270,   155,   241,
      53,   217,    69,   132,   114,   114,   231,    48,   235,   214,
     242,    42,   233,   244,   270,    74,   214,    65,   114,   194,
      62,   213,    47,   283,   195,   196,    63,   214,   210,    75,
       3,    46,   153,    54,   264,    74,   269,   114,    74,   114,
     147,   114,   263,   179,   228,   180,    12,   181,   207,    75,
     229,   238,   148,    72,   199,   200,   243,   218,    20,    74,
      70,   209,    71,   280,   245,   246,   247,   281,   252,   253,
     254,   255,   271,    41,   272,   234,   235,   216,   221,   282,
     208,   214,    35,   288,   222,   292,   205,   206,   248,   249,
      42,   225,   290,    42,   151,   250,   251,   114,    46,   275,
     230,   291,   237,   278,    42,    74,   114,   279,   256,   257,
     284,   285,     2,     3,   286,   294,   293,     4,    39,     5,
     175,     7,   258,   260,   259,    74,     9,    10,   147,    12,
     262,    13,    14,    86,   143,    16,   261,   276,    17,    18,
      19,    20,    82,    21,    22,    35,    88,    89,    90,    40,
      91,    92,   232,   274,     0,     0,    41,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,     0,   146,     0,
       0,     1,    93,     0,     0,     2,     3,     0,     0,     0,
       4,     0,     5,     6,     7,     0,     0,     0,     8,     9,
      10,    11,    12,     0,    13,    14,    94,    15,    16,     0,
       0,    17,    18,    19,    20,     0,    21,    22,     0,    64,
      95,    96,    97,     0,     0,     0,     0,     0,    98,    99,
     100,   101,   102,   103,    35,    88,    89,    90,   192,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,    93,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,    94,    15,    16,     0,     0,
      17,    18,    19,    20,     0,    21,    22,     0,    64,   174,
      96,    97,     0,     0,     0,     0,     0,    98,    99,   100,
     101,   102,   103,    35,    88,    89,    90,     0,    91,    92,
       0,     0,     0,     0,     0,     0,    35,    88,    89,    90,
       0,    91,    92,     0,     0,     0,     0,     0,     0,     0,
      93,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     0,     7,    93,     0,     0,     0,     9,    10,     0,
      12,     0,    13,    14,    94,     0,    16,     0,     0,    17,
      18,    19,    20,     0,    21,    22,     0,    94,     0,     0,
      97,     0,     0,     0,     0,     0,    98,    99,   100,   101,
     102,   103,     0,    97,     0,     0,   141,     0,     0,    98,
      99,   100,   101,   102,   103,    35,    88,    89,    90,     0,
      91,    92,     0,     0,     0,     0,     0,    35,    88,    89,
      90,     0,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,    93,     0,    35,    88,    89,    90,     0,    91,
      92,     0,     0,     0,    93,     0,     0,    35,    88,    89,
      90,     0,    91,    92,     0,     0,    94,     0,     0,     0,
       0,    93,     0,     0,     0,     0,     0,     0,    94,     0,
       0,     0,    97,   239,    93,     0,     0,     0,    98,    99,
     100,   101,   102,   103,    97,    94,     0,   268,     0,     0,
      98,    99,   100,   101,   102,   103,     0,     0,    94,     0,
       0,    97,     0,     0,   289,     0,     0,    98,    99,   100,
     101,   102,   103,     0,    97,     0,     0,     0,     0,     0,
      98,    99,   100,   101,   102,   103,    35,    88,    89,    90,
       0,    91,    92,     0,     0,     0,     0,     0,    35,    88,
      89,    90,     0,    91,    92,     0,     0,     2,     3,     0,
       0,     0,     4,    93,     5,     0,     7,     0,     0,     0,
       0,     9,    10,     0,    12,    93,    13,    14,     0,     0,
      16,     0,     0,    17,    18,    19,    20,    94,    21,    22,
       0,     0,   144,     0,     0,     0,     0,     0,     0,    94,
       0,    35,     0,   159,     0,     0,     0,     0,     0,    98,
      99,   100,   101,   102,   103,   163,     0,     0,     0,     0,
       0,    98,    99,   100,   101,   102,   103,     1,     0,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,    35,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,    16,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     1,   215,   265,
     216,     2,     3,     0,     0,    41,     4,     0,     5,     6,
       7,    35,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,    16,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     1,   215,     0,
     216,     2,     3,     0,     0,    41,     4,     0,     5,     6,
       7,    35,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,    16,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     0,     0,     0,     1,    40,     0,
       0,     2,     3,     0,     0,    41,     4,    38,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,    16,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     0,     0,     1,     0,     0,   134,
       2,     3,     0,     0,     0,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,    16,     0,     0,    17,    18,    19,    20,
       1,    21,    22,     0,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,    16,     0,     0,
      17,    18,    19,    20,     0,    21,    22,     0,    64,     1,
       0,     0,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,    65,    13,    14,     0,    15,    16,     0,   273,    17,
      18,    19,    20,     0,    21,    22,     0,     0,     0,     1,
     234,   265,   216,     2,     3,     0,     0,    41,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,    16,     0,     0,    17,
      18,    19,    20,     0,    21,    22,     2,     3,     0,     0,
       0,     4,     0,     5,     0,     7,     0,     0,     0,     0,
       9,    10,     0,    12,     0,    13,    14,     0,     0,    16,
       0,     0,    17,    18,    19,    20,     0,    21,    22,     0,
       0,     0,     1,   234,     0,   216,     2,     3,     0,     0,
      41,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,    16,
       0,     0,    17,    18,    19,    20,     1,    21,    22,     0,
       2,     3,     0,     0,   287,     4,     0,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,    16,     0,     0,    17,    18,    19,    20,
       0,    21,    22,     1,    64,     0,     0,     2,     3,     0,
       0,     0,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
      16,     0,     0,    17,    18,    19,    20,     0,    21,    22,
       2,     3,     0,     0,     0,     4,     0,     5,     0,     7,
       0,     0,     0,     0,     9,    10,     0,    12,     0,    13,
      14,     0,     0,    16,     0,     0,    17,    18,    19,    20,
       0,    21,    22,     2,     3,   226,     0,     0,     4,     0,
       5,     0,     7,     0,     0,     0,     0,     9,    10,     0,
      12,     0,    13,    14,     0,     0,    16,     0,     0,    17,
      18,    19,    20,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
       5,    79,    70,    41,     3,    65,    51,    27,    81,    64,
      65,    71,    27,     3,    64,    17,    71,     0,    27,    68,
      67,   146,    27,    61,    12,    13,    75,     3,    76,     3,
      71,    36,   136,    27,    75,    40,    91,    92,    93,    94,
      23,    97,    97,     3,    78,    79,    51,    41,    63,    69,
     105,     3,    57,     3,    69,   105,     3,    49,    63,    53,
      69,     3,   166,    78,    69,    70,    49,    61,   146,    90,
      68,    70,    64,    78,    66,    69,    81,    75,    77,    73,
      70,    64,    76,    66,    78,   158,    88,    77,    98,    99,
     100,   101,   102,   103,    70,   143,    84,    85,   136,    89,
       7,     8,     9,    97,   159,   230,    49,   163,   163,    27,
      70,    67,    72,   105,    71,    67,   136,   218,    68,   179,
      67,   136,   105,    66,   179,   180,    68,   136,   166,    75,
     180,   136,    71,   193,   235,    53,    75,    90,   193,    77,
      69,    69,   136,    89,    82,    83,    75,    75,    16,   143,
      34,    69,   230,   158,   214,    73,   216,   212,    76,   214,
      78,   216,   212,    70,    69,    72,    50,    74,    76,   163,
      75,   176,   166,   218,    10,    11,   181,   215,    62,    97,
      70,    87,    72,    71,   194,   195,   196,    75,   201,   202,
     203,   204,    70,    77,    72,    70,   234,    72,    71,    73,
      86,    75,     3,   271,    75,   283,    14,    15,   197,   198,
     215,    73,   272,   218,   229,   199,   200,   272,   136,   224,
      89,   281,    71,    71,   229,   143,   281,   237,   205,   206,
      71,    71,    33,    34,    73,    73,    71,    38,    23,    40,
     105,    42,   207,   209,   208,   163,    47,    48,   166,    50,
     211,    52,    53,    63,    73,    56,   210,   229,    59,    60,
      61,    62,    57,    64,    65,     3,     4,     5,     6,    70,
       8,     9,   163,   222,    -1,    -1,    77,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    89,    -1,
      -1,    29,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,
      38,    -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    55,    56,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    65,    -1,    67,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,     3,     4,     5,     6,    90,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65,    -1,    67,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      40,    -1,    42,    30,    -1,    -1,    -1,    47,    48,    -1,
      50,    -1,    52,    53,    54,    -1,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65,    -1,    54,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    -1,    70,    -1,    -1,    73,    -1,    -1,    76,
      77,    78,    79,    80,    81,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    30,    -1,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    54,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,
      -1,    -1,    70,    71,    30,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    70,    54,    -1,    73,    -1,    -1,
      76,    77,    78,    79,    80,    81,    -1,    -1,    54,    -1,
      -1,    70,    -1,    -1,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      76,    77,    78,    79,    80,    81,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    33,    34,    -1,
      -1,    -1,    38,    30,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    48,    -1,    50,    30,    52,    53,    -1,    -1,
      56,    -1,    -1,    59,    60,    61,    62,    54,    64,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      -1,     3,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    70,    -1,    -1,    -1,    -1,
      -1,    76,    77,    78,    79,    80,    81,    29,    -1,    -1,
      -1,    33,    34,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,     3,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    -1,    -1,    -1,    29,    70,    71,
      72,    33,    34,    -1,    -1,    77,    38,    -1,    40,    41,
      42,     3,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    -1,    -1,    -1,    29,    70,    -1,
      72,    33,    34,    -1,    -1,    77,    38,    -1,    40,    41,
      42,     3,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    -1,    -1,    -1,    29,    70,    -1,
      -1,    33,    34,    -1,    -1,    77,    38,     0,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    -1,    -1,    29,    -1,    -1,    71,
      33,    34,    -1,    -1,    -1,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      29,    64,    65,    -1,    33,    34,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65,    -1,    67,    29,
      -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    90,    52,    53,    -1,    55,    56,    -1,    18,    59,
      60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,    29,
      70,    71,    72,    33,    34,    -1,    -1,    77,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65,    33,    34,    -1,    -1,
      -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,
      47,    48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,
      -1,    -1,    59,    60,    61,    62,    -1,    64,    65,    -1,
      -1,    -1,    29,    70,    -1,    72,    33,    34,    -1,    -1,
      77,    38,    -1,    40,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    59,    60,    61,    62,    29,    64,    65,    -1,
      33,    34,    -1,    -1,    71,    38,    -1,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    29,    67,    -1,    -1,    33,    34,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    59,    60,    61,    62,    -1,    64,    65,
      33,    34,    -1,    -1,    -1,    38,    -1,    40,    -1,    42,
      -1,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,
      53,    -1,    -1,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    33,    34,    68,    -1,    -1,    38,    -1,
      40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,
      50,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    33,    34,    38,    40,    41,    42,    46,    47,
      48,    49,    50,    52,    53,    55,    56,    59,    60,    61,
      62,    64,    65,    92,    93,    94,   124,   125,   128,   129,
     130,   131,   132,   133,   139,     3,    67,   101,     0,    93,
      70,    77,   101,   126,   127,   128,   129,   130,   131,   142,
     143,   144,     3,    67,   101,   140,   141,    67,   142,   130,
     144,   145,    69,    75,    67,    90,    95,    96,   124,   125,
      70,    72,   143,    67,   129,   130,   134,   135,   136,    90,
      68,    75,   140,    71,   130,   144,   127,   142,     4,     5,
       6,     8,     9,    30,    54,    68,    69,    70,    76,    77,
      78,    79,    80,    81,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   122,   124,
     120,   153,    96,   124,    71,   101,   125,   146,   147,   148,
     149,    73,   120,   134,    68,   135,    89,   129,   130,   137,
     138,   142,   107,   119,   123,    68,   141,    68,    75,    70,
     107,   107,   107,    70,   107,   122,   136,   150,   108,   108,
     108,   108,   108,   108,    68,    98,     7,     8,     9,    70,
      72,    74,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    90,   121,    77,    82,    83,    78,    79,    10,
      11,    12,    13,    84,    85,    14,    15,    76,    86,    87,
      16,    17,    88,    69,    75,    70,    72,   142,   144,   151,
     152,    71,    75,    71,    75,    73,    68,   123,    69,    75,
      89,    68,   150,    71,    70,   144,   151,    71,   101,    71,
     106,   120,   122,   101,   120,   108,   108,   108,   109,   109,
     110,   110,   111,   111,   111,   111,   112,   112,   113,   114,
     115,   116,   117,   122,   120,    71,   146,   151,    73,   120,
     152,    70,    72,    18,   148,   101,   138,   123,    71,   108,
      71,    75,    73,    89,    71,    71,    73,    71,   146,    73,
     120,   120,   119,    71,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     101,   102,   103,   103,   104,   104,   104,   104,   105,   105,
     105,   105,   105,   105,   105,   105,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     108,   108,   109,   109,   109,   109,   110,   110,   110,   111,
     111,   111,   112,   112,   112,   112,   112,   113,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,   122,   122,   123,   124,   125,
     125,   125,   125,   125,   125,   125,   125,   126,   126,   127,
     127,   128,   128,   128,   128,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   130,   130,
     130,   131,   132,   132,   132,   133,   133,   134,   134,   135,
     136,   136,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   139,   139,   139,   140,   140,   141,   141,   142,   142,
     143,   143,   143,   143,   143,   143,   143,   144,   144,   144,
     144,   145,   145,   146,   146,   147,   147,   148,   148,   148,
     149,   149,   150,   150,   151,   151,   151,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   153
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     4,     1,     2,
       3,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     4,
       3,     4,     3,     3,     2,     2,     1,     3,     1,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     2,
       1,     4,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     5,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     5,     2,     1,     1,     1,     2,     3,
       1,     2,     1,     2,     1,     3,     1,     2,     3,     2,
       4,     5,     5,     6,     1,     3,     1,     3,     1,     2,
       1,     3,     3,     4,     4,     4,     3,     1,     2,     2,
       3,     1,     2,     1,     3,     1,     3,     2,     1,     2,
       1,     3,     1,     2,     1,     1,     2,     3,     2,     3,
       3,     4,     2,     3,     3,     4,     1
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
  switch (yykind)
    {
    case YYSYMBOL_IDENT: /* IDENT  */
#line 162 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1395 "parser.tab.c"
        break;

    case YYSYMBOL_CHARLIT: /* CHARLIT  */
#line 162 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1401 "parser.tab.c"
        break;

    case YYSYMBOL_STRINGLIT: /* STRINGLIT  */
#line 162 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1407 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBERLIT: /* NUMBERLIT  */
#line 161 "parser.y"
            { }
#line 1413 "parser.tab.c"
        break;

    case YYSYMBOL_identifier: /* identifier  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1419 "parser.tab.c"
        break;

    case YYSYMBOL_string_literal: /* string_literal  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1425 "parser.tab.c"
        break;

    case YYSYMBOL_constant: /* constant  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1431 "parser.tab.c"
        break;

    case YYSYMBOL_primary_expression: /* primary_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1437 "parser.tab.c"
        break;

    case YYSYMBOL_postfix_expression: /* postfix_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1443 "parser.tab.c"
        break;

    case YYSYMBOL_unary_expression: /* unary_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1449 "parser.tab.c"
        break;

    case YYSYMBOL_cast_expression: /* cast_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1455 "parser.tab.c"
        break;

    case YYSYMBOL_multiplicative_expression: /* multiplicative_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1461 "parser.tab.c"
        break;

    case YYSYMBOL_additive_expression: /* additive_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1467 "parser.tab.c"
        break;

    case YYSYMBOL_shift_expression: /* shift_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1473 "parser.tab.c"
        break;

    case YYSYMBOL_relational_expression: /* relational_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1479 "parser.tab.c"
        break;

    case YYSYMBOL_equality_expression: /* equality_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1485 "parser.tab.c"
        break;

    case YYSYMBOL_and_expression: /* and_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1491 "parser.tab.c"
        break;

    case YYSYMBOL_xor_expression: /* xor_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1497 "parser.tab.c"
        break;

    case YYSYMBOL_or_expression: /* or_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1503 "parser.tab.c"
        break;

    case YYSYMBOL_logical_and_expression: /* logical_and_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1509 "parser.tab.c"
        break;

    case YYSYMBOL_logical_or_expression: /* logical_or_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1515 "parser.tab.c"
        break;

    case YYSYMBOL_conditional_expression: /* conditional_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1521 "parser.tab.c"
        break;

    case YYSYMBOL_assignment_expression: /* assignment_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1527 "parser.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1533 "parser.tab.c"
        break;

    case YYSYMBOL_constant_expression: /* constant_expression  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1539 "parser.tab.c"
        break;

    case YYSYMBOL_struct_or_union_specifier: /* struct_or_union_specifier  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1545 "parser.tab.c"
        break;

    case YYSYMBOL_enum_specifier: /* enum_specifier  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1551 "parser.tab.c"
        break;

    case YYSYMBOL_initializer: /* initializer  */
#line 163 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1557 "parser.tab.c"
        break;

      default:
        break;
    }
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
#line 20 "parser.y"
{
    st_top = st_new(0);
}

#line 1633 "parser.tab.c"

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
  case 18: /* expression_statement: expression ';'  */
#line 209 "parser.y"
                   {ast_print((yyvsp[-1].node), 0);}
#line 1836 "parser.tab.c"
    break;

  case 20: /* identifier: IDENT  */
#line 216 "parser.y"
          {(yyval.node) = ast_new_ident((yyvsp[0].string).buffer);}
#line 1842 "parser.tab.c"
    break;

  case 21: /* string_literal: STRINGLIT  */
#line 220 "parser.y"
              {(yyval.node) = ast_new_stringlit((yyvsp[0].string));}
#line 1848 "parser.tab.c"
    break;

  case 22: /* constant: CHARLIT  */
#line 224 "parser.y"
            {(yyval.node) = ast_new_charlit((yyvsp[0].string).buffer[0]);}
#line 1854 "parser.tab.c"
    break;

  case 23: /* constant: NUMBERLIT  */
#line 225 "parser.y"
                {(yyval.node) = ast_new_numberlit((yyvsp[0].number));}
#line 1860 "parser.tab.c"
    break;

  case 27: /* primary_expression: '(' expression ')'  */
#line 232 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 1866 "parser.tab.c"
    break;

  case 29: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 238 "parser.y"
                                            {(yyval.node) = ast_new_unary_op('*', ast_new_binary_op('+', (yyvsp[-3].node), (yyvsp[-1].node)));}
#line 1872 "parser.tab.c"
    break;

  case 30: /* postfix_expression: postfix_expression '(' ')'  */
#line 239 "parser.y"
                                 {(yyval.node) = ast_new_function_call((yyvsp[-2].node), ast_list_new());}
#line 1878 "parser.tab.c"
    break;

  case 31: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 240 "parser.y"
                                                          {(yyval.node) = ast_new_function_call((yyvsp[-3].node), (yyvsp[-1].node_list));}
#line 1884 "parser.tab.c"
    break;

  case 32: /* postfix_expression: postfix_expression '.' identifier  */
#line 241 "parser.y"
                                        {(yyval.node) = ast_new_binary_op('.', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1890 "parser.tab.c"
    break;

  case 33: /* postfix_expression: postfix_expression "->" identifier  */
#line 242 "parser.y"
                                         {(yyval.node) = ast_new_binary_op('.', ast_new_unary_op('*', (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1896 "parser.tab.c"
    break;

  case 34: /* postfix_expression: postfix_expression "++"  */
#line 243 "parser.y"
                              {(yyval.node) = ast_new_unary_op(PLUSPLUS, (yyvsp[-1].node));}
#line 1902 "parser.tab.c"
    break;

  case 35: /* postfix_expression: postfix_expression "--"  */
#line 244 "parser.y"
                              {(yyval.node) = ast_new_unary_op(MINUSMINUS, (yyvsp[-1].node));}
#line 1908 "parser.tab.c"
    break;

  case 36: /* argument_expression_list: assignment_expression  */
#line 248 "parser.y"
                          {(yyval.node_list) = ast_list_add(ast_list_new(), (yyvsp[0].node));}
#line 1914 "parser.tab.c"
    break;

  case 37: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 249 "parser.y"
                                                         {(yyval.node_list) = ast_list_add((yyvsp[-2].node_list), (yyvsp[0].node));}
#line 1920 "parser.tab.c"
    break;

  case 39: /* unary_expression: "++" unary_expression  */
#line 254 "parser.y"
                            {(yyval.node) = ast_new_binary_op(PLUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 1926 "parser.tab.c"
    break;

  case 40: /* unary_expression: "--" unary_expression  */
#line 255 "parser.y"
                            {(yyval.node) = ast_new_binary_op(MINUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 1932 "parser.tab.c"
    break;

  case 41: /* unary_expression: '&' cast_expression  */
#line 256 "parser.y"
                          {(yyval.node) = ast_new_unary_op('&', (yyvsp[0].node));}
#line 1938 "parser.tab.c"
    break;

  case 42: /* unary_expression: '*' cast_expression  */
#line 257 "parser.y"
                          {(yyval.node) = ast_new_unary_op('*', (yyvsp[0].node));}
#line 1944 "parser.tab.c"
    break;

  case 43: /* unary_expression: '+' cast_expression  */
#line 258 "parser.y"
                          {(yyval.node) = ast_new_unary_op('+', (yyvsp[0].node));}
#line 1950 "parser.tab.c"
    break;

  case 44: /* unary_expression: '-' cast_expression  */
#line 259 "parser.y"
                          {(yyval.node) = ast_new_unary_op('-', (yyvsp[0].node));}
#line 1956 "parser.tab.c"
    break;

  case 45: /* unary_expression: '~' cast_expression  */
#line 260 "parser.y"
                          {(yyval.node) = ast_new_unary_op('~', (yyvsp[0].node));}
#line 1962 "parser.tab.c"
    break;

  case 46: /* unary_expression: '!' cast_expression  */
#line 261 "parser.y"
                          {(yyval.node) = ast_new_unary_op('!', (yyvsp[0].node));}
#line 1968 "parser.tab.c"
    break;

  case 47: /* unary_expression: SIZEOF unary_expression  */
#line 262 "parser.y"
                              {(yyval.node) = ast_new_unary_op(SIZEOF, (yyvsp[0].node));}
#line 1974 "parser.tab.c"
    break;

  case 49: /* unary_expression: ALIGNOF unary_expression  */
#line 264 "parser.y"
                               {(yyval.node) = ast_new_unary_op(ALIGNOF, (yyvsp[0].node));}
#line 1980 "parser.tab.c"
    break;

  case 53: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 274 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op('*', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1986 "parser.tab.c"
    break;

  case 54: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 275 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op('/', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1992 "parser.tab.c"
    break;

  case 55: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 276 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op('%', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1998 "parser.tab.c"
    break;

  case 57: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 281 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('+', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2004 "parser.tab.c"
    break;

  case 58: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 282 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('-', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2010 "parser.tab.c"
    break;

  case 60: /* shift_expression: shift_expression "<<" additive_expression  */
#line 287 "parser.y"
                                                {(yyval.node) = ast_new_binary_op(SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2016 "parser.tab.c"
    break;

  case 61: /* shift_expression: shift_expression ">>" additive_expression  */
#line 288 "parser.y"
                                                {(yyval.node) = ast_new_binary_op(SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2022 "parser.tab.c"
    break;

  case 63: /* relational_expression: relational_expression '<' shift_expression  */
#line 293 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('<', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2028 "parser.tab.c"
    break;

  case 64: /* relational_expression: relational_expression "<=" shift_expression  */
#line 294 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2034 "parser.tab.c"
    break;

  case 65: /* relational_expression: relational_expression '>' shift_expression  */
#line 295 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('>', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2040 "parser.tab.c"
    break;

  case 66: /* relational_expression: relational_expression ">=" shift_expression  */
#line 296 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2046 "parser.tab.c"
    break;

  case 68: /* equality_expression: equality_expression "==" relational_expression  */
#line 301 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op(EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2052 "parser.tab.c"
    break;

  case 69: /* equality_expression: equality_expression "!=" relational_expression  */
#line 302 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op(NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2058 "parser.tab.c"
    break;

  case 71: /* and_expression: and_expression '&' equality_expression  */
#line 307 "parser.y"
                                             {(yyval.node) = ast_new_binary_op('&', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2064 "parser.tab.c"
    break;

  case 73: /* xor_expression: xor_expression '^' and_expression  */
#line 311 "parser.y"
                                        {(yyval.node) = ast_new_binary_op('^', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2070 "parser.tab.c"
    break;

  case 75: /* or_expression: or_expression '|' xor_expression  */
#line 315 "parser.y"
                                       {(yyval.node) = ast_new_binary_op('|', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2076 "parser.tab.c"
    break;

  case 77: /* logical_and_expression: logical_and_expression "&&" or_expression  */
#line 320 "parser.y"
                                                {(yyval.node) = ast_new_binary_op(LOGAND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2082 "parser.tab.c"
    break;

  case 79: /* logical_or_expression: logical_or_expression "||" logical_and_expression  */
#line 325 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op(LOGOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2088 "parser.tab.c"
    break;

  case 81: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 330 "parser.y"
                                                                      {(yyval.node) = ast_new_ternary_op((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2094 "parser.tab.c"
    break;

  case 83: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 335 "parser.y"
                                                                 {(yyval.node) = ast_new_binary_op((yyvsp[-1].integer), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2100 "parser.tab.c"
    break;

  case 84: /* assignment_operator: '='  */
#line 339 "parser.y"
        {(yyval.integer) = '=';}
#line 2106 "parser.tab.c"
    break;

  case 85: /* assignment_operator: "*="  */
#line 340 "parser.y"
           {(yyval.integer) = PLUSEQ;}
#line 2112 "parser.tab.c"
    break;

  case 86: /* assignment_operator: "/="  */
#line 341 "parser.y"
           {(yyval.integer) = MINUSEQ;}
#line 2118 "parser.tab.c"
    break;

  case 87: /* assignment_operator: "%="  */
#line 342 "parser.y"
           {(yyval.integer) = TIMESEQ;}
#line 2124 "parser.tab.c"
    break;

  case 88: /* assignment_operator: "+="  */
#line 343 "parser.y"
           {(yyval.integer) = DIVEQ;}
#line 2130 "parser.tab.c"
    break;

  case 89: /* assignment_operator: "-="  */
#line 344 "parser.y"
           {(yyval.integer) = MODEQ;}
#line 2136 "parser.tab.c"
    break;

  case 90: /* assignment_operator: "<<="  */
#line 345 "parser.y"
            {(yyval.integer) = SHLEQ;}
#line 2142 "parser.tab.c"
    break;

  case 91: /* assignment_operator: ">>="  */
#line 346 "parser.y"
            {(yyval.integer) = SHREQ;}
#line 2148 "parser.tab.c"
    break;

  case 92: /* assignment_operator: "&="  */
#line 347 "parser.y"
           {(yyval.integer) = ANDEQ;}
#line 2154 "parser.tab.c"
    break;

  case 93: /* assignment_operator: "^="  */
#line 348 "parser.y"
           {(yyval.integer) = XOREQ;}
#line 2160 "parser.tab.c"
    break;

  case 94: /* assignment_operator: "|="  */
#line 349 "parser.y"
           {(yyval.integer) = OREQ;}
#line 2166 "parser.tab.c"
    break;

  case 96: /* expression: expression ',' assignment_expression  */
#line 354 "parser.y"
                                           {(yyval.node) = ast_new_binary_op(',', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2172 "parser.tab.c"
    break;

  case 98: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 367 "parser.y"
    {
        if ((yyvsp[-2].declaration_specifiers).type_specifier.scalar.full == 0)
        {
            fprintf(stderr, "%s:%d: Warning: declaration with no type specifiers treated as int\n", filename, line_num);
            (yyvsp[-2].declaration_specifiers).type_specifier.scalar.full |= TS_INT;
            goto ts_check_continue;
        }
        for (int i = 0, j = sizeof(TS_VALID) / sizeof(*TS_VALID); i < j; i++)
            if ((yyvsp[-2].declaration_specifiers).type_specifier.scalar.full == TS_VALID[i])
                goto ts_check_continue;
        fprintf(stderr, "%s:%d: Error: invalid combination of type specifiers\n", filename, line_num);
        exit(80);
    ts_check_continue:

        ast_node_t *end_scalar = ast_new_scalar((yyvsp[-2].declaration_specifiers).type_specifier, (yyvsp[-2].declaration_specifiers).type_qualifier);

        for (int i = 0; i < (yyvsp[-1].declarator_list).declarator_count ; i++)
        {
            ast_node_t *var = ast_ident_to_variable((yyvsp[-1].declarator_list).declarators[i].oldest, (yyvsp[-2].declaration_specifiers).storage_class);   
            if (st_find(0, var->ident))
            {
                fprintf(stderr, "%s:%d: Error: variable `%s` has already been declared\n", filename, line_num, var->ident);
                exit(80);
            }
            st_add(var);
            (yyvsp[-1].declarator_list).declarators[i].newest->next = end_scalar;
        }
    }
#line 2205 "parser.tab.c"
    break;

  case 99: /* declaration_specifiers: type_specifier  */
#line 398 "parser.y"
                   {ds_init(&(yyval.declaration_specifiers)); ds_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2211 "parser.tab.c"
    break;

  case 100: /* declaration_specifiers: type_qualifier  */
#line 399 "parser.y"
                     {ds_init(&(yyval.declaration_specifiers)); ds_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2217 "parser.tab.c"
    break;

  case 101: /* declaration_specifiers: storage_class_specifier  */
#line 400 "parser.y"
                              {ds_init(&(yyval.declaration_specifiers)); ds_add_storage_class(&(yyval.declaration_specifiers), (yyvsp[0].storage_class_specifier));}
#line 2223 "parser.tab.c"
    break;

  case 102: /* declaration_specifiers: function_specifier  */
#line 401 "parser.y"
                         {ds_init(&(yyval.declaration_specifiers)); ds_add_function_specifier(&(yyval.declaration_specifiers), (yyvsp[0].function_specifier));}
#line 2229 "parser.tab.c"
    break;

  case 103: /* declaration_specifiers: declaration_specifiers type_specifier  */
#line 402 "parser.y"
                                            {ds_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2235 "parser.tab.c"
    break;

  case 104: /* declaration_specifiers: declaration_specifiers type_qualifier  */
#line 403 "parser.y"
                                            {ds_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2241 "parser.tab.c"
    break;

  case 105: /* declaration_specifiers: declaration_specifiers storage_class_specifier  */
#line 404 "parser.y"
                                                     {ds_add_storage_class(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].storage_class_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2247 "parser.tab.c"
    break;

  case 106: /* declaration_specifiers: declaration_specifiers function_specifier  */
#line 405 "parser.y"
                                                {ds_add_function_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].function_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2253 "parser.tab.c"
    break;

  case 107: /* init_declarator_list: init_declarator  */
#line 409 "parser.y"
                    {dl_init(&(yyval.declarator_list)); dl_add(&(yyval.declarator_list), (yyvsp[0].declarator_helper));}
#line 2259 "parser.tab.c"
    break;

  case 108: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 410 "parser.y"
                                               {dl_add(&(yyvsp[-2].declarator_list), (yyvsp[0].declarator_helper)); (yyval.declarator_list) = (yyvsp[-2].declarator_list);}
#line 2265 "parser.tab.c"
    break;

  case 109: /* init_declarator: declarator  */
#line 414 "parser.y"
               {(yyvsp[0].declarator_helper).initializer = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2271 "parser.tab.c"
    break;

  case 110: /* init_declarator: declarator '=' initializer  */
#line 415 "parser.y"
                                 {(yyvsp[-2].declarator_helper).initializer = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 2277 "parser.tab.c"
    break;

  case 111: /* storage_class_specifier: EXTERN  */
#line 420 "parser.y"
           {(yyval.storage_class_specifier) = SC_EXTERN;}
#line 2283 "parser.tab.c"
    break;

  case 112: /* storage_class_specifier: STATIC  */
#line 421 "parser.y"
             {(yyval.storage_class_specifier) = SC_STATIC;}
#line 2289 "parser.tab.c"
    break;

  case 113: /* storage_class_specifier: AUTO  */
#line 422 "parser.y"
           {(yyval.storage_class_specifier) = SC_AUTO;}
#line 2295 "parser.tab.c"
    break;

  case 114: /* storage_class_specifier: REGISTER  */
#line 423 "parser.y"
               {(yyval.storage_class_specifier) = SC_REGISTER;}
#line 2301 "parser.tab.c"
    break;

  case 115: /* type_specifier: VOID  */
#line 429 "parser.y"
         {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_VOID};}
#line 2307 "parser.tab.c"
    break;

  case 116: /* type_specifier: CHAR  */
#line 430 "parser.y"
           {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_CHAR};}
#line 2313 "parser.tab.c"
    break;

  case 117: /* type_specifier: SHORT  */
#line 431 "parser.y"
            {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SHORT};}
#line 2319 "parser.tab.c"
    break;

  case 118: /* type_specifier: INT  */
#line 432 "parser.y"
          {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_INT};}
#line 2325 "parser.tab.c"
    break;

  case 119: /* type_specifier: LONG  */
#line 433 "parser.y"
           {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_LONG};}
#line 2331 "parser.tab.c"
    break;

  case 120: /* type_specifier: FLOAT  */
#line 434 "parser.y"
            {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_FLOAT};}
#line 2337 "parser.tab.c"
    break;

  case 121: /* type_specifier: DOUBLE  */
#line 435 "parser.y"
             {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_DOUBLE};}
#line 2343 "parser.tab.c"
    break;

  case 122: /* type_specifier: SIGNED  */
#line 436 "parser.y"
             {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SIGNED};}
#line 2349 "parser.tab.c"
    break;

  case 123: /* type_specifier: UNSIGNED  */
#line 437 "parser.y"
               {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_UNSIGNED};}
#line 2355 "parser.tab.c"
    break;

  case 124: /* type_specifier: _BOOL  */
#line 438 "parser.y"
            {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_BOOL};}
#line 2361 "parser.tab.c"
    break;

  case 125: /* type_specifier: _COMPLEX  */
#line 439 "parser.y"
               {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_COMPLEX};}
#line 2367 "parser.tab.c"
    break;

  case 126: /* type_specifier: struct_or_union_specifier  */
#line 440 "parser.y"
                                {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_STRUCT_OR_UNION, .custom = (yyvsp[0].node)};}
#line 2373 "parser.tab.c"
    break;

  case 127: /* type_specifier: enum_specifier  */
#line 441 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_ENUM, .custom = (yyvsp[0].node)};}
#line 2379 "parser.tab.c"
    break;

  case 128: /* type_qualifier: CONST  */
#line 447 "parser.y"
          {(yyval.type_qualifier) = TQ_CONST;}
#line 2385 "parser.tab.c"
    break;

  case 129: /* type_qualifier: RESTRICT  */
#line 448 "parser.y"
               {(yyval.type_qualifier) = TQ_RESTRICT;}
#line 2391 "parser.tab.c"
    break;

  case 130: /* type_qualifier: VOLATILE  */
#line 449 "parser.y"
               {(yyval.type_qualifier) = TQ_VOLATILE;}
#line 2397 "parser.tab.c"
    break;

  case 131: /* function_specifier: INLINE  */
#line 454 "parser.y"
           {(yyval.function_specifier) = FS_INLINE;}
#line 2403 "parser.tab.c"
    break;

  case 135: /* struct_or_union: STRUCT  */
#line 467 "parser.y"
           {(yyval.integer) = AST_STRUCT;}
#line 2409 "parser.tab.c"
    break;

  case 136: /* struct_or_union: UNION  */
#line 468 "parser.y"
            {(yyval.integer) = AST_UNION;}
#line 2415 "parser.tab.c"
    break;

  case 158: /* declarator: direct_declarator  */
#line 519 "parser.y"
                      {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2421 "parser.tab.c"
    break;

  case 159: /* declarator: pointer direct_declarator  */
#line 520 "parser.y"
                                {(yyvsp[0].declarator_helper).newest = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2427 "parser.tab.c"
    break;

  case 160: /* direct_declarator: identifier  */
#line 524 "parser.y"
               {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = (yyvsp[0].node);}
#line 2433 "parser.tab.c"
    break;

  case 161: /* direct_declarator: '(' declarator ')'  */
#line 525 "parser.y"
                         {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2439 "parser.tab.c"
    break;

  case 162: /* direct_declarator: direct_declarator '[' ']'  */
#line 526 "parser.y"
                                {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2445 "parser.tab.c"
    break;

  case 163: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 527 "parser.y"
                                                      {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2451 "parser.tab.c"
    break;

  case 164: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 535 "parser.y"
                                                    {fprintf(stderr, "dd12\n");}
#line 2457 "parser.tab.c"
    break;

  case 165: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 536 "parser.y"
                                                {fprintf(stderr, "dd13\n");}
#line 2463 "parser.tab.c"
    break;

  case 166: /* direct_declarator: direct_declarator '(' ')'  */
#line 537 "parser.y"
                                {fprintf(stderr, "dd14\n");}
#line 2469 "parser.tab.c"
    break;

  case 167: /* pointer: '*'  */
#line 541 "parser.y"
        {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer(0);}
#line 2475 "parser.tab.c"
    break;

  case 168: /* pointer: '*' type_qualifier_list  */
#line 542 "parser.y"
                              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer((yyvsp[0].type_qualifier));}
#line 2481 "parser.tab.c"
    break;

  case 169: /* pointer: '*' pointer  */
#line 543 "parser.y"
                  {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer(0); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2487 "parser.tab.c"
    break;

  case 170: /* pointer: '*' type_qualifier_list pointer  */
#line 544 "parser.y"
                                      {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer((yyvsp[-1].type_qualifier)); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2493 "parser.tab.c"
    break;

  case 171: /* type_qualifier_list: type_qualifier  */
#line 548 "parser.y"
                   {(yyval.type_qualifier) = (yyvsp[0].type_qualifier);}
#line 2499 "parser.tab.c"
    break;

  case 172: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 549 "parser.y"
                                         {(yyval.type_qualifier) |= (yyvsp[-1].type_qualifier);}
#line 2505 "parser.tab.c"
    break;

  case 187: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 585 "parser.y"
                                {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2511 "parser.tab.c"
    break;

  case 188: /* direct_abstract_declarator: '[' ']'  */
#line 586 "parser.y"
              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array(0);}
#line 2517 "parser.tab.c"
    break;

  case 189: /* direct_abstract_declarator: '[' assignment_expression ']'  */
#line 587 "parser.y"
                                    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array((yyvsp[-1].node));}
#line 2523 "parser.tab.c"
    break;


#line 2527 "parser.tab.c"

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

#line 606 "parser.y"

