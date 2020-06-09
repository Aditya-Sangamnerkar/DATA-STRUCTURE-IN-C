#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;

};




void print(struct Node* head)
{
	printf("\nLinked List: ");
	while(head!=NULL)
	{	
		if(head->next == NULL)
			printf("%d->NULL",head->data);
		else
			printf("%d->",head->data);
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

void insert_end(struct Node* head, int x)
{
	struct Node* temp;
	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(head == NULL)
		printf("Empty List..insert at the beginning first");
	else
	{
		while(head!=NULL)
		{
			if(head->next == NULL)
			{
				head->next = temp;
				break;			
			}
		head = head->next;
		}
		
	}
}
struct Node* insert_n(int x,int  pos,struct Node* head)
{
	struct Node*  temp1;
	int i;
	temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = x;
	temp1->next = NULL;

	struct Node* temp2 = head;
	if(pos == 1)
	{
		temp1->next = head;
		head = temp1;	
	}
	else
	{
		if(length(head)<pos)
		{
			printf("Index invalid ....");
			return head;
					
		}
		else
		{
			for(i=1;i<pos-1;i++)
			{
				temp2 = temp2->next;			
			}
			temp1->next = temp2->next;
			temp2->next = temp1;
					
		}
	}
	printf("Insertion successful at index %d ....",pos);
	return head;

	
}
int length(struct Node* head)
{
	int length = 0;
	while(head!=NULL)
	{
		length++;
		head = head->next;	
	}
	return length;
}
void main()
{
	
	struct Node* head = NULL;
	int i,n,x;
	int  ch ;
	int cont;
	do
	{
		system("clear");		
		printf(".........MENU.........");
		printf("\n1.Insert node to beginning of Linked list");
		printf("\n2.Display the linked list");
		printf("\n3.Insert node at the end of Linked list(Append)");
		printf("\n4.Length of Linked list");
		printf("\n5.Insert node at nth index");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data : ");
				scanf("%d",&x);
				head = insert_beg(head , x);
				printf("Node added successfully...");
				break;	
			case 2:
				print(head);
				break;	
			case 3:
				printf("Enter the data : ");
				scanf("%d",&x);
				insert_end(head,x);
				printf("Node added successfully...");
				break;
			case 4:
				printf("Length of linked list is %d",length(head));
				break;
			case 5:
				print(head);
				printf("\nEnter the index where you want to insert data : ");
				scanf("%d",&n);
				printf("\nEnter the data : ");
				scanf("%d",&x);
				head = insert_n(x,n,head);
				break;
		
			default: 
				printf("Invalid Choice!!!");
		}
		printf("\nDo you wish too continue 1/0");
		scanf("%d",&cont);
	}
	while(cont==1);	
}
