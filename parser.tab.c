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
  YYSYMBOL_declaration_list = 94,          /* declaration_list  */
  YYSYMBOL_compound_statement = 95,        /* compound_statement  */
  YYSYMBOL_block_item_list = 96,           /* block_item_list  */
  YYSYMBOL_block_item = 97,                /* block_item  */
  YYSYMBOL_statement = 98,                 /* statement  */
  YYSYMBOL_expression_statement = 99,      /* expression_statement  */
  YYSYMBOL_identifier = 100,               /* identifier  */
  YYSYMBOL_declaration = 101,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 102,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 103,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 104,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 105,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 106,           /* type_specifier  */
  YYSYMBOL_type_qualifier = 107,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 108,       /* function_specifier  */
  YYSYMBOL_struct_or_union_specifier = 109, /* struct_or_union_specifier  */
  YYSYMBOL_struct_or_union = 110,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 111,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 112,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 113, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 114,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 115,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 116,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 117,          /* enumerator_list  */
  YYSYMBOL_enumerator = 118,               /* enumerator  */
  YYSYMBOL_declarator = 119,               /* declarator  */
  YYSYMBOL_direct_declarator = 120,        /* direct_declarator  */
  YYSYMBOL_pointer = 121,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 122,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 123,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 124,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 125,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 126,          /* identifier_list  */
  YYSYMBOL_abstract_declarator = 127,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 128 /* direct_abstract_declarator  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   629

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

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
       0,   141,   141,   142,   146,   147,   151,   152,   156,   161,
     162,   166,   167,   173,   174,   180,   187,   338,   342,   343,
     344,   345,   346,   347,   348,   349,   353,   354,   358,   364,
     365,   366,   367,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   382,   383,   384,   385,   391,   392,   393,   398,
     403,   404,   405,   409,   410,   414,   415,   419,   423,   424,
     425,   426,   430,   431,   435,   443,   444,   445,   446,   447,
     451,   452,   456,   461,   462,   466,   467,   468,   469,   475,
     476,   477,   478,   479,   483,   484,   485,   486,   490,   491,
     495,   496,   500,   501,   505,   506,   507,   511,   512,   521,
     522,   523,   527,   528,   529,   532,   533,   534,   535,   536,
     537
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
  "declaration_list", "compound_statement", "block_item_list",
  "block_item", "statement", "expression_statement", "identifier",
  "declaration", "declaration_specifiers", "init_declarator_list",
  "init_declarator", "storage_class_specifier", "type_specifier",
  "type_qualifier", "function_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "declarator", "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "abstract_declarator", "direct_abstract_declarator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-107)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     465,  -107,  -107,  -107,  -107,    20,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,    14,  -107,  -107,   176,  -107,  -107,  -107,
    -107,  -107,    21,  -107,  -107,    26,   -35,  -107,     1,    70,
    -107,   -28,  -107,  -107,  -107,  -107,  -107,   428,    41,     4,
     -30,   564,  -107,   -49,  -107,    26,   -29,  -107,  -107,    70,
    -107,     1,   391,   428,  -107,  -107,   176,   247,   -17,    41,
     564,  -107,  -107,   498,  -107,   209,  -107,    13,   -48,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,   354,  -107,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,   136,   -27,   -21,  -107,   -41,
    -107,    -7,    35,   531,  -107,  -107,  -107,  -107,    25,  -107,
    -107,  -107,  -107,  -107,    15,    29,  -107,    96,    16,  -107,
       5,  -107,    44,  -107,   286,  -107,    26,  -107,  -107,    22,
    -107,  -107,     1,  -107,    38,  -107,    32,    36,  -107,    42,
      44,   320,    28,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,    47,  -107,    46,  -107,  -107
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    31,    34,    46,    39,     0,    29,    38,    49,    36,
      37,    32,    47,    35,    40,    30,    53,    54,    41,    33,
      48,    42,    43,     0,     2,     3,     0,    18,    19,    20,
      21,    44,     0,    45,    16,     0,    65,     1,     0,    84,
      75,     0,    26,    22,    23,    24,    25,    28,    73,     0,
      52,     0,    72,     0,    70,     0,     0,    88,    86,    85,
      17,     0,     0,     0,     4,     6,     0,     0,     0,    74,
       0,    58,    60,     0,    55,     0,    66,     0,     0,    76,
      89,    87,    27,    28,    15,    13,     0,     9,    12,    14,
      11,     5,     7,    83,    97,    95,     0,    90,    92,     0,
      77,     0,     0,     0,    50,    56,    59,    61,     0,    62,
      64,    68,    71,    67,     0,     0,    10,     0,     0,    94,
      99,    96,   100,    81,     0,    82,     0,    80,    78,     0,
      51,    57,     0,    69,     0,   107,     0,     0,   103,     0,
     101,     0,     0,    91,    93,    98,    79,    63,     8,   109,
     102,   105,   108,     0,   104,     0,   110,   106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -107,  -107,  -107,  -107,   -38,  -107,    37,  -107,  -107,    -4,
      39,     0,  -107,    60,   -16,    -5,   -11,   -13,  -107,  -107,
      56,   -67,  -107,  -107,    -1,  -107,    72,   -65,   -23,   -44,
     -37,    65,  -106,  -107,    11,  -107,    23,     8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    23,    24,    63,    85,    86,    87,    88,    89,    40,
      90,    66,    41,    42,    27,    28,    29,    30,    31,    32,
      73,    74,    75,   108,   109,    33,    53,    54,    56,    48,
      49,    59,    96,    97,    98,    99,   121,   122
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      26,    36,    58,    47,    34,    69,   105,    34,    34,    64,
      43,   136,   112,    46,    37,    45,    34,     3,    34,    76,
     113,    44,    81,    34,    50,    91,    77,   114,    57,    34,
     125,    52,    55,    12,   126,   153,   105,    70,    83,    25,
      72,    60,    79,    83,   123,    20,    71,    61,    80,   112,
      43,    52,   110,    46,   124,    45,   100,    57,   120,    72,
     101,    44,    72,    94,   107,    71,   127,    95,    71,     3,
     106,    38,   119,    52,    38,   117,    69,   118,    39,    43,
     120,   111,    46,   133,    45,    12,    65,    35,    51,   138,
      44,    80,    72,   139,   131,   146,   134,    20,    71,    34,
     132,   154,    92,   149,     3,   155,   148,   150,   128,   110,
      52,    67,   129,    68,   141,   151,   142,    95,   156,   157,
      12,    82,   145,   116,    95,     1,   103,    78,   140,     2,
       3,   147,    20,   102,     4,   144,     5,     6,     7,    34,
     137,    95,     8,     9,    10,    11,    12,    39,    13,    14,
       0,    15,    16,     0,     0,    17,    18,    19,    20,     0,
      21,    22,     0,     0,     0,     1,   117,   135,   118,     2,
       3,     0,     0,    39,     4,     0,     5,     6,     7,    34,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,    16,     0,     0,    17,    18,    19,    20,     0,
      21,    22,     0,     0,     0,     1,   117,     0,   118,     2,
       3,     0,    34,    39,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,    16,     0,     0,    17,    18,    19,    20,     0,
      21,    22,     2,     3,     0,     0,    38,     4,     0,     5,
      34,     7,     0,    39,     0,     0,     9,    10,     0,    12,
       0,    13,    14,     0,     0,    16,     0,     0,    17,    18,
      19,    20,     0,    21,    22,     0,     1,     0,     0,    38,
       2,     3,     0,     0,     0,     4,    39,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,    16,   143,     0,    17,    18,    19,    20,
       0,    21,    22,     0,     0,     1,     0,     0,    93,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,    16,     0,     0,    17,    18,    19,    20,     1,
      21,    22,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,    16,     0,     0,    17,
      18,    19,    20,     1,    21,    22,     0,     2,     3,     0,
       0,   152,     4,     0,     5,     6,     7,     0,     0,     0,
       8,     9,    10,    11,    12,     0,    13,    14,     0,    15,
      16,     0,     0,    17,    18,    19,    20,     0,    21,    22,
       1,    62,   115,    84,     2,     3,     0,     0,     0,     4,
       0,     5,     6,     7,     0,     0,     0,     8,     9,    10,
      11,    12,     0,    13,    14,     0,    15,    16,     0,     0,
      17,    18,    19,    20,     0,    21,    22,     1,    62,     0,
      84,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,     0,    15,    16,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     1,    62,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,     0,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,    16,     0,     0,    17,    18,    19,    20,     0,    21,
      22,     2,     3,     0,     0,     0,     4,     0,     5,     0,
       7,     0,     0,     0,     0,     9,    10,     0,    12,     0,
      13,    14,     0,     0,    16,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     2,     3,   104,     0,     0,     4,
       0,     5,     0,     7,     0,     0,     0,     0,     9,    10,
       0,    12,     0,    13,    14,     0,     0,    16,     0,     0,
      17,    18,    19,    20,     0,    21,    22,     2,     3,   130,
       0,     0,     4,     0,     5,     0,     7,     0,     0,     0,
       0,     9,    10,     0,    12,     0,    13,    14,     0,     0,
      16,     0,     0,    17,    18,    19,    20,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
       0,     5,    39,    26,     3,    49,    73,     3,     3,    47,
      26,   117,    77,    26,     0,    26,     3,    34,     3,    68,
      68,    26,    59,     3,     3,    63,    75,    75,    39,     3,
      71,    35,    67,    50,    75,   141,   103,    67,    61,     0,
      51,    69,    71,    66,    71,    62,    51,    75,    59,   114,
      66,    55,    75,    66,    75,    66,    73,    68,    95,    70,
      77,    66,    73,    67,    75,    70,    73,    67,    73,    34,
      75,    70,    95,    77,    70,    70,   120,    72,    77,    95,
     117,    68,    95,    68,    95,    50,    47,    67,    67,    73,
      95,   102,   103,    77,    69,    73,    67,    62,   103,     3,
      75,    73,    63,    71,    34,    77,    68,    71,    73,   132,
     114,    70,    77,    72,    70,    73,    72,   117,    71,    73,
      50,    61,   126,    86,   124,    29,    70,    55,   120,    33,
      34,   132,    62,    68,    38,   124,    40,    41,    42,     3,
     117,   141,    46,    47,    48,    49,    50,    77,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65,    -1,    -1,    -1,    29,    70,    71,    72,    33,
      34,    -1,    -1,    77,    38,    -1,    40,    41,    42,     3,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65,    -1,    -1,    -1,    29,    70,    -1,    72,    33,
      34,    -1,     3,    77,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65,    33,    34,    -1,    -1,    70,    38,    -1,    40,
       3,    42,    -1,    77,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    64,    65,    -1,    29,    -1,    -1,    70,
      33,    34,    -1,    -1,    -1,    38,    77,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    18,    -1,    59,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    29,    -1,    -1,    71,    33,
      34,    -1,    -1,    -1,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    29,
      64,    65,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,
      60,    61,    62,    29,    64,    65,    -1,    33,    34,    -1,
      -1,    71,    38,    -1,    40,    41,    42,    -1,    -1,    -1,
      46,    47,    48,    49,    50,    -1,    52,    53,    -1,    55,
      56,    -1,    -1,    59,    60,    61,    62,    -1,    64,    65,
      29,    67,    68,    69,    33,    34,    -1,    -1,    -1,    38,
      -1,    40,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65,    29,    67,    -1,
      69,    33,    34,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    29,    67,    -1,    -1,    33,    34,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      65,    33,    34,    -1,    -1,    -1,    38,    -1,    40,    -1,
      42,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,
      52,    53,    -1,    -1,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    33,    34,    68,    -1,    -1,    38,
      -1,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      -1,    50,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65,    33,    34,    68,
      -1,    -1,    38,    -1,    40,    -1,    42,    -1,    -1,    -1,
      -1,    47,    48,    -1,    50,    -1,    52,    53,    -1,    -1,
      56,    -1,    -1,    59,    60,    61,    62,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    33,    34,    38,    40,    41,    42,    46,    47,
      48,    49,    50,    52,    53,    55,    56,    59,    60,    61,
      62,    64,    65,    92,    93,   101,   102,   105,   106,   107,
     108,   109,   110,   116,     3,    67,   100,     0,    70,    77,
     100,   103,   104,   105,   106,   107,   108,   119,   120,   121,
       3,    67,   100,   117,   118,    67,   119,   107,   121,   122,
      69,    75,    67,    94,    95,   101,   102,    70,    72,   120,
      67,   106,   107,   111,   112,   113,    68,    75,   117,    71,
     107,   121,   104,   119,    69,    95,    96,    97,    98,    99,
     101,    95,   101,    71,   100,   102,   123,   124,   125,   126,
      73,    77,   122,   111,    68,   112,   106,   107,   114,   115,
     119,    68,   118,    68,    75,    68,    97,    70,    72,   119,
     121,   127,   128,    71,    75,    71,    75,    73,    73,    77,
      68,    69,    75,    68,    67,    71,   123,   127,    73,    77,
     128,    70,    72,    18,   125,   100,    73,   115,    68,    71,
      71,    73,    71,   123,    73,    77,    71,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    94,    94,    95,    96,
      96,    97,    97,    98,    98,    99,   100,   101,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   104,   105,
     105,   105,   105,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   107,   107,   107,   108,
     109,   109,   109,   110,   110,   111,   111,   112,   113,   113,
     113,   113,   114,   114,   115,   116,   116,   116,   116,   116,
     117,   117,   118,   119,   119,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   121,   121,   122,   122,
     123,   123,   124,   124,   125,   125,   125,   126,   126,   127,
     127,   127,   128,   128,   128,   128,   128,   128,   128,   128,
     128
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     3,     4,     1,     2,     5,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     2,     1,     1,     1,     2,     3,     1,     2,
       1,     2,     1,     3,     1,     2,     4,     5,     5,     6,
       1,     3,     1,     1,     2,     1,     3,     3,     4,     5,
       4,     4,     4,     3,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     1,     2,     1,     3,     1,
       1,     2,     3,     2,     3,     3,     4,     2,     3,     3,
       4
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
#line 135 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1164 "parser.tab.c"
        break;

    case YYSYMBOL_CHARLIT: /* CHARLIT  */
#line 135 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1170 "parser.tab.c"
        break;

    case YYSYMBOL_STRINGLIT: /* STRINGLIT  */
#line 135 "parser.y"
            {free(((*yyvaluep).string).buffer);}
#line 1176 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBERLIT: /* NUMBERLIT  */
#line 134 "parser.y"
            { }
#line 1182 "parser.tab.c"
        break;

    case YYSYMBOL_identifier: /* identifier  */
#line 136 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1188 "parser.tab.c"
        break;

    case YYSYMBOL_declaration_specifiers: /* declaration_specifiers  */
#line 136 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1194 "parser.tab.c"
        break;

    case YYSYMBOL_struct_or_union_specifier: /* struct_or_union_specifier  */
#line 136 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1200 "parser.tab.c"
        break;

    case YYSYMBOL_enum_specifier: /* enum_specifier  */
#line 136 "parser.y"
            {ast_free(((*yyvaluep).node));}
#line 1206 "parser.tab.c"
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
  case 16: /* identifier: IDENT  */
#line 187 "parser.y"
          {(yyval.node) = ast_new_ident((yyvsp[0].string).buffer);}
#line 1476 "parser.tab.c"
    break;

  case 18: /* declaration_specifiers: storage_class_specifier  */
#line 342 "parser.y"
                            {(yyval.node) = ast_set_variable_storage_class(ast_new_variable(), (yyvsp[0].storage_class_specifier));}
#line 1482 "parser.tab.c"
    break;

  case 19: /* declaration_specifiers: type_specifier  */
#line 343 "parser.y"
                     {(yyval.node) = ast_add_variable_type_specifier(ast_new_variable(), (yyvsp[0].type_specifier));}
#line 1488 "parser.tab.c"
    break;

  case 20: /* declaration_specifiers: type_qualifier  */
#line 344 "parser.y"
                     {(yyval.node) = ast_add_variable_type_qualifier(ast_new_variable(), (yyvsp[0].type_qualifier));}
#line 1494 "parser.tab.c"
    break;

  case 21: /* declaration_specifiers: function_specifier  */
#line 345 "parser.y"
                         {(yyval.node) = ast_set_variable_function_specifier(ast_new_variable(), (yyvsp[0].function_specifier));}
#line 1500 "parser.tab.c"
    break;

  case 22: /* declaration_specifiers: declaration_specifiers storage_class_specifier  */
#line 346 "parser.y"
                                                     {(yyval.node) = ast_set_variable_storage_class((yyvsp[-1].node), (yyvsp[0].storage_class_specifier));}
#line 1506 "parser.tab.c"
    break;

  case 23: /* declaration_specifiers: declaration_specifiers type_specifier  */
#line 347 "parser.y"
                                            {(yyval.node) = ast_add_variable_type_specifier((yyvsp[-1].node), (yyvsp[0].type_specifier));}
#line 1512 "parser.tab.c"
    break;

  case 24: /* declaration_specifiers: declaration_specifiers type_qualifier  */
#line 348 "parser.y"
                                            {(yyval.node) = ast_add_variable_type_qualifier((yyvsp[-1].node), (yyvsp[0].type_qualifier));}
#line 1518 "parser.tab.c"
    break;

  case 25: /* declaration_specifiers: declaration_specifiers function_specifier  */
#line 349 "parser.y"
                                                {(yyval.node) = ast_set_variable_function_specifier((yyvsp[-1].node), (yyvsp[0].function_specifier));}
#line 1524 "parser.tab.c"
    break;

  case 29: /* storage_class_specifier: EXTERN  */
#line 364 "parser.y"
           {(yyval.storage_class_specifier) = SC_EXTERN;}
#line 1530 "parser.tab.c"
    break;

  case 30: /* storage_class_specifier: STATIC  */
#line 365 "parser.y"
             {(yyval.storage_class_specifier) = SC_STATIC;}
#line 1536 "parser.tab.c"
    break;

  case 31: /* storage_class_specifier: AUTO  */
#line 366 "parser.y"
           {(yyval.storage_class_specifier) = SC_AUTO;}
#line 1542 "parser.tab.c"
    break;

  case 32: /* storage_class_specifier: REGISTER  */
#line 367 "parser.y"
               {(yyval.storage_class_specifier) = SC_REGISTER;}
#line 1548 "parser.tab.c"
    break;

  case 33: /* type_specifier: VOID  */
#line 373 "parser.y"
         {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_VOID};}
#line 1554 "parser.tab.c"
    break;

  case 34: /* type_specifier: CHAR  */
#line 374 "parser.y"
           {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_CHAR};}
#line 1560 "parser.tab.c"
    break;

  case 35: /* type_specifier: SHORT  */
#line 375 "parser.y"
            {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_SHORT};}
#line 1566 "parser.tab.c"
    break;

  case 36: /* type_specifier: INT  */
#line 376 "parser.y"
          {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_INT};}
#line 1572 "parser.tab.c"
    break;

  case 37: /* type_specifier: LONG  */
#line 377 "parser.y"
           {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_LONG};}
#line 1578 "parser.tab.c"
    break;

  case 38: /* type_specifier: FLOAT  */
#line 378 "parser.y"
            {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_FLOAT};}
#line 1584 "parser.tab.c"
    break;

  case 39: /* type_specifier: DOUBLE  */
#line 379 "parser.y"
             {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_DOUBLE};}
#line 1590 "parser.tab.c"
    break;

  case 40: /* type_specifier: SIGNED  */
#line 380 "parser.y"
             {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_SIGNED};}
#line 1596 "parser.tab.c"
    break;

  case 41: /* type_specifier: UNSIGNED  */
#line 381 "parser.y"
               {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_UNSIGNED};}
#line 1602 "parser.tab.c"
    break;

  case 42: /* type_specifier: _BOOL  */
#line 382 "parser.y"
            {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_BOOL};}
#line 1608 "parser.tab.c"
    break;

  case 43: /* type_specifier: _COMPLEX  */
#line 383 "parser.y"
               {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_COMPLEX};}
#line 1614 "parser.tab.c"
    break;

  case 44: /* type_specifier: struct_or_union_specifier  */
#line 384 "parser.y"
                                {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_STRUCT_OR_UNION, .custom = (yyvsp[0].node)};}
#line 1620 "parser.tab.c"
    break;

  case 45: /* type_specifier: enum_specifier  */
#line 385 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = SCLR_ENUM, .custom = (yyvsp[0].node)};}
#line 1626 "parser.tab.c"
    break;

  case 46: /* type_qualifier: CONST  */
#line 391 "parser.y"
          {(yyval.type_qualifier) = TQ_CONST;}
#line 1632 "parser.tab.c"
    break;

  case 47: /* type_qualifier: RESTRICT  */
#line 392 "parser.y"
               {(yyval.type_qualifier) = TQ_RESTRICT;}
#line 1638 "parser.tab.c"
    break;

  case 48: /* type_qualifier: VOLATILE  */
#line 393 "parser.y"
               {(yyval.type_qualifier) = TQ_VOLATILE;}
#line 1644 "parser.tab.c"
    break;

  case 49: /* function_specifier: INLINE  */
#line 398 "parser.y"
           {(yyval.function_specifier) = FS_INLINE;}
#line 1650 "parser.tab.c"
    break;

  case 84: /* pointer: '*'  */
#line 483 "parser.y"
        {}
#line 1656 "parser.tab.c"
    break;

  case 88: /* type_qualifier_list: type_qualifier  */
#line 490 "parser.y"
                   {(yyval.type_qualifier) = (yyvsp[0].type_qualifier);}
#line 1662 "parser.tab.c"
    break;

  case 89: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 491 "parser.y"
                                         {(yyval.type_qualifier) |= (yyvsp[-1].type_qualifier);}
#line 1668 "parser.tab.c"
    break;


#line 1672 "parser.tab.c"

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

#line 548 "parser.y"

