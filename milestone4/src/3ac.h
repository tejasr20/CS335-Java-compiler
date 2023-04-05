#pragma once

#include <bits/stdc++.h>
#include "typecheck.h"

using namespace std;

typedef pair <string, sym_entry*> qid;


typedef struct quadruple{
    qid op;
    qid arg1;
    qid arg2;
    qid res;
    int idx;
} quad;

extern int debug_mode;
extern vector<quad> code;
extern ofstream code_file;
extern map<string, int> func_usage_map;
extern map<string , pair<string, int>> globaldecl;
extern map<string, vector<qid>> global_array_init_map;
extern sym_table gst;


void emit(qid, qid , qid , qid , int );
void backpatch(vector<int>& , int);
qid newtemp(string );
int assign_exp(string op, string type, string type1,string type2, qid arg1, qid arg2);
void casepatch(vector<int>& bplist, qid target);
void print3AC_code();
void backpatch_remaining();
void pop_function_arguments(string id);