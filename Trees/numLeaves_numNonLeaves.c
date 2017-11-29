/* Count number of leaves in a binary tree
NL(T)=1; if T is a leaf
	 =NL(LST)+NL(RST); otherwise

=====================================================================
Count number of non leaves in a binary tree
NNL(T)=0;if T is a leaf
	  =1+NNL(LST)+NNL(RST); otherwise


In both the programs, every node is visited at most 3 times =>TC=3*n=O(n)
SC=O(ht) if tree is balannced, otherwise, O(n) if tree is skewed

So, TC=O(n)
	SC=O(n)
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node * createNode(int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
}

void insert_key(struct node **root,int data)
{
	
	if(!*root)
	{
		*root=createNode(data);
		return;
	}
	struct node *ptr=*root;
	//RECURSIVE VERSION
	if(data < ptr->data)
		insert_key(&(ptr->left),data);

	if(data > ptr->data)
		insert_key(&(ptr->right),data);

}

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}

int numLeaves(struct node *root)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return 1;
	else
		return (numLeaves(root->left)+numLeaves(root->right));
	
}

int numNonLeaves(struct node *root)
{
	if(!root)
		return 0;
	if(!root->left && !root->right)
		return 0;
	else
		return (1+numNonLeaves(root->left)+numNonLeaves(root->right));
}


int main() 	
{
	struct node *root=NULL;
	int num;

	insert_key(&root,50);
	insert_key(&root,30);
	insert_key(&root,20);
	insert_key(&root,40);
	insert_key(&root,70);
	insert_key(&root,60);
	insert_key(&root,80);
	insert_key(&root,90);
	insert_key(&root,75);
	inorder(root);
	num= numLeaves(root);
	printf("Number of leaves:%d\n",num);

	num= numNonLeaves(root);
	printf("Number of non-leaves:%d\n",num);
        	
}