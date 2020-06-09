#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;

};


struct Node* head = NULL;

void print(struct Node* head)
{
	printf("\n");
	while(head!=NULL)
	{	
		printf("%d ",head->data);
		head = head->next;	
	}
}
struct Node* insert_beg( struct Node* head,int x)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;

	if(head == NULL)
	{
		head = temp;	
	}
	else
	{
		temp->next = head;
		head = temp;
	}

	return head;
}
void main()
{
	
	struct Node* head = NULL;
	int i,n,x;
	printf("How many numbers : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the number ");
		scanf("%d",&x);		
		head = insert_beg(head,x);
		print(head);	
	}
}
