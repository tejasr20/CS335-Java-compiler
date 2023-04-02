#pragma once

#include <bits/stdc++.h>
#include<iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include<map>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define sym_file 0
#define sym_function 1
#define sym_block 2

struct sym_entry{
	string type;
	ull size;
	bool init;
	ull offset;
	map<string, sym_entry* > * entry;
	struct desc { 
		string reg;
		bool stack;
		bool heap;
	} addr_descriptor;
	int function_offset = 0;
	int heap_mem = 0;
	int next_use = -1;
	int is_derefer = 0;
	int isArray = 0;
	int size_of_pointed = 0;
	int is_global = 0;
	// vector<int> modifiers;
	int paramsize=0;
	int funcsize=0;
	vector<int> array_dims;
	string storage_class;
	bool is_static= false;
};

typedef struct sym_entry sym_entry;
typedef map<string, sym_entry* > sym_table; 
typedef map<string, pair< ull, sym_table* > > struct_sym_table;
typedef map<string, string> typ_table;

extern sym_table gst;
extern struct_sym_table struct_gst;
extern map<sym_table*, sym_table*> parent_table;
extern map<struct_sym_table*, struct_sym_table*> struct_parent_table;

extern map<string, ull> struct_size;
extern map<string, pair< string,vector<string> > > func_arg;
extern ull struct_offset;
extern sym_table* curr_table;
extern sym_table* curr_structure;
extern struct_sym_table *curr_struct_table;
extern stack<ull> Goffset, Loffset, blockSz;
extern int fl;
extern typ_table typ_gst;  
extern map<typ_table*, typ_table*> typ_parent_table;
extern typ_table* curr_typ;
extern map<sym_table*, string> table_names;
extern int classnum;
extern map <string, int> integer_types;
extern map <string, int> float_types;

extern vector<int> array_dims;
extern map<string, int> func_usage_map;
extern int dump_sym_table;


void InitSymbolTable();
sym_entry* find_in_table(string id, sym_table* tab);
sym_table* find_table(string id);
sym_entry* AddEntry(string type, ull size, bool init, ull offset);
void CreateSymbolTable(string name, string type, bool isFun, int offset_flag);
void InsertPreDefFucn(string func_name, vector<string> type, string ret_type);
void DeleteFunctionPrototype();
void SymbolTableUpdation(string id,  int offset_flag);
sym_entry* Lookup(string id);
sym_entry* CurLookup(string id);
void insertFuncArg(string &func, vector<string> &arg, string &tp);
string getFuncType(string id);
sym_entry* retTypeAttrEntry(sym_entry* t1);
void KeywordInsertion();
string FindType(string id);
void CreateStructTable();
void clear_paramoffset();
int AddStructAttr(string attr, string type, ull size, bool init);
int ShowStructTable(string struct_name);
string StructAttrType(string struct_name, string id);
int findStruct(string struct_name);
int lookupStruct(string struct_name, string id);
void CreateParameterList();
void CreateDummyClass();
void insertSymbol(sym_table& table, string id, string type, ull size, bool is_init, sym_table* ptr);
void insertTypedef(sym_table& table, string id, string type, int size, bool is_init, sym_table* ptr);
vector<string> getFuncArgs(string id);
void UpdateInit(string id);
void UpdateTableSize(string id);
void AddFunctionArguments(string &func, vector<string> &arg, string &tp);
void ShowFunctionArguments();
void printSymbolTable(sym_table* table, string file_name);
ull GetSize(string id);
string LookupType(string a);
void AddType(string a, string b);
string funcProtoLookup(string id);
void paramInsert(sym_table& table, string id, string type, int size, bool is_init, sym_table* ptr);