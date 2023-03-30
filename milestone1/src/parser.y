%{
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
%}

%union{
	char* str;
	int number;
	Node* ptr;
}

%start CompUnit

%token<str> ABSTRACT ASSERT BOOLEAN BREAK BYTE CASE CATCH CHAR CLASS COMMENT CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM ERROR
%token<str> EXTENDS FINALLY FINAL FLOAT FOR IDENTIFIER IF GOTO IMPLEMENTS IMPORT INSTANCEOF INT  INTERFACE  LITERAL LONG NATIVE NEW PACKAGE PRIVATE PROTECTED PUBLIC RETURN SHORT STATIC STRICTFP SUPER SWITCH SYNCHRONIZED THIS
%token<str> THROWS THROW TRANSIENT TRY VOID VOLATILE WHILE EQUALS GT LT NT TILDA QUESTION_MARK COLON ARROW EQEQ GREQ LEQ NEQUALS PLUSPLUS MINUSMINUS OR AND ADD SUBTRACT MULTIPLY DIVISION BINARYOR
%token<str> BINARYAND POW MOD GRGR LTLT GRGRGR PLEQ SBEQ MULEQ ANDEQ OREQ POWEQ DIVEQ MODEQ DGRGR DLRLR TGRGRGR OC CC OSQ CSQ OS CS COMMA DISTO ATR TDT FST SCLN DST
 
%type <str> AssignOp 
%type <ptr> AbstractMethod AddExpr AndExpr ArgLst ArrOp NewArr ArrInit ArrKind Assign AssignExpr 
%type <ptr> ForStmt ForStmtKind Block BlockStmt BlockStmts BreakStmt CastExpr CatchClause Catches ClassBody ClassBodyDec ClassBodyDecRec ClassDec ClassCreation MemberDec ClassOrIntfaceType ClassType ClassTypeList CompUnit ConditionAndExpr ConditionExpr ConditionOrExpr ConstantDec ConstExpr ConstructorBody ConstructorDecn ConstructorDecltr ContinueStmt
%type <ptr> DimExpr DimExprs Dims DoStmt EmptyStmt EqExpr ExclusiveOrExpr ExplicitConstructorInvocation Expr ExprStmt ExtendsIntfaces FieldAccess FieldDecn ResEnd FloatingPoint ForInit FormalParam FormalParamList ForStatement ForStatementKind ForUpdate Identifier IfThenElseStmt
%type <ptr> IfThenElseStmtKind IfThenStmt ImportDecn ImportDecnRec InclusiveOrExpr Integers IntfaceBody IntfaceDecn IntfaceMemberDecn IntfaceMemberDecnRec Intfaces IntfaceType IntfaceTypeList LabeledStmt LabeledStmtNoShortIf LeftHandSide Literal LocalVariableDecn LocalVariableDecnStmt MethodBody MethodDecn MethodDecltr MethodHead
%type <ptr> MethodInvocation Modifier Modifiers MultExpr Name Numbers PackageDecn PostDecrementExpr PostfixExpr PostIncrementExpr PreDecExpr PreIncExpr Primary PrimaryNoNewArr PrimitiveType QualName RefType RtlExpr ReturnStmt ShiftExpr SimpleName SingleTypeImportDecn Stmt StmtExpr StmtExprList
%type <ptr> StmtKind StmtWithoutTrailingSubStmt StaticInit Super SwitchBlock SwitchBlockStmtGroup SwitchBlockStmtGroups SwitchLabel SwitchLabels SwitchStmt SynchronizedStmt Throws ThrowStmt TryStmt Type TypeDec TypeDecRec ImportDDec UnaryExpr UnaryExprExtra VariableDecltr VariableDecltrId VariableDecltrs VariableInit VariableInitList WhileStmt WhileStmtKind

%left ';'


%%


Literal  :  LITERAL 	{ $$ = create_AST_leaf($1, "LITERAL"); }																				
			;

Identifier  :  IDENTIFIER 	{ $$ = create_AST_leaf($1, "IDENTIFIER"); }																			
		 ;

Type  :  RefType 		{$$ = $1;}																	
	  |	 PrimitiveType 	{$$ = $1;}																		
	  ;


RefType  : ArrKind 		{$$ = $1;}												
			   | ClassOrIntfaceType 		{$$ = $1;}	 																	
			   ;

ClassOrIntfaceType  :  Name {$$ = $1;}																	
					  ;
PrimitiveType  : Numbers 	{$$ = $1;}																
			   | BOOLEAN 		{ $$ = create_AST_leaf($1, "BOOLEAN"); }  															
			   ;

Numbers  : FloatingPoint 	 {$$ = $1;}																
			 | Integers {$$ = $1;} 																	
			 ;

Integers  :  LONG 	{ $$ = create_AST_leaf($1, "LONG"); }																				
			  |  BYTE 	{ $$ = create_AST_leaf($1, "BYTE"); } 																				
			  |  INT 	{ $$ = create_AST_leaf($1, "INT"); }																				
			  |  CHAR 	{ $$ = create_AST_leaf($1, "CHAR"); }																				
			  |  SHORT 	{ $$ = create_AST_leaf($1, "SHORT"); }																				
			  ;

FloatingPoint  :   DOUBLE 	{ $$ = create_AST_leaf($1, "DOUBLE"); }																	
			  	   |   FLOAT { $$ = create_AST_leaf($1, "FLOAT"); }																		
			  	   ;

ClassType  :  ClassOrIntfaceType  	{$$ = $1;}																
		   ;

IntfaceType  :  ClassOrIntfaceType 	{$$ = $1;}														
				;

ArrKind  :  PrimitiveType OSQ CSQ 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("ArrKind1", v);
	}	
	  |  ArrKind OSQ CSQ 			{ // for multidimensional arrays 
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("ArrKind2", v);
	}																			
		   |  Name OSQ CSQ 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("ArrKind3", v);
	}																	
		 											
		   ;


Name  :  QualName		{$$ = $1;}																
	  |  SimpleName 	{$$ = $1;}																			
	  ;

SimpleName  :  Identifier {$$ = $1;}																		
			;

QualName  :  Name FST Identifier {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("QualName", attr);
	}															
			   ;


CompUnit  :  PackageDecn ImportDecnRec TypeDecRec {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("CompUnit1",v);
	}							
				 |  TypeDecRec 		{$$ = $1;}														
				 |  PackageDecn ImportDecnRec {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		$$ = create_AST_node("CompUnit2",v);
	}																		
				 |  ImportDecnRec 		{$$ = $1;}														
				 |  PackageDecn 	{$$ = $1;}																
			 
				 |  ImportDecnRec TypeDecRec {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("CompUnit3",v);
	}																			
				 |  PackageDecn TypeDecRec		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("CompUnit4",v);
	}																	
	
				 ;

ImportDecnRec  :  ImportDecn 		{$$ = $1;}														
					  |  ImportDecnRec ImportDecn 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ImportDecnRec",v);
	}																							
					  ;

TypeDecRec  :  TypeDec 			{$$ = $1;}														
					|  TypeDecRec TypeDec 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("TypeDecRec",v);
	}																										
					;

PackageDecn  :  PACKAGE Name SCLN 		{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("PackageDecn", v);
	}																										
					;

ImportDecn  :   ImportDDec 	{$$ = $1;}										
				   |   SingleTypeImportDecn 		{$$ = $1;}													
				   ;
 
SingleTypeImportDecn  :  IMPORT Name SCLN 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("SingleTypeImportDecn",v); 
	}																							
							   ;

ImportDDec  :  IMPORT Name DST SCLN 	 {
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ImportDDec ",v); 
	}																																					
							   ;

TypeDec  : IntfaceDecn 	{$$ = $1;}																	
				 | SCLN 	{ $$ = create_AST_leaf($1, "SCLN"); }																			
				 | ClassDec  {$$ = $1;} 															
				 ;

Modifiers  :  Modifier  				{$$ = $1;}																
		   |  Modifiers Modifier 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("Modifiers",v);
	}																															
		   ;

Modifier  :  FINAL 				{ $$ = create_AST_leaf($1, "FINAL"); }																			
		  |  PRIVATE 		{ $$ = create_AST_leaf($1, "PRIVATE"); }																			
		  |  PROTECTED	 	{ $$ = create_AST_leaf($1, "PROTECTED"); }						 													
		  |  NATIVE 			{ $$ = create_AST_leaf($1, "NATIVE"); }																		
		  |  SYNCHRONIZED 		{ $$ = create_AST_leaf($1, "SYNCHRONIZED"); }																		
		  |  STATIC 		{ $$ = create_AST_leaf($1, "STATIC"); }																			
		  |  PUBLIC 		{ $$ = create_AST_leaf($1, "PUBLIC"); } 																		
		  |  TRANSIENT 			{ $$ = create_AST_leaf($1, "TRANSIENT"); }																			
		  |  ABSTRACT 		{ $$ = create_AST_leaf($1, "ABSTRACT"); }																					
		  |  VOLATILE 			{ $$ = create_AST_leaf($1, "VOLATILE"); }																		
		  ;

ClassDec  :  Modifiers CLASS Identifier Super Intfaces ClassBody 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $6, "", 1);
		$$ = create_AST_node("ClassDecn1", v);
	}							
							  |  CLASS Identifier Intfaces ClassBody 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ClassDecn4", v);
	}																			
				  |  Modifiers CLASS Identifier Super ClassBody 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("ClassDecn5", v);
	}																	
				  |  CLASS Identifier Super ClassBody 		{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ClassDecn6", v);
	}																			
			
				   |  Modifiers CLASS Identifier ClassBody 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ClassDecn7", v);
	}																			
				  |  CLASS Identifier ClassBody 		{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ClassDecn8", v);
	}	
				  |  CLASS Identifier Super Intfaces ClassBody 			{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("ClassDecn2", v);
	}															
				  |  Modifiers CLASS Identifier Intfaces ClassBody 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("ClassDecn3", v);
	}															
																					
				  ;

Super  :  EXTENDS ClassType  		{
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "EXTENDS"), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("Super", v);
	}																													
	   ;

Intfaces  :  IMPLEMENTS IntfaceTypeList 	{
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "IMPLEMENTS"), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("Intfaces", v);
	}														
			;

IntfaceTypeList  :  IntfaceType 	{$$ = $1;}																
				   |  IntfaceTypeList COMMA IntfaceType 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("IntfaceTypeList", v);
	}											
				   ;

ClassBody  :  OC CC 	{$$ = create_AST_leaf("{ }", "LITERAL");}																				
		   |  OC ClassBodyDecRec CC 		{$$=$2;}											
				   ;													
		   ;

ClassBodyDecRec  :  ClassBodyDec 	{$$ = $1;}													
			  |  ClassBodyDecRec ClassBodyDec 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ClassBodyDecRec", v);
}																					
			  ;

ClassBodyDec  :  ConstructorDecn {$$ = $1;}												
					  |  StaticInit 		{$$ = $1;}														
					  |  MemberDec {$$ = $1;} 													
					  ;

MemberDec  :  MethodDecn 	{$$ = $1;} 														
						|  FieldDecn 	{$$ = $1;}														
						;

FieldDecn  :  Modifiers Type VariableDecltrs SCLN 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("FieldDecn1", v);
}																										
				  |  Type VariableDecltrs SCLN 				{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("FieldDecn2", v);
}																											
				  ;

VariableDecltrs  :  VariableDecltr 	{$$ = $1;}														
					 |  VariableDecltrs COMMA VariableDecltr 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("VariableDecltrs", v);
}																										/**/
					 ;

VariableDecltr  :  VariableDecltrId 	{$$ = $1;}														
					|  VariableDecltrId EQUALS VariableInit {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node($2, v);
	}										
					;

VariableDecltrId  :  Identifier 		{$$ = $1;}															
					  |  VariableDecltrId OSQ CSQ {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("VariableDecltrId", v);
	}												
					  ;

VariableInit  :  Expr 			{$$ = $1;}															
					 |  ArrInit 	{$$ = $1;}															
					 ;



MethodDecn  :  MethodHead MethodBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("MethodDecn", v);
	}																											
				   ;

MethodHead  :  Modifiers Type MethodDecltr Throws {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("MethodHead1", v);
	}												
			  |  Type MethodDecltr Throws 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("MethodHead2", v);
	}	
	          |  Type MethodDecltr 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("MethodHead4", v);
	}																											
			  |  Modifiers VOID MethodDecltr Throws {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("MethodHead5", v);
	}																							
			  |  VOID MethodDecltr Throws 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("MethodHead6", v);
	}																									
			  |  Modifiers VOID MethodDecltr 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("MethodHead7", v);
	}																								
			  |  VOID MethodDecltr 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("MethodHead8", v);
	}																									
			  |  Modifiers Type MethodDecltr {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("MethodHead3", v);
	}																									
			  																											
			  ;


MethodDecltr  :  Identifier OS FormalParamList CS  {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("MethodDecltr1", attr);
	}											
				  |  Identifier OS CS 	{$$ =$1;}															
				  |  MethodDecltr OSQ OSQ 		{ 
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ [", 0);
		$$ = create_AST_node("MethodDecltr2", v);
	}												
				  ;

FormalParamList  :  FormalParam 	{$$ = $1;}															
					 |  FormalParamList COMMA FormalParam  	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("FormalParamList", v);
}																										
					 ;

FormalParam  :  Type VariableDecltrId 			{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("FormalParam", v);
}																											
				  ;

Throws  :  THROWS ClassTypeList {
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "THROWS"), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("Throws", v);
	}									
																
		;

ClassTypeList  :  ClassType 		{$$ = $1;}																	
			   |  ClassTypeList COMMA ClassType 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ClassTypeList", v);
}																															
			   ;


MethodBody  : SCLN  	{$$ = create_AST_leaf($1, "SCLN");}																	
			| Block 	{$$ = $1;}																						
			;


StaticInit  :  STATIC Block 		{
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "STATIC"), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("StaticInit", v);
	}																					
				   ;

ConstructorDecn  :  Modifiers ConstructorDecltr Throws ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ConstructorDecn1", v);
	}												
						|  Modifiers ConstructorDecltr ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ConstructorDecn3", v);
	}											
						|  ConstructorDecltr ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ConstructorDecn4", v);
	}				
						|  ConstructorDecltr Throws ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ConstructorDecn2", v);
	}											
															
						;

ConstructorDecltr  :  SimpleName OS FormalParamList CS 	{
		vector<treeNode> v, v2;
		add_attribute(v2, $3, "", 1);
		Node* node = create_AST_node("( )", v2);
		add_attribute(v, $1, "", 1);
		add_attribute(v, node, "", 1);
		$$ = create_AST_node("ConstructorDecltr1", v);
	}						
					   |  SimpleName OS CS 	{	
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "( )", 0);
		$$ = create_AST_node("ConstructorDecltr2", v);
	}													
					   ;

ConstructorBody  :  OC ExplicitConstructorInvocation BlockStmts CC 			{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ConstructorBody", v);
}																		
				 |  OC CC	{$$ = create_AST_leaf("{}", "LITERAL");}																				
				 |  OC ExplicitConstructorInvocation CC 	{$$ = $2;}												
				 |  OC BlockStmts CC 	{$$ = $2;}														
				 ;

ExplicitConstructorInvocation  :  THIS OS ArgLst CS SCLN 		{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ConstructorBody1", v);
}																											
							   |  THIS OS CS SCLN 
							   {
		vector<treeNode> v;
		$$ = create_AST_node("ConstructorBody2", v);
}																								
							   |  SUPER OS ArgLst CS SCLN {
		vector<treeNode> v;
		$$ = create_AST_node("ConstructorBody3", v);
}																			
							   |  SUPER OS CS SCLN 	{
		vector<treeNode> v;
		$$ = create_AST_node("ConstructorBody4", v);
}																											
							  ;


IntfaceDecn  :  Modifiers INTERFACE Identifier ExtendsIntfaces IntfaceBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("IntfaceDecn1", v);
}																						
									  |  Modifiers INTERFACE Identifier IntfaceBody 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("IntfaceDecn3", v);
}															
					  |  INTERFACE Identifier IntfaceBody 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("IntfaceDecn4", v);
}			
					  |  INTERFACE Identifier ExtendsIntfaces IntfaceBody {
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("IntfaceDecn2", v);
}								
									
					  ;


ExtendsIntfaces  :  EXTENDS IntfaceType 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ExtendsIntfaces1", v);
	}																							
				   |  ExtendsIntfaces COMMA IntfaceType 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ExtendsIntfaces2", v);
}																							
				   ;

IntfaceBody  :   OC CC 		{$$ = create_AST_leaf("{ }", "EMPTY");}												
			   |   OC IntfaceMemberDecnRec CC 	{$$ = $2;}																																
			   ;

IntfaceMemberDecnRec  :  IntfaceMemberDecn {$$ = $1;}											
							   |  IntfaceMemberDecnRec IntfaceMemberDecn 					{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("IntfaceMemberDecnRec", v);
}															
							   ;

IntfaceMemberDecn  :  ConstantDec 	{$$ = $1;}													
							|  AbstractMethod 		{$$ = $1;}									 			
							;

ConstantDec  :  FieldDecn 		{$$ = $1;}														
					 ;

AbstractMethod  :  MethodHead SCLN 	{$$ = $1;}															
						   ;

ArrInit : OC VariableInitList COMMA CC 		{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, create_AST_leaf($3, ""), "", 1);
		$$ = create_AST_node("ArrInit1", v);
}																							
				 | OC VariableInitList CC 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ArrInit3", v);
}																						
				 | OC CC			{$$ = create_AST_leaf($1, "EMPTY");}
				 | OC COMMA CC 			{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($2, ""), "", 1);
		$$ = create_AST_node("ArrInit2", v);
}																								
																						
				 ;

VariableInitList : VariableInitList COMMA VariableInit 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("VariableInitList", v);
}																
						| VariableInit 		{$$ = $1;}													
						;


Block : OC BlockStmts CC 		{$$ = $2;}																					
	  | OC CC 		{$$ = create_AST_leaf("{}", "EMPTY");}																											
	  ;

BlockStmts : BlockStmts BlockStmt 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("BlockStmts", v);
}																			
				| BlockStmt 	{$$ = $1;}																	
				;

BlockStmt : LocalVariableDecnStmt 	{$$ = $1;}														
			   | Stmt 			{$$ = $1;}																		
			   ;

LocalVariableDecnStmt : LocalVariableDecn SCLN 	{$$ = $1;}										
								  ;

LocalVariableDecn : Type VariableDecltrs 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("LocalVariableDecn", v);
}																											
						 ;

Stmt :	WhileStmt 			{$$ = $1;}														
		  | StmtWithoutTrailingSubStmt 	{$$ = $1;} 																	
		  | ForStatement 			{$$ = $1;}																	
		  | LabeledStmt 		{$$ = $1;}																	 
		  | IfThenStmt 		{$$ = $1;}																		
		  | IfThenElseStmt 	{$$ = $1;}																	
		  ;

StmtKind : WhileStmtKind 			{$$ = $1;} 										
				   | LabeledStmtNoShortIf 			{$$ = $1;}													
				   | StmtWithoutTrailingSubStmt 	{$$ = $1;}													
				   | IfThenElseStmtKind 		{$$ = $1;}												
				   | ForStatementKind 				{$$ = $1;}												
				   ;

StmtWithoutTrailingSubStmt : TryStmt 			{$$ = $1;}													
									 | DoStmt 			{$$ = $1;}																		
									 | BreakStmt        {$$ = $1;}  													
									 | ExprStmt 	{$$ = $1;}											
									 | ThrowStmt 			{$$ = $1;}										
									 | SwitchStmt 		{$$ = $1;}											
									 | ContinueStmt 	{$$ = $1;}													
									 |  Block 		{$$ = $1;}										
									 | EmptyStmt 	{$$ = $1;}												
									 | ReturnStmt 			{$$ = $1;}										
									 | SynchronizedStmt 	{$$ = $1;}											
									 ;
EmptyStmt : SCLN 		{$$ = create_AST_leaf($1, "SCLN");}																						
			   ;

LabeledStmt : Identifier COLON Stmt 		{$$ = $1;}													
				 ;

LabeledStmtNoShortIf : Identifier COLON StmtKind 	{$$ = $1;}									
						  ;

ExprStmt : StmtExpr SCLN 		{$$ = $1;}													
					;

StmtExpr : ClassCreation 	{$$ = $1;}																
					| PostDecrementExpr 			{$$ = $1;}												
					| PreDecExpr 		{$$ = $1;}													
					| MethodInvocation 					{$$ = $1;}												
					| PostIncrementExpr 			{$$ = $1;}												
					| PreIncExpr 		{$$ = $1;}													
					|  Assign 		{$$ = $1;}												
					;

IfThenStmt : IF OS Expr CS Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("IfThenStmt", v);
	}										
				;

IfThenElseStmt : IF OS Expr CS StmtKind ELSE Stmt {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("IfThenElseStmt", v);
	}						
					;

IfThenElseStmtKind : IF OS Expr CS StmtKind ELSE StmtKind 		{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("IfThenElseStmtKind", v);
	}					
							 ;


SwitchStmt : SWITCH OS Expr CS SwitchBlock {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("SwitchStmt", v);
	}												
				;

SwitchBlock : OC SwitchBlockStmtGroups SwitchLabels CC 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("SwitchBlock", v);
	}										
			| OC CC 	{$$ = create_AST_leaf("{ }", "EMPTY");}													
			| OC SwitchBlockStmtGroups CC 	{$$ = $2;}													
			| OC SwitchLabels CC 					{$$ = $2;}													
			;

SwitchBlockStmtGroups : SwitchBlockStmtGroup 	{$$ = $1;}												
						   | SwitchBlockStmtGroups SwitchBlockStmtGroup 							{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("SwitchBlockStmtGroups", v);
	}										
						   ;

SwitchLabels : SwitchLabel 					{$$ = $1;}															
			 | SwitchLabels SwitchLabel 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("SwitchLabels", v);
	}																							
			 ;

SwitchBlockStmtGroup : SwitchLabels BlockStmts {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("SwitchBlockStmtGroup", v);
	}																						
						  ;


SwitchLabel : CASE ConstExpr COLON {
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("SwitchLabel1", v);
	}																												
			| DEFAULT COLON 	{
		vector<treeNode> v;
		add_attribute(v, NULL, "default", 0);
		$$ = create_AST_node("SwitchLabel2", v); // empty?
	}																							
			;

WhileStmt : WHILE OS Expr CS Stmt {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("WhileStmt", v);
	}						
			   ;

WhileStmtKind : WHILE OS Expr CS StmtKind {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("WhileStmtKind", v);
	}						
						;

DoStmt : DO Stmt WHILE OS Expr CS SCLN 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("DoStmt", v);
	}											
			;

ForStatement : ForStmt {$$ = $1;}																	
			 ;

ForStatementKind : ForStmtKind 	{$$ = $1;}													
					  ;

ForStmt : FOR OS ForInit SCLN Expr SCLN ForUpdate CS Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $7, "", 1);
		add_attribute(v, $9, "", 1);
		$$ = create_AST_node("BasicForStmt1", v);
	}
					  | FOR OS ForInit SCLN Expr SCLN CS Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $8, "", 1);
		$$ = create_AST_node("BasicForStmt5", v);
	}								
				  | FOR OS SCLN Expr SCLN CS Stmt 		{
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("BasicForStmt6", v);
	}									
				  | FOR OS ForInit SCLN SCLN CS Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("BasicForStmt7", v);
	}											
				  | FOR OS SCLN SCLN CS Stmt 		{
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		$$ = create_AST_node("BasicForStmt8", v);
	}	
				  | FOR OS SCLN Expr SCLN ForUpdate CS Stmt 		{
		vector<treeNode> v;
		add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $8, "", 1);
		$$ = create_AST_node("BasicForStmt2", v);
	}
				  | FOR OS ForInit SCLN SCLN ForUpdate CS Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $8, "", 1);
		$$ = create_AST_node("BasicForStmt3", v);
	}								
				  | FOR OS SCLN SCLN ForUpdate CS Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $5, "", 1);
		add_attribute(v, $7, "", 1);
		// add_attribute(v, $6, "", 1);
		$$ = create_AST_node("BasicForStmt4", v);
	}										
											
				  ;

ForStmtKind : FOR OS ForInit SCLN Expr SCLN ForUpdate CS StmtKind  		{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $7, "", 1);
		add_attribute(v, $9, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf1", v);
	}
						   | FOR OS SCLN Expr SCLN ForUpdate CS StmtKind 		  		{
		vector<treeNode> v;
		add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $8, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf2", v);
	}
						   | FOR OS ForInit SCLN SCLN ForUpdate CS StmtKind     	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $8, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf3", v);
	}								        	
						   | FOR OS SCLN SCLN ForUpdate CS StmtKind 	{
		vector<treeNode> v;
		add_attribute(v, $5, "", 1);
		add_attribute(v, $7, "", 1);
		// add_attribute(v, $6, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf4", v);
	}														  	
						   | FOR OS ForInit SCLN Expr SCLN CS StmtKind 		{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $8, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf5", v);
	}										  	
						   | FOR OS SCLN Expr SCLN CS StmtKind 	{
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf6", v);
	}													  		
						   | FOR OS ForInit SCLN SCLN CS StmtKind {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf7", v);
	}											  	
						   | FOR OS SCLN SCLN CS StmtKind 	{
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		// add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf8", v);
	}							  	
						   ;

ForInit : StmtExprList 	{$$ = $1;}																	
		| LocalVariableDecn 	{$$ = $1;}																	
		;

ForUpdate : StmtExprList 	{$$ = $1;}																
		  ;

StmtExprList : StmtExprList COMMA StmtExpr {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("StmtExprList", attr);
	}								
						| StmtExpr 	{$$ = $1;}														
						;

BreakStmt : BREAK Identifier SCLN 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("CBreakStmt", v);
	}																									
			   | BREAK SCLN 	{$$ = create_AST_leaf($1, "BREAK");}																					
			   ;

ContinueStmt : CONTINUE Identifier SCLN 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ContinueStmt", v);
	}																	
				  | CONTINUE SCLN		{$$ = create_AST_leaf($1, "CONTINUE");}												
				  ;

ReturnStmt : RETURN SCLN 	{$$ = create_AST_leaf($1, "RETURN");}																		
				| RETURN Expr SCLN 		{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ReturnStmt", v);
	}															
				;

ThrowStmt : THROW Expr SCLN 		{
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ThrowStmt", v);
	}																										
			   ;

SynchronizedStmt : SYNCHRONIZED OS Expr CS Block {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("SynchronizedStmt", v);
	}																		
					  ;
TryStmt : TRY Block Catches 		{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("TryStmt1", v);
	}																								
			 | TRY Block ResEnd 	{
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("TryStmt2", v);
	}																										
			 | TRY Block Catches ResEnd {
		vector<treeNode> v;
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("TryStmt3", v);
	}																									
			 ;

Catches : Catches CatchClause 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("Catches", v);
	}																														
		| CatchClause 			{$$ = $1;}																		
		;

CatchClause  :  CATCH OS FormalParam CS Block 	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("CatchClause", v);
	}																			
			 ;


ResEnd : FINALLY Block 	{
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ResEnd:Finally", v);
	}																													
		;

Primary : PrimaryNoNewArr 	{$$ = $1;}											
		| NewArr 		{$$ = $1;}									
		;

PrimaryNoNewArr :	 MethodInvocation			{$$ = $1;}							 
				  |	OS Expr CS 	{$$ = $2;}									
				  | ArrOp 				{$$ = $1;}							
				  | FieldAccess 				{$$ = $1;}							
				  | THIS 					{ $$ = create_AST_leaf($1, "THIS");}							
				  | Literal 			{$$ = $1;}								
				  | ClassCreation 		{$$ = $1;}						 
				  ;

ClassCreation : NEW ClassType OS ArgLst CS 	{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("ClassInstCreationExpr1", attr);
	}								
								| NEW ClassType OS CS 		{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		// add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("ClassInstCreationExpr2", attr);
	}												
								;

ArgLst : Expr 			{$$ = $1;}										
			 | ArgLst COMMA Expr 		{
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("Arg_list", attr);
	}							
			 ;



FieldAccess : Primary FST Identifier 	{
		
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("Field access", attr);
	}									
			| SUPER FST Identifier  {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("Field access", attr);
	}											
			;

ArrOp : Name OSQ Expr CSQ 	{
		vector<treeNode> v, v2;
		add_attribute(v2, $3, "", 1);
		Node* node = create_AST_node("[ ]", v2);
		add_attribute(v, $1, "", 1);
		add_attribute(v, node, "", 1);
		$$ = create_AST_node("ArrOp1", v);
	}								
			| PrimaryNoNewArr OSQ Expr CSQ	{
		vector<treeNode> v, v2;
		add_attribute(v2, $3, "", 1);
		Node* node = create_AST_node("[ ]", v2);
		add_attribute(v, $1, "", 1);
		add_attribute(v, node, "", 1);
		$$ = create_AST_node("ArrOp2", v);
	}													
			;

MethodInvocation : Name OS ArgLst CS 		{ 
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("MethodInvocation", attr);
	}						
				 | Name OS CS 	{ $$= $1; }										
				 | Primary FST Identifier OS ArgLst CS 	{
		vector<treeNode> v, v2;
		add_attribute(v2, $1, "", 1);
		add_attribute(v2, $3, "", 1);
		Node* node = create_AST_node($2, v2);
		add_attribute(v, node, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("MethodInvocation", v);
	}								
				 | Primary FST Identifier OS CS 		{
		
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, create_AST_leaf($2, ""), "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("MethodInvocation", attr);
	}						
				 | SUPER FST Identifier OS ArgLst CS   {
		
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, create_AST_leaf($2, ""), "", 1);
		add_attribute(attr, $3, "", 1);
		add_attribute(attr, $5, "", 1);
		$$ = create_AST_node("MethodInvocation", attr);
	}					
				 | SUPER FST Identifier OS CS  		{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, create_AST_leaf($2, ""), "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("MethodInvocation", attr);
	}											
				 ;


NewArr : NEW PrimitiveType DimExprs Dims 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ArrCreationExpr1", v);
	}				
						| NEW PrimitiveType DimExprs 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ArrCreationExpr2", v);
	}						
						| NEW ClassOrIntfaceType DimExprs Dims {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ArrCreationExpr3", v);
	}				
						| NEW ClassOrIntfaceType DimExprs 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ArrCreationExpr4", v);
	}				
						;

DimExprs : DimExprs DimExpr { 
			vector<treeNode> attr;
			add_attribute(attr, $1, "", 1);
			add_attribute(attr, $2, "", 1);
			$$ = create_AST_node("dim_exprs",attr);
		}																		
		 | DimExpr 			{$$ = $1;}												
		 ;


DimExpr : OSQ Expr CSQ	   		{$$= $2;}									
		;

Dims  :  OSQ CSQ 			{$$ = create_AST_leaf("[ ]", "EMPTY_EXP") ;}												
	  |  Dims OSQ CSQ 		{ 
			vector<treeNode> attr;
			add_attribute(attr, $1, "", 1);
			add_attribute(attr, create_AST_leaf("[ ]", "EMPTY_EXP"), "", 1);
			$$ = create_AST_node("dims",attr);
		}										
	  ;

Expr : AssignExpr 	{$$ = $1;}									 		
		   ;

AssignExpr  :  ConditionExpr 			{$$ = $1;}							
					  |  Assign {$$ = $1;}										
					  ;

Assign  :  LeftHandSide AssignOp Expr 	{
							vector<treeNode> attr;
							add_attribute(attr, $1, "", 1);
							add_attribute(attr, $3, "", 1);
							$$ = create_AST_node($2,attr);
						}				
		    ;

LeftHandSide  :  Name 		{$$ = $1;}													
			  |  FieldAccess 	{$$ = $1;}												
			  |  ArrOp 		{$$ = $1;}										
			  ;

AssignOp  :  SBEQ			{ $$ = $1; }											
					|  DIVEQ		{ $$ = $1; }										
					|  OREQ				{ $$ = $1; }									
					|  PLEQ			{ $$ = $1; }										
					|  EQUALS 		{ $$ = $1; }												
					|  DLRLR			{ $$ = $1; }									
					|  TGRGRGR			{ $$ = $1; }									
					|  MODEQ		{ $$ = $1; }										
					|  ANDEQ			{ $$ = $1; }												
					|  DGRGR			{ $$ = $1; }									
					|  POWEQ			{ $$ = $1; }									
					|  MULEQ	{ $$ = $1; }											
					;

ConditionExpr : ConditionOrExpr 	{$$ = $1;}										
					  | ConditionOrExpr QUESTION_MARK Expr COLON ConditionExpr 	{
											vector<treeNode> attr;
											add_attribute(attr, $1, "", 1);
											add_attribute(attr, $3, "", 1);
											add_attribute(attr, $5, "", 1);
											$$ = create_AST_node("ternary operator",attr);
										}
					  ;

ConditionOrExpr : ConditionAndExpr 	{$$ = $1;}										
						| ConditionOrExpr OR ConditionAndExpr {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	} 						
						;

ConditionAndExpr : InclusiveOrExpr		{$$ = $1;}									
						 | ConditionAndExpr AND InclusiveOrExpr  {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	} 						
						 ;

InclusiveOrExpr : ExclusiveOrExpr	{$$ = $1;}							
					  | InclusiveOrExpr BINARYOR ExclusiveOrExpr  {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	} 			
					  ;

ExclusiveOrExpr : AndExpr 		{$$ = $1;}								
					  | ExclusiveOrExpr POW AndExpr 	 {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	} 				
					  ;	   

AndExpr : EqExpr			{$$ = $1;}								
			  | AndExpr BINARYAND EqExpr	 {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	} 							
			  ;
			  
EqExpr : RtlExpr 	{$$ = $1;}								
				   | EqExpr EQEQ RtlExpr    {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	} 		
				   | EqExpr NEQUALS RtlExpr 	 {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}		
				   ;

RtlExpr : ShiftExpr		{$$ = $1;}	
                     					 | RtlExpr GREQ ShiftExpr 	{
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}									
					 | RtlExpr INSTANCEOF RefType 		{
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}							
					 | RtlExpr LT ShiftExpr 		{
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}		
					 | RtlExpr GT ShiftExpr 		{
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}					
					 | RtlExpr LEQ ShiftExpr 	{
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}					
			
					 ;

ShiftExpr : AddExpr 		{$$ = $1;}								
				| ShiftExpr LTLT AddExpr 	{
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}				
				
				;

AddExpr : MultExpr 		{$$ = $1;}						
				   | AddExpr ADD MultExpr {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}		
				   | AddExpr SUBTRACT MultExpr  {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}				
				   ;

MultExpr : UnaryExpr 			{$$ = $1;}						
						 | MultExpr MULTIPLY UnaryExpr {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}	
						 | MultExpr DIVISION UnaryExpr  {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}		
						 | MultExpr MOD UnaryExpr  {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node($2 ,attr);
	}		
						 ;

UnaryExpr : PreIncExpr 	{$$ = $1;}								
				| PreDecExpr 		{$$ = $1;}							
				| ADD UnaryExpr 					{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node("unary_exp_plus",attr);
	}									
				| SUBTRACT UnaryExpr  			{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node("unary_exp_minus",attr);
	}														
				| UnaryExprExtra 		{$$ = $1;}							
				;

PreIncExpr : PLUSPLUS UnaryExpr {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node($1,attr);
	}				    	
					   ;

PreDecExpr : MINUSMINUS UnaryExpr {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node($1,attr);
	}								
					   ;

UnaryExprExtra : PostfixExpr 		{$$ = $1;}					
							| TILDA UnaryExpr 	{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node("unary_exp_tilde",attr);
	}							
							| NT UnaryExpr {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node("unary_exp_not",attr);
	}							
							| CastExpr 			{$$ = $1;}					
							;

PostfixExpr : Primary 			{$$ = $1;}									
                  | Name 				{$$ = $1;}											
                  | PostIncrementExpr 		{$$ = $1;}						
                  | PostDecrementExpr			{$$ = $1;}						
                  ;

PostIncrementExpr : PostfixExpr PLUSPLUS 	{
						vector<treeNode> attr;
						add_attribute(attr, $1, "", 1);
						$$ = create_AST_node($2, attr);
				};

PostDecrementExpr : PostfixExpr MINUSMINUS {
						vector<treeNode> attr;
						add_attribute(attr, $1, "", 1);
						$$ = create_AST_node($2, attr);
				};							
						;

CastExpr : OS PrimitiveType Dims CS UnaryExpr {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $3, "", 1);
		add_attribute(attr, $5, "", 1);
		$$ = create_AST_node("cast_Expr1" ,attr);
	}
	;				
			   | OS Expr CS UnaryExprExtra	
			   {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("cast_Expr2" ,attr);
	}
	;		
			   | OS PrimitiveType CS UnaryExpr 	{
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("cast_Expr3" ,attr);
	}
	;				
			   | OS Name Dims CS UnaryExprExtra {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $3, "", 1);
		add_attribute(attr, $5, "", 1);
		$$ = create_AST_node("cast_Expr4" ,attr);
	}

			   ;

ConstExpr : Expr 		{$$ = $1;}									
				   ;

%%

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

