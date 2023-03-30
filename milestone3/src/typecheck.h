#pragma once

#include "symbol_table.h"
#include <bits/stdc++.h>
using namespace std;

bool checkArrExpr(string a);
string primExpr(string id);
string constExpr(int numType );
string postfixExpr(string type_name, int rule_num);
string chkType(string a, string b);
string argExpr(string a, string b, int  rule_num);
string unaryExpr(string op, string type);
string multExpr(string a, string b, char op);
string addExpr(string a, string b, char op);
string shiftExpr(string a, string b);
string relExpr(string a, string b);
string eqlExpr(string a, string b);
string bitExpr(string a, string b);
string asgnExpr(string a, string b, string op);
string condExp(string a,string b);
int checkIfInteger (string type1);
bool checkIfFloatingPt (string type);
bool checkIfVoid(string type);
string find_base_type(string type);