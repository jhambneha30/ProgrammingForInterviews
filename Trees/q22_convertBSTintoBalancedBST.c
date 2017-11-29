/* Convert a given binary search tree into balanced binary tree
Method 1:
If we build the balanced AVL tree nu traversing the given BST and applying rotations, then for each
insertion O(logn) time will be taken. 
TC=O(nlogn)
SC=O(n)
==========================================================================================
Method 2: (Optimized)
If rather we do an inorder traversal of the given BST to get a sorted list and then apply
binary search on it to build the balanced BST, we can do it in O(n) time.
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

struct node * buildBalancedBST(int arr[],int p,int q)
{
	int mid;
	if(p>q)
	{
		// printf("p>q, p is: %d, q: %d\n",p,q);
		return NULL;	
	}
	mid=(p+q)/2;
	printf("p<=q, mid is: %d,arr[mid]:%d\n",mid,arr[mid]);
		
	struct node *root=newNode(arr[mid]);
	root->left=buildBalancedBST(arr,p,mid-1);
	root->right=buildBalancedBST(arr,mid+1,q);

	return root;
}

int main()
{
	// int arr[]={5,10,20,30,40,50,55};
	// int size=sizeof(arr)/sizeof(arr[0]);
	// printf("size:%d\n",size);
	// int p=0,q=size-1;
	// struct node *root=NULL;
	// root=buildBalancedBST(arr,p,q);
	// printf("\nPreorder of tree:\n");
	// preorder(root);

}