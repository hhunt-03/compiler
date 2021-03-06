/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Ident = 258,
     IntLit = 259,
     Int = 260,
     Void = 261,
     Return = 262,
     IF = 263,
     ELSE = 264,
     WHILE = 265,
     FOR = 266,
     READ = 267,
     PRINT = 268,
     PRINTLINES = 269,
     PRINTSPACES = 270,
     EQ = 271,
     LESS_THAN = 272,
     GREATER_THAN = 273,
     LESS_THAN_EQUALS_TO = 274,
     GREATER_THAN_EQUALS_TO = 275,
     NOT_EQUAL = 276,
     NOT = 277,
     AND = 278,
     OR = 279
   };
#endif
/* Tokens.  */
#define Ident 258
#define IntLit 259
#define Int 260
#define Void 261
#define Return 262
#define IF 263
#define ELSE 264
#define WHILE 265
#define FOR 266
#define READ 267
#define PRINT 268
#define PRINTLINES 269
#define PRINTSPACES 270
#define EQ 271
#define LESS_THAN 272
#define GREATER_THAN 273
#define LESS_THAN_EQUALS_TO 274
#define GREATER_THAN_EQUALS_TO 275
#define NOT_EQUAL 276
#define NOT 277
#define AND 278
#define OR 279




/* Copy the first part of user declarations.  */
#line 1 "ExprEval.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Semantics.h"
#include "IOMngr.h"
#include "SymTab.h"
#include "CodeGen.h"

extern  int  yylex();	    /* The next token function. */
extern  char *yytext;    /* The matched token text.  */
extern  int  yyleng;      /* The token text length.   */
extern  int  yyparse();
extern  int  yyerror(char *);
        void dumpTable();

extern sym_tab_t *table;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "ExprEval.y"
{
  long val;
  char* string;
  struct expr_res_t* expr_res_t;
  struct instr_seq_t* instr_seq_t;
  struct b_expr_res_t* b_expr_res_t;
}
/* Line 193 of yacc.c.  */
#line 172 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 185 "y.tab.c"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   196

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNRULES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    38,     2,     2,
      28,    29,    36,    34,    33,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    27,
       2,    32,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    16,    20,    22,    31,
      40,    43,    44,    47,    49,    51,    53,    55,    57,    61,
      68,    76,    88,    94,   100,   106,   112,   118,   126,   138,
     143,   147,   151,   155,   159,   163,   167,   171,   174,   178,
     182,   184,   188,   190,   194,   198,   202,   204,   208,   212,
     216,   221,   223,   227,   229,   234,   238,   240,   244,   246,
     248,   250,   254,   256,   263,   268
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      41,     0,    -1,    42,    -1,    43,    42,    -1,    -1,     5,
       3,    25,     4,    26,    27,    -1,     5,     3,    27,    -1,
      44,    -1,     6,     3,    28,    29,    30,    42,    45,    31,
      -1,     5,     3,    28,    29,    30,    42,    45,    31,    -1,
      46,    45,    -1,    -1,    47,    27,    -1,    48,    -1,    49,
      -1,    50,    -1,    51,    -1,    52,    -1,    63,    32,    55,
      -1,    63,    25,    55,    26,    32,    55,    -1,     8,    28,
      53,    29,    30,    45,    31,    -1,     8,    28,    53,    29,
      30,    45,    31,     9,    30,    45,    31,    -1,    12,    28,
      61,    29,    27,    -1,    12,    28,    62,    29,    27,    -1,
      13,    28,    54,    29,    27,    -1,    14,    28,    55,    29,
      27,    -1,    15,    28,    55,    29,    27,    -1,    10,    28,
      53,    29,    30,    45,    31,    -1,    11,    28,    47,    27,
      53,    27,    47,    29,    30,    45,    31,    -1,    63,    28,
      29,    27,    -1,     7,    55,    27,    -1,    55,    16,    55,
      -1,    55,    17,    55,    -1,    55,    18,    55,    -1,    55,
      19,    55,    -1,    55,    20,    55,    -1,    55,    21,    55,
      -1,    22,    55,    -1,    55,    23,    55,    -1,    55,    24,
      55,    -1,    55,    -1,    54,    33,    55,    -1,    55,    -1,
      25,    53,    26,    -1,    55,    34,    56,    -1,    55,    35,
      56,    -1,    56,    -1,    56,    36,    58,    -1,    56,    37,
      58,    -1,    56,    38,    58,    -1,    35,    28,    55,    29,
      -1,    57,    -1,    57,    39,    58,    -1,    58,    -1,    63,
      25,    55,    26,    -1,    28,    55,    29,    -1,    59,    -1,
      63,    28,    29,    -1,    60,    -1,     4,    -1,     3,    -1,
      61,    33,    63,    -1,    63,    -1,    62,    33,    63,    25,
      55,    26,    -1,    63,    25,    55,    26,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    83,    83,    85,    86,    88,    89,    90,    92,    93,
      95,    96,    98,    99,   100,   101,   102,   103,   105,   106,
     108,   109,   112,   113,   114,   115,   116,   118,   119,   122,
     124,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   137,   138,   140,   141,   142,   143,   145,   146,   147,
     148,   149,   151,   152,   154,   155,   156,   158,   159,   161,
     162,   164,   165,   167,   168,   170
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "Ident", "IntLit", "Int", "Void",
  "Return", "IF", "ELSE", "WHILE", "FOR", "READ", "PRINT", "PRINTLINES",
  "PRINTSPACES", "EQ", "LESS_THAN", "GREATER_THAN", "LESS_THAN_EQUALS_TO",
  "GREATER_THAN_EQUALS_TO", "NOT_EQUAL", "NOT", "AND", "OR", "'['", "']'",
  "';'", "'('", "')'", "'{'", "'}'", "'='", "','", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'^'", "$accept", "Prog", "Declarations", "Dec",
  "FunctionDecl", "StmtSeq", "Stmt", "AssignStmt", "IfStmt", "IOStmt",
  "Loop", "FunctionCall", "ReturnStmt", "BExpr", "ExprSeq", "Expr", "Term",
  "Unit", "Factor", "Item", "Atom", "IdSeq", "ArraySeq", "Id", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    91,    93,    59,    40,    41,
     123,   125,    61,    44,    43,    45,    42,    47,    37,    94
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    46,    46,    47,    47,
      48,    48,    49,    49,    49,    49,    49,    50,    50,    51,
      52,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    54,    54,    55,    55,    55,    55,    56,    56,    56,
      56,    56,    57,    57,    58,    58,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     3,     1,     8,     8,
       2,     0,     2,     1,     1,     1,     1,     1,     3,     6,
       7,    11,     5,     5,     5,     5,     5,     7,    11,     4,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       1,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       4,     1,     3,     1,     4,     3,     1,     3,     1,     1,
       1,     3,     1,     6,     4,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     2,     4,     7,     0,     0,     1,
       3,     0,     6,     0,     0,     0,     0,     0,     0,     4,
       4,     5,    11,    11,    65,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,    13,    14,    15,    16,
      17,     0,     0,    60,    59,     0,     0,     0,     0,    46,
      51,    53,    56,    58,     0,     0,     0,     0,     0,     0,
       0,     0,     9,    10,    12,     0,     0,     0,     8,     0,
       0,    40,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
       0,    42,     0,     0,     0,     0,    18,    37,    43,     0,
       0,     0,     0,     0,     0,     0,     0,    55,     0,    44,
      45,    47,    48,    49,    52,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,    31,    32,    33,    34,    35,    36,    38,    39,    50,
      54,    11,    11,     0,    22,    61,    23,     0,     0,    24,
      41,    25,    26,     0,     0,     0,     0,     0,    64,    19,
      20,    27,     0,     0,     0,     0,    63,    11,    11,     0,
       0,    21,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    33,    34,    35,    36,    37,
      38,    39,    40,    70,    90,    71,    49,    50,    51,    52,
      53,    87,    88,    54
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -53
static const yytype_int16 yypact[] =
{
     111,    -1,    40,    37,   -53,   111,   -53,    85,    25,   -53,
     -53,    58,   -53,    48,    57,    71,    70,    79,    87,   111,
     111,   -53,    61,    61,   -53,    26,   109,   116,   128,   129,
     130,   131,   132,   133,    61,   134,   -53,   -53,   -53,   -53,
     -53,    83,   135,   -12,   -53,     6,    26,   137,    -8,   117,
     123,   -53,   -53,   -53,   124,     6,     6,   160,   160,    26,
      26,    26,   -53,   -53,   -53,    26,   138,    26,   -53,    26,
     142,    72,    89,    26,   -53,    14,    14,    17,    17,    17,
      17,    26,   140,   141,   143,   144,    62,   -18,    34,   148,
      69,   108,    96,   104,    -2,   147,   108,   108,   -53,    26,
      26,    26,    26,    26,    26,    26,    26,   -53,   106,   117,
     117,   -53,   -53,   -53,   -53,    21,   -53,   145,   146,     6,
     150,   160,   151,   160,    26,   152,    26,   153,   154,   155,
     -53,   108,   108,   108,   108,   108,   108,   108,   108,   -53,
     -53,    61,    61,   156,   -53,   -53,   -53,   157,    24,   -53,
     108,   -53,   -53,    26,   158,   159,   160,    26,   -53,   108,
     175,   -53,   162,    31,   163,   164,   -53,    61,    61,   161,
     165,   -53,   -53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,     3,   -53,   -53,   -20,   -53,   -52,   -53,   -53,
     -53,   -53,   -53,   -49,   -53,   -21,    75,   -53,    49,   -53,
     -53,   -53,   -53,   -22
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
      41,    41,     7,    42,    48,    85,    83,    84,    10,    43,
      44,   120,    41,   -65,    63,   121,   -65,    43,    44,    74,
      43,    44,    22,    23,   129,    72,    75,    76,    69,    43,
      44,    45,    75,    76,    46,    86,    89,     9,    91,    92,
      93,    47,    46,     8,    94,    46,    96,   140,    97,    47,
     158,    45,   108,    14,    46,    75,    76,   166,    75,    76,
     115,    47,    15,   122,    24,    75,    76,   123,    25,    26,
     143,    27,    28,    29,    30,    31,    32,    16,   131,   132,
     133,   134,   135,   136,   137,   138,    17,    65,    99,   100,
     101,   102,   103,   104,    67,   105,   106,    18,   125,   145,
      19,   147,   126,   148,   162,   150,    75,    76,    65,    20,
      11,    66,    12,    13,    21,    67,     1,     2,   107,    41,
      41,   154,   155,    75,    76,   127,   111,   112,   113,   114,
      75,    76,   159,   128,    86,   139,   163,    55,    75,    76,
      75,    76,    75,    76,    56,    41,    41,   169,   170,    81,
     109,   110,    82,    77,    78,    79,    57,    58,    59,    60,
      61,    64,    80,    24,    62,    73,    68,    95,    98,   116,
     117,   119,   118,   124,   130,   141,   142,   144,   146,   149,
     151,   152,   157,   156,   164,     0,     0,   153,     0,   160,
     161,   165,   171,   167,   168,     0,   172
};

static const yytype_int16 yycheck[] =
{
      22,    23,     3,    23,    25,    57,    55,    56,     5,     3,
       4,    29,    34,    25,    34,    33,    28,     3,     4,    27,
       3,     4,    19,    20,    26,    46,    34,    35,    22,     3,
       4,    25,    34,    35,    28,    57,    58,     0,    59,    60,
      61,    35,    28,     3,    65,    28,    67,    26,    69,    35,
      26,    25,    73,    28,    28,    34,    35,    26,    34,    35,
      81,    35,     4,    29,     3,    34,    35,    33,     7,     8,
     119,    10,    11,    12,    13,    14,    15,    29,    99,   100,
     101,   102,   103,   104,   105,   106,    29,    25,    16,    17,
      18,    19,    20,    21,    32,    23,    24,    26,    29,   121,
      30,   123,    33,   124,   156,   126,    34,    35,    25,    30,
      25,    28,    27,    28,    27,    32,     5,     6,    29,   141,
     142,   141,   142,    34,    35,    29,    77,    78,    79,    80,
      34,    35,   153,    29,   156,    29,   157,    28,    34,    35,
      34,    35,    34,    35,    28,   167,   168,   167,   168,    25,
      75,    76,    28,    36,    37,    38,    28,    28,    28,    28,
      28,    27,    39,     3,    31,    28,    31,    29,    26,    29,
      29,    27,    29,    25,    27,    30,    30,    27,    27,    27,
      27,    27,    25,    27,     9,    -1,    -1,    32,    -1,    31,
      31,    29,    31,    30,    30,    -1,    31
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,     6,    41,    42,    43,    44,     3,     3,     0,
      42,    25,    27,    28,    28,     4,    29,    29,    26,    30,
      30,    27,    42,    42,     3,     7,     8,    10,    11,    12,
      13,    14,    15,    45,    46,    47,    48,    49,    50,    51,
      52,    63,    45,     3,     4,    25,    28,    35,    55,    56,
      57,    58,    59,    60,    63,    28,    28,    28,    28,    28,
      28,    28,    31,    45,    27,    25,    28,    32,    31,    22,
      53,    55,    55,    28,    27,    34,    35,    36,    37,    38,
      39,    25,    28,    53,    53,    47,    63,    61,    62,    63,
      54,    55,    55,    55,    55,    29,    55,    55,    26,    16,
      17,    18,    19,    20,    21,    23,    24,    29,    55,    56,
      56,    58,    58,    58,    58,    55,    29,    29,    29,    27,
      29,    33,    29,    33,    25,    29,    33,    29,    29,    26,
      27,    55,    55,    55,    55,    55,    55,    55,    55,    29,
      26,    30,    30,    53,    27,    63,    27,    63,    55,    27,
      55,    27,    27,    32,    45,    45,    27,    25,    26,    55,
      31,    31,    47,    55,     9,    29,    26,    30,    30,    45,
      45,    31,    31
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
#line 83 "ExprEval.y"
    { finish(); }
    break;

  case 3:
#line 85 "ExprEval.y"
    {}
    break;

  case 4:
#line 86 "ExprEval.y"
    {}
    break;

  case 5:
#line 88 "ExprEval.y"
    { char *size = to_int_type((yyvsp[(4) - (6)].string)); enter_name(table, (yyvsp[(2) - (6)].string), ARRAY); set_current_attr(table, size); }
    break;

  case 6:
#line 89 "ExprEval.y"
    { enter_name(table, (yyvsp[(2) - (3)].string), VAR);}
    break;

  case 7:
#line 90 "ExprEval.y"
    {}
    break;

  case 8:
#line 92 "ExprEval.y"
    { enter_name(table, (yyvsp[(2) - (8)].string), FUNCTION); set_current_attr(table, do_void_function_decl((yyvsp[(2) - (8)].string), (yyvsp[(7) - (8)].instr_seq_t)));}
    break;

  case 9:
#line 93 "ExprEval.y"
    { enter_name(table, (yyvsp[(2) - (8)].string), FUNCTION); set_current_attr(table, do_int_function_decl((yyvsp[(2) - (8)].string), (yyvsp[(7) - (8)].instr_seq_t)));}
    break;

  case 10:
#line 95 "ExprEval.y"
    {(yyval.instr_seq_t) = append_seq((yyvsp[(1) - (2)].instr_seq_t), (yyvsp[(2) - (2)].instr_seq_t)); }
    break;

  case 11:
#line 96 "ExprEval.y"
    {(yyval.instr_seq_t) = NULL;}
    break;

  case 12:
#line 98 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(1) - (2)].instr_seq_t);}
    break;

  case 13:
#line 99 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(1) - (1)].instr_seq_t);}
    break;

  case 14:
#line 100 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(1) - (1)].instr_seq_t);}
    break;

  case 15:
#line 101 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(1) - (1)].instr_seq_t);}
    break;

  case 16:
#line 102 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(1) - (1)].instr_seq_t);}
    break;

  case 17:
#line 103 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(1) - (1)].instr_seq_t);}
    break;

  case 18:
#line 105 "ExprEval.y"
    {(yyval.instr_seq_t) = do_assign((yyvsp[(1) - (3)].string), (yyvsp[(3) - (3)].expr_res_t));}
    break;

  case 19:
#line 106 "ExprEval.y"
    {(yyval.instr_seq_t) = do_array_assign((yyvsp[(1) - (6)].string), (yyvsp[(3) - (6)].expr_res_t), (yyvsp[(6) - (6)].expr_res_t));}
    break;

  case 20:
#line 108 "ExprEval.y"
    {(yyval.instr_seq_t) = do_if((yyvsp[(3) - (7)].expr_res_t), (yyvsp[(6) - (7)].instr_seq_t));}
    break;

  case 21:
#line 110 "ExprEval.y"
    {(yyval.instr_seq_t) = do_if_else((yyvsp[(3) - (11)].expr_res_t), (yyvsp[(6) - (11)].instr_seq_t), (yyvsp[(10) - (11)].instr_seq_t));}
    break;

  case 22:
#line 112 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(3) - (5)].instr_seq_t); }
    break;

  case 23:
#line 113 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(3) - (5)].instr_seq_t); }
    break;

  case 24:
#line 114 "ExprEval.y"
    {(yyval.instr_seq_t) = (yyvsp[(3) - (5)].instr_seq_t); }
    break;

  case 25:
#line 115 "ExprEval.y"
    {(yyval.instr_seq_t) = do_printlines((yyvsp[(3) - (5)].expr_res_t));}
    break;

  case 26:
#line 116 "ExprEval.y"
    {(yyval.instr_seq_t) = do_printspaces((yyvsp[(3) - (5)].expr_res_t));}
    break;

  case 27:
#line 118 "ExprEval.y"
    {(yyval.instr_seq_t) = do_while((yyvsp[(3) - (7)].expr_res_t), (yyvsp[(6) - (7)].instr_seq_t));}
    break;

  case 28:
#line 120 "ExprEval.y"
    {(yyval.instr_seq_t) = do_for((yyvsp[(3) - (11)].instr_seq_t), (yyvsp[(5) - (11)].expr_res_t), (yyvsp[(7) - (11)].instr_seq_t), (yyvsp[(10) - (11)].instr_seq_t));}
    break;

  case 29:
#line 122 "ExprEval.y"
    {(yyval.instr_seq_t) = do_function_call((yyvsp[(1) - (4)].string));}
    break;

  case 30:
#line 124 "ExprEval.y"
    {(yyval.instr_seq_t) = do_return_stmt((yyvsp[(2) - (3)].expr_res_t));}
    break;

  case 31:
#line 126 "ExprEval.y"
    {(yyval.expr_res_t) = do_eq((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t));}
    break;

  case 32:
#line 127 "ExprEval.y"
    {(yyval.expr_res_t) = do_less_than((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t));}
    break;

  case 33:
#line 128 "ExprEval.y"
    {(yyval.expr_res_t) = do_greater_than((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t));}
    break;

  case 34:
#line 129 "ExprEval.y"
    {(yyval.expr_res_t) = do_less_than_equals_to((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t));}
    break;

  case 35:
#line 130 "ExprEval.y"
    {(yyval.expr_res_t) = do_greater_than_equals_to((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t));}
    break;

  case 36:
#line 131 "ExprEval.y"
    {(yyval.expr_res_t) = do_not_equal((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t));}
    break;

  case 37:
#line 132 "ExprEval.y"
    {(yyval.expr_res_t) = do_not((yyvsp[(2) - (2)].expr_res_t)); }
    break;

  case 38:
#line 133 "ExprEval.y"
    {(yyval.expr_res_t) = do_and((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 39:
#line 134 "ExprEval.y"
    {(yyval.expr_res_t) = do_or((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 40:
#line 135 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(1) - (1)].expr_res_t);}
    break;

  case 41:
#line 137 "ExprEval.y"
    {(yyval.instr_seq_t) = append_seq((yyvsp[(1) - (3)].instr_seq_t), do_print((yyvsp[(3) - (3)].expr_res_t))); }
    break;

  case 42:
#line 138 "ExprEval.y"
    {(yyval.instr_seq_t) = do_print((yyvsp[(1) - (1)].expr_res_t)); }
    break;

  case 43:
#line 140 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(2) - (3)].expr_res_t); }
    break;

  case 44:
#line 141 "ExprEval.y"
    {(yyval.expr_res_t) = do_add((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 45:
#line 142 "ExprEval.y"
    {(yyval.expr_res_t) = do_subtraction((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 46:
#line 143 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(1) - (1)].expr_res_t); }
    break;

  case 47:
#line 145 "ExprEval.y"
    {(yyval.expr_res_t) = do_mult((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 48:
#line 146 "ExprEval.y"
    {(yyval.expr_res_t) = do_division((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 49:
#line 147 "ExprEval.y"
    {(yyval.expr_res_t) = do_mod((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 50:
#line 148 "ExprEval.y"
    {(yyval.expr_res_t) = do_unary_minus((yyvsp[(3) - (4)].expr_res_t)); }
    break;

  case 51:
#line 149 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(1) - (1)].expr_res_t); }
    break;

  case 52:
#line 151 "ExprEval.y"
    {(yyval.expr_res_t) = do_exponent((yyvsp[(1) - (3)].expr_res_t), (yyvsp[(3) - (3)].expr_res_t)); }
    break;

  case 53:
#line 152 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(1) - (1)].expr_res_t); }
    break;

  case 54:
#line 154 "ExprEval.y"
    {(yyval.expr_res_t) = do_array_access((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].expr_res_t)); }
    break;

  case 55:
#line 155 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(2) - (3)].expr_res_t); }
    break;

  case 56:
#line 156 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(1) - (1)].expr_res_t); }
    break;

  case 57:
#line 158 "ExprEval.y"
    {(yyval.expr_res_t) = do_int_function_call((yyvsp[(1) - (3)].string));}
    break;

  case 58:
#line 159 "ExprEval.y"
    {(yyval.expr_res_t) = (yyvsp[(1) - (1)].expr_res_t);}
    break;

  case 59:
#line 161 "ExprEval.y"
    {(yyval.expr_res_t) = do_int_lit(yytext); }
    break;

  case 60:
#line 162 "ExprEval.y"
    {(yyval.expr_res_t) = do_rval((yyvsp[(1) - (1)].string)); }
    break;

  case 61:
#line 164 "ExprEval.y"
    {(yyval.instr_seq_t) = append_seq((yyvsp[(1) - (3)].instr_seq_t), do_read((yyvsp[(3) - (3)].string))); }
    break;

  case 62:
#line 165 "ExprEval.y"
    {(yyval.instr_seq_t) = do_read((yyvsp[(1) - (1)].string)); }
    break;

  case 63:
#line 167 "ExprEval.y"
    {(yyval.instr_seq_t) = append_seq((yyvsp[(1) - (6)].instr_seq_t), do_array_read((yyvsp[(3) - (6)].string), (yyvsp[(5) - (6)].expr_res_t)));}
    break;

  case 64:
#line 168 "ExprEval.y"
    {(yyval.instr_seq_t) = do_array_read((yyvsp[(1) - (4)].string), (yyvsp[(3) - (4)].expr_res_t));}
    break;

  case 65:
#line 170 "ExprEval.y"
    {(yyval.string) = (yyvsp[(1) - (1)].string);}
    break;


/* Line 1267 of yacc.c.  */
#line 1839 "y.tab.c"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 172 "ExprEval.y"


int yyerror(char *s)  {
  printf("yyerror : %s\n", s);
  write_indicator(get_current_column_num());
  write_message("Illegal Character in YACC\n");
  return 1;
}

