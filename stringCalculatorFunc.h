/*
 * stringCalculaterHeader.h
 *
 *  Created on: Mar 17, 2018
 *      Author: armin
 */

#ifndef STRINGCALCULATERHEADER_H_
#define STRINGCALCULATERHEADER_H_

#include <iostream>
#include <stack>
std :: string infixToPostfix(std :: string expr); //Function declaration
// region infix to postfix
bool isoperand(char );
bool isoperator(char );
int operatorweight(char );
bool highprecendence(char , char );
// end region
int stringToInteger(std :: string);
std::string intToString(int );
std :: string calculatingPostfix(std ::string);

#endif /* STRINGCALCULATERHEADER_H_ */
