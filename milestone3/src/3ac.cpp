#include <fstream>
#include "3ac.h"

using namespace std;

vector<quad> code;
long long cntr = 0;
int f_flag=0;// used for printing stackpointer updation in constructor, because they dont return 

void emit(qid op, qid arg1, qid arg2, qid res, int idx){
    quad temp;
    temp.op = op;
    temp.arg1 = arg1;
    temp.arg2 = arg2;
    temp.res = res;
    temp.idx = idx;
    if(idx == -1) temp.idx = code.size();
    code.push_back(temp);
}

void backpatch(vector<int>& bplist, int target){
    for(int i=0;i<bplist.size(); i++){
        code[bplist[i]].idx = target;
    }
}

void casepatch(vector<int>& bplist, qid target){
    //backpatch for case statement

    for(int i=0;i<bplist.size(); i++){
        code[bplist[i]].arg1 = target;
    }
}


qid newtemp(string type){
    // creating temp variables
    string temp_var = "_t"+to_string(cntr);
    cntr++;
    insertSymbol(*curr_table, temp_var, type, GetSize(type), 0, NULL);
    return qid(temp_var, Lookup(temp_var));
}

int assign_exp(string op, string type, string type1,string type2, qid arg1, qid arg2){
    // emitting code for all type of assignment expressions
    string temp_op = "";
    qid sym_typ ;  
    qid sym_typ1;
    int flag1 = 0;
    int a;
    string str = op;
    str.pop_back();
    if(op != "="){
        temp_op = "" + op.substr(0, 1);    
        sym_typ = newtemp(type);    
    }
    else{
        sym_typ = arg2;
    }
    if(op == "<<=" ||op == ">>=")temp_op += temp_op;
    

    if(checkIfInteger(type1) && checkIfInteger(type2) ){
        temp_op += "int" ;
        if(op != "=")a = code.size(), emit(qid( temp_op ,Lookup(str)),arg1 ,arg2, sym_typ, -1);
    }
    else if( checkIfFloatingPt(type1) && checkIfInteger(type2)){
        flag1 = 1;
        sym_typ1 = newtemp(type);
        temp_op += "real" ;
        a = code.size();
        emit(qid("inttoreal",NULL), arg2, qid("" , NULL) , sym_typ1, -1);
        if(op != "=")emit(qid( temp_op ,Lookup(str)),arg1 ,sym_typ1 , sym_typ, -1);
    }
    else if( checkIfFloatingPt(type2) && checkIfInteger(type1)){
        flag1 = 1;
        sym_typ1 = newtemp(type);
        temp_op += "int" ;
        a = code.size();
        emit(qid("realtoint",NULL), arg2, qid("" , NULL) , sym_typ1, -1);
        if(op != "=") emit(qid( temp_op ,Lookup(str)),arg1 ,sym_typ1 , sym_typ, -1);
    }
    else if(checkIfFloatingPt(type1) && checkIfFloatingPt( type2) ){
        temp_op += "real" ;
        if(op != "=")a = code.size(), emit(qid( temp_op ,Lookup(str)),arg1 ,arg2, sym_typ, -1);
    }

    if(!(op == "=" && flag1 )){ a = code.size(); emit( qid ("=", Lookup("=")), sym_typ, qid("", NULL), arg1, -1);}
    else emit( qid ("=", Lookup("=")), sym_typ1, qid("", NULL), arg1, -1);

    return a;
}

void backpatch_remaining(){
    // backpatching all the remaining goto to Function end
    int i,j;
    j = code.size()-1;
	i= code.size()-2;
	// cout<<"Backpatching rem "<<code.size()<<"\n";
    // i--;
    while(code[i].op.first.substr(0,5)!="FUNC_"){
        if(code[i].op.first =="GOTO" && code[i].idx==0) code[i].idx = j;
		// cout<<code[i].op.first<<","<<code[i].arg1.first<<","<<code[i].arg2.first<<","<<code[i].res.first<<","<<code[i].idx<<","<<i<<endl;
        i--;
        
    }
}


map<int,string> mm;
vector<int> labelPlace;
map<int,string> findLabel;
int labelIdx = 0;
vector<string> checkArrPtr;

void print3AC_code(){
    ofstream tac_file;
    tac_file.open("intermediate_3ac.csv",ios::out|ios::trunc);
    if(!tac_file){
        cout<<"File not created\n";
    }
	ofstream final_3AC;
    final_3AC.open("final_3AC.txt",ios::out|ios::trunc);
    if(!final_3AC){
        cout<<"Textfile not created\n";
    }
	tac_file<<"Op, Arg1, Arg2, Result, Index, LineNum\n"; 
    for(int i=0;i<code.size(); i++){
        tac_file<<code[i].op.first<<","<<code[i].arg1.first<<","<<code[i].arg2.first<<","<<code[i].res.first<<","<<code[i].idx<<","<<i<<endl;
    }
    final_3AC<<"3AC code"<<endl;
    for(auto i:code){
        if(i.op.first == "GOTO"){
            labelPlace.push_back(i.idx);
        }
    }
    int j=0;
    for(auto i:labelPlace){
        if(findLabel.find(i)==findLabel.end()){
            j+=1;
            findLabel[i] = "L"+to_string(j);
        }
      
    }
    for(int i = 0;i<code.size();i++){
        string s1 = code[i].op.first;
        if(findLabel.find(i)!=findLabel.end() && s1!="RETURN"){
			// cout<<"YE\n";
            final_3AC<<findLabel[i]<<": ";
        }
        if(s1[0] == '+' || s1[0] == '-' || s1[0] == '*' || s1[0] == '/'){
            if(code[i].arg2.first==""){
                 final_3AC<<code[i].res.first<<" = "<<code[i].op.first<<code[i].arg1.first<<"\n";
            }
            else{
                 final_3AC<<code[i].res.first<<" = "<<code[i].arg1.first<<" "<<code[i].op.first<<" "<<code[i].arg2.first<<"\n";
            }
        }
        else if(code[i].op.first == "[ ]"){
            final_3AC<<code[i].res.first<<" = "<<code[i].arg1.first<<" + "<<code[i].arg2.first<<"\n";
            checkArrPtr.push_back(code[i].res.first);
        }
        else if(code[i].op.first == "="){
            if(count(checkArrPtr.begin(), checkArrPtr.end(), code[i].res.first) && !(count(checkArrPtr.begin(), checkArrPtr.end(), code[i].arg1.first))){
                final_3AC<<"*("<<code[i].res.first<<") = "<<code[i].arg1.first<<"\n";
            }
            else if(!(count(checkArrPtr.begin(), checkArrPtr.end(), code[i].res.first)) && (count(checkArrPtr.begin(), checkArrPtr.end(), code[i].arg1.first))){
                final_3AC<<code[i].res.first<<" = *("<<code[i].arg1.first<<")\n";
            }
            else if((count(checkArrPtr.begin(), checkArrPtr.end(), code[i].res.first)) && (count(checkArrPtr.begin(), checkArrPtr.end(), code[i].arg1.first))){
                final_3AC<<"*("<<code[i].res.first<<") = *("<<code[i].arg1.first<<")\n";
            }
            else{
                final_3AC<<code[i].res.first<<" = "<<code[i].arg1.first<<"\n";
            }
        }
		 else if(code[i].op.first == "qualname"){
            final_3AC<<code[i].res.first<<" = *("<<code[i].arg1.first<<" + "<<code[i].arg2.first<<")\n";
        }
        else if(code[i].op.first == "param"){
            final_3AC<<code[i].op.first<<" "<<code[i].arg1.first<<"\n";
        }
        else if(code[i].op.first == "CALL"){
			// sym_entry* sym= Lookup(code[i].arg1.first);
			final_3AC<<"stackpointer +"<<code[i].arg1.second->paramsize<<"\n";
            final_3AC<<code[i].op.first<<" "<<code[i].arg1.first<<", "<<code[i].arg2.first<<"\n";
			final_3AC<<"stackpointer -"<<code[i].arg1.second->paramsize<<"\n";
        }
        else if(code[i].arg1.first == "IF"){
            if(mm.find(code[i].idx)!=mm.end()){
                final_3AC<<"if "<<code[i].arg2.first<<" goto "<<mm[code[i].idx]<<"\n";
            }
            else{
                labelIdx+=1;
                mm[code[i].idx] = "L"+to_string(labelIdx);
                final_3AC<<"if "<<code[i].arg2.first<<" goto "<<mm[code[i].idx]<<"\n";
            }
        }
        else if(code[i].arg1.first == "" && code[i].op.first == "GOTO"){
            if(mm.find(code[i].idx)!=mm.end()){
                final_3AC<<"goto "<<mm[code[i].idx]<<"\n";
            }
            else{
                labelIdx+=1;
                mm[code[i].idx] = "L"+to_string(labelIdx);
                final_3AC<<"goto "<<mm[code[i].idx]<<"\n";
            }
        }
		else if(s1=="NEW")
		{
			final_3AC<<code[i].res.first<<" = "<<code[i].arg1.first<<endl;
			final_3AC<<"param "<<code[i].res.first<<endl;
			final_3AC<<"stackpointer +"<<code[i].arg1.first<<endl;
			final_3AC<<"call allocmem 1"<<endl;
			final_3AC<<"stackpointer -"<<code[i].arg1.first<<endl;
			final_3AC<<code[i].arg2.first<<" = popparam "<<endl;
		}
        else if(code[i].arg1.first != "" && code[i].op.first != "" && code[i].arg2.first !="" && code[i].res.first!=""){
            final_3AC<<code[i].res.first<<" = "<<code[i].arg1.first<<" "<<code[i].op.first<<" "<<code[i].arg2.first<<"\n";
        }
        else if(s1.substr(0,5)=="FUNC_"){
            if (s1.substr(s1.size()-5,3)=="end"){
				
                 if(f_flag==0) final_3AC<<"stackpointer -20\n";
				final_3AC<<"endfunc\n";
				f_flag=0;
            }
            else{
              
                
				final_3AC<<s1.substr(5,s1.size()-13)<<":\nbeginfunc\n";
				 final_3AC<<"stackpointer "<<code[i].op.second->size<<"\n";
				// final_3AC<<"stackpointer +20\n";
            }
        }
		
        else if(s1=="RETURN"){
			
			 final_3AC<<"stackpointer -20\n";
			  if(findLabel.find(i)!=findLabel.end()){
			// cout<<"YE\n";
            final_3AC<<findLabel[i]<<": ";
       	 }
			 f_flag=1;
            final_3AC<<"return "<<code[i].arg1.first<<endl;
        }
        else if(s1.find("to")!=-1){
            final_3AC<<code[i].res.first<<" = "<<code[i].op.first<<"("<<code[i].arg1.first<<")"<<endl;
        }
        else{
            final_3AC<<code[i].op.first<<","<<code[i].arg1.first<<","<<code[i].arg2.first<<","<<code[i].res.first<<","<<code[i].idx<<","<<i<<endl;
        }
    }
	
}
