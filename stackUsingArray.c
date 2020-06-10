#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;
void push(int x)
{
	
	if(top == MAX_SIZE - 1)
	{
		printf("\nError: stack overflow!!");
	}
	A[++top] = x;
}
int isEmpty()
{
	if(top == -1)
		return 1;
	else 
		return 0;
}
void pop()
{
	if(isEmpty())
		printf("\nError: No element to pop");
	else
	{
		printf("\nPopped element is  = %d",A[top]);
		top--;
	}	
}
void display()
{

	int i;
	printf("\nStatus of elements in stack :");
	if(top == -1)
	{
		printf("\nError: stack empty!!");
		return;	
	}
	for(i=top;i>=0;i--)
	{
		printf("\n%d",A[i]);
	}
}

void main()
{


	int ch, cont,x;
	do
	{
		system("clear");		
		printf("\n       STACK OPERATIONS (using array)");
		printf("\n--------------------------------------------");
		printf("\n1.PUSH");
		printf("\n2.POP");
		printf("\n3.DISPLAY");
		printf("\n4.EXIT");
		printf("\n--------------------------------------------");
		printf("\nChoose Operation : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element to be pushed : ");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:	
				exit(0);
				break;
			default:
				printf("\nInvalid choice!!");		
		}
		printf("\nDo you wish to continue 1/0 : ");
		scanf("%d",&cont);	
	}while(cont == 1);
}	
