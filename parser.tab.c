/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "parser.y" /* yacc.c:339  */

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

#line 85 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
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
#line 28 "parser.y" /* yacc.c:355  */

    #include "declarations.h"
    #include "types.h"
    #include "ast.h"
    #include "symbol_table.h"

#line 122 "parser.tab.c" /* yacc.c:355  */

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
#line 35 "parser.y" /* yacc.c:355  */

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

#line 226 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1246

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  210
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  338

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   321

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
static const yytype_uint16 yyrline[] =
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

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENT", "CHARLIT", "STRINGLIT",
  "NUMBERLIT", "\"->\"", "\"++\"", "\"--\"", "\"<<\"", "\">>\"", "\"<=\"",
  "\">=\"", "\"==\"", "\"!=\"", "\"&&\"", "\"||\"", "\"...\"", "\"*=\"",
  "\"/=\"", "\"%=\"", "\"+=\"", "\"-=\"", "\"<<=\"", "\">>=\"", "\"&=\"",
  "\"|=\"", "\"^=\"", "AUTO", "ALIGNOF", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL",
  "_COMPLEX", "_IMAGINARY", "'{'", "'}'", "';'", "'('", "')'", "':'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "$accept",
  "identifier", "string_literal", "constant", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "xor_expression", "or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "initializer",
  "declaration_specifiers", "storage_class_specifier",
  "function_specifier", "type_qualifier", "type_specifier", "declaration",
  "init_declarator_list", "init_declarator", "declarator",
  "direct_declarator", "pointer", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "struct_declaration_list",
  "struct_declaration", "struct_declarator_list",
  "specifier_qualifier_list", "struct_declarator", "identifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "type_qualifier_list", "struct_or_union", "struct_or_union_specifier",
  "optional_expression", "statement", "compound_statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "labeled_statement", "translation_unit",
  "external_declaration", "function_definition", "@1", "block_item_list",
  "block_item", "$@2", "optional_block_item_list", "@3", "@4", "@5", "@6",
  "@7", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   123,   125,    59,
      40,    41,    58,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      61
};
# endif

#define YYPACT_NINF -196

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-196)))

#define YYTABLE_NINF -22

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1082,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   789,  -196,  -196,  -196,  -196,  -196,    21,  -196,
     946,  -196,  -196,  -196,  -196,    34,    -4,  -196,  -196,  -196,
    -196,  -196,   -44,  -196,   -50,   100,    44,   -55,  1181,  -196,
    -196,   -42,  -196,  -196,    -4,  -196,    34,   644,   -29,   907,
     521,   100,  -196,  -196,  -196,  1115,  -196,   865,  -196,  -196,
    -196,  -196,   -46,  -196,  -196,  -196,   657,   657,   657,   698,
     441,   644,   644,   644,   644,   644,   644,  -196,  -196,  -196,
    -196,    70,   358,  -196,   -24,    69,   149,    22,   178,    13,
     -12,   -25,    78,    -2,  -196,  -196,  -196,   281,  -196,  -196,
    -196,   831,    50,    15,    43,  -196,  -196,  -196,  -196,    98,
    1181,  -196,  -196,   644,  -196,  -196,    58,   -43,  -196,   644,
    -196,  -196,  -196,   441,  -196,  -196,    51,   112,  1014,  -196,
    -196,  -196,  -196,  -196,  -196,   174,  -196,  -196,   560,   644,
     183,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,  -196,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   644,   644,   644,   644,   644,   644,   644,   644,
     644,   644,   117,   125,   644,   132,   131,  -196,   146,   215,
     157,   644,   162,   163,  -196,   -20,   789,  -196,  -196,  -196,
    -196,  -196,  -196,  -196,   361,  -196,   -29,   167,   755,   602,
    -196,    45,  -196,   106,  -196,   233,  -196,  1082,  -196,  1148,
    -196,   644,  -196,    28,   170,  -196,   644,   644,   980,   111,
    -196,  -196,  -196,    57,  -196,    -7,  -196,  -196,  -196,  -196,
    -196,   -24,   -24,    69,    69,   149,   149,   149,   149,    22,
      22,   178,    13,   -12,   -25,    78,   -15,   504,  -196,   172,
    -196,   504,   504,   644,   173,   644,   169,   177,   644,   644,
    -196,  -196,  -196,  -196,  -196,   176,   179,  -196,   180,   106,
    1048,   615,  -196,  -196,  -196,  -196,  -196,  -196,  -196,  -196,
    -196,   644,  -196,   644,  -196,   504,  -196,   185,   182,  -196,
      75,  -196,    79,    82,  -196,  -196,  -196,  -196,   181,  -196,
     186,  -196,  -196,  -196,   187,   644,   504,  -196,  -196,  -196,
    -196,   644,   184,   216,   504,   504,    95,   644,   504,  -196,
    -196,   192,   191,  -196,  -196,  -196,   504,  -196
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   133,   136,   147,   141,   131,   140,   150,   138,   139,
     134,   148,   137,   142,   132,   197,   198,   143,   135,   149,
     144,   145,     0,   125,   126,   124,   123,     5,     0,   146,
       0,     2,     4,    43,   122,     0,   164,   157,   129,   130,
     128,   127,     0,   151,   153,   155,     0,   196,     0,     1,
       3,     0,   168,   166,   165,   121,     0,     0,     0,     0,
       0,   156,   194,   203,   202,     0,   199,     0,   158,   169,
     167,   152,   153,    45,    44,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    47,    49,    48,
      51,    61,    73,    75,    79,    82,    85,    90,    93,    95,
      97,    99,   101,   103,   105,   192,   154,    12,     7,   161,
     176,   174,     0,     0,   170,   171,   159,    73,   120,     0,
       0,   193,   200,     0,   205,   204,   208,     0,   206,     0,
      62,    63,    72,     0,    70,   118,     0,     0,   178,    64,
      65,    66,    67,    68,    69,     0,    57,    58,     0,     0,
       0,   108,   109,   110,   111,   112,   113,   114,   115,   117,
     116,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    43,     0,     0,     0,     0,    30,     0,     0,
       0,    35,     0,     0,    23,     0,     0,    10,    11,    14,
      15,    16,    17,    18,    12,     8,     0,     0,     0,     0,
     173,   180,   175,   181,   162,     0,   163,     0,   160,     0,
     209,     0,   201,     0,     0,    50,     0,     0,     0,   180,
     179,    56,    53,     0,    59,     0,    55,   106,    76,    77,
      78,    80,    81,    83,    84,    87,    89,    86,    88,    91,
      92,    94,    96,    98,   100,   102,     0,    12,    38,     0,
      37,    12,    12,    35,     0,     0,    34,     0,     0,     0,
      22,     9,    13,    19,   188,     0,     0,   184,     0,   182,
       0,     0,   177,   172,   195,   210,   207,    71,   119,    74,
      54,     0,    52,     0,    40,    12,    42,     0,     0,    36,
       0,    39,     0,     0,   183,   190,   185,   189,     0,   186,
       0,    60,   104,    41,     0,    35,    12,    26,    28,   191,
     187,     0,     0,    24,    12,    12,     0,    35,    12,    27,
      29,     0,     0,    25,    31,    32,    12,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -196,     6,  -196,  -196,  -196,  -196,  -196,   -57,    -1,    29,
      55,   -34,    56,    80,    86,    88,    90,    85,  -196,   -53,
     -52,  -196,   -78,  -120,  -196,     9,   -18,   -16,    87,    77,
     -93,  -196,   218,   -14,   -36,    -9,   139,   -95,  -193,   155,
     -54,  -196,   -67,    53,  -196,   -58,  -196,    60,  -196,  -196,
    -196,  -195,   458,    72,  -196,  -196,  -196,  -196,  -196,  -196,
     250,  -196,  -196,  -196,    84,  -196,  -196,  -196,  -196,  -196,
    -196,  -196
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    87,    88,    89,    90,    91,   233,   117,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     135,   162,   195,   119,   106,   111,    23,    24,    25,    26,
      27,    42,    43,    51,    45,    46,   137,   275,   213,    65,
      66,   127,    67,   128,   112,   276,   114,   115,    54,    28,
      29,   267,   198,   108,   199,   200,   201,   202,   203,    30,
      31,    32,    58,   204,   205,   206,   207,   324,   325,   262,
     336,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   113,   136,   220,    38,   105,    39,   118,    44,    22,
      61,   122,    62,   138,   197,   180,   212,    -6,   279,   130,
     131,   132,   134,    92,    47,    55,   222,    53,    37,    68,
       3,    33,    56,   223,   170,   171,   279,    33,   107,    22,
      57,    37,    72,   230,    57,    70,    11,    33,    33,   270,
      92,   136,    37,   126,   163,   136,   226,   293,    19,   164,
     165,   226,    37,   178,   259,   110,   138,   292,   298,   226,
     118,   235,    92,    37,    36,   177,    92,   145,   146,   147,
     139,   140,   141,   142,   143,   144,   216,   181,    48,   278,
     176,    92,    92,    38,   179,    39,   234,   210,    35,    41,
     123,   285,   211,   256,    35,    92,    36,   172,   173,    40,
     237,   197,    36,   266,    35,   208,   196,    37,   209,   217,
     322,   214,   225,    52,    92,    64,   215,   226,   290,   229,
     221,   118,   332,   291,    92,    63,   245,   246,   247,   248,
     148,    69,    64,   149,   125,   150,   316,    92,   166,   167,
     317,   226,    63,   318,   124,   226,   118,    64,   226,   168,
     169,   310,   238,   239,   240,   122,   331,    63,   118,    92,
      59,   226,   218,    60,   288,    61,   280,   231,    38,   281,
      39,   228,    72,   227,   209,   266,   236,   300,    41,   257,
     302,   303,   174,   175,   258,   241,   242,    64,    40,   211,
      92,   260,    37,   261,    92,    92,    92,    63,    92,   126,
      64,    92,    92,   196,    37,   125,   263,    37,   264,   229,
      63,   282,   308,   243,   244,   124,   289,   265,   118,    37,
     249,   250,   268,   269,    92,   273,    33,   266,    92,   311,
     312,   287,   299,   326,   295,   226,   301,   304,   314,   266,
     305,   315,   319,   327,   306,   328,   251,   321,    92,    92,
     320,   334,   335,   252,    92,   255,   253,    92,    92,   254,
      92,    92,   224,    41,    71,   219,   286,   283,   272,    92,
      50,     0,     0,    40,   182,    73,    74,    75,   271,    76,
      77,     0,     0,     0,     0,     0,    64,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,     0,     0,     0,
       1,    78,   183,   184,     2,     3,   185,   186,   187,     4,
       0,     0,     5,     6,   188,   189,   190,     7,     8,     9,
      10,    11,   191,    12,    13,    79,    14,    15,   192,     0,
      16,    17,    18,    19,   193,    20,    21,     0,     0,   -21,
     194,    80,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,   182,    73,    74,    75,     0,    76,
      77,     0,     0,     0,     0,     0,     0,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,     0,     0,
       1,    78,   183,   184,     2,     3,   185,   186,   187,     4,
       0,     0,     5,     6,   188,   189,   190,     7,     8,     9,
      10,    11,   191,    12,    13,    79,    14,    15,   192,     0,
      16,    17,    18,    19,   193,    20,    21,     0,     0,   -20,
     194,    80,     0,     0,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    33,    73,    74,    75,   161,    76,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     2,     3,     0,     0,     0,     4,
       0,     0,     0,     6,     0,     0,     0,     0,     8,     9,
       0,    11,     0,    12,    13,    79,     0,    15,     0,     0,
      16,    17,    18,    19,     0,    20,    21,   182,    73,    74,
      75,    80,    76,    77,     0,     0,     0,     0,    81,    82,
      83,    84,    85,    86,    33,    73,    74,    75,     0,    76,
      77,     0,     0,     0,    78,   183,   184,     0,     0,   185,
     186,   187,     0,     0,     0,     0,     0,   188,   189,   190,
       0,    78,     0,     0,     0,   191,     0,     0,    79,     0,
       0,   192,     0,    33,    73,    74,    75,   193,    76,    77,
       0,     0,     0,   194,    80,    79,     0,     0,     0,     0,
       0,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      78,    80,     0,     0,     0,   116,     0,     0,    81,    82,
      83,    84,    85,    86,     0,    33,    73,    74,    75,     0,
      76,    77,     0,     0,    79,     0,     0,     0,    33,    73,
      74,    75,     0,    76,    77,     0,     0,     0,     0,     0,
      80,   232,    78,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,     0,     0,    78,     0,    33,    73,    74,
      75,     0,    76,    77,     0,     0,    79,     0,     0,     0,
      33,    73,    74,    75,     0,    76,    77,     0,     0,    79,
       0,     0,    80,     0,    78,     0,   277,     0,     0,    81,
      82,    83,    84,    85,    86,    80,     0,    78,     0,   309,
       0,     0,    81,    82,    83,    84,    85,    86,    79,     0,
       0,    33,    73,    74,    75,     0,    76,    77,     0,     0,
       0,    79,     0,     0,    80,   294,     0,     0,     0,   296,
     297,    81,    82,    83,    84,    85,    86,   129,    78,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    79,   313,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,     0,     0,     0,   323,    81,    82,    83,    84,    85,
      86,     0,   329,   330,     1,     0,   333,     0,     2,     3,
       0,     0,    33,     4,   337,     0,     5,     6,     0,     0,
       0,     7,     8,     9,    10,    11,     0,    12,    13,     0,
      14,    15,     0,     0,    16,    17,    18,    19,     1,    20,
      21,     0,     2,     3,     0,   208,   274,     4,   209,     0,
       5,     6,     0,    36,    33,     7,     8,     9,    10,    11,
       0,    12,    13,     0,    14,    15,     0,     0,    16,    17,
      18,    19,     0,    20,    21,     0,     0,     0,    34,    35,
       1,     0,     0,     0,     2,     3,     0,    36,    33,     4,
       0,     0,     5,     6,     0,     0,     0,     7,     8,     9,
      10,    11,     0,    12,    13,     0,    14,    15,     0,     0,
      16,    17,    18,    19,     0,    20,    21,     0,     2,     3,
       0,   208,     0,     4,   209,     0,     0,     6,     0,    36,
      33,     0,     8,     9,     0,    11,     0,    12,    13,     0,
       0,    15,     0,     0,    16,    17,    18,    19,     0,    20,
      21,     0,     0,     0,     0,    35,     1,   123,     0,     0,
       2,     3,     0,    36,     0,     4,    49,     0,     5,     6,
       0,     0,     0,     7,     8,     9,    10,    11,     0,    12,
      13,     0,    14,    15,     0,     0,    16,    17,    18,    19,
       0,    20,    21,     0,     0,     1,     0,     0,   109,     2,
       3,     0,     0,     0,     4,     0,     0,     5,     6,     0,
       0,     0,     7,     8,     9,    10,    11,     0,    12,    13,
       0,    14,    15,     0,     0,    16,    17,    18,    19,     1,
      20,    21,     0,     2,     3,     0,     0,     0,     4,     0,
       0,     5,     6,     0,     0,     0,     7,     8,     9,    10,
      11,     0,    12,    13,     0,    14,    15,     0,     0,    16,
      17,    18,    19,     0,    20,    21,     0,     2,     3,     0,
     228,   274,     4,   209,     0,     0,     6,     0,    36,     0,
       0,     8,     9,     0,    11,     0,    12,    13,     0,     0,
      15,     0,     0,    16,    17,    18,    19,     1,    20,    21,
       0,     2,     3,     0,   228,     0,     4,   209,     0,     5,
       6,     0,    36,     0,     7,     8,     9,    10,    11,     0,
      12,    13,     0,    14,    15,     0,     0,    16,    17,    18,
      19,     1,    20,    21,     0,     2,     3,     0,     0,   307,
       4,     0,     0,     5,     6,     0,     0,     0,     7,     8,
       9,    10,    11,     0,    12,    13,     0,    14,    15,     0,
       0,    16,    17,    18,    19,     0,    20,    21,     2,     3,
       0,     0,     0,     4,     0,     0,     0,     6,     0,     0,
       0,     0,     8,     9,     0,    11,     0,    12,    13,     0,
       0,    15,     0,     0,    16,    17,    18,    19,     0,    20,
      21,     2,     3,   121,     0,     0,     4,     0,     0,     0,
       6,     0,     0,     0,     0,     8,     9,     0,    11,     0,
      12,    13,     0,     0,    15,     0,     0,    16,    17,    18,
      19,     0,    20,    21,     2,     3,   284,     0,     0,     4,
       0,     0,     0,     6,     0,     0,     0,     0,     8,     9,
       0,    11,     0,    12,    13,     0,     0,    15,     0,     0,
      16,    17,    18,    19,     0,    20,    21
};

static const yytype_int16 yycheck[] =
{
      57,    59,    80,   123,    22,    57,    22,    60,    22,     0,
      46,    65,    67,    80,   107,    17,   111,    67,   211,    76,
      77,    78,    79,    80,     3,    69,    69,    36,    22,    71,
      34,     3,    76,    76,    12,    13,   229,     3,    67,    30,
      90,    35,    56,   138,    90,    54,    50,     3,     3,    69,
     107,   129,    46,    67,    78,   133,    76,    72,    62,    83,
      84,    76,    56,    88,   184,    59,   133,    74,   263,    76,
     123,   149,   129,    67,    78,    87,   133,     7,     8,     9,
      81,    82,    83,    84,    85,    86,    71,    89,    67,   209,
      77,   148,   149,   111,    16,   111,   148,   111,    70,    22,
      72,   221,   111,   181,    70,   162,    78,    85,    86,    22,
     162,   204,    78,   191,    70,    70,   107,   111,    73,    76,
     315,    71,    71,    36,   181,    48,    76,    76,    71,   138,
      72,   184,   327,    76,   191,    48,   170,   171,   172,   173,
      70,    54,    65,    73,    67,    75,    71,   204,    79,    80,
      71,    76,    65,    71,    67,    76,   209,    80,    76,    10,
      11,   281,   163,   164,   165,   219,    71,    80,   221,   226,
      70,    76,    74,    73,   226,   211,    70,     3,   196,    73,
     196,    70,   196,    71,    73,   263,     3,   265,   111,    72,
     268,   269,    14,    15,    69,   166,   167,   120,   111,   208,
     257,    69,   196,    72,   261,   262,   263,   120,   265,   223,
     133,   268,   269,   204,   208,   138,    70,   211,     3,   228,
     133,   215,   280,   168,   169,   138,   227,    70,   281,   223,
     174,   175,    70,    70,   291,    68,     3,   315,   295,   291,
     293,    71,    69,   321,    72,    76,    69,    71,    63,   327,
      71,    69,    71,    69,    74,    39,   176,    70,   315,   316,
      74,    69,    71,   177,   321,   180,   178,   324,   325,   179,
     327,   328,   133,   196,    56,   120,   223,   217,   206,   336,
      30,    -1,    -1,   196,     3,     4,     5,     6,   204,     8,
       9,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    -1,    -1,    -1,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    61,    62,    63,    64,    65,    -1,    -1,    68,
      69,    70,    -1,    -1,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,     3,     4,     5,     6,    90,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      -1,    50,    -1,    52,    53,    54,    -1,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65,     3,     4,     5,
       6,    70,     8,     9,    -1,    -1,    -1,    -1,    77,    78,
      79,    80,    81,    82,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    -1,    30,    31,    32,    -1,    -1,    35,
      36,    37,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,
      -1,    30,    -1,    -1,    -1,    51,    -1,    -1,    54,    -1,
      -1,    57,    -1,     3,     4,     5,     6,    63,     8,     9,
      -1,    -1,    -1,    69,    70,    54,    -1,    -1,    -1,    -1,
      -1,    77,    78,    79,    80,    81,    82,    -1,    -1,    -1,
      30,    70,    -1,    -1,    -1,    74,    -1,    -1,    77,    78,
      79,    80,    81,    82,    -1,     3,     4,     5,     6,    -1,
       8,     9,    -1,    -1,    54,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
      70,    71,    30,    -1,    -1,    -1,    -1,    77,    78,    79,
      80,    81,    82,    -1,    -1,    30,    -1,     3,     4,     5,
       6,    -1,     8,     9,    -1,    -1,    54,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    54,
      -1,    -1,    70,    -1,    30,    -1,    74,    -1,    -1,    77,
      78,    79,    80,    81,    82,    70,    -1,    30,    -1,    74,
      -1,    -1,    77,    78,    79,    80,    81,    82,    54,    -1,
      -1,     3,     4,     5,     6,    -1,     8,     9,    -1,    -1,
      -1,    54,    -1,    -1,    70,   257,    -1,    -1,    -1,   261,
     262,    77,    78,    79,    80,    81,    82,    70,    30,    -1,
      -1,    -1,    -1,    -1,    77,    78,    79,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,   295,    -1,    -1,    -1,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,   316,    77,    78,    79,    80,    81,
      82,    -1,   324,   325,    29,    -1,   328,    -1,    33,    34,
      -1,    -1,     3,    38,   336,    -1,    41,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    -1,    52,    53,    -1,
      55,    56,    -1,    -1,    59,    60,    61,    62,    29,    64,
      65,    -1,    33,    34,    -1,    70,    71,    38,    73,    -1,
      41,    42,    -1,    78,     3,    46,    47,    48,    49,    50,
      -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,    60,
      61,    62,    -1,    64,    65,    -1,    -1,    -1,    69,    70,
      29,    -1,    -1,    -1,    33,    34,    -1,    78,     3,    38,
      -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,
      49,    50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65,    -1,    33,    34,
      -1,    70,    -1,    38,    73,    -1,    -1,    42,    -1,    78,
       3,    -1,    47,    48,    -1,    50,    -1,    52,    53,    -1,
      -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      65,    -1,    -1,    -1,    -1,    70,    29,    72,    -1,    -1,
      33,    34,    -1,    78,    -1,    38,     0,    -1,    41,    42,
      -1,    -1,    -1,    46,    47,    48,    49,    50,    -1,    52,
      53,    -1,    55,    56,    -1,    -1,    59,    60,    61,    62,
      -1,    64,    65,    -1,    -1,    29,    -1,    -1,    71,    33,
      34,    -1,    -1,    -1,    38,    -1,    -1,    41,    42,    -1,
      -1,    -1,    46,    47,    48,    49,    50,    -1,    52,    53,
      -1,    55,    56,    -1,    -1,    59,    60,    61,    62,    29,
      64,    65,    -1,    33,    34,    -1,    -1,    -1,    38,    -1,
      -1,    41,    42,    -1,    -1,    -1,    46,    47,    48,    49,
      50,    -1,    52,    53,    -1,    55,    56,    -1,    -1,    59,
      60,    61,    62,    -1,    64,    65,    -1,    33,    34,    -1,
      70,    71,    38,    73,    -1,    -1,    42,    -1,    78,    -1,
      -1,    47,    48,    -1,    50,    -1,    52,    53,    -1,    -1,
      56,    -1,    -1,    59,    60,    61,    62,    29,    64,    65,
      -1,    33,    34,    -1,    70,    -1,    38,    73,    -1,    41,
      42,    -1,    78,    -1,    46,    47,    48,    49,    50,    -1,
      52,    53,    -1,    55,    56,    -1,    -1,    59,    60,    61,
      62,    29,    64,    65,    -1,    33,    34,    -1,    -1,    71,
      38,    -1,    -1,    41,    42,    -1,    -1,    -1,    46,    47,
      48,    49,    50,    -1,    52,    53,    -1,    55,    56,    -1,
      -1,    59,    60,    61,    62,    -1,    64,    65,    33,    34,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    48,    -1,    50,    -1,    52,    53,    -1,
      -1,    56,    -1,    -1,    59,    60,    61,    62,    -1,    64,
      65,    33,    34,    68,    -1,    -1,    38,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    48,    -1,    50,    -1,
      52,    53,    -1,    -1,    56,    -1,    -1,    59,    60,    61,
      62,    -1,    64,    65,    33,    34,    68,    -1,    -1,    38,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    48,
      -1,    50,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,
      59,    60,    61,    62,    -1,    64,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    29,    33,    34,    38,    41,    42,    46,    47,    48,
      49,    50,    52,    53,    55,    56,    59,    60,    61,    62,
      64,    65,   116,   117,   118,   119,   120,   121,   140,   141,
     150,   151,   152,     3,    69,    70,    78,    92,   117,   118,
     119,   120,   122,   123,   124,   125,   126,     3,    67,     0,
     151,   124,   119,   126,   139,    69,    76,    90,   153,    70,
      73,   125,    67,   119,   120,   130,   131,   133,    71,   119,
     126,   123,   124,     4,     5,     6,     8,     9,    30,    54,
      70,    77,    78,    79,    80,    81,    82,    92,    93,    94,
      95,    96,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   115,    67,   144,    71,
      92,   116,   135,   136,   137,   138,    74,    98,   110,   114,
     162,    68,   131,    72,   119,   120,   124,   132,   134,    70,
      98,    98,    98,    70,    98,   111,   113,   127,   133,    99,
      99,    99,    99,    99,    99,     7,     8,     9,    70,    73,
      75,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    90,   112,    78,    83,    84,    79,    80,    10,    11,
      12,    13,    85,    86,    14,    15,    77,    87,    88,    16,
      17,    89,     3,    31,    32,    35,    36,    37,    43,    44,
      45,    51,    57,    63,    69,   113,   116,   121,   143,   145,
     146,   147,   148,   149,   154,   155,   156,   157,    70,    73,
     124,   126,   128,   129,    71,    76,    71,    76,    74,   130,
     114,    72,    69,    76,   127,    71,    76,    71,    70,   126,
     128,     3,    71,    97,   111,   113,     3,   111,    99,    99,
      99,   100,   100,   101,   101,   102,   102,   102,   102,   103,
     103,   104,   105,   106,   107,   108,   113,    72,    69,   114,
      69,    72,   160,    70,     3,    70,   113,   142,    70,    70,
      69,   155,   144,    68,    71,   128,   136,    74,   114,   129,
      70,    73,    92,   138,    68,   114,   134,    71,   111,    99,
      71,    76,    74,    72,   143,    72,   143,   143,   142,    69,
     113,    69,   113,   113,    71,    71,    74,    71,   136,    74,
     114,   111,   110,   143,    63,    69,    71,    71,    71,    71,
      74,    70,   142,   143,   158,   159,   113,    69,    39,   143,
     143,    71,   142,   143,    69,    71,   161,   143
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,   150,   150,   151,   151,   153,   152,   154,   154,
     155,   155,   156,   143,   143,   143,   143,   143,   143,   144,
     157,   157,   145,   145,   146,   146,   158,   146,   159,   147,
     160,   147,   161,   147,   142,   142,   148,   148,   148,   148,
     149,   149,   149,    92,    93,    94,    94,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   100,   100,   100,   101,
     101,   101,   102,   102,   102,   103,   103,   103,   103,   103,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   121,   121,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   117,   117,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   119,   119,   119,
     118,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   125,   125,   125,   126,   126,   126,   126,   139,   139,
     136,   137,   137,   138,   138,   138,   135,   135,   127,   127,
     128,   128,   128,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   115,   141,   162,   141,   141,   140,   140,   130,
     130,   131,   133,   133,   133,   133,   132,   132,   134,   134,
     134
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

/* User initialization code.  */
#line 23 "parser.y" /* yacc.c:1429  */
{
    st_init();
    ast_init();
}

#line 1608 "parser.tab.c" /* yacc.c:1429  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 5:
#line 210 "parser.y" /* yacc.c:1646  */
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
#line 1829 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 254 "parser.y" /* yacc.c:1646  */
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
        for (int i = 0; fn->next->function.parameters && i < fn->next->function.parameters->node_count; i++)
        {
            // * mark the parameters as used or else they'll get thrown away after the compound statement
            fn->next->function.parameters->nodes[i]->variable.used = 1;
            st_add(NS_VARIABLE, fn->next->function.parameters->nodes[i]);
        }

        (yyval.node) = fn;
    }
#line 1879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 300 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-1].node)->next->function.definition = (yyvsp[0].node);
        // ! debug
        printf("FUNCTION DEFINITION: ");
        ast_print_variable((yyvsp[-1].node), 0);
        ast_print_statement((yyvsp[0].node), 0);
        printf("\n");
    }
#line 1892 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 372 "parser.y" /* yacc.c:1646  */
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
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 410 "parser.y" /* yacc.c:1646  */
    {st_add_statement((yyvsp[0].node));}
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 415 "parser.y" /* yacc.c:1646  */
    {st_push();}
#line 1947 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 415 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1953 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 424 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = st_pop();}
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 433 "parser.y" /* yacc.c:1646  */
    {ast_resolve_expression_variables(&(yyvsp[-1].node)); (yyval.node) = ast_new_expression_statement((yyvsp[-1].node));}
#line 1965 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 434 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_expression_statement(0);}
#line 1971 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 439 "parser.y" /* yacc.c:1646  */
    {
            ast_resolve_expression_variables(&(yyvsp[-2].node));
            (yyval.node) = ast_new_if_statement((yyvsp[-2].node), (yyvsp[0].node), 0);
        }
#line 1980 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 444 "parser.y" /* yacc.c:1646  */
    {
            ast_resolve_expression_variables(&(yyvsp[-4].node));
            (yyval.node) = ast_new_if_statement((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
        }
#line 1989 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 449 "parser.y" /* yacc.c:1646  */
    {
            ast_resolve_expression_variables(&(yyvsp[-1].node));
            ja_push((yyval.node) = ast_new_switch_statement((yyvsp[-1].node), 0));
        }
#line 1998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 454 "parser.y" /* yacc.c:1646  */
    {
            ja_pop();
            (yyvsp[-1].node)->switch_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2008 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 463 "parser.y" /* yacc.c:1646  */
    {
            ast_resolve_expression_variables(&(yyvsp[-1].node));
            ja_push((yyval.node) = ast_new_while_statement(AST_WHILE, (yyvsp[-1].node), 0));
        }
#line 2017 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 468 "parser.y" /* yacc.c:1646  */
    {
            ja_pop();
            (yyvsp[-1].node)->while_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2027 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 474 "parser.y" /* yacc.c:1646  */
    {
            ja_push((yyval.node) = ast_new_while_statement(AST_DO_WHILE, 0, 0));
        }
#line 2035 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 478 "parser.y" /* yacc.c:1646  */
    {
            ast_resolve_expression_variables(&(yyvsp[-2].node));
            ja_pop();
            (yyvsp[-6].node)->while_statement.condition = (yyvsp[-2].node);
            (yyvsp[-6].node)->while_statement.statement = (yyvsp[-5].node);
            (yyval.node) = (yyvsp[-6].node);
        }
#line 2047 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 486 "parser.y" /* yacc.c:1646  */
    {
            if ((yyvsp[-5].node))
                ast_resolve_expression_variables(&(yyvsp[-5].node));
            if ((yyvsp[-3].node))
                ast_resolve_expression_variables(&(yyvsp[-3].node));
            if ((yyvsp[-1].node))
                ast_resolve_expression_variables(&(yyvsp[-1].node));
            ja_push((yyval.node) = ast_new_for_statement((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-1].node), 0));
        }
#line 2061 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 496 "parser.y" /* yacc.c:1646  */
    {
            ja_pop();
            (yyvsp[-1].node)->for_statement.statement = (yyvsp[0].node);
            (yyval.node) = (yyvsp[-1].node);
        }
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 505 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2077 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 506 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = 0;}
#line 2083 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 510 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_goto_statement((yyvsp[-1].string).buffer);}
#line 2089 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 511 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_continue_statement(ja_get_continue_association());}
#line 2095 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 512 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_break_statement(ja_get_break_association());}
#line 2101 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 513 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_return_statement((yyvsp[-1].node));}
#line 2107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 517 "parser.y" /* yacc.c:1646  */
    {st_add_label((yyvsp[-2].string).buffer, (yyvsp[0].node)); (yyval.node) = (yyvsp[0].node);}
#line 2113 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 518 "parser.y" /* yacc.c:1646  */
    {ja_add_switch_case((yyvsp[-2].node), (yyvsp[0].node)); (yyval.node) = (yyvsp[0].node);}
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 519 "parser.y" /* yacc.c:1646  */
    {ja_add_switch_default((yyvsp[0].node)); (yyval.node) = (yyvsp[0].node);}
#line 2125 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 526 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ident((yyvsp[0].string).buffer);}
#line 2131 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 530 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_stringlit((yyvsp[0].string));}
#line 2137 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 534 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_charlit((yyvsp[0].string).buffer[0]); free((yyvsp[0].string).buffer);}
#line 2143 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 535 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_numberlit((yyvsp[0].number));}
#line 2149 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 542 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 2155 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 547 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op('*', ast_new_binary_op('+', (yyvsp[-3].node), (yyvsp[-1].node)));}
#line 2161 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 548 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_function_call((yyvsp[-2].node), ast_list_new());}
#line 2167 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 549 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_function_call((yyvsp[-3].node), (yyvsp[-1].node_list));}
#line 2173 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 550 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_member_access((yyvsp[-2].node), (yyvsp[0].string).buffer);}
#line 2179 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 551 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_member_access(ast_new_unary_op('*', (yyvsp[-2].node)), (yyvsp[0].string).buffer);}
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 552 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op(PLUSPLUS, (yyvsp[-1].node));}
#line 2191 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 553 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op(MINUSMINUS, (yyvsp[-1].node));}
#line 2197 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 557 "parser.y" /* yacc.c:1646  */
    {(yyval.node_list) = ast_list_add(ast_list_new(), (yyvsp[0].node));}
#line 2203 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 558 "parser.y" /* yacc.c:1646  */
    {(yyval.node_list) = ast_list_add((yyvsp[-2].node_list), (yyvsp[0].node));}
#line 2209 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 563 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(PLUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 2215 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 564 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(MINUSEQ, (yyvsp[0].node), ast_new_numberlit((number_t){.integer = 1, .type = (scalar_t){.full = TS_INT}}));}
#line 2221 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 565 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op('&', (yyvsp[0].node));}
#line 2227 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 566 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op('*', (yyvsp[0].node));}
#line 2233 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 567 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op('+', (yyvsp[0].node));}
#line 2239 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 568 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op('-', (yyvsp[0].node));}
#line 2245 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 569 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op('~', (yyvsp[0].node));}
#line 2251 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 570 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op('!', (yyvsp[0].node));}
#line 2257 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 571 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op(SIZEOF, (yyvsp[0].node));}
#line 2263 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 573 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_unary_op(ALIGNOF, (yyvsp[0].node));}
#line 2269 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 578 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_type_cast((yyvsp[0].node), (yyvsp[-2].node));}
#line 2275 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 583 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('*', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2281 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 584 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('/', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2287 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 585 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('%', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2293 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 590 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('+', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2299 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 591 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('-', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2305 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 596 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(SHL, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2311 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 597 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(SHR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2317 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 602 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('<', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2323 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 603 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(LTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2329 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 604 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('>', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2335 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 605 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(GTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2341 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 610 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(EQEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2347 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 611 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(NOTEQ, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2353 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 616 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('&', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2359 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 620 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('^', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2365 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 624 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op('|', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2371 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 629 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(LOGAND, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2377 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 634 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(LOGOR, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2383 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 639 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_ternary_op((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 644 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op((yyvsp[-1].integer), (yyvsp[-2].node), (yyvsp[0].node));}
#line 2395 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 648 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = '=';}
#line 2401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 649 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = PLUSEQ;}
#line 2407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 650 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = MINUSEQ;}
#line 2413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 651 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = TIMESEQ;}
#line 2419 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 652 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = DIVEQ;}
#line 2425 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 653 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = MODEQ;}
#line 2431 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 654 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = SHLEQ;}
#line 2437 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 655 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = SHREQ;}
#line 2443 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 656 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = ANDEQ;}
#line 2449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 657 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = XOREQ;}
#line 2455 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 658 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = OREQ;}
#line 2461 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 663 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_binary_op(',', (yyvsp[-2].node), (yyvsp[0].node));}
#line 2467 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 676 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_normalize_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
        (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
        (yyval.declaration_package) = (yyvsp[-1].declaration_package);
    }
#line 2477 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 687 "parser.y" /* yacc.c:1646  */
    {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 2483 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 688 "parser.y" /* yacc.c:1646  */
    {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 2489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 689 "parser.y" /* yacc.c:1646  */
    {declspec_init(&(yyval.declaration_specifiers)); declspec_add_storage_class(&(yyval.declaration_specifiers), (yyvsp[0].storage_class_specifier));}
#line 2495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 690 "parser.y" /* yacc.c:1646  */
    {declspec_init(&(yyval.declaration_specifiers)); declspec_add_function_specifier(&(yyval.declaration_specifiers), (yyvsp[0].function_specifier));}
#line 2501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 691 "parser.y" /* yacc.c:1646  */
    {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2507 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 692 "parser.y" /* yacc.c:1646  */
    {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2513 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 693 "parser.y" /* yacc.c:1646  */
    {declspec_add_storage_class(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].storage_class_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2519 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 694 "parser.y" /* yacc.c:1646  */
    {declspec_add_function_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].function_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 2525 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 699 "parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier) = SC_EXTERN;}
#line 2531 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 700 "parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier) = SC_STATIC;}
#line 2537 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 701 "parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier) = SC_AUTO;}
#line 2543 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 702 "parser.y" /* yacc.c:1646  */
    {(yyval.storage_class_specifier) = SC_REGISTER;}
#line 2549 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 708 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_VOID};}
#line 2555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 709 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_CHAR};}
#line 2561 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 710 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SHORT};}
#line 2567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 711 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_INT};}
#line 2573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 712 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_LONG};}
#line 2579 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 713 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_FLOAT};}
#line 2585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 714 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_DOUBLE};}
#line 2591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 715 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_SIGNED};}
#line 2597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 716 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_UNSIGNED};}
#line 2603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 717 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_BOOL};}
#line 2609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 718 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_COMPLEX};}
#line 2615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 719 "parser.y" /* yacc.c:1646  */
    {(yyval.type_specifier) = (type_specifier_t){.scalar = TS_STRUCT_OR_UNION, .custom = (yyvsp[0].node)};}
#line 2621 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 726 "parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier) = TQ_CONST;}
#line 2627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 727 "parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier) = TQ_RESTRICT;}
#line 2633 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 728 "parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier) = TQ_VOLATILE;}
#line 2639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 733 "parser.y" /* yacc.c:1646  */
    {(yyval.function_specifier) = FS_INLINE;}
#line 2645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 738 "parser.y" /* yacc.c:1646  */
    {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 2651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 739 "parser.y" /* yacc.c:1646  */
    {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 2657 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 743 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].declarator_helper).initializer = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2663 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 744 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].declarator_helper).initializer = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 2669 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 748 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2675 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 749 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2681 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 753 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = (yyvsp[0].node);}
#line 2687 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 754 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2693 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 755 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 756 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2705 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 757 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 759 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2717 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 760 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 764 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer(0);}
#line 2729 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 765 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_pointer((yyvsp[0].type_qualifier));}
#line 2735 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 766 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer(0); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 767 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[0].declarator_helper).newest->next = ast_new_pointer((yyvsp[-1].type_qualifier)); (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest;}
#line 2747 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 771 "parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier) = (yyvsp[0].type_qualifier);}
#line 2753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 772 "parser.y" /* yacc.c:1646  */
    {(yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier);}
#line 2759 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 777 "parser.y" /* yacc.c:1646  */
    {(yyval.symbol_table) = (yyvsp[0].symbol_table);}
#line 2765 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 782 "parser.y" /* yacc.c:1646  */
    {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2771 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 784 "parser.y" /* yacc.c:1646  */
    {
        if ((yyvsp[0].node)->name && st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, (yyvsp[0].node)->name);
            exit(EXIT_FAILURE);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 796 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-1].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[-1].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable((yyvsp[0].declarator_helper).oldest, (yyvsp[-1].declaration_specifiers).storage_class);
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 803 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[0].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[0].declaration_specifiers).storage_class);
        var->next = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 811 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[-1].declaration_specifiers).storage_class = declspec_normalize_parameter_storage_class((yyvsp[-1].declaration_specifiers).storage_class);

        ast_node_t *var = ast_ident_to_variable(ast_new_ident(0), (yyvsp[-1].declaration_specifiers).storage_class);
        var->next = (yyvsp[0].declarator_helper).oldest;
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = var;
    }
#line 2821 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 822 "parser.y" /* yacc.c:1646  */
    {(yyval.symbol_table) = st_add(st_new(0), (yyvsp[0].node));}
#line 2827 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 824 "parser.y" /* yacc.c:1646  */
    {
        if (st_find_local((yyvsp[-2].symbol_table), (yyvsp[0].node)->name))
        {
            fprintf(stderr, "%s:%d: Error: parameter %s was already declared\n", filename, line_num, (yyvsp[0].node)->name);
            exit(EXIT_FAILURE);
        }
        (yyval.symbol_table) = st_add((yyvsp[-2].symbol_table), (yyvsp[0].node));
    }
#line 2840 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 835 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_type((yyvsp[0].declaration_specifiers).type_specifier, (yyvsp[0].declaration_specifiers).type_qualifier);}
#line 2846 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 837 "parser.y" /* yacc.c:1646  */
    {
        (yyvsp[0].declarator_helper).newest->next = ast_new_type((yyvsp[-1].declaration_specifiers).type_specifier, (yyvsp[-1].declaration_specifiers).type_qualifier);
        (yyval.node) = (yyvsp[0].declarator_helper).oldest;
    }
#line 2855 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 844 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2861 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 845 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 2867 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 846 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].declarator_helper).newest->next = (yyvsp[-1].declarator_helper).oldest; (yyval.declarator_helper).oldest = (yyvsp[0].declarator_helper).oldest; (yyval.declarator_helper).newest = (yyvsp[-1].declarator_helper).newest;}
#line 2873 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 850 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper) = (yyvsp[-1].declarator_helper);}
#line 2879 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 851 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array(0);}
#line 2885 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 852 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_array((yyvsp[-1].node));}
#line 2891 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 853 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_array(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2897 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 854 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_array((yyvsp[-1].node)); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2903 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 855 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(0);}
#line 2909 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 856 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-2].declarator_helper).newest->next = ast_new_function(0); (yyval.declarator_helper).oldest = (yyvsp[-2].declarator_helper).oldest;}
#line 2915 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 857 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).oldest = (yyval.declarator_helper).newest = ast_new_function(st_unpack((yyvsp[-1].symbol_table)));}
#line 2921 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 858 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper).newest = (yyvsp[-3].declarator_helper).newest->next = ast_new_function(st_unpack((yyvsp[-1].symbol_table))); (yyval.declarator_helper).oldest = (yyvsp[-3].declarator_helper).oldest;}
#line 2927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 871 "parser.y" /* yacc.c:1646  */
    {(yyval.node) = ast_new_struct_or_union((yyvsp[-3].integer), 0, st_unpack((yyvsp[-1].symbol_table)));}
#line 2933 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 873 "parser.y" /* yacc.c:1646  */
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
#line 2966 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 902 "parser.y" /* yacc.c:1646  */
    {
                (yyval.node) = ast_add_struct_or_union_members((yyvsp[-2].node), st_unpack((yyvsp[-1].symbol_table)));
                ast_print_struct_or_union((yyval.node)); // ! debug
            }
#line 2975 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 907 "parser.y" /* yacc.c:1646  */
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
#line 2992 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 922 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = AST_STRUCT;}
#line 2998 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 923 "parser.y" /* yacc.c:1646  */
    {(yyval.integer) = AST_UNION;}
#line 3004 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 927 "parser.y" /* yacc.c:1646  */
    {(yyval.symbol_table) = add_members_to_symbol_table(st_new(0), (yyvsp[0].declaration_package));}
#line 3010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 928 "parser.y" /* yacc.c:1646  */
    {(yyval.symbol_table) = add_members_to_symbol_table((yyvsp[-1].symbol_table), (yyvsp[0].declaration_package));}
#line 3016 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 933 "parser.y" /* yacc.c:1646  */
    {
            (yyvsp[-2].declaration_specifiers).type_specifier.scalar = declspec_normalize_scalar((yyvsp[-2].declaration_specifiers).type_specifier.scalar);
            (yyvsp[-1].declaration_package).declaration_specifiers = (yyvsp[-2].declaration_specifiers);
            (yyval.declaration_package) = (yyvsp[-1].declaration_package);
        }
#line 3026 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 941 "parser.y" /* yacc.c:1646  */
    {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_specifier(&(yyval.declaration_specifiers), (yyvsp[0].type_specifier));}
#line 3032 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 942 "parser.y" /* yacc.c:1646  */
    {declspec_init(&(yyval.declaration_specifiers)); declspec_add_type_qualifier(&(yyval.declaration_specifiers), (yyvsp[0].type_qualifier));}
#line 3038 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 943 "parser.y" /* yacc.c:1646  */
    {declspec_add_type_specifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_specifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 3044 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 944 "parser.y" /* yacc.c:1646  */
    {declspec_add_type_qualifier(&(yyvsp[-1].declaration_specifiers), (yyvsp[0].type_qualifier)); (yyval.declaration_specifiers) = (yyvsp[-1].declaration_specifiers);}
#line 3050 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 948 "parser.y" /* yacc.c:1646  */
    {declpkg_init(&(yyval.declaration_package)); declpkg_add_declarator(&(yyval.declaration_package), (yyvsp[0].declarator_helper));}
#line 3056 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 949 "parser.y" /* yacc.c:1646  */
    {declpkg_add_declarator(&(yyvsp[-2].declaration_package), (yyvsp[0].declarator_helper)); (yyval.declaration_package) = (yyvsp[-2].declaration_package);}
#line 3062 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 953 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].declarator_helper).bit_width = 0; (yyval.declarator_helper) = (yyvsp[0].declarator_helper);}
#line 3068 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 954 "parser.y" /* yacc.c:1646  */
    {(yyval.declarator_helper) = (declarator_helper_t){.oldest = 0, .newest = 0, .bit_width = (yyvsp[0].node)};}
#line 3074 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 955 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].declarator_helper).bit_width = (yyvsp[0].node); (yyval.declarator_helper) = (yyvsp[-2].declarator_helper);}
#line 3080 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 3084 "parser.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 980 "parser.y" /* yacc.c:1906  */


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
