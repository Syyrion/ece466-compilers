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

    // * probably full of memory leaks *

    #include <stdlib.h>
    #include <stdio.h>
    #include "lexer.h"
    #include "location.h"
    #include "ast.h"
    #include "symbol_table.h"
    #include "jump_association.h"

    void yyerror (const char *s)
    {
        fprintf (stderr, "%s:%d: %s\n", filename, line_num, s);
    }

    symbol_table_t *add_members_to_symbol_table(symbol_table_t *member_table, declaration_package_t declaration_package);

#line 90 "parser.tab.c"

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
  YYSYMBOL_72_ = 72,                       /* ':'  */
  YYSYMBOL_73_ = 73,                       /* '['  */
  YYSYMBOL_74_ = 74,                       /* ']'  */
  YYSYMBOL_75_ = 75,                       /* '.'  */
  YYSYMBOL_76_ = 76,                       /* ','  */
  YYSYMBOL_77_ = 77,                       /* '&'  */
  YYSYMBOL_78_ = 78,                       /* '*'  */
  YYSYMBOL_79_ = 79,                       /* '+'  */
  YYSYMBOL_80_ = 80,                       /* '-'  */
  YYSYMBOL_81_ = 81,                       /* '~'  */
  YYSYMBOL_82_ = 82,                       /* '!'  */
  YYSYMBOL_83_ = 83,                       /* '/'  */
  YYSYMBOL_84_ = 84,                       /* '%'  */
  YYSYMBOL_85_ = 85,                       /* '<'  */
  YYSYMBOL_86_ = 86,                       /* '>'  */
  YYSYMBOL_87_ = 87,                       /* '^'  */
  YYSYMBOL_88_ = 88,                       /* '|'  */
  YYSYMBOL_89_ = 89,                       /* '?'  */
  YYSYMBOL_90_ = 90,                       /* '='  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_translation_unit = 92,          /* translation_unit  */
  YYSYMBOL_external_declaration = 93,      /* external_declaration  */
  YYSYMBOL_function_definition = 94,       /* function_definition  */
  YYSYMBOL_95_1 = 95,                      /* @1  */
  YYSYMBOL_block_item_list = 96,           /* block_item_list  */
  YYSYMBOL_block_item = 97,                /* block_item  */
  YYSYMBOL_statement = 98,                 /* statement  */
  YYSYMBOL_99_2 = 99,                      /* $@2  */
  YYSYMBOL_compound_statement = 100,       /* compound_statement  */
  YYSYMBOL_optional_block_item_list = 101, /* optional_block_item_list  */
  YYSYMBOL_expression_statement = 102,     /* expression_statement  */
  YYSYMBOL_selection_statement = 103,      /* selection_statement  */
  YYSYMBOL_104_3 = 104,                    /* @3  */
  YYSYMBOL_iteration_statement = 105,      /* iteration_statement  */
  YYSYMBOL_106_4 = 106,                    /* @4  */
  YYSYMBOL_107_5 = 107,                    /* @5  */
  YYSYMBOL_108_6 = 108,                    /* @6  */
  YYSYMBOL_optional_expression = 109,      /* optional_expression  */
  YYSYMBOL_jump_statement = 110,           /* jump_statement  */
  YYSYMBOL_labeled_statement = 111,        /* labeled_statement  */
  YYSYMBOL_identifier = 112,               /* identifier  */
  YYSYMBOL_string_literal = 113,           /* string_literal  */
  YYSYMBOL_constant = 114,                 /* constant  */
  YYSYMBOL_primary_expression = 115,       /* primary_expression  */
  YYSYMBOL_postfix_expression = 116,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 117, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 118,         /* unary_expression  */
  YYSYMBOL_cast_expression = 119,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 120, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 121,      /* additive_expression  */
  YYSYMBOL_shift_expression = 122,         /* shift_expression  */
  YYSYMBOL_relational_expression = 123,    /* relational_expression  */
  YYSYMBOL_equality_expression = 124,      /* equality_expression  */
  YYSYMBOL_and_expression = 125,           /* and_expression  */
  YYSYMBOL_xor_expression = 126,           /* xor_expression  */
  YYSYMBOL_or_expression = 127,            /* or_expression  */
  YYSYMBOL_logical_and_expression = 128,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 129,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 130,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 131,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 132,      /* assignment_operator  */
  YYSYMBOL_expression = 133,               /* expression  */
  YYSYMBOL_constant_expression = 134,      /* constant_expression  */
  YYSYMBOL_declaration = 135,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 136,   /* declaration_specifiers  */
  YYSYMBOL_storage_class_specifier = 137,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 138,           /* type_specifier  */
  YYSYMBOL_type_qualifier = 139,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 140,       /* function_specifier  */
  YYSYMBOL_init_declarator_list = 141,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 142,          /* init_declarator  */
  YYSYMBOL_declarator = 143,               /* declarator  */
  YYSYMBOL_direct_declarator = 144,        /* direct_declarator  */
  YYSYMBOL_pointer = 145,                  /* pointer  */
  YYSYMBOL_type_qualifier_list = 146,      /* type_qualifier_list  */
  YYSYMBOL_parameter_type_list = 147,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 148,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 149,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 150,          /* identifier_list  */
  YYSYMBOL_type_name = 151,                /* type_name  */
  YYSYMBOL_abstract_declarator = 152,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 153, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 154,              /* initializer  */
  YYSYMBOL_struct_or_union_specifier = 155, /* struct_or_union_specifier  */
  YYSYMBOL_156_7 = 156,                    /* @7  */
  YYSYMBOL_struct_or_union = 157,          /* struct_or_union  */
  YYSYMBOL_struct_declaration_list = 158,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 159,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 160, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 161,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 162         /* struct_declarator  */
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
#define YYLAST   1257

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  338

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
       2,     2,     2,    82,     2,     2,     2,    84,    77,     2,
      70,    71,    78,    79,    76,    80,    75,    83,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,    69,
      85,    90,    86,    89,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    73,     2,    74,    87,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    67,    88,    68,    81,     2,     2,     2,
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
       0,   203,   203,   204,   208,   209,   254,   253,   366,   367,
     371,   410,   415,   415,   416,   417,   418,   419,   420,   424,
     428,   429,   433,   434,   438,   443,   449,   448,   463,   462,
     474,   473,   486,   485,   505,   506,   510,   511,   512,   513,
     517,   518,   519,   526,   530,   534,   535,   539,   540,   541,
     542,   546,   547,   548,   549,   550,   551,   552,   553,   557,
     558,   562,   563,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,   577,   578,   582,   583,   584,   585,   589,
     590,   591,   595,   596,   597,   601,   602,   603,   604,   605,
     609,   610,   611,   615,   616,   619,   620,   623,   624,   628,
     629,   633,   634,   638,   639,   643,   644,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   658,   662,   663,
     667,   675,   681,   687,   688,   689,   690,   691,   692,   693,
     694,   699,   700,   701,   702,   708,   709,   710,   711,   712,
     713,   714,   715,   716,   717,   718,   719,   726,   727,   728,
     733,   738,   739,   743,   744,   748,   749,   753,   754,   755,
     756,   757,   759,   760,   764,   765,   766,   767,   771,   772,
     777,   782,   783,   795,   803,   810,   822,   823,   835,   836,
     844,   845,   846,   850,   851,   852,   853,   854,   855,   856,
     857,   858,   866,   871,   873,   872,   906,   922,   923,   927,
     928,   932,   941,   942,   943,   944,   948,   949,   953,   954,
     955
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
  "')'", "':'", "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='",
  "$accept", "translation_unit", "external_declaration",
  "function_definition", "@1", "block_item_list", "block_item",
  "statement", "$@2", "compound_statement", "optional_block_item_list",
  "expression_statement", "selection_statement", "@3",
  "iteration_statement", "@4", "@5", "@6", "optional_expression",
  "jump_statement", "labeled_statement", "identifier", "string_literal",
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
  "@7", "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-221)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-22)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1093,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,   957,  -221,  -221,  -221,   800,  -221,  -221,  -221,
    -221,  -221,    27,  -221,  -221,  -221,  -221,    30,    89,  -221,
    -221,  -221,  -221,  -221,   -45,  -221,   -56,    42,    12,   -27,
    1192,   -13,  -221,  -221,    89,  -221,    30,   669,     0,   918,
     215,    42,  -221,  -221,  -221,  1126,  -221,   876,  -221,  -221,
    -221,  -221,    16,  -221,  -221,  -221,   698,   698,   698,   711,
     496,   669,   669,   669,   669,   669,   669,  -221,  -221,  -221,
    -221,   248,   281,  -221,   -15,    -6,   148,    32,   111,     9,
      -7,    58,    86,    -4,  -221,  -221,  -221,   332,  -221,  -221,
    -221,   842,    95,    85,  -221,   -17,  -221,  -221,  -221,    99,
    1192,  -221,  -221,   669,  -221,  -221,   103,   -41,  -221,   669,
    -221,  -221,  -221,   496,  -221,  -221,    43,   108,  1025,  -221,
    -221,  -221,  -221,  -221,  -221,   178,  -221,  -221,   576,   669,
     180,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,  -221,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   669,   669,   669,   669,   669,   669,   669,   669,
     669,   669,   114,   119,   669,   123,   122,  -221,   126,   199,
     133,   669,   140,   144,  -221,   416,  -221,  -221,     0,   147,
    -221,  -221,  -221,  -221,  -221,   -37,  -221,   800,   766,   615,
    -221,    14,  -221,    63,  -221,  1093,  -221,   213,  -221,  1159,
    -221,   669,  -221,    11,   154,  -221,   669,   669,   991,    84,
    -221,  -221,  -221,    51,  -221,    79,  -221,  -221,  -221,  -221,
    -221,   -15,   -15,    -6,    -6,   148,   148,   148,   148,    32,
      32,   111,     9,    -7,    58,    86,   -35,   559,  -221,   155,
    -221,   559,   559,   669,   161,   669,   162,   157,   669,   669,
    -221,  -221,  -221,  -221,  -221,   165,   170,  -221,   168,    63,
    1059,   656,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,
    -221,   669,  -221,   669,  -221,   559,  -221,   181,   177,  -221,
      66,  -221,    73,    74,  -221,  -221,  -221,  -221,   176,  -221,
     192,  -221,  -221,  -221,   184,   669,   559,  -221,  -221,  -221,
    -221,   669,   182,   211,   559,   559,    76,   669,   559,  -221,
    -221,   196,   207,  -221,  -221,  -221,   559,  -221
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   136,   147,   141,   131,   140,   150,   138,   139,
     134,   148,   137,   142,   132,   197,   198,   143,   135,   149,
     144,   145,     0,     2,     4,     5,     0,   125,   123,   124,
     126,   146,     0,     1,     3,    43,   122,     0,   164,   157,
     129,   127,   128,   130,     0,   151,   153,   155,     0,   196,
       0,     0,   168,   166,   165,   121,     0,     0,     0,     0,
       0,   156,   194,   202,   203,     0,   199,     0,   158,   169,
     167,   152,   153,    45,    44,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    49,    48,
      51,    61,    73,    75,    79,    82,    85,    90,    93,    95,
      97,    99,   101,   103,   105,   192,   154,    12,     7,   161,
     176,   174,     0,   170,   171,     0,   159,    73,   120,     0,
       0,   193,   200,     0,   204,   205,   208,     0,   206,     0,
      62,    63,    72,     0,    70,   118,     0,     0,   178,    64,
      65,    66,    67,    68,    69,     0,    57,    58,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   117,
     116,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,     0,    30,     0,     0,
       0,    35,     0,     0,    23,    12,     8,    11,     0,     0,
      14,    15,    16,    17,    18,     0,    10,     0,     0,     0,
     173,   180,   175,   181,   163,     0,   162,     0,   160,     0,
     209,     0,   201,     0,     0,    50,     0,     0,     0,   180,
     179,    56,    53,     0,    59,     0,    55,   106,    76,    77,
      78,    80,    81,    83,    84,    87,    89,    86,    88,    91,
      92,    94,    96,    98,   100,   102,     0,    12,    38,     0,
      37,    12,    12,    35,     0,     0,     0,    34,     0,     0,
       9,    13,    19,    22,   188,     0,     0,   184,     0,   182,
       0,     0,   172,   177,   195,   210,   207,    71,   119,    74,
      54,     0,    52,     0,    40,    12,    42,     0,     0,    36,
       0,    39,     0,     0,   190,   183,   185,   189,     0,   186,
       0,    60,   104,    41,     0,    35,    12,    26,    28,   191,
     187,     0,     0,    24,    12,    12,     0,    35,    12,    27,
      29,     0,     0,    25,    31,    32,    12,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -221,  -221,   258,  -221,  -221,  -221,    87,  -196,  -221,    83,
    -221,  -221,  -221,  -221,  -221,  -221,  -221,  -221,  -220,  -221,
    -221,   -10,  -221,  -221,  -221,  -221,  -221,   -57,   191,    -3,
       2,    90,     3,   107,   109,   106,   112,   110,  -221,   -53,
     -52,  -221,   -78,  -105,   -97,     4,   -23,   115,    10,   -18,
    -221,   231,   -14,   -39,    24,  -221,   -58,  -221,    96,  -221,
     166,   -86,  -182,  -221,  -221,  -221,  -221,   190,   -59,   -24,
    -221,    65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    22,    23,    24,    58,   195,   196,   197,   198,   108,
     199,   200,   201,   324,   202,   325,   262,   336,   266,   203,
     204,    87,    88,    89,    90,    91,   233,   117,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     135,   162,   205,   119,    25,   111,    27,    28,    29,    30,
      44,    45,    51,    47,    48,    54,   275,   113,   114,   115,
     137,   276,   213,   106,    31,   120,    32,    65,    66,    67,
     127,   128
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   112,   136,    40,    26,   105,   122,   118,    43,    61,
     206,    -6,    46,   180,    35,    35,    39,    35,   220,   130,
     131,   132,   134,    92,    55,   212,    26,    39,   222,   279,
      49,    56,   273,    35,    57,   223,    42,   293,    39,   226,
      62,   226,    72,   298,   170,   171,    39,   279,    52,   110,
      92,   136,   230,   126,   216,   136,   138,    39,    68,   217,
      64,   294,    53,   163,    69,   296,   297,   107,   164,   165,
     118,   235,    92,   166,   167,    64,    92,   125,    70,   259,
     177,    37,    37,   123,   208,   181,   176,   209,    40,    38,
      64,    92,    92,    43,    50,   322,   234,   210,   206,   313,
      37,    39,   179,   256,   278,    92,    57,   332,    38,   138,
     237,   207,    59,   267,   225,    60,   285,   172,   173,   226,
     323,    42,   290,     3,    92,   174,   175,   291,   329,   330,
      64,   118,   333,   280,    92,   211,   281,   316,    92,    11,
     337,    41,   226,    64,   317,   318,   178,   331,   125,   226,
     226,    19,   226,   292,   228,   226,   118,   209,   168,   169,
     122,   215,   229,   241,   242,    63,   214,    38,   118,    92,
     243,   244,    61,   218,   288,   221,   310,   249,   250,   227,
      63,   231,   124,   236,    40,   267,   257,   300,   258,    43,
     302,   303,   260,    72,   261,    63,   263,    39,    39,   207,
      92,    39,   264,   265,    92,    92,    92,   283,    92,   126,
     268,    92,    92,    39,   269,   272,    35,    42,    35,    73,
      74,    75,   308,    76,    77,   287,    41,   295,   118,    64,
     299,   301,   211,   226,    92,    63,   304,   267,    92,   311,
     312,   305,   306,   326,   314,    78,   315,   319,    63,   267,
     328,   327,   229,   124,   321,   145,   146,   147,    92,    92,
     245,   246,   247,   248,    92,   334,   320,    92,    92,    79,
      92,    92,   139,   140,   141,   142,   143,   144,   335,    92,
      34,   271,   270,   251,   253,    80,   252,    71,   286,   116,
     255,   254,    81,    82,    83,    84,    85,    86,     0,   224,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     219,   282,     0,     0,     0,     0,     0,     0,   148,     0,
       0,   149,    41,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,   182,    73,    74,    75,     0,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   238,   239,   240,     0,     0,     0,
       0,     1,    78,   183,   184,     2,     3,   185,   186,   187,
       4,   161,     0,     5,     6,   188,   189,   190,     7,     8,
       9,    10,    11,   191,    12,    13,    79,    14,    15,   192,
       0,    16,    17,    18,    19,   193,    20,    21,     0,     0,
     -21,   194,    80,     0,     0,     0,     0,     0,     0,    81,
      82,    83,    84,    85,    86,     0,     0,     0,   289,   182,
      73,    74,    75,     0,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,    78,   183,   184,     2,
       3,   185,   186,   187,     4,     0,     0,     5,     6,   188,
     189,   190,     7,     8,     9,    10,    11,   191,    12,    13,
      79,    14,    15,   192,     0,    16,    17,    18,    19,   193,
      20,    21,     0,     0,   -20,   194,    80,     0,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    35,
      73,    74,    75,     0,    76,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     2,
       3,     0,     0,     0,     4,     0,     0,     0,     6,     0,
       0,     0,     0,     8,     9,     0,    11,     0,    12,    13,
      79,     0,    15,     0,     0,    16,    17,    18,    19,     0,
      20,    21,   182,    73,    74,    75,    80,    76,    77,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    35,
      73,    74,    75,     0,    76,    77,     0,     0,     0,    78,
     183,   184,     0,     0,   185,   186,   187,     0,     0,     0,
       0,     0,   188,   189,   190,     0,    78,     0,     0,     0,
     191,     0,     0,    79,     0,     0,   192,     0,    35,    73,
      74,    75,   193,    76,    77,     0,     0,     0,   194,    80,
      79,     0,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,     0,     0,     0,    78,    80,   232,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,    35,
      73,    74,    75,     0,    76,    77,     0,     0,     0,    79,
       0,     0,    35,    73,    74,    75,     0,    76,    77,     0,
       0,     0,     0,     0,     0,    80,    78,     0,     0,   277,
       0,     0,    81,    82,    83,    84,    85,    86,     0,    78,
       0,    35,    73,    74,    75,     0,    76,    77,     0,     0,
      79,     0,     0,     0,    35,    73,    74,    75,     0,    76,
      77,     0,     0,    79,     0,     0,    80,     0,    78,     0,
     309,     0,     0,    81,    82,    83,    84,    85,    86,    80,
       0,    78,     0,     0,     0,     0,    81,    82,    83,    84,
      85,    86,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,   129,    35,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,   133,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,     0,     1,     0,     0,     0,     2,
       3,     0,     0,    35,     4,     0,     0,     5,     6,     0,
       0,     0,     7,     8,     9,    10,    11,     0,    12,    13,
       0,    14,    15,     0,     0,    16,    17,    18,    19,     1,
      20,    21,     0,     2,     3,     0,   208,   274,     4,   209,
       0,     5,     6,     0,    38,    35,     7,     8,     9,    10,
      11,     0,    12,    13,     0,    14,    15,     0,     0,    16,
      17,    18,    19,     0,    20,    21,     0,     0,     0,    36,
      37,     1,     0,     0,     0,     2,     3,     0,    38,    35,
       4,     0,     0,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,    15,     0,
       0,    16,    17,    18,    19,     0,    20,    21,     0,     2,
       3,     0,   208,     0,     4,   209,     0,     0,     6,     0,
      38,    35,     0,     8,     9,     0,    11,     0,    12,    13,
       0,     0,    15,     0,     0,    16,    17,    18,    19,     0,
      20,    21,     0,     0,     0,     0,    37,     1,   123,     0,
       0,     2,     3,     0,    38,     0,     4,    33,     0,     5,
       6,     0,     0,     0,     7,     8,     9,    10,    11,     0,
      12,    13,     0,    14,    15,     0,     0,    16,    17,    18,
      19,     0,    20,    21,     0,     0,     1,     0,     0,   109,
       2,     3,     0,     0,     0,     4,     0,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    14,    15,     0,     0,    16,    17,    18,    19,
       1,    20,    21,     0,     2,     3,     0,     0,     0,     4,
       0,     0,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,     0,    12,    13,     0,    14,    15,     0,     0,
      16,    17,    18,    19,     0,    20,    21,     0,     2,     3,
       0,   228,   274,     4,   209,     0,     0,     6,     0,    38,
       0,     0,     8,     9,     0,    11,     0,    12,    13,     0,
       0,    15,     0,     0,    16,    17,    18,    19,     1,    20,
      21,     0,     2,     3,     0,   228,     0,     4,   209,     0,
       5,     6,     0,    38,     0,     7,     8,     9,    10,    11,
       0,    12,    13,     0,    14,    15,     0,     0,    16,    17,
      18,    19,     1,    20,    21,     0,     2,     3,     0,     0,
     307,     4,     0,     0,     5,     6,     0,     0,     0,     7,
       8,     9,    10,    11,     0,    12,    13,     0,    14,    15,
       0,     0,    16,    17,    18,    19,     0,    20,    21,     2,
       3,     0,     0,     0,     4,     0,     0,     0,     6,     0,
       0,     0,     0,     8,     9,     0,    11,     0,    12,    13,
       0,     0,    15,     0,     0,    16,    17,    18,    19,     0,
      20,    21,     2,     3,   121,     0,     0,     4,     0,     0,
       0,     6,     0,     0,     0,     0,     8,     9,     0,    11,
       0,    12,    13,     0,     0,    15,     0,     0,    16,    17,
      18,    19,     0,    20,    21,     2,     3,   284,     0,     0,
       4,     0,     0,     0,     6,     0,     0,     0,     0,     8,
       9,     0,    11,     0,    12,    13,     0,     0,    15,     0,
       0,    16,    17,    18,    19,     0,    20,    21
};

static const yytype_int16 yycheck[] =
{
      57,    59,    80,    26,     0,    57,    65,    60,    26,    48,
     107,    67,    26,    17,     3,     3,    26,     3,   123,    76,
      77,    78,    79,    80,    69,   111,    22,    37,    69,   211,
       3,    76,    69,     3,    90,    76,    26,    72,    48,    76,
      67,    76,    56,   263,    12,    13,    56,   229,    38,    59,
     107,   129,   138,    67,    71,   133,    80,    67,    71,    76,
      50,   257,    38,    78,    54,   261,   262,    67,    83,    84,
     123,   149,   129,    79,    80,    65,   133,    67,    54,   184,
      87,    70,    70,    72,    70,    89,    77,    73,   111,    78,
      80,   148,   149,   111,    67,   315,   148,   111,   195,   295,
      70,   111,    16,   181,   209,   162,    90,   327,    78,   133,
     162,   107,    70,   191,    71,    73,   221,    85,    86,    76,
     316,   111,    71,    34,   181,    14,    15,    76,   324,   325,
     120,   184,   328,    70,   191,   111,    73,    71,   195,    50,
     336,    26,    76,   133,    71,    71,    88,    71,   138,    76,
      76,    62,    76,    74,    70,    76,   209,    73,    10,    11,
     219,    76,   138,   166,   167,    50,    71,    78,   221,   226,
     168,   169,   211,    74,   226,    72,   281,   174,   175,    71,
      65,     3,    67,     3,   207,   263,    72,   265,    69,   207,
     268,   269,    69,   207,    72,    80,    70,   207,   208,   195,
     257,   211,     3,    70,   261,   262,   263,   217,   265,   223,
      70,   268,   269,   223,    70,    68,     3,   207,     3,     4,
       5,     6,   280,     8,     9,    71,   111,    72,   281,   219,
      69,    69,   208,    76,   291,   120,    71,   315,   295,   291,
     293,    71,    74,   321,    63,    30,    69,    71,   133,   327,
      39,    69,   228,   138,    70,     7,     8,     9,   315,   316,
     170,   171,   172,   173,   321,    69,    74,   324,   325,    54,
     327,   328,    81,    82,    83,    84,    85,    86,    71,   336,
      22,   198,   195,   176,   178,    70,   177,    56,   223,    74,
     180,   179,    77,    78,    79,    80,    81,    82,    -1,   133,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
     120,   215,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    73,   207,    75,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   163,   164,   165,    -1,    -1,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    90,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    61,    62,    63,    64,    65,    -1,    -1,
      68,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,
      78,    79,    80,    81,    82,    -1,    -1,    -1,   227,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    61,    62,    63,
      64,    65,    -1,    -1,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,
      54,    -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65,     3,     4,     5,     6,    70,     8,     9,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    30,
      31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    43,    44,    45,    -1,    30,    -1,    -1,    -1,
      51,    -1,    -1,    54,    -1,    -1,    57,    -1,     3,     4,
       5,     6,    63,     8,     9,    -1,    -1,    -1,    69,    70,
      54,    -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    -1,    -1,    -1,    30,    70,    71,    -1,    -1,
      -1,    -1,    -1,    77,    78,    79,    80,    81,    82,     3,
       4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,    54,
      -1,    -1,     3,     4,     5,     6,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    30,    -1,    -1,    74,
      -1,    -1,    77,    78,    79,    80,    81,    82,    -1,    30,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      54,    -1,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    54,    -1,    -1,    70,    -1,    30,    -1,
      74,    -1,    -1,    77,    78,    79,    80,    81,    82,    70,
      -1,    30,    -1,    -1,    -1,    -1,    77,    78,    79,    80,
      81,    82,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    70,     3,
      -1,    -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,
      82,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,    29,    -1,    -1,    -1,    33,
      34,    -1,    -1,     3,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    29,
      64,    65,    -1,    33,    34,    -1,    70,    71,    38,    73,
      -1,    41,    42,    -1,    78,     3,    46,    47,    48,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65,    -1,    -1,    -1,    69,
      70,    29,    -1,    -1,    -1,    33,    34,    -1,    78,     3,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    65,    -1,    33,
      34,    -1,    70,    -1,    38,    73,    -1,    -1,    42,    -1,
      78,     3,    -1,    47,    48,    -1,    50,    -1,    52,    53,
      -1,    -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65,    -1,    -1,    -1,    -1,    70,    29,    72,    -1,
      -1,    33,    34,    -1,    78,    -1,    38,     0,    -1,    41,
      42,    -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    -1,    -1,    29,    -1,    -1,    71,
      33,    34,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      29,    64,    65,    -1,    33,    34,    -1,    -1,    -1,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65,    -1,    33,    34,
      -1,    70,    71,    38,    73,    -1,    -1,    42,    -1,    78,
      -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,    -1,
      -1,    56,    -1,    -1,    59,    60,    61,    62,    29,    64,
      65,    -1,    33,    34,    -1,    70,    -1,    38,    73,    -1,
      41,    42,    -1,    78,    -1,    46,    47,    48,    49,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,    60,
      61,    62,    29,    64,    65,    -1,    33,    34,    -1,    -1,
      71,    38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,
      47,    48,    49,    50,    -1,    52,    53,    -1,    55,    56,
      -1,    -1,    59,    60,    61,    62,    -1,    64,    65,    33,
      34,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,
      -1,    -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,
      64,    65,    33,    34,    68,    -1,    -1,    38,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    64,    65,    33,    34,    68,    -1,    -1,
      38,    -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    50,    -1,    52,    53,    -1,    -1,    56,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    65
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    33,    34,    38,    41,    42,    46,    47,    48,
      49,    50,    52,    53,    55,    56,    59,    60,    61,    62,
      64,    65,    92,    93,    94,   135,   136,   137,   138,   139,
     140,   155,   157,     0,    93,     3,    69,    70,    78,   112,
     137,   138,   139,   140,   141,   142,   143,   144,   145,     3,
      67,   143,   139,   145,   146,    69,    76,    90,    95,    70,
      73,   144,    67,   138,   139,   158,   159,   160,    71,   139,
     145,   142,   143,     4,     5,     6,     8,     9,    30,    54,
      70,    77,    78,    79,    80,    81,    82,   112,   113,   114,
     115,   116,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   154,    67,   100,    71,
     112,   136,   147,   148,   149,   150,    74,   118,   130,   134,
     156,    68,   159,    72,   138,   139,   143,   161,   162,    70,
     118,   118,   118,    70,   118,   131,   133,   151,   160,   119,
     119,   119,   119,   119,   119,     7,     8,     9,    70,    73,
      75,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    90,   132,    78,    83,    84,    79,    80,    10,    11,
      12,    13,    85,    86,    14,    15,    77,    87,    88,    16,
      17,    89,     3,    31,    32,    35,    36,    37,    43,    44,
      45,    51,    57,    63,    69,    96,    97,    98,    99,   101,
     102,   103,   105,   110,   111,   133,   135,   136,    70,    73,
     143,   145,   152,   153,    71,    76,    71,    76,    74,   158,
     134,    72,    69,    76,   151,    71,    76,    71,    70,   145,
     152,     3,    71,   117,   131,   133,     3,   131,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   123,
     123,   124,   125,   126,   127,   128,   133,    72,    69,   134,
      69,    72,   107,    70,     3,    70,   109,   133,    70,    70,
      97,   100,    68,    69,    71,   147,   152,    74,   134,   153,
      70,    73,   149,   112,    68,   134,   162,    71,   131,   119,
      71,    76,    74,    72,    98,    72,    98,    98,   109,    69,
     133,    69,   133,   133,    71,    71,    74,    71,   147,    74,
     134,   131,   130,    98,    63,    69,    71,    71,    71,    71,
      74,    70,   109,    98,   104,   106,   133,    69,    39,    98,
      98,    71,   109,    98,    69,    71,   108,    98
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    92,    93,    93,    95,    94,    96,    96,
      97,    97,    99,    98,    98,    98,    98,    98,    98,   100,
     101,   101,   102,   102,   103,   103,   104,   103,   106,   105,
     107,   105,   108,   105,   109,   109,   110,   110,   110,   110,
     111,   111,   111,   112,   113,   114,   114,   115,   115,   115,
     115,   116,   116,   116,   116,   116,   116,   116,   116,   117,
     117,   118,   118,   118,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   119,   119,   120,   120,   120,   120,   121,
     121,   121,   122,   122,   122,   123,   123,   123,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     132,   132,   132,   132,   132,   132,   132,   132,   133,   133,
     134,   135,   135,   136,   136,   136,   136,   136,   136,   136,
     136,   137,   137,   137,   137,   138,   138,   138,   138,   138,
     138,   138,   138,   138,   138,   138,   138,   139,   139,   139,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   144,
     144,   144,   144,   144,   145,   145,   145,   145,   146,   146,
     147,   148,   148,   149,   149,   149,   150,   150,   151,   151,
     152,   152,   152,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   154,   155,   156,   155,   155,   157,   157,   158,
     158,   159,   160,   160,   160,   160,   161,   161,   162,   162,
     162
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     0,     4,     1,     2,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     1,     5,     7,     0,     6,     0,     6,
       0,     8,     0,    10,     1,     0,     3,     2,     2,     3,
       3,     4,     3,     1,     1,     1,     1,     1,     1,     1,
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
       1,     1,     3,     1,     3,     1,     2,     1,     3,     3,
       4,     3,     4,     4,     1,     2,     2,     3,     1,     2,
       1,     1,     3,     2,     1,     2,     1,     3,     1,     2,
       1,     1,     2,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     1,     4,     0,     6,     2,     1,     1,     1,
       2,     3,     1,     1,     2,     2,     1,     3,     1,     2,
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
#line 23 "parser.y"
{
    st_init();
    ast_init();
}

#line 1498 "parser.tab.c"

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
#line 210 "parser.y"
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
            printf("\n");
        }
    }
#line 1740 "parser.tab.c"
    break;

  case 6: /* @1: %empty  */
#line 254 "parser.y"
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

        // push a new scope
        st_push();
        
        // add parameters as variables in the new scope
        for (int i = 0; i < fn->next->function.parameters->node_count; i++)
        {
            // * mark the parameters as used or else they'll get thrown away after the compound statement
            fn->next->function.parameters->nodes[i]->variable.used = 1;
            st_add(NS_VARIABLE, fn->next->function.parameters->nodes[i]);
        }

        (yyval.node) = fn;
    }
#line 1790 "parser.tab.c"
    break;

  case 7: /* function_definition: declaration_specifiers declarator @1 compound_statement  */
#line 300 "parser.y"
    {
        (yyvsp[-1].node)->next->function.definition = (yyvsp[0].node);
        // ! debug
        printf("FUNCTION DEFINITION: ");
        ast_print_variable((yyvsp[-1].node), 0);
        ast_print_statement((yyvsp[0].node), 0);
        printf("\n");
    }
#line 1803 "parser.tab.c"
    break;

  case 10: /* block_item: declaration  */
#line 372 "parser.y"
    {
        // alias for declaration specs
        declaration_specifiers_t *ds = &(yyvsp[0].declaration_package).declaration_specifiers;

        // apply auto if needed
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
#line 1846 "parser.tab.c"
    break;

  case 11: /* block_item: statement  */
#line 410 "parser.y"
                {st_add_statement((yyvsp[0].node));}
#line 1852 "parser.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 415 "parser.y"
        {st_push();}
#line 1858 "parser.tab.c"
    break;

  case 13: /* statement: $@2 compound_statement  */
#line 415 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 1864 "parser.tab.c"
    break;

  case 19: /* compound_statement: '{' optional_block_item_list '}'  */
#line 424 "parser.y"
                                         {(yyval.node) = st_pop();}
#line 1870 "parser.tab.c"
    break;

  case 22: /* expression_statement: expression ';'  */
#line 433 "parser.y"
                       {ast_resolve_expression_variables(&(yyvsp[-1].node)); (yyval.node) = ast_new_expression_statement((yyvsp[-1].node));}
#line 1876 "parser.tab.c"
    break;

  case 23: /* expression_statement: ';'  */
#line 434 "parser.y"
              {(yyval.node) = ast_new_expression_statement(0);}
#line 1882 "parser.tab.c"
    break;

  case 24: /* selection_statement: IF '(' expression ')' statement  */
#line 439 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-2].node));
            (yyval.node) = ast_new_if_statement((yyvsp[-2].node), (yyvsp[0].node), 0);
        }
#line 1891 "parser.tab.c"
    break;

  case 25: /* selection_statement: IF '(' expression ')' statement ELSE statement  */
#line 444 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-4].node));
            (yyval.node) = ast_new_if_statement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1900 "parser.tab.c"
    break;

  case 26: /* @3: %empty  */
#line 449 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-1].node));
            ja_push((yyval.node) = ast_new_switch_statement((yyvsp[-1].node), 0));
        }
#line 1909 "parser.tab.c"
    break;

  case 27: /* selection_statement: SWITCH '(' expression ')' @3 statement  */
#line 454 "parser.y"
        {
            ja_pop();
            (yyvsp[-1].node)->switch_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1919 "parser.tab.c"
    break;

  case 28: /* @4: %empty  */
#line 463 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-1].node));
            ja_push((yyval.node) = ast_new_while_statement(AST_WHILE, (yyvsp[-1].node), 0));
        }
#line 1928 "parser.tab.c"
    break;

  case 29: /* iteration_statement: WHILE '(' expression ')' @4 statement  */
#line 468 "parser.y"
        {
            ja_pop();
            (yyvsp[-1].node)->while_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1938 "parser.tab.c"
    break;

  case 30: /* @5: %empty  */
#line 474 "parser.y"
        {
            ja_push((yyval.node) = ast_new_while_statement(AST_DO_WHILE, 0, 0));
        }
#line 1946 "parser.tab.c"
    break;

  case 31: /* iteration_statement: DO @5 statement WHILE '(' expression ')' ';'  */
#line 478 "parser.y"
        {
            ast_resolve_expression_variables(&(yyvsp[-2].node));
            ja_pop();
            (yyvsp[-6].node)->while_statement.condition = (yyvsp[-2].node);
            (yyvsp[-6].node)->while_statement.statement = (yyvsp[-5].node);
            (yyval.node) = (yyvsp[-6].node);
        }
#line 1958 "parser.tab.c"
    break;

  case 32: /* @6: %empty  */
#line 486 "parser.y"
        {
            if ((yyvsp[-5].node))
                ast_resolve_expression_variables(&(yyvsp[-5].node));
            if ((yyvsp[-3].node))
                ast_resolve_expression_variables(&(yyvsp[-3].node));
            if ((yyvsp[-1].node))
                ast_resolve_expression_variables(&(yyvsp[-1].node));
            ja_push((yyval.node) = ast_new_for_statement((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), 0));
        }
#line 1972 "parser.tab.c"
    break;

  case 33: /* iteration_statement: FOR '(' optional_expression ';' optional_expression ';' optional_expression ')' @6 statement  */
#line 496 "parser.y"
        {
            ja_pop();
            (yyvsp[-1].node)->for_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 1982 "parser.tab.c"
    break;

  case 34: /* optional_expression: expression  */
#line 505 "parser.y"
                   {(yyval.node) = (yyvsp[0].node);}
#line 1988 "parser.tab.c"
    break;

  case 35: /* optional_expression: %empty  */
#line 506 "parser.y"
                 {(yyval.node) = 0;}
#line 1994 "parser.tab.c"
    break;

  case 36: /* jump_statement: GOTO IDENT ';'  */
#line 510 "parser.y"
                       {(yyval.node) = ast_new_goto_statement((yyvsp[-1].string).buffer);}
#line 2000 "parser.tab.c"
    break;

  case 37: /* jump_statement: CONTINUE ';'  */
#line 511 "parser.y"
                       {(yyval.node) = ast_new_continue_statement(ja_get_continue_association());}
#line 2006 "parser.tab.c"
    break;

  case 38: /* jump_statement: BREAK ';'  */
#line 512 "parser.y"
                    {(yyval.node) = ast_new_break_statement(ja_get_break_association());}
#line 2012 "parser.tab.c"
    break;

  case 39: /* jump_statement: RETURN optional_expression ';'  */
#line 513 "parser.y"
                                         {(yyval.node) = ast_new_return_statement((yyvsp[-1].node));}
#line 2018 "parser.tab.c"
    break;

  case 40: /* labeled_statement: IDENT ':' statement  */
#line 517 "parser.y"
                            {st_add_label((yyvsp[-2].string).buffer, (yyvsp[0].node)); (yyval.node) = (yyvsp[0].node);}
#line 2024 "parser.tab.c"
    break;

  case 41: /* labeled_statement: CASE constant_expression ':' statement  */
#line 518 "parser.y"
                                                 {ja_add_switch_case((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[0].node);}
#line 2030 "parser.tab.c"
    break;

  case 42: /* labeled_statement: DEFAULT ':' statement  */
#line 519 "parser.y"
                                {ja_add_switch_default((yyvsp[0].node)); (yyval.node) = (yyvsp[0].node);}
#line 2036 "parser.tab.c"
    break;

  case 43: /* identifier: IDENT  */
#line 526 "parser.y"
              {(yyval.node) = ast_new_ident((yyvsp[0].string).buffer);}
#line 2042 "parser.tab.c"
    break;

  case 44: /* string_literal: STRINGLIT  */
#line 530 "parser.y"
                  {(yyval.node) = ast_new_stringlit((yyvsp[0].string));}
#line 2048 "parser.tab.c"
    break;

  case 45: /* constant: CHARLIT  */
#line 534 "parser.y"
                {(yyval.node) = ast_new_charlit((yyvsp[0].string).buffer[0]); free((yyvsp[0].string).buffer);}
#line 2054 "parser.tab.c"
    break;

  case 46: /* constant: NUMBERLIT  */
#line 535 "parser.y"
                    {(yyval.node) = ast_new_numberlit((yyvsp[0].number));}
#line 2060 "parser.tab.c"
    break;

  case 50: /* primary_expression: '(' expression ')'  */
#line 542 "parser.y"
                             {(yyval.node) = (yyvsp[-1].node);}
#line 2066 "parser.tab.c"
    break;

  case 52: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 547 "parser.y"
                                                {(yyval.node) = ast_new_unary_op('*', ast_new_binary_op('+', (yyvsp[-3].node), (yyvsp[-1].node)));}
#line 2072 "parser.tab.c"
    break;

  case 53: /* postfix_expression: postfix_expression '(' ')'  */
#line 548 "parser.y"
                                     {(yyval.node) = ast_new_function_call((yyvsp[-2].node), ast_list_new());}
#line 2078 "parser.tab.c"
    break;

  case 54: /* postfix_expression: postfix_expression '(' argument_expression_list ')'  */
#line 549 "parser.y"
                                                              {(yyval.node) = ast_new_function_call((yyvsp[-3].node), (yyvsp[-1].node_list));}
#line 2084 "parser.tab.c"
    break;

  case 55: /* postfix_expression: postfix_expression '.' IDENT  */
#line 550 "parser.y"
                                       {(yyval.node) = ast_new_member_access((yyvsp[-2].node), (yyvsp[0].string).buffer);}
#line 2090 "parser.tab.c"
    break;

  case 56: /* postfix_expression: postfix_expression "->" IDENT  */
#line 551 "parser.y"
                                        {(yyval.node) = ast_new_member_access(ast_new_unary_op('*', (yyvsp[-2].node)), (yyvsp[0].string).buffer);}
#line 2096 "parser.tab.c"
    break;

  case 57: /* postfix_expression: postfix_expression "++"  */
#line 552 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(PLUSPLUS, (yyvsp[-1].node));}
#line 2102 "parser.tab.c"
    break;

  case 58: /* postfix_expression: postfix_expression "--"  */
#line 553 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(MINUSMINUS, (yyvsp[-1].node));}
#line 2108 "parser.tab.c"
    break;

  case 59: /* argument_expression_list: assignment_expression  */
#line 557 "parser.y"
                              {(yyval.node_list) = ast_list_add(ast_list_new(), (yyvsp[0].node));}
#line 2114 "parser.tab.c"
    break;

  case 60: /* argument_expression_list: argument_expression_list ',' assignment_expression  */
#line 558 "parser.y"
                                                             {(yyval.node_list) = ast_list_add((yyvsp[-2].node_list), (yyvsp[0].node));}
#line 2120 "parser.tab.c"
    break;

  case 62: /* unary_expression: "++" unary_expression  */
#line 563 "parser.y"
                                {(yyval.node) = ast_new_binary_op(PLUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 2126 "parser.tab.c"
    break;

  case 63: /* unary_expression: "--" unary_expression  */
#line 564 "parser.y"
                                {(yyval.node) = ast_new_binary_op(MINUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 2132 "parser.tab.c"
    break;

  case 64: /* unary_expression: '&' cast_expression  */
#line 565 "parser.y"
                              {(yyval.node) = ast_new_unary_op('&', (yyvsp[0].node));}
#line 2138 "parser.tab.c"
    break;

  case 65: /* unary_expression: '*' cast_expression  */
#line 566 "parser.y"
                              {(yyval.node) = ast_new_unary_op('*', (yyvsp[0].node));}
#line 2144 "parser.tab.c"
    break;

  case 66: /* unary_expression: '+' cast_expression  */
#line 567 "parser.y"
                              {(yyval.node) = ast_new_unary_op('+', (yyvsp[0].node));}
#line 2150 "parser.tab.c"
    break;

  case 67: /* unary_expression: '-' cast_expression  */
#line 568 "parser.y"
                              {(yyval.node) = ast_new_unary_op('-', (yyvsp[0].node));}
#line 2156 "parser.tab.c"
    break;

  case 68: /* unary_expression: '~' cast_expression  */
#line 569 "parser.y"
                              {(yyval.node) = ast_new_unary_op('~', (yyvsp[0].node));}
#line 2162 "parser.tab.c"
    break;

  case 69: /* unary_expression: '!' cast_expression  */
#line 570 "parser.y"
                              {(yyval.node) = ast_new_unary_op('!', (yyvsp[0].node));}
#line 2168 "parser.tab.c"
    break;

  case 70: /* unary_expression: SIZEOF unary_expression  */
#line 571 "parser.y"
                                  {(yyval.node) = ast_new_unary_op(SIZEOF, (yyvsp[0].node));}
#line 2174 "parser.tab.c"
    break;

  case 72: /* unary_expression: ALIGNOF unary_expression  */
#line 573 "parser.y"
                                   {(yyval.node) = ast_new_unary_op(ALIGNOF, (yyvsp[0].node));}
#line 2180 "parser.tab.c"
    break;

  case 74: /* cast_expression: '(' type_name ')' cast_expression  */
#line 578 "parser.y"
                                            {(yyval.node) = ast_new_type_cast((yyvsp[0].node), (yyvsp[-2].node));}
#line 2186 "parser.tab.c"
    break;

  case 76: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 583 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('*', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2192 "parser.tab.c"
    break;

  case 77: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 584 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('/', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2198 "parser.tab.c"
    break;

  case 78: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 585 "parser.y"
                                                        {(yyval.node) = ast_new_binary_op('%', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2204 "parser.tab.c"
    break;

  case 80: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 590 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op('+', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2210 "parser.tab.c"
    break;

  case 81: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 591 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op('-', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2216 "parser.tab.c"
    break;

  case 83: /* shift_expression: shift_expression "<<" additive_expression  */
#line 596 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2222 "parser.tab.c"
    break;

  case 84: /* shift_expression: shift_expression ">>" additive_expression  */
#line 597 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2228 "parser.tab.c"
    break;

  case 86: /* relational_expression: relational_expression '<' shift_expression  */
#line 602 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op('<', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2234 "parser.tab.c"
    break;

  case 87: /* relational_expression: relational_expression "<=" shift_expression  */
#line 603 "parser.y"
                                                      {(yyval.node) = ast_new_binary_op(LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2240 "parser.tab.c"
    break;

  case 88: /* relational_expression: relational_expression '>' shift_expression  */
#line 604 "parser.y"
                                                     {(yyval.node) = ast_new_binary_op('>', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2246 "parser.tab.c"
    break;

  case 89: /* relational_expression: relational_expression ">=" shift_expression  */
#line 605 "parser.y"
                                                      {(yyval.node) = ast_new_binary_op(GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2252 "parser.tab.c"
    break;

  case 91: /* equality_expression: equality_expression "==" relational_expression  */
#line 610 "parser.y"
                                                         {(yyval.node) = ast_new_binary_op(EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2258 "parser.tab.c"
    break;

  case 92: /* equality_expression: equality_expression "!=" relational_expression  */
#line 611 "parser.y"
                                                         {(yyval.node) = ast_new_binary_op(NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2264 "parser.tab.c"
    break;

  case 94: /* and_expression: and_expression '&' equality_expression  */
#line 616 "parser.y"
                                                 {(yyval.node) = ast_new_binary_op('&', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2270 "parser.tab.c"
    break;

  case 96: /* xor_expression: xor_expression '^' and_expression  */
#line 620 "parser.y"
                                            {(yyval.node) = ast_new_binary_op('^', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2276 "parser.tab.c"
    break;

  case 98: /* or_expression: or_expression '|' xor_expression  */
#line 624 "parser.y"
                                           {(yyval.node) = ast_new_binary_op('|', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2282 "parser.tab.c"
    break;

  case 100: /* logical_and_expression: logical_and_expression "&&" or_expression  */
#line 629 "parser.y"
                                                    {(yyval.node) = ast_new_binary_op(LOGAND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2288 "parser.tab.c"
    break;

  case 102: /* logical_or_expression: logical_or_expression "||" logical_and_expression  */
#line 634 "parser.y"
                                                            {(yyval.node) = ast_new_binary_op(LOGOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2294 "parser.tab.c"
    break;

  case 104: /* conditional_expression: logical_or_expression '?' expression ':' conditional_expression  */
#line 639 "parser.y"
                                                                          {(yyval.node) = ast_new_ternary_op((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2300 "parser.tab.c"
    break;

  case 106: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 644 "parser.y"
                                                                     {(yyval.node) = ast_new_binary_op((yyvsp[-1].integer), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2306 "parser.tab.c"
    break;

  case 107: /* assignment_operator: '='  */
#line 648 "parser.y"
            {(yyval.integer) = '=';}
#line 2312 "parser.tab.c"
    break;

  case 108: /* assignment_operator: "*="  */
#line 649 "parser.y"
               {(yyval.integer) = PLUSEQ;}
#line 2318 "parser.tab.c"
    break;

  case 109: /* assignment_operator: "/="  */
#line 650 "parser.y"
               {(yyval.integer) = MINUSEQ;}
#line 2324 "parser.tab.c"
    break;

  case 110: /* assignment_operator: "%="  */
#line 651 "parser.y"
               {(yyval.integer) = TIMESEQ;}
#line 2330 "parser.tab.c"
    break;

  case 111: /* assignment_operator: "+="  */
#line 652 "parser.y"
               {(yyval.integer) = DIVEQ;}
#line 2336 "parser.tab.c"
    break;

  case 112: /* assignment_operator: "-="  */
#line 653 "parser.y"
               {(yyval.integer) = MODEQ;}
#line 2342 "parser.tab.c"
    break;

  case 113: /* assignment_operator: "<<="  */
#line 654 "parser.y"
                {(yyval.integer) = SHLEQ;}
#line 2348 "parser.tab.c"
    break;

  case 114: /* assignment_operator: ">>="  */
#line 655 "parser.y"
                {(yyval.integer) = SHREQ;}
#line 2354 "parser.tab.c"
    break;

  case 115: /* assignment_operator: "&="  */
#line 656 "parser.y"
               {(yyval.integer) = ANDEQ;}
#line 2360 "parser.tab.c"
    break;

  case 116: /* assignment_operator: "^="  */
#line 657 "parser.y"
               {(yyval.integer) = XOREQ;}
#line 2366 "parser.tab.c"
    break;

  case 117: /* assignment_operator: "|="  */
#line 658 "parser.y"
               {(yyval.integer) = OREQ;}
#line 2372 "parser.tab.c"
    break;

  case 119: /* expression: expression ',' assignment_expression  */
#line 663 "parser.y"
                                               {(yyval.node) = ast_new_binary_op(',', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2378 "parser.tab.c"
    break;

  case 121: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 676 "parser.y"
    {
        (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_normalize_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
        (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
        (yyval.declaration_package) = (yyvsp[-1].declaration_package);
    }
#line 2388 "parser.tab.c"
    break;

  case 123: /* declaration_specifiers: type_specifier  */
#line 687 "parser.y"
                           {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2394 "parser.tab.c"
    break;

  case 124: /* declaration_specifiers: type_qualifier  */
#line 688 "parser.y"
                             {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2400 "parser.tab.c"
    break;

  case 125: /* declaration_specifiers: storage_class_specifier  */
#line 689 "parser.y"
                                      {declspec_init(&(yyval.declaration_specifiers)); declspec_add_storage_class(&(yyval.declaration_specifiers), (yyvsp[0].storage_class_specifier));}
#line 2406 "parser.tab.c"
    break;

  case 126: /* declaration_specifiers: function_specifier  */
#line 690 "parser.y"
                                 {declspec_init(&(yyval.declaration_specifiers)); declspec_add_function_specifier(&(yyval.declaration_specifiers), (yyvsp[0].function_specifier));}
#line 2412 "parser.tab.c"
    break;

  case 127: /* declaration_specifiers: declaration_specifiers type_specifier  */
#line 691 "parser.y"
                                                    {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2418 "parser.tab.c"
    break;

  case 128: /* declaration_specifiers: declaration_specifiers type_qualifier  */
#line 692 "parser.y"
                                                    {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2424 "parser.tab.c"
    break;

  case 129: /* declaration_specifiers: declaration_specifiers storage_class_specifier  */
#line 693 "parser.y"
                                                             {declspec_add_storage_class(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].storage_class_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2430 "parser.tab.c"
    break;

  case 130: /* declaration_specifiers: declaration_specifiers function_specifier  */
#line 694 "parser.y"
                                                        {declspec_add_function_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].function_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2436 "parser.tab.c"
    break;

  case 131: /* storage_class_specifier: EXTERN  */
#line 699 "parser.y"
                   {(yyval.storage_class_specifier) = SC_EXTERN;}
#line 2442 "parser.tab.c"
    break;

  case 132: /* storage_class_specifier: STATIC  */
#line 700 "parser.y"
                     {(yyval.storage_class_specifier) = SC_STATIC;}
#line 2448 "parser.tab.c"
    break;

  case 133: /* storage_class_specifier: AUTO  */
#line 701 "parser.y"
                   {(yyval.storage_class_specifier) = SC_AUTO;}
#line 2454 "parser.tab.c"
    break;

  case 134: /* storage_class_specifier: REGISTER  */
#line 702 "parser.y"
                       {(yyval.storage_class_specifier) = SC_REGISTER;}
#line 2460 "parser.tab.c"
    break;

  case 135: /* type_specifier: VOID  */
#line 708 "parser.y"
                 {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_VOID};}
#line 2466 "parser.tab.c"
    break;

  case 136: /* type_specifier: CHAR  */
#line 709 "parser.y"
                   {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_CHAR};}
#line 2472 "parser.tab.c"
    break;

  case 137: /* type_specifier: SHORT  */
#line 710 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SHORT};}
#line 2478 "parser.tab.c"
    break;

  case 138: /* type_specifier: INT  */
#line 711 "parser.y"
                  {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_INT};}
#line 2484 "parser.tab.c"
    break;

  case 139: /* type_specifier: LONG  */
#line 712 "parser.y"
                   {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_LONG};}
#line 2490 "parser.tab.c"
    break;

  case 140: /* type_specifier: FLOAT  */
#line 713 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_FLOAT};}
#line 2496 "parser.tab.c"
    break;

  case 141: /* type_specifier: DOUBLE  */
#line 714 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_DOUBLE};}
#line 2502 "parser.tab.c"
    break;

  case 142: /* type_specifier: SIGNED  */
#line 715 "parser.y"
                     {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SIGNED};}
#line 2508 "parser.tab.c"
    break;

  case 143: /* type_specifier: UNSIGNED  */
#line 716 "parser.y"
                       {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_UNSIGNED};}
#line 2514 "parser.tab.c"
    break;

  case 144: /* type_specifier: _BOOL  */
#line 717 "parser.y"
                    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_BOOL};}
#line 2520 "parser.tab.c"
    break;

  case 145: /* type_specifier: _COMPLEX  */
#line 718 "parser.y"
                       {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_COMPLEX};}
#line 2526 "parser.tab.c"
    break;

  case 146: /* type_specifier: struct_or_union_specifier  */
#line 719 "parser.y"
                                        {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_STRUCT_OR_UNION, .custom = (yyvsp[0].node)};}
#line 2532 "parser.tab.c"
    break;

  case 147: /* type_qualifier: CONST  */
#line 726 "parser.y"
                  {(yyval.type_qualifier) = TQ_CONST;}
#line 2538 "parser.tab.c"
    break;

  case 148: /* type_qualifier: RESTRICT  */
#line 727 "parser.y"
                       {(yyval.type_qualifier) = TQ_RESTRICT;}
#line 2544 "parser.tab.c"
    break;

  case 149: /* type_qualifier: VOLATILE  */
#line 728 "parser.y"
                       {(yyval.type_qualifier) = TQ_VOLATILE;}
#line 2550 "parser.tab.c"
    break;

  case 150: /* function_specifier: INLINE  */
#line 733 "parser.y"
                   {(yyval.function_specifier) = FS_INLINE;}
#line 2556 "parser.tab.c"
    break;

  case 151: /* init_declarator_list: init_declarator  */
#line 738 "parser.y"
                    {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 2562 "parser.tab.c"
    break;

  case 152: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 739 "parser.y"
                                               {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 2568 "parser.tab.c"
    break;

  case 153: /* init_declarator: declarator  */
#line 743 "parser.y"
               {(yyvsp[0].declarator_helper).initializer = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2574 "parser.tab.c"
    break;

  case 154: /* init_declarator: declarator '=' initializer  */
#line 744 "parser.y"
                                 {(yyvsp[-2].declarator_helper).initializer = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 2580 "parser.tab.c"
    break;

  case 155: /* declarator: direct_declarator  */
#line 748 "parser.y"
                      {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2586 "parser.tab.c"
    break;

  case 156: /* declarator: pointer direct_declarator  */
#line 749 "parser.y"
                                {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2592 "parser.tab.c"
    break;

  case 157: /* direct_declarator: identifier  */
#line 753 "parser.y"
               {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = (yyvsp[0].node);}
#line 2598 "parser.tab.c"
    break;

  case 158: /* direct_declarator: '(' declarator ')'  */
#line 754 "parser.y"
                         {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2604 "parser.tab.c"
    break;

  case 159: /* direct_declarator: direct_declarator '[' ']'  */
#line 755 "parser.y"
                                {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2610 "parser.tab.c"
    break;

  case 160: /* direct_declarator: direct_declarator '[' constant_expression ']'  */
#line 756 "parser.y"
                                                    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2616 "parser.tab.c"
    break;

  case 161: /* direct_declarator: direct_declarator '(' ')'  */
#line 757 "parser.y"
                                {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2622 "parser.tab.c"
    break;

  case 162: /* direct_declarator: direct_declarator '(' identifier_list ')'  */
#line 759 "parser.y"
                                                {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2628 "parser.tab.c"
    break;

  case 163: /* direct_declarator: direct_declarator '(' parameter_type_list ')'  */
#line 760 "parser.y"
                                                    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2634 "parser.tab.c"
    break;

  case 164: /* pointer: '*'  */
#line 764 "parser.y"
        {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer(0);}
#line 2640 "parser.tab.c"
    break;

  case 165: /* pointer: '*' type_qualifier_list  */
#line 765 "parser.y"
                              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer((yyvsp[0].type_qualifier));}
#line 2646 "parser.tab.c"
    break;

  case 166: /* pointer: '*' pointer  */
#line 766 "parser.y"
                  {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer(0); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2652 "parser.tab.c"
    break;

  case 167: /* pointer: '*' type_qualifier_list pointer  */
#line 767 "parser.y"
                                      {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer((yyvsp[-1].type_qualifier)); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2658 "parser.tab.c"
    break;

  case 168: /* type_qualifier_list: type_qualifier  */
#line 771 "parser.y"
                   {(yyval.type_qualifier) = (yyvsp[0].type_qualifier);}
#line 2664 "parser.tab.c"
    break;

  case 169: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 772 "parser.y"
                                         {(yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier);}
#line 2670 "parser.tab.c"
    break;

  case 170: /* parameter_type_list: parameter_list  */
#line 777 "parser.y"
                   {(yyval.symbol_table) = (yyvsp[0].symbol_table);}
#line 2676 "parser.tab.c"
    break;

  case 171: /* parameter_list: parameter_declaration  */
#line 782 "parser.y"
                          {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2682 "parser.tab.c"
    break;

  case 172: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 784 "parser.y"
    {
        if ((yyvsp[0].node)->name && st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, (yyvsp[0].node)->name);
            exit(EXIT_FAILURE);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2695 "parser.tab.c"
    break;

  case 173: /* parameter_declaration: declaration_specifiers declarator  */
#line 796 "parser.y"
    {
        (yyvsp[-1].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[-1].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable((yyvsp[0].declarator_helper).oldest, (yyvsp[-1].declaration_specifiers).storage_class);
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2707 "parser.tab.c"
    break;

  case 174: /* parameter_declaration: declaration_specifiers  */
#line 803 "parser.y"
                             {
        (yyvsp[0].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[0].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[0].declaration_specifiers).storage_class);
        var->next = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2719 "parser.tab.c"
    break;

  case 175: /* parameter_declaration: declaration_specifiers abstract_declarator  */
#line 811 "parser.y"
    {
        (yyvsp[-1].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[-1].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[-1].declaration_specifiers).storage_class);
        var->next = (yyvsp[0].declarator_helper).oldest;
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2732 "parser.tab.c"
    break;

  case 176: /* identifier_list: identifier  */
#line 822 "parser.y"
               {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2738 "parser.tab.c"
    break;

  case 177: /* identifier_list: identifier_list ',' identifier  */
#line 824 "parser.y"
    {
        if (st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, (yyvsp[0].node)->name);
            exit(EXIT_FAILURE);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2751 "parser.tab.c"
    break;

  case 178: /* type_name: specifier_qualifier_list  */
#line 835 "parser.y"
                             {(yyval.node) = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);}
#line 2757 "parser.tab.c"
    break;

  case 179: /* type_name: specifier_qualifier_list abstract_declarator  */
#line 837 "parser.y"
    {
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = (yyvsp[0].declarator_helper).oldest;
    }
#line 2766 "parser.tab.c"
    break;

  case 180: /* abstract_declarator: pointer  */
#line 844 "parser.y"
            {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2772 "parser.tab.c"
    break;

  case 181: /* abstract_declarator: direct_abstract_declarator  */
#line 845 "parser.y"
                                 {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2778 "parser.tab.c"
    break;

  case 182: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 846 "parser.y"
                                         {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2784 "parser.tab.c"
    break;

  case 183: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 850 "parser.y"
                                {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2790 "parser.tab.c"
    break;

  case 184: /* direct_abstract_declarator: '[' ']'  */
#line 851 "parser.y"
              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array(0);}
#line 2796 "parser.tab.c"
    break;

  case 185: /* direct_abstract_declarator: '[' constant_expression ']'  */
#line 852 "parser.y"
                                  {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array((yyvsp[-1].node));}
#line 2802 "parser.tab.c"
    break;

  case 186: /* direct_abstract_declarator: direct_abstract_declarator '[' ']'  */
#line 853 "parser.y"
                                         {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2808 "parser.tab.c"
    break;

  case 187: /* direct_abstract_declarator: direct_abstract_declarator '[' constant_expression ']'  */
#line 854 "parser.y"
                                                             {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2814 "parser.tab.c"
    break;

  case 188: /* direct_abstract_declarator: '(' ')'  */
#line 855 "parser.y"
              {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(0);}
#line 2820 "parser.tab.c"
    break;

  case 189: /* direct_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 856 "parser.y"
                                         {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2826 "parser.tab.c"
    break;

  case 190: /* direct_abstract_declarator: '(' parameter_type_list ')'  */
#line 857 "parser.y"
                                  {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(st_unpack((yyvsp[-1].symbol_table)));}
#line 2832 "parser.tab.c"
    break;

  case 191: /* direct_abstract_declarator: direct_abstract_declarator '(' parameter_type_list ')'  */
#line 858 "parser.y"
                                                             {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2838 "parser.tab.c"
    break;

  case 193: /* struct_or_union_specifier: struct_or_union '{' struct_declaration_list '}'  */
#line 871 "parser.y"
                                                        {(yyval.node) = ast_new_struct_or_union((yyvsp[-3].integer), 0, st_unpack((yyvsp[-1].symbol_table)));}
#line 2844 "parser.tab.c"
    break;

  case 194: /* @7: %empty  */
#line 873 "parser.y"
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
#line 2877 "parser.tab.c"
    break;

  case 195: /* struct_or_union_specifier: struct_or_union IDENT '{' @7 struct_declaration_list '}'  */
#line 902 "parser.y"
            {
                (yyval.node) = ast_add_struct_or_union_members((yyvsp[-2].node), st_unpack((yyvsp[-1].symbol_table)));
                ast_print_struct_or_union((yyval.node)); // ! debug
            }
#line 2886 "parser.tab.c"
    break;

  case 196: /* struct_or_union_specifier: struct_or_union IDENT  */
#line 907 "parser.y"
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
#line 2903 "parser.tab.c"
    break;

  case 197: /* struct_or_union: STRUCT  */
#line 922 "parser.y"
               {(yyval.integer) = AST_STRUCT;}
#line 2909 "parser.tab.c"
    break;

  case 198: /* struct_or_union: UNION  */
#line 923 "parser.y"
                {(yyval.integer) = AST_UNION;}
#line 2915 "parser.tab.c"
    break;

  case 199: /* struct_declaration_list: struct_declaration  */
#line 927 "parser.y"
                           {(yyval.symbol_table) = add_members_to_symbol_table(st_new(0), (yyvsp[0].declaration_package));}
#line 2921 "parser.tab.c"
    break;

  case 200: /* struct_declaration_list: struct_declaration_list struct_declaration  */
#line 928 "parser.y"
                                                     {(yyval.symbol_table) = add_members_to_symbol_table((yyvsp[-1].symbol_table), (yyvsp[0].declaration_package));}
#line 2927 "parser.tab.c"
    break;

  case 201: /* struct_declaration: specifier_qualifier_list struct_declarator_list ';'  */
#line 933 "parser.y"
        {
            (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_normalize_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
            (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
            (yyval.declaration_package) = (yyvsp[-1].declaration_package);
        }
#line 2937 "parser.tab.c"
    break;

  case 202: /* specifier_qualifier_list: type_specifier  */
#line 941 "parser.y"
                       {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2943 "parser.tab.c"
    break;

  case 203: /* specifier_qualifier_list: type_qualifier  */
#line 942 "parser.y"
                         {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2949 "parser.tab.c"
    break;

  case 204: /* specifier_qualifier_list: specifier_qualifier_list type_specifier  */
#line 943 "parser.y"
                                                  {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2955 "parser.tab.c"
    break;

  case 205: /* specifier_qualifier_list: specifier_qualifier_list type_qualifier  */
#line 944 "parser.y"
                                                  {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2961 "parser.tab.c"
    break;

  case 206: /* struct_declarator_list: struct_declarator  */
#line 948 "parser.y"
                          {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 2967 "parser.tab.c"
    break;

  case 207: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 949 "parser.y"
                                                       {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 2973 "parser.tab.c"
    break;

  case 208: /* struct_declarator: declarator  */
#line 953 "parser.y"
                   {(yyvsp[0].declarator_helper).bit_width = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2979 "parser.tab.c"
    break;

  case 209: /* struct_declarator: ':' constant_expression  */
#line 954 "parser.y"
                                  {(yyval.declarator_helper) = (declarator_helper_t){.oldest = 0, .newest = 0, .bit_width = (yyvsp[0].node)};}
#line 2985 "parser.tab.c"
    break;

  case 210: /* struct_declarator: declarator ':' constant_expression  */
#line 955 "parser.y"
                                             {(yyvsp[-2].declarator_helper).bit_width = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 2991 "parser.tab.c"
    break;


#line 2995 "parser.tab.c"

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

#line 980 "parser.y"


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
