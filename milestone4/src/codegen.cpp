#include "codegen.h"
#include "3ac.h"

map<string, set<qid> > reg_desc;
map<int ,string> leaders;
map<int, string> stringlabels;
map<int, int> pointed_by;
map<qid, int> addr_pointed_to;

int string_counter = 0;
int label_counter = 0;

set<string> exclude_this;

qid empty_var("", NULL);

extern vector<quad> code;
extern ofstream code_file;
extern map<string , pair<string, int>> globaldecl;
extern sym_table gst;

string get_label(){
    return "L" +to_string(label_counter++);
}

void starting_code(){
    code_file << "\nsection .text\n";
    code_file << "\tglobal main\n";
}

// checks whether a string is an integer or not
int is_integer(string sym){
    for(int i=0; i<sym.length(); i++){
        if(sym[i] >= '0' && sym[i]<='9'){
            continue;
        }
        else return 0;
    }
    return 1;
}

int is_pointerType(string type){
    if(type[type.length() - 1] == '*'){
        return 1;
    }
    return 0;
}

// This function is used for pointers
// Returns the size of variable to which pointer is pointing to
int give_size(sym_entry* entry){
    vector<int> v = entry->array_dims;
    if(!v.empty()){
        // Array pointer
        return v[0]*4;
    }
    if(entry->size_of_pointed > 0) return entry->size_of_pointed;
    
    return 4;
}

// addtion operation
void add_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) + stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);

        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg1<<endl;
            code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
        }
        
        if(is_pointerType(instr->arg1.second->type) && !is_pointerType(instr->arg2.second->type)){
            int size = give_size(instr->arg1.second);
            exclude_this.insert(reg1);
            string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
            exclude_this.erase(reg1);
            code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
            code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
            mem2 = temp_reg;
        }
        else if(!is_pointerType(instr->arg1.second->type) && is_pointerType(instr->arg2.second->type) ){
            int size = give_size(instr->arg1.second);
            code_file << "\timul "<<reg1 << ", "<< size<<"\n";
        }

        code_file << "\tadd " << reg1 << ", " << mem2 <<endl;
        update_reg_desc(reg1, &instr->res);
    }
}

// subtraction operation
void sub_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) - stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{        
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg1<<endl;
            code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
        }

        if(is_pointerType(instr->arg1.second->type) && !is_pointerType(instr->arg2.second->type)){
            int size = give_size(instr->arg1.second);
            exclude_this.insert(reg1);
            string temp_reg = getTemporaryReg(&instr->arg2, instr->idx);
            exclude_this.erase(reg1);
            code_file << "\tmov "<<temp_reg << ", "<< mem2<<"\n";
            code_file << "\timul "<<temp_reg << ", "<< size<<"\n";
            mem2 = temp_reg;
        }
        else if(!is_pointerType(instr->arg1.second->type) && is_pointerType(instr->arg2.second->type) ){
                int size = give_size(instr->arg2.second);
                code_file << "\timul "<<reg1 << ", "<< size<<"\n";
        }

        code_file << "\tsub " << reg1 << ", " << mem2 <<endl;
        update_reg_desc(reg1, &instr->res);
    }
}

// multiplicative operation
void mul_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) * stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        string reg1 = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
        string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);
        
        if(instr->arg1.second->is_derefer){
            string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg1<<endl;
            code_file<<"\tmov "<<reg1<<", [ "<<reg1<<" ]\n";
        }
        code_file << "\timul " << reg1 << ", " << mem2 <<endl;
        update_reg_desc(reg1, &instr->res);
    }
}


// CHECK
// divison operation
void div_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) / stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        free_reg("eax");
        free_reg("edx");
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, 0);
        code_file<<"\tmov eax"<<", "<< str <<"\n";
        reg_desc["eax"].insert(instr->arg1);
        reg_desc["edx"].insert(instr->arg1);
        
        exclude_this.insert("edx");
        exclude_this.insert("eax");
        string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
        if(instr->arg2.second->is_derefer){ 
            string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg2<<endl;
            code_file<<"\tmov "<<reg2<<", [ "<<reg2<<" ]\n";
        }
        exclude_this.clear(); 

        code_file<<"\tcdq\n";
        code_file<<"\tidiv "<<reg2<<"\n";

        instr->res.second->addr_descriptor.reg = "eax";
        reg_desc["eax"].clear();
        reg_desc["edx"].clear();
        reg_desc["eax"].insert(instr->res);
    }
}

// modulo operation
void mod_op(quad* instr){
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = (stoi(instr->arg1.first) % stoi(instr->arg2.first));
        string str = get_mem_location(&instr->res, &empty_var, instr->idx, 0);
        code_file << "\tmov " << str <<", " << "dword "<< val << "\n";
    }
    else{
        free_reg("eax");
        free_reg("edx");
        string str = get_mem_location(&instr->arg1,&instr->arg2, instr->idx, 0);
        code_file<<"\tmov eax"<<", "<< str <<"\n";
        reg_desc["eax"].insert(instr->arg1);
        reg_desc["edx"].insert(instr->arg1);
        string reg2 = getReg(&instr->arg2, &instr->res, &empty_var, instr->idx);
        if(instr->arg2.second->is_derefer){
            string str = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, -1);
            code_file<<"\tmov "<<str <<", "<< reg2<<endl;
            code_file<<"\tmov "<<reg2<<", [ "<<reg2<<" ]\n";
        }

        code_file<<"\tcdq\n";
        code_file<<"\tidiv "<<reg2<<"\n";
        instr->res.second->addr_descriptor.reg = "edx";
        reg_desc["eax"].clear();
        reg_desc["edx"].clear();
        reg_desc["edx"].insert(instr->res);
    }
}





void comparison_op(quad* instr){
    string op = instr->op.first;
    string l1 = "", l2 = "";
    l1 = get_label();
    l2 = get_label();
        
    if(is_integer(instr->arg1.first) && is_integer(instr->arg2.first)){
        int val = 0;
        
        if(op == "==")      val = (stoi(instr->arg1.first)  ==  stoi(instr->arg2.first));
        else if(op == "<")  val = (stoi(instr->arg1.first)  <   stoi(instr->arg2.first));
        else if(op == "<=") val = (stoi(instr->arg1.first)  <=  stoi(instr->arg2.first));
        else if(op == ">")  val = (stoi(instr->arg1.first)  >   stoi(instr->arg2.first));
        else if(op == ">=") val = (stoi(instr->arg1.first)  >=  stoi(instr->arg2.first));
        else if(op == "!=") val = (stoi(instr->arg1.first)  !=  stoi(instr->arg2.first));
        
        string mem = get_mem_location(&instr->res, &empty_var, instr->idx, 1);
        code_file << "\tmov " << mem <<", " << "dword "<< val << "\n";
        return;
    }

    string reg = getReg(&instr->arg1, &empty_var, &instr->arg2, instr->idx);
    
    if(instr->arg1.second->is_derefer){
        string str = get_mem_location(&instr->arg1, &instr->arg2, instr->idx, -1);
        code_file<<"\tmov "<<str <<", "<< reg<<endl;
        code_file<<"\tmov "<<reg<<", [ "<<reg<<" ]\n";
    }

    string jump_instruction = "";
    
    if(op == "==")      jump_instruction = "je";
    else if(op == "<")  jump_instruction = "jl";
    else if(op == "<=") jump_instruction = "jle";
    else if(op == ">")  jump_instruction = "jg";
    else if(op == ">=") jump_instruction = "jge";
    else if(op == "!=") jump_instruction = "jne";

    string mem2 = get_mem_location(&instr->arg2, &instr->arg1, instr->idx, 0);

    code_file << "\tcmp "<<reg<<", " << mem2 <<"\n";
    code_file << "\t"<<jump_instruction << " "<<l1<<"\n";
    code_file << "\tmov " << reg <<", " << "dword 0"<<"\n";
    code_file << "\tjmp " << l2 <<"\n";
    code_file << l1 << ":"<<"\n";
    code_file << "\tmov " << reg <<", " << "dword 1"<<"\n";
    code_file << l2 <<":" <<"\n";
    update_reg_desc(reg, &instr->res);
}




string char_to_int(string sym){
    if(sym[0]!='\'')return sym;
    if(sym[1] == '\\'){
        string s = sym.substr(1,2);
        if(s == "\\0") return "0";
        if(s == "\\n") return "10";
        if(s == "\\t") return "9";
    } 
    int val = (int )sym[1];
    sym = to_string(val);
    return sym;
}

void assign_op(quad* instr){
    if(is_integer(instr->arg1.first)){
        string mem = get_mem_location(&instr->res, &instr->arg1, instr->idx, 1);
        if(reg_desc.find(mem) != reg_desc.end()){
            free_reg(mem);
            update_reg_desc(mem, &instr->res);
        }
        code_file << "\tmov "<< mem << ", dword "<< instr->arg1.first <<endl;
    }
}

void unary_op(quad* instr){
    string op = instr->op.first;
    string temp;
   
    string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
    temp =reg;

    string instruction = "";
    if(op[2] == 'P'){
        // TODO
        if(op == "++P")      instruction = "inc";
        else if(op == "--P") instruction = "dec";
        
        if(instr->arg1.second->is_derefer){
            string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
            string reg1 = getTemporaryReg(&instr->arg1, instr->idx);

            reg = "[ " + reg + " ]";

            code_file<<"\tmov "<<reg1<<", "<<reg<<endl;
            code_file<<"\t"<<instruction<<" "<<reg1<<endl;
            code_file<<"\tmov "<<reg<<", "<<reg1<<endl;
            update_reg_desc(reg1, &instr->res);
        }
        else{
            string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
            code_file<<"\t"<<instruction<<" "<<reg<<endl;
            free_reg(reg);
            update_reg_desc(reg, &instr->res);
        }
        
    }
    else if(op[2] == 'S'){
        if(op == "++S")      instruction = "inc";
        else if(op == "--S") instruction = "dec";
        
        if(instr->arg1.second->is_derefer){
            string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
            string reg1 = getTemporaryReg(&instr->arg1, instr->idx);

            reg = "[ " + reg + " ]";
            code_file<<"\tmov "<<reg1<<", "<<reg<<endl;
            update_reg_desc(reg1, &instr->res);

            code_file<<"\t"<<instruction<<" "<<reg1<<endl;
            code_file<<"\tmov "<<reg<<", "<<reg1<<endl;
        }
        else{
            string reg = getReg(&instr->arg1, &instr->res, &instr->arg2, instr->idx);
            string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
            code_file<<"\tmov "<<reg1<<", "<<reg<<endl;
            update_reg_desc(reg1, &instr->res);

            code_file<<"\t"<<instruction<<" "<<reg<<endl;
            string str = get_mem_location(&instr->arg1, &empty_var,instr->idx,-1);
            code_file<<"\tmov "<<str<<", "<<reg<<"\n";
        }
    }
    else if(op =="~" ) {
        instruction = "not";
        string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
        if(instr->arg1.second->is_derefer){
            reg = "[ " + reg + " ]";
        }

        code_file<<"\tmov "<<reg1<<", "<<reg<<"\n";
        code_file << "\t"<<instruction<< " "<<reg1<<"\n";        
        update_reg_desc(reg1, &instr->res);
    }
    else if(op == "unary-"){
        instruction = "neg";
        string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
        
        if(instr->arg1.second->is_derefer){
            reg = "[ " + reg + " ]";
        }

        code_file<<"\tmov "<<reg1<<", "<<reg<<"\n";
        code_file << "\t"<<instruction<< " "<<reg1<<"\n";        
        update_reg_desc(reg1, &instr->res);
    }
    else if(op == "unary+"){
        reg_desc[reg].insert(instr->res);
        instr->res.second->addr_descriptor.reg = reg;
    }
    else if(op == "!"){
        string l1 = get_label();
        string l2 = get_label();
        string reg1 = getTemporaryReg(&instr->arg1, instr->idx);
        
        if(instr->arg1.second->is_derefer){
            reg = "[ " + reg + " ]";
        }

        code_file<<"\tmov "<<reg1<<", "<<reg<<"\n";
        code_file << "\tcmp "<<reg1<<", dword "<<0<<"\n";  //dword inserted
        code_file << "\tje "<<l1<<"\n";
        code_file << "\tmov "<<reg1<<", dword "<<0<<"\n";
        code_file << "\tjmp "<<l2<<"\n";
        code_file << l1 <<":\n";
        code_file << "\tmov "<<reg1<<", dword "<<1<<"\n";
        code_file << l2 <<":\n";
        update_reg_desc(reg1, &instr->res);
    }
}


void genCode(){
    findBasicBlocks();
    initializeRegs();
    nextUse();
    starting_code();

    int index = 0;
    for (auto it=leaders.begin(); it != leaders.end(); it++){
        code_file << it->second <<":\n";
        auto it1 = it;
        it1++;
        if(it1 == leaders.end()) break;
        
        int ended = 0;
        int start = it->first;
        int end = it1->first;
        
        for(int idx=start; idx < end; idx++){
            quad instr = code[idx];
            if(instr.arg1.first != "") instr.arg1.first = char_to_int(instr.arg1.first);
            if(instr.arg2.first != "") instr.arg2.first = char_to_int(instr.arg2.first);
            if(instr.op.first.substr(0,2) == "++"  
                    ||instr.op.first.substr(0,2) == "--" 
                    ||instr.op.first == "!" 
                    ||instr.op.first == "~" 
                    ||instr.op.first == "unary-" 
                    ||instr.op.first == "unary+") unary_op(&instr);
            // else if(instr.op.first == "unary&" || instr.op.first == "unary*") pointer_op(&instr);
            else if(instr.op.first[0] == '+')    add_op(&instr);
            else if(instr.op.first == "=")   assign_op(&instr);
            else if(instr.op.first[0] == '-') sub_op(&instr);
            else if(instr.op.first[0] == '*') mul_op(&instr);
            else if(instr.op.first[0] == '/') div_op(&instr);
            else if(instr.op.first[0] == '%') mod_op(&instr);
            else if(instr.op.first == "=="  
                    ||instr.op.first == "<" 
                    ||instr.op.first == "<=" 
                    ||instr.op.first == ">" 
                    ||instr.op.first == ">=" 
                    ||instr.op.first == "!=" ) comparison_op(&instr);
        }
        end_basic_block();
    }
}


void end_basic_block(){
    for(auto reg = reg_desc.begin();reg!=reg_desc.end();reg++){
        for(auto sym =reg->second.begin() ;sym!=reg->second.end(); sym++){
            if( is_integer(sym->first)) continue;
            sym->second->addr_descriptor.reg = "";
            qid tem = *sym;
            string str = get_mem_location(&tem, &empty_var, -1, -1); 
            code_file<<"\tmov " << str <<", "<<reg->first<<"\n";
        }
        reg->second.clear();
    }
}

// add sym to variables stores in reg
void update_reg_desc(string reg, qid* sym){
    for(auto it = reg_desc[reg].begin();it != reg_desc[reg].end(); it++){
        it->second->addr_descriptor.reg = "";
        qid temp = *it;
    }
    
    for(auto it = reg_desc.begin(); it != reg_desc.end(); it++){
        it->second.erase(*sym);
    }
    
    reg_desc[reg].clear();
    reg_desc[reg].insert(*sym);
    sym->second->addr_descriptor.heap = false;
    sym->second->addr_descriptor.stack = false;
    sym->second->addr_descriptor.reg = reg;
}

void initializeRegs(){
    reg_desc.insert(make_pair("eax", set<qid> () ));
    reg_desc.insert(make_pair("ecx", set<qid> () ));
    reg_desc.insert(make_pair("edx", set<qid> () ));
    reg_desc.insert(make_pair("ebx", set<qid> () ));
    reg_desc.insert(make_pair("esi", set<qid> () ));
    reg_desc.insert(make_pair("edi", set<qid> () ));
}


string get_mem_location(qid* sym, qid* sym2, int idx, int flag){
    if(sym->second->is_global){
        if(globaldecl[sym->first].second == 0) return string('['+sym->first+']');
        else return sym->first;
    }
    if(is_integer(sym->first)){
        if(flag) return string("dword " + sym->first);
        else return sym->first;
    }

    if(sym->second->addr_descriptor.reg != "" && flag!=-1){
        if(!sym->second->is_derefer || flag == 2) return sym->second->addr_descriptor.reg;
        return "[ " + sym->second->addr_descriptor.reg + " ]";
    }
    
    //Symbol in stack
    if(sym->second->heap_mem == 0){
        int offset = sym->second->offset;
        int size = sym->second->size;
        string str;
        sym->second->addr_descriptor.stack = true;
        if(offset >= 0) str = string("[ ebp - " + to_string(offset + size) + " ]");
        else{
            offset=-offset;
            str = string("[ ebp + "+to_string(offset) +" ]");
        }
        if(sym->second->is_derefer && flag != -1){
            string reg = getTemporaryReg(sym2, idx);
            code_file<< "\tmov "<<reg<<", "<<str<<"\n";
            update_reg_desc(reg, sym);
            return "[ " + reg + " ]";
        }

        return str;
    }
    
    // Wont come here as of now
    sym->second->addr_descriptor.stack = false;
    sym->second->addr_descriptor.heap = true;
    return string("[ " + to_string(sym->second->heap_mem) + " ]");
}

// Get a temporary register
string getTemporaryReg(qid* exclude_symbol, int idx){
    // freeDeadTemp(idx);
    string reg = "";
    int mn = 1000000;
    for (auto it : reg_desc){
        if( (exclude_symbol && it.second.find(*exclude_symbol) != it.second.end()) || exclude_this.find(it.first) != exclude_this.end()){
            // skip the reg containing second argument for an instruction
            continue;
        }
        if (it.second.size() < mn){
            mn =  it.second.size();
            reg = it.first; 
        }
    } 
    assert(reg != "");
    free_reg(reg);
    return reg;
}

// allocates a register to a variable
// efficient allocation is done to minise load or store
string getReg(qid* sym, qid* result, qid* sym2, int idx){
    // Case 1
    string reg = "";
    if(sym->second->addr_descriptor.reg != "") {
        reg = sym->second->addr_descriptor.reg;
        vector<qid> temp;
        for(auto it: reg_desc[reg]){
            if(it.first[0]!='#' && !(it.second->addr_descriptor.stack || it.second->addr_descriptor.heap)){
                it.second->addr_descriptor.reg = "";
                string str = get_mem_location(&it, &empty_var, idx, -1); 
                it.second->addr_descriptor.stack = 1;
                code_file << "\tmov " << str << ", " << reg <<endl;
                temp.push_back(it);
            }
        }
        
        for(auto it: temp){
            reg_desc[reg].erase(it);
        }
        
        return reg;
    }

    reg = getTemporaryReg(sym2, idx);
    
    if(sym->first[0] == '\"'){
        stringlabels[string_counter] = sym->first;
        code_file<<"\tmov "<<reg<<", __str__"<<string_counter<<"\n";
        string_counter++;
    }
    else{
        string str = get_mem_location(sym, sym2, idx, -1);
        code_file << "\tmov " << reg << ", "<< str <<"\n";
        sym->second->addr_descriptor.reg = reg;
        reg_desc[reg].insert(*sym);
    }
    return reg;
}

// Clear all the registers
void clear_regs(){
    for(auto reg = reg_desc.begin(); reg != reg_desc.end(); reg++){
        reg->second.clear();
    }
}


// free a specific register
void free_reg(string reg){
    for(auto sym: reg_desc[reg]){
        if(is_integer(sym.first)) continue;
        
        sym.second->addr_descriptor.reg = "";
        string str = get_mem_location(&sym, &empty_var, -1, -1);
        code_file<<"\tmov "<< str <<", "<<reg<<"\n";
    }
    reg_desc[reg].clear();
}



void nextUse(){
    for(auto it=leaders.begin(); it != leaders.end(); it++){
        auto it1 = it;
        it1++;
        if(it1 == leaders.end()) break;

        for(int i= (it1->first)-1; i>= (it->first); i--){
            if(code[i].arg1.first != "" && code[i].arg1.first[0] == '#' && code[i].arg1.second && code[i].arg1.second->next_use == -1){
                code[i].arg1.second->next_use = i;
            } 
            if(code[i].arg2.first != "" && code[i].arg2.first[0] == '#' && code[i].arg2.second && code[i].arg2.second->next_use == -1){
                code[i].arg2.second->next_use = i;
            }
            if(code[i].res.first != "" && code[i].res.first[0] == '#' && code[i].res.second && code[i].res.second->next_use == -1){
                code[i].res.second->next_use = i;
            } 
        }
    }
}

 // Finds Basic block in 3AC code.
void findBasicBlocks(){
    for (int i=0;i< (int)code.size(); i++){

        if (i == 0){
            leaders.insert(make_pair(i, get_label()));
            continue;
        }
        if(code[i].op.first.substr(0, 5) == "FUNC_"){
                if(code[i].op.first[code[i].op.first.length()-3] == 't') leaders.insert(make_pair(i, get_label()));
                else if(i+1 != code.size()) leaders.insert(make_pair(i+1, get_label()));
        }
        else if(code[i].op.first == "GOTO"){
            leaders.insert(make_pair(code[i].idx, get_label()));
            leaders.insert(make_pair(i+1, get_label()));
        }   
    }
    leaders.insert(make_pair(code.size(), get_label()));
}
