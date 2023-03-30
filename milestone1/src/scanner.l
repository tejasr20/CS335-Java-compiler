%{
// #include<bits/stdc++.h>
// {Comment}				{yylval.str = strdup(yytext); return COMMENT;}
#include<iostream>
#include <stdio.h>
using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include "tree.h"
#include "parser.hpp"
// #include "mini.tab.h"
int yylex();
void help();
extern int column = 0;

// extern int only_lexer;
// extern FILE* lexer_file;

void col();

%}
%option yylineno
%option noyywrap


HDig                [0-9a-fA-F]
UncMarker           [u]+
UncEsc           ("\\"|"\\\\\\"+){UncMarker}{HDig}{4}
UncInputChar   {UncEsc}|{RawInputChar}
UncInputCharNotStar {UncEsc}|{RawInputCharNotStar}
UncInputCharNotStarNotSlash {UncEsc}|{RawInputCharNotStarNotSlash}
UncInputCharNotBackSlash {UncEsc}|{RawInputCharNotBackSlash}
UncInputCharNotBackSlashNotSingleQuote {UncEsc}|{RawInputCharNotBackSlashNotSingleQuote}
UncInputCharNotBackSlashNotDoubleQuote {UncEsc}|{RawInputCharNotBackSlashNotDoubleQuote}
RawInputChar		[^\n\r]
RawInputCharNotStar [^*\n\r]
RawInputCharNotStarNotSlash [^*/\n\r]
RawInputCharNotBackSlash [^\n\r\\]
RawInputCharNotBackSlashNotDoubleQuote [^\n\r\\"]
RawInputCharNotBackSlashNotSingleQuote [^\n\r\\']
DotStar                 ".*"
LineTerminator			[\n\r]
InputChar			{UncInputChar}
InputCharNotStar {UncInputCharNotStar}
InputCharNotStarNotSlash {UncInputCharNotStarNotSlash}
InputCharNotBackSlashNotDoubleQuote {UncInputCharNotBackSlashNotDoubleQuote}
InputCharNotBackSlashNotSingleQuote {UncInputCharNotBackSlashNotSingleQuote}

Cmnt					{MultiLineCmnt}|{EOLCmnt}
MultiLineCmnt		(\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)
CmntTail				"\*"{CmntTailStar}|{NotStar}{CmntTail}
CmntTailStar			"\/"|"\*"{CmntTailStar}|{NotStarNotSlash}{CmntTail}
NotStar 				{InputCharNotStar}|{LineTerminator}
NotStarNotSlash			{InputCharNotStarNotSlash}|{LineTerminator}
EOLCmnt			"\/\/"{InputChar}*

Lit					{IntLit}|{FloatingPointLit}|{BoolLit}|{CharLit}|{StringLit}|{NullLit}

IntLit 			{DecimalIntLit}|{HexIntLit}|{OctIntLit}|{BinaryIntLit}
DecimalIntLit	{DecimalNumeral}({IntTypeSuffix})?
HexIntLit		{HexNumeral}({IntTypeSuffix})?
OctIntLit		{OctNumeral}({IntTypeSuffix})?
BinaryIntLit	{BinaryNumeral}({IntTypeSuffix})?
IntTypeSuffix		"l"|"L"

DecimalNumeral			0|{NonZeroDigit}({Digits})?|{NonZeroDigit}{Unsc}{Digits}
NonZeroDigit			[1-9]
Digits					{Digit}|{Digit}({DigitAndUnsc})?{Digit}
DigitsForFloat			{NonZeroDigit}|{NonZeroDigit}({DigitAndUnsc})?{Digit}
Digit 					0|{NonZeroDigit}
DigitAndUnsc		({DigitOrUnsc})+
DigitOrUnsc		{Digit}|"_"
Unsc 			[_]+

HexNumeral				("0x"|"0X"){HDigs}
HDigs				{HDig}|{HDig}({HDigAndUnsc})?{HDig}
HDigAndUnsc 	({HDigOrUnsc})+
HDigOrUnsc	{HDig}|"_"

OctNumeral			0{OctDigits}|0{Unsc}{OctDigits}
OctDigits				{OctDigit}|{OctDigit}({OctDigitAndUnsc})?{OctDigit}
OctDigit 				[0-7]
OctDigitAndUnsc ({OctDigitOrUnsc})+
OctDigitOrUnsc	OctDigit|"_"

BinaryNumeral 			("0b"|"0B"){BinaryDigits}
BinaryDigits			{BinaryDigit}|{BinaryDigit}({BinaryDigitAndUnsc})?{BinaryDigit}
BinaryDigit 			[01]
BinaryDigitAndUnsc ({BinaryDigitOrUnsc})+
BinaryDigitOrUnsc {BinaryDigit}|"_"

FloatingPointLit	{DecimalFloatingPointLit}|{hexFloatingPointLit}
DecimalFloatingPointLit	{Digits}"."({Digits})?({ExpPart})?({FloatTypeSuffix})?|"."{Digits}({ExpPart})?({FloatTypeSuffix})?|{Digits}{ExpPart}({FloatTypeSuffix})?|{DigitsForFloat}({ExpPart})?{FloatTypeSuffix}
ExpPart			{ExpIndicator}{SignedInt}
ExpIndicator		"e"|"E"
SignedInt			({Sign})?{Digits}
Sign 					"+"|"-"
FloatTypeSuffix			"f"|"F"|"d"|"D"

hexFloatingPointLit	{HexSignificand}{BinaryExp}({FloatTypeSuffix})?
HexSignificand			{HexNumeral}[.]?|("0x"|"0X")({HDigs})?"."{HDigs}
BinaryExp			{BinaryExpIndicator}{SignedInt}
BinaryExpIndicator	"p"|"P"

BoolLit			"true"|"false"

SingleChar			{InputCharNotBackSlashNotSingleQuote}
CharLit		(')({SingleChar}|{EscSeq})(')

StringLit			(\"){StringChar}*(\")
StringChar			{InputCharNotBackSlashNotDoubleQuote}|{EscSeq}

EscSeq			(\\)[btnfr]|{OctEsc}|"\\\\"|"\\\""|"\\'"
OctEsc				(\\)({OctDigit}|{OctDigit}{OctDigit}|{ZeroToThree}{OctDigit}{OctDigit})
ZeroToThree				[0-3]

NullLit				null

JavaLetter				[A-Za-z]|"_"|"$"
JavaLetterOrDigit		{JavaLetter}|[0-9]
IDChars			{JavaLetter}({JavaLetterOrDigit})*
ID				{IDChars}

Error					[^{Cmnt}{Lit}{ID}]

%%

[ \t\r\f\b]+ 			;
[\n\r]					;


"super" { col(); yylval.str = strdup(yytext); return SUPER;}
"byte" { col(); yylval.str = strdup(yytext); return BYTE;}
"case" { col(); yylval.str = strdup(yytext); return CASE;}
"catch" { col(); yylval.str = strdup(yytext); return CATCH;}
"implements" { col(); yylval.str = strdup(yytext); return IMPLEMENTS;}
"import" { col(); yylval.str = strdup(yytext); return IMPORT;}
"instanceof" { col(); yylval.str = strdup(yytext); return INSTANCEOF;}
"int" { col(); yylval.str = strdup(yytext); return INT;}
"char" { col(); yylval.str = strdup(yytext); return CHAR;}
"class" { col(); yylval.str = strdup(yytext); return CLASS;}
"const" { col(); yylval.str = strdup(yytext); return CONST;}
"continue" { col(); yylval.str = strdup(yytext); return CONTINUE;}
"switch" { col(); yylval.str = strdup(yytext); return SWITCH;}
"synchronized" { col(); yylval.str = strdup(yytext); return SYNCHRONIZED;}
"this" { col(); yylval.str = strdup(yytext); return THIS;}
"throw" { col(); yylval.str = strdup(yytext); return THROW;}
"throws" { col(); yylval.str = strdup(yytext); return THROWS;}
"transient" { col(); yylval.str = strdup(yytext); return TRANSIENT;}
"try" { col(); yylval.str = strdup(yytext); return TRY;}
"interface" { col(); yylval.str = strdup(yytext); return INTERFACE;}
"abstract" { col(); yylval.str = strdup(yytext); return ABSTRACT;}
"assert" { col(); yylval.str = strdup(yytext); return ASSERT;}
"boolean" { col(); yylval.str = strdup(yytext); return BOOLEAN;}
"break" { col(); yylval.str = strdup(yytext); return BREAK;}
"for" { col(); yylval.str = strdup(yytext); return FOR;}
"if" { col(); yylval.str = strdup(yytext); return IF;}
"goto" { col(); yylval.str = strdup(yytext); return GOTO;}
"private" { col(); yylval.str = strdup(yytext); return PRIVATE;}
"protected" { col(); yylval.str = strdup(yytext); return PROTECTED;}
"public" { col(); yylval.str = strdup(yytext); return PUBLIC;}
"return" { col(); yylval.str = strdup(yytext); return RETURN;}
"short" { col(); yylval.str = strdup(yytext); return SHORT;}
"static" { col(); yylval.str = strdup(yytext); return STATIC;}
"strictfp" { col(); yylval.str = strdup(yytext); return STRICTFP;}
"long" { col(); yylval.str = strdup(yytext); return LONG;}
"native" { col(); yylval.str = strdup(yytext); return NATIVE;}
"new" { col(); yylval.str = strdup(yytext); return NEW;}
"default" { col(); yylval.str = strdup(yytext); return DEFAULT;}
"do" { col(); yylval.str = strdup(yytext); return DO;}
"double" { col(); yylval.str = strdup(yytext); return DOUBLE;}
"else" { col(); yylval.str = strdup(yytext); return ELSE;}
"enum" { col(); yylval.str = strdup(yytext); return ENUM;}
"extends" { col(); yylval.str = strdup(yytext); return EXTENDS;}
"final" { col(); yylval.str = strdup(yytext); return FINAL;}
"finally" { col(); yylval.str = strdup(yytext); return FINALLY;}
"float" { col(); yylval.str = strdup(yytext); return FLOAT;}
"package" { col(); yylval.str = strdup(yytext); return PACKAGE;}
"void" { col(); yylval.str = strdup(yytext); return VOID;}
"volatile" { col(); yylval.str = strdup(yytext); return VOLATILE;}
"while" { col(); yylval.str = strdup(yytext); return WHILE;}


"+" { col(); yylval.str = strdup(yytext); return ADD;}
"-" { col(); yylval.str = strdup(yytext); return SUBTRACT;}
"*" { col(); yylval.str = strdup(yytext); return MULTIPLY;}
"/" { col(); yylval.str = strdup(yytext); return DIVISION;}
"=" { col(); yylval.str = strdup(yytext); return EQUALS;}
">" { col(); yylval.str = strdup(yytext); return GT;}
"<" { col(); yylval.str = strdup(yytext); return LT;}
"!" { col(); yylval.str = strdup(yytext); return NT;}
"~" { col(); yylval.str = strdup(yytext); return TILDA;}
"?" { col(); yylval.str = strdup(yytext); return QUESTION_MARK;}
":" { col(); yylval.str = strdup(yytext); return COLON;}
"->" { col(); yylval.str = strdup(yytext); return ARROW;}
"==" { col(); yylval.str = strdup(yytext); return EQEQ;}
">=" { col(); yylval.str = strdup(yytext); return GREQ;}
"<=" { col(); yylval.str = strdup(yytext); return LEQ;}
"<<" { col(); yylval.str = strdup(yytext); return LTLT;}
">>" { col(); yylval.str = strdup(yytext); return GRGR;}
">>>" { col(); yylval.str = strdup(yytext); return GRGRGR;}
">>=" { col(); yylval.str = strdup(yytext); return DGRGR;}
"<<=" { col(); yylval.str = strdup(yytext); return DLRLR;}
">>>=" { col(); yylval.str = strdup(yytext); return TGRGRGR;}
"!=" { col(); yylval.str = strdup(yytext); return NEQUALS;}
"++" { col(); yylval.str = strdup(yytext); return PLUSPLUS;}
"--" { col(); yylval.str = strdup(yytext); return MINUSMINUS;}
"||" { col(); yylval.str = strdup(yytext); return OR;}
"&&" { col(); yylval.str = strdup(yytext); return AND;}
"|" { col(); yylval.str = strdup(yytext); return BINARYOR;}
"&" { col(); yylval.str = strdup(yytext); return BINARYAND;}
"^" { col(); yylval.str = strdup(yytext); return POW;}
"%" { col(); yylval.str = strdup(yytext); return MOD;}
"+=" { col(); yylval.str = strdup(yytext); return PLEQ;}
"-=" { col(); yylval.str = strdup(yytext); return SBEQ;}
"*=" { col(); yylval.str = strdup(yytext); return MULEQ;}
"&=" { col(); yylval.str = strdup(yytext); return ANDEQ;}
"|=" { col(); yylval.str = strdup(yytext); return OREQ;}
"^=" { col(); yylval.str = strdup(yytext); return POWEQ;}
"/=" { col(); yylval.str = strdup(yytext); return DIVEQ;}
"%=" { col(); yylval.str = strdup(yytext); return MODEQ;}


"(" { col(); yylval.str = strdup(yytext); return OS;}
")" { col(); yylval.str = strdup(yytext); return CS;}
"@" { col(); yylval.str = strdup(yytext); return ATR;}
"..." { col(); yylval.str = strdup(yytext); return TDT;}
"." { col(); yylval.str = strdup(yytext); return FST;}
";" { col(); yylval.str = strdup(yytext); return SCLN;}
"[" { col(); yylval.str = strdup(yytext); return OSQ;}
"]" { col(); yylval.str = strdup(yytext); return CSQ;}
"{" { col(); yylval.str = strdup(yytext); return OC;}
"}" { col(); yylval.str = strdup(yytext); return CC;}
"," { col(); yylval.str = strdup(yytext); return COMMA;}
"::" { col(); yylval.str = strdup(yytext); return DISTO;}
{DotStar} { col(); yylval.str = strdup(yytext); return DST;}
{Lit}				{col();yylval.str = strdup(yytext); return LITERAL;}
{ID}			{col(); yylval.str = strdup(yytext); return IDENTIFIER;}
{Error}					{col(); yylval.str = strdup(yytext); return ERROR;}
{Cmnt} {}
%%

void col()
{
	int i=0;
	while(yytext[i]!='\0')
	{
		if (yytext[i] == '\n')
		{
			column = 0;
		}
		else if (yytext[i] == '\t')
			column += 4 - (column% 4);
		else
			column++;
		i++;
	}
}