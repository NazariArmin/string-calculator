//============================================================================
// Name        : stringcalculater.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "stringCalculatorFunc.h"
#include <algorithm>
using namespace std;


int main()
{
    string infix;//Variable to get input expression
    cout<<"Enter the infix expression:";

    getline(cin,infix);
    cout << infixToPostfix(infix) << endl;


   cout << infix << " = " << calculatingPostfix(infixToPostfix(infix));

}

