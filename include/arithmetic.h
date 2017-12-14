// объ€вление функций и классов дл€ вычислени€ арифметических выражений

#pragma once

#include <iostream>

#include "stack.h"

using namespace std;

enum LEXEMTYPE {NUMBER, OPERATOR, LBRACKET, RBRACKET, UNKNOWN};

const string ALLOP = "(+-*/)";

struct LEXEM

{

LEXEMTYPE type;

string str;
double Val;

LEXEM();

LEXEM(const char c);

LEXEM(const string& str, LEXEMTYPE myType);

LEXEM(const LEXEM &t);

void operator=(const LEXEM &t);

~LEXEM() {};

};

class arithmetic

{

private:

LEXEM*pLex;

std::string EXPR;

int nLex;

LEXEM*PolLex;

int nPolLex;

void DIVISION();

int CtoPOL(LEXEM* mas);

public:

arithmetic(const string& str);

~arithmetic() { delete[] pLex; }

void Check();

};