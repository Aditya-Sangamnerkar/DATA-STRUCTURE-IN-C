#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
int isEmpty()
{
	if(front == rear && front==NULL)
		return 1;
	return 0;

}

void enqueue(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	struct Node* head = front;
	temp->data = x;
	temp->next = NULL;	
	if(isEmpty())
	{	
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;	
	}
	printf("\nData added to the queue successfully..!!");


}

void dequeue()
{
	if(isEmpty())
	{
		printf("\nQUEUE already empty!!");	
		return;
	}	
	printf("\nElement removed from the queue is = %d",front->data);
	struct Node* temp = front;
	front = temp->next;
	free(temp);	
		
}

void display()
{
	
	struct Node* temp = front;

	printf("\n QUEUE : FRONT [ ");

	if(temp == NULL){
		printf("\nQueue is empty!!");
		return;
	}
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	} 
	printf("] REAR");
}
void main()
{

	int ch,cont,x;
	do
	{
		system("clear");
		printf("\n       QUEUE OPERATIONS (using linked list )");
		printf("\n--------------------------------------------");
		printf("\n1.ENQUEUE");
		printf("\n2.DEQUEUE");
		printf("\n3.DISPLAY");
		printf("\n4.EXIT");
		printf("\n--------------------------------------------");
		printf("\nChoose Operation : ");
		scanf("%d",&ch);
		switch(ch)
		{

			case 1:
				printf("\nEnter the element you want to push into the queue : ");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default :
					printf("\nInvalid Choice!!");
		}
		printf("\nDo you wish to continue 1/0 : ");
		scanf("%d",&cont);	

	}while(cont==1);


}


