#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long unsigned int lu;
typedef long long ll;

typedef struct{
	lu id; // id is used to print out in dot file 
	string name;
	string str_val;
	char char_val;
	ll int_val;
	ll real_val;
	//to be used later in semantic analysis 
}Node;

typedef struct{
	Node* node;
	bool is_node;
	string s;
}treeNode;


vector<treeNode> create_vector();
void add_attribute(vector<treeNode>&, Node* , string , int );
Node *create_AST_leaf(string, string);
Node *create_AST_node(string , vector<treeNode>&);
