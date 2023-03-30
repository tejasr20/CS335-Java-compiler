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
     ABSTRACT = 258,
     ASSERT = 259,
     BOOLEAN = 260,
     BREAK = 261,
     BYTE = 262,
     CASE = 263,
     CATCH = 264,
     CHAR = 265,
     CLASS = 266,
     COMMENT = 267,
     CONST = 268,
     CONTINUE = 269,
     DEFAULT = 270,
     DO = 271,
     DOUBLE = 272,
     ELSE = 273,
     ENUM = 274,
     ERROR = 275,
     EXTENDS = 276,
     FINALLY = 277,
     FINAL = 278,
     FLOAT = 279,
     FOR = 280,
     IDENTIFIER = 281,
     IF = 282,
     GOTO = 283,
     IMPLEMENTS = 284,
     IMPORT = 285,
     INSTANCEOF = 286,
     INT = 287,
     INTERFACE = 288,
     LITERAL = 289,
     LONG = 290,
     NATIVE = 291,
     NEW = 292,
     PACKAGE = 293,
     PRIVATE = 294,
     PROTECTED = 295,
     PUBLIC = 296,
     RETURN = 297,
     SHORT = 298,
     STATIC = 299,
     STRICTFP = 300,
     SUPER = 301,
     SWITCH = 302,
     SYNCHRONIZED = 303,
     THIS = 304,
     THROWS = 305,
     THROW = 306,
     TRANSIENT = 307,
     TRY = 308,
     VOID = 309,
     VOLATILE = 310,
     WHILE = 311,
     EQUALS = 312,
     GT = 313,
     LT = 314,
     NT = 315,
     TILDA = 316,
     QUESTION_MARK = 317,
     COLON = 318,
     ARROW = 319,
     EQEQ = 320,
     GREQ = 321,
     LEQ = 322,
     NEQUALS = 323,
     PLUSPLUS = 324,
     MINUSMINUS = 325,
     OR = 326,
     AND = 327,
     ADD = 328,
     SUBTRACT = 329,
     MULTIPLY = 330,
     DIVISION = 331,
     BINARYOR = 332,
     BINARYAND = 333,
     POW = 334,
     MOD = 335,
     GRGR = 336,
     LTLT = 337,
     GRGRGR = 338,
     PLEQ = 339,
     SBEQ = 340,
     MULEQ = 341,
     ANDEQ = 342,
     OREQ = 343,
     POWEQ = 344,
     DIVEQ = 345,
     MODEQ = 346,
     DGRGR = 347,
     DLRLR = 348,
     TGRGRGR = 349,
     OC = 350,
     CC = 351,
     OSQ = 352,
     CSQ = 353,
     OS = 354,
     CS = 355,
     COMMA = 356,
     DISTO = 357,
     ATR = 358,
     TDT = 359,
     FST = 360,
     SCLN = 361,
     DST = 362
   };
#endif
/* Tokens.  */
#define ABSTRACT 258
#define ASSERT 259
#define BOOLEAN 260
#define BREAK 261
#define BYTE 262
#define CASE 263
#define CATCH 264
#define CHAR 265
#define CLASS 266
#define COMMENT 267
#define CONST 268
#define CONTINUE 269
#define DEFAULT 270
#define DO 271
#define DOUBLE 272
#define ELSE 273
#define ENUM 274
#define ERROR 275
#define EXTENDS 276
#define FINALLY 277
#define FINAL 278
#define FLOAT 279
#define FOR 280
#define IDENTIFIER 281
#define IF 282
#define GOTO 283
#define IMPLEMENTS 284
#define IMPORT 285
#define INSTANCEOF 286
#define INT 287
#define INTERFACE 288
#define LITERAL 289
#define LONG 290
#define NATIVE 291
#define NEW 292
#define PACKAGE 293
#define PRIVATE 294
#define PROTECTED 295
#define PUBLIC 296
#define RETURN 297
#define SHORT 298
#define STATIC 299
#define STRICTFP 300
#define SUPER 301
#define SWITCH 302
#define SYNCHRONIZED 303
#define THIS 304
#define THROWS 305
#define THROW 306
#define TRANSIENT 307
#define TRY 308
#define VOID 309
#define VOLATILE 310
#define WHILE 311
#define EQUALS 312
#define GT 313
#define LT 314
#define NT 315
#define TILDA 316
#define QUESTION_MARK 317
#define COLON 318
#define ARROW 319
#define EQEQ 320
#define GREQ 321
#define LEQ 322
#define NEQUALS 323
#define PLUSPLUS 324
#define MINUSMINUS 325
#define OR 326
#define AND 327
#define ADD 328
#define SUBTRACT 329
#define MULTIPLY 330
#define DIVISION 331
#define BINARYOR 332
#define BINARYAND 333
#define POW 334
#define MOD 335
#define GRGR 336
#define LTLT 337
#define GRGRGR 338
#define PLEQ 339
#define SBEQ 340
#define MULEQ 341
#define ANDEQ 342
#define OREQ 343
#define POWEQ 344
#define DIVEQ 345
#define MODEQ 346
#define DGRGR 347
#define DLRLR 348
#define TGRGRGR 349
#define OC 350
#define CC 351
#define OSQ 352
#define CSQ 353
#define OS 354
#define CS 355
#define COMMA 356
#define DISTO 357
#define ATR 358
#define TDT 359
#define FST 360
#define SCLN 361
#define DST 362




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

// #include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "tree.h"

using namespace std;
extern int yylineno;
extern FILE* yyin;
FILE* fp;
extern char* yytext;
extern int column;
int yyerror(const char*);
extern int yylex();
extern int yyparse();
bool verbose= false;
FILE* dotfile;
char* file;

extern int yyrestart(FILE*);
extern FILE* yyin;
#define YYERROR_VERBOSE


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
#line 28 "parser.y"
{
	char* str;
	int number;
	Node* ptr;
}
/* Line 193 of yacc.c.  */
#line 343 "parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 356 "parser.cpp"

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3155

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  138
/* YYNRULES -- Number of rules.  */
#define YYNRULES  345
/* YYNRULES -- Number of states.  */
#define YYNSTATES  614

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   362

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
       2,     2,     2,     2,     2,     2,     2,     2,     2,   108,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    27,    29,    31,    33,    35,    37,
      39,    41,    43,    47,    51,    55,    57,    59,    61,    65,
      69,    71,    74,    76,    78,    81,    84,    86,    89,    91,
      94,    98,   100,   102,   106,   111,   113,   115,   117,   119,
     122,   124,   126,   128,   130,   132,   134,   136,   138,   140,
     142,   149,   154,   160,   165,   170,   174,   180,   186,   189,
     192,   194,   198,   201,   205,   207,   210,   212,   214,   216,
     218,   220,   225,   229,   231,   235,   237,   241,   243,   247,
     249,   251,   254,   259,   263,   266,   271,   275,   279,   282,
     286,   291,   295,   299,   301,   305,   308,   311,   313,   317,
     319,   321,   324,   329,   333,   336,   340,   345,   349,   354,
     357,   361,   365,   371,   376,   382,   387,   393,   398,   402,
     407,   410,   414,   417,   421,   423,   426,   428,   430,   432,
     435,   440,   444,   447,   451,   455,   457,   461,   464,   467,
     469,   471,   473,   476,   479,   481,   483,   485,   487,   489,
     491,   493,   495,   497,   499,   501,   503,   505,   507,   509,
     511,   513,   515,   517,   519,   521,   523,   525,   529,   533,
     536,   538,   540,   542,   544,   546,   548,   550,   556,   564,
     572,   578,   583,   586,   590,   594,   596,   599,   601,   604,
     607,   611,   614,   620,   626,   634,   636,   638,   648,   657,
     665,   673,   680,   689,   698,   706,   716,   725,   734,   742,
     751,   759,   767,   774,   776,   778,   780,   784,   786,   790,
     793,   797,   800,   803,   807,   811,   817,   821,   825,   830,
     833,   835,   841,   844,   846,   848,   850,   854,   856,   858,
     860,   862,   864,   870,   875,   877,   881,   885,   889,   894,
     899,   904,   908,   915,   921,   928,   934,   939,   943,   948,
     952,   955,   957,   961,   964,   968,   970,   972,   974,   978,
     980,   982,   984,   986,   988,   990,   992,   994,   996,   998,
    1000,  1002,  1004,  1006,  1008,  1010,  1016,  1018,  1022,  1024,
    1028,  1030,  1034,  1036,  1040,  1042,  1046,  1048,  1052,  1056,
    1058,  1062,  1066,  1070,  1074,  1078,  1080,  1084,  1086,  1090,
    1094,  1096,  1100,  1104,  1108,  1110,  1112,  1115,  1118,  1120,
    1123,  1126,  1128,  1131,  1134,  1136,  1138,  1140,  1142,  1144,
    1147,  1150,  1156,  1161,  1166,  1172
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     125,     0,    -1,    34,    -1,    26,    -1,   113,    -1,   115,
      -1,   121,    -1,   114,    -1,   122,    -1,   116,    -1,     5,
      -1,   118,    -1,   117,    -1,    35,    -1,     7,    -1,    32,
      -1,    10,    -1,    43,    -1,    17,    -1,    24,    -1,   114,
      -1,   114,    -1,   115,    97,    98,    -1,   121,    97,    98,
      -1,   122,    97,    98,    -1,   124,    -1,   123,    -1,   111,
      -1,   122,   105,   111,    -1,   128,   126,   127,    -1,   127,
      -1,   128,   126,    -1,   126,    -1,   128,    -1,   126,   127,
      -1,   128,   127,    -1,   129,    -1,   126,   129,    -1,   132,
      -1,   127,   132,    -1,    38,   122,   106,    -1,   131,    -1,
     130,    -1,    30,   122,   106,    -1,    30,   122,   107,   106,
      -1,   161,    -1,   106,    -1,   135,    -1,   134,    -1,   133,
     134,    -1,    23,    -1,    39,    -1,    40,    -1,    36,    -1,
      48,    -1,    44,    -1,    41,    -1,    52,    -1,     3,    -1,
      55,    -1,   133,    11,   111,   136,   137,   139,    -1,    11,
     111,   137,   139,    -1,   133,    11,   111,   136,   139,    -1,
      11,   111,   136,   139,    -1,   133,    11,   111,   139,    -1,
      11,   111,   139,    -1,    11,   111,   136,   137,   139,    -1,
     133,    11,   111,   137,   139,    -1,    21,   119,    -1,    29,
     138,    -1,   120,    -1,   138,   101,   120,    -1,    95,    96,
      -1,    95,   140,    96,    -1,   141,    -1,   140,   141,    -1,
     157,    -1,   156,    -1,   142,    -1,   148,    -1,   143,    -1,
     133,   112,   144,   106,    -1,   112,   144,   106,    -1,   145,
      -1,   144,   101,   145,    -1,   146,    -1,   146,    57,   147,
      -1,   111,    -1,   146,    97,    98,    -1,   222,    -1,   168,
      -1,   149,   155,    -1,   133,   112,   150,   153,    -1,   112,
     150,   153,    -1,   112,   150,    -1,   133,    54,   150,   153,
      -1,    54,   150,   153,    -1,   133,    54,   150,    -1,    54,
     150,    -1,   133,   112,   150,    -1,   111,    99,   151,   100,
      -1,   111,    99,   100,    -1,   150,    97,    97,    -1,   152,
      -1,   151,   101,   152,    -1,   112,   146,    -1,    50,   154,
      -1,   119,    -1,   154,   101,   119,    -1,   106,    -1,   170,
      -1,    44,   170,    -1,   133,   158,   153,   159,    -1,   133,
     158,   159,    -1,   158,   159,    -1,   158,   153,   159,    -1,
     123,    99,   151,   100,    -1,   123,    99,   100,    -1,    95,
     160,   171,    96,    -1,    95,    96,    -1,    95,   160,    96,
      -1,    95,   171,    96,    -1,    49,    99,   214,   100,   106,
      -1,    49,    99,   100,   106,    -1,    46,    99,   214,   100,
     106,    -1,    46,    99,   100,   106,    -1,   133,    33,   111,
     162,   163,    -1,   133,    33,   111,   163,    -1,    33,   111,
     163,    -1,    33,   111,   162,   163,    -1,    21,   120,    -1,
     162,   101,   120,    -1,    95,    96,    -1,    95,   164,    96,
      -1,   165,    -1,   164,   165,    -1,   166,    -1,   167,    -1,
     143,    -1,   149,   106,    -1,    95,   169,   101,    96,    -1,
      95,   169,    96,    -1,    95,    96,    -1,    95,   101,    96,
      -1,   169,   101,   147,    -1,   147,    -1,    95,   171,    96,
      -1,    95,    96,    -1,   171,   172,    -1,   172,    -1,   173,
      -1,   175,    -1,   174,   106,    -1,   112,   144,    -1,   192,
      -1,   177,    -1,   195,    -1,   179,    -1,   183,    -1,   184,
      -1,   193,    -1,   180,    -1,   177,    -1,   185,    -1,   196,
      -1,   207,    -1,   194,    -1,   202,    -1,   181,    -1,   205,
      -1,   186,    -1,   203,    -1,   170,    -1,   178,    -1,   204,
      -1,   206,    -1,   106,    -1,   111,    63,   175,    -1,   111,
      63,   176,    -1,   182,   106,    -1,   213,    -1,   244,    -1,
     240,    -1,   217,    -1,   243,    -1,   239,    -1,   224,    -1,
      27,    99,   222,   100,   175,    -1,    27,    99,   222,   100,
     176,    18,   175,    -1,    27,    99,   222,   100,   176,    18,
     176,    -1,    47,    99,   222,   100,   187,    -1,    95,   188,
     189,    96,    -1,    95,    96,    -1,    95,   188,    96,    -1,
      95,   189,    96,    -1,   190,    -1,   188,   190,    -1,   191,
      -1,   189,   191,    -1,   189,   171,    -1,     8,   246,    63,
      -1,    15,    63,    -1,    56,    99,   222,   100,   175,    -1,
      56,    99,   222,   100,   176,    -1,    16,   175,    56,    99,
     222,   100,   106,    -1,   197,    -1,   198,    -1,    25,    99,
     199,   106,   222,   106,   200,   100,   175,    -1,    25,    99,
     199,   106,   222,   106,   100,   175,    -1,    25,    99,   106,
     222,   106,   100,   175,    -1,    25,    99,   199,   106,   106,
     100,   175,    -1,    25,    99,   106,   106,   100,   175,    -1,
      25,    99,   106,   222,   106,   200,   100,   175,    -1,    25,
      99,   199,   106,   106,   200,   100,   175,    -1,    25,    99,
     106,   106,   200,   100,   175,    -1,    25,    99,   199,   106,
     222,   106,   200,   100,   176,    -1,    25,    99,   106,   222,
     106,   200,   100,   176,    -1,    25,    99,   199,   106,   106,
     200,   100,   176,    -1,    25,    99,   106,   106,   200,   100,
     176,    -1,    25,    99,   199,   106,   222,   106,   100,   176,
      -1,    25,    99,   106,   222,   106,   100,   176,    -1,    25,
      99,   199,   106,   106,   100,   176,    -1,    25,    99,   106,
     106,   100,   176,    -1,   201,    -1,   174,    -1,   201,    -1,
     201,   101,   182,    -1,   182,    -1,     6,   111,   106,    -1,
       6,   106,    -1,    14,   111,   106,    -1,    14,   106,    -1,
      42,   106,    -1,    42,   222,   106,    -1,    51,   222,   106,
      -1,    48,    99,   222,   100,   170,    -1,    53,   170,   208,
      -1,    53,   170,   210,    -1,    53,   170,   208,   210,    -1,
     208,   209,    -1,   209,    -1,     9,    99,   152,   100,   170,
      -1,    22,   170,    -1,   212,    -1,   218,    -1,   217,    -1,
      99,   222,   100,    -1,   216,    -1,   215,    -1,    49,    -1,
     110,    -1,   213,    -1,    37,   119,    99,   214,   100,    -1,
      37,   119,    99,   100,    -1,   222,    -1,   214,   101,   222,
      -1,   211,   105,   111,    -1,    46,   105,   111,    -1,   122,
      97,   222,    98,    -1,   212,    97,   222,    98,    -1,   122,
      99,   214,   100,    -1,   122,    99,   100,    -1,   211,   105,
     111,    99,   214,   100,    -1,   211,   105,   111,    99,   100,
      -1,    46,   105,   111,    99,   214,   100,    -1,    46,   105,
     111,    99,   100,    -1,    37,   115,   219,   221,    -1,    37,
     115,   219,    -1,    37,   114,   219,   221,    -1,    37,   114,
     219,    -1,   219,   220,    -1,   220,    -1,    97,   222,    98,
      -1,    97,    98,    -1,   221,    97,    98,    -1,   223,    -1,
     227,    -1,   224,    -1,   225,   226,   222,    -1,   122,    -1,
     215,    -1,   216,    -1,    85,    -1,    90,    -1,    88,    -1,
      84,    -1,    57,    -1,    93,    -1,    94,    -1,    91,    -1,
      87,    -1,    92,    -1,    89,    -1,    86,    -1,   228,    -1,
     228,    62,   222,    63,   227,    -1,   229,    -1,   228,    71,
     229,    -1,   230,    -1,   229,    72,   230,    -1,   231,    -1,
     230,    77,   231,    -1,   232,    -1,   231,    79,   232,    -1,
     233,    -1,   232,    78,   233,    -1,   234,    -1,   233,    65,
     234,    -1,   233,    68,   234,    -1,   235,    -1,   234,    66,
     235,    -1,   234,    31,   113,    -1,   234,    59,   235,    -1,
     234,    58,   235,    -1,   234,    67,   235,    -1,   236,    -1,
     235,    82,   236,    -1,   237,    -1,   236,    73,   237,    -1,
     236,    74,   237,    -1,   238,    -1,   237,    75,   238,    -1,
     237,    76,   238,    -1,   237,    80,   238,    -1,   239,    -1,
     240,    -1,    73,   238,    -1,    74,   238,    -1,   241,    -1,
      69,   238,    -1,    70,   238,    -1,   242,    -1,    61,   238,
      -1,    60,   238,    -1,   245,    -1,   211,    -1,   122,    -1,
     243,    -1,   244,    -1,   242,    69,    -1,   242,    70,    -1,
      99,   115,   221,   100,   238,    -1,    99,   222,   100,   241,
      -1,    99,   115,   100,   238,    -1,    99,   122,   221,   100,
     241,    -1,   222,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    58,    61,    62,    66,    67,    70,    72,
      73,    76,    77,    80,    81,    82,    83,    84,    87,    88,
      91,    94,    97,   103,   109,   119,   120,   123,   126,   135,
     142,   143,   148,   149,   151,   157,   166,   167,   175,   176,
     184,   192,   193,   196,   203,   210,   211,   212,   215,   216,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     236,   245,   252,   260,   268,   275,   281,   289,   300,   308,
     316,   317,   325,   326,   330,   331,   339,   340,   341,   344,
     345,   348,   355,   363,   364,   372,   373,   381,   382,   390,
     391,   396,   404,   412,   419,   425,   432,   438,   444,   449,
     460,   466,   467,   475,   476,   484,   492,   501,   502,   511,
     512,   516,   524,   532,   539,   545,   555,   563,   571,   577,
     578,   579,   582,   587,   592,   596,   603,   611,   618,   624,
     635,   640,   648,   649,   652,   653,   661,   662,   665,   668,
     671,   677,   682,   683,   691,   697,   701,   702,   705,   711,
     714,   715,   718,   721,   729,   730,   731,   732,   733,   734,
     737,   738,   739,   740,   741,   744,   745,   746,   747,   748,
     749,   750,   751,   752,   753,   754,   756,   759,   762,   765,
     768,   769,   770,   771,   772,   773,   774,   777,   785,   794,
     804,   812,   818,   819,   820,   823,   824,   832,   833,   841,
     850,   855,   862,   870,   878,   886,   889,   892,   900,   907,
     914,   921,   928,   935,   942,   952,   960,   967,   974,   981,
     988,   995,  1002,  1011,  1012,  1015,  1018,  1024,  1027,  1033,
    1036,  1042,  1045,  1046,  1054,  1062,  1069,  1075,  1081,  1090,
    1096,  1099,  1108,  1116,  1117,  1120,  1121,  1122,  1123,  1124,
    1125,  1126,  1129,  1136,  1145,  1146,  1156,  1163,  1171,  1179,
    1189,  1195,  1196,  1205,  1213,  1222,  1232,  1240,  1247,  1255,
    1264,  1270,  1274,  1277,  1278,  1286,  1289,  1290,  1293,  1301,
    1302,  1303,  1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,
    1314,  1315,  1316,  1317,  1320,  1321,  1330,  1331,  1339,  1340,
    1348,  1349,  1357,  1358,  1366,  1367,  1375,  1376,  1382,  1390,
    1391,  1397,  1403,  1409,  1415,  1424,  1425,  1434,  1435,  1441,
    1449,  1450,  1456,  1462,  1470,  1471,  1472,  1478,  1484,  1487,
    1494,  1501,  1502,  1508,  1514,  1517,  1518,  1519,  1520,  1523,
    1529,  1536,  1544,  1552,  1559,  1569
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ABSTRACT", "ASSERT", "BOOLEAN", "BREAK",
  "BYTE", "CASE", "CATCH", "CHAR", "CLASS", "COMMENT", "CONST", "CONTINUE",
  "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "ERROR", "EXTENDS", "FINALLY",
  "FINAL", "FLOAT", "FOR", "IDENTIFIER", "IF", "GOTO", "IMPLEMENTS",
  "IMPORT", "INSTANCEOF", "INT", "INTERFACE", "LITERAL", "LONG", "NATIVE",
  "NEW", "PACKAGE", "PRIVATE", "PROTECTED", "PUBLIC", "RETURN", "SHORT",
  "STATIC", "STRICTFP", "SUPER", "SWITCH", "SYNCHRONIZED", "THIS",
  "THROWS", "THROW", "TRANSIENT", "TRY", "VOID", "VOLATILE", "WHILE",
  "EQUALS", "GT", "LT", "NT", "TILDA", "QUESTION_MARK", "COLON", "ARROW",
  "EQEQ", "GREQ", "LEQ", "NEQUALS", "PLUSPLUS", "MINUSMINUS", "OR", "AND",
  "ADD", "SUBTRACT", "MULTIPLY", "DIVISION", "BINARYOR", "BINARYAND",
  "POW", "MOD", "GRGR", "LTLT", "GRGRGR", "PLEQ", "SBEQ", "MULEQ", "ANDEQ",
  "OREQ", "POWEQ", "DIVEQ", "MODEQ", "DGRGR", "DLRLR", "TGRGRGR", "OC",
  "CC", "OSQ", "CSQ", "OS", "CS", "COMMA", "DISTO", "ATR", "TDT", "FST",
  "SCLN", "DST", "';'", "$accept", "Literal", "Identifier", "Type",
  "RefType", "ClassOrIntfaceType", "PrimitiveType", "Numbers", "Integers",
  "FloatingPoint", "ClassType", "IntfaceType", "ArrKind", "Name",
  "SimpleName", "QualName", "CompUnit", "ImportDecnRec", "TypeDecRec",
  "PackageDecn", "ImportDecn", "SingleTypeImportDecn", "ImportDDec",
  "TypeDec", "Modifiers", "Modifier", "ClassDec", "Super", "Intfaces",
  "IntfaceTypeList", "ClassBody", "ClassBodyDecRec", "ClassBodyDec",
  "MemberDec", "FieldDecn", "VariableDecltrs", "VariableDecltr",
  "VariableDecltrId", "VariableInit", "MethodDecn", "MethodHead",
  "MethodDecltr", "FormalParamList", "FormalParam", "Throws",
  "ClassTypeList", "MethodBody", "StaticInit", "ConstructorDecn",
  "ConstructorDecltr", "ConstructorBody", "ExplicitConstructorInvocation",
  "IntfaceDecn", "ExtendsIntfaces", "IntfaceBody", "IntfaceMemberDecnRec",
  "IntfaceMemberDecn", "ConstantDec", "AbstractMethod", "ArrInit",
  "VariableInitList", "Block", "BlockStmts", "BlockStmt",
  "LocalVariableDecnStmt", "LocalVariableDecn", "Stmt", "StmtKind",
  "StmtWithoutTrailingSubStmt", "EmptyStmt", "LabeledStmt",
  "LabeledStmtNoShortIf", "ExprStmt", "StmtExpr", "IfThenStmt",
  "IfThenElseStmt", "IfThenElseStmtKind", "SwitchStmt", "SwitchBlock",
  "SwitchBlockStmtGroups", "SwitchLabels", "SwitchBlockStmtGroup",
  "SwitchLabel", "WhileStmt", "WhileStmtKind", "DoStmt", "ForStatement",
  "ForStatementKind", "ForStmt", "ForStmtKind", "ForInit", "ForUpdate",
  "StmtExprList", "BreakStmt", "ContinueStmt", "ReturnStmt", "ThrowStmt",
  "SynchronizedStmt", "TryStmt", "Catches", "CatchClause", "ResEnd",
  "Primary", "PrimaryNoNewArr", "ClassCreation", "ArgLst", "FieldAccess",
  "ArrOp", "MethodInvocation", "NewArr", "DimExprs", "DimExpr", "Dims",
  "Expr", "AssignExpr", "Assign", "LeftHandSide", "AssignOp",
  "ConditionExpr", "ConditionOrExpr", "ConditionAndExpr",
  "InclusiveOrExpr", "ExclusiveOrExpr", "AndExpr", "EqExpr", "RtlExpr",
  "ShiftExpr", "AddExpr", "MultExpr", "UnaryExpr", "PreIncExpr",
  "PreDecExpr", "UnaryExprExtra", "PostfixExpr", "PostIncrementExpr",
  "PostDecrementExpr", "CastExpr", "ConstExpr", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   111,   112,   112,   113,   113,   114,   115,
     115,   116,   116,   117,   117,   117,   117,   117,   118,   118,
     119,   120,   121,   121,   121,   122,   122,   123,   124,   125,
     125,   125,   125,   125,   125,   125,   126,   126,   127,   127,
     128,   129,   129,   130,   131,   132,   132,   132,   133,   133,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   134,
     135,   135,   135,   135,   135,   135,   135,   135,   136,   137,
     138,   138,   139,   139,   140,   140,   141,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   147,
     147,   148,   149,   149,   149,   149,   149,   149,   149,   149,
     150,   150,   150,   151,   151,   152,   153,   154,   154,   155,
     155,   156,   157,   157,   157,   157,   158,   158,   159,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   161,   161,
     162,   162,   163,   163,   164,   164,   165,   165,   166,   167,
     168,   168,   168,   168,   169,   169,   170,   170,   171,   171,
     172,   172,   173,   174,   175,   175,   175,   175,   175,   175,
     176,   176,   176,   176,   176,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   178,   179,   180,   181,
     182,   182,   182,   182,   182,   182,   182,   183,   184,   185,
     186,   187,   187,   187,   187,   188,   188,   189,   189,   190,
     191,   191,   192,   193,   194,   195,   196,   197,   197,   197,
     197,   197,   197,   197,   197,   198,   198,   198,   198,   198,
     198,   198,   198,   199,   199,   200,   201,   201,   202,   202,
     203,   203,   204,   204,   205,   206,   207,   207,   207,   208,
     208,   209,   210,   211,   211,   212,   212,   212,   212,   212,
     212,   212,   213,   213,   214,   214,   215,   215,   216,   216,
     217,   217,   217,   217,   217,   217,   218,   218,   218,   218,
     219,   219,   220,   221,   221,   222,   223,   223,   224,   225,
     225,   225,   226,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   227,   227,   228,   228,   229,   229,
     230,   230,   231,   231,   232,   232,   233,   233,   233,   234,
     234,   234,   234,   234,   234,   235,   235,   236,   236,   236,
     237,   237,   237,   237,   238,   238,   238,   238,   238,   239,
     240,   241,   241,   241,   241,   242,   242,   242,   242,   243,
     244,   245,   245,   245,   245,   246
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     1,     1,     1,     3,     3,
       1,     2,     1,     1,     2,     2,     1,     2,     1,     2,
       3,     1,     1,     3,     4,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       6,     4,     5,     4,     4,     3,     5,     5,     2,     2,
       1,     3,     2,     3,     1,     2,     1,     1,     1,     1,
       1,     4,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     2,     4,     3,     2,     4,     3,     3,     2,     3,
       4,     3,     3,     1,     3,     2,     2,     1,     3,     1,
       1,     2,     4,     3,     2,     3,     4,     3,     4,     2,
       3,     3,     5,     4,     5,     4,     5,     4,     3,     4,
       2,     3,     2,     3,     1,     2,     1,     1,     1,     2,
       4,     3,     2,     3,     3,     1,     3,     2,     2,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     7,
       5,     4,     2,     3,     3,     1,     2,     1,     2,     2,
       3,     2,     5,     5,     7,     1,     1,     9,     8,     7,
       7,     6,     8,     8,     7,     9,     8,     8,     7,     8,
       7,     7,     6,     1,     1,     1,     3,     1,     3,     2,
       3,     2,     2,     3,     3,     5,     3,     3,     4,     2,
       1,     5,     2,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     5,     4,     1,     3,     3,     3,     4,     4,
       4,     3,     6,     5,     6,     5,     4,     3,     4,     3,
       2,     1,     3,     2,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     2,     2,     1,     2,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     5,     4,     4,     5,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,    58,     0,    50,     0,     0,    53,     0,    51,    52,
      56,    55,    54,    57,    59,    46,     0,    32,    30,    33,
      36,    42,    41,    38,     0,    48,    47,    45,     3,     0,
      27,     0,    26,    25,     0,     0,     1,    34,    37,    39,
      31,    35,     0,     0,    49,     0,     0,     0,     0,     0,
      65,     0,    43,     0,     0,     0,     0,   128,    40,    29,
       0,     0,    20,    68,     8,    21,    70,    69,    10,    14,
      16,    18,    19,    15,    13,    17,    55,     0,    72,     0,
       4,     7,     5,     9,    12,    11,     6,     8,    26,     0,
       0,    74,    78,    80,    79,     0,    77,    76,     0,     0,
      63,    61,    28,    44,   130,   132,     0,   138,     0,     0,
     134,   136,   137,     0,   129,     0,     0,    64,     0,   127,
       0,     0,   111,     0,    98,    87,     0,    83,    85,    94,
       0,     0,     0,     0,     0,     0,     0,    73,    75,   109,
      91,   110,     0,     0,     0,   114,    66,   139,   133,   135,
     131,     0,    62,    67,   126,    71,     0,     0,     0,     0,
       0,     2,     0,     0,     0,     0,     0,   249,     0,     0,
       0,     0,     0,   147,     0,   176,   250,    27,     0,   279,
     172,     0,   149,   150,     0,   151,   155,   173,   157,   168,
       0,   158,   159,   170,   154,   166,   156,   205,   167,   171,
     174,   169,   175,   165,   335,   243,   251,   248,   247,   245,
     244,   186,     0,   185,   182,     0,   184,   181,     0,     0,
      96,     0,    82,     0,     0,    93,    22,    23,    24,   117,
       0,     0,   103,    97,     0,    99,     0,   113,   107,   106,
       0,   249,   119,     0,     0,   115,    60,   229,     0,   231,
       0,   336,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,     0,   232,   251,   245,     0,   275,   277,   276,
     294,   296,   298,   300,   302,   304,   306,   309,   315,   317,
     320,   324,   325,   328,   331,   337,   338,   334,     0,     0,
       0,     0,     0,     0,   336,   248,   247,   329,   330,     0,
       0,    87,   153,     0,     0,   146,   148,   152,   179,     0,
       0,   286,   285,   282,   293,   290,   284,   292,   283,   289,
     291,   287,   288,     0,   339,   340,   101,     0,   102,    84,
       0,    86,    90,    89,    88,   105,   116,     0,    95,    81,
      92,   112,     0,     0,     0,   120,     0,   121,   228,   230,
       0,     0,     0,   224,   227,     0,   223,     0,     0,   269,
     271,   267,     0,   333,   332,   326,   327,     0,   336,     0,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     257,     0,     0,   234,     0,     0,   236,   240,   237,     0,
     246,   177,     0,   261,     0,   254,   256,     0,   278,   100,
     142,     0,   145,     0,   104,   108,     0,     0,     0,     0,
     118,     0,     0,     0,     0,     0,     0,     0,     0,   270,
     268,   266,   253,     0,     0,     0,     0,     0,     0,   246,
       0,   297,   299,   301,   303,   305,   307,   308,   311,     0,
     313,   312,   310,   314,   316,   318,   319,   321,   322,   323,
       0,     0,     0,     0,   242,   239,   238,     0,   258,   260,
       0,     0,   259,   143,   141,     0,   125,     0,   123,     0,
       0,     0,     0,   225,     0,     0,     0,   226,     0,     0,
       0,    27,   187,     0,   155,   161,   163,   160,   164,   206,
     272,   273,     0,   252,   343,     0,     0,   342,     0,   265,
       0,     0,   190,   235,     0,   202,   255,   263,     0,   140,
     144,   124,   122,     0,   211,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   274,   341,   344,   295,
     264,     0,     0,   192,     0,     0,   195,   197,     0,   262,
     204,   214,   209,     0,   210,     0,     0,     0,     0,     0,
       0,     0,   178,   188,   345,     0,   201,   193,     0,   196,
     194,   199,   198,   241,   212,   213,   208,     0,     0,     0,
       0,     0,     0,   200,   191,   207,     0,     0,     0,     0,
       0,     0,   203,   222,     0,     0,     0,     0,     0,     0,
       0,   218,   220,     0,   221,     0,     0,     0,   189,   216,
     217,   219,     0,   215
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   176,    30,   178,    80,    81,    82,    83,    84,    85,
      63,    66,    86,   251,    32,    33,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    48,    49,    67,
      50,    90,    91,    92,    93,   126,   127,   128,   331,    94,
      95,   124,   231,   232,   144,   239,   140,    96,    97,    98,
     145,   243,    27,    56,    57,   109,   110,   111,   112,   332,
     413,   180,   571,   182,   183,   184,   185,   493,   186,   187,
     188,   495,   189,   190,   191,   192,   496,   193,   512,   544,
     545,   546,   547,   194,   497,   195,   196,   498,   197,   499,
     355,   482,   483,   198,   199,   200,   201,   202,   203,   396,
     397,   398,   204,   205,   264,   404,   207,   208,   265,   210,
     359,   360,   430,   405,   267,   211,   212,   323,   269,   270,
     271,   272,   273,   274,   275,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   565
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -439
static const yytype_int16 yypact[] =
{
     508,  -439,    41,  -439,    41,    41,  -439,    41,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,    96,   634,   199,   634,
    -439,  -439,  -439,  -439,  1137,  -439,  -439,  -439,  -439,    34,
    -439,   213,  -439,  -439,     0,   183,  -439,   199,  -439,  -439,
     634,   199,    41,    41,  -439,    41,    41,  1544,    14,    48,
    -439,    41,  -439,     5,    41,  2574,    36,  -439,  -439,   199,
      34,     0,  -439,  -439,    47,  -439,  -439,    57,  -439,  -439,
    -439,  -439,  -439,  -439,  -439,  -439,    73,    41,  -439,    41,
    -439,  -439,    75,  -439,  -439,  -439,   103,   107,   108,  3078,
    2620,  -439,  -439,  -439,  -439,   -30,  -439,  -439,    23,    48,
    -439,  -439,  -439,  -439,  -439,  -439,  3078,  -439,   105,  2666,
    -439,  -439,  -439,    41,  -439,    14,    48,  -439,    36,  -439,
      41,  2040,  -439,   138,    38,   138,    81,  -439,    -3,    38,
     123,   127,   150,   336,    41,    41,    23,  -439,  -439,  -439,
    -439,  -439,    41,  2106,   160,  -439,  -439,  -439,  -439,  -439,
    -439,    48,  -439,  -439,  -439,  -439,    19,    24,  1815,   167,
     222,  -439,   762,  2662,   177,   246,   253,  -439,  3017,    73,
     256,  3017,  3017,  -439,  3017,  -439,  -439,   273,    41,   188,
    -439,  2172,  -439,  -439,   251,  -439,  -439,  -439,  -439,  -439,
     280,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  -439,   254,   270,   144,  1948,  2013,   210,
    -439,  -439,  2146,  -439,  -439,   255,   259,   261,   408,   285,
    -439,    41,  -439,  2942,   291,  -439,  -439,  -439,  -439,  -439,
      41,   214,  -439,    38,    93,    38,   160,  -439,  -439,   293,
     -12,   297,  -439,  2238,  2304,  -439,  -439,  -439,   296,  -439,
     298,  1845,   341,   685,  3017,   302,   302,   306,  3017,  3017,
    3017,  3017,  2502,  -439,  -439,  -439,   300,  -439,  -439,  -439,
      12,   339,   331,   333,   342,    56,   139,   332,   266,   237,
    -439,  -439,  -439,  -439,   255,  -439,  -439,  -439,    41,  3017,
    3017,   313,    60,  3017,   104,  -439,  -439,  -439,  -439,   322,
    1815,  -439,   326,  2960,   539,  -439,  -439,  -439,  -439,    41,
    3017,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,  -439,  3017,  -439,  -439,  -439,   232,  -439,  -439,
    2788,  -439,  -439,  -439,  -439,   340,  -439,   762,  -439,  -439,
    -439,  -439,    41,  1595,  2795,  -439,  2370,  -439,  -439,  -439,
    3017,   324,  2678,  -439,  -439,   323,   337,   344,  3017,   345,
    -439,   345,  2844,  -439,  -439,  -439,  -439,   156,  3050,   346,
    -439,  3017,  3017,  3017,  3017,  3017,  3017,  3017,  3017,   762,
    3017,  3017,  3017,  3017,  3017,  3017,  3017,  3017,  3017,  3017,
     334,   347,   348,  -439,   351,    73,    60,  -439,  -439,   353,
    -439,  -439,   343,  -439,   249,  -439,   355,   357,  -439,  -439,
    -439,   349,  -439,   122,  -439,  -439,   352,   263,   354,   269,
    -439,  3017,   657,   356,  2720,   147,  2474,   361,  3001,  -439,
     367,   367,  -439,   272,   368,  3017,   181,  3001,   206,  1009,
     376,   339,   331,   333,   342,    56,   139,   139,  -439,    75,
     332,   332,   332,   332,   266,   237,   237,  -439,  -439,  -439,
    2851,   372,    73,   762,  -439,  -439,  -439,  1815,  -439,  -439,
    3017,  2893,  -439,  -439,  -439,  2900,  -439,   362,  -439,   365,
     373,  1815,   374,   337,   778,   889,   371,  -439,   383,   386,
     387,   427,  -439,   473,   474,  -439,  -439,  -439,  -439,  -439,
    -439,  -439,   396,  -439,  -439,  3017,  1009,  -439,  3017,  -439,
     274,    16,  -439,  -439,   395,  -439,  -439,  -439,   276,  -439,
    -439,  -439,  -439,   393,  -439,  1815,  1815,   400,  1815,   402,
     980,   850,  3017,  3017,  2474,  1815,  -439,  -439,  -439,  -439,
    -439,  3017,   450,  -439,    27,  1195,  -439,  -439,    73,  -439,
    -439,  -439,  -439,  1815,  -439,  1815,  1815,   414,  2737,   410,
     417,   422,  -439,  -439,  -439,   462,  -439,  -439,  1953,  -439,
    -439,  2436,  -439,  -439,  -439,  -439,  -439,  1815,  1005,   423,
    2739,  2474,  2474,  -439,  -439,  -439,  2474,   428,  1019,  1323,
     424,   516,  -439,  -439,  2474,  2474,   435,  2474,   436,  1413,
    2474,  -439,  -439,  2474,  -439,  2474,  2474,   439,  -439,  -439,
    -439,  -439,  2474,  -439
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -439,  -439,    -2,   -28,   163,   -34,  -155,  -439,  -439,  -439,
    -134,   -22,  -439,   245,   102,  -439,  -439,   526,   196,  -439,
      49,  -439,  -439,   126,    25,    10,  -439,   490,    -9,  -439,
     -31,  -439,   465,  -439,   -19,   -65,   350,   327,  -315,  -439,
       1,    -8,   359,  -327,   -76,  -439,  -439,  -439,  -439,   469,
    -114,  -439,  -439,   500,    -4,  -439,   453,  -439,  -439,  -439,
    -439,   -72,  -105,  -180,  -439,  -248,  -125,   -85,  -417,  -439,
    -439,  -439,  -439,  -251,  -439,  -439,  -439,  -439,  -439,  -439,
      20,    26,  -406,  -439,  -439,  -439,  -439,  -439,  -439,  -439,
      37,  -438,  -247,  -439,  -439,  -439,  -439,  -439,  -439,  -439,
     171,   176,  -439,  -439,   240,  -318,  -113,  1228,   416,  -439,
     325,   -57,  -141,  1593,  -439,  1368,  -439,  -439,    70,  -439,
     211,   216,   220,   215,   226,     3,   -86,   212,    -1,  -158,
     556,   732,  -402,   849,   940,  1220,  -439,  -439
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -339
static const yytype_int16 yytable[] =
{
      29,   306,   354,    34,   122,   353,   356,   256,   238,   494,
     414,    62,    65,   297,   298,   412,   181,   100,   101,    79,
      65,    54,   237,   141,   541,   417,   419,    79,   257,   117,
     245,   542,   104,   252,    44,   541,   107,   507,   244,    99,
      60,    61,   542,    46,   433,    28,   527,   529,   220,   102,
      28,   116,   114,   225,   223,    45,   108,   119,   295,   295,
     236,   135,    79,    46,   306,   121,    38,    28,   146,   394,
     234,   129,    89,   142,   371,   123,   139,   125,   135,    65,
     106,    79,   395,   372,   152,   153,    65,   343,   142,    38,
     107,   150,   557,   288,   224,    55,    36,   292,   155,    44,
     363,   364,   365,   366,   538,   230,   151,   367,    62,    47,
     108,   103,   543,   302,   154,    89,    44,   494,   143,   177,
     246,   377,   341,   567,   378,   247,   233,   235,   255,    47,
     249,    55,   123,   125,   106,   219,   514,   113,   346,   572,
     587,   177,   510,    47,    39,   295,   295,   295,   295,    88,
     596,   598,    51,   518,   248,   250,   177,   338,   120,   340,
     520,   607,   572,    39,   494,   494,   306,    39,   121,   494,
     379,   354,   130,    28,   487,   401,   301,   494,   494,   177,
     494,   161,   221,   494,   162,    39,   494,   222,   494,   494,
     230,    88,    88,   164,   221,   494,   167,   380,   381,   339,
     131,   350,     1,   304,   132,   382,   383,   133,   415,    51,
       2,   147,    51,    37,    -8,    41,   171,   172,   474,   301,
     431,   226,     3,   475,   449,   227,   436,   438,   301,   457,
     458,   459,     5,   354,   354,     6,    59,   218,     8,     9,
      10,   177,   177,    11,  -180,  -180,   174,    12,   228,    31,
    -180,    13,    35,   434,    14,   143,   435,  -336,  -336,   295,
     295,   295,   295,   295,   295,   295,   253,   295,   295,   295,
     295,   295,   295,   295,   295,   295,   295,   504,   502,   354,
     354,   505,   288,   353,   356,   303,   390,   304,    51,    58,
      64,    64,    87,    51,   450,   451,   452,   453,   177,    64,
      87,   492,   429,   502,   429,    15,   506,   406,    62,   230,
    -183,  -183,   387,   388,   336,   337,  -183,   389,    51,    52,
      53,   254,   295,   464,   324,   325,   295,   354,  -337,  -337,
    -338,  -338,   409,   337,    87,    87,   300,   354,   354,   385,
     386,    68,   515,    69,   177,   289,    70,   537,   354,   469,
     470,    87,   290,    71,    87,   293,   524,   307,    64,   309,
      72,   206,    28,   477,   470,    64,   179,   310,    73,   479,
     470,    74,   503,   470,   540,   470,   549,   470,    87,    75,
     446,   447,   328,   206,   455,   456,   308,    64,   179,   334,
     513,   306,   295,   295,   342,   295,   344,   351,   206,   358,
     551,   552,   348,   554,   349,   362,   370,    64,   374,   401,
     563,   373,   375,    68,   384,    69,   294,   294,    70,   393,
     376,   206,   400,   421,   491,    71,   179,   221,   574,   424,
     575,   576,    72,   460,    28,   230,   229,   224,   425,   508,
      73,   468,   428,    74,   426,   473,   439,   461,   462,   562,
     463,    75,   585,   467,   471,   472,   492,   515,   476,   500,
     478,   524,   484,    87,   502,   177,   501,   511,   521,   551,
     552,   522,   554,   523,   525,   563,   573,   530,   574,   177,
     575,   576,   531,   206,   206,   532,   533,   585,   179,   179,
     534,   535,  -162,   206,   536,   548,   591,   592,   179,   550,
     553,   593,   555,   294,   294,   294,   294,   368,   326,   601,
     602,     1,   604,   566,   577,   608,   580,   581,   609,     2,
     610,   611,   582,   177,   177,   583,   177,   613,   594,   588,
     599,     3,   491,   177,   600,   603,   605,   209,     4,   612,
     206,     5,   448,   177,     6,    40,     7,     8,     9,    10,
     115,   177,    11,   177,   177,   138,    12,   335,   136,   209,
      13,   118,   149,    14,   568,    28,   177,   465,   559,   177,
     569,   329,   466,   161,   209,   177,   162,   327,   539,   491,
     491,   361,    87,   441,   491,   164,   206,    64,   167,   442,
     444,   179,   491,   491,   443,   491,   454,   209,   491,   258,
     259,   491,   445,   491,   491,     0,     0,     0,   171,   172,
     491,     0,   260,   261,    15,     0,     0,   294,   294,   294,
     294,   294,   294,   294,    87,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,     0,     0,     1,   262,   403,
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     3,     0,   209,
     209,     0,   206,     0,     4,   206,   206,     5,     0,   209,
       6,     0,     0,     8,     9,    10,     0,   213,    11,     0,
     294,     0,    12,    28,   294,     0,    13,     0,     0,    14,
      68,   161,    69,     0,   162,    70,     0,     0,     0,   213,
       0,     0,    71,   164,     0,     0,   167,   206,    87,    72,
       0,    28,     0,     0,   213,     0,   209,    73,     0,   161,
      74,   206,   162,     0,   206,   206,   171,   172,    75,     0,
       0,   164,     0,     0,   167,     0,     0,   213,     0,     0,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     294,   294,     0,   294,   171,   172,   174,   481,     0,     0,
       0,     0,   209,     0,     0,   206,   206,    68,   206,    69,
     206,   206,    70,     0,   206,   206,   179,     0,     0,    71,
       0,     0,     0,     0,   174,   206,    72,     0,    28,     0,
     179,   352,     0,   206,    73,   206,   206,    74,     0,   213,
     213,     0,     0,     0,    28,    75,     0,     0,   206,   213,
       0,   206,   161,   179,     0,   162,   179,   206,   206,     0,
       0,   206,   206,     0,   164,     0,   206,   167,   206,   206,
       0,     0,     0,     0,   206,   206,     0,   206,   209,   206,
     206,   209,   209,   206,     0,   206,   206,   171,   172,     0,
       0,     0,   206,   214,     0,    68,   213,    69,     0,     0,
      70,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,     0,     0,     0,    72,   214,    28,   174,   526,     0,
       0,     0,    73,   209,   161,    74,     0,   162,     0,     0,
     214,     0,     0,    75,     0,     0,   164,   209,     0,   167,
     209,   209,   213,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,    28,     0,     0,     0,   171,
     172,     0,     0,   161,     0,     0,   162,     0,     0,     0,
       0,     0,     0,     0,     0,   164,     0,     0,   167,     0,
       0,   209,   209,     0,   209,     0,   209,   209,     0,   174,
     209,   209,     0,     0,     0,     0,   558,     0,   171,   172,
       0,   209,     0,     0,     0,     0,     0,     0,     0,   209,
     215,   209,   209,     0,     0,   214,   214,     0,   213,     0,
       0,   213,   213,     0,   209,   214,     0,   209,   174,   528,
       0,     0,   215,   209,   209,     0,     0,   209,   209,     0,
       0,     0,   209,     0,   209,   209,    28,   215,     0,     0,
     209,   209,     0,   209,   161,   209,   209,   162,     0,   209,
       0,   209,   209,   213,     0,     0,   164,     0,   209,   167,
     215,    28,   214,     0,     0,    28,     0,   213,     0,   161,
     213,   213,   162,   161,     0,    28,   162,     0,     0,   171,
     172,   164,     0,   161,   167,   164,   162,     0,   167,     0,
       0,   216,     0,     0,     0,   164,     0,     0,   167,   258,
     259,     0,     0,     0,   171,   172,     0,     0,   214,   174,
     556,   213,   213,   216,   213,     0,   213,   213,   171,   172,
     213,   213,   215,   215,     0,     0,     0,     0,   216,     0,
       0,   213,   215,     0,   174,   586,     0,     0,   262,   213,
       0,   213,   213,     0,     0,     0,     0,     0,   174,   595,
       0,   216,     0,     0,   213,     0,     0,   213,     0,     0,
       0,     0,     0,   213,   213,     0,     0,   213,   213,     0,
       1,     0,   213,     0,   213,   213,     0,     0,    42,   215,
     213,   213,     0,   213,   214,   213,   213,   214,   214,   213,
       3,   213,   213,     0,     0,     0,     0,     0,   213,     0,
      43,     0,     0,     6,     0,     0,     8,     9,    10,     0,
       0,    11,     0,   216,   216,    12,     0,     0,     0,    13,
       0,     0,    14,   216,     0,   215,     0,     0,     0,   214,
      68,   156,    69,   541,     0,    70,     0,     0,     0,   157,
     542,   158,    71,   214,     0,     0,   214,   214,     0,    72,
     159,    28,   160,     0,     0,     0,     0,    73,     0,   161,
      74,     0,   162,     0,     0,     0,     0,   163,    75,     0,
     216,   164,   165,   166,   167,     0,   168,     0,   169,     0,
       0,   170,     0,     0,     0,     0,     0,   214,   214,     0,
     214,     0,   214,   214,   171,   172,   214,   214,     0,     0,
       0,   215,     0,     0,   215,   215,     0,   214,     0,     0,
       0,     0,     0,     0,     0,   214,   216,   214,   214,     0,
     121,   570,     0,     0,   174,     0,     0,     0,     0,     0,
     214,   175,     0,   214,     0,     0,     0,     0,     0,   214,
     214,     0,     0,   214,   214,     0,   215,     0,   214,     0,
     214,   214,     0,     0,     0,     0,   214,   214,     0,   214,
     215,   214,   214,   215,   215,   214,     0,   214,   214,     0,
       0,   217,     0,     0,   214,     0,     0,     0,     0,    28,
       0,     0,     0,     0,     0,     0,     0,   161,     0,     0,
     162,     0,   216,   217,     0,   216,   216,     0,     0,   164,
       0,     0,   167,     0,   215,   215,     0,   215,   217,   215,
     215,     0,     0,   215,   215,     0,     0,     0,     0,     0,
       0,     0,   171,   172,   215,     0,     0,     0,     0,   296,
     296,   217,   215,     0,   215,   215,     0,   216,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   215,     0,     0,
     215,   216,   174,   597,   216,   216,   215,   215,     0,     0,
     215,   215,     0,     0,     0,   215,     0,   215,   215,    28,
       0,     0,     0,   215,   215,     0,   215,   161,   215,   215,
     162,     0,   215,     0,   215,   215,     0,     0,     0,   164,
       0,   215,   167,   217,   217,   216,   216,     0,   216,     0,
     216,   216,     0,   217,   216,   216,     0,     0,     0,     0,
       0,     0,   171,   172,     0,   216,   296,   296,   296,   296,
       0,     0,     0,   216,     0,   216,   216,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   216,     0,
       0,   216,   174,   606,     0,     0,     0,   216,   216,     0,
     217,   216,   216,     0,     0,     0,   216,     0,   216,   216,
       0,   268,     0,     0,   216,   216,   268,   216,     0,   216,
     216,     0,   268,   216,     0,   216,   216,     1,     0,    68,
       0,    69,   216,     0,    70,     0,     0,     0,     0,     0,
       0,    71,     0,     0,     0,     0,   217,     3,    72,     0,
      28,     0,     0,     0,     0,     0,    73,     0,     0,    74,
       6,     0,     0,     8,     9,    10,     0,    75,    76,     0,
       0,   268,    12,     0,     0,     0,    13,     0,    77,    14,
     296,   296,   296,   296,   296,   296,   296,     0,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,     0,     0,
       0,    28,   268,     0,     0,     0,     0,     0,     0,   161,
     268,     0,   162,     0,     0,     0,     0,     0,     0,     0,
      78,   164,   217,     0,   167,   217,   217,     0,     0,     0,
       0,     0,     0,     0,     0,   258,   259,   268,   268,     0,
       0,   268,     0,   296,   171,   172,     0,   296,   260,   261,
       0,   268,   268,     0,     0,     0,     0,     0,   268,     0,
       0,     0,     0,     0,     0,     0,     0,   217,     0,     0,
       0,   268,     0,     0,   262,   416,     0,     0,   268,     0,
       0,   217,     0,     0,   217,   217,     0,     0,     0,     0,
       0,   268,   268,     0,     0,     0,     0,     0,   268,     0,
     268,     0,     0,     0,     0,     0,   268,     0,     0,     0,
     268,     0,     0,   296,   296,     0,   296,     0,     0,   268,
       0,     0,     0,     0,     0,   217,   217,     0,   217,     0,
     217,   217,     0,     0,   217,   217,   266,     0,     0,     0,
       0,   291,     0,     0,     0,   217,     0,   299,     0,     0,
       0,     0,     0,   217,     0,   217,   217,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   217,   268,
       0,   217,   268,     0,     0,     0,   268,   217,   217,     0,
       0,   217,   217,     0,     0,   268,   217,     0,   217,   217,
       0,     0,     0,     0,   217,   217,   333,   217,     0,   217,
     217,   156,     0,   217,     0,   217,   217,     0,   268,   157,
       0,   158,   217,     0,     0,     0,     0,     0,   268,   268,
     159,    28,   160,   268,     0,     0,     0,   357,     0,   161,
       0,     0,   162,     0,     0,   369,     0,   163,     0,     0,
       0,   164,   165,   166,   167,     0,   168,     0,   169,     0,
       0,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   391,   392,   171,   172,   399,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   402,     0,     0,     0,
     268,   268,  -279,   407,     0,     0,     0,     0,     0,   268,
     121,     0,     0,     0,   174,     0,   408,     0,     0,     0,
       0,   175,     0,   333,     0,     0,   268,     0,     0,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
       0,     0,   350,   402,   304,   423,     0,     0,   268,     0,
      51,   427,     0,     0,     0,     0,     0,     0,    68,   156,
      69,   541,     0,    70,   440,     0,     0,   157,   542,   158,
      71,     0,     0,     0,     0,     0,     0,    72,   159,    28,
     160,     0,     0,     0,     0,    73,     0,   161,    74,     0,
     162,     0,     0,     0,     0,   163,    75,     0,     0,   164,
     165,   166,   167,     0,   168,  -280,   169,     0,     0,   170,
       0,     0,     0,     0,   480,     0,     0,   486,     0,     0,
       0,   427,   171,   172,     0,     0,     0,     0,     0,     0,
     402,     0,  -280,  -280,  -280,  -280,  -280,  -280,  -280,  -280,
    -280,  -280,  -280,     0,     0,    68,   156,    69,   121,   584,
      70,     0,   174,     0,   157,     0,   158,    71,     0,   175,
       0,     0,     0,   516,    72,   159,    28,   160,   333,     0,
    -281,     0,    73,     0,   161,    74,     0,   162,     0,     0,
       0,     0,   163,    75,     0,     0,   164,   165,   166,   167,
       0,   168,     0,   169,     0,     0,   170,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,     0,   171,
     172,    68,   156,    69,     0,     0,    70,     0,     0,     0,
     157,     0,   158,    71,     0,   560,   561,     0,     0,     0,
      72,   159,    28,   160,   564,   121,   173,     0,    73,   174,
     161,    74,     0,   162,     0,     0,   175,     0,   163,    75,
       0,   579,   240,   165,   166,   241,     0,   168,     0,   169,
       0,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   590,     0,   171,   172,    68,   156,    69,
       0,     0,    70,     0,     0,     0,   157,     0,   158,    71,
       0,     0,     0,     0,     0,     0,    72,   159,    28,   160,
       0,   121,   242,   311,    73,   174,   161,    74,     0,   162,
       0,     0,   175,     0,   163,    75,     0,     0,   164,   165,
     166,   167,     0,   168,     0,   169,     0,     0,   170,     0,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     322,   171,   172,    68,   156,    69,     0,     0,    70,     0,
       0,     0,   157,     0,   158,    71,     0,     0,     0,     0,
       0,     0,    72,   159,    28,   160,     0,   121,   305,     0,
      73,   174,   161,    74,     0,   162,     0,     0,   175,     0,
     163,    75,     0,     0,   164,   165,   166,   167,     0,   168,
       0,   169,     0,     0,   170,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   171,   172,    68,
     156,    69,     0,     0,    70,     0,     0,     0,   157,     0,
     158,    71,     0,     0,     0,     0,     0,     0,    72,   159,
      28,   160,     0,   121,   345,     0,    73,   174,   161,    74,
       0,   162,     0,     0,   175,     0,   163,    75,     0,     0,
     164,   165,   166,   167,     0,   168,     0,   169,     0,     0,
     170,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,   172,    68,   156,    69,     0,     0,
      70,     0,     0,     0,   157,     0,   158,    71,     0,     0,
       0,     0,     0,     0,    72,   159,    28,   160,     0,   121,
     347,     0,    73,   174,   161,    74,     0,   162,     0,     0,
     175,     0,   163,    75,     0,     0,   164,   165,   166,   167,
       0,   168,     0,   169,     0,     0,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   171,
     172,    68,   156,    69,     0,     0,    70,     0,     0,     0,
     157,     0,   158,    71,     0,     0,     0,     0,     0,     0,
      72,   159,    28,   160,     0,   121,   420,     0,    73,   174,
     161,    74,     0,   162,     0,     0,   175,     0,   163,    75,
     156,     0,   164,   165,   166,   167,     0,   168,   157,   169,
     158,     0,   170,     0,     0,     0,     0,     0,     0,   488,
      28,   489,     0,     0,     0,   171,   172,    68,   161,    69,
       0,   162,    70,     0,     0,     0,   163,     0,     0,    71,
     164,   165,   166,   167,     0,   168,    72,   169,    28,     0,
     490,   121,     0,     0,    73,   174,   161,    74,     0,   162,
       0,     0,   175,   171,   172,    75,     0,     0,   164,     0,
       0,   167,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   258,   259,     0,     0,     0,     0,     0,   121,
       0,   171,   172,   174,     0,   260,   261,     1,     0,    68,
     175,    69,     0,     0,    70,     0,     0,     0,     0,     0,
       0,    71,     0,     0,     0,     0,     0,     3,    72,     0,
      28,   262,     0,     0,     0,     0,    73,     0,     0,    74,
       6,     0,     0,     8,     9,    10,     0,    75,    11,     0,
       0,     0,    12,     1,     0,    68,    13,    69,    77,    14,
      70,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       0,     0,     0,     3,    72,     0,    28,     0,     0,     0,
       0,     0,    73,     0,     0,    74,     6,     0,     0,     8,
       9,    10,     0,    75,    76,     0,     0,     0,    12,     1,
     105,    68,    13,    69,    77,    14,    70,     0,     0,     0,
       0,     0,     0,    71,     0,     0,     0,     0,    28,     3,
      72,     0,    28,     0,     0,     0,   161,     0,    73,   162,
       0,    74,     6,     0,    28,     8,     9,    10,   164,    75,
      11,   167,   161,     0,    12,   162,   137,     0,    13,     0,
      77,    14,   258,   259,   164,     0,     0,   167,     0,     0,
       0,   171,   172,     0,     0,   260,   261,     0,   258,   259,
       0,     0,     0,     0,     0,     0,    28,   171,   172,     0,
       0,   260,   261,     0,   161,     0,     0,   162,     0,     0,
       0,   262,   148,    28,     0,    28,   164,     0,   263,   167,
       0,   161,     0,   161,   162,     0,   162,   262,     0,     0,
     258,   259,     0,   164,   422,   164,   167,     0,   167,   171,
     172,     0,     0,   260,   261,     0,     0,   258,   259,   258,
     259,     0,     0,     0,     0,     0,   171,   172,   171,   172,
     260,   261,   260,   261,    28,     0,     0,     0,     0,   262,
       0,    28,   161,     0,     0,   162,   485,     0,     0,   161,
       0,     0,   162,     0,   164,     0,   262,   167,   262,     0,
       0,   164,     0,   578,   167,   589,     0,     0,   258,   259,
       0,     0,     0,     0,     0,   258,   259,   171,   172,     0,
       0,   260,   261,     0,   171,   172,     0,     0,   260,   261,
      28,     0,     0,     0,     0,     0,     0,    28,   161,     0,
       0,   162,     0,   330,   410,   161,     0,   262,   162,   411,
     164,     0,     0,   167,   262,   418,     0,   164,     0,     0,
     167,     0,     0,     0,   258,   259,     0,     0,     0,     0,
       0,   258,   259,   171,   172,     0,     0,   260,   261,    28,
     171,   172,     0,     0,   260,   261,    28,   161,     0,     0,
     162,     0,     0,     0,   161,     0,     0,   162,     0,   164,
       0,     0,   167,   262,   432,     0,   164,     0,     0,   167,
     262,   509,     0,   258,   259,     0,     0,     0,     0,     0,
     258,   259,   171,   172,     0,     0,   260,   261,    28,   171,
     172,     0,     0,   260,   261,     0,   161,     0,     0,   162,
       0,     0,     0,     0,     0,     0,    28,     0,   164,     0,
       0,   167,   262,   517,   161,   330,   519,   162,     0,   262,
       0,     0,   258,   259,     0,     0,   164,     0,     0,   167,
       0,   171,   172,     0,     0,   260,   261,     0,     0,     0,
     258,   259,     0,     0,     0,     0,     0,    28,     0,   171,
     172,     0,     0,   260,   261,   161,     0,   330,   162,     0,
       0,   262,     0,    28,     0,     0,     0,   164,     0,     0,
     167,   161,     0,     0,   162,     0,     0,     0,   228,   262,
       0,   258,   259,   164,     0,     0,   167,     0,     0,     0,
     171,   172,     0,     0,   260,   261,     0,   258,   259,     0,
       0,     1,     0,    68,     0,    69,   171,   172,    70,     0,
     260,   261,     0,     0,     0,    71,     0,     0,     0,   501,
     262,     3,    72,     0,    28,     0,     0,  -279,     0,     0,
      73,     0,     0,    74,     6,     0,   262,     8,     9,    10,
       0,    75,    11,     0,     0,     0,    12,     0,     0,     0,
      13,     0,   134,    14,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,     0,     0,   437,     0,   304,
       0,     0,     0,     0,     0,    51
};

static const yytype_int16 yycheck[] =
{
       2,   181,   253,     5,    76,   253,   253,   162,   142,   426,
     337,    45,    46,   171,   172,   330,   121,    48,    49,    47,
      54,    21,   136,    95,     8,   343,   344,    55,   162,    60,
     144,    15,    54,   158,    24,     8,    55,   439,   143,    48,
      42,    43,    15,    29,   362,    26,   484,   485,   124,    51,
      26,    60,    56,   129,    57,    21,    55,    61,   171,   172,
     136,    89,    90,    29,   244,    95,    17,    26,    99,     9,
     135,    79,    47,    50,    62,    77,   106,    79,   106,   113,
      55,   109,    22,    71,   115,   116,   120,    99,    50,    40,
     109,   113,   530,   105,    97,    95,     0,   169,   120,    89,
     258,   259,   260,   261,   506,   133,   115,   262,   142,    95,
     109,   106,    96,   178,   118,    90,   106,   534,    95,   121,
     151,    65,   236,    96,    68,   106,   134,   135,   162,    95,
     106,    95,   134,   135,   109,    97,   463,   101,   243,   545,
     578,   143,   460,    95,    18,   258,   259,   260,   261,    47,
     588,   589,   105,   471,   156,   157,   158,   233,   101,   235,
     475,   599,   568,    37,   581,   582,   346,    41,    95,   586,
      31,   422,    97,    26,   425,   300,   178,   594,   595,   181,
     597,    34,   101,   600,    37,    59,   603,   106,   605,   606,
     218,    89,    90,    46,   101,   612,    49,    58,    59,   106,
      97,    97,     3,    99,    97,    66,    67,    99,   342,   105,
      11,   106,   105,    17,    26,    19,    69,    70,    96,   221,
     361,    98,    23,   101,   379,    98,   367,   368,   230,   387,
     388,   389,    33,   484,   485,    36,    40,    99,    39,    40,
      41,   243,   244,    44,   100,   101,    99,    48,    98,     4,
     106,    52,     7,    97,    55,    95,   100,    69,    70,   372,
     373,   374,   375,   376,   377,   378,    99,   380,   381,   382,
     383,   384,   385,   386,   387,   388,   389,   435,    97,   530,
     531,   100,   105,   531,   531,    97,   288,    99,   105,   106,
      45,    46,    47,   105,   380,   381,   382,   383,   300,    54,
      55,   426,   359,    97,   361,   106,   100,   309,   342,   337,
     100,   101,    75,    76,   100,   101,   106,    80,   105,   106,
     107,    99,   435,   395,    69,    70,   439,   578,    69,    70,
      69,    70,   100,   101,    89,    90,    63,   588,   589,    73,
      74,     5,   467,     7,   346,    99,    10,   505,   599,   100,
     101,   106,    99,    17,   109,    99,   481,   106,   113,   105,
      24,   121,    26,   100,   101,   120,   121,    97,    32,   100,
     101,    35,   100,   101,   100,   101,   100,   101,   133,    43,
     377,   378,    97,   143,   385,   386,   106,   142,   143,    98,
     462,   571,   505,   506,   101,   508,    99,    56,   158,    97,
     525,   526,   106,   528,   106,    99,   106,   162,    77,   534,
     535,    72,    79,     5,    82,     7,   171,   172,    10,   106,
      78,   181,   100,    99,   426,    17,   181,   101,   553,   106,
     555,   556,    24,    99,    26,   463,   100,    97,   101,    63,
      32,    98,    97,    35,   100,    96,   100,   100,   100,   534,
      99,    43,   577,   100,    99,    98,   581,   582,   106,    98,
     106,   586,   106,   218,    97,   467,    98,    95,   106,   594,
     595,   106,   597,   100,   100,   600,   548,   106,   603,   481,
     605,   606,    99,   243,   244,    99,    99,   612,   243,   244,
      63,    18,    18,   253,    98,   100,   581,   582,   253,   106,
     100,   586,   100,   258,   259,   260,   261,   262,   100,   594,
     595,     3,   597,    63,   100,   600,   106,   100,   603,    11,
     605,   606,   100,   525,   526,    63,   528,   612,   100,   106,
     106,    23,   534,   535,    18,   100,   100,   121,    30,   100,
     300,    33,   379,   545,    36,    19,    38,    39,    40,    41,
      60,   553,    44,   555,   556,    90,    48,   230,    89,   143,
      52,    61,   109,    55,   544,    26,   568,   396,   531,   571,
     544,   221,   396,    34,   158,   577,    37,   218,   508,   581,
     582,   256,   337,   372,   586,    46,   346,   342,    49,   373,
     375,   346,   594,   595,   374,   597,   384,   181,   600,    60,
      61,   603,   376,   605,   606,    -1,    -1,    -1,    69,    70,
     612,    -1,    73,    74,   106,    -1,    -1,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,    -1,    -1,     3,    99,   100,
      -1,    -1,    -1,    -1,    -1,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    -1,   243,
     244,    -1,   422,    -1,    30,   425,   426,    33,    -1,   253,
      36,    -1,    -1,    39,    40,    41,    -1,   121,    44,    -1,
     435,    -1,    48,    26,   439,    -1,    52,    -1,    -1,    55,
       5,    34,     7,    -1,    37,    10,    -1,    -1,    -1,   143,
      -1,    -1,    17,    46,    -1,    -1,    49,   467,   463,    24,
      -1,    26,    -1,    -1,   158,    -1,   300,    32,    -1,    34,
      35,   481,    37,    -1,   484,   485,    69,    70,    43,    -1,
      -1,    46,    -1,    -1,    49,    -1,    -1,   181,    -1,    -1,
     106,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     505,   506,    -1,   508,    69,    70,    99,   100,    -1,    -1,
      -1,    -1,   346,    -1,    -1,   525,   526,     5,   528,     7,
     530,   531,    10,    -1,   534,   535,   531,    -1,    -1,    17,
      -1,    -1,    -1,    -1,    99,   545,    24,    -1,    26,    -1,
     545,   106,    -1,   553,    32,   555,   556,    35,    -1,   243,
     244,    -1,    -1,    -1,    26,    43,    -1,    -1,   568,   253,
      -1,   571,    34,   568,    -1,    37,   571,   577,   578,    -1,
      -1,   581,   582,    -1,    46,    -1,   586,    49,   588,   589,
      -1,    -1,    -1,    -1,   594,   595,    -1,   597,   422,   599,
     600,   425,   426,   603,    -1,   605,   606,    69,    70,    -1,
      -1,    -1,   612,   121,    -1,     5,   300,     7,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,   143,    26,    99,   100,    -1,
      -1,    -1,    32,   467,    34,    35,    -1,    37,    -1,    -1,
     158,    -1,    -1,    43,    -1,    -1,    46,   481,    -1,    49,
     484,   485,   346,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   181,    -1,    26,    -1,    -1,    -1,    69,
      70,    -1,    -1,    34,    -1,    -1,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    -1,
      -1,   525,   526,    -1,   528,    -1,   530,   531,    -1,    99,
     534,   535,    -1,    -1,    -1,    -1,   106,    -1,    69,    70,
      -1,   545,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   553,
     121,   555,   556,    -1,    -1,   243,   244,    -1,   422,    -1,
      -1,   425,   426,    -1,   568,   253,    -1,   571,    99,   100,
      -1,    -1,   143,   577,   578,    -1,    -1,   581,   582,    -1,
      -1,    -1,   586,    -1,   588,   589,    26,   158,    -1,    -1,
     594,   595,    -1,   597,    34,   599,   600,    37,    -1,   603,
      -1,   605,   606,   467,    -1,    -1,    46,    -1,   612,    49,
     181,    26,   300,    -1,    -1,    26,    -1,   481,    -1,    34,
     484,   485,    37,    34,    -1,    26,    37,    -1,    -1,    69,
      70,    46,    -1,    34,    49,    46,    37,    -1,    49,    -1,
      -1,   121,    -1,    -1,    -1,    46,    -1,    -1,    49,    60,
      61,    -1,    -1,    -1,    69,    70,    -1,    -1,   346,    99,
     100,   525,   526,   143,   528,    -1,   530,   531,    69,    70,
     534,   535,   243,   244,    -1,    -1,    -1,    -1,   158,    -1,
      -1,   545,   253,    -1,    99,   100,    -1,    -1,    99,   553,
      -1,   555,   556,    -1,    -1,    -1,    -1,    -1,    99,   100,
      -1,   181,    -1,    -1,   568,    -1,    -1,   571,    -1,    -1,
      -1,    -1,    -1,   577,   578,    -1,    -1,   581,   582,    -1,
       3,    -1,   586,    -1,   588,   589,    -1,    -1,    11,   300,
     594,   595,    -1,   597,   422,   599,   600,   425,   426,   603,
      23,   605,   606,    -1,    -1,    -1,    -1,    -1,   612,    -1,
      33,    -1,    -1,    36,    -1,    -1,    39,    40,    41,    -1,
      -1,    44,    -1,   243,   244,    48,    -1,    -1,    -1,    52,
      -1,    -1,    55,   253,    -1,   346,    -1,    -1,    -1,   467,
       5,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,
      15,    16,    17,   481,    -1,    -1,   484,   485,    -1,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    32,    -1,    34,
      35,    -1,    37,    -1,    -1,    -1,    -1,    42,    43,    -1,
     300,    46,    47,    48,    49,    -1,    51,    -1,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,   525,   526,    -1,
     528,    -1,   530,   531,    69,    70,   534,   535,    -1,    -1,
      -1,   422,    -1,    -1,   425,   426,    -1,   545,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   553,   346,   555,   556,    -1,
      95,    96,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
     568,   106,    -1,   571,    -1,    -1,    -1,    -1,    -1,   577,
     578,    -1,    -1,   581,   582,    -1,   467,    -1,   586,    -1,
     588,   589,    -1,    -1,    -1,    -1,   594,   595,    -1,   597,
     481,   599,   600,   484,   485,   603,    -1,   605,   606,    -1,
      -1,   121,    -1,    -1,   612,    -1,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      37,    -1,   422,   143,    -1,   425,   426,    -1,    -1,    46,
      -1,    -1,    49,    -1,   525,   526,    -1,   528,   158,   530,
     531,    -1,    -1,   534,   535,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,   545,    -1,    -1,    -1,    -1,   171,
     172,   181,   553,    -1,   555,   556,    -1,   467,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,    -1,    -1,
     571,   481,    99,   100,   484,   485,   577,   578,    -1,    -1,
     581,   582,    -1,    -1,    -1,   586,    -1,   588,   589,    26,
      -1,    -1,    -1,   594,   595,    -1,   597,    34,   599,   600,
      37,    -1,   603,    -1,   605,   606,    -1,    -1,    -1,    46,
      -1,   612,    49,   243,   244,   525,   526,    -1,   528,    -1,
     530,   531,    -1,   253,   534,   535,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    -1,   545,   258,   259,   260,   261,
      -1,    -1,    -1,   553,    -1,   555,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,    -1,
      -1,   571,    99,   100,    -1,    -1,    -1,   577,   578,    -1,
     300,   581,   582,    -1,    -1,    -1,   586,    -1,   588,   589,
      -1,   163,    -1,    -1,   594,   595,   168,   597,    -1,   599,
     600,    -1,   174,   603,    -1,   605,   606,     3,    -1,     5,
      -1,     7,   612,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,   346,    23,    24,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
      36,    -1,    -1,    39,    40,    41,    -1,    43,    44,    -1,
      -1,   223,    48,    -1,    -1,    -1,    52,    -1,    54,    55,
     372,   373,   374,   375,   376,   377,   378,    -1,   380,   381,
     382,   383,   384,   385,   386,   387,   388,   389,    -1,    -1,
      -1,    26,   254,    -1,    -1,    -1,    -1,    -1,    -1,    34,
     262,    -1,    37,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    46,   422,    -1,    49,   425,   426,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    60,    61,   289,   290,    -1,
      -1,   293,    -1,   435,    69,    70,    -1,   439,    73,    74,
      -1,   303,   304,    -1,    -1,    -1,    -1,    -1,   310,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   467,    -1,    -1,
      -1,   323,    -1,    -1,    99,   100,    -1,    -1,   330,    -1,
      -1,   481,    -1,    -1,   484,   485,    -1,    -1,    -1,    -1,
      -1,   343,   344,    -1,    -1,    -1,    -1,    -1,   350,    -1,
     352,    -1,    -1,    -1,    -1,    -1,   358,    -1,    -1,    -1,
     362,    -1,    -1,   505,   506,    -1,   508,    -1,    -1,   371,
      -1,    -1,    -1,    -1,    -1,   525,   526,    -1,   528,    -1,
     530,   531,    -1,    -1,   534,   535,   163,    -1,    -1,    -1,
      -1,   168,    -1,    -1,    -1,   545,    -1,   174,    -1,    -1,
      -1,    -1,    -1,   553,    -1,   555,   556,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   568,   421,
      -1,   571,   424,    -1,    -1,    -1,   428,   577,   578,    -1,
      -1,   581,   582,    -1,    -1,   437,   586,    -1,   588,   589,
      -1,    -1,    -1,    -1,   594,   595,   223,   597,    -1,   599,
     600,     6,    -1,   603,    -1,   605,   606,    -1,   460,    14,
      -1,    16,   612,    -1,    -1,    -1,    -1,    -1,   470,   471,
      25,    26,    27,   475,    -1,    -1,    -1,   254,    -1,    34,
      -1,    -1,    37,    -1,    -1,   262,    -1,    42,    -1,    -1,
      -1,    46,    47,    48,    49,    -1,    51,    -1,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   289,   290,    69,    70,   293,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   303,    -1,    -1,    -1,
     532,   533,    57,   310,    -1,    -1,    -1,    -1,    -1,   541,
      95,    -1,    -1,    -1,    99,    -1,   323,    -1,    -1,    -1,
      -1,   106,    -1,   330,    -1,    -1,   558,    -1,    -1,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      -1,    -1,    97,   350,    99,   352,    -1,    -1,   580,    -1,
     105,   358,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
       7,     8,    -1,    10,   371,    -1,    -1,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    -1,    34,    35,    -1,
      37,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    46,
      47,    48,    49,    -1,    51,    57,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,   421,    -1,    -1,   424,    -1,    -1,
      -1,   428,    69,    70,    -1,    -1,    -1,    -1,    -1,    -1,
     437,    -1,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    -1,    -1,     5,     6,     7,    95,    96,
      10,    -1,    99,    -1,    14,    -1,    16,    17,    -1,   106,
      -1,    -1,    -1,   470,    24,    25,    26,    27,   475,    -1,
      57,    -1,    32,    -1,    34,    35,    -1,    37,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    46,    47,    48,    49,
      -1,    51,    -1,    53,    -1,    -1,    56,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    -1,    69,
      70,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
      14,    -1,    16,    17,    -1,   532,   533,    -1,    -1,    -1,
      24,    25,    26,    27,   541,    95,    96,    -1,    32,    99,
      34,    35,    -1,    37,    -1,    -1,   106,    -1,    42,    43,
      -1,   558,    46,    47,    48,    49,    -1,    51,    -1,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   580,    -1,    69,    70,     5,     6,     7,
      -1,    -1,    10,    -1,    -1,    -1,    14,    -1,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,
      -1,    95,    96,    57,    32,    99,    34,    35,    -1,    37,
      -1,    -1,   106,    -1,    42,    43,    -1,    -1,    46,    47,
      48,    49,    -1,    51,    -1,    53,    -1,    -1,    56,    -1,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    69,    70,     5,     6,     7,    -1,    -1,    10,    -1,
      -1,    -1,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    27,    -1,    95,    96,    -1,
      32,    99,    34,    35,    -1,    37,    -1,    -1,   106,    -1,
      42,    43,    -1,    -1,    46,    47,    48,    49,    -1,    51,
      -1,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,     5,
       6,     7,    -1,    -1,    10,    -1,    -1,    -1,    14,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    27,    -1,    95,    96,    -1,    32,    99,    34,    35,
      -1,    37,    -1,    -1,   106,    -1,    42,    43,    -1,    -1,
      46,    47,    48,    49,    -1,    51,    -1,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    69,    70,     5,     6,     7,    -1,    -1,
      10,    -1,    -1,    -1,    14,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    -1,    95,
      96,    -1,    32,    99,    34,    35,    -1,    37,    -1,    -1,
     106,    -1,    42,    43,    -1,    -1,    46,    47,    48,    49,
      -1,    51,    -1,    53,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,     5,     6,     7,    -1,    -1,    10,    -1,    -1,    -1,
      14,    -1,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    95,    96,    -1,    32,    99,
      34,    35,    -1,    37,    -1,    -1,   106,    -1,    42,    43,
       6,    -1,    46,    47,    48,    49,    -1,    51,    14,    53,
      16,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    25,
      26,    27,    -1,    -1,    -1,    69,    70,     5,    34,     7,
      -1,    37,    10,    -1,    -1,    -1,    42,    -1,    -1,    17,
      46,    47,    48,    49,    -1,    51,    24,    53,    26,    -1,
      56,    95,    -1,    -1,    32,    99,    34,    35,    -1,    37,
      -1,    -1,   106,    69,    70,    43,    -1,    -1,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    69,    70,    99,    -1,    73,    74,     3,    -1,     5,
     106,     7,    -1,    -1,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    24,    -1,
      26,    99,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
      36,    -1,    -1,    39,    40,    41,    -1,    43,    44,    -1,
      -1,    -1,    48,     3,    -1,     5,    52,     7,    54,    55,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,
      -1,    -1,    -1,    23,    24,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    32,    -1,    -1,    35,    36,    -1,    -1,    39,
      40,    41,    -1,    43,    44,    -1,    -1,    -1,    48,     3,
      96,     5,    52,     7,    54,    55,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    -1,    -1,    -1,    -1,    26,    23,
      24,    -1,    26,    -1,    -1,    -1,    34,    -1,    32,    37,
      -1,    35,    36,    -1,    26,    39,    40,    41,    46,    43,
      44,    49,    34,    -1,    48,    37,    96,    -1,    52,    -1,
      54,    55,    60,    61,    46,    -1,    -1,    49,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    74,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    69,    70,    -1,
      -1,    73,    74,    -1,    34,    -1,    -1,    37,    -1,    -1,
      -1,    99,    96,    26,    -1,    26,    46,    -1,   106,    49,
      -1,    34,    -1,    34,    37,    -1,    37,    99,    -1,    -1,
      60,    61,    -1,    46,   106,    46,    49,    -1,    49,    69,
      70,    -1,    -1,    73,    74,    -1,    -1,    60,    61,    60,
      61,    -1,    -1,    -1,    -1,    -1,    69,    70,    69,    70,
      73,    74,    73,    74,    26,    -1,    -1,    -1,    -1,    99,
      -1,    26,    34,    -1,    -1,    37,   106,    -1,    -1,    34,
      -1,    -1,    37,    -1,    46,    -1,    99,    49,    99,    -1,
      -1,    46,    -1,   106,    49,   106,    -1,    -1,    60,    61,
      -1,    -1,    -1,    -1,    -1,    60,    61,    69,    70,    -1,
      -1,    73,    74,    -1,    69,    70,    -1,    -1,    73,    74,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    26,    34,    -1,
      -1,    37,    -1,    95,    96,    34,    -1,    99,    37,   101,
      46,    -1,    -1,    49,    99,   100,    -1,    46,    -1,    -1,
      49,    -1,    -1,    -1,    60,    61,    -1,    -1,    -1,    -1,
      -1,    60,    61,    69,    70,    -1,    -1,    73,    74,    26,
      69,    70,    -1,    -1,    73,    74,    26,    34,    -1,    -1,
      37,    -1,    -1,    -1,    34,    -1,    -1,    37,    -1,    46,
      -1,    -1,    49,    99,   100,    -1,    46,    -1,    -1,    49,
      99,   100,    -1,    60,    61,    -1,    -1,    -1,    -1,    -1,
      60,    61,    69,    70,    -1,    -1,    73,    74,    26,    69,
      70,    -1,    -1,    73,    74,    -1,    34,    -1,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    46,    -1,
      -1,    49,    99,   100,    34,    95,    96,    37,    -1,    99,
      -1,    -1,    60,    61,    -1,    -1,    46,    -1,    -1,    49,
      -1,    69,    70,    -1,    -1,    73,    74,    -1,    -1,    -1,
      60,    61,    -1,    -1,    -1,    -1,    -1,    26,    -1,    69,
      70,    -1,    -1,    73,    74,    34,    -1,    95,    37,    -1,
      -1,    99,    -1,    26,    -1,    -1,    -1,    46,    -1,    -1,
      49,    34,    -1,    -1,    37,    -1,    -1,    -1,    98,    99,
      -1,    60,    61,    46,    -1,    -1,    49,    -1,    -1,    -1,
      69,    70,    -1,    -1,    73,    74,    -1,    60,    61,    -1,
      -1,     3,    -1,     5,    -1,     7,    69,    70,    10,    -1,
      73,    74,    -1,    -1,    -1,    17,    -1,    -1,    -1,    98,
      99,    23,    24,    -1,    26,    -1,    -1,    57,    -1,    -1,
      32,    -1,    -1,    35,    36,    -1,    99,    39,    40,    41,
      -1,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      52,    -1,    54,    55,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    -1,    -1,    97,    -1,    99,
      -1,    -1,    -1,    -1,    -1,   105
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    11,    23,    30,    33,    36,    38,    39,    40,
      41,    44,    48,    52,    55,   106,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   161,    26,   111,
     111,   122,   123,   124,   111,   122,     0,   127,   129,   132,
     126,   127,    11,    33,   134,    21,    29,    95,   136,   137,
     139,   105,   106,   107,    21,    95,   162,   163,   106,   127,
     111,   111,   114,   119,   122,   114,   120,   138,     5,     7,
      10,    17,    24,    32,    35,    43,    44,    54,    96,   112,
     113,   114,   115,   116,   117,   118,   121,   122,   123,   133,
     140,   141,   142,   143,   148,   149,   156,   157,   158,   137,
     139,   139,   111,   106,   120,    96,   133,   143,   149,   164,
     165,   166,   167,   101,   163,   136,   137,   139,   162,   163,
     101,    95,   170,   111,   150,   111,   144,   145,   146,   150,
      97,    97,    97,    99,    54,   112,   158,    96,   141,   106,
     155,   170,    50,    95,   153,   159,   139,   106,    96,   165,
     120,   137,   139,   139,   163,   120,     6,    14,    16,    25,
      27,    34,    37,    42,    46,    47,    48,    49,    51,    53,
      56,    69,    70,    96,    99,   106,   110,   111,   112,   122,
     170,   171,   172,   173,   174,   175,   177,   178,   179,   181,
     182,   183,   184,   186,   192,   194,   195,   197,   202,   203,
     204,   205,   206,   207,   211,   212,   213,   215,   216,   217,
     218,   224,   225,   239,   240,   242,   243,   244,    99,    97,
     153,   101,   106,    57,    97,   153,    98,    98,    98,   100,
     112,   151,   152,   150,   144,   150,   153,   159,   119,   154,
      46,    49,    96,   160,   171,   159,   139,   106,   111,   106,
     111,   122,   175,    99,    99,   114,   115,   119,    60,    61,
      73,    74,    99,   106,   213,   217,   222,   223,   224,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   105,    99,
      99,   222,   170,    99,   122,   215,   216,   238,   238,   222,
      63,   111,   144,    97,    99,    96,   172,   106,   106,   105,
      97,    57,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,   226,    69,    70,   100,   151,    97,   145,
      95,   147,   168,   222,    98,   146,   100,   101,   153,   106,
     153,   159,   101,    99,    99,    96,   171,    96,   106,   106,
      97,    56,   106,   174,   182,   199,   201,   222,    97,   219,
     220,   219,    99,   238,   238,   238,   238,   115,   122,   222,
     106,    62,    71,    72,    77,    79,    78,    65,    68,    31,
      58,    59,    66,    67,    82,    73,    74,    75,    76,    80,
     111,   222,   222,   106,     9,    22,   208,   209,   210,   222,
     100,   175,   222,   100,   214,   222,   111,   222,   222,   100,
      96,   101,   147,   169,   152,   119,   100,   214,   100,   214,
      96,    99,   106,   222,   106,   101,   100,   222,    97,   220,
     221,   221,   100,   214,    97,   100,   221,    97,   221,   100,
     222,   229,   230,   231,   232,   233,   234,   234,   113,   115,
     235,   235,   235,   235,   236,   237,   237,   238,   238,   238,
      99,   100,   100,    99,   170,   209,   210,   100,    98,   100,
     101,    99,    98,    96,    96,   101,   106,   100,   106,   100,
     222,   100,   200,   201,   106,   106,   222,   182,    25,    27,
      56,   111,   175,   176,   177,   180,   185,   193,   196,   198,
      98,    98,    97,   100,   238,   100,   100,   241,    63,   100,
     214,    95,   187,   170,   152,   175,   222,   100,   214,    96,
     147,   106,   106,   100,   175,   100,   100,   200,   100,   200,
     106,    99,    99,    99,    63,    18,    98,   238,   241,   227,
     100,     8,    15,    96,   188,   189,   190,   191,   100,   100,
     106,   175,   175,   100,   175,   100,   100,   200,   106,   199,
     222,   222,   176,   175,   222,   246,    63,    96,   189,   190,
      96,   171,   191,   170,   175,   175,   175,   100,   106,   222,
     106,   100,   100,    63,    96,   175,   100,   200,   106,   106,
     222,   176,   176,   176,   100,   100,   200,   100,   200,   106,
      18,   176,   176,   100,   176,   100,   100,   200,   176,   176,
     176,   176,   100,   176
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
#line 55 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "LITERAL"); ;}
    break;

  case 3:
#line 58 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "IDENTIFIER"); ;}
    break;

  case 4:
#line 61 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 5:
#line 62 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 6:
#line 66 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 7:
#line 67 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 8:
#line 70 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 9:
#line 72 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 10:
#line 73 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "BOOLEAN"); ;}
    break;

  case 11:
#line 76 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 12:
#line 77 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 13:
#line 80 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "LONG"); ;}
    break;

  case 14:
#line 81 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "BYTE"); ;}
    break;

  case 15:
#line 82 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "INT"); ;}
    break;

  case 16:
#line 83 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "CHAR"); ;}
    break;

  case 17:
#line 84 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "SHORT"); ;}
    break;

  case 18:
#line 87 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "DOUBLE"); ;}
    break;

  case 19:
#line 88 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "FLOAT"); ;}
    break;

  case 20:
#line 91 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 21:
#line 94 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 22:
#line 97 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		(yyval.ptr) = create_AST_node("ArrKind1", v);
	;}
    break;

  case 23:
#line 103 "parser.y"
    { // for multidimensional arrays 
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		(yyval.ptr) = create_AST_node("ArrKind2", v);
	;}
    break;

  case 24:
#line 109 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		(yyval.ptr) = create_AST_node("ArrKind3", v);
	;}
    break;

  case 25:
#line 119 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 26:
#line 120 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 27:
#line 123 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 28:
#line 126 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("QualName", attr);
	;}
    break;

  case 29:
#line 135 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("CompUnit1",v);
	;}
    break;

  case 30:
#line 142 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 31:
#line 143 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("CompUnit2",v);
	;}
    break;

  case 32:
#line 148 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 33:
#line 149 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 34:
#line 151 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("CompUnit3",v);
	;}
    break;

  case 35:
#line 157 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("CompUnit4",v);
	;}
    break;

  case 36:
#line 166 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 37:
#line 167 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ImportDecnRec",v);
	;}
    break;

  case 38:
#line 175 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 39:
#line 176 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("TypeDecRec",v);
	;}
    break;

  case 40:
#line 184 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (3)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("PackageDecn", v);
	;}
    break;

  case 41:
#line 192 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 42:
#line 193 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 43:
#line 196 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SingleTypeImportDecn",v); 
	;}
    break;

  case 44:
#line 203 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ImportDDec ",v); 
	;}
    break;

  case 45:
#line 210 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 46:
#line 211 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "SCLN"); ;}
    break;

  case 47:
#line 212 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 48:
#line 215 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 49:
#line 216 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Modifiers",v);
	;}
    break;

  case 50:
#line 224 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "FINAL"); ;}
    break;

  case 51:
#line 225 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "PRIVATE"); ;}
    break;

  case 52:
#line 226 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "PROTECTED"); ;}
    break;

  case 53:
#line 227 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "NATIVE"); ;}
    break;

  case 54:
#line 228 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "SYNCHRONIZED"); ;}
    break;

  case 55:
#line 229 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "STATIC"); ;}
    break;

  case 56:
#line 230 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "PUBLIC"); ;}
    break;

  case 57:
#line 231 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "TRANSIENT"); ;}
    break;

  case 58:
#line 232 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "ABSTRACT"); ;}
    break;

  case 59:
#line 233 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "VOLATILE"); ;}
    break;

  case 60:
#line 236 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (6)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (6)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (6)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (6)].ptr), "", 1);
		add_attribute(v, (yyvsp[(6) - (6)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn1", v);
	;}
    break;

  case 61:
#line 245 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn4", v);
	;}
    break;

  case 62:
#line 252 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn5", v);
	;}
    break;

  case 63:
#line 260 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn6", v);
	;}
    break;

  case 64:
#line 268 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn7", v);
	;}
    break;

  case 65:
#line 275 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn8", v);
	;}
    break;

  case 66:
#line 281 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn2", v);
	;}
    break;

  case 67:
#line 289 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassDecn3", v);
	;}
    break;

  case 68:
#line 300 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "EXTENDS"), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Super", v);
	;}
    break;

  case 69:
#line 308 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "IMPLEMENTS"), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Intfaces", v);
	;}
    break;

  case 70:
#line 316 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 71:
#line 317 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IntfaceTypeList", v);
	;}
    break;

  case 72:
#line 325 "parser.y"
    {(yyval.ptr) = create_AST_leaf("{ }", "LITERAL");;}
    break;

  case 73:
#line 326 "parser.y"
    {(yyval.ptr)=(yyvsp[(2) - (3)].ptr);;}
    break;

  case 74:
#line 330 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 75:
#line 331 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassBodyDecRec", v);
;}
    break;

  case 76:
#line 339 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 77:
#line 340 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 78:
#line 341 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 79:
#line 344 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 80:
#line 345 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 81:
#line 348 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("FieldDecn1", v);
;}
    break;

  case 82:
#line 355 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("FieldDecn2", v);
;}
    break;

  case 83:
#line 363 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 84:
#line 364 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("VariableDecltrs", v);
;}
    break;

  case 85:
#line 372 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 86:
#line 373 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str), v);
	;}
    break;

  case 87:
#line 381 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 88:
#line 382 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		(yyval.ptr) = create_AST_node("VariableDecltrId", v);
	;}
    break;

  case 89:
#line 390 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 90:
#line 391 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 91:
#line 396 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodDecn", v);
	;}
    break;

  case 92:
#line 404 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead1", v);
	;}
    break;

  case 93:
#line 412 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead2", v);
	;}
    break;

  case 94:
#line 419 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead4", v);
	;}
    break;

  case 95:
#line 425 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead5", v);
	;}
    break;

  case 96:
#line 432 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead6", v);
	;}
    break;

  case 97:
#line 438 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead7", v);
	;}
    break;

  case 98:
#line 444 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead8", v);
	;}
    break;

  case 99:
#line 449 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodHead3", v);
	;}
    break;

  case 100:
#line 460 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodDecltr1", attr);
	;}
    break;

  case 101:
#line 466 "parser.y"
    {(yyval.ptr) =(yyvsp[(1) - (3)].ptr);;}
    break;

  case 102:
#line 467 "parser.y"
    { 
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, NULL, "[ [", 0);
		(yyval.ptr) = create_AST_node("MethodDecltr2", v);
	;}
    break;

  case 103:
#line 475 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 104:
#line 476 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("FormalParamList", v);
;}
    break;

  case 105:
#line 484 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("FormalParam", v);
;}
    break;

  case 106:
#line 492 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "THROWS"), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Throws", v);
	;}
    break;

  case 107:
#line 501 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 108:
#line 502 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassTypeList", v);
;}
    break;

  case 109:
#line 511 "parser.y"
    {(yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "SCLN");;}
    break;

  case 110:
#line 512 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 111:
#line 516 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "STATIC"), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("StaticInit", v);
	;}
    break;

  case 112:
#line 524 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ConstructorDecn1", v);
	;}
    break;

  case 113:
#line 532 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ConstructorDecn3", v);
	;}
    break;

  case 114:
#line 539 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ConstructorDecn4", v);
	;}
    break;

  case 115:
#line 545 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ConstructorDecn2", v);
	;}
    break;

  case 116:
#line 555 "parser.y"
    {
		vector<treeNode> v, v2;
		add_attribute(v2, (yyvsp[(3) - (4)].ptr), "", 1);
		Node* node = create_AST_node("( )", v2);
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, node, "", 1);
		(yyval.ptr) = create_AST_node("ConstructorDecltr1", v);
	;}
    break;

  case 117:
#line 563 "parser.y"
    {	
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, NULL, "( )", 0);
		(yyval.ptr) = create_AST_node("ConstructorDecltr2", v);
	;}
    break;

  case 118:
#line 571 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ConstructorBody", v);
;}
    break;

  case 119:
#line 577 "parser.y"
    {(yyval.ptr) = create_AST_leaf("{}", "LITERAL");;}
    break;

  case 120:
#line 578 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 121:
#line 579 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 122:
#line 582 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ConstructorBody1", v);
;}
    break;

  case 123:
#line 588 "parser.y"
    {
		vector<treeNode> v;
		(yyval.ptr) = create_AST_node("ConstructorBody2", v);
;}
    break;

  case 124:
#line 592 "parser.y"
    {
		vector<treeNode> v;
		(yyval.ptr) = create_AST_node("ConstructorBody3", v);
;}
    break;

  case 125:
#line 596 "parser.y"
    {
		vector<treeNode> v;
		(yyval.ptr) = create_AST_node("ConstructorBody4", v);
;}
    break;

  case 126:
#line 603 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IntfaceDecn1", v);
;}
    break;

  case 127:
#line 611 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IntfaceDecn3", v);
;}
    break;

  case 128:
#line 618 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IntfaceDecn4", v);
;}
    break;

  case 129:
#line 624 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IntfaceDecn2", v);
;}
    break;

  case 130:
#line 635 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ExtendsIntfaces1", v);
	;}
    break;

  case 131:
#line 640 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ExtendsIntfaces2", v);
;}
    break;

  case 132:
#line 648 "parser.y"
    {(yyval.ptr) = create_AST_leaf("{ }", "EMPTY");;}
    break;

  case 133:
#line 649 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 134:
#line 652 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 135:
#line 653 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IntfaceMemberDecnRec", v);
;}
    break;

  case 136:
#line 661 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 137:
#line 662 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 138:
#line 665 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 139:
#line 668 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (2)].ptr);;}
    break;

  case 140:
#line 671 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, create_AST_leaf((yyvsp[(3) - (4)].str), ""), "", 1);
		(yyval.ptr) = create_AST_node("ArrInit1", v);
;}
    break;

  case 141:
#line 677 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ArrInit3", v);
;}
    break;

  case 142:
#line 682 "parser.y"
    {(yyval.ptr) = create_AST_leaf((yyvsp[(1) - (2)].str), "EMPTY");;}
    break;

  case 143:
#line 683 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(2) - (3)].str), ""), "", 1);
		(yyval.ptr) = create_AST_node("ArrInit2", v);
;}
    break;

  case 144:
#line 691 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("VariableInitList", v);
;}
    break;

  case 145:
#line 697 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 146:
#line 701 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 147:
#line 702 "parser.y"
    {(yyval.ptr) = create_AST_leaf("{}", "EMPTY");;}
    break;

  case 148:
#line 705 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BlockStmts", v);
;}
    break;

  case 149:
#line 711 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 150:
#line 714 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 151:
#line 715 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 152:
#line 718 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (2)].ptr);;}
    break;

  case 153:
#line 721 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("LocalVariableDecn", v);
;}
    break;

  case 154:
#line 729 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 155:
#line 730 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 156:
#line 731 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 157:
#line 732 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 158:
#line 733 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 159:
#line 734 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 160:
#line 737 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 161:
#line 738 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 162:
#line 739 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 163:
#line 740 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 164:
#line 741 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 165:
#line 744 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 166:
#line 745 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 167:
#line 746 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 168:
#line 747 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 169:
#line 748 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 170:
#line 749 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 171:
#line 750 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 172:
#line 751 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 173:
#line 752 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 174:
#line 753 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 175:
#line 754 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 176:
#line 756 "parser.y"
    {(yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "SCLN");;}
    break;

  case 177:
#line 759 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (3)].ptr);;}
    break;

  case 178:
#line 762 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (3)].ptr);;}
    break;

  case 179:
#line 765 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (2)].ptr);;}
    break;

  case 180:
#line 768 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 181:
#line 769 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 182:
#line 770 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 183:
#line 771 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 184:
#line 772 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 185:
#line 773 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 186:
#line 774 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 187:
#line 777 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IfThenStmt", v);
	;}
    break;

  case 188:
#line 785 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IfThenElseStmt", v);
	;}
    break;

  case 189:
#line 794 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("IfThenElseStmtKind", v);
	;}
    break;

  case 190:
#line 804 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SwitchStmt", v);
	;}
    break;

  case 191:
#line 812 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SwitchBlock", v);
	;}
    break;

  case 192:
#line 818 "parser.y"
    {(yyval.ptr) = create_AST_leaf("{ }", "EMPTY");;}
    break;

  case 193:
#line 819 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 194:
#line 820 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 195:
#line 823 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 196:
#line 824 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SwitchBlockStmtGroups", v);
	;}
    break;

  case 197:
#line 832 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 198:
#line 833 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SwitchLabels", v);
	;}
    break;

  case 199:
#line 841 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SwitchBlockStmtGroup", v);
	;}
    break;

  case 200:
#line 850 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SwitchLabel1", v);
	;}
    break;

  case 201:
#line 855 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, NULL, "default", 0);
		(yyval.ptr) = create_AST_node("SwitchLabel2", v); // empty?
	;}
    break;

  case 202:
#line 862 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("WhileStmt", v);
	;}
    break;

  case 203:
#line 870 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("WhileStmtKind", v);
	;}
    break;

  case 204:
#line 878 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (7)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("DoStmt", v);
	;}
    break;

  case 205:
#line 886 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 206:
#line 889 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 207:
#line 892 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (9)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (9)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (9)].ptr), "", 1);
		add_attribute(v, (yyvsp[(9) - (9)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt1", v);
	;}
    break;

  case 208:
#line 900 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(8) - (8)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt5", v);
	;}
    break;

  case 209:
#line 907 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		add_attribute(v, (yyvsp[(4) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt6", v);
	;}
    break;

  case 210:
#line 914 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (7)].ptr), "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt7", v);
	;}
    break;

  case 211:
#line 921 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, (yyvsp[(6) - (6)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt8", v);
	;}
    break;

  case 212:
#line 928 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(4) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(6) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(8) - (8)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt2", v);
	;}
    break;

  case 213:
#line 935 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(6) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(8) - (8)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt3", v);
	;}
    break;

  case 214:
#line 942 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(5) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		// add_attribute(v, $6, "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmt4", v);
	;}
    break;

  case 215:
#line 952 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (9)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (9)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (9)].ptr), "", 1);
		add_attribute(v, (yyvsp[(9) - (9)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf1", v);
	;}
    break;

  case 216:
#line 960 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(4) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(6) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(8) - (8)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf2", v);
	;}
    break;

  case 217:
#line 967 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(6) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(8) - (8)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf3", v);
	;}
    break;

  case 218:
#line 974 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(5) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		// add_attribute(v, $6, "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf4", v);
	;}
    break;

  case 219:
#line 981 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (8)].ptr), "", 1);
		add_attribute(v, (yyvsp[(8) - (8)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf5", v);
	;}
    break;

  case 220:
#line 988 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		add_attribute(v, (yyvsp[(4) - (7)].ptr), "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf6", v);
	;}
    break;

  case 221:
#line 995 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (7)].ptr), "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, (yyvsp[(7) - (7)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf7", v);
	;}
    break;

  case 222:
#line 1002 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, (yyvsp[(6) - (6)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("BasicForStmtNoShortIf8", v);
	;}
    break;

  case 223:
#line 1011 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 224:
#line 1012 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 225:
#line 1015 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 226:
#line 1018 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("StmtExprList", attr);
	;}
    break;

  case 227:
#line 1024 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 228:
#line 1027 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (3)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("CBreakStmt", v);
	;}
    break;

  case 229:
#line 1033 "parser.y"
    {(yyval.ptr) = create_AST_leaf((yyvsp[(1) - (2)].str), "BREAK");;}
    break;

  case 230:
#line 1036 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (3)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ContinueStmt", v);
	;}
    break;

  case 231:
#line 1042 "parser.y"
    {(yyval.ptr) = create_AST_leaf((yyvsp[(1) - (2)].str), "CONTINUE");;}
    break;

  case 232:
#line 1045 "parser.y"
    {(yyval.ptr) = create_AST_leaf((yyvsp[(1) - (2)].str), "RETURN");;}
    break;

  case 233:
#line 1046 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (3)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ReturnStmt", v);
	;}
    break;

  case 234:
#line 1054 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ThrowStmt", v);
	;}
    break;

  case 235:
#line 1062 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("SynchronizedStmt", v);
	;}
    break;

  case 236:
#line 1069 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("TryStmt1", v);
	;}
    break;

  case 237:
#line 1075 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("TryStmt2", v);
	;}
    break;

  case 238:
#line 1081 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("TryStmt3", v);
	;}
    break;

  case 239:
#line 1090 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(1) - (2)].ptr), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Catches", v);
	;}
    break;

  case 240:
#line 1096 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 241:
#line 1099 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(v, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("CatchClause", v);
	;}
    break;

  case 242:
#line 1108 "parser.y"
    {
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ResEnd:Finally", v);
	;}
    break;

  case 243:
#line 1116 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 244:
#line 1117 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 245:
#line 1120 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 246:
#line 1121 "parser.y"
    {(yyval.ptr) = (yyvsp[(2) - (3)].ptr);;}
    break;

  case 247:
#line 1122 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 248:
#line 1123 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 249:
#line 1124 "parser.y"
    { (yyval.ptr) = create_AST_leaf((yyvsp[(1) - (1)].str), "THIS");;}
    break;

  case 250:
#line 1125 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 251:
#line 1126 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 252:
#line 1129 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (5)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(2) - (5)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(4) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ClassInstCreationExpr1", attr);
	;}
    break;

  case 253:
#line 1136 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (4)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(2) - (4)].ptr), "", 1);
		// add_attribute(attr, $4, "", 1);
		(yyval.ptr) = create_AST_node("ClassInstCreationExpr2", attr);
	;}
    break;

  case 254:
#line 1145 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 255:
#line 1146 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Arg_list", attr);
	;}
    break;

  case 256:
#line 1156 "parser.y"
    {
		
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Field access", attr);
	;}
    break;

  case 257:
#line 1163 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (3)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("Field access", attr);
	;}
    break;

  case 258:
#line 1171 "parser.y"
    {
		vector<treeNode> v, v2;
		add_attribute(v2, (yyvsp[(3) - (4)].ptr), "", 1);
		Node* node = create_AST_node("[ ]", v2);
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, node, "", 1);
		(yyval.ptr) = create_AST_node("ArrOp1", v);
	;}
    break;

  case 259:
#line 1179 "parser.y"
    {
		vector<treeNode> v, v2;
		add_attribute(v2, (yyvsp[(3) - (4)].ptr), "", 1);
		Node* node = create_AST_node("[ ]", v2);
		add_attribute(v, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(v, node, "", 1);
		(yyval.ptr) = create_AST_node("ArrOp2", v);
	;}
    break;

  case 260:
#line 1189 "parser.y"
    { 
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (4)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodInvocation", attr);
	;}
    break;

  case 261:
#line 1195 "parser.y"
    { (yyval.ptr)= (yyvsp[(1) - (3)].ptr); ;}
    break;

  case 262:
#line 1196 "parser.y"
    {
		vector<treeNode> v, v2;
		add_attribute(v2, (yyvsp[(1) - (6)].ptr), "", 1);
		add_attribute(v2, (yyvsp[(3) - (6)].ptr), "", 1);
		Node* node = create_AST_node((yyvsp[(2) - (6)].str), v2);
		add_attribute(v, node, "", 1);
		add_attribute(v, (yyvsp[(5) - (6)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodInvocation", v);
	;}
    break;

  case 263:
#line 1205 "parser.y"
    {
		
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (5)].ptr), "", 1);
		add_attribute(attr, create_AST_leaf((yyvsp[(2) - (5)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(3) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodInvocation", attr);
	;}
    break;

  case 264:
#line 1213 "parser.y"
    {
		
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (6)].str), ""), "", 1);
		add_attribute(attr, create_AST_leaf((yyvsp[(2) - (6)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(3) - (6)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(5) - (6)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodInvocation", attr);
	;}
    break;

  case 265:
#line 1222 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (5)].str), ""), "", 1);
		add_attribute(attr, create_AST_leaf((yyvsp[(2) - (5)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(3) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("MethodInvocation", attr);
	;}
    break;

  case 266:
#line 1232 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (4)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ArrCreationExpr1", v);
	;}
    break;

  case 267:
#line 1240 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (3)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ArrCreationExpr2", v);
	;}
    break;

  case 268:
#line 1247 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (4)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (4)].ptr), "", 1);
		add_attribute(v, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ArrCreationExpr3", v);
	;}
    break;

  case 269:
#line 1255 "parser.y"
    {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf((yyvsp[(1) - (3)].str), ""), "", 1);
		add_attribute(v, (yyvsp[(2) - (3)].ptr), "", 1);
		add_attribute(v, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("ArrCreationExpr4", v);
	;}
    break;

  case 270:
#line 1264 "parser.y"
    { 
			vector<treeNode> attr;
			add_attribute(attr, (yyvsp[(1) - (2)].ptr), "", 1);
			add_attribute(attr, (yyvsp[(2) - (2)].ptr), "", 1);
			(yyval.ptr) = create_AST_node("dim_exprs",attr);
		;}
    break;

  case 271:
#line 1270 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 272:
#line 1274 "parser.y"
    {(yyval.ptr)= (yyvsp[(2) - (3)].ptr);;}
    break;

  case 273:
#line 1277 "parser.y"
    {(yyval.ptr) = create_AST_leaf("[ ]", "EMPTY_EXP") ;;}
    break;

  case 274:
#line 1278 "parser.y"
    { 
			vector<treeNode> attr;
			add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
			add_attribute(attr, create_AST_leaf("[ ]", "EMPTY_EXP"), "", 1);
			(yyval.ptr) = create_AST_node("dims",attr);
		;}
    break;

  case 275:
#line 1286 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 276:
#line 1289 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 277:
#line 1290 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 278:
#line 1293 "parser.y"
    {
							vector<treeNode> attr;
							add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
							add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
							(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str),attr);
						;}
    break;

  case 279:
#line 1301 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 280:
#line 1302 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 281:
#line 1303 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 282:
#line 1306 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 283:
#line 1307 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 284:
#line 1308 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 285:
#line 1309 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 286:
#line 1310 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 287:
#line 1311 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 288:
#line 1312 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 289:
#line 1313 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 290:
#line 1314 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 291:
#line 1315 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 292:
#line 1316 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 293:
#line 1317 "parser.y"
    { (yyval.str) = (yyvsp[(1) - (1)].str); ;}
    break;

  case 294:
#line 1320 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 295:
#line 1321 "parser.y"
    {
											vector<treeNode> attr;
											add_attribute(attr, (yyvsp[(1) - (5)].ptr), "", 1);
											add_attribute(attr, (yyvsp[(3) - (5)].ptr), "", 1);
											add_attribute(attr, (yyvsp[(5) - (5)].ptr), "", 1);
											(yyval.ptr) = create_AST_node("ternary operator",attr);
										;}
    break;

  case 296:
#line 1330 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 297:
#line 1331 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 298:
#line 1339 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 299:
#line 1340 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 300:
#line 1348 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 301:
#line 1349 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 302:
#line 1357 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 303:
#line 1358 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 304:
#line 1366 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 305:
#line 1367 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 306:
#line 1375 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 307:
#line 1376 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 308:
#line 1382 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 309:
#line 1390 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 310:
#line 1391 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 311:
#line 1397 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 312:
#line 1403 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 313:
#line 1409 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 314:
#line 1415 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 315:
#line 1424 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 316:
#line 1425 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 317:
#line 1434 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 318:
#line 1435 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 319:
#line 1441 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 320:
#line 1449 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 321:
#line 1450 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 322:
#line 1456 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 323:
#line 1462 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(1) - (3)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (3)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(2) - (3)].str) ,attr);
	;}
    break;

  case 324:
#line 1470 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 325:
#line 1471 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 326:
#line 1472 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (2)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("unary_exp_plus",attr);
	;}
    break;

  case 327:
#line 1478 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (2)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("unary_exp_minus",attr);
	;}
    break;

  case 328:
#line 1484 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 329:
#line 1487 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(1) - (2)].str),attr);
	;}
    break;

  case 330:
#line 1494 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node((yyvsp[(1) - (2)].str),attr);
	;}
    break;

  case 331:
#line 1501 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 332:
#line 1502 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (2)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("unary_exp_tilde",attr);
	;}
    break;

  case 333:
#line 1508 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf((yyvsp[(1) - (2)].str), ""), "", 1);
		add_attribute(attr, (yyvsp[(2) - (2)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("unary_exp_not",attr);
	;}
    break;

  case 334:
#line 1514 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 335:
#line 1517 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 336:
#line 1518 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 337:
#line 1519 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 338:
#line 1520 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;

  case 339:
#line 1523 "parser.y"
    {
						vector<treeNode> attr;
						add_attribute(attr, (yyvsp[(1) - (2)].ptr), "", 1);
						(yyval.ptr) = create_AST_node((yyvsp[(2) - (2)].str), attr);
				;}
    break;

  case 340:
#line 1529 "parser.y"
    {
						vector<treeNode> attr;
						add_attribute(attr, (yyvsp[(1) - (2)].ptr), "", 1);
						(yyval.ptr) = create_AST_node((yyvsp[(2) - (2)].str), attr);
				;}
    break;

  case 341:
#line 1536 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(2) - (5)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("cast_Expr1" ,attr);
	;}
    break;

  case 342:
#line 1545 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("cast_Expr2" ,attr);
	;}
    break;

  case 343:
#line 1552 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(2) - (4)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(4) - (4)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("cast_Expr3" ,attr);
	;}
    break;

  case 344:
#line 1559 "parser.y"
    {
		vector<treeNode> attr;
		add_attribute(attr, (yyvsp[(2) - (5)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(3) - (5)].ptr), "", 1);
		add_attribute(attr, (yyvsp[(5) - (5)].ptr), "", 1);
		(yyval.ptr) = create_AST_node("cast_Expr4" ,attr);
	;}
    break;

  case 345:
#line 1569 "parser.y"
    {(yyval.ptr) = (yyvsp[(1) - (1)].ptr);;}
    break;


/* Line 1267 of yacc.c.  */
#line 5277 "parser.cpp"
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


#line 1572 "parser.y"


void help(){
	fprintf(stdout, "Usage Guidelines:\n");
	fprintf(stdout, "./ans [OPTIONS]\n");
	fprintf(stdout, "Where options are:\n");
	fprintf(stdout, "\t--help: For usage guidelines\n");
	fprintf(stdout, "\t-input <file>: Passes the input java file to the parser to be read.\n");
	fprintf(stdout, "\t-output <file>: Creates the dot script containing the AST in <file>\n");
}

bool check_fp(FILE* fp, char* name)
{
	if(fp == NULL){
		fprintf(stdout, "Error: Unable to open %s. Please retry.\n", name);
		return false;
	}
	else return true; //successfully opened file 

}

int main(int argc, char** argv) 

{
	char* output_dot_file = "graph.dot";
	char* input_java_file = "test.java";
	if(argc <= 1){
		fprintf(stdout, "Please pass arguments for input and output and retry.\n");
		return 1;
	}
	for(int i = 1; i<argc; i++){
		if(!strcmp(argv[i], "--help")){
			help();
			return 0;
		}
	}
	for(int i=1;i<argc; ++i)
	{
		if(!strcmp(argv[i], "-input"))
		{
			if(i+1 >= argc || argv[i+1][0] == '-')
			{
				fprintf(stdout, "Error: Please add the input filename after \"-input\" and retry.\n");
				return 1; //error detected
			}
			else
			{
				input_java_file = argv[i+1]; //output file name
				i++;
			}
		}
		if(!strcmp(argv[i], "-output"))
		{
			if(i+1 >= argc || argv[i+1][0] == '-')
			{
				fprintf(stdout, "Error: Please add the output filename after \"-output\" and retry.\n");
				return 2; //error detected
			}
			else
			{
				output_dot_file = argv[i+1]; //output file name
				i++;
			}
		}
		if(!strcmp(argv[i], "-verbose")) verbose= true; //give better error messages 
	}
	yyin = fopen(input_java_file, "r"); // this opens the java input file
	dotfile = fopen(output_dot_file, "w"); // opens output dot file 
	if(!check_fp(yyin, input_java_file)) return 3;
	if(!check_fp(dotfile, output_dot_file)) return 4;
	fprintf(dotfile, "digraph AST {\n\tordering=out;\n");
    int column = 0;
	file = input_java_file;
	yyrestart(yyin); 
	yyparse();
	fprintf(dotfile, "}\n"); 	// Dot file has been completely written to 
	fclose(dotfile);	
	return 0;
}

int yyerror(const char *s) { 
	FILE *duplicate_input_file = fopen(file, "r");
	int count = 1;
	if(!verbose)
	{
		fprintf(stderr, "Error on line number %d: %s\n",yylineno, s);
		exit(1);
	}
	//verbose error message prints entire line. 
	char input_line[512];  //possible maximum line size 
	while (fgets(input_line, sizeof(input_line), duplicate_input_file) != NULL) {
		if (count == yylineno){
			fprintf(stderr, "Error on line number:%d\n",yylineno);
			fprintf(stderr, "Error reported by parser: %s\n",s);
			fprintf(stderr, "Check error near line: %s\n",input_line);
			return 4;
		}
		else{
			count++;
		}
	}
	fclose(duplicate_input_file);
	return -1;
}


