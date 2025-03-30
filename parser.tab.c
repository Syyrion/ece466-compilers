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
  YYSYMBOL_translation_unit = 92,          /* translation_unit  */
  YYSYMBOL_external_declaration = 93,      /* external_declaration  */
  YYSYMBOL_function_definition = 94,       /* function_definition  */
  YYSYMBOL_95_1 = 95,                      /* @1  */
  YYSYMBOL_96_2 = 96,                      /* @2  */
  YYSYMBOL_declaration_list = 97,          /* declaration_list  */
  YYSYMBOL_compound_statement = 98,        /* compound_statement  */
  YYSYMBOL_block_item_list = 99,           /* block_item_list  */
  YYSYMBOL_block_item = 100,               /* block_item  */
  YYSYMBOL_statement = 101,                /* statement  */
  YYSYMBOL_102_3 = 102,                    /* $@3  */
  YYSYMBOL_expression_statement = 103,     /* expression_statement  */
  YYSYMBOL_identifier = 104,               /* identifier  */
  YYSYMBOL_string_literal = 105,           /* string_literal  */
  YYSYMBOL_constant = 106,                 /* constant  */
  YYSYMBOL_primary_expression = 107,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 108,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 109, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 110,         /* unary_expression  */
  YYSYMBOL_cast_expression = 111,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 112, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 113,      /* additive_expression  */
  YYSYMBOL_shift_expression = 114,         /* shift_expression  */
  YYSYMBOL_relational_expression = 115,    /* relational_expression  */
  YYSYMBOL_equality_expression = 116,      /* equality_expression  */
  YYSYMBOL_and_expression = 117,           /* and_expression  */
  YYSYMBOL_xor_expression = 118,           /* xor_expression  */
  YYSYMBOL_or_expression = 119,            /* or_expression  */
  YYSYMBOL_logical_and_expression = 120,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 121,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 122,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 123,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 124,      /* assignment_operator  */
  YYSYMBOL_expression = 125,               /* expression  */
  YYSYMBOL_constant_expression = 126,      /* constant_expression  */
  YYSYMBOL_declaration = 127,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 128,   /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 129,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 130,           /* type_specifier  */
  YYSYMBOL_type_qualifier = 131,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 132,       /* function_specifier  */
  YYSYMBOL_init_declarator_list = 133,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 134,          /* init_declarator  */
  YYSYMBOL_declarator = 135,               /* declarator  */
  YYSYMBOL_direct_declarator = 136,        /* direct_declarator  */
  YYSYMBOL_pointer = 137,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 138,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 139,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 140,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 141,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 142,          /* identifier_list  */
  YYSYMBOL_type_name = 143,                /* type_name  */
  YYSYMBOL_abstract_declarator = 144,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 145, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 146,              /* initializer  */
  YYSYMBOL_struct_or_union_specifier = 147, /* struct_or_union_specifier  */
  YYSYMBOL_148_4 = 148,                    /* @4  */
  YYSYMBOL_struct_or_union = 149,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 150,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 151,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 152, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 153,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 154,        /* struct_declarator  */
  YYSYMBOL_enum_specifier = 155,           /* enum_specifier  */
  YYSYMBOL_enumerator_list = 156,          /* enumerator_list  */
  YYSYMBOL_enumerator = 157                /* enumerator  */
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
#define YYLAST   1194

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  200
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  299

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
       0,   196,   196,   197,   201,   205,   249,   248,   297,   296,
     346,   347,   351,   352,   356,   357,   361,   400,   405,   405,
     406,   411,   417,   423,   427,   431,   432,   436,   437,   438,
     439,   444,   445,   446,   447,   448,   449,   450,   451,   455,
     456,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   475,   476,   480,   481,   482,   483,   487,
     488,   489,   493,   494,   495,   499,   500,   501,   502,   503,
     507,   508,   509,   513,   514,   517,   518,   521,   522,   526,
     527,   531,   532,   536,   537,   541,   542,   546,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   556,   560,   561,
     565,   573,   579,   585,   586,   587,   588,   589,   590,   591,
     592,   597,   598,   599,   600,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   615,   616,   617,   618,   624,   625,
     626,   631,   636,   637,   641,   642,   646,   647,   651,   652,
     653,   654,   665,   667,   668,   672,   673,   674,   675,   679,
     680,   685,   690,   691,   703,   716,   727,   743,   744,   756,
     757,   765,   766,   767,   771,   772,   773,   774,   775,   778,
     779,   780,   781,   789,   794,   796,   795,   830,   846,   847,
     851,   852,   856,   865,   866,   867,   868,   872,   873,   877,
     878,   879,   886,   887,   888,   889,   890,   894,   895,   899,
     900
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
  "$accept", "translation_unit", "external_declaration",
  "function_definition", "@1", "@2", "declaration_list",
  "compound_statement", "block_item_list", "block_item", "statement",
  "$@3", "expression_statement", "identifier", "string_literal",
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
  "direct_abstract_declarator", "initializer", "struct_or_union_specifier",
  "@4", "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-188)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-7)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1063,  -188,  -188,  -188,  -188,    31,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,   876,  -188,  -188,  -188,   755,  -188,  -188,
    -188,  -188,  -188,    39,  -188,  -188,    21,   -40,  -188,  -188,
    -188,    13,    78,  -188,  -188,  -188,  -188,  -188,    73,  -188,
     910,    15,    18,   -35,  1129,   -45,     7,  -188,    21,   -11,
    -188,  -188,    78,  -188,    13,   571,    -4,  1063,  -188,   755,
     837,   450,    15,  -188,  -188,  -188,   641,  -188,   192,   571,
    -188,    23,    27,  -188,  -188,  -188,  -188,   -19,  -188,  -188,
    -188,   650,   650,   650,   662,   437,   571,   571,   571,   571,
     571,   571,  -188,  -188,  -188,  -188,   191,   275,  -188,    64,
      87,    99,    54,   189,    38,    48,    57,   109,     1,  -188,
    -188,  -188,   279,  -188,    -4,  -188,  -188,  -188,   797,   102,
     100,  -188,    58,  -188,   111,  1129,  -188,  -188,   571,  -188,
    -188,   104,    82,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
      26,   571,  -188,  -188,  -188,   437,  -188,  -188,   101,   125,
     989,  -188,  -188,  -188,  -188,  -188,  -188,    21,  -188,  -188,
     529,   571,    21,  -188,  -188,  -188,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,   571,   571,   571,   571,   571,   571,
     571,   571,   571,   571,  -188,  -188,   358,  -188,  -188,    -4,
    -188,    85,  -188,  -188,   715,   541,  -188,    49,  -188,    86,
    -188,  1063,  -188,    21,  -188,  1096,  -188,   571,  -188,     4,
    -188,   130,  -188,   571,   571,   949,   122,  -188,  -188,  -188,
     103,  -188,    51,  -188,  -188,  -188,  -188,  -188,    64,    64,
      87,    87,    99,    99,    99,    99,    54,    54,   189,    38,
      48,    57,   109,   -31,  -188,  -188,  -188,  -188,  -188,   136,
     148,  -188,   147,    86,  1029,   558,  -188,  -188,  -188,  -188,
    -188,  -188,  -188,  -188,  -188,   571,  -188,   571,  -188,  -188,
    -188,  -188,   151,  -188,   154,  -188,  -188,  -188,  -188
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   113,   116,   128,   121,     0,   111,   120,   131,   118,
     119,   114,   129,   117,   122,   112,   178,   179,   123,   115,
     130,   124,   125,     0,     2,     4,     5,     0,   105,   103,
     104,   106,   126,     0,   127,    23,     0,   192,     1,     3,
     102,     0,   145,   138,   109,   107,   108,   110,     0,   132,
     134,   136,     0,   177,     0,   199,     0,   197,     0,     0,
     149,   147,   146,   101,     0,     0,     0,     8,    10,     0,
       0,     0,   137,   175,   183,   184,     0,   180,     0,     0,
     193,     0,     0,   139,   150,   148,   133,   134,    25,    24,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    29,    28,    31,    41,    53,    55,    59,
      62,    65,    70,    73,    75,    77,    79,    81,    83,    85,
     173,   135,    18,     7,     0,    11,   142,   157,   155,     0,
     151,   152,     0,   140,     0,     0,   174,   181,     0,   185,
     186,   189,     0,   187,    53,   100,   200,   195,   198,   194,
       0,     0,    42,    43,    52,     0,    50,    98,     0,     0,
     159,    44,    45,    46,    47,    48,    49,     0,    37,    38,
       0,     0,     0,    88,    89,    90,    91,    92,    93,    94,
      95,    97,    96,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,    22,    18,    14,    17,     0,
      20,     0,    16,     9,     0,     0,   154,   161,   156,   162,
     144,     0,   143,     0,   141,     0,   190,     0,   182,     0,
     196,     0,    30,     0,     0,     0,   161,   160,    36,    33,
       0,    39,     0,    35,    86,    56,    57,    58,    60,    61,
      63,    64,    67,    69,    66,    68,    71,    72,    74,    76,
      78,    80,    82,     0,    12,    15,    19,    21,   169,     0,
       0,   165,     0,   163,     0,     0,   153,   158,   176,   191,
     188,    51,    99,    54,    34,     0,    32,     0,   171,   164,
     166,   170,     0,   167,     0,    40,    84,   172,   168
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -188,  -188,   212,  -188,  -188,  -188,  -188,  -104,  -188,    30,
    -188,  -188,  -188,    -5,  -188,  -188,  -188,  -188,  -188,   -54,
      90,    28,    24,   -12,    32,    40,    44,    37,    45,    47,
    -188,   -77,   -62,  -188,   -71,  -123,   -42,     5,   -15,    42,
       8,   -13,  -188,   177,   -21,   -48,   -29,  -188,   -69,  -188,
      29,  -188,    92,   -82,  -187,  -188,  -188,  -188,  -188,   120,
     -66,   -76,  -188,    35,  -188,   200,   -58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    23,    24,    25,    66,   124,    67,   123,   206,   207,
     208,   209,   210,   102,   103,   104,   105,   106,   240,   144,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   157,   184,   158,   146,    26,   128,    28,    29,
      30,    31,    48,    49,    59,    51,    52,    62,   269,   130,
     131,   132,   159,   270,   219,   121,    32,   135,    33,    76,
      77,    78,   142,   143,    34,    56,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      37,   129,   145,   120,    72,    27,    50,    35,    68,   134,
     137,   107,    44,    61,    47,   226,    35,   107,   202,   160,
     213,    35,    43,   148,    35,   125,    35,    58,    27,    35,
     273,    55,    73,    85,    35,    46,    43,   152,   153,   154,
     156,   107,    53,    87,   233,    79,   218,    43,    87,   273,
      60,   211,    35,    55,    44,    69,    47,   141,   287,    43,
      83,   145,    75,   122,    43,   127,   192,   193,   107,    45,
      84,    65,    69,    43,    41,    80,    55,    46,   237,   160,
     212,    42,    81,    41,    75,    70,   140,    71,    41,   203,
      42,   147,   148,   138,   230,   149,    74,   107,    36,   217,
     242,   107,   150,    75,   279,   266,    54,   216,   241,   190,
     191,    45,     3,    44,   198,    47,   107,   107,    74,   214,
     139,   215,   244,    43,   286,   201,   233,    69,    12,   222,
     107,   236,   263,   223,   199,   211,    46,    74,   194,   195,
      20,   185,    63,    75,   200,    55,   186,   187,    64,   107,
     145,   228,   107,   272,   267,    42,   274,   229,   275,   137,
     233,   107,   238,    75,   212,   188,   189,   243,   140,    72,
      45,   282,   232,   220,   284,   221,   233,    74,   285,   107,
     252,   253,   254,   255,   224,   217,   161,   162,   163,   164,
     165,   166,   235,   227,   215,    35,   234,    74,   167,   168,
     169,   281,   139,   196,   197,   292,   236,   288,   141,    43,
     296,    69,    43,   294,   250,   251,   248,   249,   277,   289,
     290,   107,   297,   295,    43,     2,     3,   298,   256,   257,
       4,   107,     5,    75,     7,    39,   265,   260,   258,     9,
      10,    86,    12,   259,    13,    14,   261,   231,    16,   262,
     276,    17,    18,    19,    20,   225,    21,    22,    82,     0,
       0,   170,    41,   171,   280,   172,     0,    74,     0,    42,
       0,     0,     0,     0,     0,   245,   246,   247,     0,     0,
       0,   138,    35,    88,    89,    90,     0,    91,    92,     0,
       0,     0,     0,     0,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,     0,     0,     0,     0,     1,    93,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,   283,     8,     9,    10,    11,    12,
       0,    13,    14,    94,    15,    16,     0,     0,    17,    18,
      19,    20,     0,    21,    22,     0,     0,   204,   205,    95,
       0,     0,     0,     0,     0,    96,    97,    98,    99,   100,
     101,    35,    88,    89,    90,   183,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,    93,     0,
       0,     2,     3,     0,     0,     0,     4,     0,     5,     6,
       7,     0,     0,     0,     8,     9,    10,    11,    12,     0,
      13,    14,    94,    15,    16,     0,     0,    17,    18,    19,
      20,     0,    21,    22,     0,     0,   264,   205,    95,     0,
       0,     0,     0,     0,    96,    97,    98,    99,   100,   101,
      35,    88,    89,    90,     0,    91,    92,     0,     0,     0,
       0,     0,     0,    35,    88,    89,    90,     0,    91,    92,
       0,     0,     0,     0,     0,     0,     0,    93,     0,     0,
       2,     3,     0,     0,     0,     4,     0,     5,     0,     7,
      93,     0,     0,     0,     9,    10,     0,    12,     0,    13,
      14,    94,     0,    16,     0,     0,    17,    18,    19,    20,
       0,    21,    22,     0,    94,     0,     0,    95,     0,     0,
       0,     0,     0,    96,    97,    98,    99,   100,   101,     0,
      95,     0,     0,   133,     0,     0,    96,    97,    98,    99,
     100,   101,    35,    88,    89,    90,     0,    91,    92,     0,
       0,     0,     0,     0,    35,    88,    89,    90,     0,    91,
      92,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,    35,    88,    89,    90,     0,    91,    92,     0,     0,
       0,    93,     0,     0,    35,    88,    89,    90,     0,    91,
      92,     0,     0,    94,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,    95,
     239,    93,     0,     0,     0,    96,    97,    98,    99,   100,
     101,    95,    94,     0,   271,     0,     0,    96,    97,    98,
      99,   100,   101,     0,     0,    94,     0,     0,    95,     0,
       0,   293,     0,     0,    96,    97,    98,    99,   100,   101,
       0,    95,     0,     0,     0,     0,     0,    96,    97,    98,
      99,   100,   101,    35,    88,    89,    90,     0,    91,    92,
       0,     0,     0,     0,     0,    35,    88,    89,    90,     0,
      91,    92,     0,     0,     2,     3,     0,     0,     0,     4,
      93,     5,     0,     7,     0,     0,     0,     0,     9,    10,
       0,    12,    93,    13,    14,     0,     0,    16,     0,     0,
      17,    18,    19,    20,    94,    21,    22,     0,     0,   136,
       0,     0,     0,     0,     0,     0,    94,     0,    35,     0,
     151,     0,     0,     0,     0,     0,    96,    97,    98,    99,
     100,   101,   155,     0,     0,     0,     0,     0,    96,    97,
      98,    99,   100,   101,     1,     0,     0,     0,     2,     3,
       0,     0,     0,     4,     0,     5,     6,     7,    35,     0,
       0,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,    16,     0,     0,    17,    18,    19,    20,     0,    21,
      22,     0,     0,     0,     1,   214,   268,   215,     2,     3,
       0,     0,    42,     4,     0,     5,     6,     7,     0,     0,
      35,     8,     9,    10,    11,    12,     0,    13,    14,     0,
      15,    16,     0,     0,    17,    18,    19,    20,     0,    21,
      22,     0,     0,     0,    40,    41,     1,     0,     0,     0,
       2,     3,    42,     0,     0,     4,     0,     5,     6,     7,
      35,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,    16,     0,     0,    17,    18,    19,    20,
       0,    21,    22,     0,     0,     0,     1,   214,     0,   215,
       2,     3,     0,     0,    42,     4,    38,     5,     6,     7,
       0,     0,     0,     8,     9,    10,    11,    12,     0,    13,
      14,     0,    15,    16,     0,     0,    17,    18,    19,    20,
       0,    21,    22,     0,     0,     1,     0,     0,   126,     2,
       3,     0,     0,     0,     4,     0,     5,     6,     7,     0,
       0,     0,     8,     9,    10,    11,    12,     0,    13,    14,
       0,    15,    16,     0,     0,    17,    18,    19,    20,     1,
      21,    22,     0,     2,     3,     0,     0,     0,     4,     0,
       5,     6,     7,     0,     0,     0,     8,     9,    10,    11,
      12,     0,    13,    14,     0,    15,    16,     0,     0,    17,
      18,    19,    20,     0,    21,    22,     0,    -6,     1,     0,
       0,     0,     2,     3,     0,     0,     0,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
      65,    13,    14,     0,    15,    16,     0,     0,    17,    18,
      19,    20,     0,    21,    22,     0,     0,     0,     0,   235,
     268,   215,     2,     3,     0,     0,    42,     4,     0,     5,
       0,     7,     0,     0,     0,     0,     9,    10,     0,    12,
       0,    13,    14,     0,     0,    16,     0,     0,    17,    18,
      19,    20,     0,    21,    22,     0,     0,     0,     1,   235,
       0,   215,     2,     3,     0,     0,    42,     4,     0,     5,
       6,     7,     0,     0,     0,     8,     9,    10,    11,    12,
       0,    13,    14,     0,    15,    16,     0,     0,    17,    18,
      19,    20,     1,    21,    22,     0,     2,     3,     0,     0,
     291,     4,     0,     5,     6,     7,     0,     0,     0,     8,
       9,    10,    11,    12,     0,    13,    14,     0,    15,    16,
       0,     0,    17,    18,    19,    20,     0,    21,    22,     2,
       3,     0,     0,     0,     4,     0,     5,     0,     7,     0,
       0,     0,     0,     9,    10,     0,    12,     0,    13,    14,
       0,     0,    16,     0,     0,    17,    18,    19,    20,     0,
      21,    22,     2,     3,   278,     0,     0,     4,     0,     5,
       0,     7,     0,     0,     0,     0,     9,    10,     0,    12,
       0,    13,    14,     0,     0,    16,     0,     0,    17,    18,
      19,    20,     0,    21,    22
};

static const yytype_int16 yycheck[] =
{
       5,    70,    79,    65,    52,     0,    27,     3,    50,    71,
      76,    65,    27,    42,    27,   138,     3,    71,    17,    95,
     124,     3,    27,    81,     3,    67,     3,    67,    23,     3,
     217,    36,    67,    62,     3,    27,    41,    91,    92,    93,
      94,    95,     3,    64,    75,    90,   128,    52,    69,   236,
      42,   122,     3,    58,    69,    50,    69,    78,    89,    64,
      71,   138,    54,    67,    69,    70,    12,    13,   122,    27,
      62,    90,    67,    78,    70,    68,    81,    69,   160,   155,
     122,    77,    75,    70,    76,    70,    78,    72,    70,    88,
      77,    68,   150,    89,    68,    68,    54,   151,    67,   128,
     171,   155,    75,    95,   227,   209,    67,   128,   170,    10,
      11,    69,    34,   128,    76,   128,   170,   171,    76,    70,
      78,    72,   184,   128,    73,    16,    75,   122,    50,    71,
     184,   160,   203,    75,    86,   206,   128,    95,    84,    85,
      62,    77,    69,   135,    87,   150,    82,    83,    75,   203,
     227,    69,   206,   215,    69,    77,    70,    75,    72,   225,
      75,   215,   167,   155,   206,    78,    79,   172,   160,   217,
     128,   233,    71,    71,    71,    75,    75,   135,    75,   233,
     192,   193,   194,   195,    73,   214,    96,    97,    98,    99,
     100,   101,    70,    89,    72,     3,    71,   155,     7,     8,
       9,    71,   160,    14,    15,   274,   235,    71,   229,   214,
     287,   206,   217,   275,   190,   191,   188,   189,   223,    71,
      73,   275,    71,   285,   229,    33,    34,    73,   196,   197,
      38,   285,    40,   225,    42,    23,   206,   200,   198,    47,
      48,    64,    50,   199,    52,    53,   201,   155,    56,   202,
     221,    59,    60,    61,    62,   135,    64,    65,    58,    -1,
      -1,    70,    70,    72,   229,    74,    -1,   225,    -1,    77,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,    -1,    -1,
      -1,    89,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    -1,    -1,    -1,    -1,    29,    30,
      -1,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    -1,    -1,   234,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    55,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    64,    65,    -1,    -1,    68,    69,    70,
      -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      81,     3,     4,     5,     6,    90,     8,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,    33,    34,    -1,    -1,    -1,    38,    -1,    40,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    54,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    -1,    -1,    68,    69,    70,    -1,
      -1,    -1,    -1,    -1,    76,    77,    78,    79,    80,    81,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    -1,    38,    -1,    40,    -1,    42,
      30,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,
      53,    54,    -1,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    -1,    54,    -1,    -1,    70,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    79,    80,    81,    -1,
      70,    -1,    -1,    73,    -1,    -1,    76,    77,    78,    79,
      80,    81,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    30,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    54,    -1,    -1,    -1,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    70,
      71,    30,    -1,    -1,    -1,    76,    77,    78,    79,    80,
      81,    70,    54,    -1,    73,    -1,    -1,    76,    77,    78,
      79,    80,    81,    -1,    -1,    54,    -1,    -1,    70,    -1,
      -1,    73,    -1,    -1,    76,    77,    78,    79,    80,    81,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,
      79,    80,    81,     3,     4,     5,     6,    -1,     8,     9,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,
      30,    40,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      -1,    50,    30,    52,    53,    -1,    -1,    56,    -1,    -1,
      59,    60,    61,    62,    54,    64,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,     3,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    77,    78,    79,
      80,    81,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,
      78,    79,    80,    81,    29,    -1,    -1,    -1,    33,    34,
      -1,    -1,    -1,    38,    -1,    40,    41,    42,     3,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      65,    -1,    -1,    -1,    29,    70,    71,    72,    33,    34,
      -1,    -1,    77,    38,    -1,    40,    41,    42,    -1,    -1,
       3,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      65,    -1,    -1,    -1,    69,    70,    29,    -1,    -1,    -1,
      33,    34,    77,    -1,    -1,    38,    -1,    40,    41,    42,
       3,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    -1,    29,    70,    -1,    72,
      33,    34,    -1,    -1,    77,    38,     0,    40,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    29,    -1,    -1,    71,    33,
      34,    -1,    -1,    -1,    38,    -1,    40,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    29,
      64,    65,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      40,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65,    -1,    67,    29,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      90,    52,    53,    -1,    55,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    64,    65,    -1,    -1,    -1,    -1,    70,
      71,    72,    33,    34,    -1,    -1,    77,    38,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    64,    65,    -1,    -1,    -1,    29,    70,
      -1,    72,    33,    34,    -1,    -1,    77,    38,    -1,    40,
      41,    42,    -1,    -1,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,    60,
      61,    62,    29,    64,    65,    -1,    33,    34,    -1,    -1,
      71,    38,    -1,    40,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    59,    60,    61,    62,    -1,    64,    65,    33,
      34,    -1,    -1,    -1,    38,    -1,    40,    -1,    42,    -1,
      -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,
      -1,    -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65,    33,    34,    68,    -1,    -1,    38,    -1,    40,
      -1,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    33,    34,    38,    40,    41,    42,    46,    47,
      48,    49,    50,    52,    53,    55,    56,    59,    60,    61,
      62,    64,    65,    92,    93,    94,   127,   128,   129,   130,
     131,   132,   147,   149,   155,     3,    67,   104,     0,    93,
      69,    70,    77,   104,   129,   130,   131,   132,   133,   134,
     135,   136,   137,     3,    67,   104,   156,   157,    67,   135,
     131,   137,   138,    69,    75,    90,    95,    97,   127,   128,
      70,    72,   136,    67,   130,   131,   150,   151,   152,    90,
      68,    75,   156,    71,   131,   137,   134,   135,     4,     5,
       6,     8,     9,    30,    54,    70,    76,    77,    78,    79,
      80,    81,   104,   105,   106,   107,   108,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   146,    67,    98,    96,   127,    71,   104,   128,   139,
     140,   141,   142,    73,   123,   148,    68,   151,    89,   130,
     131,   135,   153,   154,   110,   122,   126,    68,   157,    68,
      75,    70,   110,   110,   110,    70,   110,   123,   125,   143,
     152,   111,   111,   111,   111,   111,   111,     7,     8,     9,
      70,    72,    74,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    90,   124,    77,    82,    83,    78,    79,
      10,    11,    12,    13,    84,    85,    14,    15,    76,    86,
      87,    16,    17,    88,    68,    69,    99,   100,   101,   102,
     103,   125,   127,    98,    70,    72,   135,   137,   144,   145,
      71,    75,    71,    75,    73,   150,   126,    89,    69,    75,
      68,   143,    71,    75,    71,    70,   137,   144,   104,    71,
     109,   123,   125,   104,   123,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   114,   115,   115,   116,   117,
     118,   119,   120,   125,    68,   100,    98,    69,    71,   139,
     144,    73,   123,   145,    70,    72,   141,   104,    68,   126,
     154,    71,   123,   111,    71,    75,    73,    89,    71,    71,
      73,    71,   139,    73,   123,   123,   122,    71,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    95,    94,    96,    94,
      97,    97,    98,    98,    99,    99,   100,   100,   102,   101,
     101,   103,   103,   104,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   112,   113,
     113,   113,   114,   114,   114,   115,   115,   115,   115,   115,
     116,   116,   116,   117,   117,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   124,   124,   124,   125,   125,
     126,   127,   127,   128,   128,   128,   128,   128,   128,   128,
     128,   129,   129,   129,   129,   130,   130,   130,   130,   130,
     130,   130,   130,   130,   130,   130,   130,   130,   131,   131,
     131,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     136,   136,   136,   136,   136,   137,   137,   137,   137,   138,
     138,   139,   140,   140,   141,   141,   141,   142,   142,   143,
     143,   144,   144,   144,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   146,   147,   148,   147,   147,   149,   149,
     150,   150,   151,   152,   152,   152,   152,   153,   153,   154,
     154,   154,   155,   155,   155,   155,   155,   156,   156,   157,
     157
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     0,     4,     0,     5,
       1,     2,     3,     2,     1,     2,     1,     1,     0,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     3,     4,     3,     3,     2,     2,     1,
       3,     1,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     2,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     2,     1,     1,     1,     1,     2,     2,     2,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     2,     1,     3,
       3,     4,     3,     4,     4,     1,     2,     2,     3,     1,
       2,     1,     1,     3,     2,     1,     2,     1,     3,     1,
       2,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4,     1,     4,     0,     6,     2,     1,     1,
       1,     2,     3,     1,     1,     2,     2,     1,     3,     1,
       2,     3,     2,     4,     5,     5,     6,     1,     3,     1,
       3
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
#line 20 "parser.y"
{
    st_init();
    ast_init();
}

#line 1459 "parser.tab.c"

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
  case 4: /* external_declaration: function_definition  */
#line 202 "parser.y"
    {

    }
#line 1664 "parser.tab.c"
    break;

  case 5: /* external_declaration: declaration  */
#line 206 "parser.y"
    {
        // alias for declaration specs
        declaration_specifiers_t *ds = &(yyvsp[0].declaration_package).declaration_specifiers;

        // apply extern if needed since this is an external declaration
        if (!ds->storage_class)
            ds->storage_class = SC_EXTERN;

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
                    fprintf(stderr, "%s:%d: Error: conflicting type on already existing variable `%s`\n", filename, line_num, other->name);
                    exit(EXIT_FAILURE);
                }
            }
            else
                st_add(NS_VARIABLE, var);

            // ! debug
            printf("EXTERNAL DECLARATION: ");
            ast_print_variable(var, 0);
        }
    }
#line 1708 "parser.tab.c"
    break;

  case 6: /* @1: %empty  */
#line 249 "parser.y"
    {
        if (!(yyvsp[-1].declaration_specifiers).storage_class)
            (yyvsp[-1].declaration_specifiers).storage_class = SC_EXTERN;

        ast_node_t *type = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        ast_node_t *fn = ast_ident_to_variable((yyvsp[0].declarator_helper).oldest, (yyvsp[-1].declaration_specifiers).storage_class);
        (yyvsp[0].declarator_helper).newest->next = type;

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

        (yyval.node) = fn;
    }
#line 1752 "parser.tab.c"
    break;

  case 7: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 289 "parser.y"
    {
        (yyvsp[-1].node)->next->function.definition = (function_definition_t){.namespaces = st_pop()};
        // ! debug
        printf("FUNCTION DEFINITION (1): ");
        ast_print_variable((yyvsp[-1].node), 0);
    }
#line 1763 "parser.tab.c"
    break;

  case 8: /* @2: %empty  */
#line 297 "parser.y"
    {
        if (!(yyvsp[-2].declaration_specifiers).storage_class)
            (yyvsp[-2].declaration_specifiers).storage_class = SC_EXTERN;

        ast_node_t *type = ast_new_type((yyvsp[-2].declaration_specifiers).type_specifier, (yyvsp[-2].declaration_specifiers).type_qualifier);
        ast_node_t *fn = ast_ident_to_variable((yyvsp[-1].declarator_helper).oldest, (yyvsp[-2].declaration_specifiers).storage_class);
        (yyvsp[-1].declarator_helper).newest->next = type;

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

        (yyval.node) = fn;
    }
#line 1807 "parser.tab.c"
    break;

  case 9: /* function_definition: declaration_specifiers declarator declaration_list @2 compound_statement  */
#line 337 "parser.y"
    {
        (yyvsp[-2].node)->next->function.definition = (function_definition_t){.namespaces = st_pop()};
        // ! debug
        printf("FUNCTION DEFINITION (2): ");
        ast_print_variable((yyvsp[-1].node), 0);
    }
#line 1818 "parser.tab.c"
    break;

  case 16: /* block_item: declaration  */
#line 362 "parser.y"
    {
        // alias for declaration specs
        declaration_specifiers_t *ds = &(yyvsp[0].declaration_package).declaration_specifiers;

        // apply extern if needed since this is an external declaration
        if (!ds->storage_class)
            ds->storage_class = SC_AUTO;

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
#line 1861 "parser.tab.c"
    break;

  case 18: /* $@3: %empty  */
#line 405 "parser.y"
        {st_push();}
#line 1867 "parser.tab.c"
    break;

  case 21: /* expression_statement: expression ';'  */
#line 412 "parser.y"
        {
            // ! debug
            printf("EXPRESSION: ");
            ast_print_expression((yyvsp[-1].node), 0);
        }
#line 1877 "parser.tab.c"
    break;

  case 23: /* identifier: IDENT  */
#line 423 "parser.y"
              {(yyval.node) = ast_new_ident((yyvsp[0].string).buffer);}
#line 1883 "parser.tab.c"
    break;

  case 24: /* string_literal: STRINGLIT  */
#line 427 "parser.y"
                  {(yyval.node) = ast_new_stringlit((yyvsp[0].string));}
#line 1889 "parser.tab.c"
    break;

  case 25: /* constant: CHARLIT  */
#line 431 "parser.y"
                {(yyval.node) = ast_new_charlit((yyvsp[0].string).buffer[0]);}
#line 1895 "parser.tab.c"
    break;

  case 26: /* constant: NUMBERLIT  */
#line 432 "parser.y"
                    {(yyval.node) = ast_new_numberlit((yyvsp[0].number));}
#line 1901 "parser.tab.c"
    break;

  case 30: /* primary_expression: '(' expression ')'  */
#line 439 "parser.y"
                             {(yyval.node) = (yyvsp[-1].node);}
#line 1907 "parser.tab.c"
    break;

  case 32: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 445 "parser.y"
                                                {(yyval.node) = ast_new_unary_op('*', ast_new_binary_op('+', (yyvsp[-3].node), (yyvsp[-1].node)));}
#line 1913 "parser.tab.c"
    break;

  case 33: /* postfix_expression: postfix_expression '(' ')'  */
#line 446 "parser.y"
                                     {(yyval.node) = ast_new_function_call((yyvsp[-2].node), ast_list_new());}
#line 1919 "parser.tab.c"
    break;

  case 34: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 447 "parser.y"
                                                              {(yyval.node) = ast_new_function_call((yyvsp[-3].node), (yyvsp[-1].node_list));}
#line 1925 "parser.tab.c"
    break;

  case 35: /* postfix_expression: postfix_expression '.' identifier  */
#line 448 "parser.y"
                                            {(yyval.node) = ast_new_binary_op('.', (yyvsp[-2].node), (yyvsp[0].node));}
#line 1931 "parser.tab.c"
    break;

  case 36: /* postfix_expression: postfix_expression "->" identifier  */
#line 449 "parser.y"
                                             {(yyval.node) = ast_new_binary_op('.', ast_new_unary_op('*', (yyvsp[-2].node)), (yyvsp[0].node));}
#line 1937 "parser.tab.c"
    break;

  case 37: /* postfix_expression: postfix_expression "++"  */
#line 450 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(PLUSPLUS, (yyvsp[-1].node));}
#line 1943 "parser.tab.c"
    break;

  case 38: /* postfix_expression: postfix_expression "--"  */
#line 451 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(MINUSMINUS, (yyvsp[-1].node));}
#line 1949 "parser.tab.c"
    break;

  case 39: /* argument_expression_list: assignment_expression  */
#line 455 "parser.y"
                              {(yyval.node_list) = ast_list_add(ast_list_new(), (yyvsp[0].node));}
#line 1955 "parser.tab.c"
    break;

  case 40: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 456 "parser.y"
                                                             {(yyval.node_list) = ast_list_add((yyvsp[-2].node_list), (yyvsp[0].node));}
#line 1961 "parser.tab.c"
    break;

  case 42: /* unary_expression: "++" unary_expression  */
#line 461 "parser.y"
                                {(yyval.node) = ast_new_binary_op(PLUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 1967 "parser.tab.c"
    break;

  case 43: /* unary_expression: "--" unary_expression  */
#line 462 "parser.y"
                                {(yyval.node) = ast_new_binary_op(MINUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 1973 "parser.tab.c"
    break;

  case 44: /* unary_expression: '&' cast_expression  */
#line 463 "parser.y"
                              {(yyval.node) = ast_new_unary_op('&', (yyvsp[0].node));}
#line 1979 "parser.tab.c"
    break;

  case 45: /* unary_expression: '*' cast_expression  */
#line 464 "parser.y"
                              {(yyval.node) = ast_new_unary_op('*', (yyvsp[0].node));}
#line 1985 "parser.tab.c"
    break;

  case 46: /* unary_expression: '+' cast_expression  */
#line 465 "parser.y"
                              {(yyval.node) = ast_new_unary_op('+', (yyvsp[0].node));}
#line 1991 "parser.tab.c"
    break;

  case 47: /* unary_expression: '-' cast_expression  */
#line 466 "parser.y"
                              {(yyval.node) = ast_new_unary_op('-', (yyvsp[0].node));}
#line 1997 "parser.tab.c"
    break;

  case 48: /* unary_expression: '~' cast_expression  */
#line 467 "parser.y"
                              {(yyval.node) = ast_new_unary_op('~', (yyvsp[0].node));}
#line 2003 "parser.tab.c"
    break;

  case 49: /* unary_expression: '!' cast_expression  */
#line 468 "parser.y"
                              {(yyval.node) = ast_new_unary_op('!', (yyvsp[0].node));}
#line 2009 "parser.tab.c"
    break;

  case 50: /* unary_expression: SIZEOF unary_expression  */
#line 469 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(SIZEOF, (yyvsp[0].node));}
#line 2015 "parser.tab.c"
    break;

  case 52: /* unary_expression: ALIGNOF unary_expression  */
#line 471 "parser.y"
                                   {(yyval.node) = ast_new_unary_op(ALIGNOF, (yyvsp[0].node));}
#line 2021 "parser.tab.c"
    break;

  case 54: /* cast_expression: '(' type_name ')' cast_expression  */
#line 476 "parser.y"
                                            {(yyval.node) = ast_new_type_cast((yyvsp[0].node), (yyvsp[-2].node));}
#line 2027 "parser.tab.c"
    break;

  case 56: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 481 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('*', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2033 "parser.tab.c"
    break;

  case 57: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 482 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('/', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2039 "parser.tab.c"
    break;

  case 58: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 483 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('%', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2045 "parser.tab.c"
    break;

  case 60: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 488 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op('+', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2051 "parser.tab.c"
    break;

  case 61: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 489 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op('-', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2057 "parser.tab.c"
    break;

  case 63: /* shift_expression: shift_expression "<<" additive_expression  */
#line 494 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2063 "parser.tab.c"
    break;

  case 64: /* shift_expression: shift_expression ">>" additive_expression  */
#line 495 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2069 "parser.tab.c"
    break;

  case 66: /* relational_expression: relational_expression '<' shift_expression  */
#line 500 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op('<', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2075 "parser.tab.c"
    break;

  case 67: /* relational_expression: relational_expression "<=" shift_expression  */
#line 501 "parser.y"
                                                      {(yyval.node) = ast_new_binary_op(LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2081 "parser.tab.c"
    break;

  case 68: /* relational_expression: relational_expression '>' shift_expression  */
#line 502 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op('>', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2087 "parser.tab.c"
    break;

  case 69: /* relational_expression: relational_expression ">=" shift_expression  */
#line 503 "parser.y"
                                                      {(yyval.node) = ast_new_binary_op(GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2093 "parser.tab.c"
    break;

  case 71: /* equality_expression: equality_expression "==" relational_expression  */
#line 508 "parser.y"
                                                         {(yyval.node) = ast_new_binary_op(EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2099 "parser.tab.c"
    break;

  case 72: /* equality_expression: equality_expression "!=" relational_expression  */
#line 509 "parser.y"
                                                         {(yyval.node) = ast_new_binary_op(NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2105 "parser.tab.c"
    break;

  case 74: /* and_expression: and_expression '&' equality_expression  */
#line 514 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('&', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2111 "parser.tab.c"
    break;

  case 76: /* xor_expression: xor_expression '^' and_expression  */
#line 518 "parser.y"
                                            {(yyval.node) = ast_new_binary_op('^', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2117 "parser.tab.c"
    break;

  case 78: /* or_expression: or_expression '|' xor_expression  */
#line 522 "parser.y"
                                           {(yyval.node) = ast_new_binary_op('|', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2123 "parser.tab.c"
    break;

  case 80: /* logical_and_expression: logical_and_expression "&&" or_expression  */
#line 527 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(LOGAND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2129 "parser.tab.c"
    break;

  case 82: /* logical_or_expression: logical_or_expression "||" logical_and_expression  */
#line 532 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op(LOGOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2135 "parser.tab.c"
    break;

  case 84: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 537 "parser.y"
                                                                          {(yyval.node) = ast_new_ternary_op((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2141 "parser.tab.c"
    break;

  case 86: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 542 "parser.y"
                                                                     {(yyval.node) = ast_new_binary_op((yyvsp[-1].integer), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2147 "parser.tab.c"
    break;

  case 87: /* assignment_operator: '='  */
#line 546 "parser.y"
            {(yyval.integer) = '=';}
#line 2153 "parser.tab.c"
    break;

  case 88: /* assignment_operator: "*="  */
#line 547 "parser.y"
               {(yyval.integer) = PLUSEQ;}
#line 2159 "parser.tab.c"
    break;

  case 89: /* assignment_operator: "/="  */
#line 548 "parser.y"
               {(yyval.integer) = MINUSEQ;}
#line 2165 "parser.tab.c"
    break;

  case 90: /* assignment_operator: "%="  */
#line 549 "parser.y"
               {(yyval.integer) = TIMESEQ;}
#line 2171 "parser.tab.c"
    break;

  case 91: /* assignment_operator: "+="  */
#line 550 "parser.y"
               {(yyval.integer) = DIVEQ;}
#line 2177 "parser.tab.c"
    break;

  case 92: /* assignment_operator: "-="  */
#line 551 "parser.y"
               {(yyval.integer) = MODEQ;}
#line 2183 "parser.tab.c"
    break;

  case 93: /* assignment_operator: "<<="  */
#line 552 "parser.y"
                {(yyval.integer) = SHLEQ;}
#line 2189 "parser.tab.c"
    break;

  case 94: /* assignment_operator: ">>="  */
#line 553 "parser.y"
                {(yyval.integer) = SHREQ;}
#line 2195 "parser.tab.c"
    break;

  case 95: /* assignment_operator: "&="  */
#line 554 "parser.y"
               {(yyval.integer) = ANDEQ;}
#line 2201 "parser.tab.c"
    break;

  case 96: /* assignment_operator: "^="  */
#line 555 "parser.y"
               {(yyval.integer) = XOREQ;}
#line 2207 "parser.tab.c"
    break;

  case 97: /* assignment_operator: "|="  */
#line 556 "parser.y"
               {(yyval.integer) = OREQ;}
#line 2213 "parser.tab.c"
    break;

  case 99: /* expression: expression ',' assignment_expression  */
#line 561 "parser.y"
                                               {(yyval.node) = ast_new_binary_op(',', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2219 "parser.tab.c"
    break;

  case 101: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 574 "parser.y"
    {
        (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_verify_and_simplify_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
        (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
        (yyval.declaration_package) = (yyvsp[-1].declaration_package);
    }
#line 2229 "parser.tab.c"
    break;

  case 102: /* declaration: declaration_specifiers ';'  */
#line 579 "parser.y"
                                 {}
#line 2235 "parser.tab.c"
    break;

  case 103: /* declaration_specifiers: type_specifier  */
#line 585 "parser.y"
                           {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2241 "parser.tab.c"
    break;

  case 104: /* declaration_specifiers: type_qualifier  */
#line 586 "parser.y"
                             {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2247 "parser.tab.c"
    break;

  case 105: /* declaration_specifiers: storage_class_specifier  */
#line 587 "parser.y"
                                      {declspec_init(&(yyval.declaration_specifiers)); declspec_add_storage_class(&(yyval.declaration_specifiers), (yyvsp[0].storage_class_specifier));}
#line 2253 "parser.tab.c"
    break;

  case 106: /* declaration_specifiers: function_specifier  */
#line 588 "parser.y"
                                 {declspec_init(&(yyval.declaration_specifiers)); declspec_add_function_specifier(&(yyval.declaration_specifiers), (yyvsp[0].function_specifier));}
#line 2259 "parser.tab.c"
    break;

  case 107: /* declaration_specifiers: declaration_specifiers type_specifier  */
#line 589 "parser.y"
                                                    {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2265 "parser.tab.c"
    break;

  case 108: /* declaration_specifiers: declaration_specifiers type_qualifier  */
#line 590 "parser.y"
                                                    {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2271 "parser.tab.c"
    break;

  case 109: /* declaration_specifiers: declaration_specifiers storage_class_specifier  */
#line 591 "parser.y"
                                                             {declspec_add_storage_class(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].storage_class_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2277 "parser.tab.c"
    break;

  case 110: /* declaration_specifiers: declaration_specifiers function_specifier  */
#line 592 "parser.y"
                                                        {declspec_add_function_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].function_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2283 "parser.tab.c"
    break;

  case 111: /* storage_class_specifier: EXTERN  */
#line 597 "parser.y"
                   {(yyval.storage_class_specifier) = SC_EXTERN;}
#line 2289 "parser.tab.c"
    break;

  case 112: /* storage_class_specifier: STATIC  */
#line 598 "parser.y"
                     {(yyval.storage_class_specifier) = SC_STATIC;}
#line 2295 "parser.tab.c"
    break;

  case 113: /* storage_class_specifier: AUTO  */
#line 599 "parser.y"
                   {(yyval.storage_class_specifier) = SC_AUTO;}
#line 2301 "parser.tab.c"
    break;

  case 114: /* storage_class_specifier: REGISTER  */
#line 600 "parser.y"
                       {(yyval.storage_class_specifier) = SC_REGISTER;}
#line 2307 "parser.tab.c"
    break;

  case 115: /* type_specifier: VOID  */
#line 606 "parser.y"
                 {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_VOID};}
#line 2313 "parser.tab.c"
    break;

  case 116: /* type_specifier: CHAR  */
#line 607 "parser.y"
                   {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_CHAR};}
#line 2319 "parser.tab.c"
    break;

  case 117: /* type_specifier: SHORT  */
#line 608 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SHORT};}
#line 2325 "parser.tab.c"
    break;

  case 118: /* type_specifier: INT  */
#line 609 "parser.y"
                  {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_INT};}
#line 2331 "parser.tab.c"
    break;

  case 119: /* type_specifier: LONG  */
#line 610 "parser.y"
                   {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_LONG};}
#line 2337 "parser.tab.c"
    break;

  case 120: /* type_specifier: FLOAT  */
#line 611 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_FLOAT};}
#line 2343 "parser.tab.c"
    break;

  case 121: /* type_specifier: DOUBLE  */
#line 612 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_DOUBLE};}
#line 2349 "parser.tab.c"
    break;

  case 122: /* type_specifier: SIGNED  */
#line 613 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SIGNED};}
#line 2355 "parser.tab.c"
    break;

  case 123: /* type_specifier: UNSIGNED  */
#line 614 "parser.y"
                       {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_UNSIGNED};}
#line 2361 "parser.tab.c"
    break;

  case 124: /* type_specifier: _BOOL  */
#line 615 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_BOOL};}
#line 2367 "parser.tab.c"
    break;

  case 125: /* type_specifier: _COMPLEX  */
#line 616 "parser.y"
                       {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_COMPLEX};}
#line 2373 "parser.tab.c"
    break;

  case 126: /* type_specifier: struct_or_union_specifier  */
#line 617 "parser.y"
                                        {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_STRUCT_OR_UNION, .custom = (yyvsp[0].node)};}
#line 2379 "parser.tab.c"
    break;

  case 127: /* type_specifier: enum_specifier  */
#line 618 "parser.y"
                             {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_ENUM, .custom = (yyvsp[0].node)};}
#line 2385 "parser.tab.c"
    break;

  case 128: /* type_qualifier: CONST  */
#line 624 "parser.y"
                  {(yyval.type_qualifier) = TQ_CONST;}
#line 2391 "parser.tab.c"
    break;

  case 129: /* type_qualifier: RESTRICT  */
#line 625 "parser.y"
                       {(yyval.type_qualifier) = TQ_RESTRICT;}
#line 2397 "parser.tab.c"
    break;

  case 130: /* type_qualifier: VOLATILE  */
#line 626 "parser.y"
                       {(yyval.type_qualifier) = TQ_VOLATILE;}
#line 2403 "parser.tab.c"
    break;

  case 131: /* function_specifier: INLINE  */
#line 631 "parser.y"
                   {(yyval.function_specifier) = FS_INLINE;}
#line 2409 "parser.tab.c"
    break;

  case 132: /* init_declarator_list: init_declarator  */
#line 636 "parser.y"
                    {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 2415 "parser.tab.c"
    break;

  case 133: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 637 "parser.y"
                                               {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 2421 "parser.tab.c"
    break;

  case 134: /* init_declarator: declarator  */
#line 641 "parser.y"
               {(yyvsp[0].declarator_helper).initializer = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2427 "parser.tab.c"
    break;

  case 135: /* init_declarator: declarator '=' initializer  */
#line 642 "parser.y"
                                 {(yyvsp[-2].declarator_helper).initializer = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 2433 "parser.tab.c"
    break;

  case 136: /* declarator: direct_declarator  */
#line 646 "parser.y"
                      {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2439 "parser.tab.c"
    break;

  case 137: /* declarator: pointer direct_declarator  */
#line 647 "parser.y"
                                {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2445 "parser.tab.c"
    break;

  case 138: /* direct_declarator: identifier  */
#line 651 "parser.y"
               {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = (yyvsp[0].node);}
#line 2451 "parser.tab.c"
    break;

  case 139: /* direct_declarator: '(' declarator ')'  */
#line 652 "parser.y"
                         {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2457 "parser.tab.c"
    break;

  case 140: /* direct_declarator: direct_declarator '[' ']'  */
#line 653 "parser.y"
                                {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2463 "parser.tab.c"
    break;

  case 141: /* direct_declarator: direct_declarator '[' assignment_expression ']'  */
#line 654 "parser.y"
                                                      {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node));

        // fprintf(stderr, "%d", $$.newest->array.size->kind);
     (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2472 "parser.tab.c"
    break;

  case 142: /* direct_declarator: direct_declarator '(' ')'  */
#line 665 "parser.y"
                                {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2478 "parser.tab.c"
    break;

  case 143: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 667 "parser.y"
                                                {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2484 "parser.tab.c"
    break;

  case 144: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 668 "parser.y"
                                                    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2490 "parser.tab.c"
    break;

  case 145: /* pointer: '*'  */
#line 672 "parser.y"
        {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer(0);}
#line 2496 "parser.tab.c"
    break;

  case 146: /* pointer: '*' type_qualifier_list  */
#line 673 "parser.y"
                              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer((yyvsp[0].type_qualifier));}
#line 2502 "parser.tab.c"
    break;

  case 147: /* pointer: '*' pointer  */
#line 674 "parser.y"
                  {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer(0); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2508 "parser.tab.c"
    break;

  case 148: /* pointer: '*' type_qualifier_list pointer  */
#line 675 "parser.y"
                                      {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer((yyvsp[-1].type_qualifier)); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2514 "parser.tab.c"
    break;

  case 149: /* type_qualifier_list: type_qualifier  */
#line 679 "parser.y"
                   {(yyval.type_qualifier) = (yyvsp[0].type_qualifier);}
#line 2520 "parser.tab.c"
    break;

  case 150: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 680 "parser.y"
                                         {(yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier);}
#line 2526 "parser.tab.c"
    break;

  case 151: /* parameter_type_list: parameter_list  */
#line 685 "parser.y"
                   {(yyval.symbol_table) = (yyvsp[0].symbol_table);}
#line 2532 "parser.tab.c"
    break;

  case 152: /* parameter_list: parameter_declaration  */
#line 690 "parser.y"
                          {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2538 "parser.tab.c"
    break;

  case 153: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 692 "parser.y"
    {
        if ((yyvsp[0].node)->name && st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, (yyvsp[0].node)->name);
            exit(EXIT_FAILURE);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2551 "parser.tab.c"
    break;

  case 154: /* parameter_declaration: declaration_specifiers declarator  */
#line 704 "parser.y"
    {
        if ((yyvsp[-1].declaration_specifiers).storage_class && (yyvsp[-1].declaration_specifiers).storage_class != SC_REGISTER)
        {
            fprintf(stderr, "%s:%d: Error: invalid parameter storage class \n", filename, line_num);
            exit(EXIT_FAILURE);
        }

        ast_node_t *var = ast_ident_to_variable((yyvsp[0].declarator_helper).oldest, (yyvsp[-1].declaration_specifiers).storage_class);

        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2568 "parser.tab.c"
    break;

  case 155: /* parameter_declaration: declaration_specifiers  */
#line 716 "parser.y"
                             {
        if ((yyvsp[0].declaration_specifiers).storage_class && (yyvsp[0].declaration_specifiers).storage_class != SC_REGISTER)
        {
            fprintf(stderr, "%s:%d: Error: invalid parameter storage class \n", filename, line_num);
            exit(EXIT_FAILURE);
        }

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[0].declaration_specifiers).storage_class);
        var->next = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2584 "parser.tab.c"
    break;

  case 156: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 728 "parser.y"
    {
        if ((yyvsp[-1].declaration_specifiers).storage_class && (yyvsp[-1].declaration_specifiers).storage_class != SC_REGISTER)
        {
            fprintf(stderr, "%s:%d: Error: invalid parameter storage class \n", filename, line_num);
            exit(EXIT_FAILURE);
        }

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[-1].declaration_specifiers).storage_class);
        var->next = (yyvsp[0].declarator_helper).oldest;
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2601 "parser.tab.c"
    break;

  case 157: /* identifier_list: identifier  */
#line 743 "parser.y"
               {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2607 "parser.tab.c"
    break;

  case 158: /* identifier_list: identifier_list ',' identifier  */
#line 745 "parser.y"
    {
        if (st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, (yyvsp[0].node)->name);
            exit(EXIT_FAILURE);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2620 "parser.tab.c"
    break;

  case 159: /* type_name: specifier_qualifier_list  */
#line 756 "parser.y"
                             {(yyval.node) = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);}
#line 2626 "parser.tab.c"
    break;

  case 160: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 758 "parser.y"
    {
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = (yyvsp[0].declarator_helper).oldest;
    }
#line 2635 "parser.tab.c"
    break;

  case 161: /* abstract_declarator: pointer  */
#line 765 "parser.y"
            {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2641 "parser.tab.c"
    break;

  case 162: /* abstract_declarator: direct_abstract_declarator  */
#line 766 "parser.y"
                                 {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2647 "parser.tab.c"
    break;

  case 163: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 767 "parser.y"
                                         {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2653 "parser.tab.c"
    break;

  case 164: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 771 "parser.y"
                                {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2659 "parser.tab.c"
    break;

  case 165: /* direct_abstract_declarator: '[' ']'  */
#line 772 "parser.y"
              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array(0);}
#line 2665 "parser.tab.c"
    break;

  case 166: /* direct_abstract_declarator: '[' assignment_expression ']'  */
#line 773 "parser.y"
                                    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array((yyvsp[-1].node));}
#line 2671 "parser.tab.c"
    break;

  case 167: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 774 "parser.y"
                                         {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2677 "parser.tab.c"
    break;

  case 168: /* direct_abstract_declarator: direct_abstract_declarator '[' assignment_expression ']'  */
#line 775 "parser.y"
                                                               {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2683 "parser.tab.c"
    break;

  case 169: /* direct_abstract_declarator: '(' ')'  */
#line 778 "parser.y"
              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(0);}
#line 2689 "parser.tab.c"
    break;

  case 170: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 779 "parser.y"
                                         {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2695 "parser.tab.c"
    break;

  case 171: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 780 "parser.y"
                                  {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(st_unpack((yyvsp[-1].symbol_table)));}
#line 2701 "parser.tab.c"
    break;

  case 172: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 781 "parser.y"
                                                             {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2707 "parser.tab.c"
    break;

  case 174: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 794 "parser.y"
                                                        {(yyval.node) = ast_new_struct_or_union((yyvsp[-3].integer), 0, st_unpack((yyvsp[-1].symbol_table)));}
#line 2713 "parser.tab.c"
    break;

  case 175: /* @4: %empty  */
#line 796 "parser.y"
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
                            fprintf(stderr, "%s:%d: Error: `%s` is already complete\n", filename, line_num, (yyvsp[-1].string).buffer);
                            exit(EXIT_FAILURE);
                        }
                    }
                    else
                    {
                        fprintf(stderr, "%s:%d: Error: a struct or union `%s` has already been declared\n", filename, line_num, (yyvsp[-1].string).buffer);
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    st_add(NS_STRUCT, (yyval.node) = ast_new_struct_or_union((yyvsp[-2].integer), (yyvsp[-1].string).buffer, 0));
                }
            }
#line 2746 "parser.tab.c"
    break;

  case 176: /* struct_or_union_specifier: struct_or_union IDENT '{' @4 struct_declaration_list '}'  */
#line 825 "parser.y"
            {
                (yyval.node) = ast_add_struct_or_union_members((yyvsp[-2].node), st_unpack((yyvsp[-1].symbol_table)));

                ast_print_struct_or_union((yyval.node)); // ! debug
            }
#line 2756 "parser.tab.c"
    break;

  case 177: /* struct_or_union_specifier: struct_or_union IDENT  */
#line 831 "parser.y"
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
#line 2773 "parser.tab.c"
    break;

  case 178: /* struct_or_union: STRUCT  */
#line 846 "parser.y"
               {(yyval.integer) = AST_STRUCT;}
#line 2779 "parser.tab.c"
    break;

  case 179: /* struct_or_union: UNION  */
#line 847 "parser.y"
                {(yyval.integer) = AST_UNION;}
#line 2785 "parser.tab.c"
    break;

  case 180: /* struct_declaration_list: struct_declaration  */
#line 851 "parser.y"
                           {(yyval.symbol_table) = add_members_to_symbol_table(st_new(0), (yyvsp[0].declaration_package));}
#line 2791 "parser.tab.c"
    break;

  case 181: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 852 "parser.y"
                                                     {(yyval.symbol_table) = add_members_to_symbol_table((yyvsp[-1].symbol_table), (yyvsp[0].declaration_package));}
#line 2797 "parser.tab.c"
    break;

  case 182: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 857 "parser.y"
        {
            (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_verify_and_simplify_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
            (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
            (yyval.declaration_package) = (yyvsp[-1].declaration_package);
        }
#line 2807 "parser.tab.c"
    break;

  case 183: /* specifier_qualifier_list: type_specifier  */
#line 865 "parser.y"
                       {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2813 "parser.tab.c"
    break;

  case 184: /* specifier_qualifier_list: type_qualifier  */
#line 866 "parser.y"
                         {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2819 "parser.tab.c"
    break;

  case 185: /* specifier_qualifier_list: specifier_qualifier_list type_specifier  */
#line 867 "parser.y"
                                                  {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2825 "parser.tab.c"
    break;

  case 186: /* specifier_qualifier_list: specifier_qualifier_list type_qualifier  */
#line 868 "parser.y"
                                                  {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2831 "parser.tab.c"
    break;

  case 187: /* struct_declarator_list: struct_declarator  */
#line 872 "parser.y"
                          {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 2837 "parser.tab.c"
    break;

  case 188: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 873 "parser.y"
                                                       {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 2843 "parser.tab.c"
    break;

  case 189: /* struct_declarator: declarator  */
#line 877 "parser.y"
                   {(yyvsp[0].declarator_helper).bit_width = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2849 "parser.tab.c"
    break;

  case 190: /* struct_declarator: ':' constant_expression  */
#line 878 "parser.y"
                                  {(yyval.declarator_helper) = (declarator_helper_t){.oldest = 0, .newest = 0, .bit_width = (yyvsp[0].node)};}
#line 2855 "parser.tab.c"
    break;

  case 191: /* struct_declarator: declarator ':' constant_expression  */
#line 879 "parser.y"
                                             {(yyvsp[-2].declarator_helper).bit_width = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 2861 "parser.tab.c"
    break;


#line 2865 "parser.tab.c"

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

#line 904 "parser.y"


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
                && type->type.specifier.custom->structure.members == 0     // no members
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
