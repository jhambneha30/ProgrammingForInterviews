/*Form a balanced binary search tree from given sorted array.
Method 1:
Keep insering the nodes one by one from the array (logn for insert) and keep balancing the tree
at every insertion (O(1) for every node=>O(n) for n nodes)
TC=O(nlogn)+O(n)=O(nlogn)
SC=O(ht)=O(n) for stack

Method 2:
Make use of the sorted array rather than balancing the tree while inserting the nodes.
For this, go to the middle of the array first and make it the root. Then, go the left part of
the sorted array, go to its middle and amke it the left child of the root and so on.

Basically, we are using Divide and conquer paradigm and problem gets divided into 2 sub halves.

T(n)=1(to find middle)+T(n/2)++T(n/2) = O(n)

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
	int arr[]={5,10,20,30,40,50,55};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("size:%d\n",size);
	int p=0,q=size-1;
	struct node *root=NULL;
	root=buildBalancedBST(arr,p,q);
	printf("\nPreorder of tree:\n");
	preorder(root);

}