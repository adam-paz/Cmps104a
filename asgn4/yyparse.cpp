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

#include <cassert>

#include "lyutils.h"
#include "astree.h"


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
     ROOT = 292,
     IDENT = 293,
     TOK_FUNCTION = 294,
     TOK_PARAMLIST = 295,
     TOK_PROTOTYPE = 296,
     TOK_NEWSTRING = 297,
     TOK_INDEX = 298,
     TOK_DECLID = 299,
     TOK_RETURNVOID = 300,
     TOK_VARDECLAR = 301
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
#line 188 "yyparse.cpp"

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
#define YYLAST   538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  79
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,     2,     2,    52,     2,     2,
      59,    61,    50,    48,    60,    49,    55,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,    56,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    11,    14,    18,    22,    23,
      28,    33,    37,    41,    44,    48,    50,    52,    54,    56,
      58,    61,    65,    70,    75,    80,    85,    88,    92,    95,
      98,   101,   104,   106,   108,   110,   112,   114,   117,   119,
     124,   130,   138,   144,   147,   151,   153,   155,   157,   159,
     163,   165,   167,   171,   175,   179,   183,   187,   191,   195,
     199,   203,   207,   211,   214,   217,   220,   225,   231,   237,
     241,   245,   248,   252,   254,   259,   263,   265,   267,   269
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    -1,    65,    66,    -1,    65,    71,
      -1,    65,    75,    -1,    65,     1,    56,    -1,    65,     1,
      57,    -1,    -1,    11,    21,    67,    56,    -1,    11,    21,
      58,    56,    -1,    58,    68,    57,    -1,    67,    68,    57,
      -1,    69,    21,    -1,    69,    14,    21,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,    21,    -1,    59,    72,
      -1,    70,    60,    72,    -1,    72,    70,    61,    74,    -1,
      72,    70,    61,    57,    -1,    72,    59,    61,    74,    -1,
      72,    59,    61,    57,    -1,    69,    21,    -1,    69,    14,
      21,    -1,    58,    75,    -1,    73,    75,    -1,    73,    56,
      -1,    58,    56,    -1,    74,    -1,    76,    -1,    77,    -1,
      78,    -1,    79,    -1,    80,    57,    -1,    57,    -1,    72,
      47,    80,    57,    -1,     9,    59,    80,    61,    75,    -1,
       7,    59,    80,    61,    75,     8,    75,    -1,     7,    59,
      80,    61,    75,    -1,    10,    57,    -1,    10,    80,    57,
      -1,    81,    -1,    82,    -1,    83,    -1,    85,    -1,    59,
      80,    61,    -1,    86,    -1,    87,    -1,    80,    15,    80,
      -1,    80,    16,    80,    -1,    80,    17,    80,    -1,    80,
      18,    80,    -1,    80,    19,    80,    -1,    80,    20,    80,
      -1,    80,    48,    80,    -1,    80,    49,    80,    -1,    80,
      50,    80,    -1,    80,    51,    80,    -1,    80,    47,    80,
      -1,    29,    80,    -1,    30,    80,    -1,    53,    80,    -1,
      13,    21,    59,    61,    -1,    13,     6,    59,    80,    61,
      -1,    13,    69,    54,    80,    62,    -1,    21,    59,    80,
      -1,    84,    60,    80,    -1,    84,    61,    -1,    21,    59,
      61,    -1,    21,    -1,    80,    54,    80,    62,    -1,    80,
      55,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    12,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    51,    52,    53,    54,    55,    56,    59,
      62,    67,    68,    72,    74,    79,    80,    81,    82,    83,
      86,    89,    92,    99,   105,   113,   122,   127,   134,   139,
     145,   150,   157,   158,   159,   160,   161,   162,   163,   166,
     174,   181,   188,   195,   200,   207,   208,   209,   210,   211,
     212,   213,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   229,   230,   231,   234,   240,   246,   254,
     259,   266,   271,   279,   280,   286,   293,   294,   295,   296
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
  "TOK_FIELD", "TOK_ORD", "TOK_CHR", "TOK_ROOT", "ROOT", "IDENT",
  "TOK_FUNCTION", "TOK_PARAMLIST", "TOK_PROTOTYPE", "TOK_NEWSTRING",
  "TOK_INDEX", "TOK_DECLID", "TOK_RETURNVOID", "TOK_VARDECLAR", "'='",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'['", "'.'", "'}'", "';'",
  "'{'", "'('", "','", "')'", "']'", "$accept", "start", "program",
  "structdef", "strfield", "fielddec", "basetype", "plist", "function",
  "identdec", "body", "block", "statement", "vardec", "while", "ifelse",
  "return", "exp", "binop", "unop", "allocator", "cexp", "call",
  "variable", "constant", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,    61,    43,    45,
      42,    47,    37,    33,    91,    46,   125,    59,   123,    40,
      44,    41,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    65,    65,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    69,    69,    69,
      70,    70,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    76,
      77,    78,    78,    79,    79,    80,    80,    80,    80,    80,
      80,    80,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    83,    83,    83,    84,
      84,    85,    85,    86,    86,    86,    87,    87,    87,    87
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     2,     3,     3,     0,     4,
       4,     3,     3,     2,     3,     1,     1,     1,     1,     1,
       2,     3,     4,     4,     4,     4,     2,     3,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     2,     1,     4,
       5,     7,     5,     2,     3,     1,     1,     1,     1,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     4,     5,     5,     3,
       3,     2,     3,     1,     4,     3,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     0,     1,     0,    15,    16,    17,    18,     0,
       0,     0,     0,    79,     0,    73,    76,    77,    78,     0,
       0,     0,    38,     0,     0,     3,     0,     4,     0,     0,
      32,     5,    33,    34,    35,    36,     0,    45,    46,    47,
       0,    48,    50,    51,     6,     7,     0,     0,    73,    43,
       0,     0,    18,    19,     0,     0,    63,    64,    65,    31,
       0,    28,     0,     0,    26,     0,     0,     0,    30,    29,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,    71,     0,     0,    44,     0,
       0,     0,     0,     0,    72,    69,    49,    27,     0,    19,
       0,    20,     0,     0,    52,    53,    54,    55,    56,    57,
      62,    58,    59,    60,    61,     0,    75,    70,     0,     0,
      10,     0,     0,     9,     0,     0,    66,     0,    39,    25,
      24,    21,    23,    22,    74,    42,    40,    11,     0,    13,
      12,    67,    68,     0,    14,    41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    25,    90,   121,    26,    67,    27,    60,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -99
static const yytype_int16 yypact[] =
{
     -99,     4,   102,   -99,   -38,   -99,   -99,   -99,   -99,   -51,
     -46,   308,    12,   -99,    31,     0,   -99,   -99,   -99,   321,
     321,   321,   -99,   141,   321,   -99,    24,   -99,   -19,   180,
     -99,   -99,   -99,   -99,   -99,   -99,   418,   -99,   -99,   -99,
     -12,   -99,   -99,   -99,   -99,   -99,   321,   321,   -37,   -99,
     461,   -14,    -9,     5,     9,   232,     1,     1,     1,   -99,
      13,   -99,   337,    67,   -99,   321,    20,    23,   -99,   -99,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     321,   321,    69,   -99,   321,   -99,   353,   400,   -99,     6,
      26,   321,    49,   321,   -99,   483,   -99,   -99,   472,   -99,
      28,   -99,   113,    42,    43,    43,    43,    43,    43,    43,
     483,     3,     3,     1,     1,   248,   -99,   483,   219,   219,
     -99,    47,    25,   -99,    64,   409,   -99,   264,   -99,   -99,
     -99,   -99,   -99,   -99,   -99,   114,   -99,   -99,   106,   -99,
     -99,   -99,   -99,   219,   -99,   -99
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -99,   -99,   -99,   -99,   -99,    38,   -11,   -99,   -99,    -1,
     -99,   -98,   -23,   -99,   -99,   -99,   -99,    -4,   -99,   -99,
     -99,   -99,   -99,   -99,   -99
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -20
static const yytype_int16 yytable[] =
{
      61,    28,   130,    54,     3,   133,    69,    50,    46,     5,
       6,     7,     8,    47,   -19,    56,    57,    58,    44,    45,
      62,   -19,    55,     5,     6,     7,     8,    99,    65,     5,
       6,     7,     8,    51,     5,     6,     7,    52,    63,   138,
      66,    99,    86,    87,    89,    64,   139,    99,    84,    85,
      91,    95,    53,    79,    80,    81,    82,    81,    82,    55,
      65,    98,   120,    93,    92,   101,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   122,   122,
     117,   100,   123,   102,   103,   129,    23,   125,    97,   127,
     116,    77,    78,    79,    80,   135,   136,    81,    82,   132,
      23,   131,    -2,     4,   137,     5,     6,     7,     8,     9,
     126,    10,    11,    12,    13,    14,     5,     6,     7,     8,
     145,   140,   143,    15,    16,    17,    18,   144,   124,     0,
       0,    19,    20,     0,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,     0,
      10,    11,     0,    13,    14,    21,     0,     0,     0,    22,
      23,    24,    15,    16,    17,    18,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,     0,    10,
      11,     0,    13,    14,    21,     0,     0,    59,    22,    23,
      24,    15,    16,    17,    18,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     6,     7,     8,     9,     0,    10,    11,
       0,    13,    14,    21,     0,     0,    68,    22,    23,    24,
      15,    16,    17,    18,    13,    14,     0,     0,    19,    20,
       0,     0,     0,    48,    16,    17,    18,     0,     0,     0,
       0,    19,    20,    70,    71,    72,    73,    74,    75,     0,
       0,     0,    21,     0,     0,     0,    22,    23,    24,    70,
      71,    72,    73,    74,    75,    21,     0,     0,     0,     0,
       0,    24,     0,    94,     0,    76,    77,    78,    79,    80,
       0,     0,    81,    82,     0,     0,     0,     0,     0,     0,
     134,    76,    77,    78,    79,    80,     0,     0,    81,    82,
      13,    14,     0,     0,     0,     0,   142,     0,     0,    48,
      16,    17,    18,    13,    14,     0,     0,    19,    20,     0,
       0,     0,    48,    16,    17,    18,     0,     0,     0,     0,
      19,    20,    70,    71,    72,    73,    74,    75,     0,     0,
       0,    21,     0,     0,     0,    49,     0,    24,    70,    71,
      72,    73,    74,    75,    21,     0,     0,     0,     0,     0,
      24,     0,     0,     0,    76,    77,    78,    79,    80,     0,
       0,    81,    82,     0,     0,     0,     0,     0,    96,     0,
      76,    77,    78,    79,    80,     0,     0,    81,    82,     0,
       0,     0,     0,     0,   118,    70,    71,    72,    73,    74,
      75,     0,     0,     0,    70,    71,    72,    73,    74,    75,
       0,     0,     0,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,     0,     0,    81,    82,    76,    77,    78,    79,
      80,   119,     0,    81,    82,    76,    77,    78,    79,    80,
     141,     0,    81,    82,     0,    83,    70,    71,    72,    73,
      74,    75,     0,     0,     0,     0,     0,    70,    71,    72,
      73,    74,    75,     0,     0,     0,     0,     0,    70,    71,
      72,    73,    74,    75,     0,     0,     0,     0,    76,    77,
      78,    79,    80,     0,     0,    81,    82,     0,    88,    76,
      77,    78,    79,    80,     0,     0,    81,    82,     0,   128,
      76,    77,    78,    79,    80,     0,     0,    81,    82
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      23,     2,   100,    14,     0,   103,    29,    11,    59,     3,
       4,     5,     6,    59,    14,    19,    20,    21,    56,    57,
      24,    21,    59,     3,     4,     5,     6,    21,    47,     3,
       4,     5,     6,    21,     3,     4,     5,     6,    14,    14,
      59,    21,    46,    47,    58,    21,    21,    21,    60,    61,
      59,    55,    21,    50,    51,    54,    55,    54,    55,    59,
      47,    65,    56,    54,    59,    66,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    89,    90,
      84,    61,    56,    60,    61,    57,    58,    91,    21,    93,
      21,    48,    49,    50,    51,   118,   119,    54,    55,    57,
      58,   102,     0,     1,    57,     3,     4,     5,     6,     7,
      61,     9,    10,    11,    12,    13,     3,     4,     5,     6,
     143,    57,     8,    21,    22,    23,    24,    21,    90,    -1,
      -1,    29,    30,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,
       9,    10,    -1,    12,    13,    53,    -1,    -1,    -1,    57,
      58,    59,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,     9,
      10,    -1,    12,    13,    53,    -1,    -1,    56,    57,    58,
      59,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    29,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,    -1,     9,    10,
      -1,    12,    13,    53,    -1,    -1,    56,    57,    58,    59,
      21,    22,    23,    24,    12,    13,    -1,    -1,    29,    30,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    29,    30,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    57,    58,    59,    15,
      16,    17,    18,    19,    20,    53,    -1,    -1,    -1,    -1,
      -1,    59,    -1,    61,    -1,    47,    48,    49,    50,    51,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      62,    47,    48,    49,    50,    51,    -1,    -1,    54,    55,
      12,    13,    -1,    -1,    -1,    -1,    62,    -1,    -1,    21,
      22,    23,    24,    12,    13,    -1,    -1,    29,    30,    -1,
      -1,    -1,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      29,    30,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    53,    -1,    -1,    -1,    57,    -1,    59,    15,    16,
      17,    18,    19,    20,    53,    -1,    -1,    -1,    -1,    -1,
      59,    -1,    -1,    -1,    47,    48,    49,    50,    51,    -1,
      -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      47,    48,    49,    50,    51,    -1,    -1,    54,    55,    -1,
      -1,    -1,    -1,    -1,    61,    15,    16,    17,    18,    19,
      20,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    48,    49,
      50,    51,    -1,    -1,    54,    55,    47,    48,    49,    50,
      51,    61,    -1,    54,    55,    47,    48,    49,    50,    51,
      61,    -1,    54,    55,    -1,    57,    15,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    47,    48,
      49,    50,    51,    -1,    -1,    54,    55,    -1,    57,    47,
      48,    49,    50,    51,    -1,    -1,    54,    55,    -1,    57,
      47,    48,    49,    50,    51,    -1,    -1,    54,    55
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    64,    65,     0,     1,     3,     4,     5,     6,     7,
       9,    10,    11,    12,    13,    21,    22,    23,    24,    29,
      30,    53,    57,    58,    59,    66,    69,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    56,    57,    59,    59,    21,    57,
      80,    21,     6,    21,    69,    59,    80,    80,    80,    56,
      72,    75,    80,    14,    21,    47,    59,    70,    56,    75,
      15,    16,    17,    18,    19,    20,    47,    48,    49,    50,
      51,    54,    55,    57,    60,    61,    80,    80,    57,    58,
      67,    59,    59,    54,    61,    80,    61,    21,    80,    21,
      61,    72,    60,    61,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    21,    80,    61,    61,
      56,    68,    69,    56,    68,    80,    61,    80,    57,    57,
      74,    72,    57,    74,    62,    75,    75,    57,    14,    21,
      57,    61,    62,     8,    21,    75
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
#line 48 "parser.y"
    {yyparse_astree = (yyvsp[(1) - (1)]);}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 51 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 52 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 53 "parser.y"
    {(yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 54 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 55 "parser.y"
    {(yyval) = (yyvsp[(1) - (3)]);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 56 "parser.y"
    {(yyval) = new_parseroot();}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 60 "parser.y"
    {destroy((yyvsp[(4) - (4)])); (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->changeSym( TOK_TYPEID, (yyvsp[(2) - (4)]));
                    (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)]), (yyvsp[(3) - (4)]));}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 63 "parser.y"
    {destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)])); (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->changeSym(TOK_TYPEID, (yyvsp[(2) - (4)]));
                (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)]));}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 67 "parser.y"
    {destroy((yyvsp[(3) - (3)])); (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 69 "parser.y"
    {destroy((yyvsp[(3) - (3)])); (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 73 "parser.y"
    {(yyvsp[(2) - (2)]) = (yyvsp[(2) - (2)])->changeSym(TOK_FIELD, (yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 75 "parser.y"
    {(yyvsp[(3) - (3)]) = (yyvsp[(3) - (3)])->changeSym(TOK_FIELD, (yyvsp[(3) - (3)])); 
                        (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 79 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 80 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 81 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 82 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 83 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)])->changeSym(TOK_TYPEID,(yyvsp[(1) - (1)]));}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 87 "parser.y"
    {(yyvsp[(1) - (2)]) = (yyvsp[(1) - (2)])->changeSym(TOK_PARAMLIST, (yyvsp[(1) - (2)]));
                    (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 89 "parser.y"
    {destroy((yyvsp[(2) - (3)])); (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)]));}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 93 "parser.y"
    {
                    destroy((yyvsp[(3) - (4)])); 
                    (yyval) = new astree(TOK_FUNCTION, (yyvsp[(1) - (4)])->lloc, "");
                    (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
                    (yyval) = (yyval)->adopt((yyvsp[(4) - (4)]));
                }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    {
                    destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                    (yyval) = new astree(TOK_PROTOTYPE, (yyvsp[(1) - (4)])->lloc, "");
                    (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
                }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 106 "parser.y"
    {
                    destroy((yyvsp[(3) - (4)]));
                    (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->changeSym(TOK_PARAMLIST,(yyvsp[(2) - (4)]) );
                    (yyval) = new astree(TOK_FUNCTION, (yyvsp[(1) - (4)])->lloc, "");
                    (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
                    (yyval) = (yyval)->adopt((yyvsp[(4) - (4)]));
                }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    {
                    destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                    (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->changeSym(TOK_PARAMLIST, (yyvsp[(2) - (4)]));
                    (yyval) = new astree(TOK_PROTOTYPE, (yyvsp[(1) - (4)])->lloc, "");
                    (yyval) = (yyval)->adopt((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));
                }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 123 "parser.y"
    { 
                    (yyvsp[(2) - (2)]) = (yyvsp[(2) - (2)])->changeSym(TOK_DECLID, (yyvsp[(2) - (2)]));
                    (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));
                }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 128 "parser.y"
    {
                    (yyvsp[(3) - (3)]) = (yyvsp[(3) - (3)])->changeSym(TOK_DECLID,(yyvsp[(3) - (3)]));
                    (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 135 "parser.y"
    {
                    (yyvsp[(1) - (2)]) = (yyvsp[(1) - (2)])->changeSym(TOK_BLOCK, (yyvsp[(1) - (2)]));
                    (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)]));
                }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {
                    (yyval) = (yyvsp[(1) - (2)])->adopt((yyvsp[(2) - (2)])); 
                }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    {
                    destroy((yyvsp[(2) - (2)]));
                    (yyval) = (yyvsp[(1) - (2)])->changeSym(TOK_BLOCK, (yyvsp[(1) - (2)]));
                }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 151 "parser.y"
    {
                    destroy((yyvsp[(2) - (2)]));
                    (yyval) = (yyvsp[(1) - (2)])->changeSym(TOK_BLOCK,(yyvsp[(1) - (2)]));
                }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 157 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 158 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 159 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 160 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 161 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {destroy((yyvsp[(2) - (2)])); (yyval) = (yyvsp[(1) - (2)]);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 167 "parser.y"
    {
                    destroy((yyvsp[(4) - (4)]));
                    (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->changeSym(TOK_VARDECLAR,(yyvsp[(2) - (4)]));
                    (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
                }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    { 
                    destroy((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                    (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 182 "parser.y"
    {
                    destroy((yyvsp[(2) - (7)]), (yyvsp[(4) - (7)]));
                    (yyvsp[(1) - (7)])->changeSym(TOK_IFELSE, (yyvsp[(1) - (7)]));
                    (yyval) = (yyvsp[(1) - (7)])->adopt((yyvsp[(3) - (7)]), (yyvsp[(5) - (7)]));
                    (yyval) = (yyval)->adopt((yyvsp[(7) - (7)]));
                }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 189 "parser.y"
    {
                    destroy((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                    (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    {
                    destroy((yyvsp[(2) - (2)]));
                    (yyval) = (yyvsp[(1) - (2)])->changeSym(TOK_RETURNVOID, (yyvsp[(1) - (2)]));
                }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 201 "parser.y"
    {
                    destroy((yyvsp[(3) - (3)]));
                    (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(2) - (3)]));
                }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 208 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 209 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 210 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 211 "parser.y"
    {destroy((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); (yyval) = (yyvsp[(2) - (3)]);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 212 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 213 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 218 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 219 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 220 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 222 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 223 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 224 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 225 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 226 "parser.y"
    {(yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 229 "parser.y"
    {(yyval) = (yyval)->adopt((yyvsp[(2) - (2)]));}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 230 "parser.y"
    {(yyval) = (yyval)->adopt((yyvsp[(2) - (2)]));}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 231 "parser.y"
    {(yyval) = (yyval)->adopt((yyvsp[(2) - (2)]));}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 235 "parser.y"
    {
                    destroy((yyvsp[(3) - (4)]), (yyvsp[(4) - (4)]));
                    (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->changeSym(TOK_TYPEID, (yyvsp[(2) - (4)]));
                    (yyval) = (yyvsp[(1) - (4)])->adopt((yyvsp[(2) - (4)]));
                }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 241 "parser.y"
    {
                    destroy((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                    (yyvsp[(1) - (5)]) = (yyvsp[(1) - (5)])->changeSym(TOK_NEWSTRING,(yyvsp[(1) - (5)]));
                    (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(4) - (5)]));
                }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 247 "parser.y"
    {
                    destroy((yyvsp[(3) - (5)]), (yyvsp[(5) - (5)]));
                    (yyvsp[(1) - (5)]) = (yyvsp[(1) - (5)])->changeSym(TOK_NEWARRAY, (yyvsp[(1) - (5)]));
                    (yyval) = (yyvsp[(1) - (5)])->adopt((yyvsp[(2) - (5)]), (yyvsp[(4) - (5)]));
                }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 255 "parser.y"
    {
                    (yyvsp[(2) - (3)]) = (yyvsp[(2) - (3)])->changeSym(TOK_CALL, (yyvsp[(2) - (3)]));
                    (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 260 "parser.y"
    {
                    destroy((yyvsp[(2) - (3)]));
                    (yyval) = (yyvsp[(1) - (3)])->adopt((yyvsp[(3) - (3)]));
                }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 267 "parser.y"
    {
                    destroy((yyvsp[(2) - (2)]));
                    (yyval) = (yyvsp[(1) - (2)]);
                }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 272 "parser.y"
    {
                    destroy((yyvsp[(3) - (3)]));
                    (yyvsp[(2) - (3)]) = (yyvsp[(2) - (3)])->changeSym(TOK_CALL, (yyvsp[(2) - (3)]));
                    (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]));
                }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 279 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 281 "parser.y"
    { 
                    destroy((yyvsp[(4) - (4)]));
                    (yyvsp[(2) - (4)]) = (yyvsp[(2) - (4)])->changeSym(TOK_INDEX, (yyvsp[(2) - (4)]));
                    (yyval) = (yyvsp[(2) - (4)])->adopt((yyvsp[(1) - (4)]), (yyvsp[(3) - (4)]));
                }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 287 "parser.y"
    {
                    (yyvsp[(3) - (3)]) = (yyvsp[(3) - (3)])->changeSym(TOK_FIELD, (yyvsp[(3) - (3)]));
                    (yyval) = (yyvsp[(2) - (3)])->adopt((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)]));
                }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 293 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 294 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 295 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 296 "parser.y"
    {(yyval) = (yyvsp[(1) - (1)]);}
    break;


/* Line 1792 of yacc.c  */
#line 2156 "yyparse.cpp"
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
#line 299 "parser.y"


const char *parser::get_tname(int symbol) {
   return yytname [YYTRANSLATE(symbol)];
}

const char *get_yytname(int symbol) {
   return yytname [YYTRANSLATE(symbol)];
}


bool is_defined_token(int symbol) {
   return YYTRANSLATE(symbol) > YYUNDEFTOK;
}
