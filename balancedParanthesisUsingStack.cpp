#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
bool matchParathesis(char open,char close)
{
  if(open == '[' && close == ']')
    return true;
  else if(open == '{' && close == '}')
    return true;
  else if(open == '(' && close == ')')
    return true;
  else
    return false;
}

bool checkParanthesis(char exp[])
{
  int l = strlen(exp);
  stack<char> s;
  for(int i=0;i<l;i++)
  {
    if((exp[i] == '[')||(exp[i] == '{')||(exp[i] == '(') )
      s.push(exp[i]);
    else if((exp[i] == ']')||(exp[i] == '}' )||(exp[i] == ')'))
    {
      if(s.empty() || !(matchParathesis(s.top(),exp[i])))
        return false;
      else
        s.pop();
    }
    else
      continue;
  }
  return s.empty()? true:false;
}

int main()
{
  char expression[50];
  int ch;
  do {
    system("clear");
    cout<<"\nEnter a Paranthesis expression to validate : ";
    cin>>expression;
    if(checkParanthesis(expression))
      cout<<"\nValid expression";
    else
      cout<<"\nExpression invalid";
    cout<<"\nDo you wish to continue 1/0 : ";
    cin>>ch;
  } while(ch==1);

}
