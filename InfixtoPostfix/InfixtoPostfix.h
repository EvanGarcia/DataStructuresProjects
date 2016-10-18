//Evan Garcia
//Data Structures II Lab 1
//April 18, 2015
//Filename: InfixtoPostfix.h
//The purpose of this program is to convert infix expressions to postfix expressions.


#ifndef _InfixPostfix_H_ 
#define _InfixPostfix_H_

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class infixPostfix
{
public:
	infixPostfix(string _infx = "", string _pstfx = "");
	bool getInfix();
	void showInfix();
	void showPostfix();

private:
	
	string infx, pfx;
	stack<char> theStack;
	bool convertToPostfix();
	int getOpWeight(char op);
	bool precedence(char op1, char op2);

};


#endif //_InfixPostfix_H_