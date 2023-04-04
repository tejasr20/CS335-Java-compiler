#include "typecheck.h"

//RETURNS THE TYPE OF IDENTIFIER id USING Lookup

bool checkArrExpr(string a)
{
	if(checkIfInteger(a)) return true;
	return false;
}

string primExpr(string id) {
    sym_entry* n = Lookup(id);
    if(n) {
		string s;
		if(id.substr(0,5)=="CLASS")
		{
			cout<<id.substr(6,id.length()-6)<<" Y\n";
			s= id.substr(6,id.length()-6);
		}
        else s = n->type;
        return s;     
    }
	return "";
}

string constExpr(int numType ){
    switch(numType){
        case 1: return "int";
        case 2: return "long";
        case 3: return "float";
        case 4: return "double";
        default : return "default";
    }
}

string postfixExpr(string type_name, int rule_num) {
    string result_type;
    switch(rule_num) {
        case 1: {
            if(type_name.back()=='*')return type_name.substr(0,type_name.length()-1);
            return "";
        }
        case 2:{
            if(type_name.substr(0, 5)=="FUNC_")return type_name.substr(5, type_name.length() - 5); 
            return "";
        }
        case 3:{
            if(type_name.substr(0, 5)=="FUNC_")return type_name.substr(5, type_name.length() - 5);
            return "";
        }
		// can combine cases 6 and 7 
        case 6:{
            if(checkIfInteger(type_name) || type_name == "char")return type_name;
            return ""; // used for postincerement 
        }
        case 7:{
            if(checkIfInteger(type_name) || type_name == "char")return type_name;
            return ""; // used for postdecrement,
        }
        default : return "";
    }   
}

string chkType(string a, string b){
    if(a == b)return "ok";
    if((a == "void*" && b.back()=='*')||(a.back()=='*' && b == "void"))return "ok";
    if(a.back()=='*' && b.back()=='*')return "warning";
    if((checkIfInteger(a) && b.back()=='*')||(checkIfInteger(b)&&a.back()=='*'))return "warning";
    if(a == "char" || checkIfInteger(a)) a = "double";
    if(b == "char" || checkIfInteger(b)) b = "double";
    if(checkIfFloatingPt(a) && checkIfFloatingPt(b)) return "ok";
    return "";
}

string argExpr(string a, string b, int  rule_num){
    if(rule_num == 1){
        if(a == "void") return a;
        return "";
    }
    else{
        if(a == "void" && b=="void") return a;
        return "";
    }
}

string unaryExpr(string op, string type){
    if(op=="*") return postfixExpr(type, 1);
    else if(op == "&") type+="*";
    else if(op=="+" || op=="-"){
        if(!(checkIfInteger(type) || checkIfFloatingPt(type))) return "";
    }
    else if(op=="~"){
        if(!(checkIfInteger(type) || type != "bool")) return "";
    }
    else if(op=="!" && !(checkIfInteger(type) || type != "bool")) return "";
    return type;
}

string multExpr(string a, string b, char op){
    if(op=='*' || op =='/'){
        if(checkIfInteger(a) && checkIfInteger(b)) 
		{
			return "int";
		}
        else if((checkIfInteger(a) || checkIfFloatingPt(a)) && (checkIfInteger(b) || checkIfFloatingPt(b))) return "float";
       
		return "";
    }
    else if(op=='%'){
        if(checkIfInteger(a) && checkIfInteger(b)) return "int";
    }
    return "";
}

string addExpr(string a, string b, char op){
    if(checkIfInteger(a) && checkIfInteger(b)) return "int";
    else if((checkIfInteger(a) || checkIfFloatingPt(a)) && (checkIfInteger(b) || checkIfFloatingPt(b))) return "real";
    else if((checkIfInteger(a) && b=="char") || (a=="char" && checkIfInteger(b))) return "char";
    else if(checkIfInteger(a) && b.back()=='*') return b;
    else if(a.back()=='*' && checkIfInteger(b)) return a;
    else if(a=="char*" && b=="char*") return "char*";
    return "";
}

string shiftExpr(string a, string b){
    if(checkIfInteger(a) && checkIfInteger(b)) return "ok";
    return "";
}

string relExpr(string a, string b){
    if((checkIfInteger(a) || checkIfFloatingPt(a) || a=="char") && (checkIfInteger(b) || checkIfFloatingPt(b) ||b=="char")) return "bool";
    if((checkIfInteger(a) || a=="char") && b.back()=='*') return "Bool";
    if((checkIfInteger(b) || b=="char") && a.back()=='*') return "Bool";
    return "";
}

string eqlExpr(string a, string b){
    if(a==b) return "Ok";
    if((checkIfInteger(a) || checkIfFloatingPt(a) || a=="char") && (checkIfInteger(b) || checkIfFloatingPt(b) ||b=="char")) return "Ok";
    if((checkIfInteger(a) && b.back()=='*') || (a.back()=='*' && checkIfInteger(b))) return "ok";
    return "";
}

string bitExpr(string a, string b){
    if(a=="bool" && b=="bool") return "ok";
    if((a=="bool" || checkIfInteger(a)) && (b=="bool" || checkIfInteger(b))) return "Ok";
    return "";
}

string asgnExpr(string a, string b, string op){
    if(op=="="){
        return chkType(a,b);
    }
    if(op == "*=" || op == "/=" || op == "%="){
        if(multExpr(a, b, op[0])=="") return "";
        else return "ok";
    }
    if(op == "+=" || op == "-="){
        if(addExpr(a, b, op[0])=="") return "";
        else return "ok";
    }
    if(op == ">>=" || op == "<<="){
        if(shiftExpr(a, b)=="") return "";
        else return "ok";
    }
    if(op == "&=" || op == "|=" || op == "^="){
        if(bitExpr(a, b)=="") return "";
        else return "ok";
    }
    return "";
}

string condExp(string a,string b){
    if(a == b)return a;
    if(a == "char"|| checkIfInteger(a)) a = "float";
    if(b == "char"|| checkIfInteger(b)) b = "float";
    if(checkIfFloatingPt(a) && checkIfFloatingPt(b)) return "int";
    if(a.back() == '*' && b.back() == '*')return "void*" ;
    return "";
}

int checkIfInteger(string type1){
if(integer_types.find(type1)!=integer_types.end()) return 1;
   return 0;
}


bool checkIfFloatingPt (string type){
if(float_types.find(type)!=float_types.end()) return 1;
   return 0;
}

bool checkIfVoid(string type){
    if(type.length() < 4) return 0;
    else if(type.substr(0,4) == "void") return 1;
    else return 0;
}

string find_base_type(string type)
{
	int i=0;
	while(i<type.length())
	{
		if(type[i]=='*') break;
		i++;
	}
	return type.substr(0, i);
}
