
#include "symbol_table.h"

sym_table gst;
struct_sym_table struct_gst;
map<sym_table*, sym_table*> parent_table;
map<struct_sym_table*, struct_sym_table*> struct_parent_table;

map<string, ull> struct_size;
map<string, pair< string,vector<string> > > func_arg;
ull struct_offset;
sym_table* curr_table;
sym_table* curr_structure;
struct_sym_table *curr_struct_table;
stack<ull> Goffset, Loffset, blockSz;

typ_table typ_gst;  
map<typ_table*, typ_table*> typ_parent_table;
typ_table* curr_typ;

int max_size = 0;
extern int param_offset = -4;

extern int isArray;
extern vector<int> array_dims;
extern map<string, int> func_usage_map;
extern int dump_sym_table;


map<sym_table*, string> table_names;
int classnum=1;


int struct_count = 1;
int cl=0;
int fl=0;
int num=1;
string name1= "Global Symbol Table";
int blockCnt = 1;
map <string, int> integer_types={  {"char",1}, {"short",2}, {"int",4}, {"byte",1}, {"long",8}};
map <string, int> float_types={  {"float",4}, {"double",8}};


void InitSymbolTable(){
	Goffset.push(0);
	Loffset.push(0);
	blockSz.push(0);
	table_names[&gst]= name1;
	// table_names.insert(make_pair(gst,name1 ));
	parent_table.insert(make_pair(&gst, nullptr));
	struct_parent_table.insert(make_pair(&struct_gst, nullptr));
	curr_table = &gst;
	curr_struct_table = &struct_gst;
	curr_typ = &typ_gst;
	KeywordInsertion();
}

sym_entry* AddEntry(string type, ull size, bool init, ull offset, sym_table* ptr){
	sym_entry* new_sym = new sym_entry();
	new_sym->type = type;
	new_sym->size = size;
	new_sym->init = init;
	new_sym->offset = offset;
	new_sym->entry = ptr;
	return new_sym;
}


void CreateSymbolTable(string name, string type, bool isFun, int offset_flag){
	int b;
	string s,s1, s2 ;
	s= type;
	if(isFun)
	{
		//  cout<<"Function table created.\n";
		 b= fl;
		 s1= "FUNC_";
		 s2="dummyF_name";
	}
	else 
	{
		b= cl; // cl is always zero so for a block, it will always behave correctly. 
		s1= "CLASS_";
		s2= "dummyC_name";
	}
	if(!b){
		sym_table* new_table = new sym_table;
		struct_sym_table* new_struct_table = new struct_sym_table;
		typ_table* new_typ = new typ_table;
		if(type!= "") insertSymbol(*curr_table, name , s1 + s , 0 , 1, new_table);
		// if type="" then we are creating a symbol table for a nested scope("Block")
		// within a class or function. 
		else{
			insertSymbol(*curr_table, name , "Block",0,1, new_table);
			blockCnt++; // used to count number of blocks, till it is reset. 
		}
		
		Goffset.push(0); // Table to be changed, so update the new offsets from 0. 
		if(offset_flag) 
		{
			blockSz.push(0);
		}
		parent_table.insert(make_pair(new_table, curr_table));
		struct_parent_table.insert(make_pair(new_struct_table, curr_struct_table));
		typ_parent_table.insert(make_pair(new_typ, curr_typ));

		curr_table = new_table;
		curr_struct_table = new_struct_table;
		curr_typ = new_typ;
		table_names[curr_table]= s2;
	}
	else{
		// b = 0;
		if(isFun) fl=0;
		else cl=0;
		table_names[curr_table]= name;
		(*parent_table[curr_table]).erase(s2);
		(*parent_table[curr_table]).insert(make_pair(name,AddEntry(s1+s,0,1,Loffset.top(), NULL)));
		Loffset.pop();
	}
}

void DeleteFunctionPrototype(){
	fl = 0;
	param_offset=-4;
	SymbolTableUpdation("dummyF_name", 1);
	parent_table.erase((*curr_table)["dummyF_name"]->entry);
	(*curr_table).erase("dummyF_name");
	Loffset.pop();
}


void printSymbolTable(sym_table* table, string file_name){
	FILE* file = fopen(file_name.c_str(), "w");
	// cout<<"Printing table "<<file_name<<"\n";
  	fprintf( file,"Name, Type, Size, isInitialized, Offset\n");
  	for(auto it: (*table)){
    	fprintf(file,"%s,%s,", it.first.c_str(), it.second->type.c_str());
		fprintf(file, "%lld,%d,%lld\n", (it.second)->size, (it.second)->init, (it.second)->offset);
  }
  fclose(file);
}


void SymbolTableUpdation(string id,  int offset_flag){
	ull temp = Goffset.top();
	Goffset.pop();
	Goffset.top()+=temp;

	curr_table = parent_table[curr_table];
	curr_struct_table = struct_parent_table[curr_struct_table];
	curr_typ = typ_parent_table[curr_typ];

	// now Lookup in parent table, if found add entry size. 
	sym_entry* entry = Lookup(id);
	if(entry) 
	{
		entry->size = blockSz.top();
		cout<<"Function locals and temporaries size is "<<entry->size<<endl;
		entry->funcsize= entry->size;
	}

	if(offset_flag){
		// cout<<id<<" Updation\n";
		// new block?
		temp = blockSz.top();
		blockSz.pop();
		blockSz.top()+=temp;
	}
}

sym_entry* Lookup(string id){
	sym_table* temp = curr_table;
	while(temp){
		if((*temp).find(id)!=(*temp).end()) 
		{
			return (*temp)[id]; // returns a symbol table entry 
		}
		temp = parent_table[temp];
	}
	return nullptr; // returns nullptr if the element is not present in the symbol table 
}

sym_entry* find_in_table(string id, sym_table* tab)
{
	sym_table* temp = tab;
	while(temp){
		if((*temp).find(id)!=(*temp).end()) 
		{
			return (*temp)[id]; // returns a symbol table entry 
		}
		temp = parent_table[temp];
	}
	return nullptr; //
}



sym_table* find_table(string id){
	sym_table* temp = curr_table;
	while(temp){
		if((*temp).find(id)!=(*temp).end()) 
		{
			return temp; // where to search 
		}
		temp = parent_table[temp];
	}
	return nullptr; // returns nullptr if the element is not present in the symbol table 
}

sym_entry* CurLookup(string id){
	if((*curr_table).find(id)==(*curr_table).end()) return nullptr;
	return (*curr_table)[id];
}

void KeywordInsertion(){
	vector<string> key_words = {"super","byte","case","catch","implements","import","instanceof","int","char","class","const","continue","switch","synchronized","this","throw","throws","transient","try","interface","abstract","assert","boolean","break","for","if","goto","private","protected","public","return","short","static","strictfp","long","native","new","default","do","double","else","enum","extends","final","finally","float","package","void","volatile","while"}; 
	vector<string> op = {"...",">>=","<<=","+=","-=","*=","/=","%=","&=","^=","|=",">>","<<",">>>","++","--","->","&&","||","<=",">=","==","!=",";","{","<%","}","%>",",",":","=","(",")","[","<:","]",":>",".","&","!","~","-","+","*","/","%","<",">","^","|","?"};

	for(auto h:key_words){
		insertSymbol(*curr_table, h, "keyword", 8, 1, nullptr);
	}
	for(auto h:op){
		insertSymbol(*curr_table, h, "operator", 8, 1, nullptr);
	}

	vector<string> type = {"void*"};
	InsertPreDefFucn("System.out.println", type, "int");
	InsertPreDefFucn("System.err.println", type, "int");
	InsertPreDefFucn("System.in.read", type, "int");

}

void InsertPreDefFucn(string func_name, vector<string> type, string ret_type){
	insertSymbol(*curr_table, func_name, "FUNC_"+ret_type, 4, 0, nullptr);
	func_arg.insert({func_name, make_pair("FUNC_"+ret_type, type)});
	func_usage_map.insert({func_name, 0});
}

string FindType(string id){
	sym_entry* entry = Lookup(id);
	string ret = "";
	if(entry) ret += entry->type;
	
	return ret;
}


void CreateStructTable(){
	sym_table* new_table = new sym_table;
	curr_structure = new_table;
	struct_offset = 0;
}

// insert struct attributes in struct tsymbol table
int AddStructAttr(string attr, string type, ull size, bool init){  
	if((*curr_structure).find(attr)==(*curr_structure).end()){
		blockSz.top()+=size;
		Goffset.top()+=size;
		(*curr_structure).insert(make_pair(attr,AddEntry(type,size,init, struct_offset, nullptr)));
		struct_offset += size;
		return 1;
	}
	return 0;
}

int ShowStructTable(string struct_name){
	if((*curr_struct_table).find(struct_name)==(*curr_struct_table).end()){
		(*curr_struct_table).insert(make_pair(struct_name, make_pair(struct_offset,curr_structure)));
		printSymbolTable(curr_structure, struct_name+ "_" + to_string(struct_count)+".csv");  // prints structure symbol table
		struct_count++;
		return 1;
	}
	return 0;
}

string StructAttrType(string struct_name, string id){
	struct_sym_table* temp = curr_struct_table;
	while((*temp).find(struct_name) == (*temp).end()){
		temp = struct_parent_table[temp];
	}

	sym_table* table = (*temp)[struct_name].second;

	return ((*table)[id]->type);
}

int findStruct(string struct_name){

	struct_sym_table* temp = curr_struct_table;

	while(temp){
		if((*temp).find(struct_name)!=(*temp).end()) return 1;
		temp = struct_parent_table[temp];
	}
	return 0;

}

int lookupStruct(string struct_name, string id){

	struct_sym_table* temp = curr_struct_table;

	while(temp){
		if((*temp).find(struct_name)!=(*temp).end()){
			if((*((*temp)[struct_name].second)).find(id)!=(*((*temp)[struct_name].second)).end()) return 1;//found
			else return 0;
		}
		temp = struct_parent_table[temp];
	}
	return -1;// struct table not found
	
}

ull getStructsize(string struct_name){
	struct_sym_table* temp = curr_struct_table;

	while(temp){
		if((*temp).find(struct_name)!=(*temp).end()){
			return (*temp)[struct_name].first;
		}
		temp = struct_parent_table[temp];
	}
	return 0;
}

void CreateParameterList(){
	cout<<"GoFFSET "<<Goffset.top()<<endl;
	Loffset.push(Goffset.top());
	CreateSymbolTable("dummyF_name", "", 1,1);
	fl = 1; 
}

// void CreateDummyClass(){
// 	Loffset.push(Goffset.top());
// 	CreateSymbolTable("dummyC_name"+to_string(classnum), "", 0, 1);
// 	cl = 1; 
// }

void insertSymbol(sym_table& table, string id, string type, ull size, bool is_init, sym_table* ptr){
	table.insert(make_pair(id, AddEntry(type, size, is_init, Goffset.top(), ptr)));
	blockSz.top()+=size;
	Goffset.top()+=size;
}

vector<string> getFuncArgs(string id){
	vector<string> temp;
	temp.push_back("#NO_FUNC");
	if(func_arg.find(id) != func_arg.end()) return func_arg[id].second;
	else return temp;
}

void UpdateInit(string id){
	sym_entry* entry = Lookup(id);
	if(entry) entry->init = true;
}

void updTableSize(string id){
	sym_entry* entry = Lookup(id);
	if(entry) entry->size = blockSz.top();
}

void AddFunctionArguments(string &func, vector<string> &arg, string &tp){
	func_arg.insert(make_pair(func,  make_pair(string("FUNC_" +tp),arg)));
}

void AddType(string a, string b){
	if((*curr_typ).find(b)==(*curr_typ).end()){
		(*curr_typ).insert(make_pair(a,b));
	}
	else{
		(*curr_typ).insert(make_pair(a, (*curr_typ)[b]));
	}
}

string LookupType(string a){
	typ_table* temp = curr_typ;

	while(temp){
		if((*temp).find(a)==(*temp).end()) return (*temp)[a];
		temp = typ_parent_table[temp];
	}

	return "";
}

// update the argument list and return type of a function
void insertFuncArg(string &func, vector<string> &arg, string &tp){
	func_arg.insert(make_pair(func, make_pair(string("FUNC_" +tp),arg)));
}

// return the return type of the required function
string getFuncType(string id){
	if(func_arg.find(id) != func_arg.end()) return func_arg[id].first;
	return "";
}


sym_entry* retTypeAttrEntry(sym_entry* t1){
	sym_entry* t = new sym_entry;
	t=t1;
	t->next_use = -1;
	t->heap_mem = 0;
	t->is_derefer = 0;
	return t;
}

void clear_paramoffset()
{
	param_offset = -4;
}

// public static $1->type "public static"
// insert function parameters into the symbol table of the function
void paramInsert(sym_table& table, string id, string type, int size, bool is_init, sym_table* ptr){
	table.insert(make_pair(id, AddEntry(type, size, is_init, param_offset-size, ptr)));
	cout<<id<<" "<<param_offset-size<<"\n";
	if(type[type.length()-1] == '*' && !array_dims.empty()){
		size = 4;
		vector<int> temp;
		int curr = 1;
		for(int i = array_dims.size()-1; i>=1; i--){
			curr*=array_dims[i];
			temp.push_back(curr);
		}
		reverse(temp.begin(), temp.end());
		table[id]->array_dims = temp;
		table[id]->offset = param_offset - size;
		array_dims.clear();
	}
	param_offset-=size;
}

void insertTypedef(sym_table& table, string id, string type, int size, bool is_init, sym_table* ptr){
	table.insert(make_pair(id, AddEntry(type, size, is_init, blockSz.top(), ptr)));
	if(type[type.length()-1] == '*' && !array_dims.empty()){
		vector<int> temp;
		int curr = 1;
		for(int i = array_dims.size()-1; i>=1; i--){
			curr*=array_dims[i];
			temp.push_back(curr);
		}
		reverse(temp.begin(), temp.end());
		table[id]->array_dims = temp;
		array_dims.clear();
	}
	table[id]->storage_class = "typedef";
	blockSz.top()+=size;
	Goffset.top()+=size;
}

ull GetSize(string id){
	if(integer_types.find(id)!=integer_types.end())
	{
		return integer_types[id];
	}
	if(id=="bool") return 4;
  return 8;
}



// sym_entry* retTypeAttrEntry(sym_entry* t1){
// 	// struct_sym_table* temp = curr_struct_table;
// 	// while((*temp).find(struct_name) == (*temp).end()){
// 	// 	temp = struct_parent_table[temp];
// 	// }
// 	// sym_table* table = (*temp)[struct_name].second;
// 	// sym_entry* struct_entry = Lookup(struct_var);
// 	// t->type = ((*table)[id])->type;
// 	// t->size = ((*table)[id])->size;
// 	// t->offset = ((*table)[id])->offset;
// 	// t->isArray = ((*table)[id])->isArray;
// 	// t->array_dims = ((*table)[id])->array_dims;
// 	// t->addr_descriptor = ((*table)[id])->addr_descriptor;
// 	sym_entry* t = new sym_entry;
// 	t=t1;
// 	t->next_use = -1;
// 	t->heap_mem = 0;
// 	t->is_derefer = 0;
// 	return t;
// }
