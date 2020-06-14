#include<iostream>
#include<queue>
using namespace std;
struct Node{

	char data;
	Node* right;
	Node* left;
};

Node* getNewNode(char data)
{
	Node* temp = new Node();

	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}
Node* insert(Node* root , char data)
{
	if(root == NULL)
	{
		root = getNewNode(data);
	}
	else if(data <= root->data)
	{
		root->left = insert(root->left,data);
	}
	else
	{
		root->right = insert(root->right,data);
	}
	return root;

}
bool search(Node* root, char data)
{
	if(root == NULL)
	{

		return false;
	}
	else if(data == root->data)
	{
		return true;

	}
	else if(data<= root->data)
		return search(root->left,data);
	else
		return search(root->right,data);

}
bool isEmpty(Node* root)
{
	if(root == NULL)
		return true;
	else
		return false;
}
char findMax(Node* root)
{
	//recurrsive solution
	if(isEmpty(root))
	{
		cout<<"\nBST EMPTY!!";
		return '-1';
	}
	else if(root->right == NULL)
		return root->data;
	else
		findMax(root->right);


}
char findMin(Node* root)
{
	//recurrsive solution
	if(isEmpty(root) == true)
	{
		cout<<"\nBST EMPTY!!";
		return '-1';
	}
	else if(root->left == NULL)
		return root->data;
	else
		findMin(root->left);


}
int max(int left,int right)
{
	if(left > right)
		return left;
	else
		return right;

}
int findHeight(Node* root)
{
	int l,r;

	if(isEmpty(root) ==  true)
		return -1;
	else
	{
		l = findHeight(root->left);
		r = findHeight(root->right);
		return 	max(l,r) + 1;
	}

}
void levelOrder(Node* root)
{
	if(root == NULL)
	{
		cout<<"\nTree empty";
		return;
	}
	queue<Node*>Q;
	Q.push(root);
	cout<<"\nTRAVERSAL AS LEVEL ORDER :";
	while(!Q.empty())
	{
		root = Q.front();
		if(root->left!=NULL) Q.push(root->left);
		if(root->right!=NULL) Q.push(root->right);
		cout<<(Q.front()->data)<<" ";
		Q.pop();
	}


}
void preorder(Node* root)
{
	if(root == NULL)
	{

		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);

}
void inorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);

}
void postorder(Node* root)
{
	if(root == NULL)
	{

		return;
	}

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";

}



int main()
{
	Node* root;
	root = NULL;
	int ch,cont;
	char x;
	do
	{
		system("clear");
		cout<<"\n       BINARY SEARCH TREE OPERATIONS (input data as single character alphabets !! )";
		cout<<"\n--------------------------------------------";
		cout<<"\n1.INSERT";
		cout<<"\n2.SEARCH";
		cout<<"\n3.MAXIMUM AND MINIMUM VALUES";
		cout<<"\n4.HEIGHT OF BST";
		cout<<"\n5.BREADTH FIRST TRAVERSAL";
		cout<<"\n6.PREORDER TRAVERSAL";
		cout<<"\n7.POSTORDER TRAVERSAL";
		cout<<"\n8.INORDER TRAVERSAL";
		cout<<"\n9.DELETE A NODE FROM BST";
		cout<<"\n10.EXIT";
		cout<<"\n--------------------------------------------";
		cout<<"\nChoose Operation : ";
		cin>>ch;
		switch(ch)
		{

			case 1:
				cout<<"\nEnter the data for binary search tree : ";
				cin>>x;
				root = insert(root,x);
				cout<<"\nData entry successful!!";
				break;
			case 2:
				cout<<"\nEnter the data you want to search in binary search tree :";
				cin>>x;
				if(search(root,x) ==  true)
					cout<<"\nBST contains the given data";
				else
					cout<<"\nBST does not contain the given data";

				break;
			case 3:
				cout<<"\nMAXIMUM VALUE : "<<findMax(root);
				cout<<"\nMINIMUM VALUE : "<<findMin(root);
				break;
			case 4:
				cout<<"\nHEIGHT OF BST : "<<findHeight(root);
				break;
			case 5:
							levelOrder(root);
							break;
			case 6:

							cout<<"\nPREORDER TRAVERSAL : ";
							if(isEmpty(root) ==  true)
								cout<<"\nTREE EMPTY";
							else
								preorder(root);
							break;
				case 7:
								cout<<"\nPOSTORDER TRAVERSAL : ";
								if(isEmpty(root) ==  true)
									cout<<"\nTREE EMPTY";
								else
									postorder(root);
								break;
				case 8:
							cout<<"\nINORDER TRAVERSAL : ";
							if(isEmpty(root) ==  true)
								cout<<"\nTREE EMPTY";
							else
								inorder(root);
							break;


			case 11:
				exit(0);
				break;
			default :
					cout<<"\nInvalid Choice!!";
		}
		cout<<"\nDo you wish to continue 1/0 : ";
		cin>>cont;

	}while(cont==1);
	return 0;




}
