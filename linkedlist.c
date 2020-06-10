#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;

};
struct Node* head = NULL;
void print()
{
	printf("\nLINKED LIST: ");
	struct Node* temp = head;
	if(temp == NULL)
		printf("Linked List is empty....");
	else
	{	
	while(temp!=NULL)
	{	
		if(temp->next == NULL)
			printf("%d-->NULL",temp->data);
		else
			printf("%d-->",temp->data);
		temp = temp->next;	
	}
	}
}
void append(int x)
{
	struct Node* temp1;
	temp1 = (struct Node*)malloc(sizeof(struct Node));
	temp1->data = x;
	temp1->next = NULL;
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
				break;			
			}
		temp2 = temp2->next;
		}
		
	}
}
void insert_n(int x,int  pos)
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
		printf("Node inserted successfully...");
	}
	else
	{
		if(length()<pos)
		{
			printf("Index invalid....");
			free(temp1);
					
		}
		else
		{
			for(i=1;i<pos-1;i++)
			{
				temp2 = temp2->next;			
			}
			temp1->next = temp2->next;
			temp2->next = temp1;
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
int length()
{
	int length = 0;
	struct Node* temp = head;	
	while(temp!=NULL)
	{
		length++;
		temp = temp->next;	
	}
	return length;
}
void  delete_n(int pos)
{
	int i,len;
	len = length(head);	
	struct Node* temp1 = head;
	if(isEmpty() == 0)
		printf("Linked List already empty :p...");
	else if(pos == 1)
	{
		head = temp1->next;
		free(temp1);	
		
	}
	else if(pos > len)
	{
		printf("Index invalid...");
			
	}
	else
	{
	
	for(i=0;i<pos-2;i++)
		temp1 = temp1->next;
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	free(temp2);
	printf("Node deleted sucessfully ...");
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
void reverse()
{
	struct Node *current,*prev,*next;
	current = head;
	prev = NULL;
	if(length(head)<2)
		printf("Cannot be reversed...");
	else
	{
	while(current!=NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;	
	}
	head = prev;
	}

}
void main()
{
	
	
	int i,n,x;
	int  ch ;
	int cont;
	do
	{
		system("clear");		
		printf(".........MENU.........");
		printf("\n1.Append");
		printf("\n2.Display");
		printf("\n3.Insert @nth position");
		printf("\n4.Length");
		printf("\n5.Delete @nth position");
		printf("\n6.Modify");
		printf("\n7.Reverse");
		printf("\n8.Exit");
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
				printf("\nEnter the index where you want to insert data : ");
				scanf("%d",&n);
				printf("\nEnter the data : ");
				scanf("%d",&x);
				insert_n(x,n);
				break;
			case 4:
				printf("\nLength of linked list is %d",length(head));
				break;

			case 5:
				print(head);
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
				print();				
				reverse();
				print();
				break;
			case 8:
				
				exit(0);
				break;
		
			default: 
				printf("\nInvalid Choice!!!");
		}
		printf("\nDo you wish too continue 1/0 : ");
		scanf("%d",&cont);
	}
	while(cont==1);	
}
