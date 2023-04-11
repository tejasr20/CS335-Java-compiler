#pragma once
#include <bits/stdc++.h>
#include "3ac.h"
using namespace std;


void starting_code();
void add_op(quad* instr);
void genCode();
void update_reg_desc(string reg, qid* sym);
void initializeRegs();

string get_mem_location(qid* sym, qid* sym2, int idx, int flag);
string getTemporaryReg(qid* sym, int idx);
string getReg(qid* sym, qid* result, qid* sym2, int idx);

void nextUse();
int is_integer(string sym);
void assign_op(quad* instr);
void findBasicBlocks();
void end_basic_block();
void sub_op(quad* instr);
void mul_op(quad* instr);
void div_op(quad* instr);
void mod_op(quad* instr);
void clear_regs();
void assign_op(quad* instr);
void comparison_op(quad* instr, string op);
void unary_op(quad* instr);
void free_reg(string reg);
string char_to_int(string sym);
