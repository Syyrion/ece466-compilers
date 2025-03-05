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

    // what the hell is happening

    #include <stdlib.h>
    #include <stdio.h>
    #include "lexer.h"
    #include "ast.h"

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s:%d: %s\n", filename, line_num, s);
    }


#line 86 "parser.tab.c"

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
  YYSYMBOL_external_declaration = 92,      /* external_declaration  */
  YYSYMBOL_function_definition = 93,       /* function_definition  */
  YYSYMBOL_compound_statement = 94,        /* compound_statement  */
  YYSYMBOL_block_item_list = 95,           /* block_item_list  */
  YYSYMBOL_block_item = 96,                /* block_item  */
  YYSYMBOL_statement = 97,                 /* statement  */
  YYSYMBOL_expression_statement = 98,      /* expression_statement  */
  YYSYMBOL_primary_expression = 99,        /* primary_expression  */
  YYSYMBOL_postfix_expression = 100,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 101, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 102,         /* unary_expression  */
  YYSYMBOL_cast_expression = 103,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 104, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 105,      /* additive_expression  */
  YYSYMBOL_shift_expression = 106,         /* shift_expression  */
  YYSYMBOL_relational_expression = 107,    /* relational_expression  */
  YYSYMBOL_equality_expression = 108,      /* equality_expression  */
  YYSYMBOL_and_expression = 109,           /* and_expression  */
  YYSYMBOL_xor_expression = 110,           /* xor_expression  */
  YYSYMBOL_or_expression = 111,            /* or_expression  */
  YYSYMBOL_logical_and_expression = 112,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 113,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 114,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 115,    /* assignment_expression  */
  YYSYMBOL_expression = 116,               /* expression  */
  YYSYMBOL_constant_expression = 117,      /* constant_expression  */
  YYSYMBOL_declaration_specifiers = 118,   /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 119,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 120,           /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 121, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 122,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 123,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 124,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 125, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 126,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 127,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 128,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 129,          /* enumerator_list  */
  YYSYMBOL_enumerator = 130,               /* enumerator  */
  YYSYMBOL_enumeration_constant = 131,     /* enumeration_constant  */
  YYSYMBOL_type_qualifier = 132,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 133,       /* function_specifier  */
  YYSYMBOL_declarator = 134,               /* declarator  */
  YYSYMBOL_direct_declarator = 135,        /* direct_declarator  */
  YYSYMBOL_pointer = 136,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 137,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 138,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 139,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 140,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 141,          /* identifier_list  */
  YYSYMBOL_abstract_declarator = 142,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 143, /* direct_abstract_declarator  */
  YYSYMBOL_typedef_name = 144              /* typedef_name  */
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
#define YYLAST   1097

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  187
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  297

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
       0,   125,   125,   130,   140,   145,   146,   151,   157,   158,
     162,   163,   169,   170,   171,   172,   173,   178,   179,   180,
     181,   182,   183,   184,   185,   189,   190,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   209,   214,
     215,   216,   217,   221,   222,   223,   227,   228,   229,   233,
     234,   235,   236,   237,   241,   242,   243,   247,   248,   251,
     252,   255,   256,   260,   261,   265,   266,   270,   271,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   289,   290,   294,   304,   305,   306,   307,   308,   309,
     310,   311,   325,   326,   327,   328,   329,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   351,   352,   353,   357,   358,   362,   363,   367,   371,
     372,   373,   374,   378,   379,   383,   384,   385,   391,   392,
     393,   394,   395,   399,   400,   404,   405,   409,   413,   414,
     415,   419,   423,   424,   428,   429,   430,   431,   432,   433,
     434,   435,   436,   437,   438,   439,   440,   441,   445,   446,
     447,   448,   452,   453,   457,   458,   462,   463,   467,   468,
     469,   473,   474,   483,   484,   485,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   499,   503
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
  "$accept", "external_declaration", "function_definition",
  "compound_statement", "block_item_list", "block_item", "statement",
  "expression_statement", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "xor_expression", "or_expression", "logical_and_expression",
  "logical_or_expression", "conditional_expression",
  "assignment_expression", "expression", "constant_expression",
  "declaration_specifiers", "storage_class_specifier", "type_specifier",
  "struct_or_union_specifier", "struct_or_union",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "enumeration_constant", "type_qualifier", "function_specifier",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "abstract_declarator", "direct_abstract_declarator",
  "typedef_name", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-166)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-172)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     999,  -166,  -166,  -166,  -166,  -166,   141,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,    59,  -166,   744,  -166,  -166,
    -166,   154,  -166,  -166,  -166,  -166,   -25,    49,  -166,   101,
      18,   -16,  -166,  -166,  -166,  -166,    75,    -4,    13,    94,
    1032,    49,  -166,   -39,  -166,    79,  -166,    96,  -166,  -166,
     -16,   370,  -166,   804,   249,    -4,  1032,  -166,   892,  -166,
     186,  -166,   -36,  -166,    47,   611,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,   611,   611,   611,   611,  -166,   611,   611,
     611,   611,   611,   611,   611,  -166,   341,  -166,  -166,  -166,
    -166,   190,   803,  -166,   -28,    77,   153,    52,   160,   115,
     -14,   105,   161,    -3,  -166,  -166,   -49,   -31,  -166,   704,
     123,   120,  -166,   -30,   353,  -166,   449,   127,   262,   925,
    -166,  -166,   611,  -166,   -13,  -166,  -166,   107,  -166,    83,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,   -18,
    -166,  -166,  -166,  -166,  -166,  -166,   134,  -166,   200,  -166,
    -166,   461,   611,   204,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,   611,   611,   611,   611,   611,   611,   611,
     611,   611,   611,  -166,   611,   664,   479,  -166,    12,  -166,
       3,  -166,   965,  -166,   206,   137,   353,  -166,  -166,   611,
    -166,   491,   138,  -166,  -166,  -166,    76,   611,  -166,  -166,
     144,  -166,  -166,    -6,  -166,    85,  -166,  -166,  -166,  -166,
    -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,  -166,
    -166,   -28,   -28,    77,    77,   153,   153,   153,    52,    52,
     160,   115,   -14,   105,   161,   -56,  -166,  -166,   142,   151,
    -166,   570,   150,     3,   858,   582,  -166,  -166,  -166,  -166,
     152,   156,  -166,  -166,  -166,  -166,  -166,  -166,   611,  -166,
     611,  -166,  -166,  -166,  -166,  -166,   159,  -166,   599,   162,
    -166,  -166,  -166,  -166,  -166,  -166,  -166
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   187,    95,    98,   138,   103,     0,    93,   102,   141,
     100,   101,    96,   139,    99,   104,    94,   114,    92,   115,
     105,    97,   140,   106,   107,     0,     2,     0,    84,    86,
     108,     0,   109,    88,    90,   110,   128,     0,     1,   187,
       0,   158,    85,    87,    89,    91,     0,   142,     0,   113,
       0,     0,   137,     0,   133,   135,   144,     0,   162,   160,
     159,     0,     3,     0,     0,   143,     0,   119,     0,   116,
       0,   121,     0,   129,     0,     0,   145,   163,   161,    12,
      13,    14,    15,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     5,     7,     9,
      17,    27,    38,    39,    43,    46,    49,    54,    57,    59,
      61,    63,    65,    67,    69,    81,     0,   187,   157,   169,
       0,   164,   166,     0,     0,   146,     0,     0,     0,     0,
     111,   117,     0,   120,     0,   123,   122,   125,   130,     0,
     131,   134,    38,    83,   136,    28,    29,    37,    36,     0,
      30,    31,    32,    33,    34,    35,     0,     6,     0,    23,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     0,     0,   168,   173,   170,
     174,   155,     0,   156,     0,     0,     0,   154,   148,     0,
     147,     0,     0,   112,   126,   118,     0,     0,   132,    16,
       0,    22,    19,     0,    25,     0,    21,    71,    72,    73,
      74,    75,    76,    77,    78,    80,    79,    70,    40,    41,
      42,    44,    45,    47,    48,    51,    50,    52,    55,    56,
      58,    60,    62,    64,    66,     0,    82,   183,     0,     0,
     177,     0,     0,   175,     0,     0,   165,   167,   172,   150,
       0,     0,   153,   149,   124,   127,     4,    20,     0,    18,
       0,   185,   176,   181,   179,   184,     0,   178,     0,     0,
     151,   152,    26,    68,   186,   182,   180
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -166,  -166,  -166,   169,  -166,   131,  -166,  -166,  -166,  -166,
    -166,   -61,   -83,     1,     5,     0,     2,    45,    53,    48,
      50,    58,  -166,   -74,   -47,   -60,  -119,   243,   -22,    21,
    -166,  -166,   178,    73,  -166,  -166,    43,  -166,   210,    42,
    -166,    10,    11,   -23,   -46,   -29,    90,  -165,  -166,    67,
    -166,    78,    74,  -166
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    25,    26,    95,    96,    97,    98,    99,   100,   101,
     223,   142,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   144,   119,    28,    29,
      30,    31,    68,    69,    70,   134,   135,    32,    53,    54,
      55,    33,    34,    57,    47,    48,    60,   120,   121,   122,
     123,   199,   200,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     102,   143,    65,   102,    46,    42,   150,   151,   152,   153,
     154,   155,    59,   214,   191,    56,    56,   127,     4,   194,
     193,    56,   145,   146,   147,   148,   194,   102,   149,    73,
     258,    78,   138,   280,    13,   102,    74,    44,    45,   139,
    -171,   203,    51,   151,  -171,   204,    22,   137,    43,   175,
      52,    58,    52,   219,   176,   177,   215,   194,   143,    38,
      71,    41,   216,   102,   182,   277,    63,   102,    64,   278,
      77,    67,   188,   264,    58,   265,    71,   205,    71,    56,
     136,   212,   195,    40,   196,   192,    52,    67,    40,    67,
     198,   133,   238,   239,   240,    41,   197,    42,   275,   286,
     102,   102,   225,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   224,   140,   141,   227,   228,   229,
     230,   231,   232,   233,   234,   235,   236,   237,   151,    44,
      45,   102,   255,   102,    58,   102,   183,   184,    77,    71,
      43,   131,    61,   143,    36,   102,    40,   256,   102,   262,
      67,   218,    65,    41,   128,   178,   179,    49,   279,   270,
     194,    66,   271,   180,   181,   132,   198,    76,  -144,    75,
    -144,  -144,  -144,  -144,   185,   186,  -144,   190,   151,   241,
     242,   141,   245,   246,   247,   243,   244,   248,   249,    39,
    -144,   187,   189,   137,   201,   202,   217,   158,   159,   160,
     208,   220,   131,   221,   102,   151,   293,   226,    37,   268,
     269,   273,   276,   281,   206,    62,    77,   102,   289,     3,
       4,    50,   282,   284,     5,   290,     6,   157,     8,   291,
     294,   292,   250,    10,    11,   296,    13,   252,    14,    15,
     253,   251,    17,    27,   129,    19,    20,    21,    22,   254,
      23,    24,    79,    80,    81,    82,    40,    83,    84,   274,
     161,    72,   162,    41,   163,    79,    80,    81,    82,   267,
      83,    84,   263,   259,     0,   132,     0,     0,     0,    85,
       0,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,    85,     0,     0,     0,     4,     0,     0,    13,
       0,     0,     0,    86,   124,     0,     0,     0,     0,     0,
       0,    22,    13,     0,     0,     0,    86,   209,     0,    88,
       0,     0,   125,     0,    22,    89,   126,    91,    92,    93,
      94,     0,    88,     0,     0,   210,     0,     0,    89,   211,
      91,    92,    93,    94,    79,    80,    81,    82,     0,    83,
      84,     0,     0,     0,     0,     0,    79,    80,    81,    82,
       0,    83,    84,     0,     0,     0,     0,     0,     0,     0,
       0,    85,     0,    79,    80,    81,    82,     0,    83,    84,
       0,     0,     0,    85,     0,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,    86,     0,     0,     0,     0,
      85,     0,     0,    13,     0,     0,     0,    86,    61,   156,
      87,    88,     0,     0,     0,    22,     0,    89,    90,    91,
      92,    93,    94,    88,    86,     0,     0,     0,     0,    89,
      90,    91,    92,    93,    94,     0,     0,    61,     0,    87,
      88,     0,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    79,    80,    81,    82,     0,    83,    84,     0,
       0,     0,     0,     0,    79,    80,    81,    82,     0,    83,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    85,
       0,     0,    79,    80,    81,    82,     0,    83,    84,     0,
       0,    85,     0,     0,    79,    80,    81,    82,     0,    83,
      84,     0,     0,    86,     0,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,    86,     0,     0,     0,    88,
       0,    85,   207,     0,     0,    89,    90,    91,    92,    93,
      94,    88,   222,    86,     0,     0,     0,    89,    90,    91,
      92,    93,    94,     0,     0,    86,     0,     0,     0,    88,
       0,     0,   260,     0,     0,    89,   261,    91,    92,    93,
      94,    88,     0,     0,   272,     0,     0,    89,    90,    91,
      92,    93,    94,    79,    80,    81,    82,     0,    83,    84,
       0,     0,     0,     0,     0,    79,    80,    81,    82,     0,
      83,    84,     0,     0,     0,     0,     0,     0,     0,     0,
      85,     0,    79,    80,    81,    82,     0,    83,    84,     0,
       0,     0,    85,     0,    79,    80,    81,    82,     0,    83,
      84,     0,     0,     0,    86,     0,     0,     0,     0,    85,
       0,     0,     0,     0,     0,     0,    86,     0,     0,     0,
      88,    85,     0,   283,     0,     0,    89,    90,    91,    92,
      93,    94,    88,    86,     0,   287,     0,     0,    89,   288,
      91,    92,    93,    94,     0,    86,     0,    39,     0,    88,
       0,     0,   295,     0,     0,    89,    90,    91,    92,    93,
      94,    88,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,     2,     0,     0,     0,     3,     4,     0,
       0,     0,     5,     0,     6,     7,     8,    39,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,     0,    16,
      17,     0,    18,    19,    20,    21,    22,     0,    23,    24,
       0,     0,     0,     2,   195,   257,   196,     3,     4,     0,
       0,    41,     5,     0,     6,     7,     8,    39,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,     0,    16,
      17,     0,    18,    19,    20,    21,    22,     0,    23,    24,
       0,     0,     0,     2,   195,     0,   196,     3,     4,     0,
       0,    41,     5,     0,     6,     7,     8,     0,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,     0,    16,
      17,     0,    18,    19,    20,    21,    22,   117,    23,    24,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,    41,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,     0,     2,     0,     0,     0,     3,     4,     0,
       0,     0,     5,     0,     6,     7,     8,     0,     0,     0,
       9,    10,    11,    12,    13,     0,    14,    15,     0,    16,
      17,     1,    18,    19,    20,    21,    22,     0,    23,    24,
       0,     0,     0,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     2,     0,     0,
       0,     3,     4,   174,     0,     1,     5,     0,     6,     7,
       8,     0,     0,     0,     9,    10,    11,    12,    13,     0,
      14,    15,     0,    16,    17,     0,    18,    19,    20,    21,
      22,     0,    23,    24,     0,     3,     4,     0,     1,   285,
       5,     0,     6,     0,     8,     0,     0,     0,     0,    10,
      11,     0,    13,     0,    14,    15,     0,     0,    17,     0,
       0,    19,    20,    21,    22,     0,    23,    24,     3,     4,
     130,     0,     0,     5,     0,     6,     0,     8,     1,     0,
       0,     0,    10,    11,     0,    13,     0,    14,    15,     0,
       0,    17,     0,   266,    19,    20,    21,    22,     0,    23,
      24,     0,     0,   213,     2,     0,     0,     0,     3,     4,
       0,     0,     1,     5,     0,     6,     7,     8,     0,     0,
       0,     9,    10,    11,    12,    13,     0,    14,    15,     0,
      16,    17,     0,    18,    19,    20,    21,    22,     2,    23,
      24,     0,     3,     4,     0,     1,     0,     5,     0,     6,
       7,     8,     0,     0,     0,     9,    10,    11,    12,    13,
       0,    14,    15,     0,    16,    17,     0,    18,    19,    20,
      21,    22,     0,    23,    24,     3,     4,     0,     0,     0,
       5,     0,     6,     0,     8,     0,     0,     0,     0,    10,
      11,     0,    13,     0,    14,    15,     0,     0,    17,     0,
       0,    19,    20,    21,    22,     0,    23,    24
};

static const yytype_int16 yycheck[] =
{
      61,    75,    48,    64,    27,    27,    89,    90,    91,    92,
      93,    94,    41,   132,    17,     3,     3,    64,    34,    75,
      69,     3,    83,    84,    85,    86,    75,    88,    88,    68,
     195,    60,    68,    89,    50,    96,    75,    27,    27,    75,
      71,    71,    67,   126,    75,    75,    62,    70,    27,    77,
       3,    41,     3,    71,    82,    83,    69,    75,   132,     0,
      50,    77,    75,   124,    12,    71,    70,   128,    72,    75,
      60,    50,    86,    70,    64,    72,    66,   124,    68,     3,
      70,   128,    70,    70,    72,    88,     3,    66,    70,    68,
     119,    70,   175,   176,   177,    77,   119,   119,   217,   264,
     161,   162,   162,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   161,    68,    74,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   211,   119,
     119,   192,   192,   194,   124,   196,    84,    85,   128,   129,
     119,    68,    67,   217,     3,   206,    70,   194,   209,   196,
     129,    68,   198,    77,    64,    78,    79,     3,    73,   206,
      75,    67,   209,    10,    11,    89,   195,    71,    67,    90,
      69,    70,    71,    72,    14,    15,    75,    16,   261,   178,
     179,   139,   182,   183,   184,   180,   181,   185,   186,     3,
      89,    76,    87,   216,    71,    75,    89,     7,     8,     9,
      73,    67,   129,     3,   265,   288,   280,     3,    67,     3,
      73,    73,    68,    71,   124,    46,   206,   278,   265,    33,
      34,    67,    71,    73,    38,    73,    40,    96,    42,    73,
      71,   278,   187,    47,    48,    73,    50,   189,    52,    53,
     190,   188,    56,     0,    66,    59,    60,    61,    62,   191,
      64,    65,     3,     4,     5,     6,    70,     8,     9,   216,
      70,    51,    72,    77,    74,     3,     4,     5,     6,   202,
       8,     9,   198,   195,    -1,    89,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    30,    -1,    -1,    -1,    34,    -1,    -1,    50,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    62,    50,    -1,    -1,    -1,    54,    55,    -1,    70,
      -1,    -1,    73,    -1,    62,    76,    77,    78,    79,    80,
      81,    -1,    70,    -1,    -1,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    50,    -1,    -1,    -1,    54,    67,    68,
      69,    70,    -1,    -1,    -1,    62,    -1,    76,    77,    78,
      79,    80,    81,    70,    54,    -1,    -1,    -1,    -1,    76,
      77,    78,    79,    80,    81,    -1,    -1,    67,    -1,    69,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    30,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    70,
      -1,    30,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    70,    71,    54,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    -1,    -1,    54,    -1,    -1,    -1,    70,
      -1,    -1,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    70,    -1,    -1,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    30,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,
      70,    30,    -1,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,    70,    54,    -1,    73,    -1,    -1,    76,    77,
      78,    79,    80,    81,    -1,    54,    -1,     3,    -1,    70,
      -1,    -1,    73,    -1,    -1,    76,    77,    78,    79,    80,
      81,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,    29,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,     3,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,    -1,    64,    65,
      -1,    -1,    -1,    29,    70,    71,    72,    33,    34,    -1,
      -1,    77,    38,    -1,    40,    41,    42,     3,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,    -1,    64,    65,
      -1,    -1,    -1,    29,    70,    -1,    72,    33,    34,    -1,
      -1,    77,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    58,    59,    60,    61,    62,     3,    64,    65,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,
      -1,    77,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    -1,    29,    -1,    -1,    -1,    33,    34,    -1,
      -1,    -1,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,     3,    58,    59,    60,    61,    62,    -1,    64,    65,
      -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    -1,    -1,
      -1,    33,    34,    90,    -1,     3,    38,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    58,    59,    60,    61,
      62,    -1,    64,    65,    -1,    33,    34,    -1,     3,    71,
      38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    65,    33,    34,
      68,    -1,    -1,    38,    -1,    40,    -1,    42,     3,    -1,
      -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,    -1,
      -1,    56,    -1,    18,    59,    60,    61,    62,    -1,    64,
      65,    -1,    -1,    68,    29,    -1,    -1,    -1,    33,    34,
      -1,    -1,     3,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    58,    59,    60,    61,    62,    29,    64,
      65,    -1,    33,    34,    -1,     3,    -1,    38,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    58,    59,    60,
      61,    62,    -1,    64,    65,    33,    34,    -1,    -1,    -1,
      38,    -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    33,    34,    38,    40,    41,    42,    46,
      47,    48,    49,    50,    52,    53,    55,    56,    58,    59,
      60,    61,    62,    64,    65,    92,    93,   118,   119,   120,
     121,   122,   128,   132,   133,   144,     3,    67,     0,     3,
      70,    77,   119,   120,   132,   133,   134,   135,   136,     3,
      67,    67,     3,   129,   130,   131,     3,   134,   132,   136,
     137,    67,    94,    70,    72,   135,    67,   120,   123,   124,
     125,   132,   129,    68,    75,    90,    71,   132,   136,     3,
       4,     5,     6,     8,     9,    30,    54,    69,    70,    76,
      77,    78,    79,    80,    81,    94,    95,    96,    97,    98,
      99,   100,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,     3,    71,   118,
     138,   139,   140,   141,    55,    73,    77,   115,   137,   123,
      68,   124,    89,   120,   126,   127,   132,   134,    68,    75,
      68,   130,   102,   114,   117,   102,   102,   102,   102,   116,
     103,   103,   103,   103,   103,   103,    68,    96,     7,     8,
       9,    70,    72,    74,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    90,    77,    82,    83,    78,    79,
      10,    11,    12,    84,    85,    14,    15,    76,    86,    87,
      16,    17,    88,    69,    75,    70,    72,   134,   136,   142,
     143,    71,    75,    71,    75,   115,   137,    73,    73,    55,
      73,    77,   115,    68,   117,    69,    75,    89,    68,    71,
      67,     3,    71,   101,   115,   116,     3,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   103,   103,
     103,   104,   104,   105,   105,   106,   106,   106,   107,   107,
     108,   109,   110,   111,   112,   116,   115,    71,   138,   142,
      73,    77,   115,   143,    70,    72,    18,   140,     3,    73,
     115,   115,    73,    73,   127,   117,    68,    71,    75,    73,
      89,    71,    71,    73,    73,    71,   138,    73,    77,   115,
      73,    73,   115,   114,    71,    73,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    94,    95,    95,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   103,   104,
     104,   104,   104,   105,   105,   105,   106,   106,   106,   107,
     107,   107,   107,   107,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   116,   116,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   119,   119,   119,   119,   119,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   121,   121,   121,   122,   122,   123,   123,   124,   125,
     125,   125,   125,   126,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   129,   129,   130,   130,   131,   132,   132,
     132,   133,   134,   134,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   136,
     136,   136,   137,   137,   138,   138,   139,   139,   140,   140,
     140,   141,   141,   142,   142,   142,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     3,     5,     1,     2,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     4,     3,
       4,     3,     3,     2,     2,     1,     3,     1,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     1,     1,     2,     1,     2,     1,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     5,     2,     1,     1,     1,     2,     3,     1,
       2,     1,     2,     1,     3,     1,     2,     3,     2,     4,
       5,     5,     6,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     3,     4,     4,     5,
       5,     6,     6,     5,     4,     4,     4,     3,     1,     2,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     1,
       2,     1,     3,     1,     1,     2,     3,     2,     3,     3,
       4,     3,     4,     2,     3,     3,     4,     1
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
#line 119 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1348 "parser.tab.c"
        break;

    case YYSYMBOL_CHARLIT: /* CHARLIT  */
#line 119 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1354 "parser.tab.c"
        break;

    case YYSYMBOL_STRINGLIT: /* STRINGLIT  */
#line 119 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1360 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBERLIT: /* NUMBERLIT  */
#line 118 "parser.y"
            { }
#line 1366 "parser.tab.c"
        break;

    case YYSYMBOL_primary_expression: /* primary_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1372 "parser.tab.c"
        break;

    case YYSYMBOL_postfix_expression: /* postfix_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1378 "parser.tab.c"
        break;

    case YYSYMBOL_unary_expression: /* unary_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1384 "parser.tab.c"
        break;

    case YYSYMBOL_cast_expression: /* cast_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1390 "parser.tab.c"
        break;

    case YYSYMBOL_multiplicative_expression: /* multiplicative_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1396 "parser.tab.c"
        break;

    case YYSYMBOL_additive_expression: /* additive_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1402 "parser.tab.c"
        break;

    case YYSYMBOL_shift_expression: /* shift_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1408 "parser.tab.c"
        break;

    case YYSYMBOL_relational_expression: /* relational_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1414 "parser.tab.c"
        break;

    case YYSYMBOL_equality_expression: /* equality_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1420 "parser.tab.c"
        break;

    case YYSYMBOL_and_expression: /* and_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1426 "parser.tab.c"
        break;

    case YYSYMBOL_xor_expression: /* xor_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1432 "parser.tab.c"
        break;

    case YYSYMBOL_or_expression: /* or_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1438 "parser.tab.c"
        break;

    case YYSYMBOL_logical_and_expression: /* logical_and_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1444 "parser.tab.c"
        break;

    case YYSYMBOL_logical_or_expression: /* logical_or_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1450 "parser.tab.c"
        break;

    case YYSYMBOL_conditional_expression: /* conditional_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1456 "parser.tab.c"
        break;

    case YYSYMBOL_assignment_expression: /* assignment_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1462 "parser.tab.c"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1468 "parser.tab.c"
        break;

    case YYSYMBOL_constant_expression: /* constant_expression  */
#line 120 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1474 "parser.tab.c"
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
  case 12: /* primary_expression: IDENT  */
#line 169 "parser.y"
          {(yyval.node) = ast_new_ident((yyvsp[0].string).buffer);}
#line 1744 "parser.tab.c"
    break;

  case 13: /* primary_expression: CHARLIT  */
#line 170 "parser.y"
              {(yyval.node) = ast_new_charlit((yyvsp[0].string).buffer[0]);}
#line 1750 "parser.tab.c"
    break;

  case 14: /* primary_expression: STRINGLIT  */
#line 171 "parser.y"
                {(yyval.node) = ast_new_stringlit((yyvsp[0].string));}
#line 1756 "parser.tab.c"
    break;

  case 15: /* primary_expression: NUMBERLIT  */
#line 172 "parser.y"
                {(yyval.node) = ast_new_numberlit((yyvsp[0].number));}
#line 1762 "parser.tab.c"
    break;

  case 16: /* primary_expression: '(' expression ')'  */
#line 173 "parser.y"
                         {(yyval.node) = (yyvsp[-1].node);}
#line 1768 "parser.tab.c"
    break;

  case 21: /* postfix_expression: postfix_expression '.' IDENT  */
#line 182 "parser.y"
                                   {(yyval.node) = ast_new_binary_op('.', (yyvsp[-2].node), (yyvsp[0].string));}
#line 1774 "parser.tab.c"
    break;

  case 22: /* postfix_expression: postfix_expression "->" IDENT  */
#line 183 "parser.y"
                                    {(yyval.node) = ast_new_binary_op('.', ast_new_unary_op('*', (yyvsp[-2].node)), (yyvsp[0].string));}
#line 1780 "parser.tab.c"
    break;

  case 23: /* postfix_expression: postfix_expression "++"  */
#line 184 "parser.y"
                              {(yyval.node) = ast_new_unary_op(PLUSPLUS, (yyvsp[-1].node));}
#line 1786 "parser.tab.c"
    break;

  case 24: /* postfix_expression: postfix_expression "--"  */
#line 185 "parser.y"
                              {(yyval.node) = ast_new_unary_op(MINUSMINUS, (yyvsp[-1].node));}
#line 1792 "parser.tab.c"
    break;

  case 40: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 215 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op('*', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1798 "parser.tab.c"
    break;

  case 41: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 216 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op('/', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1804 "parser.tab.c"
    break;

  case 42: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 217 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op('%', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1810 "parser.tab.c"
    break;

  case 44: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 222 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('+', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1816 "parser.tab.c"
    break;

  case 45: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 223 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('-', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1822 "parser.tab.c"
    break;

  case 47: /* shift_expression: shift_expression "<<" additive_expression  */
#line 228 "parser.y"
                                                {(yyval.node) = ast_new_binary_op(SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1828 "parser.tab.c"
    break;

  case 48: /* shift_expression: shift_expression ">>" additive_expression  */
#line 229 "parser.y"
                                                {(yyval.node) = ast_new_binary_op(SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1834 "parser.tab.c"
    break;

  case 50: /* relational_expression: relational_expression '<' shift_expression  */
#line 234 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('<', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1840 "parser.tab.c"
    break;

  case 51: /* relational_expression: relational_expression "<=" shift_expression  */
#line 235 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1846 "parser.tab.c"
    break;

  case 52: /* relational_expression: relational_expression '>' shift_expression  */
#line 236 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('>', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1852 "parser.tab.c"
    break;

  case 53: /* relational_expression: relational_expression "<=" shift_expression  */
#line 237 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1858 "parser.tab.c"
    break;

  case 55: /* equality_expression: equality_expression "==" relational_expression  */
#line 242 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op(EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1864 "parser.tab.c"
    break;

  case 56: /* equality_expression: equality_expression "!=" relational_expression  */
#line 243 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op(NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1870 "parser.tab.c"
    break;

  case 58: /* and_expression: and_expression '&' equality_expression  */
#line 248 "parser.y"
                                             {(yyval.node) = ast_new_binary_op('&', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1876 "parser.tab.c"
    break;

  case 60: /* xor_expression: xor_expression '^' and_expression  */
#line 252 "parser.y"
                                        {(yyval.node) = ast_new_binary_op('^', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1882 "parser.tab.c"
    break;

  case 62: /* or_expression: or_expression '|' xor_expression  */
#line 256 "parser.y"
                                       {(yyval.node) = ast_new_binary_op('|', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1888 "parser.tab.c"
    break;

  case 64: /* logical_and_expression: logical_and_expression "&&" or_expression  */
#line 261 "parser.y"
                                                {(yyval.node) = ast_new_binary_op(LOGAND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1894 "parser.tab.c"
    break;

  case 66: /* logical_or_expression: logical_or_expression "||" logical_and_expression  */
#line 266 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op(LOGOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1900 "parser.tab.c"
    break;

  case 68: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 271 "parser.y"
                                                                      {(yyval.node) = ast_new_ternary_op((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 1906 "parser.tab.c"
    break;

  case 70: /* assignment_expression: unary_expression '=' assignment_expression  */
#line 276 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('=', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1912 "parser.tab.c"
    break;

  case 71: /* assignment_expression: unary_expression "*=" assignment_expression  */
#line 277 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(PLUSEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1918 "parser.tab.c"
    break;

  case 72: /* assignment_expression: unary_expression "/=" assignment_expression  */
#line 278 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(MINUSEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1924 "parser.tab.c"
    break;

  case 73: /* assignment_expression: unary_expression "%=" assignment_expression  */
#line 279 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(TIMESEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1930 "parser.tab.c"
    break;

  case 74: /* assignment_expression: unary_expression "+=" assignment_expression  */
#line 280 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(DIVEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1936 "parser.tab.c"
    break;

  case 75: /* assignment_expression: unary_expression "-=" assignment_expression  */
#line 281 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(MODEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1942 "parser.tab.c"
    break;

  case 76: /* assignment_expression: unary_expression "<<=" assignment_expression  */
#line 282 "parser.y"
                                                   {(yyval.node) = ast_new_binary_op(SHLEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1948 "parser.tab.c"
    break;

  case 77: /* assignment_expression: unary_expression ">>=" assignment_expression  */
#line 283 "parser.y"
                                                   {(yyval.node) = ast_new_binary_op(SHREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1954 "parser.tab.c"
    break;

  case 78: /* assignment_expression: unary_expression "&=" assignment_expression  */
#line 284 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(ANDEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1960 "parser.tab.c"
    break;

  case 79: /* assignment_expression: unary_expression "^=" assignment_expression  */
#line 285 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(XOREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1966 "parser.tab.c"
    break;

  case 80: /* assignment_expression: unary_expression "|=" assignment_expression  */
#line 286 "parser.y"
                                                  {(yyval.node) = ast_new_binary_op(OREQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 1972 "parser.tab.c"
    break;

  case 82: /* expression: expression ',' assignment_expression  */
#line 290 "parser.y"
                                           {(yyval.node) = ast_new_binary_op(',', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1978 "parser.tab.c"
    break;


#line 1982 "parser.tab.c"

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

#line 510 "parser.y"

