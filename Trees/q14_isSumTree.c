/*Check wheather the given binary tree is sum tree or not.
if the node's data = sum of all nodes' data of LST and RST

Method 1: Postorder traversal in which printing the root can be replaced by summing the 
LST_sum and RST_sum.



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

int isSumTree(struct node *root)
{
	int leftSum=0;
	int rightSum=0;
	if(!root)
		return 0;

	if(!root->left && !root->right)
	{
		printf("Leaf is: %d\n", root->data);
		return root->data;
	}
		
	
	leftSum=isSumTree(root->left);
	printf("For root: %d, leftSum=%d, rightSum=%d\n",root->data,leftSum,rightSum);
	rightSum=isSumTree(root->right);
	printf("For root: %d, leftSum=%d, rightSum=%d\n",root->data,leftSum,rightSum);
	if(leftSum==-1 || rightSum==-1)
	{
		return -1;
	}
		

	if((leftSum+rightSum)==root->data)
	{
		return 2*root->data;
	}
		

	return -1;	
	
}

int main()
{
	struct node *root=NULL;
	int sum=0;
	root = newNode(50);
    root->left = newNode(15);
    root->right = newNode(10);

    root->left->left  = newNode(10);
    root->left->right = newNode(5);
    root->right->left  = newNode(7);
    root->right->right = newNode(3);
	
	preorder(root);
	sum=isSumTree(root);
	if(sum==(2*root->data))
		printf("It is SUM TREE with sum=%d!\n",sum);
	else
		printf("Not a SUM TREE! sum=%d!\n",sum);
	
	return 0;
}