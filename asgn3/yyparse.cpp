/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 7 "parser.y"

// prologue
#include <cassert>
#include "lyutils.h"
#include "astree.h"
#include "stdio.h"

/* Line 371 of yacc.c  */
#line 76 "yyparse.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "yyparse.h".  */
#ifndef YY_YY_YYPARSE_H_INCLUDED
# define YY_YY_YYPARSE_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_VOID = 258,
     TOK_CHAR = 259,
     TOK_INT = 260,
     TOK_STRING = 261,
     TOK_IF = 262,
     TOK_ELSE = 263,
     TOK_WHILE = 264,
     TOK_RETURN = 265,
     TOK_STRUCT = 266,
     TOK_NULL = 267,
     TOK_NEW = 268,
     TOK_ARRAY = 269,
     TOK_EQ = 270,
     TOK_NE = 271,
     TOK_LT = 272,
     TOK_LE = 273,
     TOK_GT = 274,
     TOK_GE = 275,
     TOK_IDENT = 276,
     TOK_INTCON = 277,
     TOK_CHARCON = 278,
     TOK_STRINGCON = 279,
     TOK_BLOCK = 280,
     TOK_CALL = 281,
     TOK_IFELSE = 282,
     TOK_INITDECL = 283,
     TOK_POS = 284,
     TOK_NEG = 285,
     TOK_NEWARRAY = 286,
     TOK_TYPEID = 287,
     TOK_FIELD = 288,
     TOK_ORD = 289,
     TOK_CHR = 290,
     TOK_ROOT = 291,
     TOK_VARDECL = 292,
     TOK_IDENTDECL = 293,
     TOK_BOOL = 294,
     TOK_DECLID = 295,
     TOK_FALSE = 296,
     TOK_TRUE = 297,
     TOK_NEWSTRING = 298,
     TOK_RETURNVOID = 299,
     TOK_INDEX = 300,
     TOK_PROTOTYPE = 301,
     TOK_FUNCTION = 302,
     TOK_PARAMLIST = 303
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_YYPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 190 "yyparse.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   554

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    55,     2,     2,     2,    54,     2,     2,
      58,    60,    52,    50,    63,    51,    57,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    61,
       2,    49,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    62,     2,    59,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    26,
      27,    30,    34,    38,    42,    45,    47,    49,    51,    53,
      55,    57,    62,    67,    71,    74,    76,    79,    83,    86,
      89,    91,    93,    95,    97,    99,   101,   103,   106,   111,
     117,   123,   131,   134,   138,   142,   146,   150,   154,   158,
     162,   166,   170,   174,   178,   182,   186,   189,   192,   195,
     198,   201,   203,   205,   209,   211,   213,   218,   224,   230,
     233,   237,   241,   245,   247,   252,   256,   258,   260,   262,
     264,   266
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      66,     0,    -1,    67,    -1,    67,    68,    -1,    67,    72,
      -1,    67,    77,    -1,    67,     1,    59,    -1,    67,     1,
      60,    -1,    67,     1,    61,    -1,    -1,    69,    59,    -1,
      69,    70,    61,    -1,    11,    21,    62,    -1,    71,    14,
      21,    -1,    71,    21,    -1,     3,    -1,    39,    -1,     4,
      -1,     5,    -1,     6,    -1,    21,    -1,    74,    73,    60,
      75,    -1,    74,    73,    60,    61,    -1,    73,    63,    74,
      -1,    58,    74,    -1,    58,    -1,    71,    21,    -1,    71,
      14,    21,    -1,    76,    59,    -1,    76,    77,    -1,    62,
      -1,    75,    -1,    61,    -1,    78,    -1,    79,    -1,    80,
      -1,    81,    -1,    82,    61,    -1,    74,    49,    82,    61,
      -1,     9,    58,    82,    60,    77,    -1,     7,    58,    82,
      60,    77,    -1,     7,    58,    82,    60,    77,     8,    77,
      -1,    10,    61,    -1,    10,    82,    61,    -1,    82,    49,
      82,    -1,    82,    15,    82,    -1,    82,    16,    82,    -1,
      82,    17,    82,    -1,    82,    18,    82,    -1,    82,    19,
      82,    -1,    82,    20,    82,    -1,    82,    50,    82,    -1,
      82,    51,    82,    -1,    82,    52,    82,    -1,    82,    53,
      82,    -1,    82,    54,    82,    -1,    50,    82,    -1,    51,
      82,    -1,    55,    82,    -1,    34,    82,    -1,    35,    82,
      -1,    83,    -1,    84,    -1,    58,    82,    60,    -1,    86,
      -1,    87,    -1,    13,    21,    58,    60,    -1,    13,     6,
      58,    82,    60,    -1,    13,    71,    56,    82,    64,    -1,
      85,    60,    -1,    21,    58,    60,    -1,    85,    63,    82,
      -1,    21,    58,    82,    -1,    21,    -1,    82,    56,    82,
      64,    -1,    82,    57,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,    41,    -1,    42,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    58,    58,    62,    63,    64,    65,    66,    67,    68,
      71,    75,    78,    83,    85,    89,    90,    91,    92,    93,
      94,    99,   102,   107,   110,   113,   118,   120,   124,   128,
     129,   133,   134,   135,   136,   137,   138,   139,   142,   148,
     153,   156,   163,   165,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   183,   185,   186,
     187,   188,   189,   190,   191,   192,   195,   198,   201,   207,
     208,   213,   215,   219,   220,   224,   229,   230,   231,   232,
     233,   234
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_VOID", "TOK_CHAR", "TOK_INT",
  "TOK_STRING", "TOK_IF", "TOK_ELSE", "TOK_WHILE", "TOK_RETURN",
  "TOK_STRUCT", "TOK_NULL", "TOK_NEW", "TOK_ARRAY", "TOK_EQ", "TOK_NE",
  "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE", "TOK_IDENT", "TOK_INTCON",
  "TOK_CHARCON", "TOK_STRINGCON", "TOK_BLOCK", "TOK_CALL", "TOK_IFELSE",
  "TOK_INITDECL", "TOK_POS", "TOK_NEG", "TOK_NEWARRAY", "TOK_TYPEID",
  "TOK_FIELD", "TOK_ORD", "TOK_CHR", "TOK_ROOT", "TOK_VARDECL",
  "TOK_IDENTDECL", "TOK_BOOL", "TOK_DECLID", "TOK_FALSE", "TOK_TRUE",
  "TOK_NEWSTRING", "TOK_RETURNVOID", "TOK_INDEX", "TOK_PROTOTYPE",
  "TOK_FUNCTION", "TOK_PARAMLIST", "'='", "'+'", "'-'", "'*'", "'/'",
  "'%'", "'!'", "'['", "'.'", "'('", "'}'", "')'", "';'", "'{'", "','",
  "']'", "$accept", "start", "program", "structdef", "strfield",
  "fielddecl", "basetype", "function", "funcargs", "identdecl", "block",
  "blockstmnts", "statement", "vardecl", "while", "ifelse", "return",
  "expr", "allocator", "call", "callargs", "variable", "constant", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,    61,
      43,    45,    42,    47,    37,    33,    91,    46,    40,   125,
      41,    59,   123,    44,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    67,    67,    67,    67,    67,    67,
      68,    69,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    72,    72,    73,    73,    73,    74,    74,    75,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    78,    79,
      80,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    87,    87,    87,    87,
      87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     3,     0,
       2,     3,     3,     3,     2,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     2,     1,     2,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     2,     4,     5,
       5,     7,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     1,     1,     3,     1,     1,     4,     5,     5,     2,
       3,     3,     3,     1,     4,     3,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,     0,     0,     1,     0,    15,    17,    18,    19,     0,
       0,     0,     0,    81,     0,    73,    76,    77,    78,     0,
       0,    16,    79,    80,     0,     0,     0,     0,    32,    30,
       3,     0,     0,     4,     0,    31,     0,     5,    33,    34,
      35,    36,     0,    61,    62,     0,    64,    65,     6,     7,
       8,     0,     0,    73,    42,     0,     0,    19,    20,     0,
       0,    59,    60,    56,    57,    58,     0,    20,    10,     0,
       0,     0,    26,     0,    25,     0,    28,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    69,     0,     0,     0,    43,    12,
       0,     0,     0,    70,    72,    63,    11,     0,    14,    27,
       0,    24,     0,     0,    45,    46,    47,    48,    49,    50,
      44,    51,    52,    53,    54,    55,     0,    75,    71,     0,
       0,     0,    66,     0,    13,    38,    22,    21,    23,    74,
      40,    39,    67,    68,     0,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    30,    31,    69,    32,    33,    75,    77,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
     -58,    14,   112,   -58,   -18,   -58,   -58,   -58,   -58,   -31,
       1,   257,    41,   -58,    49,    -9,   -58,   -58,   -58,    16,
      16,   -58,   -58,   -58,    16,    16,    16,    16,   -58,   -58,
     -58,     5,     3,   -58,   -45,   -58,   172,   -58,   -58,   -58,
     -58,   -58,   337,   -58,   -58,   -57,   -58,   -58,   -58,   -58,
     -58,    16,    16,     7,   -58,   355,     6,    15,    31,    34,
     309,   497,   497,   -11,   -11,   -11,   415,   -58,   -58,     2,
       4,    71,   -58,    16,   256,   -27,   -58,    44,   -58,    16,
      16,    16,    16,    16,    16,    16,    16,    16,    16,    16,
      16,    16,    76,   -58,   -58,    16,   427,   473,   -58,   -58,
      16,    39,    16,   -58,   497,   -58,   -58,    79,   -58,   -58,
     402,   -58,    -1,   256,   147,   147,   147,   147,   147,   147,
     497,   -22,   -22,   -11,   -11,   -11,    88,   -58,   497,   232,
     232,   485,   -58,   285,   -58,   -58,   -58,   -58,   -58,   -58,
      93,   -58,   -58,   -58,   232,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -58,   -58,   -58,   -12,   -58,   -58,    -2,
     -10,   -58,   -35,   -58,   -58,   -58,   -58,    -4,   -58,   -58,
     -58,   -58,   -58
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -21
static const yytype_int16 yytable[] =
{
      34,    78,    59,    94,    73,   -20,    95,    55,     5,     6,
       7,     8,   -20,    74,     3,    61,    62,    71,   107,    70,
      63,    64,    65,    66,    72,   108,    67,    51,    13,    14,
      88,    89,    90,   112,    91,    92,   113,    53,    16,    17,
      18,    48,    49,    50,    21,    91,    92,    96,    97,    60,
      19,    20,     5,     6,     7,    57,   104,    22,    23,    52,
     136,    29,    56,   106,    68,    60,    24,    25,    99,   110,
      58,    26,   111,   100,    27,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    21,   101,
     102,   128,   109,    73,   140,   141,   131,   127,   133,   132,
     134,   144,   137,    79,    80,    81,    82,    83,    84,   145,
       0,   138,    -2,     4,     0,     5,     6,     7,     8,     9,
       0,    10,    11,    12,    13,    14,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    19,    20,     0,     0,
       0,    21,   139,    22,    23,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,    26,     0,     0,
      27,     0,     0,    28,    29,     5,     6,     7,     8,     9,
       0,    10,    11,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,    86,    87,    88,
      89,    90,     0,    91,    92,     0,    19,    20,     0,     0,
       0,    21,     0,    22,    23,     0,     0,     0,     0,     0,
       0,     0,    24,    25,     0,     0,     0,    26,     0,     0,
      27,    76,     0,    28,    29,     5,     6,     7,     8,     9,
       0,    10,    11,     0,    13,    14,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,     0,     0,     5,
       6,     7,     8,     0,     0,     0,    19,    20,     0,    13,
      14,    21,     0,    22,    23,     0,     0,    67,    53,    16,
      17,    18,    24,    25,     0,     0,     0,    26,     0,     0,
      27,    19,    20,    28,    29,    21,     0,     0,    22,    23,
      79,    80,    81,    82,    83,    84,     0,    24,    25,     0,
       0,     0,    26,     0,     0,    27,     0,     0,    54,     0,
       0,    13,    14,     0,     0,     0,     0,     0,     0,     0,
      53,    16,    17,    18,    85,    86,    87,    88,    89,    90,
       0,    91,    92,    19,    20,     0,     0,     0,     0,   143,
      22,    23,    79,    80,    81,    82,    83,    84,     0,    24,
      25,     0,     0,     0,    26,     0,     0,    27,     0,   103,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,     0,    91,    92,     0,     0,     0,    93,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,     0,    98,    79,    80,    81,
      82,    83,    84,     0,     0,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,     0,     0,
       0,    85,    86,    87,    88,    89,    90,     0,    91,    92,
       0,     0,     0,   135,    85,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,   105,    85,    86,    87,    88,
      89,    90,     0,    91,    92,     0,     0,   129,    79,    80,
      81,    82,    83,    84,     0,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,     0,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,     0,    91,
      92,     0,     0,   130,    85,    86,    87,    88,    89,    90,
       0,    91,    92,     0,     0,   142,    85,    86,    87,    88,
      89,    90,     0,    91,    92
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-58)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       2,    36,    14,    60,    49,    14,    63,    11,     3,     4,
       5,     6,    21,    58,     0,    19,    20,    14,    14,    31,
      24,    25,    26,    27,    21,    21,    21,    58,    12,    13,
      52,    53,    54,    60,    56,    57,    63,    21,    22,    23,
      24,    59,    60,    61,    39,    56,    57,    51,    52,    58,
      34,    35,     3,     4,     5,     6,    60,    41,    42,    58,
      61,    62,    21,    61,    59,    58,    50,    51,    62,    73,
      21,    55,    74,    58,    58,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    39,    58,
      56,    95,    21,    49,   129,   130,   100,    21,   102,    60,
      21,     8,   112,    15,    16,    17,    18,    19,    20,   144,
      -1,   113,     0,     1,    -1,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    49,    50,    51,
      52,    53,    54,    -1,    56,    57,    34,    35,    -1,    -1,
      -1,    39,    64,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,
      58,    -1,    -1,    61,    62,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    34,    35,    -1,    -1,
      -1,    39,    -1,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,
      58,    59,    -1,    61,    62,     3,     4,     5,     6,     7,
      -1,     9,    10,    -1,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,     3,
       4,     5,     6,    -1,    -1,    -1,    34,    35,    -1,    12,
      13,    39,    -1,    41,    42,    -1,    -1,    21,    21,    22,
      23,    24,    50,    51,    -1,    -1,    -1,    55,    -1,    -1,
      58,    34,    35,    61,    62,    39,    -1,    -1,    41,    42,
      15,    16,    17,    18,    19,    20,    -1,    50,    51,    -1,
      -1,    -1,    55,    -1,    -1,    58,    -1,    -1,    61,    -1,
      -1,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    34,    35,    -1,    -1,    -1,    -1,    64,
      41,    42,    15,    16,    17,    18,    19,    20,    -1,    50,
      51,    -1,    -1,    -1,    55,    -1,    -1,    58,    -1,    60,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    -1,    -1,    61,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    -1,    56,    57,
      -1,    -1,    -1,    61,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    -1,    60,    49,    50,    51,    52,
      53,    54,    -1,    56,    57,    -1,    -1,    60,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    -1,    56,
      57,    -1,    -1,    60,    49,    50,    51,    52,    53,    54,
      -1,    56,    57,    -1,    -1,    60,    49,    50,    51,    52,
      53,    54,    -1,    56,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    66,    67,     0,     1,     3,     4,     5,     6,     7,
       9,    10,    11,    12,    13,    21,    22,    23,    24,    34,
      35,    39,    41,    42,    50,    51,    55,    58,    61,    62,
      68,    69,    71,    72,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    59,    60,
      61,    58,    58,    21,    61,    82,    21,     6,    21,    71,
      58,    82,    82,    82,    82,    82,    82,    21,    59,    70,
      71,    14,    21,    49,    58,    73,    59,    74,    77,    15,
      16,    17,    18,    19,    20,    49,    50,    51,    52,    53,
      54,    56,    57,    61,    60,    63,    82,    82,    61,    62,
      58,    58,    56,    60,    82,    60,    61,    14,    21,    21,
      82,    74,    60,    63,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    21,    82,    60,
      60,    82,    60,    82,    21,    61,    61,    75,    74,    64,
      77,    77,    60,    64,     8,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      case 3: /* TOK_VOID */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 926 "yyparse.cpp"
        break;
      case 4: /* TOK_CHAR */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 933 "yyparse.cpp"
        break;
      case 5: /* TOK_INT */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 940 "yyparse.cpp"
        break;
      case 6: /* TOK_STRING */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 947 "yyparse.cpp"
        break;
      case 7: /* TOK_IF */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 954 "yyparse.cpp"
        break;
      case 8: /* TOK_ELSE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 961 "yyparse.cpp"
        break;
      case 9: /* TOK_WHILE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 968 "yyparse.cpp"
        break;
      case 10: /* TOK_RETURN */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 975 "yyparse.cpp"
        break;
      case 11: /* TOK_STRUCT */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 982 "yyparse.cpp"
        break;
      case 12: /* TOK_NULL */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 989 "yyparse.cpp"
        break;
      case 13: /* TOK_NEW */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 996 "yyparse.cpp"
        break;
      case 14: /* TOK_ARRAY */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1003 "yyparse.cpp"
        break;
      case 15: /* TOK_EQ */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1010 "yyparse.cpp"
        break;
      case 16: /* TOK_NE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1017 "yyparse.cpp"
        break;
      case 17: /* TOK_LT */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1024 "yyparse.cpp"
        break;
      case 18: /* TOK_LE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1031 "yyparse.cpp"
        break;
      case 19: /* TOK_GT */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1038 "yyparse.cpp"
        break;
      case 20: /* TOK_GE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1045 "yyparse.cpp"
        break;
      case 21: /* TOK_IDENT */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1052 "yyparse.cpp"
        break;
      case 22: /* TOK_INTCON */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1059 "yyparse.cpp"
        break;
      case 23: /* TOK_CHARCON */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1066 "yyparse.cpp"
        break;
      case 24: /* TOK_STRINGCON */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1073 "yyparse.cpp"
        break;
      case 25: /* TOK_BLOCK */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1080 "yyparse.cpp"
        break;
      case 26: /* TOK_CALL */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1087 "yyparse.cpp"
        break;
      case 27: /* TOK_IFELSE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1094 "yyparse.cpp"
        break;
      case 28: /* TOK_INITDECL */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1101 "yyparse.cpp"
        break;
      case 29: /* TOK_POS */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1108 "yyparse.cpp"
        break;
      case 30: /* TOK_NEG */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1115 "yyparse.cpp"
        break;
      case 31: /* TOK_NEWARRAY */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1122 "yyparse.cpp"
        break;
      case 32: /* TOK_TYPEID */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1129 "yyparse.cpp"
        break;
      case 33: /* TOK_FIELD */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1136 "yyparse.cpp"
        break;
      case 34: /* TOK_ORD */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1143 "yyparse.cpp"
        break;
      case 35: /* TOK_CHR */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1150 "yyparse.cpp"
        break;
      case 36: /* TOK_ROOT */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1157 "yyparse.cpp"
        break;
      case 37: /* TOK_VARDECL */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1164 "yyparse.cpp"
        break;
      case 38: /* TOK_IDENTDECL */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1171 "yyparse.cpp"
        break;
      case 39: /* TOK_BOOL */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1178 "yyparse.cpp"
        break;
      case 40: /* TOK_DECLID */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1185 "yyparse.cpp"
        break;
      case 41: /* TOK_FALSE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1192 "yyparse.cpp"
        break;
      case 42: /* TOK_TRUE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1199 "yyparse.cpp"
        break;
      case 43: /* TOK_NEWSTRING */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1206 "yyparse.cpp"
        break;
      case 44: /* TOK_RETURNVOID */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1213 "yyparse.cpp"
        break;
      case 45: /* TOK_INDEX */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1220 "yyparse.cpp"
        break;
      case 46: /* TOK_PROTOTYPE */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1227 "yyparse.cpp"
        break;
      case 47: /* TOK_FUNCTION */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1234 "yyparse.cpp"
        break;
      case 48: /* TOK_PARAMLIST */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1241 "yyparse.cpp"
        break;
      case 49: /* '=' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1248 "yyparse.cpp"
        break;
      case 50: /* '+' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1255 "yyparse.cpp"
        break;
      case 51: /* '-' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1262 "yyparse.cpp"
        break;
      case 52: /* '*' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1269 "yyparse.cpp"
        break;
      case 53: /* '/' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1276 "yyparse.cpp"
        break;
      case 54: /* '%' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1283 "yyparse.cpp"
        break;
      case 55: /* '!' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1290 "yyparse.cpp"
        break;
      case 56: /* '[' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1297 "yyparse.cpp"
        break;
      case 57: /* '.' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1304 "yyparse.cpp"
        break;
      case 58: /* '(' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1311 "yyparse.cpp"
        break;
      case 59: /* '}' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1318 "yyparse.cpp"
        break;
      case 60: /* ')' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1325 "yyparse.cpp"
        break;
      case 61: /* ';' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1332 "yyparse.cpp"
        break;
      case 62: /* '{' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1339 "yyparse.cpp"
        break;
      case 63: /* ',' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1346 "yyparse.cpp"
        break;
      case 64: /* ']' */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1353 "yyparse.cpp"
        break;
      case 66: /* start */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1360 "yyparse.cpp"
        break;
      case 67: /* program */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1367 "yyparse.cpp"
        break;
      case 68: /* structdef */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1374 "yyparse.cpp"
        break;
      case 69: /* strfield */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1381 "yyparse.cpp"
        break;
      case 70: /* fielddecl */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1388 "yyparse.cpp"
        break;
      case 71: /* basetype */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1395 "yyparse.cpp"
        break;
      case 72: /* function */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1402 "yyparse.cpp"
        break;
      case 73: /* funcargs */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1409 "yyparse.cpp"
        break;
      case 74: /* identdecl */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1416 "yyparse.cpp"
        break;
      case 75: /* block */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1423 "yyparse.cpp"
        break;
      case 76: /* blockstmnts */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1430 "yyparse.cpp"
        break;
      case 77: /* statement */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1437 "yyparse.cpp"
        break;
      case 78: /* vardecl */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1444 "yyparse.cpp"
        break;
      case 79: /* while */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1451 "yyparse.cpp"
        break;
      case 80: /* ifelse */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1458 "yyparse.cpp"
        break;
      case 81: /* return */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1465 "yyparse.cpp"
        break;
      case 82: /* expr */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1472 "yyparse.cpp"
        break;
      case 83: /* allocator */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1479 "yyparse.cpp"
        break;
      case 84: /* call */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1486 "yyparse.cpp"
        break;
      case 85: /* callargs */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1493 "yyparse.cpp"
        break;
      case 86: /* variable */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1500 "yyparse.cpp"
        break;
      case 87: /* constant */
/* Line 823 of yacc.c  */
#line 40 "parser.y"
        { astree::dump (yyoutput, (*yyvaluep)); };
/* Line 823 of yacc.c  */
#line 1507 "yyparse.cpp"
        break;
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
/* Line 1575 of yacc.c  */
#line 37 "parser.y"
{
  parser::root = new astree (TOK_ROOT, {0,0,0}, "<<ROOT>>");
}
/* Line 1575 of yacc.c  */
#line 2019 "yyparse.cpp"
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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1792 of yacc.c  */
#line 58 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]) = nullptr;}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 62 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 63 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 64 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 65 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 66 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    { (yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 68 "parser.y"
    {(yyval) = parser::root ;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 72 "parser.y"
    {destroy((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]); }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 76 "parser.y"
    { destroy((yyvsp[(3) - (3)])); 
            (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)])); }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    { destroy((yyvsp[(3) - (3)])); 
            (yyval)=(yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));changeSym(TOK_TYPEID,(yyvsp[(2) - (3)]));}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 84 "parser.y"
    { (yyval)=(yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)])); changeSym(TOK_FIELD,(yyvsp[(3) - (3)]));}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 86 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); changeSym(TOK_FIELD,(yyvsp[(2) - (2)])) ;}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 90 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 91 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 92 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 95 "parser.y"
    { changeSym(TOK_TYPEID, (yyvsp[(1) - (1)])); 
            (yyval)=(yyvsp[(1) - (1)]); }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    { destroy((yyvsp[(3) - (4)])); 
            (yyval)=create_astree_one(TOK_FUNCTION, (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]), (yyvsp[(4) - (4)])); }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 103 "parser.y"
    { destroy((yyvsp[(3) - (4)]));destroy((yyvsp[(4) - (4)])); 
            (yyval)=create_astree(TOK_PROTOTYPE, (yyvsp[(1) - (4)]), (yyvsp[(2) - (4)])); }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 108 "parser.y"
    { destroy((yyvsp[(2) - (3)])); 
            (yyval)=(yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)])); }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 111 "parser.y"
    { changeSym(TOK_PARAMLIST, (yyvsp[(1) - (2)])); 
            (yyval)=(yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    { changeSym(TOK_PARAMLIST, (yyvsp[(1) - (1)])); 
            (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 119 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)])/*->adopt($2); changeSym(TOK_DECLID,$1);*/ ;}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 121 "parser.y"
    { (yyval)=(yyvsp[(2) - (3)])->adopt((yyvsp[(3) - (3)]),(yyvsp[(1) - (3)])); changeSym( TOK_DECLID, (yyvsp[(3) - (3)]));}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 125 "parser.y"
    { destroy((yyvsp[(2) - (2)])); (yyval)=(yyvsp[(1) - (2)]);}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)])->adopt( (yyvsp[(2) - (2)]));}
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 129 "parser.y"
    { changeSym(TOK_BLOCK,(yyvsp[(1) - (1)])); 
                                        (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 134 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 136 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 137 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 138 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    { (yyval)=(yyvsp[(1) - (2)]); destroy((yyvsp[(2) - (2)]));}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 143 "parser.y"
    { destroy((yyvsp[(4) - (4)])); 
            changeSym(TOK_VARDECL, (yyvsp[(2) - (4)]));
            (yyval)=(yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)]));}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 149 "parser.y"
    { destroy((yyvsp[(2) - (5)])); destroy((yyvsp[(4) - (5)])); 
            (yyval)=(yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 154 "parser.y"
    { destroy((yyvsp[(2) - (5)])); destroy((yyvsp[(4) - (5)])); 
            (yyval)=(yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]),(yyvsp[(5) - (5)]));}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    { destroy((yyvsp[(2) - (7)]));destroy((yyvsp[(4) - (7)])); 
            free((yyvsp[(6) - (7)])); 
            (yyval)=(yyvsp[(1) - (7)])->adopt((yyvsp[(3) - (7)]),(yyvsp[(5) - (7)]));
            (yyval)=(yyvsp[(1) - (7)])->adopt((yyvsp[(7) - (7)])); changeSym(TOK_IFELSE,(yyvsp[(7) - (7)]));}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    { destroy((yyvsp[(2) - (2)])); changeSym(TOK_RETURNVOID, (yyvsp[(1) - (2)])); (yyval)=(yyvsp[(1) - (2)]);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 166 "parser.y"
    { destroy((yyvsp[(3) - (3)])); (yyval)=(yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    { (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 181 "parser.y"
    { changeSym(TOK_POS, (yyvsp[(1) - (2)]));
                                      (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    { changeSym(TOK_NEG, (yyvsp[(1) - (2)]));
                                      (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    { (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 188 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 189 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    { destroy((yyvsp[(1) - (3)]));destroy((yyvsp[(3) - (3)]));(yyval)=(yyvsp[(2) - (3)]);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 191 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 192 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    { destroy((yyvsp[(3) - (4)])); destroy((yyvsp[(4) - (4)])); 
            (yyval)=(yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)]));changeSym(TOK_TYPEID,(yyvsp[(2) - (4)]));}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 199 "parser.y"
    { destroy((yyvsp[(3) - (5)])); destroy((yyvsp[(5) - (5)])); changeSym( TOK_NEWSTRING,(yyvsp[(2) - (5)]));
              (yyval) = (yyvsp[(2) - (5)])->adopt((yyvsp[(4) - (5)]));}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 202 "parser.y"
    { destroy((yyvsp[(3) - (5)]));destroy((yyvsp[(5) - (5)])); 
            changeSym( TOK_NEWARRAY, (yyvsp[(1) - (5)]));
            (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(2) - (5)]),(yyvsp[(4) - (5)])); changeSym(TOK_TYPEID,(yyvsp[(2) - (5)]));}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    { destroy((yyvsp[(2) - (2)])); (yyval)=(yyvsp[(1) - (2)]);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    { destroy((yyvsp[(3) - (3)])); 
                                       changeSym( TOK_CALL,(yyvsp[(2) - (3)]));
                                       (yyval)=(yyvsp[(2) - (3)])->adopt( (yyvsp[(1) - (3)]));}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    { destroy((yyvsp[(2) - (3)])); 
                                       (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)]));}
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    { (yyvsp[(2) - (3)])->adopt_sym(TOK_CALL); 
                                       (yyval)=(yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));}
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 219 "parser.y"
    { (yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    { destroy((yyvsp[(4) - (4)])); 
            changeSym(TOK_INDEX,(yyvsp[(2) - (4)])); 
            (yyval)=(yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    { destroy((yyvsp[(2) - (3)])); 
            (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)])); changeSym(TOK_FIELD,(yyvsp[(3) - (3)]));}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 230 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 231 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 232 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 233 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 234 "parser.y"
    { (yyval)=(yyvsp[(1) - (1)]);}
    break;


/* Line 1792 of yacc.c  */
#line 2709 "yyparse.cpp"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 238 "parser.y"


//Epilogue

const char *parser::get_tname (int symbol) {
   return yytname [YYTRANSLATE (symbol)];
}
bool is_defined_token (int symbol) {
   return YYTRANSLATE (symbol) > YYUNDEFTOK;
}
/*
static void* yycalloc (size_t size) {
   void* result = calloc (1, size);
   assert (result != nullptr);
   return result;
}
*/
