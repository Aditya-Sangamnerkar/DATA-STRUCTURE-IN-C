#include<stdio.h>
#include<stdlib.h>
#define max_size 3;

int A[101];
int front = -1;
int rear = -1;

int isEmpty()
{
	if(front == -1 && rear == -1)
		return 1;
	else
		return 0;
}

int isFull()
{
	if((rear+1)%3 == front)
		return 1;
	else
		return 0;
}

void enqueue(int x)
{
	if(isFull())
	{
		printf("\nError: Queue overflow!!");
		return;
	}
	else if(isEmpty())
	{
		front = rear = 0;
	}
	else
		rear = (rear + 1)% max_size;

	A[rear] =  x;
	printf("\nEnqeuing successful...");
}

void dequeue()
{
	if(isEmpty())
	{
		printf("\nError : Queue already empty!!");
		return;	
	}
	else if(front == rear)
	{
		printf("\nThe element dequeued is = %d",A[front]);
		front = rear -1;	
	}
	else
	{

		printf("\nThe element dequeued is = %d",A[front]);
		front = (front + 1)%max_size;
	}	
}


void display()
{
	int i;
	printf("QUEUE : FRONT [ ");
	if(isEmpty())
	{
		printf("QUEUE EMPTY ");	
	}
	else if(front <= rear )
	{
		for(i=front;i<=rear;i++)
			printf("%d ",A[i]);
	}
	else 
	{
		for(i=front; i < 3; i++)
			printf("%d ",A[i]);
		for(i=rear;i<front;i++)
			printf("%d ",A[i]);
	}
	printf("] REAR");

}


void main()
{

	int ch,cont,x;
	do
	{
		system("clear");
		printf("\n       STACK OPERATIONS (using array)");
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


