#include "tree.h"

extern FILE *dotfile;
lu counter = 0; //counts number of nodes and is used to build .dot file 

vector<treeNode> createVector(){
	vector<treeNode> v;
	return v;
}

void add_attribute(vector<treeNode> &v, Node* n, string s, int flag){
	treeNode d;
	d.node = n; // may be NULL 
	d.is_node = flag;
	d.s = s;
	v.push_back(d);
}


Node *create_AST_node(string s, vector<treeNode> &v)
{
	Node *node = new Node;
	node->name = s;
	node->id = ++counter;
	vector<lu> op_id;
	int i=0;
	while(i<v.size()){
		if(!v[i].is_node){
			counter+=1;
			lu opid = counter;
			op_id.push_back(opid);
			if(v[i].s!="") fprintf(dotfile, "\t%lu [label=\"%s\"];\n", opid, v[i].s.c_str());
		}
		i++;
	}
	fprintf(dotfile, "\t%lu [label=\"%s\"];\n", node->id, node->name.c_str());
	int j=0;
	i=0;
	while(i<v.size()){
		if(v[i].is_node && v[i].node ) fprintf(dotfile, "\t%lu -> %lu;\n", node->id, v[i].node->id);
		if(!v[i].is_node){
			if(v[i].s!="") fprintf(dotfile, "\t%lu -> %lu;\n", node->id, op_id[j]);
			j++;
		}
		i++;
	}
	return node;
}

Node *create_AST_leaf(string s, string token_name)
{
	Node *node = new Node;
	node->id = ++counter;
	
	string temp = "";
	int i=0;
	while(i<s.length()){
		temp+=s[i];
		if(s[i]=='\\') temp+=s[i];
		i++;
	}
	node->name = temp;
	if(s[0]=='"')
	{
		string s = temp.substr(1,temp.length()-2);
		fprintf(dotfile, "\t%lu [label=\"%s(\\\"%s\\\")\" shape=box style=filled color=\"lightblue\" fillcolor=\"lightyellow\"];\n", node->id, token_name.c_str(), s.c_str());
	}
	else
	{
		fprintf(dotfile, "\t%lu [label=\"%s(%s)\" shape=box style=filled color=\"dodgerblue\" fillcolor=\"lightgreen\"];\n", node->id, token_name.c_str(), node->name.c_str() );
	}
	return node;
}
