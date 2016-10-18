//Evan Garcia
//Data Structures II Lab 1
//April 18, 2015
//Filename: InfixtoPostfix.cpp
//The purpose of this program is to convert infix expressions to postfix expressions.

#include "InfixtoPostfix.h"

infixPostfix::infixPostfix(string i, string p)
{
	infx = i;
	pfx = p;
}

//Prompts user to enter infix chars
 bool infixPostfix::getInfix()
{
	infx = "";
	char ch;

	cout << "Please enter an infix expression, one character at a time:" <<endl;
	cin >> ch;
	while(ch != ';')
	{
		infx += ch;
	    cin >> ch; 
	}

	if(infx != ";" || infx != "")
		return true;

	if(infx == ";")
	{ 
		cout << "Error! Please enter a valid infix expression!" <<endl;
		return false;
	}
	
	
}

 ///Outputs infix expression
 void infixPostfix::showInfix()
 {
	 cout << infx << endl;  
 }

 //Outputs postfix expression
 void infixPostfix::showPostfix()
 {
	 convertToPostfix();
	 cout << pfx <<endl;
 }

 //Converts infix expression to postfix
 bool infixPostfix::convertToPostfix()
 {
	 pfx = "";

	 for(int i = 0; i <= infx.length(); i++)
	 {

		 if(infx[i] == '+' || infx[i] == '-' || infx[i] == '*' || infx[i] == '/' || infx[i] == '$')
			{

				while(!theStack.empty() && theStack.top() != '(' && (precedence(theStack.top(),infx[i])))
				{
					pfx += theStack.top();
					theStack.pop();
				}
				theStack.push(infx[i]);
			}
			 
		
			 if(isalpha(infx[i]))
			 {
				 pfx += infx[i];
			 }

			 if(infx[i] == '(')
			 {
				 theStack.push(infx[i]);
			 }

			
			 if(infx[i] == ')')
			 {
				 while(!theStack.empty() && theStack.top() != '(')
				 {

					 pfx += theStack.top();
					 theStack.pop();
					 
				 }
				 theStack.pop();
			 }


	}
	
	while(!theStack.empty())
	{
		if(theStack.top() == '(')
		{
			cout << "You have unbalanced parentheses!" << endl;
		}
		pfx += theStack.top();
		theStack.pop();
	}
		
	 return true;
 }

 //Gets operator weight to check precedence
 int infixPostfix::getOpWeight(char op)
{
	int weight = -1; 
	switch(op)
	{
	case '+':
	case '-':
		weight = 1;
	case '*':
	case '/':
		weight = 2;
	}
	return weight;
}

//Checks Precedence
bool infixPostfix::precedence(char character1, char character2)
 {

		 int op1Weight = getOpWeight(character1);
		 int op2Weight = getOpWeight(character2);


		 if (op1Weight >= op2Weight )
		 {
			 return true;
		 }

		 else return false;

 }