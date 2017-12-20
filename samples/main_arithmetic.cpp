// реализация пользовательского приложения

#pragma once
#include <iostream>
#include "arithmetic.h"
#include <string>
using namespace std;

int main()
{
	string Exp;
	int p = 1;
	int a;
	cout << "CALCULATE\n";
	cout << "Select an action:\n";
	while (p == 1)
	{
		cout << "1.ENTER\n";
		cout << "2.EXIT\n";
		cin >> a;
		system("cls");
		switch (a)
		{
		case 1:
		{
			cout << "Enter your expression:\n";
			cin >> Exp;
			arithmetic A(Exp);
			A.Clrspace();
			A.Minus();
			A.DIVITION();
			if (A.Check() == true)
			{
				A.CtoPOL();
				double res = A.Result();
				cout << '=' << res << endl;
			}
		}
		break;
		case 2: p = 0;
			break;

		}
	}
}