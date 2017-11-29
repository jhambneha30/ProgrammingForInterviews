/* Print nodes k distance from root in a binary tree.
Method 1: Use preorder traversal (or any traversal) and keep track of the distance.
In case tthe distance is less than the required distance, keep calling the function on LST 
and RST. In case the distance becomes greater than the given distance don't make further 
calls to the LST and RST.

Time taken depends on the no. of nodes visited upto distance k. Every node is visited 3 times.
TC=3*(2^0+2^1+........2^k) = 3*O(2^k) [This is sum of GP]
So TC=O(2^k)
SC=ht of stack=O(k)
*/

#include <stdio.h>
#include <stdlib.h>

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

void nodesAtLevel(struct node *root, int l, int currLevel)
{
	if(!root)
		return;
	
		
	if(currLevel==l)
	{
		printf("%d  ",root->data);
	}
	if(currLevel<l)
	{
		++currLevel;
		if(root->left)
			nodesAtLevel(root->left,l,currLevel);
		if(root->right)
			nodesAtLevel(root->right, l,currLevel);
	}
}

int main()
{
	struct node *root=NULL;
	int level=0	;
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
	
	preorder(root);
	printf("\n");
	nodesAtLevel(root,level,0);
	// printf("Level of %d is: %d\n",key,level);
	
	return 0;
}