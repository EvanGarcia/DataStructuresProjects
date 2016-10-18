//Evan Garcia
//Data Structures II Lab 1
//April 18, 2015
//Filename: Client.cpp
//The purpose of this program is to convert infix expressions to postfix expressions.

#include "InfixtoPostfix.h"

using namespace std;

int main()
{
	cout << "Welcome to Evan's Infix-to-Postfix converter!" << endl << endl;
	infixPostfix expr; // create a class object

	bool exprOK = expr.getInfix();
	while (exprOK)
	{
		expr.showInfix();
		expr.showPostfix();
		cout << endl;
		exprOK = expr.getInfix();
	}
	return 0;
}