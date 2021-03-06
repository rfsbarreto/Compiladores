/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "bison.y"
 
//#include <stdio.h>
//#include "bib1.c"
#include "bib_inic.h"
//#include "leitura.h"

//#include "teste.h"
#include "lex.c"
#define YYDEBUG 1
//#define DEC(dec) mng_##dec dec
//extern mng_tipbase ;

//No_ast* arvore;
lista_simb* tbl;
mng_prg* arvore;
pilha* p;


void yyerror(const char* errmsg);






/* Line 268 of yacc.c  */
#line 97 "sint.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     ELSE = 259,
     FLOAT = 260,
     IF = 261,
     INT = 262,
     NEW = 263,
     RETURN = 264,
     VOID = 265,
     WHILE = 266,
     NUMINT = 267,
     NUMFLOAT = 268,
     STRING = 269,
     ID = 270,
     PTVIRG = 271,
     VIRG = 272,
     ACOL = 273,
     FCOL = 274,
     APAR = 275,
     FPAR = 276,
     ACHAVE = 277,
     FCHAVE = 278,
     SOMA = 279,
     SUB = 280,
     MULT = 281,
     DIV = 282,
     ATRIB = 283,
     IGUAL = 284,
     MENORIG = 285,
     MAIORIG = 286,
     MENORQ = 287,
     MAIORQ = 288,
     NAO = 289,
     E = 290,
     OU = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 33 "bison.y"

	
	mng_tipbase  tipbase;	
	mng_id id;
	mng_var* var;
	mng_bloco * bloco;
//	DEC(bloco);
	mng_pars * pars;
	mng_par* par;
	mng_decvar* decvar;
	mng_decfunc* decfunc;
	mng_tip* tip;
	mng_prg* prg;
	mng_dec* dec;
	mng_listnom* listnom;
	mng_decvars* decvars;
	mng_cmds* cmds;
	mng_cmd* cmd;
	mng_ptelse* ptelse;
	mng_chmet* chmet;
	mng_listexp* listexp;
	mng_exp* exp;
	DEC(numint);
	DEC(numfloat);
	DEC(string);
	DEC(chr);
	//DEC(prg);
	//int token;



/* Line 293 of yacc.c  */
#line 201 "sint.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 213 "sint.c"

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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   262

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  118

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,     9,    11,    13,    17,    19,
      23,    25,    29,    31,    33,    35,    42,    49,    50,    52,
      56,    59,    64,    67,    68,    71,    72,    79,    85,    90,
      94,    97,   100,   102,   103,   106,   108,   113,   115,   117,
     119,   121,   125,   127,   133,   136,   140,   144,   148,   152,
     156,   160,   164,   168,   172,   175,   179,   183,   188,   189,
     191
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    -1,    40,    39,    -1,    41,
      -1,    45,    -1,    43,    42,    16,    -1,    15,    -1,    15,
      17,    42,    -1,    44,    -1,    43,    18,    19,    -1,     7,
      -1,     3,    -1,     5,    -1,    10,    15,    20,    46,    21,
      48,    -1,    43,    15,    20,    46,    21,    48,    -1,    -1,
      47,    -1,    47,    17,    46,    -1,    43,    15,    -1,    22,
      49,    50,    23,    -1,    41,    49,    -1,    -1,    51,    50,
      -1,    -1,     6,    20,    54,    21,    51,    52,    -1,    11,
      20,    54,    21,    51,    -1,    53,    28,    54,    16,    -1,
       9,    54,    16,    -1,     9,    16,    -1,    55,    16,    -1,
      48,    -1,    -1,     4,    51,    -1,    15,    -1,    53,    18,
      54,    19,    -1,    12,    -1,    13,    -1,    14,    -1,    53,
      -1,    20,    54,    21,    -1,    55,    -1,     8,    43,    18,
      54,    19,    -1,    25,    54,    -1,    54,    24,    54,    -1,
      54,    25,    54,    -1,    54,    26,    54,    -1,    54,    27,
      54,    -1,    54,    29,    54,    -1,    54,    30,    54,    -1,
      54,    31,    54,    -1,    54,    32,    54,    -1,    54,    33,
      54,    -1,    34,    54,    -1,    54,    35,    54,    -1,    54,
      36,    54,    -1,    15,    20,    56,    21,    -1,    -1,    54,
      -1,    54,    17,    56,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   105,   105,   112,   113,   118,   125,   135,   138,   141,
     145,   146,   155,   156,   157,   160,   172,   190,   192,   194,
     198,   200,   203,   204,   207,   209,   212,   216,   220,   228,
     232,   234,   235,   240,   241,   244,   245,   259,   263,   268,
     272,   276,   281,   282,   289,   295,   304,   310,   320,   327,
     333,   339,   345,   351,   357,   363,   372,   383,   386,   388,
     390
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "ELSE", "FLOAT", "IF", "INT",
  "NEW", "RETURN", "VOID", "WHILE", "NUMINT", "NUMFLOAT", "STRING", "ID",
  "PTVIRG", "VIRG", "ACOL", "FCOL", "APAR", "FPAR", "ACHAVE", "FCHAVE",
  "SOMA", "SUB", "MULT", "DIV", "ATRIB", "IGUAL", "MENORIG", "MAIORIG",
  "MENORQ", "MAIORQ", "NAO", "E", "OU", "$accept", "principal", "programa",
  "declaracao", "decvariavel", "listanomes", "tipo", "tipobase",
  "decfuncao", "parametros", "parametro", "bloco", "decvariaveis",
  "comandos", "comando", "parteelse", "var", "exp", "chamadaMetodo",
  "listaexp", 0
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
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    42,    42,
      43,    43,    44,    44,    44,    45,    45,    46,    46,    46,
      47,    48,    49,    49,    50,    50,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    53,    53,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    55,    56,    56,
      56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     6,     6,     0,     1,     3,
       2,     4,     2,     0,     2,     0,     6,     5,     4,     3,
       2,     2,     1,     0,     2,     1,     4,     1,     1,     1,
       1,     3,     1,     5,     2,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     4,     0,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    13,    14,    12,     0,     0,     2,     3,     5,     0,
      10,     6,     0,     1,     4,     8,     0,     0,    17,     0,
      17,    11,     7,     0,     0,    18,     8,     9,     0,    20,
       0,    17,     0,    23,    15,    19,    16,    23,     0,    25,
      22,     0,     0,     0,    35,    32,     0,    25,     0,     0,
       0,     0,    37,    38,    39,    30,     0,     0,     0,    40,
       0,    42,     0,    58,    21,    24,     0,     0,    31,     0,
       0,     0,    44,    54,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    59,     0,     0,
       0,     0,     0,    41,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    55,    56,     0,    58,    57,    36,    28,
      33,     0,    27,    60,     0,    26,    43,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    17,    23,    10,    11,    24,
      25,    45,    39,    46,    47,   115,    59,    87,    61,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
     252,   -88,   -88,   -88,     7,    21,   -88,   252,   -88,     2,
     -88,   -88,    14,   -88,   -88,    38,    16,    23,    40,    34,
      40,   -88,   -88,     8,    39,    48,    52,   -88,    49,   -88,
      55,    40,    55,    40,   -88,   -88,   -88,    40,    56,    35,
     -88,    58,    -1,    59,    60,   -88,    69,    35,    10,    77,
      17,    40,   -88,   -88,   -88,   -88,    17,    17,    17,    76,
      93,   -88,    17,    17,   -88,   -88,    17,    17,   -88,   171,
      78,   184,   218,   -88,   -88,    17,    17,    17,    17,    17,
      17,    17,    17,    17,    17,    17,   197,   128,    82,   143,
     111,    35,    87,   -88,   218,   218,   210,   210,   218,   218,
     218,   218,   218,   -88,   -88,    35,    17,   -88,   -88,   -88,
     100,   158,   -88,   -88,    35,   -88,   -88,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,    90,   -88,   -31,    86,     3,   -88,   -88,   -15,
     -88,    29,    71,    63,   -87,   -88,   -39,     6,   -38,     5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,    49,    37,     9,   110,    28,    37,    51,    48,    49,
       9,    52,    53,    54,    44,    55,    35,    15,   112,    56,
      16,    13,    12,    29,    57,    51,    16,   117,    66,    52,
      53,    54,    44,    58,    18,    21,    38,    56,    67,    22,
      38,    41,    57,     1,    42,     2,    43,     3,    60,    26,
      44,    58,    48,    49,    70,    19,    69,    33,    20,    34,
      30,    36,    71,    72,    73,    31,    48,    49,    86,    19,
      32,    26,    89,    90,    16,    48,    49,    33,    50,    62,
      63,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    64,    68,    66,    51,    92,    14,   111,    52,
      53,    54,    44,   107,   114,    27,    21,    56,    40,    74,
      65,   113,    57,     0,     0,     0,     0,    75,    76,    77,
      78,    58,    79,    80,    81,    82,    83,   109,    84,    85,
       0,     0,     0,     0,     0,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,   106,    84,    85,     0,     0,
       0,     0,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,   108,    84,    85,     0,     0,    75,    76,    77,
      78,     0,    79,    80,    81,    82,    83,   116,    84,    85,
       0,     0,    75,    76,    77,    78,     0,    79,    80,    81,
      82,    83,    91,    84,    85,    75,    76,    77,    78,     0,
      79,    80,    81,    82,    83,    93,    84,    85,    75,    76,
      77,    78,     0,    79,    80,    81,    82,    83,   105,    84,
      85,    75,    76,    77,    78,     0,    79,    80,    81,    82,
      83,     0,    84,    85,    75,    76,     0,     0,     0,    79,
      80,    81,    82,    83,     0,    84,    85,    79,    80,    81,
      82,    83,     0,    84,    85,     1,     0,     2,     0,     3,
       0,     0,     4
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-88))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
      39,    39,    33,     0,    91,    20,    37,     8,    47,    47,
       7,    12,    13,    14,    15,    16,    31,    15,   105,    20,
      18,     0,    15,    15,    25,     8,    18,   114,    18,    12,
      13,    14,    15,    34,    20,    19,    33,    20,    28,    16,
      37,     6,    25,     3,     9,     5,    11,     7,    42,    15,
      15,    34,    91,    91,    51,    17,    50,    22,    20,    30,
      21,    32,    56,    57,    58,    17,   105,   105,    62,    17,
      21,    15,    66,    67,    18,   114,   114,    22,    20,    20,
      20,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    23,    16,    18,     8,    18,     7,    92,    12,
      13,    14,    15,    21,     4,    19,    19,    20,    37,    16,
      47,   106,    25,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    34,    29,    30,    31,    32,    33,    16,    35,    36,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    17,    35,    36,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    19,    35,    36,    -1,    -1,    24,    25,    26,
      27,    -1,    29,    30,    31,    32,    33,    19,    35,    36,
      -1,    -1,    24,    25,    26,    27,    -1,    29,    30,    31,
      32,    33,    21,    35,    36,    24,    25,    26,    27,    -1,
      29,    30,    31,    32,    33,    21,    35,    36,    24,    25,
      26,    27,    -1,    29,    30,    31,    32,    33,    21,    35,
      36,    24,    25,    26,    27,    -1,    29,    30,    31,    32,
      33,    -1,    35,    36,    24,    25,    -1,    -1,    -1,    29,
      30,    31,    32,    33,    -1,    35,    36,    29,    30,    31,
      32,    33,    -1,    35,    36,     3,    -1,     5,    -1,     7,
      -1,    -1,    10
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,    10,    38,    39,    40,    41,    43,
      44,    45,    15,     0,    39,    15,    18,    42,    20,    17,
      20,    19,    16,    43,    46,    47,    15,    42,    46,    15,
      21,    17,    21,    22,    48,    46,    48,    41,    43,    49,
      49,     6,     9,    11,    15,    48,    50,    51,    53,    55,
      20,     8,    12,    13,    14,    16,    20,    25,    34,    53,
      54,    55,    20,    20,    23,    50,    18,    28,    16,    54,
      43,    54,    54,    54,    16,    24,    25,    26,    27,    29,
      30,    31,    32,    33,    35,    36,    54,    54,    56,    54,
      54,    21,    18,    21,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    21,    17,    21,    19,    16,
      51,    54,    51,    56,     4,    52,    19,    51
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

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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

/* Line 1806 of yacc.c  */
#line 105 "bison.y"
    {   arvore= (yyvsp[(1) - (1)].prg); 
			//printf("Impressão teste ");imprimirlistaprog(arvore);
			//printf("\n\n ");
			//printf("\nlista final: \n");
//			PercorreArvore($1);	
}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 112 "bison.y"
    { (yyval.prg)=NULL; }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 113 "bison.y"
    {   (yyval.prg)=inicializaprog((yyvsp[(1) - (2)].dec),(yyvsp[(2) - (2)].prg)); 
 //imprimirlistadec($1); printf("\n"); 
}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 118 "bison.y"
    { (yyval.dec)=inicializadec(); 
			(*(yyval.dec)).decvar =(yyvsp[(1) - (1)].decvar); 
			(*(yyval.dec)).tipodec=MNG_DECVAR;
			//tbl=adicionaVar(tbl,$1.p_listnom,$1.tip); 
		//	verificasimbolos(tbl,$1.p_listnom);
		//	imprimirlista(tbl);	
			}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 125 "bison.y"
    {  (yyval.dec)=inicializadec(); 
			(*(yyval.dec)).decfunc =(yyvsp[(1) - (1)].decfunc);  
			(*(yyval.dec)).tipodec=MNG_DECFUNC;
		//	tbl=adicionaFunc(tbl,$1); 
		//	verificasimbolo(tbl,$1.id);
		//	imprimirlista(tbl);
		//imprimirlistaprog(arvore)
}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 135 "bison.y"
    { (yyval.decvar)=inicializadecvar((yyvsp[(1) - (3)].tip),(yyvsp[(2) - (3)].listnom));  }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 138 "bison.y"
    { (yyval.listnom)=inicializalistnom((yyvsp[(1) - (1)].id),NULL); 
					//verificaIDDuplicado(tbl, $1);
		}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 141 "bison.y"
    {  (yyval.listnom)=inicializalistnom((yyvsp[(1) - (3)].id),(yyvsp[(3) - (3)].listnom)); }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 145 "bison.y"
    { (yyval.tip)=inicializatipo(); (*(yyval.tip)).tipbase = (yyvsp[(1) - (1)].tipbase); (*(yyval.tip)).qtdACOL= 0;}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 146 "bison.y"
    { 
			(yyval.tip)=inicializatipo();
			(*(yyval.tip)).tipbase = (*(yyvsp[(1) - (3)].tip)).tipbase;			
			(*(yyval.tip)).qtdACOL =(*(yyvsp[(1) - (3)].tip)).qtdACOL+1;
			
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 155 "bison.y"
    {  (yyval.tipbase)=TIPO_INT;}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 156 "bison.y"
    { (yyval.tipbase)=TIPO_CHAR;}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 157 "bison.y"
    { (yyval.tipbase)=TIPO_FLOAT;}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 160 "bison.y"
    {(yyval.decfunc)=inicializadecfunc((yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].pars), (yyvsp[(6) - (6)].bloco));
							(*(yyval.decfunc)).tip = inicializatipo(); 
						(*(*(yyval.decfunc)).tip).tipbase = TIPO_VAZIO;
						//lista_simb* tblaux=adicionaVars(tblaux,$6);
						//verificasimbolosbloco(tblaux,$6);
						//tbl=adicionaFunc(tbl,$$,$4,tblaux);  
					//	imprimirlista(tblaux);
						//verificaIDDuplicado(tbl, $2);
						if ((yyvsp[(4) - (6)].pars) != NULL){
						(*(yyval.decfunc)).qtdPars = (*(yyvsp[(4) - (6)].pars)).qtdPars;}else (*(yyval.decfunc)).qtdPars =0;
				//		verificaReturn($6, (*$$).tip, $2);
						}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 172 "bison.y"
    {(yyval.decfunc)=inicializadecfunc((yyvsp[(2) - (6)].id), (yyvsp[(4) - (6)].pars), (yyvsp[(6) - (6)].bloco));
						(*(yyval.decfunc)).tip = inicializatipo();  
						(*(yyval.decfunc)).tip = (yyvsp[(1) - (6)].tip);
						if ((yyvsp[(4) - (6)].pars) != NULL) {
						(*(yyval.decfunc)).qtdPars = (*(yyvsp[(4) - (6)].pars)).qtdPars;} else (*(yyval.decfunc)).qtdPars =0;

						//lista_simb* tblaux1=adicionaVars(tblaux1,$6);
						//tbl=adicionaFunc(tbl,$$,$4,tblaux1);  
						//imprimirlista(tblaux1);
						//verificasimbolosbloco(tblaux1,$6);
			//			verificaIDDuplicado(tbl, $2);
//						verificaReturn($6, (*$$).tip, $2);       
}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 190 "bison.y"
    {(yyval.pars) = NULL; //(*$$).qtdPars = 0;
}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 192 "bison.y"
    {(yyval.pars) = inicializapars((yyvsp[(1) - (1)].par), NULL); (*(yyval.pars)).qtdPars =1;
}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 194 "bison.y"
    {(yyval.pars) = inicializapars((yyvsp[(1) - (3)].par), (yyvsp[(3) - (3)].pars)); if ((yyvsp[(3) - (3)].pars) != NULL){(*(yyval.pars)).qtdPars = (*(yyvsp[(3) - (3)].pars)).qtdPars +1;} else (*(yyval.pars)).qtdPars= 1;
}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 198 "bison.y"
    { (yyval.par) = inicializapar((yyvsp[(1) - (2)].tip), (yyvsp[(2) - (2)].id));}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 200 "bison.y"
    {(yyval.bloco) = inicializabloco((yyvsp[(2) - (4)].decvars), (yyvsp[(3) - (4)].cmds));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 203 "bison.y"
    { (yyval.decvars) = inicializadecvars((yyvsp[(1) - (2)].decvar),(yyvsp[(2) - (2)].decvars)); }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 204 "bison.y"
    {(yyval.decvars) = NULL;}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 207 "bison.y"
    {(yyval.cmds) = inicializacmds((yyvsp[(1) - (2)].cmd),(yyvsp[(2) - (2)].cmds)); (*(yyval.cmds)).cmd = (yyvsp[(1) - (2)].cmd);  (*(yyval.cmds)).cmds = (yyvsp[(2) - (2)].cmds);
			}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 209 "bison.y"
    {(yyval.cmds) = NULL;}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 212 "bison.y"
    {(yyval.cmd)= inicializacmd(MNG_IF); 
					(*(yyval.cmd)).decif.exp = (yyvsp[(3) - (6)].exp); 
					(*(yyval.cmd)).decif.cmd = (yyvsp[(5) - (6)].cmd); 
					(*(yyval.cmd)).decif.ptelse = (yyvsp[(6) - (6)].ptelse); (*(yyval.cmd)).linha=lineno;}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 216 "bison.y"
    {(yyval.cmd)= inicializacmd(MNG_WHILE); 
					(*(yyval.cmd)).decwhile.exp=(yyvsp[(3) - (5)].exp); 
					(*(yyval.cmd)).decwhile.cmd = (yyvsp[(5) - (5)].cmd);
					(*(yyval.cmd)).linha=lineno;}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 220 "bison.y"
    {(yyval.cmd)= inicializacmd(MNG_ATRIB);
				(*(yyval.cmd)).atrib= inicializaatrib((yyvsp[(1) - (4)].var),(yyvsp[(3) - (4)].exp));	
//				(*$$).atrib.var = $1; 
//				(*$$).atrib.exp = $3; 
				(*(yyval.cmd)).linha=lineno;
//				(*(*(*aux).atrib).exp).tipoexp == MNG_TIPEXP
			
				}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 228 "bison.y"
    {(yyval.cmd)= inicializacmd(MNG_RETURN); 
				(*(yyval.cmd)).ret.exp = (yyvsp[(2) - (3)].exp); 
				(*(yyval.cmd)).ret.tipret=RET_EXP; 
				(*(yyval.cmd)).linha=lineno; }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 232 "bison.y"
    {(yyval.cmd)= inicializacmd(MNG_RETURN); 
					(*(yyval.cmd)).ret.tipret=RET_VAZIO; (*(yyval.cmd)).linha=lineno;  }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 234 "bison.y"
    {(yyval.cmd)= inicializacmd(MNG_CHMET); (*(yyval.cmd)).chmet= (yyvsp[(1) - (2)].chmet);(*(yyval.cmd)).linha=lineno;}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 235 "bison.y"
    {(yyval.cmd)=inicializacmd(MNG_BLOCO); (*(yyval.cmd)).bloco = ((yyvsp[(1) - (1)].bloco));(*(yyval.cmd)).linha=lineno;
			}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 240 "bison.y"
    {(yyval.ptelse) = NULL;}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 241 "bison.y"
    {(yyval.ptelse) = inicializaptelse((yyvsp[(2) - (2)].cmd));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 244 "bison.y"
    { (yyval.var) = inicializavar(NULL); (*(yyval.var)).tip = inicializatipo(); (*(yyval.var)).id = (yyvsp[(1) - (1)].id); (*(yyval.var)).qtdACOL=0; (*(yyval.var)).var = NULL;}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 245 "bison.y"
    {
		(*(yyval.var)).var= (yyvsp[(1) - (4)].var);
		(yyval.var)=inicializavar((yyvsp[(3) - (4)].exp)); 
		(*(yyval.var)).id=(*(yyvsp[(1) - (4)].var)).id; 
		(*(yyval.var)).tip = inicializatipo();  
		(*(yyval.var)).qtdACOL=(*(yyvsp[(1) - (4)].var)).qtdACOL+1;
		}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 259 "bison.y"
    { (yyval.exp)=inicializaexp(MNG_TIPBASE);  
				(*(yyval.exp)).tipo = inicializatipo();		  
		(*(*(yyval.exp)).tipo).tipbase =TIPO_INT; 
		(*(yyval.exp)).numint=(yyvsp[(1) - (1)].numint);}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 263 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_TIPBASE); 
				(*(yyval.exp)).tipo = inicializatipo();	
		(*(*(yyval.exp)).tipo).tipbase=TIPO_FLOAT;
		(*(yyval.exp)).numfloat=(yyvsp[(1) - (1)].numfloat);   
		}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 268 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_TIPBASE);
			(*(yyval.exp)).tipo = inicializatipo(); 
			(*(*(yyval.exp)).tipo).tipbase= (yyvsp[(1) - (1)].string).tipo; 
			(*(yyval.exp)).string=(yyvsp[(1) - (1)].string); }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 272 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_VAR); 
		(*(yyval.exp)).var= (yyvsp[(1) - (1)].var); 
		(*(*(yyval.exp)).var).qtdACOL= (*(yyvsp[(1) - (1)].var)).qtdACOL; 
		}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 276 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_EXP); 
			(*(yyval.exp)).exp= (yyvsp[(2) - (3)].exp); 
			(*(yyval.exp)).tipo = inicializatipo();	
			(*(*(yyval.exp)).tipo).tipbase = (*(*(*(yyval.exp)).exp).tipo).tipbase;
			}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 281 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_CHMET); (*(yyval.exp)).chmet= (yyvsp[(1) - (1)].chmet);}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 282 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_TIPEXP); 
			(*(yyval.exp)).tipexp.tip = inicializatipo();
			(*(yyval.exp)).tipexp.tip = (yyvsp[(2) - (5)].tip);
			(*(*(yyval.exp)).tipexp.tip).qtdACOL = (*(yyvsp[(2) - (5)].tip)).qtdACOL +1;
			(*(yyval.exp)).tipexp.exp = (yyvsp[(4) - (5)].exp);
			
			}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 289 "bison.y"
    {
			(yyval.exp)=inicializaexp(MNG_TIPBASE); 
			(*(yyval.exp)).tipo = inicializatipo();
//			(*(*$$).tipo).tipbase = (*(*$2).tipo).tipbase; 
	//		((*(*$2).tipo).tipbase==TIPO_INT)?((*$$).numint.valor=(-1 * (*$2).numint.valor)):((*$$).numfloat.valor=(-1*(*$2).numfloat.valor)); 
		  }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 295 "bison.y"
    {
			(yyval.exp)=inicializaexp(MNG_OP);
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_SOMA,(yyvsp[(3) - (3)].exp)); 
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo = inicializatipo();
		
			//(*(*$$).tipo).tipbase=verificatipoexpOP($1,$3);
			}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 304 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_SUB,(yyvsp[(3) - (3)].exp));  
			(*(*(yyval.exp)).op).linha = lineno;
(*(yyval.exp)).tipo = inicializatipo();
	//		(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 310 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_MULT,(yyvsp[(3) - (3)].exp));  
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo = inicializatipo();
			int tamanho= sizeof(mng_tipbase);
			(*(*(yyval.exp)).tipo).tipbase = (mng_tipbase) malloc(tamanho);
	
 			(*(*(yyval.exp)).tipo).tipbase = TIPO_CHAR;
			//(*(*$$).tipo).tipbase=verificatipoexpOP($1,$3);
			}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 320 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_DIV,(yyvsp[(3) - (3)].exp));  
			(*(*(yyval.exp)).op).linha = lineno;

			(*(yyval.exp)).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 327 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_IGUAL,(yyvsp[(3) - (3)].exp));
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 333 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_MENORIG,(yyvsp[(3) - (3)].exp)); 
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 339 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_MAIORIG,(yyvsp[(3) - (3)].exp));  
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 345 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_MENORQ,(yyvsp[(3) - (3)].exp));  
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 351 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_MAIORQ,(yyvsp[(3) - (3)].exp)); 
			(*(*(yyval.exp)).op).linha = lineno; 
			(*(yyval.exp)).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 357 "bison.y"
    {	(yyval.exp)=inicializaexp(MNG_NAO); 
			(*(yyval.exp)).nao.op = OP_NAO; 
			(*(yyval.exp)).nao.exp = (yyvsp[(2) - (2)].exp); 
			(*(yyval.exp)).tipo= inicializatipo();
		//	(*(*$$).tipo).tipbase = (*(*$2).tipo).tipbase;
		}
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 363 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_E,(yyvsp[(3) - (3)].exp)); 
//			(*(*$$).op).exp1= $1; 
//			(*(*$$).op).op= OP_E; 
//			(*(*$$).op).exp2 = $3;
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo= inicializatipo();
			//(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
			}
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 372 "bison.y"
    {(yyval.exp)=inicializaexp(MNG_OP); 
			(*(yyval.exp)).op=inicializaop((yyvsp[(1) - (3)].exp),OP_OU,(yyvsp[(3) - (3)].exp));
			//(*(*$$).op).exp1= $1; 
			//(*(*$$).op).op= OP_OU; 
			//(*(*$$).op).exp2 = $3;
			(*(*(yyval.exp)).op).linha = lineno;
			(*(yyval.exp)).tipo= inicializatipo();
//			(*(*$$).tipo).tipbase=verificatipoexpOP((*$$).op);
}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 383 "bison.y"
    {(yyval.chmet) = inicializachmet((yyvsp[(1) - (4)].id),(yyvsp[(3) - (4)].listexp));}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 386 "bison.y"
    {(yyval.listexp) = NULL;// (*$$).qtdPars = 0;
}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 388 "bison.y"
    {(yyval.listexp) = inicializalistexp((yyvsp[(1) - (1)].exp), NULL); (*(yyval.listexp)).qtdPars = 1;
}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 390 "bison.y"
    {(yyval.listexp) = inicializalistexp((yyvsp[(1) - (3)].exp), (yyvsp[(3) - (3)].listexp)); (*(yyval.listexp)).qtdPars = (*(yyvsp[(3) - (3)].listexp)).qtdPars +1;
}
    break;



/* Line 1806 of yacc.c  */
#line 2161 "sint.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 2067 of yacc.c  */
#line 394 "bison.y"


void yyerror(const char* errmsg)
{
	printf("\n***Linha %d: Erro: %s\n", lineno, errmsg);
}

//int yywrap() { return 1; }
	


 
int main(int argc, char** argv){
	extern yydebug;
	yydebug=1;
    yyparse();
//	printf("\n==========================================================================================================================\n");
	PercorreArvore(arvore,NULL);
	//printf("acabou o/");
//	printf("arvore: %d \n",(*arvore).teste);
//	mng_prg p = 	(*arvore).prog;
//	printf("arvore2: %d \n",(*arvore).prog.teste);
//	printprg(arvore);
     return 0;
}


