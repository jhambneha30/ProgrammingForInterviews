/* Print Top view of a Binary tree

Method 1:
This is a modification to the Vertical Level Order.
Build the Double linked list containing all the numbers in the range. Then add just the first
element at that horizontal distance to the below linked list.

Finally print these elements in the below linked lists. These form the top view of the binary 
tree.

TC=O(n)
SC=O(ht) for stack and O(n) for DLL structure in worst case
============================================================================================
Method 2:
Use two variables: min and max to store the min horizontal distance while going towards the
left sub tree and max horizontaL distance while going towards the RST. Print the node only
when the value in min and max is updated. 

TC=O(n)
SC=O(n) used by stack + O(1) for two variables
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct LLnode
{
	int data;
	struct LLnode *nextLL;
};

struct DLLnode
{
	int index;
	struct DLLnode *next, *prev;
	struct LLnode *below;
};

struct node * newNode(int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}

struct LLnode *newLLNode(int data)
{
	struct LLnode *newLL=(struct LLnode *)malloc(sizeof(struct LLnode));
	newLL->data=data;
	newLL->nextLL=NULL;

	return newLL;
}

struct DLLnode *newDLLNode(int index,int belowData)
{
	struct DLLnode *newDLL=(struct DLLnode *)malloc(sizeof(struct DLLnode));
	newDLL->index=index;
	newDLL->next=NULL;
	newDLL->prev=NULL;
	//--------First node in the below LL
	newDLL->below=newLLNode(belowData);
	printf("added new dll\n");
	return newDLL;
}




void preorder(struct node *root)
{
	if(root)
	{
		printf("%d  ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
	
}

void insertInLL(struct LLnode *belowHead,int newData)
{
	if(!belowHead)
		return;

	struct LLnode *newLL=newLLNode(newData);
	newLL->nextLL=belowHead->nextLL;
	belowHead->nextLL=newLL;

}

struct DLLnode* verticalOrderTraversal(struct node *root,struct DLLnode *head, int hd,char flag)
{
	struct DLLnode *ptr;
	if(!root)
		return;
	
	if(!head && flag=='h')
	{
		
		head=newDLLNode(hd,root->data);
		// printf("Inside head:%d\n",head->index);
		ptr=head;
	}
	//printf("flag:%c\n",flag);
	if(flag=='l')
	{
		// printf("Inside l:%d\n",head->index);
		if(!head->prev)
		{
			// printf("Inside !head->prev condition1:%d\n",head->index);
			head->prev=newDLLNode(hd,root->data);
			// printf("Inside !head->prev condition2:%d\n",head->prev->index);
			head->prev->next=head;
			// printf("Inside !head->prev condition3:%d\n",head->prev->next->index);
			head=head->prev;
			// printf("Inside !head->prev condition4:%d\n",head->index);
			

		}
		// else
		// {
		// 	// printf("In left: head->prev already present :%d\n",head->prev->index);
		// 	insertInLL((head->prev->below),root->data);

		// }
		
	}

	if(flag=='r')
	{
		if(!head->next)
		{
			head->next=newDLLNode(hd,root->data);
			head->next->prev=head;
			head=head->next;

		}
		// else
		// {
		// 	insertInLL((head->next->below),root->data);
		// }
		

	}

	// printf("value:%d, hor dist:%d\n",root->data,hd);
	verticalOrderTraversal(root->left,head,hd-1,'l');

	verticalOrderTraversal(root->right,head,hd+1,'r');
	return ptr;
}

void verticalOrderTraversal_2(struct node *root, int horizontalDist,int *min, int *max)
{
	if(!root)
		return;
	// if(flag=='h')
	// 	printf("%d  ",root->data);

	printf("value:%d, hor dist:%d\n",root->data,horizontalDist);
	if(horizontalDist<*min)
	{
		*min=horizontalDist;
		printf("%d  ",root->data);
	}
	if(horizontalDist>*max)
	{
		*max=horizontalDist;
		printf("%d  ",root->data);
	}
	verticalOrderTraversal_2(root->left,horizontalDist-1,min,max);

	verticalOrderTraversal_2(root->right,horizontalDist+1,min,max);
}

int main()
{
	struct node *root=NULL;
	struct DLLnode *head=NULL;
	int horizontalDist=0;
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
	
	preorder(root);
	printf("\nTOP VIEW using Vertical order traversal:\n");

	head=verticalOrderTraversal(root,head,horizontalDist,'h');
	struct DLLnode *temp=head;
	while(temp->prev)
	{
		// printf("Indicator: %d\n",temp->index);
		temp=temp->prev;
	}
	head=temp;
	while(temp)
	{
		printf("\nIndicator: %d\n",temp->index);
		struct LLnode *ptr=temp->below;
		while(ptr)
		{
			printf("%d  ",ptr->data);
			ptr=ptr->nextLL;
		}
		temp=temp->next;
	}

	preorder(root);
	printf("\n=======Method 2 (takes less space)=======\n");
	int min=0,max=INT_MIN;
	verticalOrderTraversal_2(root,horizontalDist,&min,&max);

	return 0;
}