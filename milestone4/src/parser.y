%{
#include<bits/stdc++.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "tree.h"
#include "symbol_table.h"
#include "typecheck.h"
#include "3ac.h"
#include "codegen.h"
set<string> is_static;
using namespace std;
extern int yylineno;
extern FILE* yyin;
ofstream code_file;
FILE* fp;
extern char* yytext;
extern int column;
string special_type;
extern vector<quad> code;
int constructor_num=1;
int yyerror(const char*);
extern int yylex();
extern int yyparse();
bool verbose= false;
int interrupt_compiler = 0;
FILE* dotfile;
char* file;
char* curr_file;

bool fn_decl = 0;
int func_flag = 0;
int dump_tac = 0;
int dump_sym_table = 0;
int only_lexer = 0;
int block_count = 0;
int if_found = 0;
int previous_if_found = 0;
int stop_compiler = 0;		// shows error while parsing
int isArray = 0;			// true when array is declared
int type_delim = 0;	
int debug_mode = 0;	
int param_size= 0;
int func_size= 0;
int field_size= 0;

string funcName = ""; // global variables. 
string className= "";
string structName = "";
string classType= "";
string structTemp ="";
string funcType = "";
string type = "";
string storage_class = "";
string constructor_temporary="";
stack<int> block_stack;
vector<string> varlist;

int Anon_StructCounter=0;
vector<string> funcArgs;
vector<sym_entry*> args;
vector<string> idList;
vector<string> currArgs;

vector<string> classNamelist;
vector<qid> initializer_list_values;
vector<int> array_dims;
map<string, vector<int> > arr_dimensions;
map<string, int > arr_index;
map<string, vector<int> > gotolablelist;
map<string, int> gotolabel;
map<string, int> func_usage_map;
map<string, vector<qid>> global_array_init_map;
// vector<string, 

extern int yyrestart(FILE*);
int warning(const char* s) ;
extern FILE* yyin;
#define YYERROR_VERBOSE
%}

%union{
	char* str;
	int number;
	Node* ptr;
	constants* num;
}

%start CompUnit

%token<str> ABSTRACT ASSERT BOOLEAN BREAK BYTE CASE CATCH CHAR CLASS COMMENT CONST CONTINUE DEFAULT DO DOUBLE ELSE ENUM ERROR
%token<str> EXTENDS FINALLY FINAL FLOAT FOR IDENTIFIER IF GOTO IMPLEMENTS IMPORT INSTANCEOF INT  INTERFACE  LITERAL LONG NATIVE NEW PACKAGE PRIVATE PROTECTED PUBLIC RETURN SHORT STATIC STRICTFP SUPER SWITCH SYNCHRONIZED THIS
%token<str> THROWS THROW TRANSIENT TRY VOID VOLATILE WHILE EQUALS GT LT NT TILDA QUESTION_MARK COLON ARROW EQEQ GREQ LEQ NEQUALS PLUSPLUS MINUSMINUS OR AND ADD SUBTRACT MULTIPLY DIVISION BINARYOR
%token<str> BINARYAND POW MOD GRGR LTLT GRGRGR PLEQ SBEQ MULEQ ANDEQ OREQ POWEQ DIVEQ MODEQ DGRGR DLRLR TGRGRGR OC CC OSQ CSQ OS CS COMMA DISTO ATR TDT FST SCLN DST STRING_LITERAL STRING
%token<num> CONST_LITERAL 
 
%type<number> NEXT_QUAD WRITE_GOTO
%type <str> AssignOp 
%type <ptr> IF_CODE AbstractMethod AddExpr AndExpr ArgLst ArrOp NewArr ArrInit ArrKind Assign AssignExpr
%type <ptr> ForStmt ForStmtKind Block BlockStmt BlockStmts BreakStmt CastExpr CatchClause Catches ClassBody ClassBodyDec ClassBodyDecRec ClassDec ClassCreation MemberDec ClassOrIntfaceType ClassType ClassTypeList CompUnit ConditionAndExpr ConditionExpr ConditionOrExpr ConstantDec ConstExpr ConstructorBody ConstructorDecn ConstructorDecltr ContinueStmt GOTO_AND GOTO_OR GOTO_COND
%type <ptr> DimExpr DimExprs Dims DoStmt EmptyStmt EqExpr ExclusiveOrExpr ExplicitConstructorInvocation Expr ExprStmt ExtendsIntfaces FieldAccess FieldDecn ResEnd FloatingPoint ForInit FormalParam FormalParamList ForStatement ForStatementKind ForUpdate Identifier IfThenElseStmt
%type <ptr> IfThenElseStmtKind IfThenStmt ImportDecn ImportDecnRec InclusiveOrExpr Integers IntfaceBody IntfaceDecn IntfaceMemberDecn IntfaceMemberDecnRec Intfaces IntfaceType IntfaceTypeList LabeledStmt LabeledStmtNoShortIf LeftHandSide Literal LocalVariableDecn LocalVariableDecnStmt MethodBody MethodDecn MethodDecltr MethodHead
%type <ptr> MethodInvocation Modifier Modifiers MultExpr Name Numbers PackageDecn PostDecrementExpr PostfixExpr PostIncrementExpr PreDecExpr PreIncExpr Primary PrimaryNoNewArr PrimitiveType QualName RefType RtlExpr ReturnStmt ShiftExpr SimpleName SingleTypeImportDecn Stmt StmtExpr StmtExprList
%type <ptr> StmtKind StmtWithoutTrailingSubStmt StaticInit Super SwitchBlock SwitchBlockStmtGroup SwitchBlockStmtGroups SwitchLabel SwitchLabels SwitchStmt SynchronizedStmt Throws ThrowStmt TryStmt Type TypeDec TypeDecRec ImportDDec UnaryExpr UnaryExprExtra VariableDecltr VariableDecltrId VariableDecltrs VariableInit VariableInitList WhileStmt WhileStmtKind
%type <ptr> MethodIdentifier   EXPR_STMT_CODE N F ConstructorName
%type <str> C CT M S StructName ClassName

%left ';'

%%


Literal  :  CONST_LITERAL 	{ 
								$$ = create_AST_leaf($1->str, "CONST_LITERAL");
								$$->type = $1->type; // either "int" or "double"
								$$->int_val = $1->int_val;
								$$->real_val = $1->real_val;
								$$->expType = 4; // expression type 4 
								$$->temp_name = $1->str;
								$$->isInit = 1;
								//--3AC
								sym_entry* temp = new sym_entry;
								if($1->type != "char" ) $$->place = qid(to_string($1->int_val), temp);
								// if($1->type != "char" && $1->int_val==-1 ) $$->place = qid(to_string($1->real_val), temp);
								// if($1->type != "char") $$->place = qid(to_string($1->int_val), temp);
								else $$->place = qid($1->str, temp);
								$$->nextlist.clear();
								
					 }		
					| STRING_LITERAL {
						$$ = create_AST_leaf($1, "STRING_LITERAL");
						$$->type = string("char*"); // may need to change later 
						$$->temp_name = string($1);
						$$->str_val = string($1); 
						
						//--3AC
						string str = string($1);
						sym_entry* temp = new sym_entry;
						$$->place = qid(str, temp);
						$$->nextlist.clear();
					}																		
			;

Identifier  :  IDENTIFIER 	{ 
									$$ = create_AST_leaf($1, "IDENTIFIER");

									bool is_place_set= false;
									string t;
									int flag=0;
									//
									
									string temp= primExpr("CLASS_"+string($1));
									
									if(temp!="") 
									{
										flag=1;
									}
									if(temp=="")  temp = primExpr(string($1));
									
									if(temp == ""){
										yyerror(("Undeclared Identifier " + string($1)).c_str());
									}
									else{
										if(temp.substr(0, 5) == "FUNC_"){
											$$->expType = 3; // 3 is function 
										}
										else if(temp.back() == '*'){ 
											$$->expType = 2;  // 2 is array
											sym_entry* sym=  Lookup(string($1));
											if(sym==nullptr) 
											{
												yyerror((string($1) + " array not declared before access").c_str());
											}
											// cout<<"Array id "<<sym->place<<"\n";
											$$->place= qid(sym->place, sym);
											is_place_set= true;
										}
										else $$->expType = 1; // 1 is variable 
										if(temp.substr(0,5)=="FUNC_" && temp.back() == '#'){
											// which case? 
											temp.pop_back();
											$$->type = temp;
											$$->temp_name = string($1); 
											$$->nextlist.clear();
										}
										else{

											$$->type = temp;
											string s;
											if(flag) s= "CLASS_"+string($1);
											else s= string($1);
											$$->isInit = Lookup(s)->init;
											// sym_entry* has init and node* has isInit 
											$$->size = GetSize(temp); // returns size of type of the identifier s. 
											$$->temp_name = string($1); 
											//--3AC
											// cout<<s<<
											sym_entry* sym= Lookup(s);
											// bool b=1;
											// if(sym==nullptr) b=0;
											// cout<<"Searching for "<<s<<" found? "<<b<<endl;
											// cout<<"In id offsets  "<<string($1)<<" "<<sym->offset<<endl;
											if(find(classNamelist.begin(), classNamelist.end(), sym->type)!=classNamelist.end())
											{
												$$->place= qid(sym->place, sym);
												is_place_set= true;
											}
											// if(sym->offset<0) // function argument 
											// {
											// 	//  cout<<"Is offfset negative?\n";
											// 	 $$->place= qid(sym->place, sym);
											// 	 is_place_set= true;
											// }
											if(!is_place_set) $$->place = qid(string($1), Lookup(s));
											$$->nextlist.clear();
										}
									
									} 
							}																			
		 ;

Type  :  RefType 		{$$ = $1;}																	
	  |	 PrimitiveType 	{$$ = $1;}																		
	  ;


RefType  : ArrKind 		{$$ = $1;}												
			   | ClassOrIntfaceType 		{$$ = $1;}	 																	
			   ;

ClassOrIntfaceType  :  Name {$$ = $1;}	 // refers to a class or struct. 																
					  ;
PrimitiveType  : Numbers 	{$$ = $1;}		 // type name as string has been stored in primitive type 														
			   | BOOLEAN 		{ 
									$$ = create_AST_leaf($1, "BOOLEAN"); 
									// Semantics
									if(type == "") type ="int";
									else type += " int";
									// boolean treated as one byte
									$$->size= 4;
									$$->type= "bool";
							}  															
			   ;

Numbers  : FloatingPoint 	 {$$ = $1;}																
			 | Integers {$$ = $1;} 																	
			 ;

Integers  :  LONG 	{ 
							$$ = create_AST_leaf($1, "LONG"); 
								// Semantics
							if(type == "") type = string($1);
							// only primiive types are supported 
							// long long not likely to occur 
							else type += " " + string($1);
							$$->size= 8;
							$$->type= "long";
					}																				
			  |  BYTE 	{ 
				  			$$ = create_AST_leaf($1, "BYTE");
			  				
							// Semantics
							if(type == "") type = string($1);
							else type += " " + string($1);
							$$->size= 1;
							$$->type= "byte";
				  } 																				
			  |  INT 	{ 
							$$ = create_AST_leaf($1, "INT"); 

							// Semantics
							if(type == "") type = string($1);
							else type += " " + string($1);
							$$->size= 4;
							$$->type= "int";
					}																				
			  |  CHAR 	{ 
				  			$$ = create_AST_leaf($1, "CHAR");
							
							// Semantics
							if(type == "") type = string($1);
							else type += " " + string($1);
							$$->size= 1;
							$$->type= "char";
				 }																				
			  |  SHORT 	{ 
				  			$$ = create_AST_leaf($1, "SHORT"); 

							// Semantics
							if(type == "") type = string($1);
							else type += " " + string($1);
							$$->size= 2;
							$$->type= "short";
			  }
				| STRING {
								$$ = create_AST_leaf($1, "STRING"); 

								// Semantics
								if(type == "") type = "char*";
								else type += " char*";
								$$->size= 8;
								$$->type= "String";
			  }																		
			  ;

FloatingPoint  :   DOUBLE 	{
								 $$ = create_AST_leaf($1, "DOUBLE"); 
								 
								// Semantics
								if(type == "") type = string($1);
								else type += " " + string($1);
								$$->size= 8;
						}																	
			  	   |   FLOAT { 
						 			$$ = create_AST_leaf($1, "FLOAT");
								
									// Semantics
									if(type == "") type = string($1);
									else type += " " + string($1);
									$$->size= 4;
					}																		
			  	   ;

ClassType  :  ClassOrIntfaceType  	{
						$$ = $1;
						qid tmp = newtemp($$->type);
						qid tmp1 = newtemp($$->type);
						// cout<<"If found kdhe "<<if_found<<"\n";
						int temp=1;
						// cout<<"SISZEEC "<<$3->dims[0]<<" "<<$3->dims.size()<<endl;
						// cout<<"DA TYPEC IS "<<$2->type<<endl;
						// for(int i=0;i<$3->dims.size();i++)
						// {
						// 	temp*=$3->dims[i];
						// }
						sym_entry* sym= Lookup(className);
						// cout<<"Found type is "<<sym->type<<endl;
						if (sym ==nullptr){
							yyerror(("Field size not found in class "+ className).c_str());
						}
						emit(qid("NEW", sym), qid(to_string(sym->fieldsize), NULL), tmp1, tmp, -1);	
						$$->place= tmp1;
						$$->expType= 3;
						// qid tmp1 = newtemp($$->type);
						// emit(qid("NEW", sym), qid(to_string(sym->fieldsize), NULL), qid("", NULL), tmp, -1);	
		}																
		   ;

IntfaceType  :  ClassOrIntfaceType 	{$$ = $1;}														
				;

ArrKind  :  PrimitiveType OSQ CSQ 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("ArrKind1", v);
	}	
	  |  ArrKind OSQ CSQ 			{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("ArrKind2", v);
	}																			
		   |  Name OSQ CSQ 		{ // ASSUMING NAME IS IDENITFIER FOR NOE
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("ArrKind3", v);

		// needs to be filled in for type checking and 3AC. Arrays incomplete 
	}																	
		 											
		   ;

Name  :  QualName		{$$ = $1;}																
	  |  SimpleName 	{$$ = $1;}																			
	  ;

SimpleName  :  Identifier {
								$$ = $1;
								// special_type= $1->temp_name;
								// special_type was an attempt to recognise class names. 
								// Not used. 
						};

QualName  :  Name FST IDENTIFIER {
	// Name FST IDENTIFIER {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, create_AST_leaf($3, "IDENTIFIER"), "", 1);
		$$ = create_AST_node("QualName", attr);

		// treats similar to a struct 
		if(!$1->is_error && $1->expType!=4){
			string temp = string($3);
			// cout<<"Will call find_table now"<<"\n";
			sym_table* ret = find_table("CLASS_"+$1->type);
			if(ret == nullptr){
				yyerror(("Class " + $1->name + " not defined").c_str());
				$$->is_error = 1;
			}
			// else{
			// 	cout<<"ret="<<"CLASS_"+$1->type<<endl;
			// 	for(map<string, sym_entry*>::iterator it = ret->begin(); it!=ret->end(); it++){ cout<<it->first<<endl; }
			// }
			sym_entry* r;
			r= find_in_table(temp, ret);
			if (r == nullptr){
				yyerror(("Class " + $1->type + " has no field " + string($3)).c_str());
				$$->is_error = 1;
			}
			else{
				$$->type = r->type;
				$$->temp_name = $1->temp_name + "." + temp;
				qid temp_var1 = newtemp($$->type);
				emit(qid("=", r), qid(to_string(r->offset),NULL), qid("",NULL), temp_var1, -1);
				qid temp_var = newtemp($$->type);
				// adds a temporary variable(for 3AC) to symbol table. 
				// cout<<"In qual name "<<$1->place.first<<endl;
				sym_entry* attr_sym = retTypeAttrEntry(r);
				emit(qid("qualname", r), $1->place, temp_var1, temp_var, -1);
				temp_var.second->array_dims = attr_sym->array_dims;
				$$->place = temp_var;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error = 1;
		}
	}															
			   ;


CompUnit  :  PackageDecn ImportDecnRec TypeDecRec {
	// have not supported imports and packages yet. 
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
		add_attribute(v, $2, "", 1);
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
				 | ClassDec  {$$ = $1; } 															
				 ;

Modifiers  :  Modifier  				{$$ = $1;}																
		   |  Modifiers Modifier 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("Modifiers",v);

		//Semantic 
		$$->type= $1->type+ " "+ $2->type;
	}																															
		   ;

// modifiers are used purely in declarations. So we should treat them similar to 
// the integer types "int", "float", etc. How about we create a new variable for modifiers
// that behaves exactly like type? 

Modifier  :  FINAL 				{  
										$$ = create_AST_leaf($1, "FINAL");
										// Semantic
										$$->type= string($1);
										// $$->modifiers[0]=1;
				 }																			
		  |  PRIVATE 		{ 
			  						$$ = create_AST_leaf($1, "PRIVATE");
		  							// Semantic
									$$->type= string($1);
			   }																			
		  |  PROTECTED	 	{ 
			  						$$ = create_AST_leaf($1, "PROTECTED"); 
		  							// Semantic
									$$->type= string($1);
			   }									 													
		  |  NATIVE 		{ 
			  					$$ = create_AST_leaf($1, "NATIVE");
		  							// Semantic
									$$->type= string($1);
			   }																			
		  |  SYNCHRONIZED 	{ 
			  					$$ = create_AST_leaf($1, "SYNCHRONIZED");
		  							// Semantic
									$$->type= string($1);
			   }																			
		  |  STATIC 	{ 
			  					$$ = create_AST_leaf($1, "STATIC");
		  							// Semantic
									$$->type= string($1);
			   }																			
		  |  PUBLIC 	{ 
			  					 $$ = create_AST_leaf($1, "PUBLIC");
		  							// Semantic
									$$->type= string($1);
			   }																			
		  |  TRANSIENT 		{ 
			  					 $$ = create_AST_leaf($1, "TRANSIENT"); 
		  							// Semantic
									$$->type= string($1);
			   }																				
		  |  ABSTRACT 		{ 
			  					$$ = create_AST_leaf($1, "ABSTRACT"); 
		  							// Semantic
									$$->type= string($1);
			   }																					
		  |  VOLATILE 		{ 
			  				$$ = create_AST_leaf($1, "VOLATILE");
		  							// Semantic
									$$->type= string($1);
		  }																	
		  ;


// To add support for modifiers and for types. 
ClassDec  :  Modifiers CLASS ClassName Super Intfaces C ClassBody 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, create_AST_leaf($3, "IDENTIFIER"), "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $5, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("ClassDecn1", v);

		string cName= className.substr(6, className.size()-6);
		classType= string($1->type); // by default it is private
		printSymbolTable(curr_table ,className + ".csv");
		SymbolTableUpdation(className, 1);		
	}							
							  |  CLASS ClassName Intfaces C ClassBody 	{
		vector<treeNode> v;
		// add_attribute(v, $2, "", 1);
		add_attribute(v, create_AST_leaf($2, "IDENTIFIER"), "",1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("ClassDecn4", v);

		string cName= className.substr(6, className.size()-6);
		classType= "private"; // by default it is private
		printSymbolTable(curr_table ,className + ".csv");
		SymbolTableUpdation(className, 1);		
	}																			
				  |  Modifiers CLASS ClassName Super C ClassBody 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, create_AST_leaf($3, "IDENTIFIER"), "",1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		$$ = create_AST_node("ClassDecn5", v);
		// Symbol table 
		string cName= className.substr(6, className.size()-6);
		classType= string($1->type); // by default it is private
		printSymbolTable(curr_table ,className + ".csv");
		SymbolTableUpdation(className, 1);				
	}																	
				  |  CLASS ClassName Super C ClassBody 		{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($2, "IDENTIFIER"), "",1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("ClassDecn6", v);
		classType= "private"; // by default it is private
		type = "";
		field_size=0;
		string cName= className.substr(6, className.size()-6);
		printSymbolTable(curr_table ,className + ".csv");
		SymbolTableUpdation(className, 1);	
	}																			
			
				   |  Modifiers CLASS ClassName C ClassBody 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, create_AST_leaf($3, "IDENTIFIER"), "",1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("ClassDecn7", v);
		
		// Symbol table 
		classType= string($1->type);
		type = "";
		field_size=0;
		string cName= className.substr(6, className.size()-6);
		printSymbolTable(curr_table ,className + ".csv");
		SymbolTableUpdation(className, 1);

	}																			
				  |  CLASS ClassName C ClassBody {
					
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($2, "IDENTIFIER"), "",1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ClassDecn8", v);

		// Symbol tabl
		// cout<<"Class table "<<className<<endl; 
		classType= string("private"); // by default it is private
		type = "";
		string cName= className.substr(6, className.size()-6);
		printSymbolTable(curr_table ,className + ".csv");
		SymbolTableUpdation(className, 1);		
	}	
				  |  CLASS ClassName Super Intfaces C ClassBody 			{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($2, "IDENTIFIER"), "",1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		$$ = create_AST_node("ClassDecn2", v);

		classType= string("private"); // by default it is private
		type = "";
		string cName= className.substr(6, className.size()-6);
		printSymbolTable(curr_table ,className + ".csv");
		SymbolTableUpdation(className, 1);	
	}															
				  |  Modifiers CLASS ClassName Intfaces C ClassBody 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, create_AST_leaf($3, "IDENTIFIER"), "",1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		$$ = create_AST_node("ClassDecn3", v);

		classType= string($1->type);
		type = "";
		string cName= className.substr(6, className.size()-6);
		field_size=0;
		printSymbolTable(curr_table ,cName + ".csv");
		SymbolTableUpdation(className, 1);
	}															
						
						
C: { 	
		string cName= string("DummyC_name"+to_string(classnum));
		classnum++;

			// cout<<"CLass name is "<<className<<"\n";
		classType= string("private"); // by default it is private
		if (gst.find(className) != gst.end()){
			yyerror(("Redefinition of class " + cName).c_str());
		}
		else{
			CreateSymbolTable(className, classType, 0,0 ); // global vars
		
			// insertSymbol(*curr_table, className, className.substr(6, className.size()-6), 0, 0, NULL);
			block_count = 1;
		}
		type = "";
 	}

ClassName: IDENTIFIER {
							$$=$1;
							className= "CLASS_"+string($1);
							classNamelist.push_back(string($1));
							// add 3AC support. 
}


Super  :  EXTENDS ClassType  		{
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "EXTENDS"), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("Super", v);
	};

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
		   |  OC CT ClassBodyDecRec CC 		{
			   
			//    $$=$2;
			vector<treeNode> v;
			add_attribute(v, $3, "", 1);
			$$ = create_AST_node("Block", v);

			if(func_flag>=2){
				int bc = block_stack.top();
				block_stack.pop();
				string str = "Block" + to_string(bc);
				string name = funcName+str+".csv";
				printSymbolTable(curr_table, name);
				SymbolTableUpdation(str, 0);
				func_flag--;
			}
		}											
				   ;													
		   

ClassBodyDecRec  :  ClassBodyDec 	{$$ = $1;}													
			  |  ClassBodyDecRec  NEXT_QUAD ClassBodyDec 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("Class!", v);

		if($1->is_error || $3->is_error)	{
			$$->is_error = 1;
		}
        backpatch($1->nextlist, $2);
        $$->nextlist = $3->nextlist;
		$1->caselist.insert($1->caselist.end(), $3->caselist.begin(), $3->caselist.end());
        $$->caselist = $1->caselist;
		$1->continuelist.insert($1->continuelist.end(), $3->continuelist.begin(), $3->continuelist.end());
        $1->breaklist.insert($1->breaklist.end(), $3->breaklist.begin(), $3->breaklist.end());
        $$->continuelist = $1->continuelist;
        $$->breaklist = $1->breaklist;
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

		// $$->type= $2->type;
		// $$->size= $2->size;
		type = "";
		type_delim = 0;
		storage_class = "";
		
		if(!$2->is_error && !$3->is_error){
			// 3AC
			$$->nextlist = $3->nextlist;
		}
		else $$->is_error = 1;
		// cout<<"Field decn ."<<$2->type<<" "<<type<<endl;
		field_size+= GetSize($2->type);
		sym_entry* sym= Lookup(className);
		if (sym ==nullptr){
			yyerror((className+ " not inserted in symbol table").c_str());
		}
		else 
		{
			sym->fieldsize= field_size;
			//cout<<"FIelddejnb2 "<<field_size<<" "<<sym->type<<endl;
		}
		// field_size=0;
}																										
				  |  Type VariableDecltrs SCLN 				{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("FieldDecn2", v);

		type = "";
		type_delim = 0;
		storage_class = "";
		
		if(!$1->is_error && !$2->is_error){
			// 3AC
			$$->nextlist = $2->nextlist;
		}
		else $$->is_error = 1;
		//cout<<"Field decn1 "<<$2->type<<" "<<type<<endl;
		field_size+= GetSize($2->type);
		sym_entry* sym= Lookup(className);
		if (sym ==nullptr){
			yyerror((className+ " not inserted in symbol table").c_str());
		}
		else 
		{
			sym->fieldsize= field_size;
			//cout<<"FIelddejnb2 "<<field_size<<" "<<sym->type<<endl;
		}
		// field_size=0;
		// $$->type= $1->type;
		// $$->size= $1->size;
}																											
				  ;

VariableDecltrs  :  VariableDecltr	{
											$$ = $1;
											varlist.push_back($1->temp_name);
					}														
					 |  VariableDecltrs COMMA NEXT_QUAD VariableDecltr 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("VariableDecltrs", v);
		varlist.push_back($4->temp_name);

		if(!$1->is_error && !$4->is_error){
			// 3AC
			backpatch($1->nextlist, $3);
			$$->nextlist = $4->nextlist;
		}
		else $$->is_error = 1;

}																										/**/
					 ;

VariableDecltr  :  VariableDecltrId 	{$$ = $1;

										// Semantics
										if(!$1->is_error){
											if(CurLookup($1->temp_name) ){
												string errstr = $1->temp_name + " is already declared";
												yyerror(errstr.c_str());
												$$->is_error = 1;
											}
											else if($1->expType == 3){
												if(fn_decl){
													yyerror("A parameter list without types is only allowed in a function definition");
													$$->is_error = 1;
													fn_decl = 0;
												}
												DeleteFunctionPrototype();
												code.pop_back();
											}
											else{
												if(storage_class != "typedef"){
													// cout<<"IN HERE YES1 "<<$1->temp_name<<" with type "<<$1->type<<"\n";
													// if($1->type=="") 
													// {
														
													// 	$1->type= className.substr(6, className.size()-6);
													// 	cout<<"IN HERE YES\n";
													// }
													insertSymbol(*curr_table, $1->temp_name, $1->type, $1->size, 0, NULL);
													$$->place = qid($1->temp_name, Lookup($1->temp_name));
													isArray = 0;
												}
												else{
													insertTypedef(*curr_table, $1->temp_name, $1->type, $1->size, 0, NULL);
													$$->place = qid($1->temp_name, Lookup($1->temp_name));
												} 
											}
										}
										else $$->is_error = 1;
}														

					|  VariableDecltrId EQUALS NEXT_QUAD VariableInit {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node($2, v);

		// Semantics
		bool place_is_set= false;
		if(!$1->is_error && !$4->is_error){
			if( CurLookup($1->temp_name) ){ // eaelier part 
				string errstr = $1->temp_name + " is already declared";
				yyerror(errstr.c_str());
				$$->is_error = 1;
			}
			else{
				if(findStruct($1->type) && $1->type[0] == 'u') $1->size = GetSize($1->type);
				else $1->size = $1->size> (int)initializer_list_values.size()*4 ? $1->size: (int)initializer_list_values.size()*4 ;
				// cout<<"LVD 1\n";
				if($1->type=="")
				{
						// cout<<"BAD\n";
						// cout<<"HI THEN "<<$4->type<<"\n";
						$1->type= $4->type;
				}
				// cout<<"Inserting symbol "<<$4->place.first<<endl;
				insertSymbol(*curr_table, $1->temp_name, $1->type, $1->size, 1, NULL, $1->int_val, $1->str_val);
				// $$->place= $4->place;
				sym_entry* sym= Lookup($1->temp_name);
				if(find(classNamelist.begin(), classNamelist.end(), $1->type)!=classNamelist.end())
				{
					sym->place= $4->place.first;
					place_is_set=true;
				}
				else if(sym->type.back()=='*')
				{
					// cout<<"Variable INit"<< $4->place.first<<"\n";
					sym->place= $4->place.first;
					place_is_set=true;
				}
			}
			
			if(!checkIfVoid($1->type)){			
				// cout<<"Temp name is "<<	$1->temp_name<<"\n";
				sym_entry* entry = Lookup($1->temp_name);
				$1->place = qid($1->temp_name, entry);
				// cout<<"LVD woopp"<< entry->isArray<<" isArray\n";
				// if(entry->isArray || (findStruct($1->type) && $1->type.substr(0, 7) == "struct_" && $4->expType == 6)){
					
					if(arr_dimensions.find($1->temp_name)!=arr_dimensions.end() || (findStruct($1->type) && $1->type.substr(0, 7) == "struct_" && $4->expType == 6)){
					int i = 0;
					// isArray=0;
					if($4->dims.size()!=0)
					{
						// cout<<"New Dim size is "<<$4->dims.size()<<" Dim size is "<<arr_dimensions[$1->temp_name].size()<<"\n";
						if($4->dims.size()<arr_dimensions[$1->temp_name].size())
						{
							yyerror(("Invalid creation of array " + $1->temp_name + ": lesser parameters passed in NEW").c_str()); 
							$$->is_error = 1;
						}
						else if($4->dims.size()>arr_dimensions[$1->temp_name].size())
						{
							yyerror(("Invalid creation of array " + $1->temp_name + ": more parameters passed in NEW").c_str()); 
							$$->is_error = 1;
						}
						else
						{
							for(int i=0;i<$4->dims.size();i++)
							{
								if($4->dims[i]==0) arr_dimensions[$1->temp_name][i]= -1;
								else arr_dimensions[$1->temp_name][i]= $4->dims[i];
							}
							// dims.clear();
						}
					}
					else
					{
						reverse(initializer_list_values.begin(), initializer_list_values.end());
						// cout<<initializer_list_values.size()<<" initializer size \n";
						for(qid x: initializer_list_values){
							qid temp;
							temp.first = "array_init";
							temp.second = new sym_entry;
							temp.second->offset = entry->offset+i;
							temp.second->size = 4;
							i+=4;
							emit(qid("=", NULL), x, qid("", NULL), temp, -1);
						}
						global_array_init_map.insert({$1->temp_name, initializer_list_values});
					}
				}
			
				else if(findStruct($1->type) && $4->expType == 6){
					if(initializer_list_values.size() > 1){
						warning("excess elements in union initializer");
					}
					int _size = GetSize($1->type);
					for(int i = 0; i<_size; i+=4){
						qid temp;
						temp.first = "union_init";
						temp.second = new sym_entry;
						temp.second->offset = entry->offset+i;
						temp.second->size = 4;
						emit(qid("=", NULL), initializer_list_values[0], qid("", NULL), temp, -1);
					}
				}
				else{
					// cout<<"IN heredbwid"<<$1->type<<"\n";
					if(find(classNamelist.begin(), classNamelist.end(), $1->type)==classNamelist.end())
					{
						assign_exp("=", $1->type,$1->type, $4->type, $1->place, $4->place);
					}
					// $$->intval= $4->intval;
				}
				
				if(!place_is_set) 
				{
					$$->place = $1->place;

				}
				// cout<<"Plce is "<<$1->place.first<<endl;
				$$->nextlist = $4->nextlist;
				backpatch($1->nextlist, $3);
			}
			else { 
				yyerror(("Invalid assignment to variable of type " + $1->type).c_str()); 
				$$->is_error = 1;
			}
			if(!place_is_set)  $$->place = qid($1->temp_name, Lookup($1->temp_name));
		}
		else $$->is_error = 1;
		initializer_list_values.clear();
	}										
					;

VariableDecltrId  :  IDENTIFIER		{
								$$ = create_AST_leaf($1, "IDENTIFIER");
								type_delim = 1;

								$$->expType = 1; // Variable
								$$->type = type;
								if(type=="")
								{
									$$->type= className.substr(6, className.size()-6);
									// sym_entry* sym= Lookup(string($1));
									// $$->place= 
								}
								$$->temp_name = string($1);
								$$->size = GetSize(type);

								//3AC
								// if(type=="") $$->place= sym->sym_place;
								 $$->place = qid($$->temp_name, NULL);
			}															
					  |  VariableDecltrId OSQ CSQ {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ ]", 0);
		$$ = create_AST_node("VariableDecltrId", v);
		
		// Semantics
		if(!$1->is_error){
			if($1->expType <=2 ) {
				$$->expType = 2;
				$$->type = $1->type + "*";
				$$->temp_name = $1->temp_name;
				$$->size = 8;	 // pointer type 
				$$->int_val = 8;
				// cout<<"Are we seetting 1\n";
				// isArray=1;
				//3AC
				
				$$->place = qid($$->temp_name, NULL);
				array_dims.push_back(0); //size of array_dims will indicate size of array
				if(arr_dimensions.find($1->temp_name)==arr_dimensions.end())
				{
					vector<int> temp;
					temp.push_back(0);
					arr_dimensions[$1->temp_name]= temp;
					arr_index[$1->temp_name]= 0;
				}
				else arr_dimensions[$1->temp_name].push_back(0);
				// cout<<"dims of array "<<$$->temp_name<<" is "<<arr_dimensions[$1->temp_name].size()<<"\n";
				isArray = 1;
			}
			else {
				yyerror(( $1->temp_name + " declared as function returning an array").c_str());
				$$->is_error = 1;
			}
		}
		else $$->is_error = 1;
	}												
					  ;

VariableInit  :  Expr 			{$$ = $1; 	
								initializer_list_values.push_back($1->place);
								}															
					 |  ArrInit 	{$$ = $1;}															
					 ;

MethodDecn  :  MethodHead F MethodBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("MethodDecn", v);

			// Semantics
		type = "";
		type_delim = 0;
		funcName = "";
		funcType = "";

		for(auto i: gotolablelist){
			if(gotolabel.find(i.first) == gotolabel.end()){
				yyerror(("label \'" + string(i.first) + "\' used but not defined").c_str());
			}
			else backpatch(i.second, gotolabel[i.first]);
		}

		if($1->is_error || $3->is_error) {
			$$->is_error = 1;
		}

		if($2->is_error) {
			$$->is_error = 1;
			DeleteFunctionPrototype();
		}

		else {
			string fName = $2->name;
			string cName= className.substr(6, className.size()-6);
			string funName= cName+ "_" +fName+ ".csv";
			// string func_3AC= cName+ "."+ fName;
			string func_3AC= fName;
			printSymbolTable(curr_table ,funName);
			SymbolTableUpdation(fName,1);
			
			sym_entry* sym= Lookup(fName);

			// if(sym==nullptr) cout<<"THIS IS NULL BRODIJ "<<funcName<<"\n";
			
			sym->funcsize= sym->size;
			emit(qid("FUNC_" + func_3AC + " end :", sym), qid(to_string(sym->size), NULL), qid("", NULL), qid("", NULL), -1);
			// cout<<"IN PARSER "<<fName<<" "<<sym->type<<" "<<sym->size<<endl;
			backpatch_remaining();
			// cout<<" ended "<<fName<<endl;
			
		}
	}																											
				   ;

F: 				{
						$$ = new Node();
						clear_paramoffset();
						// param_offset = -4;
						
						if (gst.find(funcName) != gst.end()){
							yyerror(("Redefinition of function " + funcName).c_str());
							$$->is_error = 1;
						}
						else{
						
							CreateSymbolTable(funcName, funcType,1, 1);
							sym_entry* sym= Lookup(funcName);
							if(sym==nullptr) cout<<"THIS IS NULL BRO3 "<<funcName<<"\n";
							// emit(qid("FUNC_size",sym),qid("",NULL),qid("",NULL),qid("",NULL),-1);
							// cout<<" whdih "<<funcName<<endl;
							// if(find(classNamelist.begin(), classNamelist.end(), funcName)!=classNamelist.end())
							// {
							// 	qid tmp= newtemp("");
							// 	emit(qid("=", NULL), qid("popparam",NULL), qid(funcName, NULL), tmp, -1);
								
							// 	$$->place= tmp;
							// 	constructor_temporary= tmp.first;
							// }
							// pop_function_arguments($$->type);
								// cout<<"F "<<funcName<<"\n";
							// cout<<"Here "<<sym->type<<endl;
							// cout<<"Param size is "<<param_size<<endl;
							// cout<<funcType<<" TYPE "<<funcName<<"\n";
							if(funcType=="") sym->paramsize= param_size;
							else sym->paramsize= param_size+ GetSize(funcType);// To accomodate space for return value. 
							// cout<<"INSIDE F my func size is "<<sym->size<<endl;
				
							// cout<<"Function locals and temporaries size is "<<sym->size<<endl;
							// sym->funcsize= sym->size;
							// cout<<"sehhhh is "<<param_size<<endl;
							param_size=0;
							$$->name = (funcName);
							block_count = 1; 
							type = "";
							type_delim = 0;
						}

		}	

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
		// if($1 == "static")is_static.insert($3);
	}																									
			  																											
			  ;

MethodIdentifier: IDENTIFIER { $$ = create_AST_leaf($1, "IDENTIFIER");
		// cout<<"Method Identifier "<<"\n";
		// Semantics
		$$->expType = 1; // Variable
		if(type != "") $$->type = type;
		else $$->type = "int";
		$$->temp_name = string($1);
		$$->size = GetSize(type);

		//3AC
		$$->place = qid($$->temp_name, NULL);


}

MethodDecltr  :  MethodIdentifier OS M FormalParamList CS NEXT_QUAD {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("MethodDecltr1", attr);
		// cout<<$4->is_error<<" YES\n";
		
		// Semantics
		if(!$1->is_error && !$4->is_error){
			// cout<<"Type heere is "<<$1->expType<<"\n";
			if($1->expType == 1) {
				$$->temp_name = $1->temp_name;
				$$->expType = 3; // function declaration
				$$->type = $1->type;
				$$->size = GetSize($$->type);
				string fName= $1->temp_name;
				string cName= className.substr(6, className.size()-6);
				string funName= cName+ "_" +fName+ ".csv";
				// string func_3AC= cName+ "."+ fName;
				string func_3AC= fName;

				vector<string> temp = getFuncArgs($1->temp_name);
				// for(int i=0;i<temp.size();i++)
				// {
				// 	cout<<temp[i]<<" ";
				// }
				// cout<<endl;
				
				if(temp.size() == 1 && temp[0] == "#NO_FUNC"){
					insertFuncArg($$->temp_name, funcArgs, $$->type);
					funcArgs.clear();
					funcName = string($1->temp_name);
					funcType = $1->type;
					
					//3AC
					$$->place = qid($$->temp_name, NULL);
					backpatch($4->nextlist,$6);
					
					// sym_entry* sym= Lookup(funcName);
					// if(sym==nullptr) cout<<"THIS IS NULL BRO1 "<<funcName<<"\n";
					emit(pair<string,sym_entry*>("FUNC_" + func_3AC + " start :",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
					
					
					// qid tmp = newtemp($$->type);
					// emit(qid("",NULL),qid("",NULL),qid("",NULL),tmp, -1 );
					// cout<<"CRASH\n";
				}
				else{
					// Check if temp is correct
					if(temp == funcArgs){
						funcArgs.clear();
						funcName = string($1->temp_name);
						funcType = $1->type;

						//3AC
						$$->place = qid($$->temp_name, NULL);
						backpatch($4->nextlist,$6);
						sym_entry* sym= Lookup($1->temp_name);
						
						emit(pair<string,sym_entry*>("FUNC_" + func_3AC + " start :",sym),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
						
					}
					else {
						yyerror(("Conflicting types for function " + $1->temp_name).c_str());
						$$->is_error = 1;
					}
				}
			}
			else {
				if($1->expType == 2){
					yyerror( ($1->temp_name + "declared as array of function").c_str());
				}
				else{
					yyerror( ($1->temp_name + "declared as function of function").c_str());
				}
				$$->is_error = 1;
			}
		}
		else $$->is_error =1;
		
	}											
				  |  MethodIdentifier OS M CS 	{
			$$ =$1;

			// $$->temp_name= $1->temp_name;
			// Semantics
				if(!$1->is_error){
				if($1->expType == 1) {
				$$->temp_name = $1->temp_name;
				$$->expType = 3;
				$$->type = $1->type;
				$$->size = GetSize($$->type);
				string fName= $1->temp_name;
				string cName= className.substr(6, className.size()-6);
				string funName= cName+ "_" +fName+ ".csv";
				// string func_3AC= cName+ "."+ fName;
				string func_3AC= fName;
				// cout<<"Start\n";
				vector<string> temp = getFuncArgs($1->temp_name);
				if((temp.size() == 1 && temp[0] == "#NO_FUNC") || funcArgs == temp){
					insertFuncArg($$->temp_name, funcArgs, $$->type);
					funcArgs.clear();
					funcName = string($1->temp_name);
					funcType = $1->type;
				}
				else {
					yyerror(("Conflicting types for function " + $1->temp_name).c_str());
					$$->is_error = 1;
				}
				//3AC
				$$->place = qid($$->temp_name, NULL);
				sym_entry* sym= Lookup($1->temp_name);
				emit(pair<string,sym_entry*>("FUNC_" + func_3AC + " start :",sym),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
			}
			else {
				if($1->expType == 2){
					yyerror( ($1->temp_name + "declared as array of function").c_str());
				}
				else{
					yyerror( ($1->temp_name + "declared as function of function").c_str());
				}
				$$->is_error = 1;
			}
		}
		else $$->is_error = 1;
		}															
				  |  MethodDecltr OSQ OSQ 		{ 
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "[ [", 0);
		$$ = create_AST_node("MethodDecltr2", v);

		// Semantics
		if($1->expType == 1) {
			$$->temp_name = $1->temp_name;
			$$->expType = 3;
			$$->type = $1->type;
			$$->size = GetSize($$->type);
			vector<string> temp = getFuncArgs($1->temp_name);
			if(temp.size() == 1 && temp[0] == "#NO_FUNC"){
				insertFuncArg($$->temp_name, funcArgs, $$->type);
				funcArgs.clear();
				funcName = string($1->temp_name);
				funcType = $1->type;
			}
			else{
				yyerror(("Conflicting types for function " + $1->temp_name).c_str());
			}
		}
		else {
			if($1->expType == 2){
				yyerror( ($1->temp_name + "declared as array of function").c_str());
			}
			else{
				yyerror( ($1->temp_name + "declared as function of function").c_str());
			}
		}
	}												
				  ;

M: 							{
	type ="";
	// cout<<"Function flag set to zero in func declaration\n";
		func_flag = 0;
		funcArgs.clear();
		CreateParameterList();
		gotolablelist.clear();
		gotolabel.clear();
}


FormalParamList  :  FormalParam 	{
				$$ = $1;
			}															
					 |  FormalParamList COMMA NEXT_QUAD FormalParam  	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("FormalParamList", v);

		if(!$1->is_error && !$4->is_error){
			// 3AC
			backpatch($1->nextlist, $3);
			$$->nextlist = $4->nextlist;
		}
		else $$->is_error = 1;
}																										
					 ;

FormalParam  :  Type VariableDecltrId 			{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("FormalParam", v);

		// Semantics
		if(!$1->is_error && !$2->is_error){
			type_delim = 0;
			type = "";
			if($2->expType == 1 || $2->expType == 2) {
				if(CurLookup($2->temp_name)) {
					yyerror(("Redeclaration of Parameter " + $2->temp_name).c_str());
					$$->is_error = 1;
				}
				else {
					paramInsert(*curr_table, $2->temp_name, $2->type, $2->size, true, NULL);
					param_size+=$2->size;
					sym_entry* sym= Lookup($2->temp_name);
					// if(sym==nullptr) {
					// 	yyerror(($2->temp_name+" not found").c_str());
					// }
					// cout<<sym->offset<<" Ujwal\n";
					// qid temp= newtemp($$->type);
					// emit(qid("=", NULL), qid("popparam",NULL), qid($2->temp_name, NULL), temp, -1);
					// sym->place= 
					// insertSymbol(*curr_table, $2->temp_name, $2->type, $2->size, 1, NULL);
				}
				funcArgs.push_back($2->type);
			}
		}
		else $$->is_error = 1;
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

// MethodBody also calls Block. So the last time that Block is called if for methodybody.
// (within a function.) CT is called from innermost block first. 
// So anything within the curly brackets of the function will be printed in 
// the function table. That is, until a new nested scope is created, which 
// calls CT again, this time changing the table to a block and adding 


MethodBody  : SCLN  	{$$ = create_AST_leaf($1, "SCLN");}																	
			| Block 	{
								// cout<<"Block called for method body\n";
								$$ = $1;
						}																						
			;


StaticInit  :  STATIC Block 		{
		vector<treeNode> v;
		// add_attribute(v, create_AST_leaf($1, "STATIC"), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("StaticInit", v);
	}																					
				   ;

ConstructorDecn  :  Modifiers ConstructorDecltr Throws F ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("ConstructorDecn1", v);

		// Semantics
		// Semantics
		type = "";
		type_delim = 0;
		funcName = "";
		funcType = "";

		for(auto i: gotolablelist){
			if(gotolabel.find(i.first) == gotolabel.end()){
				yyerror(("label \'" + string(i.first) + "\' used but not defined").c_str());
			}
			else backpatch(i.second, gotolabel[i.first]);
		}

		if($1->is_error || $2->is_error || $3->is_error|| $5->is_error) {
			$$->is_error = 1;
		}

		if($4->is_error) {
			$$->is_error = 1;
			DeleteFunctionPrototype();
		}

		else {
			string fName = $4->name;
			// printSymbolTable(curr_table ,fName + ".csv");
			string cName= className.substr(6, className.size()-6);
			string constName= cName+ "_ctor"+ to_string(constructor_num)+ ".csv";
			string constr_3AC=  cName+ ".ctor"+ to_string(constructor_num);
			printSymbolTable(curr_table ,constName);
			constructor_num++;
			SymbolTableUpdation(fName,1);
			sym_entry* sym= Lookup(fName);
			
			sym->funcsize= sym->size;
			// if(sym==nullptr) cout<<"THIS IS NULL BRODIJ "<<funcName<<"\n";
			// emit(qid("FUNC_" + func_3AC + " end :", sym), qid(to_string(sym->size), NULL), qid("", NULL), qid("", NULL), -1);
			emit(qid("FUNC_" +  constr_3AC + " end :", sym), qid(to_string(sym->size), NULL), qid("", NULL), qid("", NULL), -1);
			backpatch_remaining();
			constructor_temporary="";
		}
	}												
						|  Modifiers ConstructorDecltr F ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ConstructorDecn3", v);

		// Semantics
			// Semantics
		type = "";
		type_delim = 0;
		funcName = "";
		funcType = "";

		for(auto i: gotolablelist){
			if(gotolabel.find(i.first) == gotolabel.end()){
				yyerror(("label \'" + string(i.first) + "\' used but not defined").c_str());
			}
			else backpatch(i.second, gotolabel[i.first]);
		}

		if($1->is_error || $2->is_error || $4->is_error) {
			$$->is_error = 1;
		}

		if($3->is_error) {
			$$->is_error = 1;
			DeleteFunctionPrototype();
		}

		else {
			// cout<<className<<"in constructor\n";
			string fName = $3->name;
			string cName= className.substr(6, className.size()-6);
			string constName= cName+ "_ctor"+ to_string(constructor_num)+ ".csv";
			string constr_3AC=  cName+ ".ctor"+ to_string(constructor_num);
			printSymbolTable(curr_table ,constName);
			constructor_num++;
			// printSymbolTable(curr_table ,fName + ".csv");
			sym_entry* sym= Lookup(fName);
			// cout<<"hijk1 "<<sym->size<<endl;
			sym->funcsize= sym->size;
			// if(sym==nullptr) cout<<"THIS IS NULL BRODIJ "<<funcName<<"\n";
			SymbolTableUpdation(fName,1);
			emit(qid("FUNC_" +  constr_3AC  + " end :", sym), qid(to_string(sym->size), NULL), qid("", NULL), qid("", NULL), -1);
			backpatch_remaining();
			constructor_temporary="";
		}
	}											
						|  ConstructorDecltr F ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("ConstructorDecn4", v);

		// Semantics
			// Semantics
		type = "";
		type_delim = 0;
		funcName = "";
		funcType = "";

		for(auto i: gotolablelist){
			if(gotolabel.find(i.first) == gotolabel.end()){
				yyerror(("label \'" + string(i.first) + "\' used but not defined").c_str());
			}
			else backpatch(i.second, gotolabel[i.first]);
		}

		if($1->is_error || $3->is_error) {
			$$->is_error = 1;
		}

		if($2->is_error) {
			$$->is_error = 1;
			DeleteFunctionPrototype();
		}

		else {
			string fName = $2->name;
			string cName= className.substr(6, className.size()-6);
			string constName= cName+ "_ctor"+ to_string(constructor_num)+ ".csv";
			string constr_3AC=  cName+ ".ctor"+ to_string(constructor_num);
			printSymbolTable(curr_table ,constName);
			// printSymbolTable(curr_table ,"_ctor" +to_string(constructor_num)+ ".csv");
			constructor_num++;
			// printSymbolTable(curr_table ,fName + ".csv");
			SymbolTableUpdation(fName,1);
			sym_entry* sym= Lookup(fName);
			// cout<<"hijk1 "<<sym->size<<endl;
			sym->funcsize= sym->size;
			// if(sym==nullptr) cout<<"THIS IS NULL BRODIJ "<<funcName<<"\n";
			emit(qid("FUNC_" +  constr_3AC + " end :", sym), qid(to_string(sym->size), NULL), qid("", NULL), qid("", NULL), -1);
			backpatch_remaining();
			constructor_temporary="";
		}
	}				
						|  ConstructorDecltr Throws F ConstructorBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("ConstructorDecn2", v);

			// Semantics
		type = "";
		type_delim = 0;
		funcName = "";
		funcType = "";

		for(auto i: gotolablelist){
			if(gotolabel.find(i.first) == gotolabel.end()){
				yyerror(("label \'" + string(i.first) + "\' used but not defined").c_str());
			}
			else backpatch(i.second, gotolabel[i.first]);
		}

		if($1->is_error || $2->is_error || $3->is_error) {
			$$->is_error = 1;
		}

		if($3->is_error) {
			$$->is_error = 1;
			DeleteFunctionPrototype();
		}

		else {
			string fName = $3->name;
			string cName= className.substr(6, className.size()-6);
			string constName= cName+ "_ctor"+ to_string(constructor_num)+ ".csv";
			string constr_3AC=  cName+ ".ctor"+ to_string(constructor_num);
			printSymbolTable(curr_table ,constName);
			// printSymbolTable(curr_table ,"ctor" +to_string(constructor_num)+ ".csv");
			constructor_num++;
			// printSymbolTable(curr_table ,fName + ".csv");
			SymbolTableUpdation(fName,1);
			emit(qid("FUNC_" +  constr_3AC + " end :", NULL), qid("", NULL), qid("", NULL), qid("", NULL), -1);
			backpatch_remaining();
			constructor_temporary="";
		}
	}											
															
						;

ConstructorName: IDENTIFIER {
									$$=create_AST_leaf($1, "IDENTIFIER");

									$$->expType = 1; // Variable
									$$->temp_name = string($1);
									$$->size = GetSize(type);

									//3AC
									$$->place = qid($$->temp_name, NULL);
									// $$->temp_name= string($1);
									// $$->expType=1;
}

ConstructorDecltr  :  ConstructorName OS M FormalParamList CS  NEXT_QUAD	{
		vector<treeNode> v, v2;
		add_attribute(v2, $4, "", 1);
		Node* node = create_AST_node("( )", v2);
		add_attribute(v, $1, "", 1);
		add_attribute(v, node, "", 1);
		$$ = create_AST_node("ConstructorDecltr1", v);

		// Semantics
		if(!$1->is_error && !$4->is_error){
			if($1->expType == 1) {
				$$->temp_name = $1->temp_name;
				$$->expType = 3;
				$$->type = $1->type;
				$$->size = GetSize($$->type);
				string cName= className.substr(6, className.size()-6);
				string constr_3AC=  cName+ ".ctor"+ to_string(constructor_num);
				// constructor_num++;
				vector<string> temp = getFuncArgs($1->temp_name);
				if(temp.size() == 1 && temp[0] == "#NO_FUNC"){
					insertFuncArg($$->temp_name, funcArgs, $$->type);
					funcArgs.clear();
					funcName = string($1->temp_name);
					funcType = $1->type;
					
					// string constName= cName+ "_ctor"+ to_string(constructor_num)+ ".csv";
					//3AC
					$$->place = qid($$->temp_name, NULL);
					backpatch($4->nextlist,$6);
					emit(pair<string,sym_entry*>("FUNC_" + constr_3AC + " start :",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
				}
				else{
					// Check if temp is correct
					if(temp == funcArgs){
						funcArgs.clear();
						funcName = string($1->temp_name);
						funcType = $1->type;

						//3AC
						$$->place = qid($$->temp_name, NULL);
						backpatch($4->nextlist,$6);
						emit(pair<string,sym_entry*>("FUNC_" + constr_3AC + " start :",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
					}
					else {
						yyerror(("Conflicting types for function " + $1->temp_name).c_str());
						$$->is_error = 1;
					}
				}
			}
			else {
				if($1->expType == 2){
					yyerror( ($1->temp_name + "declared as array of function").c_str());
				}
				else{
					yyerror( ($1->temp_name + "declared as function of function").c_str());
				}
				$$->is_error = 1;
			}
		}
		else $$->is_error =1;
	}						
					   |  ConstructorName OS M CS 	{	
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, NULL, "( )", 0);
		$$ = create_AST_node("ConstructorDecltr2", v);

			// Semantics
		if(!$1->is_error){
			if($1->expType == 1) {
				$$->temp_name = $1->temp_name;
				$$->expType = 3;
				$$->type = $1->type;
				$$->size = GetSize($$->type);
				string cName= className.substr(6, className.size()-6);
				string constr_3AC=  cName+ ".ctor"+ to_string(constructor_num);
				// constructor_num++;
				vector<string> temp = getFuncArgs($1->temp_name);
				if((temp.size() == 1 && temp[0] == "#NO_FUNC") || funcArgs == temp){
					insertFuncArg($$->temp_name, funcArgs, $$->type);
					funcArgs.clear();
					funcName = string($1->temp_name);
					funcType = $1->type;
				}
				else {
					yyerror(("Conflicting types for function " + $1->temp_name).c_str());
					$$->is_error = 1;
				}
				//3AC
				$$->place = qid($$->temp_name, NULL);
				// emit(pair<string,sym_entry*>("FUNC_" + $$->temp_name + " start :",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
				emit(pair<string,sym_entry*>("FUNC_" + constr_3AC + " start :",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),pair<string,sym_entry*>("",NULL),-2);
			}
			else {
				if($1->expType == 2){
					yyerror( ($1->temp_name + "declared as array of function").c_str());
				}
				else{
					yyerror( ($1->temp_name + "declared as function of function").c_str());
				}
				$$->is_error = 1;
			}
		}
		else $$->is_error = 1;
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


IntfaceDecn  :  Modifiers INTERFACE StructName ExtendsIntfaces S IntfaceBody {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, create_AST_leaf($3,"IDENTIFIER"), "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $6, "", 1);
		$$ = create_AST_node("IntfaceDecn1", v);

		if(ShowStructTable("STRUCT_" + structName) == 1){
			if(type == "")type = "STRUCT_" + structName;
			else type += " STRUCT_" + structName;
		}
		else {
			yyerror(("Struct " + structName + " is already defined").c_str());
		}

		varlist.clear();
}																						
									  |  Modifiers INTERFACE StructName S IntfaceBody 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, create_AST_leaf($3,"IDENTIFIER"), "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("IntfaceDecn3", v);

		if(ShowStructTable("STRUCT_" + structName) == 1){
			if(type == "")type = "STRUCT_" + structName;
			else type += " STRUCT_" + structName;
		}
		else {
			yyerror(("Struct " + structName + " is already defined").c_str());
		}
		varlist.clear();
}															
					  |  INTERFACE StructName S IntfaceBody 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($3,"IDENTIFIER"), "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("IntfaceDecn4", v);

		if(ShowStructTable("STRUCT_" + structName) == 1){
			if(type == "")type = "STRUCT_" + structName;
			else type += " STRUCT_" + structName;
		}
		else {
			yyerror(("Struct " + structName + " is already defined").c_str());
		}
		varlist.clear();
}			
					  |  INTERFACE StructName ExtendsIntfaces S IntfaceBody {
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($2,"IDENTIFIER"), "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("IntfaceDecn2", v);

		if(ShowStructTable("STRUCT_" + structName) == 1){
			if(type == "")type = "STRUCT_" + structName;
			else type += " STRUCT_" + structName;
		}
		else {
			yyerror(("Struct " + structName + " is already defined").c_str());
		}
		varlist.clear();
}								
									
					  ;


StructName: IDENTIFIER		{
					$$= $1;
					structName= $1;
}


S: 				{
	CreateStructTable();
}



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
			   |   OC CT IntfaceMemberDecnRec CC 	{
				//    $$ = $2;
				vector<treeNode> v;
			add_attribute(v, $3, "", 1);
			$$ = create_AST_node("Interface", v);

			   if(func_flag>=2){
					int bc = block_stack.top();
					block_stack.pop();
					string str = "Block" + to_string(bc);
					string name = funcName+str+".csv";
					printSymbolTable(curr_table, name);
					SymbolTableUpdation(str, 0);
					func_flag--;
				}
				   }																																
			   ;

IntfaceMemberDecnRec  :  IntfaceMemberDecn {$$ = $1;}											
							   |  IntfaceMemberDecnRec IntfaceMemberDecn 					{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("IntfaceMemberDecnRec", v);
}															
							   ;

IntfaceMemberDecn  :  ConstantDec 	{
										$$ = $1;
										for(auto it: varlist)
										{
											if (AddStructAttr(it, $1->type, $1->size, 0) != 1){
											yyerror(("The Attribute " + string(it) + " is already declared in the same struct").c_str());
											} 
										}
										}													
							|  AbstractMethod 		{$$ = $1;}									 			
							;

ConstantDec  :  FieldDecn 		{$$ = $1;}											
					 ;

AbstractMethod  :  MethodHead SCLN 	{
											$$ = $1;
											// what size to I use here? 
											if (AddStructAttr($1->temp_name, $1->type, 4, 0) != 1){
											yyerror(("The abstract method " + $1->temp_name + " is already declared in the same struct").c_str());
											}				
						}															
						   ;

ArrInit : OC VariableInitList COMMA CC 		{

		$$ = $2;
		$$->expType = 6;
		if(!$2->is_error){
			//3AC
			$$->place = $2->place;
			$$->nextlist = $2->nextlist;
		}
}																							
				 | OC VariableInitList CC 	{
		// vector<treeNode> v;
		// add_attribute(v, $2, "", 1);
		// $$ = create_AST_node("ArrInit3", v);
			$$ = $2 ;
		$$->expType = 6;
}																						
				 | OC CC			{
					 $$ = create_AST_leaf($1, "EMPTY");
					 $$->expType= 6;
				 }
				 | OC COMMA CC 			{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($2, ""), "", 1);
		$$ = create_AST_node("ArrInit2", v);
		 $$->expType= 6;
}																								
																						
				 ;

VariableInitList : VariableInitList COMMA NEXT_QUAD VariableInit 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $4, "", 1);
		$$ = create_AST_node("VariableInitList", v);

		if(!$1->is_error && !$4->is_error){
			//3AC
			backpatch($1->nextlist, $3);
			$$->nextlist = $4->nextlist;
		}
		else $$->is_error = 1;
}																
						| VariableInit 		{$$ = $1;}													
						;


Block : OC CT BlockStmts CC 		{
					// $$ = $2;
					vector<treeNode> v;
					add_attribute(v, $3, "", 1);
					$$ = create_AST_node("Block", v);
					// cout<<"Block stmt "<<func_flag<<" \n";
					// varlist.clear();

					if(func_flag>=2){
					int bc = block_stack.top();
					block_stack.pop();
					string str = "Block" + to_string(bc);
					string name = funcName+str+".csv";
					printSymbolTable(curr_table, name);
					SymbolTableUpdation(str, 0);
					func_flag--;
				}
				// cout<<"BLock reduced "<<func_flag<<"\n";

// 
	}																					
	  | OC CC 		{$$ = create_AST_leaf("{}", "EMPTY");}																											
	  ;

// { {} }
CT: 				{
				// cout<<"CT "<<func_flag<<" \n";
				varlist.clear(); // not using 
				if(func_flag){
					
					string str = "Block" +to_string(block_count);
					// cout<<"Symbol table "<<str<< " created \n";
					// pushes to block_stack. Popped later after block finishes. 
					block_stack.push(block_count);
					block_count++;
					func_flag++;
					CreateSymbolTable(str, "", 0, 1);
				}
				else func_flag++;
}

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
		// cout<<"LVD\n";
		type=""; // resetting type 
		type_delim = 0;
		storage_class = "";
		
		if(!$1->is_error && !$2->is_error){
			// 3AC
			$$->nextlist = $2->nextlist;
		}
		else $$->is_error = 1;
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
									 |  Block 		{$$ = $1;} // block contains block										
									 | EmptyStmt 	{$$ = $1;}												
									 | ReturnStmt 			{$$ = $1;}										
									 | SynchronizedStmt 	{$$ = $1;}											
									 ;
EmptyStmt : SCLN 		{$$ = create_AST_leaf($1, "SCLN");}																						
			   ;

LabeledStmt : IDENTIFIER COLON Stmt 		{$$ = create_AST_leaf($1, "IDENTIFIER");}	 // change later 												
				 ;

LabeledStmtNoShortIf : IDENTIFIER COLON StmtKind 	{$$ = create_AST_leaf($1, "IDENTIFIER");}									
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

		
IfThenStmt : IF_CODE NEXT_QUAD Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		$$ = create_AST_node("IfThenStmt", v);

		if($1->is_error || $3->is_error)	{
			$$->is_error = 1;
		}

        backpatch($1->truelist, $2);
		$3->nextlist.insert($3->nextlist.end(), $1->falselist.begin(), $1->falselist.end());// merges 
        $$->nextlist= $3->nextlist;
        $$->continuelist = $3->continuelist;
        $$->breaklist = $3->breaklist;
	}										
				;

IfThenElseStmt : IF_CODE NEXT_QUAD StmtKind N ELSE NEXT_QUAD Stmt {
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("IfThenElseStmt", v);

		if($1->is_error || $3->is_error || $7->is_error)	{
			$$->is_error = 1;
		}

        backpatch($1->truelist, $2);
        backpatch($1->falselist, $6);
		$3->nextlist.insert($3->nextlist.end(), $4->nextlist.begin(), $4->nextlist.end());
		$3->nextlist.insert($3->nextlist.end(), $7->nextlist.begin(), $7->nextlist.end());
        $$->nextlist = $3->nextlist;
		$3->breaklist.insert($3->breaklist.end(), $7->breaklist.begin(), $7->breaklist.end());
		$$->breaklist = $3->breaklist;
		$3->continuelist.insert($3->continuelist.end(), $7->continuelist.begin(), $7->continuelist.end());
		$$->continuelist = $3->continuelist;
	};

IfThenElseStmtKind : IF_CODE NEXT_QUAD StmtKind N ELSE NEXT_QUAD StmtKind 		{
		vector<treeNode> v;
		add_attribute(v, $1, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("IfThenElseStmtKind", v);
		if($1->is_error || $3->is_error || $7->is_error)	{
			$$->is_error = 1;
		}

        backpatch($1->truelist, $2);
        backpatch($1->falselist, $6);
		$3->nextlist.insert($3->nextlist.end(), $4->nextlist.begin(), $4->nextlist.end());
		$3->nextlist.insert($3->nextlist.end(), $7->nextlist.begin(), $7->nextlist.end());
        $$->nextlist = $3->nextlist;
		$3->breaklist.insert($3->breaklist.end(), $7->breaklist.begin(), $7->breaklist.end());
		$$->breaklist = $3->breaklist;
		$3->continuelist.insert($3->continuelist.end(), $7->continuelist.begin(), $7->continuelist.end());
		$$->continuelist = $3->continuelist;
	}				
							 ;


IF_CODE
		: IF {if_found=1;} OS Expr CS {
            if($4->truelist.empty() && $4->falselist.empty()) {
            int a = code.size();
			backpatch($4->nextlist, a);
            emit(qid("GOTO", NULL),qid("IF", Lookup("if")), $4->place, qid("", NULL ),0);
            int b = code.size();
            emit(qid("GOTO", NULL),qid("", NULL), qid("", NULL), qid("", NULL ),0);
            $4->truelist.push_back(a);
            $4->falselist.push_back(b);
        }
        $$ = $4;
		if_found = 0;
		}


SwitchStmt : SWITCH OS Expr CS SwitchBlock {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("SwitchStmt", v);
       if($3->is_error || $5->is_error)	{
			$$->is_error = 1;
		}

        casepatch($5->caselist, $3->place);
        $5->nextlist.insert($5->nextlist.end(), $5->breaklist.begin(), $5->breaklist.end());
		$$->nextlist= $5->nextlist;
        $$->continuelist= $5->continuelist;
		
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
// WHILE OS Expr CS Stmt
WhileStmt : WHILE OS NEXT_QUAD EXPR_STMT_CODE CS NEXT_QUAD Stmt {
		vector<treeNode> v;
		// add_attribute(v, $3, "", 1);
		// add_attribute(v, $5, "", 1);
		add_attribute(v, $4, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("WhileStmt", v);

		if($4->is_error || $7->is_error)	{
			$$->is_error = 1;
		}
	
        backpatch($4->truelist, $6);
		$7->nextlist.insert($7->nextlist.end(), $7->continuelist.begin(), $7->continuelist.end());
        backpatch($7->nextlist, $3);
        $$->nextlist = $4->falselist;
        $$->nextlist.insert($$->nextlist.end(), $7->breaklist.begin(), $7->breaklist.end());
        emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), $3);
    }
						
			   ;

// WhileStmtKind : WHILE OS Expr CS StmtKind {
WhileStmtKind : WHILE OS Expr CS StmtKind {
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("WhileStmtKind", v);
	}						
						;

// DoStmt : DO Stmt WHILE OS Expr CS SCLN 	{
DoStmt : DO NEXT_QUAD Stmt WHILE OS NEXT_QUAD EXPR_STMT_CODE CS SCLN 	{
		vector<treeNode> v;
		// add_attribute(v, $2, "", 1);
		// add_attribute(v, $5, "", 1);
		add_attribute(v, $3, "", 1);
		add_attribute(v, $7, "", 1);
		$$ = create_AST_node("DoStmt", v);
				if($3->is_error || $7->is_error)	{
			$$->is_error = 1;
		}

        backpatch($7->truelist, $2);
        $3->nextlist.insert($3->nextlist.end(), $3->continuelist.begin(), $3->continuelist.end());
		backpatch($3->nextlist, $6);
        $$->nextlist = $7->falselist;
		$$->nextlist.insert($$->nextlist.end(), $3->breaklist.begin(), $3->breaklist.end());
	}											
			;

ForStatement : ForStmt {$$ = $1;}																	
			 ;

ForStatementKind : ForStmtKind 	{$$ = $1;}													
					  ;

ForStmt : FOR OS ForInit SCLN NEXT_QUAD EXPR_STMT_CODE SCLN NEXT_QUAD ForUpdate N CS NEXT_QUAD Stmt 	{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $9, "", 1);
		add_attribute(v, $13, "", 1);
		$$ = create_AST_node("BasicForStmt1", v);

		if($3->is_error || $6->is_error || $9->is_error || $13->is_error)	{
			$$->is_error = 1;
		}
	
        backpatch($3->nextlist, $5);
        backpatch($6->truelist, $12);
        $$->nextlist = $6->falselist;
		$$->nextlist.insert($$->nextlist.end(), $13->breaklist.begin(), $13->breaklist.end());
		$13->nextlist.insert($13->nextlist.end(), $13->continuelist.begin(), $13->continuelist.end());
        backpatch($13->nextlist, $8);
		$9->nextlist.insert($9->nextlist.end(), $10->nextlist.begin(), $10->nextlist.end());
        backpatch($9->nextlist, $5);
        emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), $8);
    }
					  | FOR OS ForInit NEXT_QUAD SCLN EXPR_STMT_CODE SCLN CS NEXT_QUAD Stmt 	{
		vector<treeNode> v;
		// 3->3, 4->4, 5->6 , 7->9, 8->10 
		add_attribute(v, $3, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $10, "", 1);
		$$ = create_AST_node("BasicForStmt5", v);

		if($3->is_error || $6->is_error || $10->is_error)	{
			$$->is_error = 1;
		}
        backpatch($3->nextlist, $4);
        backpatch($6->truelist, $9);
        $$->nextlist = $6->falselist;
		$$->nextlist.insert($$->nextlist.end(), $10->breaklist.begin(), $10->breaklist.end());
        $10->nextlist.insert($10->nextlist.end(), $10->continuelist.begin(), $10->continuelist.end());
        backpatch($10->nextlist, $4);
        emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), $4);
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

ForStmtKind : FOR OS ForInit SCLN NEXT_QUAD EXPR_STMT_CODE SCLN NEXT_QUAD ForUpdate N CS NEXT_QUAD StmtKind  		{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $9, "", 1);
		add_attribute(v, $13, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf1", v);

		if($3->is_error || $6->is_error || $9->is_error || $13->is_error)	{
			$$->is_error = 1;
		}
	
        backpatch($3->nextlist, $5);
        backpatch($6->truelist, $12);
        $$->nextlist = $6->falselist;
		$$->nextlist.insert($$->nextlist.end(), $13->breaklist.begin(), $13->breaklist.end());
		$13->nextlist.insert($13->nextlist.end(), $13->continuelist.begin(), $13->continuelist.end());
        backpatch($13->nextlist, $8);
		$9->nextlist.insert($9->nextlist.end(), $10->nextlist.begin(), $10->nextlist.end());
        backpatch($9->nextlist, $5);
        emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), $8);
    // }
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
						   | FOR OS ForInit SCLN NEXT_QUAD EXPR_STMT_CODE SCLN CS NEXT_QUAD StmtKind 		{
		vector<treeNode> v;
		add_attribute(v, $3, "", 1);
		add_attribute(v, $6, "", 1);
		add_attribute(v, $10, "", 1);
		$$ = create_AST_node("BasicForStmtNoShortIf5", v);

		if($3->is_error || $6->is_error || $10->is_error)	{
			$$->is_error = 1;
		}

        backpatch($3->nextlist, $5);
        backpatch($6->truelist, $9);
        $$->nextlist = $6->falselist;
		$$->nextlist.insert($$->nextlist.end(), $10->breaklist.begin(), $10->breaklist.end());
        $10->nextlist.insert($10->nextlist.end(), $10->continuelist.begin(), $10->continuelist.end());
        backpatch($10->nextlist, $5);
        emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), $5);
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


EXPR_STMT_CODE
    : {if_found = 1;} Expr { 
		if($2->truelist.empty() && $2->falselist.empty()) {
            int a = code.size();
			backpatch($2->nextlist, a);
            emit(qid("GOTO", NULL),qid("IF", Lookup("if")), $2->place, qid("", NULL ),0);
            int b = code.size();
            emit(qid("GOTO", NULL),qid("", NULL), qid("", NULL), qid("", NULL ),0);
            $2->truelist.push_back(a);
            $2->falselist.push_back(b);
        }
        $$ = $2;
		if_found = 0;
	}
    ;

N
:  {
	int a = code.size();
	$$ = new Node;
	emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
	$$->nextlist.push_back(a);
}
;

ForInit : StmtExprList 	{$$ = $1;}																	
		| LocalVariableDecn 	{$$ = $1;}																	
		;

ForUpdate : StmtExprList 	{$$ = $1;}																
		  ;

StmtExprList : StmtExprList COMMA NEXT_QUAD StmtExpr {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("StmtExprList", attr);

		if(!$1->is_error && !$4->is_error){
			$$->type = $1->type;
			// 3AC 
			backpatch($1->nextlist,$3);
			backpatch($1->truelist,$3);
			backpatch($1->falselist,$3);
			$$->nextlist = $4->nextlist;
			$$->place = $4->place;
		}
		else {
			$$->is_error = 1;
		}

	}								
						| StmtExpr 	{$$ = $1;}														
						;

BreakStmt : BREAK IDENTIFIER SCLN 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, create_AST_leaf($2, ""), "", 1);
		// add_attribute(v, $2, "", 1);
		$$ = create_AST_node("CBreakStmt", v);
		//have not implemented labeled break
	}																									
			   | BREAK SCLN 	{
				   	$$ = create_AST_leaf($1, "BREAK");
					      
					int a = code.size();
					emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
					$$->breaklist.push_back(a);
				}																					
			   ;

ContinueStmt : CONTINUE IDENTIFIER SCLN 	{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, create_AST_leaf($2, ""), "", 1);
		// add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ContinueStmt", v);
		///modify
		int a = code.size();
		emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
		$$->continuelist.push_back(a);

		
	}																	
				  | CONTINUE SCLN		{
					  	$$ = create_AST_leaf($1, "CONTINUE");
						int a = code.size();
						emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
						$$->continuelist.push_back(a);
				}												
				  ;

ReturnStmt : RETURN SCLN 	{
		$$ = create_AST_leaf($1, "RETURN");
	 	emit(qid("RETURN", NULL), qid("", NULL), qid("", NULL), qid("", NULL), -1);
	}																		
				| RETURN Expr SCLN 		{
		vector<treeNode> v;
		add_attribute(v, create_AST_leaf($1, ""), "", 1);
		add_attribute(v, $2, "", 1);
		$$ = create_AST_node("ReturnStmt", v);

			if($2->is_error)	{
			$$->is_error = 1;
		}
		backpatch($2->nextlist,code.size());
        emit(qid("RETURN", NULL), $2->place, qid("", NULL), qid("", NULL), -1);
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
				  | THIS 					{ 

					  		$$ = create_AST_leaf($1, "THIS");
							$$->place= qid(constructor_temporary,NULL);
				}							
				  | Literal 			{$$ = $1;}								
				  | ClassCreation 		{$$ = $1;}						 
				  ;

ClassCreation : NEW ClassType OS ArgLst CS 	{  // TYPECHECK
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("ClassInstCreationExpr1", attr);
// cout<<"NISH3\n";
		if(type == "") type =  $2->type;
		else type += " " + string($1);
		$$->size= 1;
		string temp= $2->type;
		
			// $$->isInit = $3->isInit; // { currArgs.push_back(vector<string>()); }  used in theirs 
			// cout<<"p2 "<<$2->type<<endl;
		// string temp = postfixExpr("FUNC_"+$2->type,3);
			// cout<<"p1 "<<temp<<endl;
		// if(temp.empty()){
		// 	temp = getFuncType($2->temp_name);
		// }
		int fl=0;
		if(!($2->is_error || $4->is_error) && $2->expType!=4 && fl==0){
			// cout<<"ABIHSIHEIH "<<temp<<endl;
			if(!temp.empty()){	
				// cout<<"NISH2\n";
				$$->type = temp;
				if($2->expType ==3){
					// cout<<"NISH2\n";
					vector<string> funcArgs = getFuncArgs($2->temp_name);
					vector<string> tempArgs =currArgs;
					for(int i=0;i<tempArgs.size();i++){
						// cout<<tempArgs[i]<<"F\n";

					}	
					for(int i=0;i<funcArgs.size();i++){
						if(funcArgs[i]=="...")break;
						if(tempArgs.size()==i){
							yyerror(("Too few Arguments to constructor " + $2->temp_name).c_str());
							break;
						}
						string msg = chkType(funcArgs[i],tempArgs[i]);

						if(msg =="warning"){
							warning(("Incompatible conversion of " +  tempArgs[i] + " to parameter of type " + funcArgs[i]).c_str());
						}
						else if(msg.empty()){
							yyerror(("Incompatible Argument to the constructor " + $2->temp_name).c_str());
							$$->is_error = 1;
							break;
						}
						if(i==funcArgs.size()-1 && i<tempArgs.size()-1){
							yyerror(("Too many Arguments to constructor " + $2->temp_name).c_str());
							$$->is_error = 1;
							break;
						}

					}	
					//--3AC
					if(!$$->is_error){
						int _idx = -1;
						// here, emitting a -1: index is set to code.size() here. 
						if($$->type == "char*" && $$->place.second == NULL) _idx = -4;
						emit(qid("param", NULL), $2->place, qid("", NULL), qid("", NULL), _idx);
						// qid q = newtemp($$->type);
						// $$->place = q;
						$$->place= $2->place;
						$$->nextlist.clear();
						// cout<<"name is "<<$2->temp_name<<"\n";
						sym_entry* sym= Lookup($2->temp_name);
						// cout<<"CHECK "<<sym->paramsize<<"\n";
						emit(qid("CALL_constr", NULL), qid($2->temp_name,sym), qid(to_string(currArgs.size()), NULL), qid("",NULL), -1);
						// currArgs.pop_back();
						
						if(func_usage_map.find($2->temp_name) != func_usage_map.end()){
							func_usage_map[$2->temp_name] = 1;
						}
						currArgs.clear();
					}

				}
			}
			else{
				// cout<<"NISH4\n";
				yyerror("Invalid function call");
				$$->is_error=1;
			}
		}
		else{
			// cout<<"NISH5\n";
			if($2->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
			// cout<<"NISH1\n";
		}
			
	}								
								| NEW ClassType OS CS 		{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, $2, "", 1);
		// add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("ClassInstCreationExpr2", attr);
		if(type == "") type = $2->type;
		else type += " " + $2->type;
		$$->size= 1;


		// This is the defualt constructor. Will need to treat this a little differently to a function with no arguments. 
		$$->isInit = 1;
		string temp = postfixExpr($2->type,2);
		cout<<"const "<<temp<<" "<<$2->type<<" "<<className<<endl;
		string blank_s = "";
		currArgs.push_back(blank_s ); 

		if(temp.empty()){
			temp = getFuncType($2->temp_name);
		}

		if(!($2->is_error) && $2->expType!=4){
			if(!temp.empty()){	
				$$->type = temp;
				if($2->expType == 3){
					vector<string> funcArg = getFuncArgs($2->temp_name);
					if(!funcArg.empty()){
						yyerror(("Too few Arguments to constructor " + $2->temp_name).c_str());
					}
					else{

					//--3AC
						// qid q = newtemp(temp);
						$$->nextlist.clear();
						sym_entry* sym=	 Lookup("CLASS_"+$2->temp_name);
						// cout<<"CHECK "<<sym->paramsize<<"\n";
						emit(qid("CALL_constr", NULL), qid($2->temp_name,sym), qid(to_string(currArgs.size()), NULL), qid("",NULL), -1);
						// emit(qid("CALL", NULL),qid($$->temp_name,NULL), qid("0", NULL), q, -1);
						currArgs.pop_back();
						//if(currArgs.size()>1)currArgs.push_back($$->type) ;
						// $$->place = q;
						$$->place= $2->place;

						if(func_usage_map.find($2->temp_name) != func_usage_map.end()){
							func_usage_map[$2->temp_name] = 1;
						}
						currArgs.clear();
					}
				}
			}
			else{
				
				// yyerror(("Constructor " + $2->temp_name + " not declared in this scope").c_str());
				// $$->is_error=1;
				// this means that we are creating an object of a class using a default constructor 
				if(find(classNamelist.begin(), classNamelist.end(), $2->type)!=classNamelist.end())
				{
					// $$->place= qid(sym->place, sym);
					// is_place_set= true;
					// class exists! can create object. 
					//--3AC
						// qid q = newtemp(temp);
						$$->nextlist.clear();
						cout<<"CHECK1 "<<"\n";
						sym_entry* sym=	 Lookup("CLASS_"+$2->temp_name);
						if(sym==nullptr) 	cout<<"CHECK "<<"\n";
					
						emit(qid("CALL_constr", NULL), qid($2->temp_name,sym), qid(to_string(currArgs.size()), NULL), qid("",NULL), -1);
						// emit(qid("CALL", NULL),qid($$->temp_name,NULL), qid("0", NULL), q, -1);
						currArgs.pop_back();
						//if(currArgs.size()>1)currArgs.push_back($$->type) ;
						// $$->place = q;
						$$->place= $2->place;

						if(func_usage_map.find($2->temp_name) != func_usage_map.end()){
							func_usage_map[$2->temp_name] = 1;
						}
						currArgs.clear();
				}
}
		}
		else{
			if($2->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
		}
	}												
								;
/* 				
Alloc: 					{
			cout<<"in alloc "<<type<<endl;
			qid tmp = newtemp(type);
			// cout<<"If found kdhe "<<if_found<<"\n";
			int temp=1;
			// cout<<"SISZEEC "<<$3->dims[0]<<" "<<$3->dims.size()<<endl;
			// cout<<"DA TYPEC IS "<<$2->type<<endl;
			// for(int i=0;i<$3->dims.size();i++)
			// {
			// 	temp*=$3->dims[i];
			// }
			sym_entry* sym= Lookup(className);
			cout<<"Found type is "<<sym->type<<endl;
			if (sym ==nullptr){
				yyerror(("Field size not found in class "+ className).c_str());
			}
			emit(qid("NEW", sym), qid(to_string(sym->fieldsize), NULL), qid("", NULL), tmp, -1);
	}
  */
/* 1,2,3 */
ArgLst : Expr 			{
							$$ = $1;
							if(!$1->is_error){
								//Semantic
								$$->isInit = $1->isInit;
								string temp_s;
								temp_s = $1->type;
								// cout<<"The size of currArgs is "<<currArgs.size()<<endl;
								
								// cout<<$1->int_val<<"\n";
								currArgs.push_back((temp_s));
								// cout<<currArgs[0]<<"C\n";
								// currArgs.push_back($1->type);
								$$->type = "void";

								//--3AC
								$$->nextlist.clear();
								int _idx = -1;
								// here, emitting a -1: index is set to code.size() here. 
								if($$->type == "char*" && $$->place.second == NULL) _idx = -4;
								emit(qid("param", NULL), $$->place, qid("", NULL), qid("", NULL), _idx);
							}
							else{
								$$->is_error = 1;
							}
							$$->nextlist.clear();
							int _idx = -1;
							if($$->type == "char*" && $$->place.second == NULL) _idx = -4;
							// emit(qid("param", NULL), $$->place, qid("", NULL), qid("", NULL), _idx);
						}										
			 | ArgLst COMMA Expr 		{
											vector<treeNode> attr;
											add_attribute(attr, $1, "", 1);
											add_attribute(attr, $3, "", 1);
											$$ = create_AST_node("Arg_list", attr);
											//Semantic
											if(!($1->is_error || $3->is_error)){
												string temp = argExpr($1->type, $3->type, 2);

												if($1->isInit && $3->isInit) $$->isInit=1;
												currArgs.push_back($3->type);
												
												$$->type = "void";

												//--3AC
												$$->nextlist.clear();
												int _idx = -1;
												backpatch($3->nextlist, code.size());
												if($3->type == "char*" && $3->place.second == NULL) _idx = -4;
												emit(qid("param", NULL), $3->place, qid("", NULL), qid("", NULL), _idx);
											}
											else{
												$$->is_error = 1;
											}
								
										}							
			 ;



FieldAccess : Primary FST Identifier	{
		
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		// add_attribute(attr, $3, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("Field access", attr);
		$$->type = $3->type;
		$$->temp_name= $3->temp_name;
		
		// Semantics

		// treats similar to a struct 
		if(!$1->is_error && $1->expType!=4){
			string temp = string($3->temp_name);
			// cout<<"Will call find_table now"<<"\n";
			sym_table* ret = find_table(className);
			if(ret == nullptr){
				yyerror(("Class1 " + $1->name + " not defined").c_str());
				$$->is_error = 1;
			}
			// else{
			// 	cout<<"ret="<<"CLASS_"+$1->type<<endl;
			// 	for(map<string, sym_entry*>::iterator it = ret->begin(); it!=ret->end(); it++){ cout<<it->first<<endl; }
			// }
			sym_entry* r;
			r= find_in_table(temp, ret);
			if (r == nullptr){
				yyerror(("Class1 " + $1->type + " has no field " + string($3->temp_name)).c_str());
				$$->is_error = 1;
			}
			else{
				$$->type = r->type;
				$$->temp_name = $1->temp_name + "." + temp;
				qid temp_var1 = newtemp($$->type);
				emit(qid("=", r), qid(to_string(r->offset),NULL), qid("",NULL), temp_var1, -1);
				qid temp_var = newtemp($$->type);
				// adds a temporary variable(for 3AC) to symbol table. 
				// cout<<"In qual name "<<$1->place.first<<endl;
				sym_entry* attr_sym = retTypeAttrEntry(r);
				emit(qid("qualname", r), $1->place, temp_var1, temp_var, -1);
				temp_var.second->array_dims = attr_sym->array_dims;
				$$->place = temp_var;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error = 1;
		}
		
		// if(!$3->is_error){
		// 	if(CurLookup($3->temp_name) ){
		// 		string errstr = $3->temp_name + " is already declared";
		// 		yyerror(errstr.c_str());
		// 		$$->is_error = 1;
		// 	}
		// 	else if($3->expType == 3){
		// 		if(fn_decl){
		// 			yyerror("A parameter list without types is only allowed in a function definition");
		// 			$$->is_error = 1;

		// 			fn_decl = 0;
		// 		}
		// 		DeleteFunctionPrototype();
		// 		code.pop_back();
		// 	}
		// 	else{
		// 		if(storage_class != "typedef"){
		// 			// cout<<"GG\n";
		// 			// insertSymbol(*curr_table, $3->temp_name, $3->type, $3->size, 0, NULL);
		// 			qid temp= newtemp($3->type);
		// 			sym_entry* sym= Lookup($3->temp_name);
		// 			if(sym==nullptr)
		// 			{
		// 				yyerror(($3->temp_name+ " field access error").c_str());
		// 			}
		// 			emit(qid("=",sym),qid(to_string(sym->offset),NULL),qid("",NULL),temp,-1 );
		// 			// cout<<" RONNIE "<<className<<endl;
		// 			// $$->place = qid($3->temp_name, sym);
		// 			$$->place = qid(className, sym);
		// 			isArray = 0;
		// 		}
		// 		else{
		// 			insertTypedef(*curr_table, $3->temp_name, $3->type, $3->size, 0, NULL);
		// 			$$->place = qid($3->temp_name, Lookup($3->temp_name));
		// 		} 
		// 	}
		// }
		// else $$->is_error = 1;
	}									
			| SUPER FST IDENTIFIER  {
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, "IDENTIFIER"), "", 1);

		add_attribute(attr, create_AST_leaf($3,"IDENTIFIER"), "", 1);
		$$ = create_AST_node("Field access", attr);
	}											
			;
			/* m= 2; 
			int arr[][]= new int[m][n]
			arr[i][j]

			t1 = n*4
			t2 = i*t1
			t3 = m*4
			t4 = t2+t3 */


ArrOp : Name OSQ Expr CSQ 	{
		vector<treeNode> v, v2;
		add_attribute(v2, $3, "", 1);
		Node* node = create_AST_node("[ ]", v2);
		add_attribute(v, $1, "", 1);
		add_attribute(v, node, "", 1);
		$$ = create_AST_node("ArrOp1", v);
		// cout<<"Access tp 2\n";/
		//Semantics
		if($1->isInit && $3->isInit){
			$$->isInit = 1;
		}
		if(!checkArrExpr($3->type)) {
			yyerror(("Array index " + $3->temp_name +  " is not integral").c_str());
		}
		// seems like a check we need to do.
		// why is there no error thrown when both are not initialised? 
		// cout<<"Array 2718 "<<$1->type<<endl;
		string temp = postfixExpr($1->type,1); //the type_name passed to the function is stored in postifix expr
		string base_type= find_base_type($1->type);
		if(!($1->is_error || $3->is_error) && $1->expType!=4){
			if(!temp.empty()){	
				$$->type = temp;

				//--3AC
				qid temp_var1 = newtemp($$->type);
				// emit(qid("*", NULL),$3->place , qid(to_string(GetSize($$->type)),NULL), temp_var1, -1);	
				int t=1;
				arr_index[$1->temp_name]++;
				for(int i=arr_index[$1->temp_name];i<arr_dimensions[$1->temp_name].size();i++)
				{
					t*= arr_dimensions[$1->temp_name][i];
				}
				// cout<<"FIRST DIM "<<$3->int_val<<"\n";
			
					if(($3->int_val!=-1 && arr_dimensions[$1->temp_name][0]!=-1) && $3->int_val>=arr_dimensions[$1->temp_name][0]) {
					yyerror(("Array index3 " + $3->temp_name +  " is out of bound").c_str());
		
				}
					
				emit(qid("*", NULL), $3->place , qid(to_string(t*GetSize(base_type)),NULL), temp_var1, -1);
				//returns the symbol table entry to the temporary variable 
				//array_dims is a vector<int> in sym_entry*
				// $$->place= temp_var1;

				if(arr_index[$1->temp_name]==arr_dimensions[$1->temp_name].size()) 
				{
					qid temp_var = newtemp($$->type); 
					temp_var.second->array_dims = $1->place.second->array_dims;
					if(temp_var.second->array_dims.size()) temp_var.second->array_dims.erase(temp_var.second->array_dims.begin());
					// $$->place = temp_var;
					// emit(qid("[ ]", NULL), $1->place, $3->place, temp_var, -1);	
					// cout<<"Name place is "<<$1->place.first<<"\n";
					sym_entry* sym= Lookup($1->temp_name);
					if(sym==nullptr)
					{
						yyerror(($1->temp_name + ": array not defined").c_str());
					}
					emit(qid("[ ]", sym), $1->place, temp_var1, temp_var, -1);	
					$$->nextlist.clear();
					$$->place= temp_var;
					arr_index[$1->temp_name]=0;
				}
				else
				{
					$$->place= temp_var1;
					$$->nextlist.clear();
					// $$->temp_name= $1->place.first;
					$$->temp_name= $1->temp_name;
				}
			}
			else{
				yyerror(($1->temp_name +  " is not an array").c_str());
				$$->is_error=1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
		}
	}								
			| PrimaryNoNewArr OSQ Expr CSQ	{
		vector<treeNode> v, v2;
		add_attribute(v2, $3, "", 1);
		Node* node = create_AST_node("[ ]", v2);
		add_attribute(v, $1, "", 1);
		add_attribute(v, node, "", 1);
		$$ = create_AST_node("ArrOp2", v);
		$$->temp_name= $1->temp_name;
		$$->type= $1->type;
		// cout<<"Access tp 1\n";
		//Semantics
		// cout<<$1->temp_name<<"\n";
		if($1->isInit && $3->isInit){
			$$->isInit = 1;
		}
		if(!checkArrExpr($3->type)) {
			yyerror(("Array index " + $3->temp_name +  " is not integral").c_str());
		}
		string temp = postfixExpr($1->type,1);
		string base_type= find_base_type($1->type);
		if(!($1->is_error || $3->is_error) && $1->expType!=4){
			if(!temp.empty()){	
				$$->type = temp;
				qid temp_var1 = newtemp($$->type);
				int t=1;
				if(($3->int_val!=-1 && arr_dimensions[$1->temp_name][0]!=-1) && $3->int_val>=arr_dimensions[$1->temp_name][arr_index[$1->temp_name]]) {
			yyerror(("Array index1 " + $3->temp_name +  " is out of bound").c_str());
		}
				arr_index[$1->temp_name]++;
				for(int i=arr_index[$1->temp_name];i<arr_dimensions[$1->temp_name].size();i++)
				{
					t*= arr_dimensions[$1->temp_name][i];
				}
				
				emit(qid("*", NULL), $3->place , qid(to_string(t*GetSize(base_type)),NULL), temp_var1, -1);
				qid temp_var = newtemp($$->type);
				temp_var.second->array_dims = $1->place.second->array_dims;
				if(temp_var.second->array_dims.size()) temp_var.second->array_dims.erase(temp_var.second->array_dims.begin());
				// $$->place = temp_var;
				emit(qid("+", NULL), $1->place, temp_var1, temp_var, -1);	
				$$->nextlist.clear();
				//--3AC
				$$->place= temp_var;
				// cout<<arr_index[$1->temp_name]<<" "<<arr_dimensions[$1->temp_name].size()<<"\n";
				if(arr_index[$1->temp_name]==arr_dimensions[$1->temp_name].size())
				{
					sym_entry* sym= Lookup($1->temp_name);
					if(sym==nullptr)
					{
						yyerror((($1->temp_name + ": Multidim array not defined")).c_str());
					}
					// cout<<"In\n";
					qid temp_var2 = newtemp($$->type);
					temp_var2.second->array_dims = $1->place.second->array_dims;
					if(temp_var2.second->array_dims.size()) temp_var2.second->array_dims.erase(temp_var2.second->array_dims.begin());
					$$->place = temp_var2;
					emit(qid("[ ]", sym),qid(sym->place, NULL), temp_var, temp_var2, -1);	
					$$->nextlist.clear();
					arr_index[$1->temp_name]=0;
				} 
			}
			else{
				yyerror(("Array0 " + $1->temp_name +  " Index out of bound").c_str());
				$$->is_error=1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
		}
			//Semantics
		// if($1->isInit && $3->isInit){
		// 	$$->isInit = 1;
		// }
		// // seems like a check we need to do.
		// // why is there no error thrown when both are not initialised? 
		// string temp = postfixExpr($1->type,1); //the type_name passed to the function is stored in postifix expr
		// if(!checkArrExpr($3->type)) {
		// 	yyerror(("Array index " + $3->temp_name +  " is not integral").c_str());
		// }
		// if(!temp.empty()){
		// 	$$->type = temp;
		// }
		// else{
		// 	// empty is only returned when we encounter an unknown type or some other error. 
		// 	yyerror(("Array " + $1->temp_name +  " Index out of bound1").c_str());
		// }

	}													
			;

MethodInvocation : Name OS ArgLst CS 		{   // TYPECHECK
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("MethodInvocation1", attr);

			//Semantics
		$$->isInit = $3->isInit; // { currArgs.push_back(vector<string>()); }  used in theirs 
		string temp = postfixExpr($1->type,3);
		if(temp.empty()){
			temp = getFuncType($1->temp_name);
		}
		int fl=0;
		if($1->temp_name=="System.out.println")
		{
			fl=1;
			// cout<<"YEA \n";
		}
		if(!($1->is_error || $3->is_error) && $1->expType!=4){
			if(!temp.empty()){	
				$$->type = temp;
				if($1->expType ==3){
					vector<string> funcArgs = getFuncArgs($1->temp_name);
					
					// cout<<endl;
					vector<string> tempArgs =currArgs;
					if(fl==0)
					{
						// cout<<"Function "<<$1->temp_name<<" "<<funcArgs.size()<<" "<<currArgs.size()<<"\n";
						for(int i=0;i<funcArgs.size();i++)
						{
							if(funcArgs[i]=="...")break;
							if(tempArgs.size()==i){
								yyerror(("Too few Arguments to Function " + $1->temp_name).c_str());
								break;
							}
							string msg = chkType(funcArgs[i],tempArgs[i]);

							if(msg =="warning"){
								warning(("Incompatible conversion of " +  tempArgs[i] + " to parameter of type " + funcArgs[i]).c_str());
							}
							else if(msg.empty()){
								yyerror(("Incompatible Argument to the function " + $1->temp_name).c_str());
								$$->is_error = 1;
								break;
							}
							if(i==funcArgs.size()-1 && i<tempArgs.size()-1){
								yyerror(("Too many Arguments to Function " + $1->temp_name).c_str());
								$$->is_error = 1;
								break;
							}

						}	
					}
					
					//--3AC
					if(!$$->is_error){
						qid q = newtemp($$->type);
						$$->place = q;
						
						$$->nextlist.clear();
						// cout<<"name is "<<$1->temp_name<<"\n";
						sym_entry* sym= Lookup($1->temp_name);
						cout<<"CHECK "<<sym->paramsize<<"\n";
						if(sym==nullptr) cout<<"NULL\n";
						if($1->temp_name== "System.out.println") $1->temp_name= "print";
						emit(qid("CALL", NULL), qid($1->temp_name,sym), qid(to_string(currArgs.size()), NULL), q, -1);
						// currArgs.pop_back();
						currArgs.clear();

						if(func_usage_map.find($1->temp_name) != func_usage_map.end()){
							func_usage_map[$1->temp_name] = 1;
						}
					}

				}
			}
			else{
				yyerror("Invalid function call");
				$$->is_error=1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
		}
	}						
				 | Name OS CS 	{ 
					 
					 $$= $1;  //done
					//Semantics
		$$->isInit = 1;
		string temp = postfixExpr($1->type,2);
		string blank_s = "";
		currArgs.push_back(blank_s ); 

		if(temp.empty()){
			temp = getFuncType($1->temp_name);
		}

		if(!($1->is_error) && $1->expType!=4){
			if(!temp.empty()){	
				$$->type = temp;
				if($1->expType == 3){
					vector<string> funcArg = getFuncArgs($1->temp_name);
					if(!funcArg.empty()){
						yyerror(("Too few Arguments to Function " + $1->temp_name).c_str());
					}
					else{

					//--3AC
						qid q = newtemp(temp);
						$$->nextlist.clear();
						sym_entry* sym= Lookup($1->temp_name);
						//cout<<"CHECK "<<sym->paramsize<<"\n";
						if($1->temp_name== "System.out.println") $1->temp_name= "print";
						emit(qid("CALL", NULL), qid($1->temp_name,sym), qid(to_string(currArgs.size()), NULL), q, -1);
						// emit(qid("CALL", NULL),qid($$->temp_name,NULL), qid("0", NULL), q, -1);
						// currArgs.pop_back();
						currArgs.clear();
						//if(currArgs.size()>1)currArgs.push_back($$->type) ;
						$$->place = q;

						if(func_usage_map.find($1->temp_name) != func_usage_map.end()){
							func_usage_map[$1->temp_name] = 1;
						}
					}
				}
			}
			else{
				yyerror(("Function " + $1->temp_name + " not declared in this scope").c_str());
				$$->is_error=1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
		}

				 		}										
				 | Primary FST IDENTIFIER OS ArgLst CS 	
				 {
		vector<treeNode> v, v2;
		add_attribute(v2, $1, "", 1);
		add_attribute(v2, create_AST_leaf($3,"IDENTIFIER"), "", 1);
		Node* node = create_AST_node($2, v2);
		add_attribute(v, node, "", 1);
		add_attribute(v, $5, "", 1);
		$$ = create_AST_node("MethodInvocation2", v);
		//Semantics
		
		if(!$1->is_error && $1->expType!=4){
			string temp = string($3);
			sym_table* ret = find_table("CLASS_"+$1->type);
			if(ret == nullptr){
				yyerror(("Class " + $1->name + " not defined").c_str());
				$$->is_error = 1;
			}
			sym_entry* r;
			r= find_in_table(temp, ret);
			if (r == nullptr){
				yyerror(("Class " + $1->type + " has no field " + string($3)).c_str());
				$$->is_error = 1;
			}
			else{
				$$->type = r->type;
				$$->temp_name = $1->temp_name + "." + temp;
				
				qid temp_var = newtemp($$->type);
				sym_entry* attr_sym = retTypeAttrEntry(r);
				emit(qid("member_access", NULL), $1->place, qid(string($3), attr_sym), temp_var, -1);
				temp_var.second->array_dims = attr_sym->array_dims;
				$$->place = temp_var;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error = 1;
		}
		$$->isInit = $5->isInit;
		string temp = postfixExpr($1->type,3);
		if(temp.empty()){
			temp = getFuncType($1->temp_name);
		}

		if(!($1->is_error || $5->is_error) && $1->expType!=4){
			if(!temp.empty()){	
				$$->type = temp;
				if($1->expType ==3){
					vector<string> funcArgs = getFuncArgs($1->temp_name);
					vector<string> tempArgs =currArgs;
					for(int i=0;i<funcArgs.size();i++){
						if(funcArgs[i]=="...")break;
						if(tempArgs.size()==i){
							yyerror(("Too few Arguments to Function " + $1->temp_name).c_str());
							break;
						}
						string msg = chkType(funcArgs[i],tempArgs[i]);

						if(msg =="warning"){
							warning(("Incompatible conversion of " +  tempArgs[i] + " to parameter of type " + funcArgs[i]).c_str());
						}
						else if(msg.empty()){
							yyerror(("Incompatible Argument to the function " + $1->temp_name).c_str());
							$$->is_error = 1;
							break;
						}
						if(i==funcArgs.size()-1 && i<tempArgs.size()-1){
							yyerror(("Too many Arguments to Function " + $1->temp_name).c_str());
							$$->is_error = 1;
							break;
						}

					}	

					//--3AC
					if(!$$->is_error){
						qid q = newtemp($$->type);
						$$->place = q;
						$$->nextlist.clear();

						emit(qid("CALL", NULL), qid($1->temp_name,NULL), qid(to_string(currArgs.size()), NULL), q, -1);
						// currArgs.pop_back();

						currArgs.clear();
						if(func_usage_map.find($1->temp_name) != func_usage_map.end()){
							func_usage_map[$1->temp_name] = 1;
						}
					}

				}
			}
			else{
				yyerror("Invalid function call");
				$$->is_error=1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
		}

	}								
				 | Primary FST IDENTIFIER OS CS 		{
		
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, create_AST_leaf($2, ""), "", 1);
		add_attribute(attr, create_AST_leaf($3, "IDENTIFIER"), "", 1);
		$$ = create_AST_node("MethodInvocation3", attr);
		//Semantics

		if(!$1->is_error && $1->expType!=4){
			string temp = string($3);
			sym_table* ret = find_table("CLASS_"+$1->type);
			if(ret == nullptr){
				yyerror(("Class " + $1->name + " not defined").c_str());
				$$->is_error = 1;
			}
			sym_entry* r;
			r= find_in_table(temp, ret);
			if (r == nullptr){
				yyerror(("Class " + $1->type + " has no field " + string($3)).c_str());
				$$->is_error = 1;
			}
			else{
				$$->type = r->type;
				$$->temp_name = $1->temp_name + "." + temp;
				
				qid temp_var = newtemp($$->type);
				sym_entry* attr_sym = retTypeAttrEntry(r);
				emit(qid("member_access", NULL), $1->place, qid(string($3), attr_sym), temp_var, -1);
				temp_var.second->array_dims = attr_sym->array_dims;
				$$->place = temp_var;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error = 1;
		}
		$$->isInit = 1;
		string temp = postfixExpr($1->type,2);
		// blank_s = {};
		currArgs.push_back(""); 

		if(temp.empty()){
			temp = getFuncType($1->temp_name);
		}

		if(!($1->is_error) && $1->expType!=4){
			if(!temp.empty()){	
				$$->type = temp;
				if($1->expType == 3){
					vector<string> funcArg = getFuncArgs($1->temp_name);
					if(!funcArg.empty()){
						yyerror(("Too few Arguments to Function " + $1->temp_name).c_str());
					}
					else{

					//--3AC
						qid q = newtemp(temp);
						$$->nextlist.clear();

						emit(qid("CALL", NULL),qid($$->temp_name,NULL), qid("0", NULL), q, -1);
						// currArgs.pop_back();
						currArgs.clear();
						//if(currArgs.size()>1)currArgs.push_back($$->type) ;
						$$->place = q;

						if(func_usage_map.find($1->temp_name) != func_usage_map.end()){
							func_usage_map[$1->temp_name] = 1;
						}
					}
				}
			}
			else{
				yyerror(("Function " + $1->temp_name + " not declared in this scope").c_str());
				$$->is_error=1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error=1;
		}

		
	}						
				 | SUPER FST Identifier OS ArgLst CS   {
		
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, create_AST_leaf($2, ""), "", 1);
		add_attribute(attr, $3, "", 1);
		add_attribute(attr, $5, "", 1);
		$$ = create_AST_node("MethodInvocation4", attr);
	}					
				 | SUPER FST Identifier OS CS  		{
		vector<treeNode> attr;
		add_attribute(attr, create_AST_leaf($1, ""), "", 1);
		add_attribute(attr, create_AST_leaf($2, ""), "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("MethodInvocation5", attr);
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
		$$->dims= $3->dims;
		//cout<<"NEW "<<$3->dims.size()<<" "<<$3->dims[0]<<"\n";

		qid tmp = newtemp($$->type);
		qid tmp1 = newtemp($$->type);
		// cout<<"If found kdhe "<<if_found<<"\n";
		int temp=1;
		//cout<<"SISZEE "<<$3->dims[0]<<" "<<$3->dims.size()<<endl;
		//cout<<"DA TYPE IS "<<$2->type<<endl;
		for(int i=0;i<$3->dims.size();i++)
		{
			temp*=$3->dims[i];
		}
		// emit(qid("NEW", NULL), qid(to_string(temp*GetSize($2->type)), NULL), qid("", NULL), tmp, -1);
			emit(qid("NEW", NULL), qid(to_string(temp*GetSize($2->type)), NULL), tmp1, tmp, -1);	
		$$->place= tmp1;
		// emit(qid("NEW", NULL), qid(to_string(temp*GetSize($2->type)), NULL), qid("", NULL), qid("", NULL), -1);
		// $$->place = tmp;

		// $$= $3;
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
			$$->dims= $1->dims;	
			$$->dims.push_back($2->int_val);
			// cout<<"INTVAL "<<$2->int_val;
		}																		
		 | DimExpr 			{	$$ = $1;
								vector<int> temp;
								temp.push_back($1->int_val);
								cout<<"INTVAL "<<$1->int_val;
							 	$$->dims= temp;
							 }												
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

Expr : AssignExpr 	{$$ = $1; 	}									 		
		   ;

AssignExpr  :  ConditionExpr 			{$$ = $1;}							
					  |  Assign {$$ = $1;}										
					  ;

Assign  :  LeftHandSide AssignOp {if_found = 0;} Expr 	{
							vector<treeNode> attr;
							add_attribute(attr, $1, "", 1);
							add_attribute(attr, $4, "", 1);
							$$ = create_AST_node($2,attr);
							// cout<<"Assign Expression "<<$1->temp_name<<" "<<$1->type<<" "<<string($2)<<" "<<$4->temp_name<<" "<<$4->type<<"\n";

							//Semantics
		string temp = asgnExpr($1->type,$4->type,string($2));

		if(!$1->is_error && !$4->is_error && $1->expType!=4){
			if(!temp.empty()){
				if(temp =="ok"){
					$$->type = $1->type;
				}
				else if(temp == "warning"){
				$$->type = $1->type;
				yyerror("Assignment with incompatible pointer types: maybe passed lesser dimensions to array");
			} 
				if($1->expType == 3 && $4->isInit){
					UpdateInit($1->temp_name);
				}
				// cout<<"Type of first arg "<<$1->type<<"\n";
				// 3ac 
				int num;
				// if($1->place.first.substr(0,5)=="CLASS")
				// {
				// 	emit(qid("",NULL),qid("",NULL),qid("",NULL),qid("",NULL),-1);
				// } 
				
				// else  
				// {
					num = assign_exp($2, $$->type, $1->type, $4->type, $1->place, $4->place);
				// }
				$$->place = $1->place;
				backpatch($4->nextlist, num);
			}
			else{
				yyerror(("Incompatible types when assigning " + $4->type + " type to " + $1->type).c_str());
				$$->is_error = 1;
			}
		}
		else{
			if($1->expType==4){
				yyerror("Left operand in assignment operation cannot be a constant expression");
			}
			$$->is_error = 1;
		}
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
					  | GOTO_COND NEXT_QUAD Expr WRITE_GOTO COLON NEXT_QUAD ConditionExpr 	{
											vector<treeNode> attr;
											add_attribute(attr, $1, "", 1);
											add_attribute(attr, $3, "", 1);
											add_attribute(attr, $7, "", 1);
											$$ = create_AST_node("ternary operator",attr);
										    // Semantics
											// string temp = condExp($3->type, $5->type);
											//if (!temp.empty()){
												//$ $->type = "int";
											//}
// 											//else {
												 //yyerror("Type mismatch in Conditional Expression");
											// }
// 											if// ($1->isInit==1 && $3->isInit==1 && $5->isInit==1) $$->isInit=1;
	
											string temp = condExp($3->type, $7->type);

											if(!$1->is_error && !$3->is_error && !$7->is_error){
												if(!temp.empty()){

													if_found = previous_if_found;
													$$->type = string("int");
													if($1->int_val) $$->int_val = $3->int_val;
													else $$->int_val = $7->int_val;
													if($1->isInit==1 && $3->isInit==1 && $7->isInit==1) $$->isInit=1;

													// 3AC
													qid temp1 = newtemp($$->type);

													backpatch($1->truelist, $2);
													backpatch($1->falselist, $6);
													backpatch($3->nextlist, $4-1);
													backpatch($3->truelist, $4-1);
													backpatch($3->falselist, $4-1);

													code[$4-1].arg1 = $3->place;
													code[$4-1].res = temp1;

													backpatch($7->nextlist, code.size());
													backpatch($7->falselist, code.size());
													backpatch($7->truelist, code.size());

													emit(qid("=", NULL), $7->place, qid("", NULL), temp1, -1);
													$$->nextlist.push_back($4);
													$$->place = temp1;
												}
												else {
													yyerror("type mismatch in conditional expression");
													$$->is_error = 1;
												}
											}									
										}
					  ;

GOTO_COND
	: ConditionOrExpr QUESTION_MARK {
		previous_if_found = if_found;
		if_found = 0;
		$$ = $1;
		if(!$1->is_error){
			if($1->truelist.empty()){
				backpatch($1->nextlist, code.size());
				emit(qid("GOTO", NULL), qid("IF", Lookup("if")), $1->place, qid("", NULL), 0);
				$1->truelist.push_back(code.size()-1);
				emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
				$1->falselist.push_back(code.size()-1);
			}
		}
		else $$->is_error = 1;
	}
	;

WRITE_GOTO
	: {
		emit(qid("=", NULL), qid("", NULL), qid("", NULL), qid("", NULL), -1);
		emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
		$$ = code.size()-1;
	}
	;

ConditionOrExpr : ConditionAndExpr 	{$$ = $1;}										
						| GOTO_OR NEXT_QUAD ConditionAndExpr {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("||" ,attr);

		// Semantics

		if(!$1->is_error && !$3->is_error){
			$$->type = string("int");
			$$->isInit = (($1->isInit) & ($3->isInit));   
			$$->int_val = $1->int_val || $3->int_val;

			// 3AC
			if($3->truelist.empty() && if_found){
				// cout<<"If found "<<if_found<<"\n";

				backpatch($3->nextlist, code.size());
				emit(qid("GOTO", NULL), qid("IF", Lookup("if")), $3->place, qid("", NULL), 0);
				$3->truelist.push_back(code.size()-1);
				emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
				$3->falselist.push_back(code.size()-1);
			}
			else {
				qid tmp = newtemp($$->type);
				// cout<<"If found kdhe "<<if_found<<"\n";
				emit(qid("||", NULL), $1->place, $3->place, tmp, -1);
				$$->place = tmp;
			}
			backpatch($1->falselist, $2);
			$$->truelist = $1->truelist;
			$$->truelist.insert($$->truelist.end(), $3->truelist.begin(), $3->truelist.end());
			$$->falselist = $3->falselist;
		}
		else{
			$$->is_error = 1;
		}
	} 						
						;

GOTO_OR
	: ConditionOrExpr OR {
		$$ = $1;
		if(!$1->is_error){
			if($1->truelist.empty() && if_found){
				backpatch($1->nextlist, code.size());
				emit(qid("GOTO", NULL), qid("IF", Lookup("if")), $1->place, qid("", NULL), 0);
				$1->truelist.push_back(code.size()-1);
				emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
				$1->falselist.push_back(code.size()-1);
			}
		}
		else $$->is_error = 1;
		
	}
	;

ConditionAndExpr : InclusiveOrExpr		{$$ = $1;}									
						 | GOTO_AND NEXT_QUAD InclusiveOrExpr  {
		vector<treeNode> attr;
		add_attribute(attr, $1, "", 1);
		add_attribute(attr, $3, "", 1);
		$$ = create_AST_node("&&" ,attr);
		// cout<<"In and rule \n";
		// Semantics
		if(!$1->is_error && !$3->is_error){
			$$->type = string("int");
			$$->isInit = (($1->isInit) & ($3->isInit));   
			$$->int_val = $1->int_val && $3->int_val;

			// 3AC
			if($3->truelist.empty() && if_found){
				// cout<<"If found "<<if_found<<"\n";
				backpatch($3->nextlist, code.size());
				// cout<<"In and rule1 \n";
				emit(qid("GOTO", NULL), qid("IF", Lookup("if")), $3->place, qid("", NULL), 0);
				$3->truelist.push_back(code.size()-1);
				emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
				$3->falselist.push_back(code.size()-1);
			}
			else {
				qid tmp = newtemp($$->type);
				// cout<<"In and rule2 \n";
				emit(qid("&&", NULL), $1->place, $3->place, tmp, -1);
				$$->place = tmp;
			}
			backpatch($1->truelist, $2);
			$$->truelist = $3->truelist;
			$$->falselist = $1->falselist;
			$$->falselist.insert($$->falselist.end(), $3->falselist.begin(), $3->falselist.end());
		}
		else{
			$$->is_error = 1;
		}

	} 						
						 ;

GOTO_AND
	: ConditionAndExpr AND {
		$$ = $1;
		
		if(!$1->is_error){
			if($1->truelist.empty() && if_found){
				backpatch($1->nextlist, code.size());
				emit(qid("GOTO", NULL), qid("IF", Lookup("if")), $1->place, qid("", NULL), 0);
				$1->truelist.push_back(code.size()-1);
				emit(qid("GOTO", NULL), qid("", NULL), qid("", NULL), qid("", NULL), 0);
				$1->falselist.push_back(code.size()-1);
			}
		}
		else $$->is_error = 1;
	}
	;

NEXT_QUAD
	: {
		$$ = code.size();
	}
	;

InclusiveOrExpr : ExclusiveOrExpr	{$$ = $1;}							
					  | InclusiveOrExpr BINARYOR ExclusiveOrExpr  {
																	vector<treeNode> attr;
																	add_attribute(attr, $1, "", 1);
																	add_attribute(attr, $3, "", 1);
																	$$ = create_AST_node($2 ,attr);
																	//Semantics
																// if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
																
															
																	// if(!temp.empty()){
																	// 	if(temp =="ok"){
																	// 		$$->type = "bool";
																	// 	}
																	// 	else $$->type = "long long";
																		
																	// }
																	// else{
																	// 	yyerror("Invalid operands to binary |");
																	// }
																	if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
																	// else if($1->isInit == 0){
																	// 	yyerror(($1->name + " is not initialized\n").c_str());
																	// 	$$->is_error = 1;
																	// }
																	// else {
																	// 	yyerror(($3->name + " is not initialized\n").c_str());
																	// 	$$->is_error = 1;
																	// }
																	string temp = bitExpr($1->type,$3->type);

																	if(!$1->is_error && !$3->is_error){
																		if(!temp.empty()){
																			if(temp =="ok"){
																				$$->type = "bool";
																			}
																			else $$->type = "long long";
																			
																			$$->int_val = $1->int_val | $3->int_val;

																			// 3AC
																			if($1->expType == 4 && $3->expType == 4){
																				$$->place = qid(to_string($$->int_val), $1->place.second);
																				$$->expType = 4;
																			}
																			else{
																				qid temp1 = newtemp($$->type);
																				emit(qid("|", NULL), $1->place, $3->place, temp1, -1);
																				$$->place = temp1;
																			}
																			$$->nextlist.clear();
																		}
																		else{
																			yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary |").c_str());
																			$$->is_error = 1;
																		}
																	}
																	else{
																		$$->is_error = 1;
																	}
																} 			
					  ;

ExclusiveOrExpr : AndExpr 		{$$ = $1;}								
					  | ExclusiveOrExpr POW AndExpr 	 {
															vector<treeNode> attr;
															add_attribute(attr, $1, "", 1);
															add_attribute(attr, $3, "", 1);
															$$ = create_AST_node($2 ,attr);

															//Semantics
														     
															if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
															
															string temp = bitExpr($1->type,$3->type);

															if(!$1->is_error && !$3->is_error){
																if(!temp.empty()){
																	if(temp =="ok"){
																		$$->type = "bool";
																	}
																	else $$->type = "long long";

																	$$->int_val = $1->int_val ^ $3->int_val;

																	// 3AC
																	if($1->expType == 4 && $3->expType == 4){
																		$$->place = qid(to_string($$->int_val), $1->place.second);
																		$$->expType = 4;
																	}
																	else{
																		qid temp1 = newtemp($$->type);
																		emit(qid("^", NULL), $1->place, $3->place, temp1, -1);
																		$$->place = temp1; 
																	}
																	$$->nextlist.clear();
																}
																else{
																	yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary ^").c_str());
																	$$->is_error = 1;
																}
															}
															else{
																$$->is_error = 1;
															}
														} 				
					  ;	   

AndExpr : EqExpr			{$$ = $1;}								
			  | AndExpr BINARYAND EqExpr	 {
												vector<treeNode> attr;
												add_attribute(attr, $1, "", 1);
												add_attribute(attr, $3, "", 1);
												$$ = create_AST_node($2 ,attr);
												//Semantics
											
												if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
											
												string temp = bitExpr($1->type,$3->type);

												if(!$1->is_error && !$3->is_error){
													if(!temp.empty()){
														if(temp =="ok"){
															$$->type = "bool";
														}
														else $$->type = "long long";
														
														$$->int_val = $1->int_val & $3->int_val;

														// 3AC
														if($1->expType == 4 && $3->expType == 4){
															$$->place = qid(to_string($$->int_val), $1->place.second);
															$$->expType = 4;
														}
														else{
															qid temp1 = newtemp($$->type);
															emit(qid("&", NULL), $1->place, $3->place, temp1, -1);
															$$->place = temp1;
														}
														$$->nextlist.clear();
													}
													else{
														yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary &").c_str());
														$$->is_error = 1;
													}
												}
												else{
													$$->is_error = 1;
												}
											} 							
			  ;
			  
EqExpr : RtlExpr 	{$$ = $1;}								
				   | EqExpr EQEQ RtlExpr    {
												vector<treeNode> attr;
												add_attribute(attr, $1, "", 1);
												add_attribute(attr, $3, "", 1);
												$$ = create_AST_node($2 ,attr);
												//Semantics
												
												if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
												// else if($1->isInit == 0){
												
												string temp = eqlExpr($1->type,$3->type);

												if(!$1->is_error && !$3->is_error){
													if(!temp.empty()){
														if(temp =="ok"){
															warning("Comparison between pointer and integer");
														}
														$$->type = "bool";

														if($1->int_val == $3->int_val) $$->int_val = 1;
														else $$->int_val = 0;

														// 3AC
														if($1->expType == 4 && $3->expType == 4){
															$$->place = qid(to_string($$->int_val), $1->place.second);
															$$->expType = 4;
														}
														else{
															qid temp1 = newtemp($$->type);
															emit(qid("==", NULL), $1->place, $3->place, temp1, -1);
															$$->place = temp1;
														}
														$$->nextlist.clear();
													}
													else{
														yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary ==").c_str());
														$$->is_error = 1;
													}
												}
												else{
													$$->is_error = 1;
												}
											} 		
				   | EqExpr NEQUALS RtlExpr 	 {
													vector<treeNode> attr;
													add_attribute(attr, $1, "", 1);
													add_attribute(attr, $3, "", 1);
													$$ = create_AST_node($2 ,attr);
													//Semantics
											
													if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
												
													string temp = eqlExpr($1->type,$3->type);

													if(!$1->is_error && !$3->is_error){
														if(!temp.empty()){
															if(temp =="ok"){
																//warning("Comparison between pointer and integer");
															}
															$$->type = "int";

															if($1->int_val != $3->int_val) $$->int_val = 1;
															else $$->int_val = 0;

															// 3AC
															if($1->expType == 4 && $3->expType == 4){
																$$->place = qid(to_string($$->int_val), $1->place.second);
																$$->expType = 4;
															}
															else{
																qid temp1 = newtemp($$->type);
																emit(qid("!=", NULL), $1->place, $3->place, temp1, -1);
																$$->place = temp1; 
															}
															$$->nextlist.clear();
														}
														else{
															yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary !=").c_str());
															$$->is_error = 1;
														}
													}
													else{
														$$->is_error = 1;
													}
												}		
				   ;

RtlExpr : ShiftExpr		{$$ = $1; }	
                     					 | RtlExpr GREQ ShiftExpr 	{
																		vector<treeNode> attr;
																		add_attribute(attr, $1, "", 1);
																		add_attribute(attr, $3, "", 1);
																		$$ = create_AST_node($2 ,attr);

																		//Semantic
																if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
															
																		string temp = relExpr($1->type,$3->type);

																		if(!$1->is_error && !$3->is_error){
																			if(!temp.empty()){
																				if(temp == "bool"){
																					$$->type = "bool";
																				}
																				else if(temp == "Bool"){
																					$$->type = "bool";
																					//warning("Comparison between pointer and integer");
																				}
																				if($1->int_val >= $3->int_val) $$->int_val = 1;
																				else $$->int_val = 0;

																				// 3AC
																				if($1->expType == 4 && $3->expType == 4){
																					$$->place = qid(to_string($$->int_val), $1->place.second);
																					$$->expType = 4;
																				}
																				else{
																					qid temp1 = newtemp($$->type);
																					emit(qid(">=", NULL), $1->place, $3->place, temp1, -1);
																					$$->place = temp1;
																				}
																				$$->nextlist.clear();
																				
																			}
																			else{
																				yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary >=").c_str());
																				$$->is_error = 1;
																			}
																		}
																		else{
																			$$->is_error = 1;
																		}
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
														//Semantic
												        
														if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
														
														string temp = relExpr($1->type,$3->type);

														if(!$1->is_error && !$3->is_error){
															if(!temp.empty()){
																if(temp == "bool"){
																	$$->type = "bool";
																}
																else if(temp == "Bool"){
																	$$->type = "bool";
																	warning("Comparison between pointer and integer");
																}

																if($1->int_val < $3->int_val) $$->int_val = 1;
																else $$->int_val = 0;

																// 3AC
																if($1->expType == 4 && $3->expType == 4){
																	$$->place = qid(to_string($$->int_val), $1->place.second);
																	$$->expType = 4;
																}
																else{
																	qid temp1 = newtemp($$->type);
																	emit(qid("<", NULL), $1->place, $3->place, temp1, -1);
																	$$->place = temp1; 
																}
																$$->nextlist.clear();
																
															}
															else{
																yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary <").c_str());
																$$->is_error = 1;
															}
														}
														else{
															$$->is_error = 1;
														}
													}		
					 | RtlExpr GT ShiftExpr 		{
														vector<treeNode> attr;
														add_attribute(attr, $1, "", 1);
														add_attribute(attr, $3, "", 1);
														$$ = create_AST_node($2 ,attr);
														

														//Semantic
														
														if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
														// else if($1->isInit == 0){
														// 	yyerror(($1->name + " is not initialized\n").c_str());
														// 	$$->is_error = 1;
														// }
														// else {
														// 	yyerror(($3->name + " is not initialized\n").c_str());
														// 	$$->is_error = 1;
														// }
														string temp = relExpr($1->type,$3->type);

														if(!$1->is_error && !$3->is_error){
															if(!temp.empty()){
																if(temp == "bool"){
																	$$->type = "bool";
																}
																else if(temp == "Bool"){
																	$$->type = "bool";
																	warning("Comparison between pointer and integer");
																}

																if($1->int_val > $3->int_val) $$->int_val = 1;
																else $$->int_val = 0;
																// 3AC
																if($1->expType == 4 && $3->expType == 4){
																	$$->place = qid(to_string($$->int_val), $1->place.second);
																	$$->expType = 4;
																}
																else{
																	qid temp1 = newtemp($$->type);
																	emit(qid(">", NULL), $1->place, $3->place, temp1, -1);
																	$$->place = temp1; 
																}
																$$->nextlist.clear();
															}
															else{
																yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary >").c_str());
																$$->is_error = 1;
															}
														}
														else{
															$$->is_error = 1;
														}
													}					
					 | RtlExpr LEQ ShiftExpr 	{
													vector<treeNode> attr;
													add_attribute(attr, $1, "", 1);
													add_attribute(attr, $3, "", 1);
													$$ = create_AST_node($2 ,attr);
													//Semantic
												
												
													if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
													
													string temp = relExpr($1->type,$3->type);

													if(!$1->is_error && !$3->is_error){
														if(!temp.empty()){
															if(temp == "bool"){
																$$->type = "int";
															}
															else if(temp == "Bool"){
																$$->type = "int";
																//warning("Comparison between pointer and integer");
															}
															if($1->int_val <= $3->int_val) $$->int_val = 1;
															else $$->int_val = 0;

															// 3AC
															if($1->expType == 4 && $3->expType == 4){
																$$->place = qid(to_string($$->int_val), $1->place.second);
																$$->expType = 4;
															}
															else{
																qid temp1 = newtemp($$->type);
																emit(qid("<=", NULL), $1->place, $3->place, temp1, -1);
																$$->place = temp1; 
															}
															$$->nextlist.clear();
														}
														else{
															yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary <=").c_str());
															$$->is_error = 1;
														}
													}
													else{
														$$->is_error = 1;
													}
												}					
			
					 ;

ShiftExpr : AddExpr 		{$$ = $1;}								
				| ShiftExpr LTLT AddExpr 	{
												vector<treeNode> attr;
												add_attribute(attr, $1, "", 1);
												add_attribute(attr, $3, "", 1);
												$$ = create_AST_node($2 ,attr);
												//Semantic
												if(!$1->is_error && !$3->is_error){
												
																if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
																// else if($1->isInit == 0){
																// 	yyerror(($1->name + " is not initialized\n").c_str());
																// 	$$->is_error = 1;
																// }
																// else {
																// 	yyerror(($3->name + " is not initialized\n").c_str());
																// 	$$->is_error = 1;
																// }
													string temp = shiftExpr($1->type,$3->type);
													if(!temp.empty()){
														$$->type = $1->type;
														$$->int_val = $1->int_val << $3->int_val;
														$$->temp_name = $1->temp_name + " << " + $3->temp_name;

														// 3AC
														if($1->expType == 4 && $3->expType == 4){
															$$->place = qid(to_string($$->int_val), $1->place.second);
															$$->expType = 4;
														}
														else{
															qid temp1 = newtemp($$->type);
															emit(qid("<<", NULL), $1->place, $3->place, temp1, -1);
															$$->place = temp1;
														}
														$$->nextlist.clear();
													}
													else{
														yyerror(("Invalid operands of types \'" + $1->type + "\' and \'" + $3->type + "\' to binary <<").c_str());
														$$->is_error = 1;
													}
												}
												else{
													$$->is_error = 1;
												}
											}				
				
				;

AddExpr : MultExpr 		{$$ = $1;}						
				   | AddExpr ADD MultExpr {
											vector<treeNode> attr;
											add_attribute(attr, $1, "", 1);
											add_attribute(attr, $3, "", 1);
											$$ = create_AST_node($2 ,attr);
											//Semantic
											
																if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
																// else if($1->isInit == 0){
																// 	yyerror(($1->name + " is not initialized\n").c_str());
																// 	$$->is_error = 1;
																// }
																// else {
																// 	yyerror(($3->name + " is not initialized\n").c_str());
																// 	$$->is_error = 1;
																// }
											$$->int_val = $1->int_val + $3->int_val;
											string temp = addExpr($1->type,$3->type,'+');
											
											if(!$1->is_error && !$3->is_error){
												if(!temp.empty()){
													if(temp == "int")	$$->type = "int";
													else if(temp == "real")	$$->type = "float";
													else $$->type =  temp;

													$$->int_val = $1->int_val + $3->int_val;
													$$->real_val = $1->real_val + $3->real_val;
													$$->temp_name = $1->temp_name + " + " + $3->temp_name;

													// 3AC

													if($1->expType == 4 && $3->expType == 4){
														$$->place = qid(to_string($$->int_val), $1->place.second);
														$$->expType = 4;
													}
													else{
														qid temp1 = newtemp($$->type);
														int cond1 = (checkIfInteger($1->type) && checkIfFloatingPt($3->type));
														int cond2 = (checkIfInteger($3->type) && checkIfFloatingPt($1->type));

														if(cond1){
															qid temp2 = newtemp($3->type);
															emit(qid("inttoreal", NULL), $1->place, qid("", NULL), temp2, -1);
															emit(qid("+"+temp, NULL), temp2, $3->place, temp1, -1);
														}
														else if(cond2){
															qid temp2 = newtemp($1->type);
															emit(qid("inttoreal", NULL), $3->place, qid("", NULL), temp2, -1);
															emit(qid("+"+temp, NULL), $1->place, temp2, temp1, -1);
														}
														else{
															emit(qid("+"+temp, NULL), $1->place, $3->place, temp1, -1);
														}
														$$->place = temp1;
													}
													$$->nextlist.clear();
												}
												else{
													
													yyerror(("Incompatible types \'" + $1->type + "\' and \'" + $3->type + "\' for + operator").c_str());
													// $$->is_error = 1;
												}
											}
											else{
												$$->is_error = 1;
											}
										}		
				   | AddExpr SUBTRACT MultExpr  {
													vector<treeNode> attr;
													add_attribute(attr, $1, "", 1);
													add_attribute(attr, $3, "", 1);
													$$ = create_AST_node($2 ,attr);
													// //Semantic
																if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
																// else if($1->isInit == 0){
																// 	yyerror(($1->name + " is not initialized\n").c_str());
																// 	$$->is_error = 1;
																// }
																// else {
																// 	yyerror(($3->name + " is not initialized\n").c_str());
																// 	$$->is_error = 1;
																// }
                                                    $$->int_val = $1->int_val - $3->int_val;
													string temp = addExpr($1->type,$3->type,'-');
													if(!$1->is_error && !$3->is_error){
														if(!temp.empty()){
															if(temp == "int")$$->type = "int";
															else if(temp == "real")$$->type = "float";
															else $$->type = temp;

															$$->int_val = $1->int_val - $3->int_val;
															$$->real_val = $1->real_val - $3->real_val;
															$$->temp_name = $1->temp_name + " - " + $3->temp_name;

															// 3AC

															if($1->expType == 4 && $3->expType == 4){
																$$->place = qid(to_string($$->int_val), $1->place.second);
																$$->expType = 4;
															}
															else{
																qid temp1 = newtemp($$->type);
																int cond1 = (checkIfInteger($1->type) && checkIfFloatingPt($3->type));
																int cond2 = (checkIfInteger($3->type) && checkIfFloatingPt($1->type));

																if(cond1){
																	qid temp2 = newtemp($3->type);
																	emit(qid("inttoreal", NULL), $1->place, qid("", NULL), temp2, -1);
																	emit(qid("-"+temp, NULL), temp2, $3->place, temp1, -1);
																}
																else if(cond2){
																	qid temp2 = newtemp($1->type);
																	emit(qid("inttoreal", NULL), $3->place, qid("", NULL), temp2, -1);
																	emit(qid("-"+temp, NULL), $1->place, temp2, temp1, -1);
																}
																else{
																	emit(qid("-"+temp, NULL), $1->place, $3->place, temp1, -1);
																}
																$$->place = temp1;
															}
															$$->nextlist.clear();
															
														}
														else{
															yyerror(("Incompatible types \'" + $1->type + "\' and \'" + $3->type + "\' for - operator").c_str());
															$$->is_error = 1;
														}
													}
													else{
														$$->is_error = 1;
													}
												}				
				   ;

MultExpr : UnaryExpr 			{$$ = $1;}						
						 | MultExpr MULTIPLY UnaryExpr {
															vector<treeNode> attr;
															add_attribute(attr, $1, "", 1);
															add_attribute(attr, $3, "", 1);
															$$ = create_AST_node($2 ,attr);

															if(!($1->is_error || $3->is_error)){
															// 	//Semantic
																$$->int_val = $1->int_val * $3->int_val; 

																if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
															
																string temp = multExpr($1->type, $3->type, '*');
		// cout<<"Temp is "<<temp<<"\n";
																if(!temp.empty()){
																	$$->type = temp;
																	if($1->expType == 4 && $3->expType == 4){
																		$$->place = qid(to_string($$->int_val), $1->place.second);
																		$$->expType = 4;
																	}
																	else{
																		if(temp == "int"){
																			$$->type = "int" ;

																			//--3AC
																			qid q = newtemp("int");
																			$$->place = q;
																			$$->nextlist.clear();
																			emit(qid("*int", NULL), $1->place, $3->place, q, -1);
																		}
																		else if(temp == "float"){
																			$$->type = "float";

																			//--3AC

																			qid q = newtemp("float");
																			$$->place = q;
																			$$->nextlist.clear();

																			if(checkIfInteger($1->type)){
																				qid q1 = newtemp($$->type);
																				emit(qid("inttoreal", NULL), $1->place, qid("", NULL), q1, -1);

																				emit(qid("*real", NULL), q1, $3->place, q, -1);
																			}
																			else if(checkIfInteger($3->type)){
																				qid q1 = newtemp($$->type);
																				emit(qid("inttoreal", NULL), $3->place, qid("", NULL), q1, -1);
																				emit(qid("*real", NULL), $1->place, q1, q, -1);
																			}
																			else{
																				emit(qid("*real", NULL), $1->place, $3->place, q, -1);
																			}
																		}
																	}
																	$$->nextlist.clear();
																}
																else{
																	yyerror(("Incompatible types \'" + $1->type + "\' and \'" + $3->type + "\' for * operator").c_str());
																	$$->is_error = 1;
																}
															}
															else{
																$$->is_error = 1;
															}
														}	
						 | MultExpr DIVISION UnaryExpr  {
															vector<treeNode> attr;
															add_attribute(attr, $1, "", 1);
															add_attribute(attr, $3, "", 1);
															$$ = create_AST_node($2 ,attr);
															if(!($1->is_error || $3->is_error)){
																//Semantic
																if($3->int_val!=0)$$->int_val = $1->int_val / $3->int_val;
															
																if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
															
																string temp =multExpr($1->type,$3->type,'/');
																if(!temp.empty()){
																	$$->type = temp;

																	if($1->expType == 4 && $3->expType == 4){
																		$$->place = qid(to_string($$->int_val), $1->place.second);
																		$$->expType = 4;
																	}
																	else{
																		if(temp == "int"){
																			$$->type = "int" ;

																			//--3AC
																			qid q = newtemp("int");
																			$$->place = q;
																			$$->nextlist.clear();
																			emit(qid("/int", NULL), $1->place, $3->place, q, -1);
																		}
																		else if(temp == "float"){
																			$$->type = "float";

															// 				//--3AC
																			qid q = newtemp("float");
																			$$->place = q;
																			$$->nextlist.clear();
																			if(checkIfInteger($1->type)){
																				qid q1 = newtemp($$->type);
																				emit(qid("inttoreal", NULL), $1->place, qid("", NULL), q1, -1);

																				emit(qid("/real", NULL), q1, $3->place, q, -1);
																			}
																			else if(checkIfInteger($3->type)){
																				qid q1 = newtemp($$->type);
																				emit(qid("inttoreal", NULL), $3->place, qid("", NULL), q1, -1);

																				emit(qid("/real", NULL), $1->place, q1, q, -1);
																			}
																			else{
																				emit(qid("/real", NULL), $1->place, $3->place, q, -1);
																			}
																		}
																	}
																	$$->nextlist.clear();
																}
																else{
																	yyerror(("Incompatible types \'" + $1->type + "\' and \'" + $3->type + "\' for / operator").c_str());
																	$$->is_error = 1;
																}
																}
															else{
																$$->is_error = 1;
															}
														}		
						 | MultExpr MOD UnaryExpr  {
														vector<treeNode> attr;
														add_attribute(attr, $1, "", 1);
														add_attribute(attr, $3, "", 1);
														$$ = create_AST_node($2 ,attr);
														if(!($1->is_error || $3->is_error)){
															//Semantic
															    if($1->isInit ==1 && $3->isInit ==1) $$->isInit = 1;
																
															if($3->int_val!=0)$$->int_val = $1->int_val % $3->int_val;
															string temp =multExpr($1->type,$3->type,'%');
															if(temp == "int"){
																$$->type = "int" ;

																//--3AC
																if($1->expType == 4 && $3->expType == 4){
																	$$->place = qid(to_string($$->int_val), $1->place.second);
																	$$->expType = 4;
																}
																else{
																	qid q = newtemp("int");
																	$$->place = q;
																	emit(qid("%", NULL), $1->place, $3->place, q, -1);
																}
																$$->nextlist.clear();

															}
															else{
																yyerror(("Incompatible types \'" + $1->type + "\' and \'" + $3->type + "\' for % operator").c_str());
																$$->is_error = 1;
															}
														}
														else{
															$$->is_error = 1;
														}
													}		
						 ;

UnaryExpr : PreIncExpr 	{$$ = $1;}								
				| PreDecExpr 		{$$ = $1;}							
				| ADD UnaryExpr 					{
														vector<treeNode> attr;
														add_attribute(attr, create_AST_leaf($1, ""), "", 1);
														add_attribute(attr, $2, "", 1);
														$$ = create_AST_node("unary_exp_plus",attr);
														$$->place = qid("unary+", Lookup("+"));
													}									
				| SUBTRACT UnaryExpr  			{
													vector<treeNode> attr;
													add_attribute(attr, create_AST_leaf($1, ""), "", 1);
													add_attribute(attr, $2, "", 1);
													$$ = create_AST_node("unary_exp_minus",attr);
													$$->place = qid("unary-", Lookup("-"));
												}														
				| UnaryExprExtra 		{$$ = $1; 
											// cout<<"unary "<<$1->dims.size()<<"\n";
												
												
												}						
				| TILDA UnaryExpr 	{
										vector<treeNode> attr;
										add_attribute(attr, create_AST_leaf($1, ""), "", 1);
										add_attribute(attr, $2, "", 1);
										$$ = create_AST_node("unary_exp_tilde",attr);
										$$->place = qid("~", Lookup("~"));
									}							
				| NT UnaryExpr {
									vector<treeNode> attr;
									add_attribute(attr, create_AST_leaf($1, ""), "", 1);
									add_attribute(attr, create_AST_leaf($1, "NOT"), "", 1);
									$$ = create_AST_node("unary_exp_not",attr);
									$$->place = qid("unary!", Lookup("!"));
								
								}							
				;


PreIncExpr : PLUSPLUS UnaryExpr {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node($1,attr);
		//Semantic
		
		if(!$2->is_error && $2->expType!=4){
			$$->isInit = $2->isInit;
			string temp = postfixExpr($2->type,6);
			
			if(!temp.empty()){
				$$->type = temp;
				$$->int_val = $2->int_val +1;

				//--3AC
				qid q = newtemp(temp);
				$$->place = q;
				$$->nextlist.clear();
				emit(qid("++P", NULL), $2->place, qid("", NULL), q, -1);
			}
			else{
				yyerror("Increment not defined for this type");
				$$->is_error = 1;
			}
		}
		else{
			if($2->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error = 1;
		}
	}				    	
					   ;

PreDecExpr : MINUSMINUS UnaryExpr {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		$$ = create_AST_node($1,attr);
		//Semantic
		if(!$2->is_error && $2->expType!=4){
			$$->isInit = $2->isInit;
			string temp = postfixExpr($2->type,7);
			if(!temp.empty()){
				$$->type = temp;
				$$->int_val = $2->int_val -1;

				//--3AC
				qid q = newtemp(temp);
				$$->place = q;
				$$->nextlist.clear();
				emit(qid("--P", NULL), $2->place, qid("", NULL), q, -1);
			}
			else{
				yyerror("Decrement not defined for this type");
			}
		}
		else{
			if($2->expType==4){
				yyerror("constant expression cannot be used as lvalue");
			}
			$$->is_error = 1;
		}
	}								
					   ;

UnaryExprExtra : PostfixExpr 		{$$ = $1;}					
							| CastExpr 			{
													$$ = $1;
												}					
							;

PostfixExpr : Primary 			{$$ = $1;}									
                  | Name 				{$$ = $1;}											
                  | PostIncrementExpr 		{$$ = $1;}						
                  | PostDecrementExpr			{$$ = $1;}						
                  ;

PostIncrementExpr : PostfixExpr PLUSPLUS 	{  // TYPECHECK
						vector<treeNode> attr;
						add_attribute(attr, $1, "", 1);
						$$ = create_AST_node($2, attr);
						//Semantics
						$$->isInit = $1->isInit;
						if(!$1->is_error && $1->expType!=4){
							string temp = postfixExpr($1->type,6);
							if(!temp.empty()){
								$$->type = temp;
								$$->int_val = $1->int_val + 1; // increment value 

						 		//--3AC

						 		qid q = newtemp(temp);
						 		$$->place = q;
						 		$$->nextlist.clear();
						 		emit(qid("++S", NULL), $1->place, qid("", NULL), q, -1);
						 	}
							else{
								yyerror("Increment not defined for this type");
								$$->is_error = 1;
							}
						}
						else{
							if($1->expType==4){
								yyerror("constant expression cannot be used as lvalue");
							}

							$$->is_error = 1;
						}
				};

PostDecrementExpr : PostfixExpr MINUSMINUS { // TYPECHECK
						vector<treeNode> attr;
						add_attribute(attr, $1, "", 1);
						$$ = create_AST_node($2, attr);
						//Semantics
						if(!$1->is_error && $1->expType!=4){
							$$->isInit = $1->isInit;
							string temp = postfixExpr($1->type,7);
							if(!temp.empty()){
								$$->type = temp;
								$$->int_val = $1->int_val - 1; // decrement value 

								//--3AC

								qid q = newtemp(temp);
								$$->place = q;
								$$->nextlist.clear();
								emit(qid("--S", NULL), $1->place, qid("", NULL), q, -1);

							}
							else{
								yyerror("Decrement not defined for this type");
								$$->is_error = 1;
							}
						}
						else{
							if($1->expType==4){
								yyerror("constant expression cannot be used as lvalue");
							}
							$$->is_error = 1;
						}
				};							
						

CastExpr : OS PrimitiveType Dims CS UnaryExpr { // TYPECASTING	
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $3, "", 1);
		add_attribute(attr, $5, "", 1);
		$$ = create_AST_node("cast_Expr1" ,attr);
		
		// $$->type = $2->type;
		// $$->isInit = $5->isInit;
		if(!($2->is_error || $5->is_error)){
			//Semantic
			$$->type = $2->type;
			$$->isInit = $5->isInit;

			//--3AC
			// qid q = newtemp($$->type);
			$$->place = $5->place;
			$$->place.second->type = $2->type;
			$5->nextlist.clear();
			// cout<<"In cast\n";
		}
		else{
			// cout<<"NOT IN cast\n";
			$$->is_error = 1;
		}
	}
	;		
			   | OS PrimitiveType CS UnaryExpr 	{
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $4, "", 1);
		$$ = create_AST_node("cast_Expr3" ,attr);

		// $$->type = $2->type;
		// $$->isInit = $4->isInit;
		if(!($2->is_error || $4->is_error)){
			//Semantic
			$$->type = $2->type;
			$$->isInit = $4->isInit;
			// cout<<"In castExpr"<<endl;

			//--3AC
			// qid q = newtemp($$->type);
			$$->place = $4->place;
			$$->place.second->type = $2->type;
			$4->nextlist.clear();
		}
		else{
			$$->is_error = 1;
		}
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
			   | OS Name Dims CS UnaryExprExtra {
		vector<treeNode> attr;
		add_attribute(attr, $2, "", 1);
		add_attribute(attr, $3, "", 1);
		add_attribute(attr, $5, "", 1);
		$$ = create_AST_node("cast_Expr4" ,attr);
		
		// $$->type = $2->type;
		// $$->isInit = $5->isInit;
		if(!($2->is_error || $5->is_error)){
			//Semantic
			$$->type = $2->type;
			$$->isInit = $5->isInit;

			//--3AC
			// qid q = newtemp($$->type);
			$$->place = $5->place;
			$$->place.second->type = $2->type;
			$5->nextlist.clear();
		}
		else{
			$$->is_error = 1;
		}
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
	char* input_java_file = "../tests/test0.java";
	char* file_name = "asm.s";
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
	InitSymbolTable();
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
	InitSymbolTable();
	yyparse();
	printSymbolTable(&gst, "#Global_Symbol_Table#.csv");
	fprintf(dotfile, "}\n"); 	// Dot file has been completely written to 
	fclose(dotfile);
	if(!interrupt_compiler){
		code_file.open(file_name);
		setGlobal();
		print3AC_code();
		/* gen_start(); */
		genCode();
		printSymbolTable(&gst, "#Global_Symbol_Table#.csv");
	}
	return 0;
}


void print_warning(){
	cout<<"\033[1;36mWarning: \033[0m";
}

int warning(const char* s) { 
	FILE *dupfile = fopen(curr_file, "r");
	int count = 1;

	char currline[512]; /* or other suitable maximum line size */
	while (fgets(currline, sizeof(currline), dupfile) != NULL) {
		if (count == yylineno){
			cout<<curr_file<<":"<<yylineno<<":"<<column+1-strlen(yytext)<<":: "<<currline;
			print_warning();
			cout<<s<<"\n\n";
			return -1;
		}
		else{
			count++;
		}
	}

	fclose(dupfile);
	return 1;
}



int yyerror(const char *s) { 
	interrupt_compiler = 1;
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

