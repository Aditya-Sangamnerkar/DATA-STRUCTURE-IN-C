#include<stdio.h>
#include<stdlib.h>
struct Node{
	
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head = NULL;

struct Node* getNewNode(int x)
{
	//we can create a node like "Node myNode;" but it will be a local variable and it's lifetime will be only within the function.
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void append(int x)
{
	struct Node* temp1 = getNewNode(x);
	if(head == NULL)
	{
		head = temp1;
		return;	
	}
	struct Node* temp2 = head;
	if(head == NULL)
	{
		head = temp1;
	}
	else
	{
		while(temp2!=NULL)
		{
			if(temp2->next == NULL)
			{
				temp2->next = temp1;
				temp1->prev = temp2;
				break;			
			}
		temp2 = temp2->next;
		}
		
	}
	
}
void print()
{
	
	printf("\n DOUBLY LINKED LIST: ");
	struct Node* temp = head;
	if(temp == NULL)
		printf("Doubly Linked List is empty....");
	else
	{	
	while(temp!=NULL)
	{	
		if(temp->next == NULL)
			printf("%d-->NULL",temp->data);
		else if(temp->prev == NULL)
			printf("NULL<--%d<-->",temp->data);
		else
			printf("%d<-->",temp->data);
		temp = temp->next;	
	}
	}
}
int length()
{
	struct Node* temp = head;
	int length = 0;
	while(temp!=NULL)
	{
		length++;
		temp = temp->next;	
	}
	return length;
}
void insert_n(int x,int pos)
{
	struct Node *newNode,*prevNode,*currentNode;
	int i;
	newNode = getNewNode(x);
	currentNode= head;
	if(pos == 1)
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;	
		printf("Node inserted successfully...");
	}
	else
	{
		if(length()<pos)
		{
			printf("Index invalid....");
			free(newNode);
					
		}
		else
		{
			for(i=1;i<pos-1;i++)
			{
				currentNode = currentNode->next;			
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
			newNode->prev = prevNode;
			newNode->next = currentNode;
			prevNode->next = newNode;
			currentNode->prev = newNode;
			printf("Node inserted successfully...");
					
		}
	}
	

}
int isEmpty()
{
	if(head == NULL)
		return 0;
	else
		return 1;
}
void  delete_n(int pos)
{
	int i,len;
	len = length(head);	
	struct Node* temp1 = head;
	if(isEmpty() == 0)
		printf("Doubly Linked List already empty :p...");
	else if(pos == 1)
	{
		head = temp1->next;
		free(temp1);	
		
	}
	else if(pos > len)
	{
		printf("Index invalid...");
		return;		
	}
	else
	{
	
	for(i=0;i<pos-1;i++)
		temp1 = temp1->next;
	(*(temp1->next)).prev = temp1->prev;
	(*(temp1->prev)).next = temp1->next;
	free(temp1);
	
	}
	printf("\nNode deleted successfully from index %d",pos);
	
}
void print_rev()
{
	struct Node* temp = head;
	int l = length();

	printf("\n DOUBLY LINKED LIST: ");
	
	if(temp == NULL)
		printf("Doubly Linked List is empty....");
	else
	{	
		while(l>1)
		{	
			temp = temp->next;
			l--;	
		}	
		
		while(temp!=NULL)
		{	
			if(temp->next == NULL)
				printf("NULL<--%d",temp->data);
			else if(temp->prev == NULL)
				printf("<-->%d-->NULL",temp->data);
			else
				printf("<-->%d",temp->data);
			temp = temp->prev;	
		}
	}

	
}
void modify(int x,int pos)
{
	struct Node* temp1 = head;
	int i;
	if(length(head)<pos)
		printf("Index invalid");
	else
	{
		for(i=0;i<pos-1;i++)
		{
			temp1 = temp1->next;		
		}	
		temp1->data = x;
		printf("Node modified successfully...");
	}
}

void main()
{

	int x,n,ch,cont;
	do
	{
		system("clear");		
		printf(".........MENU.........");
		printf("\n1.Append");
		printf("\n2.Display");
		printf("\n3.Insert @nth position");
		printf("\n4.Reverse Print...");
		printf("\n5.Delete @nth position");
		printf("\n6.Modify");
		printf("\n7.Exit");
		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("\nEnter the data : ");
				scanf("%d",&x);
				append(x);
				break;
			case 2:
				print();
				break;
			case 3:
				print();
				printf("\nEnter the position of insertion : ");
				scanf("%d",&n);
				printf("\nEnter the data for the new node : ");
				scanf("%d",&x);
				insert_n(x,n);
				break;
			case 4:
				print_rev();
				break;
			case 5:
				print();				
				printf("\nEnter the index of node you want to delete : ");
				scanf("%d",&n);
				delete_n(n);
				break;
			case 6:
				print();
				printf("\nEnter the index of node you want to modify : ");
				scanf("%d",&n);
				printf("\nEnter the modified data : ");
				scanf("%d",&x);
				modify(x,n);
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("\nInvalid Choice...");		
		}
		printf("\nDo you wish to continue 1/0 : ");
		scanf("%d" ,&cont);
	}while(cont == 1);
	
}

