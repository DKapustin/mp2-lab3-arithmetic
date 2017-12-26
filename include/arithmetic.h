// объ€вление функций и классов дл€ вычислени€ арифметических выражений


#pragma once 

 
 #include <iostream> 
 
 
 #include "stack.h" 
 
 
 using namespace std; 
 
 
 enum LEXEMTYPE {NUMBER, OPERATOR, LBRACKET, RBRACKET, UNKNOWN, VARIABLE}; 
 
 
 const string ALLOP = "(+-*/)"; 
 
 
 struct LEXEM 
 
 
 { 
 
 
 LEXEMTYPE type; 
 char Op; 
 
 
 string str; 
 double Val; 
 
 
 LEXEM(); 
 
 
 LEXEM(const char c); 
 
 
 LEXEM(const string& str); 
 
 
 LEXEM(const LEXEM &t); 
 
 
 LEXEM& operator=(const LEXEM &t); 
 
 
 bool operator==(const LEXEM &t) const 
 { 
 	bool flag = false; 
 	if ((type == t.type) && (Op == t.Op) && (Val == t.Val)) 
 		flag = true; 
 	return flag; 
 } 
 
 
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
 
 
 
 
 
 
 public: 
 	void DIVITION(); 
 
 
 	void CtoPOL();  
 	void Clrspace();							 
 	bool Check_Sym() const;					 
 	bool Check_Br() const;				 
 	bool Check_Op() const;					 
 	bool Check(); 
 
 
 arithmetic(const string& str); 
 
 
 ~arithmetic() { delete[] pLex; } 
 double Result();  
 LEXEM* GetLexems() { return pLex; } 
 int GetNLex() { return nLex; } 
 LEXEM*GETPOL() { return PolLex; } 
 int GETnPOL() { return nPolLex; } 
 
 
 void Minus() 
 { 
 	if (EXPR[0] == '-') 
 		EXPR.insert(0, "0"); 
 	for (unsigned int i = 1; i < EXPR.length(); i++) 
 		if (EXPR[i - 1] == '(' && EXPR[i] == '-') 
 			EXPR.insert(i, "0"); 
 	delete[] pLex; 
 	pLex = new LEXEM[EXPR.length()]; 
 } 
 

 }; 
