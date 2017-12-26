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
 	switch (c) 
 	{ 
 	case '(': 
 	{ 
 		type = LBRACKET; 
 		Val = 0; 
 		Op = '0'; 
 		break; 
 	} 
 	case ')': 
 	{ 
 		type = RBRACKET; 
 		Val = 0; 
 		Op = '0'; 
		break; 
 	} 
 	case '+': 
 	{ 
 		type = OPERATOR;; 
 		Val = 1; 
 		Op = '+'; 
 		break; 
	} 
 	case '-': 
 	{ 
 		type = OPERATOR;; 
 		Val = 1; 
 		Op = '-'; 
 		break; 
 	} 
 	case '*': 
 	{ 
 		type = OPERATOR;; 
 		Val = 2; 
		Op = '*'; 
 		break; 
 	} 
 	case '/': 
 	{ 
 		type = OPERATOR;; 
		Val = 2; 
 		Op = '/'; 
 		break; 
 	} 
 	default: type = UNKNOWN; 
 		break; 
 
 	} 
 
 
 } 
 
 
 LEXEM::LEXEM(const string& str) 
 { 
 	Val = stod(str); 
 	type = NUMBER; 
 	Op = '0'; 
 } 
 

 LEXEM::LEXEM(const LEXEM &t) 
 { 
 	Val = t.Val; 
 	type = t.type; 
 	Op = t.Op; 
 } 
 
 
 LEXEM& LEXEM::operator=(const LEXEM &t) 
 { 
 	Val = t.Val; 
 	type = t.type; 
 	Op = t.Op; 
 	return *this; 
 } 
 

 
 
 arithmetic::arithmetic(const string& str) 
 { 
 	pLex = new LEXEM[str.length()]; 
 	EXPR = str; 
 	nLex = 0; 
 } 
 
 
 void arithmetic::DIVITION() 
 { 
 	for (int i = 0; i < EXPR.length(); i++) 
 	{ 
 		char c = EXPR[i]; 
 		if ((c == '*') || (c == '/') || (c == '+') || (c == '-') || (c == ')') || (c == '(')) 
 		{ 
 			LEXEM OPER(c); 
 			pLex[nLex] = OPER; 
 			nLex++; 
 		} 
 		else 
 			if (isdigit(c)) 
 			{ 
 				string EXP; 
 				int j = i; 
 				int t = EXPR.length(); 
 				while ((j < t) && ((isdigit(EXPR[j])) || EXPR[j] == '.')) 
 				{ 
 					j++; 
 				} 
 				EXP = EXPR.substr(i, j - i); 
 				pLex[nLex] = LEXEM(EXP); 
 				nLex++; 
 				i = j - 1; 
 			} 
 	} 
} 
 
 
 void arithmetic::Clrspace() 
 { 
 	unsigned int i = 0; 
 	while (i < EXPR.length()) 
 	{ 
 		if (EXPR[i] == ' ') 
 			EXPR.erase(i, 1); 
 		else i++; 
 	} 
 } 
 
 
 
 
 void arithmetic::CtoPOL() 
 { 
 	TStack<LEXEM> st; 
 	PolLex = new LEXEM[nLex]; 
 	int j = 0; 
 
 	for (int i = 0; i < nLex; i++) 
 	{ 
 
 
 		if (pLex[i].type == NUMBER || pLex[i].type == VARIABLE) 
 			PolLex[j++] = pLex[i]; 
 
 
 		if (pLex[i].type == LBRACKET) 
 			st.Push(pLex[i]); 
 
 
 		if (pLex[i].type == RBRACKET) 
 		{ 
 			while (st.Peek().type != LBRACKET) 
 				PolLex[j++] = st.Pop(); 
 			st.Pop(); 
 		} 
 
 
 
 
 		if (pLex[i].type == OPERATOR) 
 		{ 
 			if (st.IsEmpty()) 
 			{ 
 				st.Push(pLex[i]); 
			} 
 			else 
 			{ 
 				LEXEM t = st.Peek(); 
 				while (!st.IsEmpty() && t.Val >= pLex[i].Val) 
				{ 
 					t = st.Pop(); 
 					PolLex[j++] = t; 
					if (!st.IsEmpty())
 						t = st.Peek(); 
 				} 
 				st.Push(pLex[i]); 
			} 
 		} 
 
	} 
 
 
 
 
 	while (!st.IsEmpty()) 
 	{ 
 		LEXEM t = st.Pop(); 
 		PolLex[j++] = t; 
 	} 
 	nPolLex = j; 
 } 
 
 
 bool arithmetic::Check_Sym() const 
 { 
 	bool flag = true; 
 
 
 	for (int i = 0; i < nLex; i++) 
 	{ 
 		if (pLex[i].type == UNKNOWN) 
 		{ 
 			cout << "  " << "UNKNOWN SYMBOL" << endl; 
 			flag = false; 
 		} 
 		if ((pLex[i].type == VARIABLE)) 
 		{ 
 			cout << "UNKNOWN SYMBOL in " << i << endl; 
 			flag = false; 
 		} 
 	} 
 	return flag; 
 } 
 
 
 bool arithmetic::Check_Op() const
 {
	 bool flag = true;

	 if ((pLex[0].type == NUMBER || pLex[0].type == LBRACKET || pLex[0].Op == '-') && (pLex[nLex - 1].type == NUMBER || pLex[nLex - 1].type == RBRACKET || pLex[nLex - 1].type == VARIABLE))
	 {
		 for (int i = 0; i < (nLex - 1); i++)
		 {
			 switch (pLex[i].type)
			 {
			 case NUMBER:
				 if ((pLex[i + 1].type != RBRACKET) && (pLex[i + 1].type != OPERATOR))
				 {
					 flag = false;
					 cout <<"\n"<< "WARNING " << endl;
				 }
				 break;
			 case VARIABLE:
				 if ((pLex[i + 1].type != RBRACKET) && (pLex[i + 1].type != OPERATOR))
				 {
					 flag = false;
					 cout << "\n" << "WARNING " << endl;
				 }
				 break;
			 case OPERATOR:
				 if ((pLex[i + 1].type != NUMBER) && (pLex[i + 1].type != VARIABLE) && (pLex[i + 1].type != LBRACKET))
				 {
					 flag = false;
					 cout << "\n" << "WARNING " << endl;
				 }
				 break;
			 case LBRACKET:
				 if ((pLex[i + 1].type != NUMBER) && pLex[i + 1].type != VARIABLE && (pLex[i + 1].type != LBRACKET) && pLex[i + 1].Op != '-')  //&& (pLexem[i + 1].type != CLOSE_BRACKET)
				 {
					 flag = false;
					 cout << "\n" << "WARNING " << endl;
				 }
				 break;
			 case RBRACKET:
				 if ((pLex[i + 1].type != RBRACKET) && (pLex[i + 1].type != OPERATOR))
				 {
					 flag = false;
					 cout << "\n" << "WARNING " << endl;
				 }
				 break;
			 }
		 }
	 }
	 else
	 {
		 flag = false;
		 cout << "\n" << "WARNING " << endl;
	 }

	 return flag;

 }

 bool arithmetic::Check_Br() const 
 { 
 	bool flag = true; 
 	int p = 0; 
 	for (int i = 0; i < nLex; i++) 
 	{ 
		if (pLex[i].type == LBRACKET) 
 			p++; 
 

 		if (pLex[i].type == RBRACKET) 
 			p--; 
 	} 
 
 
 	if (p != 0) 
 	{ 
 		cout << "\n" << "ERROR(with BRACKETS)" << endl; 
 		flag = false; 
 	} 
 	return flag; 
 } 
 
bool arithmetic::Check() 
{ 
 	bool flag; 
 	if (EXPR.length() > 0) 
 	{ 
 		bool SYM, OP, BR; 
 
 
 		SYM = Check_Sym(); 
 		OP = Check_Op(); 
 		BR = Check_Br(); 
 		flag = (SYM && OP && BR); 
 	} 
 	else 
 	{ 
 		cout << "YOUR STRING IS EMPTY"; 
 		flag = false; 
 	} 
 	return flag; 
 } 
 

 
 
 double arithmetic::Result() 
 { 
 	TStack<double> st; 
 	double res = 0; 
 
 


 	for (int i = 0; i < nPolLex; i++) 
 	{ 
 

 		if (PolLex[i].type == NUMBER) 
 		{ 
 			st.Push(PolLex[i].Val); 

 
 		} 
		if (PolLex[i].type == OPERATOR) 
 		{ 
 			double l = st.Pop(); 
 			double r = st.Pop(); 
 
 
 			switch (PolLex[i].Op) 
 			{ 
 			case '+': 
 				res = l + r; 
 				break; 
 			case '-': 
 				res = r - l; 
 				break; 
 			case '*': 
 				res = l * r; 
 				break; 
 			case '/': 
 				res = r / l; 
 				break; 
 			} 
 			st.Push(res); 
 		} 
 	} 
 	return st.Pop(); 
 
 
 } 
