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
#line 1 "parser.y" /* yacc.c:339  */

	#include<stdio.h>
	#include<string.h>
	int parseflag = 0, validfuncflag = 0;
	int nestval = 0;
	int paracount = 0, argcount = 0; 
	char currfunc[100], currfunctype[100];
	char paratypes[100], argtypes[100], exprtype[100];
	
	int linenum();
	char* getcurrid();
	char* getcurrtype();
	char* getprevid();
	void checkfunduplicate(char *s);
	char* getprevtype();
	void yyerror(char *s);
	int hash(char *s);
	void insert(char* name, char* type, int flag, int nest, int numofpara, char* paratypes);
	void deletedata(int nest);
	void print();
	int checkscope(char* name);
	void isduplicate(char* name, int nest);
	void checkfuncargs(char* name, int numofargs, char* types);
	char getfirst(char* s);
	char gettype(char* name, int flag);

#line 93 "y.tab.c" /* yacc.c:339  */

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    CHAR = 259,
    VOID = 260,
    FOR = 261,
    WHILE = 262,
    IF = 263,
    ELSE = 264,
    BREAK = 265,
    RETURN = 266,
    CONTINUE = 267,
    ID = 268,
    STRING = 269,
    LITERAL = 270,
    NUM = 271,
    INCLUDE = 272,
    EQ = 273,
    PEQ = 274,
    MEQ = 275,
    MUEQ = 276,
    DEQ = 277,
    BOR = 278,
    BXOR = 279,
    BAND = 280,
    AND = 281,
    OR = 282,
    EQEQ = 283,
    NEQ = 284,
    LT = 285,
    GT = 286,
    LE = 287,
    GE = 288,
    PLUS = 289,
    MINUS = 290,
    DIV = 291,
    MULT = 292,
    MOD = 293,
    INC = 294,
    DEC = 295
  };
#endif
/* Tokens.  */
#define INT 258
#define CHAR 259
#define VOID 260
#define FOR 261
#define WHILE 262
#define IF 263
#define ELSE 264
#define BREAK 265
#define RETURN 266
#define CONTINUE 267
#define ID 268
#define STRING 269
#define LITERAL 270
#define NUM 271
#define INCLUDE 272
#define EQ 273
#define PEQ 274
#define MEQ 275
#define MUEQ 276
#define DEQ 277
#define BOR 278
#define BXOR 279
#define BAND 280
#define AND 281
#define OR 282
#define EQEQ 283
#define NEQ 284
#define LT 285
#define GT 286
#define LE 287
#define GE 288
#define PLUS 289
#define MINUS 290
#define DIV 291
#define MULT 292
#define MOD 293
#define INC 294
#define DEC 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 221 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,     2,     2,    46,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    42,    42,    43,    46,    47,    48,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    64,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    95,    96,    97,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   107,
     108,   111,   111,   114,   115,   118,   118,   119,   122,   123,
     124,   125,   126,   129,   132,   132,   133,   136,   136,   137,
     137,   140,   140,   140,   141,   141,   144,   145,   148,   149,
     153,   154,   155,   156,   159,   160
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "CHAR", "VOID", "FOR", "WHILE",
  "IF", "ELSE", "BREAK", "RETURN", "CONTINUE", "ID", "STRING", "LITERAL",
  "NUM", "INCLUDE", "EQ", "PEQ", "MEQ", "MUEQ", "DEQ", "BOR", "BXOR",
  "BAND", "AND", "OR", "EQEQ", "NEQ", "LT", "GT", "LE", "GE", "PLUS",
  "MINUS", "DIV", "MULT", "MOD", "INC", "DEC", "';'", "'('", "')'", "'{'",
  "'}'", "','", "$accept", "start", "type", "stmt", "expr", "expr1",
  "assignment", "$@1", "$@2", "$@3", "$@4", "$@5", "declaration",
  "stmtblock", "$@6", "stmtlist", "argumentlist", "$@7", "argument",
  "parameter", "paramlist", "$@8", "funccall", "$@9", "$@10", "funcdef",
  "$@11", "$@12", "$@13", "whileloop", "forloop", "ifstmt", "elsestmt", YY_NULLPTR
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
     295,    59,    40,    41,   123,   125,    44
};
# endif

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -85

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   163,    15,  -122,  -122,  -122,   -25,   -22,   -11,     0,
       3,    21,    96,  -122,  -122,    56,    56,    56,  -122,    56,
    -122,    19,   178,   270,    22,    23,  -122,    26,  -122,  -122,
    -122,  -122,  -122,    71,    56,    56,  -122,    -2,  -122,   289,
    -122,  -122,    27,    55,    66,    54,    67,    53,    64,   -17,
     -17,   207,   187,  -122,  -122,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,  -122,  -122,  -122,  -122,  -122,  -122,   308,    49,  -122,
     228,   249,  -122,    14,    50,    56,    56,    56,    56,    56,
    -122,    51,   113,   113,   113,   113,   113,   319,   319,   326,
     326,   326,   326,    64,    64,   -17,   -17,   -17,    71,   121,
     121,  -122,  -122,  -122,  -122,    79,    62,    61,  -122,   308,
     308,   308,   308,   308,     8,    69,    78,  -122,  -122,  -122,
      88,    88,  -122,  -122,  -122,   108,    77,    92,   110,    71,
     178,   121,  -122,  -122,    14,  -122,  -122,  -122,  -122,   114,
     119,  -122,  -122,  -122,     8,   110,   121,  -122,  -122,  -122,
    -122,  -122
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     4,     5,     6,     0,     0,     0,     0,
       0,     0,    42,    44,    43,     0,     0,     0,    14,     0,
       2,     0,    64,     0,     0,     0,     3,    45,     7,    10,
       9,     8,     1,    48,     0,     0,    17,    42,    15,     0,
      45,    16,    77,     0,     0,     0,     0,     0,    36,    37,
      38,     0,    49,    60,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    13,    12,    11,    19,    46,     0,    47,
       0,     0,    18,     0,     0,     0,     0,     0,     0,     0,
      41,    81,    22,    23,    24,    21,    20,    25,    26,    29,
      30,    27,    28,    31,    32,    35,    33,    34,    48,     0,
       0,    69,    72,    70,    71,     0,     0,    67,    80,    50,
      52,    54,    56,    58,     0,     0,     0,    61,    87,    86,
      93,    92,    68,    78,    65,     0,    76,     0,     0,    48,
       0,     0,    91,    90,     0,    73,    74,    82,    85,     0,
       0,    95,    94,    66,     0,     0,     0,    62,    75,    83,
      89,    88
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,   157,  -121,   -75,    -9,  -103,   -19,  -122,  -122,  -122,
    -122,  -122,  -122,   -73,  -122,   -18,    28,  -122,  -122,  -122,
       5,  -122,    -1,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,    46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    21,    22,    23,    78,    24,    43,    44,    45,
      46,    47,    25,   129,   140,    26,   116,   144,   117,   136,
     137,   154,    40,    83,    84,    28,   124,   155,   125,    29,
      30,    31,   142
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      27,    39,    53,   135,    54,   126,    48,    49,    50,     1,
      51,     3,     4,     5,    79,    32,    37,    33,    13,    14,
      34,    27,    71,    72,    77,    80,    81,   111,   112,   113,
     114,    35,    52,   135,   128,   130,   149,   131,    15,   115,
      42,    36,    16,    17,    38,    19,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    41,    74,    75,   148,   151,    76,   152,    37,
     -79,    13,    14,    85,    87,    89,   119,   120,   121,   122,
     123,   160,   159,   161,    12,    86,    13,    14,    88,    79,
     108,    15,   132,   118,   -84,    16,    17,   141,    19,    77,
      68,    69,    70,    71,    72,   133,    15,   134,    27,    27,
      16,    17,   138,    19,   -49,   -51,   -53,   -55,   -57,   139,
      79,   145,   150,   146,     3,     4,     5,     6,     7,     8,
      77,     9,    10,    11,    12,   147,    13,    14,    42,    27,
      27,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   127,    27,    15,   156,    20,   158,
      16,    17,    18,    19,   157,   127,     3,     4,     5,     6,
       7,     8,   153,     9,    10,    11,    12,   143,    13,    14,
       1,     3,     4,     5,     6,     7,     8,     0,     9,    10,
      11,    12,     0,    13,    14,     0,     0,     0,    15,     0,
       0,     0,    16,    17,    18,    19,   -51,   -53,   -55,   -57,
       0,     0,     0,    15,     0,     0,     0,    16,    17,    18,
      19,     0,     0,     0,     0,     0,     0,     0,   -59,    91,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
      90,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,   109,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,   110,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      82,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      66,    67,    68,    69,    70,    71,    72
};

static const yytype_int16 yycheck[] =
{
       1,    10,    21,   124,    22,   108,    15,    16,    17,    17,
      19,     3,     4,     5,    33,     0,    13,    42,    15,    16,
      42,    22,    39,    40,    33,    34,    35,    13,    14,    15,
      16,    42,    13,   154,   109,   110,   139,   110,    35,    25,
      42,    41,    39,    40,    41,    42,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    41,    41,    41,   138,   141,    41,   141,    13,
      43,    15,    16,    18,    20,    22,    85,    86,    87,    88,
      89,   156,   155,   156,    13,    19,    15,    16,    21,   108,
      41,    35,    13,    43,    43,    39,    40,     9,    42,   108,
      36,    37,    38,    39,    40,    43,    35,    46,   109,   110,
      39,    40,    43,    42,    18,    19,    20,    21,    22,    41,
     139,    13,   140,    46,     3,     4,     5,     6,     7,     8,
     139,    10,    11,    12,    13,    43,    15,    16,    42,   140,
     141,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    44,   156,    35,    43,     1,   154,
      39,    40,    41,    42,    45,    44,     3,     4,     5,     6,
       7,     8,   144,    10,    11,    12,    13,   131,    15,    16,
      17,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    -1,    15,    16,    -1,    -1,    -1,    35,    -1,
      -1,    -1,    39,    40,    41,    42,    19,    20,    21,    22,
      -1,    -1,    -1,    35,    -1,    -1,    -1,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      43,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    43,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    43,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      34,    35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    48,     3,     4,     5,     6,     7,     8,    10,
      11,    12,    13,    15,    16,    35,    39,    40,    41,    42,
      48,    49,    50,    51,    53,    59,    62,    69,    72,    76,
      77,    78,     0,    42,    42,    42,    41,    13,    41,    51,
      69,    41,    42,    54,    55,    56,    57,    58,    51,    51,
      51,    51,    13,    53,    62,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    41,    41,    41,    51,    52,    53,
      51,    51,    41,    70,    71,    18,    19,    20,    21,    22,
      43,    42,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    41,    43,
      43,    13,    14,    15,    16,    25,    63,    65,    43,    51,
      51,    51,    51,    51,    73,    75,    52,    44,    50,    60,
      50,    60,    13,    43,    46,    49,    66,    67,    43,    41,
      61,     9,    79,    79,    64,    13,    46,    43,    60,    52,
      62,    50,    60,    63,    68,    74,    43,    45,    67,    60,
      50,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    48,    49,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    52,    52,    52,    54,
      53,    55,    53,    56,    53,    57,    53,    58,    53,    59,
      59,    61,    60,    62,    62,    64,    63,    63,    65,    65,
      65,    65,    65,    66,    68,    67,    67,    70,    69,    71,
      69,    73,    74,    72,    75,    72,    76,    76,    77,    77,
      78,    78,    78,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     1,     2,     2,     2,     3,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     0,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     2,
       2,     0,     4,     2,     1,     0,     4,     1,     2,     1,
       1,     1,     1,     2,     0,     4,     1,     0,     5,     0,
       4,     0,     0,     8,     0,     6,     5,     5,     9,     9,
       6,     6,     5,     5,     2,     2
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
        case 15:
#line 59 "parser.y" /* yacc.c:1646  */
    {if(!strcmp(currfunctype, "void")) printf("%d - Return type is not VOID\n", linenum());}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 62 "parser.y" /* yacc.c:1646  */
    {if(!strcmp(currfunctype, "void")) printf("%d - Return type is VOID but returns non void expression\n", linenum()); 
												else if((yyval) == -1) printf("%d - Expression doesn't match return type of function\n", linenum());}
#line 1462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 67 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 68 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 69 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 70 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 71 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 72 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 73 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 74 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 75 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 76 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 77 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 78 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 79 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 80 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1546 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 81 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 82 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-2])==1 && (yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 83 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1564 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 84 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 85 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[0])==1)(yyval)=1; else (yyval)=-1;}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 86 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1])==1)(yyval)=1; else (yyval)=-1;}
#line 1582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 87 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1])==1)(yyval)=1; else (yyval)=-1;}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 88 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1])==1)(yyval)=1; else (yyval)=-1;}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 89 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid()); if(gettype(getcurrid(), 0)=='i' || gettype(getcurrid(), 1)== 'c') (yyval) = 1; else (yyval) = -1;}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval)=1;}
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval)=1;}
#line 1612 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 92 "parser.y" /* yacc.c:1646  */
    {if(gettype(getcurrid(), 0)=='i' || gettype(getcurrid(), 1)== 'c') (yyval) = 1; else (yyval) = -1;}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 100 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid());}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 101 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid());}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 102 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid());}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 103 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid());}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 104 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid());}
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 107 "parser.y" /* yacc.c:1646  */
    {isduplicate(getcurrid(), nestval); insert(getcurrid(), getcurrtype(), 0, nestval, paracount, paratypes);}
#line 1654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 111 "parser.y" /* yacc.c:1646  */
    {nestval++;}
#line 1660 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 111 "parser.y" /* yacc.c:1646  */
    {deletedata(nestval); nestval--;}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 118 "parser.y" /* yacc.c:1646  */
    {argcount++;}
#line 1672 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 119 "parser.y" /* yacc.c:1646  */
    {argcount++;}
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 122 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid());}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 123 "parser.y" /* yacc.c:1646  */
    {argtypes[argcount] = getfirst(getcurrtype());}
#line 1690 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 124 "parser.y" /* yacc.c:1646  */
    {argtypes[argcount] = 'c';}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 125 "parser.y" /* yacc.c:1646  */
    {argtypes[argcount] = 'i';}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 126 "parser.y" /* yacc.c:1646  */
    {argtypes[argcount] = 'c';}
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 129 "parser.y" /* yacc.c:1646  */
    {paratypes[paracount] = getfirst(getcurrtype()); insert(getcurrid(), getcurrtype(), 0, nestval, paracount, paratypes);}
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 132 "parser.y" /* yacc.c:1646  */
    {paracount++;}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 133 "parser.y" /* yacc.c:1646  */
    {paracount++;}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 136 "parser.y" /* yacc.c:1646  */
    {strcpy(currfunc, getprevid());}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 136 "parser.y" /* yacc.c:1646  */
    {checkfuncargs(currfunc, argcount, argtypes); strcpy(argtypes, " "); argcount = 0;}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 137 "parser.y" /* yacc.c:1646  */
    {checkscope(getcurrid());}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 137 "parser.y" /* yacc.c:1646  */
    {checkfuncargs(getcurrid(), argcount, argtypes); strcpy(argtypes, " "); argcount = 0;}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 140 "parser.y" /* yacc.c:1646  */
    {strcpy(currfunc, getcurrid());checkfunduplicate(getcurrid());strcpy(currfunctype, getprevtype()); nestval++;}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 140 "parser.y" /* yacc.c:1646  */
    {insert(currfunc, currfunctype, 1, nestval-1, paracount, paratypes); paracount = 0; strcpy(paratypes, " ");}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 140 "parser.y" /* yacc.c:1646  */
    {deletedata(nestval); nestval--;}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 141 "parser.y" /* yacc.c:1646  */
    {insert(getcurrid(), getcurrtype(), 1, nestval, paracount, paratypes); paracount = 0; strcpy(paratypes, " "); nestval++;}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 141 "parser.y" /* yacc.c:1646  */
    {deletedata(nestval); nestval--;}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1784 "y.tab.c" /* yacc.c:1646  */
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
#line 163 "parser.y" /* yacc.c:1906  */

#include"lex.yy.c"

int linenum()
{
	return line;
}

char* getcurrid()
{
	return currid;
}

char* getcurrtype()
{
	return currtype;
}

char* getprevid()
{
	return previd;
}

char* getprevtype()
{ 
	return prevtype;
}

void yyerror(char *s)
{
	parseflag = 1;
	printf("%d - %s: %s\n", linenum(), yytext, s);
}

int hash(char *s)
{
	int mod = 1001;
	int l = strlen(s), val = 0, i;
	for (i=0;i<l;i++)
	{
		val = val * 10 + (s[i] - 'A');
		val = val%mod;
		while(val<0)
			val += mod;
	}
	return val;
}

void insert(char* name, char* type, int flag, int nest, int numofpara, char* paratypes)
{
	int l1 = strlen(name);
	int l2 = strlen(type);
	int v = hash(name);
	if (table[v].len == 0)
	{
		strcpy(table[v].symbol, name);
		strcpy(table[v].type, type);
		table[v].isfunc = flag;
		table[v].nesting = nest;
		table[v].len = l1;
		table[v].numofpara = numofpara;
		strcpy(table[v].paratypes, paratypes);
		return;
	}
	
	if (strcmp(table[v].symbol, name) == 0)
		return ;
		
	int i, pos = 0;
	
	for (i=0;i<1001;i++)
	{
		if (table[i].len==0)
		{
			pos = i;
			break;
		}
	}
	
	strcpy(table[pos].symbol, name);
	strcpy(table[pos].type, type);
	table[pos].isfunc = flag;
	table[pos].nesting = nest;
	table[pos].len = l1;
	table[pos].numofpara = numofpara;
	strcpy(table[pos].paratypes, paratypes);
}

void deletedata(int nestval)
	{
	int i;
	for (i=0;i<1001;i++)
	{
		if (table[i].nesting == nestval)
		{
			table[i].len = 0;
			strcpy(table[i].symbol, "");
			strcpy(table[i].value, "");
			table[i].isfunc = -1;
			table[i].nesting = -1;
			table[i].numofpara = 0;
			strcpy(table[i].paratypes, "");
		}
	}
}

void print()
{
	int i = 0;
	for (i=0;i<1001;i++)
	{
		if (table[i].len == 0)
			continue;
		printf("%s - %s - %d - %d - %s\n", table[i].symbol, table[i].type, table[i].isfunc, table[i].numofpara, table[i].paratypes);
	}
}

int checkscope(char *s)
{
    int i, flag = 0;
    for (i=0;i<1001;i++)
    {
        if(strcmp(table[i].symbol, s) == 0)
        {
            if(table[i].nesting <= nestval)
            {
                flag = 1;
                break;
            }
        }
    }

    if(!flag)
        printf("%d - Undeclared variable %s\n", linenum(), s);
    return flag;
}

void isduplicate(char *s, int nest)
{
	int val = hash(s);
	if (strcmp(table[val].symbol, s) == 0 && table[val].nesting == nest)
	{
		printf("%d - Duplicate declaration of %s\n", linenum(), s);
		return;
	}
	int i;
	for (i=0;i<1002;i++)
	{
		if (strcmp(table[i].symbol, s) == 0 && table[i].nesting == nest)
		{
			printf("%d - Duplicate declaration of %s\n", linenum(), s);
			return;
		}
	}
}

void checkfuncargs(char *name, int numofargs, char *types)
{
	if (checkscope(currfunc) == 0)
		return;
	int i;
	validfuncflag = 0;

    for (i=0;i<1001;i++)
    {
        if(strcmp(table[i].symbol, name) == 0)
        {
            if(table[i].isfunc == 1 && strcmp(table[i].paratypes, types) == 0)
            {
                validfuncflag = 1;
                break;
            }
        }
    }

    if(!validfuncflag)
        printf("%d - Argument mismatch for %s\n", linenum(), name);
}

char getfirst(char*s)
{
	if (strcmp(s, "int") == 0)
		return 'i';
	else if (strcmp(s, "char") == 0)
		return 'c';
	else if (strcmp(s, "void") == 0)
		return 'v';
}

void checkfunduplicate(char *s){

	int flag=0,i;

	for (i=0;i<1001;i++){
		if(strcmp(table[i].symbol,s)==0){
			flag=1;
			printf("Duplicate Function Declaration of %s on line %d\n",s,line);
		}
	}

}

char gettype(char *name, int flag)
{
	if (flag == 1 && validfuncflag == 1)
	{
		int i;
		for (i=0;i<1001;i++){
			if(strcmp(table[i].symbol,name)==0){
				return (table[i].type[0]);
			}
		}
	}
	else if (flag == 0)
	{
		int i;
		for (i=0;i<1001;i++){
			if(strcmp(table[i].symbol,name)==0){
				return (table[i].type[0]);
			}
		}
	}
}

int main()
{
	yyin = fopen("test-2.c", "r");
	yyparse();
	if (!parseflag)
		printf("Parsing successful\n");
	
	print();
}
	
