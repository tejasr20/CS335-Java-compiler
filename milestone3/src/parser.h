#ifndef YY_parse_h_included
#define YY_parse_h_included
/*#define YY_USE_CLASS 
*/
#line 1 "/usr/share/bison++/bison.h"
/* before anything */
#ifdef c_plusplus
 #ifndef __cplusplus
  #define __cplusplus
 #endif
#endif


 #line 8 "/usr/share/bison++/bison.h"

#line 84 "parser.y"
typedef union{
	char* str;
	int number;
	Node* ptr;
	constants* num;
} yy_parse_stype;
#define YY_parse_STYPE yy_parse_stype
#ifndef YY_USE_CLASS
#define YYSTYPE yy_parse_stype
#endif

#line 21 "/usr/share/bison++/bison.h"
 /* %{ and %header{ and %union, during decl */
#ifndef YY_parse_COMPATIBILITY
 #ifndef YY_USE_CLASS
  #define  YY_parse_COMPATIBILITY 1
 #else
  #define  YY_parse_COMPATIBILITY 0
 #endif
#endif

#if YY_parse_COMPATIBILITY != 0
/* backward compatibility */
 #ifdef YYLTYPE
  #ifndef YY_parse_LTYPE
   #define YY_parse_LTYPE YYLTYPE
/* WARNING obsolete !!! user defined YYLTYPE not reported into generated header */
/* use %define LTYPE */
  #endif
 #endif
/*#ifdef YYSTYPE*/
  #ifndef YY_parse_STYPE
   #define YY_parse_STYPE YYSTYPE
  /* WARNING obsolete !!! user defined YYSTYPE not reported into generated header */
   /* use %define STYPE */
  #endif
/*#endif*/
 #ifdef YYDEBUG
  #ifndef YY_parse_DEBUG
   #define  YY_parse_DEBUG YYDEBUG
   /* WARNING obsolete !!! user defined YYDEBUG not reported into generated header */
   /* use %define DEBUG */
  #endif
 #endif 
 /* use goto to be compatible */
 #ifndef YY_parse_USE_GOTO
  #define YY_parse_USE_GOTO 1
 #endif
#endif

/* use no goto to be clean in C++ */
#ifndef YY_parse_USE_GOTO
 #define YY_parse_USE_GOTO 0
#endif

#ifndef YY_parse_PURE

 #line 65 "/usr/share/bison++/bison.h"

#line 65 "/usr/share/bison++/bison.h"
/* YY_parse_PURE */
#endif


 #line 68 "/usr/share/bison++/bison.h"

#line 68 "/usr/share/bison++/bison.h"
/* prefix */

#ifndef YY_parse_DEBUG

 #line 71 "/usr/share/bison++/bison.h"

#line 71 "/usr/share/bison++/bison.h"
/* YY_parse_DEBUG */
#endif

#ifndef YY_parse_LSP_NEEDED

 #line 75 "/usr/share/bison++/bison.h"

#line 75 "/usr/share/bison++/bison.h"
 /* YY_parse_LSP_NEEDED*/
#endif

/* DEFAULT LTYPE*/
#ifdef YY_parse_LSP_NEEDED
 #ifndef YY_parse_LTYPE
  #ifndef BISON_YYLTYPE_ISDECLARED
   #define BISON_YYLTYPE_ISDECLARED
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;
  #endif

  #define YY_parse_LTYPE yyltype
 #endif
#endif

/* DEFAULT STYPE*/
#ifndef YY_parse_STYPE
 #define YY_parse_STYPE int
#endif

/* DEFAULT MISCELANEOUS */
#ifndef YY_parse_PARSE
 #define YY_parse_PARSE yyparse
#endif

#ifndef YY_parse_LEX
 #define YY_parse_LEX yylex
#endif

#ifndef YY_parse_LVAL
 #define YY_parse_LVAL yylval
#endif

#ifndef YY_parse_LLOC
 #define YY_parse_LLOC yylloc
#endif

#ifndef YY_parse_CHAR
 #define YY_parse_CHAR yychar
#endif

#ifndef YY_parse_NERRS
 #define YY_parse_NERRS yynerrs
#endif

#ifndef YY_parse_DEBUG_FLAG
 #define YY_parse_DEBUG_FLAG yydebug
#endif

#ifndef YY_parse_ERROR
 #define YY_parse_ERROR yyerror
#endif

#ifndef YY_parse_PARSE_PARAM
 #ifndef __STDC__
  #ifndef __cplusplus
   #ifndef YY_USE_CLASS
    #define YY_parse_PARSE_PARAM
    #ifndef YY_parse_PARSE_PARAM_DEF
     #define YY_parse_PARSE_PARAM_DEF
    #endif
   #endif
  #endif
 #endif
 #ifndef YY_parse_PARSE_PARAM
  #define YY_parse_PARSE_PARAM void
 #endif
#endif

/* TOKEN C */
#ifndef YY_USE_CLASS

 #ifndef YY_parse_PURE
  #ifndef yylval
   extern YY_parse_STYPE YY_parse_LVAL;
  #else
   #if yylval != YY_parse_LVAL
    extern YY_parse_STYPE YY_parse_LVAL;
   #else
    #warning "Namespace conflict, disabling some functionality (bison++ only)"
   #endif
  #endif
 #endif


 #line 169 "/usr/share/bison++/bison.h"
#define	ABSTRACT	258
#define	ASSERT	259
#define	BOOLEAN	260
#define	BREAK	261
#define	BYTE	262
#define	CASE	263
#define	CATCH	264
#define	CHAR	265
#define	CLASS	266
#define	COMMENT	267
#define	CONST	268
#define	CONTINUE	269
#define	DEFAULT	270
#define	DO	271
#define	DOUBLE	272
#define	ELSE	273
#define	ENUM	274
#define	ERROR	275
#define	EXTENDS	276
#define	FINALLY	277
#define	FINAL	278
#define	FLOAT	279
#define	FOR	280
#define	IDENTIFIER	281
#define	IF	282
#define	GOTO	283
#define	IMPLEMENTS	284
#define	IMPORT	285
#define	INSTANCEOF	286
#define	INT	287
#define	INTERFACE	288
#define	LITERAL	289
#define	LONG	290
#define	NATIVE	291
#define	NEW	292
#define	PACKAGE	293
#define	PRIVATE	294
#define	PROTECTED	295
#define	PUBLIC	296
#define	RETURN	297
#define	SHORT	298
#define	STATIC	299
#define	STRICTFP	300
#define	SUPER	301
#define	SWITCH	302
#define	SYNCHRONIZED	303
#define	THIS	304
#define	THROWS	305
#define	THROW	306
#define	TRANSIENT	307
#define	TRY	308
#define	VOID	309
#define	VOLATILE	310
#define	WHILE	311
#define	EQUALS	312
#define	GT	313
#define	LT	314
#define	NT	315
#define	TILDA	316
#define	QUESTION_MARK	317
#define	COLON	318
#define	ARROW	319
#define	EQEQ	320
#define	GREQ	321
#define	LEQ	322
#define	NEQUALS	323
#define	PLUSPLUS	324
#define	MINUSMINUS	325
#define	OR	326
#define	AND	327
#define	ADD	328
#define	SUBTRACT	329
#define	MULTIPLY	330
#define	DIVISION	331
#define	BINARYOR	332
#define	BINARYAND	333
#define	POW	334
#define	MOD	335
#define	GRGR	336
#define	LTLT	337
#define	GRGRGR	338
#define	PLEQ	339
#define	SBEQ	340
#define	MULEQ	341
#define	ANDEQ	342
#define	OREQ	343
#define	POWEQ	344
#define	DIVEQ	345
#define	MODEQ	346
#define	DGRGR	347
#define	DLRLR	348
#define	TGRGRGR	349
#define	OC	350
#define	CC	351
#define	OSQ	352
#define	CSQ	353
#define	OS	354
#define	CS	355
#define	COMMA	356
#define	DISTO	357
#define	ATR	358
#define	TDT	359
#define	FST	360
#define	SCLN	361
#define	DST	362
#define	STRING_LITERAL	363
#define	STRING	364
#define	CONST_LITERAL	365


#line 169 "/usr/share/bison++/bison.h"
 /* #defines token */
/* after #define tokens, before const tokens S5*/
#else
 #ifndef YY_parse_CLASS
  #define YY_parse_CLASS parse
 #endif

 #ifndef YY_parse_INHERIT
  #define YY_parse_INHERIT
 #endif

 #ifndef YY_parse_MEMBERS
  #define YY_parse_MEMBERS 
 #endif

 #ifndef YY_parse_LEX_BODY
  #define YY_parse_LEX_BODY  
 #endif

 #ifndef YY_parse_ERROR_BODY
  #define YY_parse_ERROR_BODY  
 #endif

 #ifndef YY_parse_CONSTRUCTOR_PARAM
  #define YY_parse_CONSTRUCTOR_PARAM
 #endif
 /* choose between enum and const */
 #ifndef YY_parse_USE_CONST_TOKEN
  #define YY_parse_USE_CONST_TOKEN 0
  /* yes enum is more compatible with flex,  */
  /* so by default we use it */ 
 #endif
 #if YY_parse_USE_CONST_TOKEN != 0
  #ifndef YY_parse_ENUM_TOKEN
   #define YY_parse_ENUM_TOKEN yy_parse_enum_token
  #endif
 #endif

class YY_parse_CLASS YY_parse_INHERIT
{
public: 
 #if YY_parse_USE_CONST_TOKEN != 0
  /* static const int token ... */
  
 #line 212 "/usr/share/bison++/bison.h"
static const int ABSTRACT;
static const int ASSERT;
static const int BOOLEAN;
static const int BREAK;
static const int BYTE;
static const int CASE;
static const int CATCH;
static const int CHAR;
static const int CLASS;
static const int COMMENT;
static const int CONST;
static const int CONTINUE;
static const int DEFAULT;
static const int DO;
static const int DOUBLE;
static const int ELSE;
static const int ENUM;
static const int ERROR;
static const int EXTENDS;
static const int FINALLY;
static const int FINAL;
static const int FLOAT;
static const int FOR;
static const int IDENTIFIER;
static const int IF;
static const int GOTO;
static const int IMPLEMENTS;
static const int IMPORT;
static const int INSTANCEOF;
static const int INT;
static const int INTERFACE;
static const int LITERAL;
static const int LONG;
static const int NATIVE;
static const int NEW;
static const int PACKAGE;
static const int PRIVATE;
static const int PROTECTED;
static const int PUBLIC;
static const int RETURN;
static const int SHORT;
static const int STATIC;
static const int STRICTFP;
static const int SUPER;
static const int SWITCH;
static const int SYNCHRONIZED;
static const int THIS;
static const int THROWS;
static const int THROW;
static const int TRANSIENT;
static const int TRY;
static const int VOID;
static const int VOLATILE;
static const int WHILE;
static const int EQUALS;
static const int GT;
static const int LT;
static const int NT;
static const int TILDA;
static const int QUESTION_MARK;
static const int COLON;
static const int ARROW;
static const int EQEQ;
static const int GREQ;
static const int LEQ;
static const int NEQUALS;
static const int PLUSPLUS;
static const int MINUSMINUS;
static const int OR;
static const int AND;
static const int ADD;
static const int SUBTRACT;
static const int MULTIPLY;
static const int DIVISION;
static const int BINARYOR;
static const int BINARYAND;
static const int POW;
static const int MOD;
static const int GRGR;
static const int LTLT;
static const int GRGRGR;
static const int PLEQ;
static const int SBEQ;
static const int MULEQ;
static const int ANDEQ;
static const int OREQ;
static const int POWEQ;
static const int DIVEQ;
static const int MODEQ;
static const int DGRGR;
static const int DLRLR;
static const int TGRGRGR;
static const int OC;
static const int CC;
static const int OSQ;
static const int CSQ;
static const int OS;
static const int CS;
static const int COMMA;
static const int DISTO;
static const int ATR;
static const int TDT;
static const int FST;
static const int SCLN;
static const int DST;
static const int STRING_LITERAL;
static const int STRING;
static const int CONST_LITERAL;


#line 212 "/usr/share/bison++/bison.h"
 /* decl const */
 #else
  enum YY_parse_ENUM_TOKEN { YY_parse_NULL_TOKEN=0
  
 #line 215 "/usr/share/bison++/bison.h"
	,ABSTRACT=258
	,ASSERT=259
	,BOOLEAN=260
	,BREAK=261
	,BYTE=262
	,CASE=263
	,CATCH=264
	,CHAR=265
	,CLASS=266
	,COMMENT=267
	,CONST=268
	,CONTINUE=269
	,DEFAULT=270
	,DO=271
	,DOUBLE=272
	,ELSE=273
	,ENUM=274
	,ERROR=275
	,EXTENDS=276
	,FINALLY=277
	,FINAL=278
	,FLOAT=279
	,FOR=280
	,IDENTIFIER=281
	,IF=282
	,GOTO=283
	,IMPLEMENTS=284
	,IMPORT=285
	,INSTANCEOF=286
	,INT=287
	,INTERFACE=288
	,LITERAL=289
	,LONG=290
	,NATIVE=291
	,NEW=292
	,PACKAGE=293
	,PRIVATE=294
	,PROTECTED=295
	,PUBLIC=296
	,RETURN=297
	,SHORT=298
	,STATIC=299
	,STRICTFP=300
	,SUPER=301
	,SWITCH=302
	,SYNCHRONIZED=303
	,THIS=304
	,THROWS=305
	,THROW=306
	,TRANSIENT=307
	,TRY=308
	,VOID=309
	,VOLATILE=310
	,WHILE=311
	,EQUALS=312
	,GT=313
	,LT=314
	,NT=315
	,TILDA=316
	,QUESTION_MARK=317
	,COLON=318
	,ARROW=319
	,EQEQ=320
	,GREQ=321
	,LEQ=322
	,NEQUALS=323
	,PLUSPLUS=324
	,MINUSMINUS=325
	,OR=326
	,AND=327
	,ADD=328
	,SUBTRACT=329
	,MULTIPLY=330
	,DIVISION=331
	,BINARYOR=332
	,BINARYAND=333
	,POW=334
	,MOD=335
	,GRGR=336
	,LTLT=337
	,GRGRGR=338
	,PLEQ=339
	,SBEQ=340
	,MULEQ=341
	,ANDEQ=342
	,OREQ=343
	,POWEQ=344
	,DIVEQ=345
	,MODEQ=346
	,DGRGR=347
	,DLRLR=348
	,TGRGRGR=349
	,OC=350
	,CC=351
	,OSQ=352
	,CSQ=353
	,OS=354
	,CS=355
	,COMMA=356
	,DISTO=357
	,ATR=358
	,TDT=359
	,FST=360
	,SCLN=361
	,DST=362
	,STRING_LITERAL=363
	,STRING=364
	,CONST_LITERAL=365


#line 215 "/usr/share/bison++/bison.h"
 /* enum token */
     }; /* end of enum declaration */
 #endif
public:
 int YY_parse_PARSE(YY_parse_PARSE_PARAM);
 virtual void YY_parse_ERROR(char *msg) YY_parse_ERROR_BODY;
 #ifdef YY_parse_PURE
  #ifdef YY_parse_LSP_NEEDED
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL,YY_parse_LTYPE *YY_parse_LLOC) YY_parse_LEX_BODY;
  #else
   virtual int  YY_parse_LEX(YY_parse_STYPE *YY_parse_LVAL) YY_parse_LEX_BODY;
  #endif
 #else
  virtual int YY_parse_LEX() YY_parse_LEX_BODY;
  YY_parse_STYPE YY_parse_LVAL;
  #ifdef YY_parse_LSP_NEEDED
   YY_parse_LTYPE YY_parse_LLOC;
  #endif
  int YY_parse_NERRS;
  int YY_parse_CHAR;
 #endif
 #if YY_parse_DEBUG != 0
  public:
   int YY_parse_DEBUG_FLAG;	/*  nonzero means print parse trace	*/
 #endif
public:
 YY_parse_CLASS(YY_parse_CONSTRUCTOR_PARAM);
public:
 YY_parse_MEMBERS 
};
/* other declare folow */
#endif


#if YY_parse_COMPATIBILITY != 0
 /* backward compatibility */
 /* Removed due to bison problems
 /#ifndef YYSTYPE
 / #define YYSTYPE YY_parse_STYPE
 /#endif*/

 #ifndef YYLTYPE
  #define YYLTYPE YY_parse_LTYPE
 #endif
 #ifndef YYDEBUG
  #ifdef YY_parse_DEBUG 
   #define YYDEBUG YY_parse_DEBUG
  #endif
 #endif

#endif
/* END */

 #line 267 "/usr/share/bison++/bison.h"
#endif
