// тесты для вычисления арифметических выражений

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
	 arithmetic EXPR("5*7+(8-9/(6*8))");
	 EXPR.DIVITION();
	 LEXEM el[15];
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("5");
	 el[1] = LEXEM('*');
	 el[2] = LEXEM("7");
	 el[3] = LEXEM('+');
	 el[4] = LEXEM('(');
	 el[5] = LEXEM("8");
	 el[6] = LEXEM('-');
	 el[7] = LEXEM("9");
	 el[8] = LEXEM('/');
	 el[9] = LEXEM('(');
	 el[10] = LEXEM("6");
	 el[11] = LEXEM('*');
	 el[12] = LEXEM("8");
	 el[13] = LEXEM(')');
	 el[14] = LEXEM(')');
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmethic, can_divice_EXPR3)
 {
	 arithmetic EXPR("(2-6)*(3-6)*(4-6)");
	 EXPR.DIVITION();
	 LEXEM el[17];
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM('(');
	 el[1] = LEXEM("2");
	 el[2] = LEXEM('-');
	 el[3] = LEXEM("6");
	 el[4] = LEXEM(')');
	 el[5] = LEXEM('*');
	 el[6] = LEXEM('(');
	 el[7] = LEXEM("3");
	 el[8] = LEXEM('-');
	 el[9] = LEXEM("6");
	 el[10] = LEXEM(')');
	 el[11] = LEXEM('*');
	 el[12] = LEXEM('(');
	 el[13] = LEXEM("4");
	 el[14] = LEXEM('-');
	 el[15] = LEXEM("6");
	 el[16] = LEXEM(')');
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmethic, can_divice_EXPR4)
 {
	 arithmetic EXPR("23/7");
	 EXPR.DIVITION();
	 LEXEM el[3];
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("23");
	 el[1] = LEXEM('/');
	 el[2] = LEXEM("7");
	 EXPECT_EQ(el[0], src[0]);
	 EXPECT_EQ(el[1], src[1]);
	 EXPECT_EQ(el[2], src[2]);
 }
 TEST(arithmethic, can_divice_EXPR5)
 {
	 arithmetic EXPR("11*44-23+67");
	 EXPR.DIVITION();
	 LEXEM el[7];
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("11");
	 el[1] = LEXEM('*');
	 el[2] = LEXEM("44");
	 el[3] = LEXEM('-');
	 el[4] = LEXEM("23");
	 el[5] = LEXEM('+');
	 el[6] = LEXEM("67");
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmethic, can_convert_to_POL1) 
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
 TEST(arithmethic, can_convert_to_POL2)
 {
	 arithmetic EXPR("5-7");
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 int i = EXPR.GETnPOL();
	 LEXEM el[3];
	 el[0] = LEXEM("5");
	 el[1] = LEXEM("7");
	 el[2] = LEXEM('-');


	 EXPECT_EQ(el[0], src[0]);
	 EXPECT_EQ(el[1], src[1]);
	 EXPECT_EQ(el[2], src[2]);
 }
 TEST(arithmethic, can_convert_to_POL3)
 {
	 arithmetic EXPR("5-7*(2-(9+3))");
	 LEXEM el[9];
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("5");
	 el[1] = LEXEM("7");
	 el[2] = LEXEM("2");
	 el[3] = LEXEM("9");
	 el[4] = LEXEM("3");
	 el[5] = LEXEM('+');
	 el[6] = LEXEM('-');
	 el[7] = LEXEM('*');
	 el[8] = LEXEM('-');
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);

	 
 }
 TEST(arithmethic, can_convert_to_POL4)
 {
	 arithmetic EXPR("5*8-(9-(6+3*(23-27)))");
	 LEXEM el[13];
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("5");
	 el[1] = LEXEM("8");
	 el[2] = LEXEM('*');
	 el[3] = LEXEM("9");
	 el[4] = LEXEM("6");
	 el[5] = LEXEM("3");
	 el[6] = LEXEM("23");
	 el[7] = LEXEM("27");
	 el[8] = LEXEM('-');
	 el[9] = LEXEM('*');
	 el[10] = LEXEM('+');
	 el[11] = LEXEM('-');
	 el[12] = LEXEM('-');
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);


 }
 TEST(arithmethic, can_convert_to_POL5)
 {
	 arithmetic EXPR("55*67/(9-(16+23*(23-127)))");
	 LEXEM el[13];
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("55");
	 el[1] = LEXEM("67");
	 el[2] = LEXEM('*');
	 el[3] = LEXEM("9");
	 el[4] = LEXEM("16");
	 el[5] = LEXEM("23");
	 el[6] = LEXEM("23");
	 el[7] = LEXEM("127");
	 el[8] = LEXEM('-');
	 el[9] = LEXEM('*');
	 el[10] = LEXEM('+');
	 el[11] = LEXEM('-');
	 el[12] = LEXEM('/');
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);


 }
 TEST(arithmethic, can_devide_EXPR_with_minus1)
 {
	 arithmetic EXPR("-22*(48/24-111)");
	 LEXEM el[11];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM('-');
	 el[2] = LEXEM("22");
	 el[3] = LEXEM('*');
	 el[4] = LEXEM('(');
	 el[5] = LEXEM("48");
	 el[6] = LEXEM('/');
	 el[7] = LEXEM("24");
	 el[8] = LEXEM('-');
	 el[9] = LEXEM("111");
	 el[10] = LEXEM(')');
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmethic, can_devide_EXPR_with_minus2)
 {
	 arithmetic EXPR("-(233-78*89)+334");
	 LEXEM el[11];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM('-');
	 el[2] = LEXEM('(');
	 el[3] = LEXEM("233");
	 el[4] = LEXEM('-');
	 el[5] = LEXEM("78");
	 el[6] = LEXEM('*');
	 el[7] = LEXEM("89");
	 el[8] = LEXEM(')');
	 el[9] = LEXEM('+');
	 el[10] = LEXEM("334");
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmethic, can_devide_EXPR_with_minus3)
 {
	 arithmetic EXPR("67/34-56/(-34-17)");
	 LEXEM el[13];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("67");
	 el[1] = LEXEM('/');
	 el[2] = LEXEM("34");
	 el[3] = LEXEM('-');
	 el[4] = LEXEM("56");
	 el[5] = LEXEM('/');
	 el[6] = LEXEM('(');
	 el[7] = LEXEM("0");
	 el[8] = LEXEM('-');
	 el[9] = LEXEM("34");
	 el[10] = LEXEM('-');
	 el[11] = LEXEM("17");
	 el[12] = LEXEM(')');
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmethic, can_devide_EXPR_with_minus4)
 {
	 arithmetic EXPR("-22*(22+34-111*(23-34))");
	 LEXEM el[16];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM('-');
	 el[2] = LEXEM("22");
	 el[3] = LEXEM('*');
	 el[4] = LEXEM('(');
	 el[5] = LEXEM("22");
	 el[6] = LEXEM('+');
	 el[7] = LEXEM("34");
	 el[8] = LEXEM('-');
	 el[9] = LEXEM("111");
	 el[10] = LEXEM('*');
	 el[11] = LEXEM('(');
	 el[12] = LEXEM("23");
	 el[13] = LEXEM('-');
	 el[14] = LEXEM("34");
	 el[15] = LEXEM(')');
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmethic, can_devide_EXPR_with_minus5)
 {
	 arithmetic EXPR("-60-(35-24*111)/4");
	 LEXEM el[13];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 LEXEM* src = EXPR.GetLexems();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM('-');
	 el[2] = LEXEM("60");
	 el[3] = LEXEM('-');
	 el[4] = LEXEM('(');
	 el[5] = LEXEM("35");
	 el[6] = LEXEM('-');
	 el[7] = LEXEM("24");
	 el[8] = LEXEM('*');
	 el[9] = LEXEM("111");
	 el[10] = LEXEM(')');
	 el[11] = LEXEM('/');
	 el[12] = LEXEM("4");
	 bool res = true;
	 for (int i = 0; i < EXPR.GetNLex(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmetic, can_convert_to_POL_with_minus1)
 {
	 arithmetic EXPR("-33-34+35+36");
	 LEXEM el[9];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM("33");
	 el[2] = LEXEM('-');
	 el[3] = LEXEM("34");
	 el[4] = LEXEM('-');
	 el[5] = LEXEM("35");
	 el[6] = LEXEM('+');
	 el[7] = LEXEM("36");
	 el[8] = LEXEM('+');
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmetic, can_convert_to_POL_with_minus2)
 {
	 arithmetic EXPR("89-(-23*56-78)");
	 LEXEM el[9];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("89");
	 el[1] = LEXEM("0");
	 el[2] = LEXEM("23");
	 el[3] = LEXEM("56");
	 el[4] = LEXEM('*');
	 el[5] = LEXEM('-');
	 el[6] = LEXEM("78");
	 el[7] = LEXEM('-');
	 el[8] = LEXEM('-');
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmetic, can_convert_to_POL_with_minus3)
 {
	 arithmetic EXPR("-33*8+35/36");
	 LEXEM el[9];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM("33");
	 el[2] = LEXEM("8");
	 el[3] = LEXEM('*');
	 el[4] = LEXEM('-');
	 el[5] = LEXEM("35");
	 el[6] = LEXEM("36");
	 el[7] = LEXEM('/');
	 el[8] = LEXEM('+');
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmetic, can_convert_to_POL_with_minus4)
 {
	 arithmetic EXPR("(-23-45)*9");
	 LEXEM el[6];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM("23");
	 el[2] = LEXEM('-');
	 el[3] = LEXEM("45");
	 el[4] = LEXEM('*');
	 el[5] = LEXEM("9");
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
 TEST(arithmetic, can_convert_to_POL_with_minus5)
 {
	 arithmetic EXPR("-33-34*(-98+89)");
	 LEXEM el[11];
	 EXPR.Minus();
	 EXPR.DIVITION();
	 EXPR.CtoPOL();
	 LEXEM* src = EXPR.GETPOL();
	 el[0] = LEXEM("0");
	 el[1] = LEXEM("33");
	 el[2] = LEXEM('-');
	 el[3] = LEXEM("34");
	 el[4] = LEXEM("0");
	 el[5] = LEXEM("98");
	 el[6] = LEXEM('-');
	 el[7] = LEXEM("89");
	 el[8] = LEXEM('+');
	 el[9] = LEXEM('*');
	 el[10] = LEXEM('-');
	 bool res = true;
	 for (int i = 0; i < EXPR.GETnPOL(); i++)
		 if (el[i] == src[i])
			 res = true;
		 else
			 res = false;
	 EXPECT_EQ(true, res);
 }
