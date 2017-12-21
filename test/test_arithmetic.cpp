// тесты для вычисления арифметических выражений

<<<<<<< HEAD
#include <gtest.h> 
 #include "arithmetic.h" 
 #include "sstream" 
 using namespace std; 
 TEST(arithmethic, can_divice_EXPR1) 
 { 
 	arithmetic EXPR("5*7"); 
 	EXPR.DIVITION(); 
 	LEXEM el[3]; 
 	LEXEM* src = EXPR.GetLexems(); 
 	el[0] = LEXEM("5"); 
 	el[1] = LEXEM('*'); 
 	el[2] = LEXEM("7"); 
 	EXPECT_EQ(el[0], src[0]); 
 	EXPECT_EQ(el[1], src[1]); 
 	EXPECT_EQ(el[2], src[2]); 
 } 
 TEST(arithmethic, can_divice_EXPR2) 
 { 
 	arithmetic EXPR("5*7"); 
 	EXPR.DIVITION(); 
 	EXPR.CtoPOL(); 
 	LEXEM* src = EXPR.GETPOL(); 
 	int i = EXPR.GETnPOL(); 
 	LEXEM el[3]; 
 	el[0] = LEXEM("5"); 
 	el[1] = LEXEM("7"); 
 	el[2] = LEXEM('*'); 
 
 
 	EXPECT_EQ(el[0], src[0]); 
 	EXPECT_EQ(el[1], src[1]); 
 	EXPECT_EQ(el[2], src[2]); 
 } 
=======
#include <gtest.h>
#include "arithmetic.h"
#include "sstream"
using namespace std;
TEST(arithmethic, can_divice_EXPR1)
{
	arithmetic EXPR("5*7");
	EXPR.DIVITION();
	LEXEM el[3];
	LEXEM* src = EXPR.GetLexems();
	el[0] = LEXEM("5");
	el[1] = LEXEM("*");
	el[2] = LEXEM("7");
	EXPECT_EQ(el[0], src[0]);
	EXPECT_EQ(el[1], src[1]);
	EXPECT_EQ(el[2], src[2]);
}
TEST(arithmethic, can_divice_EXPR2)
{
	arithmetic EXPR("5*7");
	EXPR.DIVITION();
	EXPR.CtoPOL();
	LEXEM* src = EXPR.GETPOL();
	int i = EXPR.GETnPOL();
	LEXEM el[3];
	el[0] = LEXEM("5");
	el[1] = LEXEM("7");
	el[2] = LEXEM('*');

	EXPECT_EQ(el[0], src[0]);
	EXPECT_EQ(el[1], src[1]);
	EXPECT_EQ(el[2], src[2]);
}
>>>>>>> 275806a7380edd64ead0df76ee970146e7cf3c5d
