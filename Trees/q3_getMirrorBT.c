/* Find the mirror tree of the given tree.

1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
(2)  Call Mirror for right-subtree  i.e., Mirror(right-subtree)
(3)  Swap left and right subtrees.
          temp = left-subtree
          left-subtree = right-subtree
          right-subtree = temp

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

struct node * getMirror(struct node *root)
{
	if(!root)
		return root;
	
	//If root is not null
	getMirror(root->left);
	getMirror(root->right);
	struct node *temp;
	temp=root->left;
	root->left=root->right;
	root->right=temp;

	return root;
}


int main()
{
	struct node *root=NULL;
	

	root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 
	preorder(root);
	root=getMirror(root);
	preorder(root);
        	
}