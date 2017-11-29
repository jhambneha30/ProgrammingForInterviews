/* Remove nodes on root to leaf paths of length < K.
Method 1:
Recursively remove the paths of length k-1 from the LSt and RST and so on. Keep subtracting 1
from k and keep recursively calling the LST and RSt till all the smaller paths are removed.
We follow POSTORDER TRAVERSAL here and if the LST and RST have vanished, then it means there
is no path of length k-1 in the LST or in RST, then we can remove root as there can be no path 
which will form a path of length k from the root.
Otherwise, do not delete the root.

TC=O(n)
SC=O(n)

Method 2:

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
struct node *removeSmallPaths(struct node *root,int k)
{
	if(!root)
		return root;
	if(k==0)
		return root;
	root->left=removeSmallPaths(root->left,k-1);
	root->right=removeSmallPaths(root->right,k-1);
	if(root->left==NULL && root->right==NULL)
	{
		free(root);
		return NULL;
	}
	return root;
}

struct node *removeSmallPaths_2(struct node *root,int k)
{
	if(!root)
		return root;
	if(!root->left && !root->right && k>=1)
	{
		free(root);
		return NULL;
	}

	root->left=removeSmallPaths_2(root->left,k-1);
	root->right=removeSmallPaths_2(root->right,k-1);

	return root;

}

int main()
{
	struct node *root=NULL;
	int k=2;
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
	printf("METHOD 1-Preorder of tree:\n");
	preorder(root);

	removeSmallPaths(root,k);
	printf("\nPreorder traversal after removing paths of length less than %d\n",k);

	preorder(root);
//------------------------------------------------------
	root=NULL;

	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
	printf("METHOD 2-Preorder of tree:\n");
	preorder(root);

	removeSmallPaths_2(root,k);
	printf("\nPreorder traversal after removing paths of length less than %d\n",k);
	preorder(root);
	return 0;
}