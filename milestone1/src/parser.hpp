/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "parser.y"
{
	char* str;
	int number;
	Node* ptr;
}
/* Line 1529 of yacc.c.  */
#line 269 "parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

