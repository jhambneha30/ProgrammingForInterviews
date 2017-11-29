/* Print the left view of a binary tree.
For this, we need to print the first node from left at every level.
We need to maintain 2 variable maxLevel and currentLevel. maxLevel stores the maximum
level visited till now while the currLevel stores the level of the current node. We follow
preorder traversal and at every node, we check if currLevel>maxLevel. If this is true,
then we print the node, otherwise we move on.

TC=O(n)
SC=O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
	int data;
	struct node *left, *right;
};

struct node * newNode(int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=data;
	new->left=NULL;
	new->right=NULL;
	return new;
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

void leftView(struct node *root,int currLevel,int *maxLevel)
{
	if(!root)
		return;
	//If it is the first time we aare visiting this level, then print the node
	if(currLevel>*maxLevel)
	{
		printf("%d ",root->data);
		*maxLevel=currLevel;
	}
	leftView(root->left,currLevel+1,maxLevel);
	leftView(root->right,currLevel+1,maxLevel);
}

int main()
{
	struct node *root=NULL;
	struct DLLnode *head=NULL;
	int currLevel=1,maxLevelReached=0;
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
	
	preorder(root);
	printf("\nLEFT VIEW:\n");

	leftView(root,currLevel,&maxLevelReached);
	
	
	return 0;
}