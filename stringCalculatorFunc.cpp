/*
 * stringCalculaterSource.cpp
 *
 *  Created on: Mar 17, 2018
 *      Author: armin
 */
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include "stringCalculatorFunc.h"
using namespace std;
int stringToInteger(string str)
{
    int number;
    istringstream convert(str);
    if ( !(convert >> number) )
       throw "Can not convert";

    return number;
}
string intToString(int number)
{
	stringstream convert;
	convert << number;
	string result = convert.str();
	return result;
}
int operatorweight(char arg)//Add weight to the operator
{
    int weight = 0;
    switch(arg)
    {
    case '*':
    	weight = 3;
    	break;
    case '/':
        weight = 4;
        break;
    case '+':
    	weight = 1;
    	break;
    case '-':
        weight = 2;
        break;
    }
    return(weight);
}
bool isoperand(char arg)//Check weather the character is operand
{
    if(arg >= '0' && arg <= '9')
    	return 1;
    if(arg >= 'a' && arg <= 'z')
    	return 1;
    if(arg >= 'A' && arg <= 'Z')
    	return 1;
    return 0;
}
bool isoperator(char arg)//Check weather the character is operator
{
    if(arg == '*' || arg == '/' || arg == '+' || arg == '-')
    	return(1);
    else
    	return(0);
}
bool isoperator(string arg)//Check weather the character is operator
{
    if(arg == "*" || arg == "/" || arg == "+" || arg == "-")
    	return(1);
    else
    	return(0);
}

bool highprecendence(char a, char b)//Check for operator precendence
{
    int weighta = operatorweight(a);
    int weightb = operatorweight(b);
    if(weighta > weightb)
    	return 1;
    return 0;
}


string infixToPostfix(string infix)//Function to perform all conversion operation
{

    stack<char> stk;//Declaring a stack for conversion purpose
    string postfix = "";//Initialize the output string as empty;
    string number = "";
    for(int i = 0;i < infix.length(); i++)//Scan the infix string one by one
    {

        if(infix[i] == '(')
        {
        	if(number != "")
        	{
        		postfix += number;
        		postfix += " ";
        		number = "";
        	}
            stk.push(infix[i]);
        }
        else if(infix[i] == ')')
        {
        	if(number != "")
        	        	{
        	        		postfix += number;
        	        		postfix += " ";
        	        		number = "";
        	        	}
            while(stk.top() != '(')
            {
                postfix = postfix + stk.top();
                postfix += " ";
                stk.pop();
            }
            stk.pop();
        }
        else if(isoperand(infix[i]))
        {

        		if(infix[i-1] == '-' && (isoperator(infix[i-2])||i==1||infix[i-2]=='('))
        		{

        			number = intToString(0 - infix[i] + 48);

        		}
        		else
        			{

        				number += infix[i];
        			}

        }
        else if(isoperator(infix[i]))
        {
        		if(!isoperator(infix[i-1]) && infix[i-1]!='(' && i!=0)
        		{

        			if(number != "")
        			{
        				postfix += number;
        				postfix += " ";
        				number = "";
        			}
        			while(!stk.empty()&& !highprecendence(infix[i],stk.top()))
        			{

        				postfix += stk.top();
        				postfix +=" ";
        				stk.pop();
        			}

        			stk.push(infix[i]);

        		}
        }

    }


    if(number != "")
            	{

            		postfix += number;
            		postfix += " ";
            		number = "";
            	}

    while(!stk.empty())
    {

        postfix+= stk.top();
        postfix += " ";
        stk.pop();
    }
    return postfix;
}

string calculatingPostfix(string postfix)
{
	stack<string> stkPostfix ;
	string number = "";
	for(int i = 0 ; i < postfix.length(); i++)
				{
					if(isdigit(postfix[i]))
					{
						if(postfix[i-1] == '-')
							number = intToString(0 - postfix[i] + 48);
						else
							number += postfix[i];
					}
					else if(postfix[i] == ' ')
					{

						if(number != "")
										{
											stkPostfix.push(number);
											number = "";
										}
					}
					else if(isoperator(postfix[i])&& !isoperand(postfix[i+1]))
					{

						stkPostfix.push(postfix[i] + number);

					}
				}
	stack<string> calculatingStack;
				while(!stkPostfix.empty())
				{
					calculatingStack.push(stkPostfix.top());
					stkPostfix.pop();
				}

	stack<string> helpCalculating;
	while(!calculatingStack.empty())
	{
		if(isoperator(calculatingStack.top()))
		{

			int firstNumber = stringToInteger(helpCalculating.top());
			helpCalculating.pop();
			int secondNumber = stringToInteger(helpCalculating.top());
			helpCalculating.pop();
			if(calculatingStack.top() == "+")
				helpCalculating.push(intToString(secondNumber + firstNumber));
			else if(calculatingStack.top() == "-")
				helpCalculating.push(intToString(secondNumber - firstNumber));
			else if(calculatingStack.top() == "*")
				helpCalculating.push(intToString(secondNumber * firstNumber));
			else if(calculatingStack.top() == "/")
				helpCalculating.push(intToString(secondNumber / firstNumber));
		}
		else
		{
			helpCalculating.push(calculatingStack.top());

		}
		calculatingStack.pop();

	}
	return helpCalculating.top();


}






