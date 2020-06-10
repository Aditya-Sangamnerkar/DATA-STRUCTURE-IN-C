#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;

};
struct Node* top = NULL;
void display()
{
	printf("\nStatus of Elements in Stack : ");
	struct Node* temp = top;
	if(temp == NULL)
		printf("Error: Stack empty!!");
	else
	{	
	while(temp!=NULL)
	{	printf("\n%d",temp->data);
		temp = temp->next;	
	}
	}
}
void push(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = top;
	top = temp;
}
void pop()
{
	struct Node* temp = top;
	if(top == NULL)
	{	
		printf("\nError: Stack empty!!");
		return;
	}
	top = top->next;
	printf("Popped element is = %d",temp->data);
	free(temp);
}
void main()
{


	int ch, cont,x;
	do
	{
		system("clear");		
		printf("\n       STACK OPERATIONS (using linked list)");
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
