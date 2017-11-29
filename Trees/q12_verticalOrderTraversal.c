/* VERTICAL ORDER TRAVERSAL

For this, we compute the horizontal distance of each node from the root.
Root's horizontal dist from root=0,
if we go left, we subtract 1 and if we go right , we add 1.

Thus the roots at the same horizontal distances form a vertical straight line.

Method 1: First find the range of the horizontal distances (say [-2,2]) using any traversal.
So, we do a traversal and keep computing the horizontal distance on the fly and keep updating
the min and max variable which will finally give the range.

Now, for every number in the range, call the traversal function and print the nodes with
horizontal dist = that number.

TC=O(n) to compute the range + k*O(n); where k=total numbers in the range
SC=O(n) taken by stack.
=============================================================================================
Method 2: Using a hash table and chaining
If we store the nodes in hash table along with computing the horizontal distance, then we can
save traversing the tree so many times.

Deciding hash table size: We know that the max range possible is -(n-1) to (n-1) if the tree
is left/right skewed.
So, we take a hash table of size 2(n-1)+1

Now, as we compute the horizontal dist of each node, add it to the Linked list corresponding
to that index in hash table.

TC=O(n) as tree is traversed atmost once + traversing the hash table in O(numbers in range)
=>TC=O(n)
SC=O(n) for stack and for hash table O(n)=O(n)
==============================================================================================
Method 3:OPTIMIZATION of method 2 by reducing the size of hash table.
Use a DOUBLY LINKED LIST in the place of using a hash table:-This can be created as we are 
computing the horizontal distance of nodes.
Refer to the diagram to see the structure of the DLL

TC=O(n) for single preorder traversal
SC=O(n) for stack and DLL
==============================================================================================
Method 4: Using level order traversal
http://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/
*/

#include <stdio.h>
#include <stdlib.h>

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
	//Flag h means this is the call to the root of the tree
	//Flag l means this is the call to the LST
	//Flag r means this is the call to the RST
	if(!head && flag=='h')
	{
		
		head=newDLLNode(hd,root->data);
		printf("Inside head:%d\n",head->index);
		ptr=head; 
	}
	printf("flag:%c\n",flag);
	if(flag=='l')
	{
		printf("Inside l:%d\n",head->index);
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
		else
		{
			// printf("In left: head->prev already present :%d\n",head->prev->index);
			insertInLL((head->prev->below),root->data);

		}
		
	}

	if(flag=='r')
	{
		if(!head->next)
		{
			head->next=newDLLNode(hd,root->data);
			head->next->prev=head;
			head=head->next;

		}
		else
		{
			insertInLL((head->next->below),root->data);
		}
		

	}

	printf("value:%d, hor dist:%d\n",root->data,hd);
	verticalOrderTraversal(root->left,head,hd-1,'l');

	verticalOrderTraversal(root->right,head,hd+1,'r');
	return ptr;
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
	printf("\nVertical order traversal:\n");

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

	return 0;
}