#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
void reverse(char c[],int n) //array always passed as reference :)
{
	stack<char> s;
	for(int i=0;i<n;i++)
	{
		s.push(c[i]);		
	}
	for(int i=0;i<n;i++)
	{
		c[i] =s.top();
		s.pop();	
	}
}
int main()
{
	char c[51];
	int ch;
	do
	{
		system("clear");	
		cout<<"\nEnter a String  : ";
		cin>>c;
		reverse(c,strlen(c));
		cout<<"\nOutput : "<<c;
		cout<<"\nDo you wish to continue 1/0 : ";
		cin>>ch; 	
	}
	while(ch==1);


}
