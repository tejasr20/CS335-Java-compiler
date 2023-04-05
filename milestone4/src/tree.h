#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "3ac.h"
using namespace std;
typedef long unsigned int lu;
typedef long long ll;
typedef long double ld;


typedef struct{
	lu id;
	string name;
	// char char_val;
	// symbol table additions
	ll size;
	string type;
	int isInit;
	ll int_val= -1;
	ld real_val;
	string str_val;
	vector<int> dims;
	int is_error = 0;
	int expType=0;	// 1 -> Variable, 2 -> Array, 3-> Function, 4 -> Constant, 5 -> string  	
	
	string temp_name;
	qid place;
	vector<int> truelist;
	vector<int> falselist;
	vector<int> breaklist;
	vector<int> continuelist;
	vector<int> nextlist;
	vector<int> caselist;
	//to be used later in semantic analysis 
}Node;


typedef struct{
	string str;
	string type;
	ll int_val;
	ld real_val;
	string str_val;
	int isInit;
}constants;



typedef struct{
	Node* node;
	bool is_node;
	string s;
}treeNode;


vector<treeNode> create_vector();
void add_attribute(vector<treeNode>&, Node* , string , int );
Node *create_AST_leaf(string, string);
Node *create_AST_node(string , vector<treeNode>&);
