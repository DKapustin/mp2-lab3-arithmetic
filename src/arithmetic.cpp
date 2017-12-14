// реализация функций и классов для вычисления арифметических выражений

#include <iostream>

#include "arithmetic.h"

#include <string>

LEXEM::LEXEM()

{

type = UNKNOWN;

Val = 0;

}

LEXEM::LEXEM(const char c)

{

Val = ALLOP.find(c);

switch (c)

{

case'(':

{

type = LBRACKET;

Val = 0;

break;

}

case ')':

{

type = RBRACKET;

Val = 0;

break;

}

}

if (Val > 0)

type = OPERATOR;

}

LEXEM::LEXEM(const string& str, LEXEMTYPE myType)

{

Val = stod(str);

type = myType;

}

LEXEM::LEXEM(const LEXEM &t)

{

Val = t.Val;

type = t.type;

}

arithmetic::arithmetic(const string& str)

{

pLex = new LEXEM[str.length()];

string expr = str;

nLex = 0;

}

void arithmetic::DIVISION()

{

for (int i = 0; i < EXPR.length(); i++)

{

char c = EXPR[i];

if (ALLOP.find(c) != string::npos)

{

pLex[nLex] = LEXEM(c);

nLex++;

}

else if (isdigit(c))

{

string v;

int j = i;

while (j < EXPR.length() && (EXPR[j] == isdigit(c) || EXPR[j] == '.'))

j++;

v = EXPR.substr(i, j - i);

pLex[nLex] = LEXEM(v, NUMBER);

nLex++;

i = j - 1;

}

else if (c != ' ')

throw "ERROR";

}

}

void arithmetic::Check()

{

DIVISION();

int k = 0, p = 0;

for (int i = 0; i < nLex; i++)

{

if (pLex[i].type == LBRACKET) k++;

if (pLex[i].type == RBRACKET) p++;

}

if (((pLex[0].type == NUMBER) || (pLex[0].type == LBRACKET)) && ((pLex[nLex - 1].type == NUMBER) || (pLex[nLex - 1].type == RBRACKET)) && (p = k))

{

for (int i = 0; i < (nLex - 1); i++)

switch (pLex[i].type)

{

case NUMBER:

if ((pLex[i + 1].type != RBRACKET) || (pLex[i + 1].type != OPERATOR))

throw "WARNING";

case OPERATOR:

if ((pLex[i + 1].type != NUMBER) || (pLex[i + 1].type != RBRACKET))

throw "WARNING";

case LBRACKET:

if ((pLex[i + 1].type != NUMBER) || (pLex[i + 1].type != RBRACKET))

throw "WARNING";

case RBRACKET:

if ((pLex[i + 1].type != RBRACKET) || (pLex[i + 1].type != OPERATOR))

throw "WARNING";

}

}

else

throw "WARNING";

}

int arithmetic::CtoPOL(LEXEM* mas)

{

LEXEM ZERO;

ZERO.Val = 0;

ZERO.type = NUMBER;

LEXEMTYPE LT;

int j = 0;

TStack<LEXEM> EXP(2 * nLex);

for (int i = 0; i < nLex; i++)

{

LT = pLex[i].type;

if (LT == NUMBER)

mas[j++] = pLex[i];

if (LT == LBRACKET)

EXP.Push(pLex[i]);

if (LT == RBRACKET)

{

while (EXP.Peek().type != LBRACKET)

mas[j++] = EXP.Pop();

EXP.Pop();

}

if (LT == OPERATOR)

{

if (pLex[i].Val == 4)

if (i == 0)

mas[j++] = ZERO;

else if (pLex[i - 1].type == LBRACKET)

mas[j++] = ZERO;

while (!EXP.IsEmpty() && EXP.Peek().type != LBRACKET && (pLex[i].Val <= EXP.Peek().Val))

mas[j++] = EXP.Pop();

EXP.Push(pLex[i]);

}

}

while (!EXP.IsEmpty())

mas[j++] = EXP.Pop();

return j;

}