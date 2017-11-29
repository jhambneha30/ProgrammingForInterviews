/* Check whether the given two trees are mirrors or not.

For two trees ‘a’ and ‘b’ to be mirror images, the following three conditions must be true:

1. Their root node’s key must be same
2. Left subtree of root of ‘a’ and right subtree root of ‘b’ are mirror.
3. Right subtree of ‘a’ and left subtree of ‘b’ are mirror.

TC=O(n)
SC=O(n) if tree is skewed, O(log n) if balanced.
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

void getMirror(struct node **root)
{
	//We use post order traversal and we swap the LST and RST
	if(!*root)
		return;
	getMirror(*root->left);
	getMirror(*root->right);
	//Swap the left and right sub trees
	struct node *temp;
	temp=root->left;
	root->left=root->right;
	root->right=temp;
}

int isMirror(struct node *root1, struct node *root2)
{
	if(!root1 && !root2)
		return 1;
	if(root1 && root2)
	{
		return root1->data == root2->data
		&& isMirror(root1->left,root2->right)
		&& isMirror(root1->right,root2->left); 
	}
	return 0;
}


int main()
{
	struct node *root1=NULL;
	struct node *root2=NULL;
	int num;

	root1 = newNode(1);
    root2 = newNode(1);

    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);
 
    root2->left = newNode(3);
    root2->right = newNode(2);
    root2->right->left = newNode(5);
    root2->right->right = newNode(4);
	preorder(root1);
	preorder(root2);
	num=isMirror(root1,root2);
	if(num)
		printf("They are mirrors!\n");
	else
		printf("Not mirrors!\n");

	getMirror(&root);
	postorder(root);
        	
}