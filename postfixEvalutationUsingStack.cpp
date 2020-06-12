#include<iostream>
#include<stack>
#include<string>
#include<cmath>
/*
	Evaluation of postfix expression in C++.
	Input postfix expression is not checked for it's correctness.
	Operands must be integers.
	Operators must be : + - * /
	every operand and operator must be followed by a space also various operands must be seperated by commas.
	ex 2 32 +


*/

using namespace std;

int evaluatePostfix(string exp);
bool isOperator(char opt);
bool isOperand(char opd);
int calculate(char opt,int opd1,int opd2);
int intValue(char num);

int main()
{
	string expression;
	cout<<"\nEnter a postfix expression : ";
	getline(cin,expression);
	int result = evaluatePostfix(expression);
	cout<<"\nOutput : "<<result;
}

int evaluatePostfix(string exp)
{
	stack<int> s;
	int operand = 0;
	int placevalue = 0;
	int op1,op2,result;
	for (int i = 0; i < exp.length(); i++) {

			if(exp[i] == ' ')
			{
				continue;
			}
			else if(isOperator(exp[i]))
			{
				op1 = s.top();
				s.pop();
				op2 = s.top();
				s.pop();
				result = calculate(exp[i],op1,op2);
				s.push(result);
			}
			else if(isOperand(exp[i]))
			{
				operand = intValue(exp[i]) + (operand * pow(10,placevalue));
				placevalue++;

				if(exp[i+1] == ' ')
				{
						s.push(operand);
						operand = 0;
						placevalue = 0;
				}

			}
	}
	return s.top();
}

bool isOperator(char c)
{

	if(c == '+' || c =='-' || c == '/' || c == '*')
		return true;
	else
		return false;


}
bool isOperand(char c)
{

	if(c>=48 && c<=57 )
		return true;
	else
		return false;
}
int calculate(char opt,int op1,int op2)
{

	int result;
	switch(opt)
	{
		case '+':
			 result = op1 + op2;
				break;
		case '-':
			 result = op1 - op2;
				break;
		case '*':
			 result = op1 * op2;
				break;
		case '/':
			 result = op1 / op2;
				break;
		default:
			result =0;



	}
	return result;

}
int intValue(char c)
{

	int value;
	switch(c)
	{

		case '0':
				value = 0;
				break;
		case '1':
				value = 1;
				break;
		case '2':
				value = 2;
				break;
		case '3':
				value = 3;
				break;
		case '4':
				value = 4;
				break;
		case '5':
				value = 5;
				break;
		case '6':
				value = 6;
				break;
		case '7':
				value = 7;
				break;
		case '8':
				value = 8;
				break;
		case '9':
				value = 9;
				break;
		default:
				value = 0;


	}


		return value;
}
