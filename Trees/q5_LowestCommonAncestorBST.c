/* Find the lowest common ancestor for two given nodes in a BST.

Method 1:
Traverse the path to both the nodes and store both the paths in two arrays. Now, keep comparing
the corresponding indices till the path becomes different. The last same element gives us the LCA.

It involves 2 searches (2*O(ht)=2*O(n)) and then traversing the arrays (=O(ht)=O(n))
TC=SC=O(n)

Method 2: Apply search simultaneously. Keep searching for both the lements and when the path
diverges, the last common node will be the LCA.

Note: We assume that both the given nodes are present in the BST.
NOTE: One corner case here is that when one of the nodes happens to be the LCA of both the nodes.
TC=O(ht)=O(n) - for unbalanced
SC=O(1) for iterative version, O(ht)=O(n) for recursive version

VARIATION: If the nodes in the BST have pointers to their parents, then how can you find the LCA?
SOLUTION: This problem is same as finding the merge point of two linked lists.
So, first traverse from root till both the given nodes. Then, subtract the lengths of two paths (=d).
On the longer path, move the pointer in the reverse direction steps=the difference (d) and then keep
comparing the corresponding nodes. When the first instance of nodes is same, that will be the
merge point or the LCA.

TC=O(ht)=O(n)
SC=O(1)
Note: This method is not an improvement, just a variation!



*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

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

int search(struct node *root,int item)
{
	if(!root)
		return 0;

	if(item<root->data)
		return search(root->left,item);
	if(item>root->data)
		return search(root->right,item);
	if(item==root->data)
		return 1;
	else
		return 0;
}

struct node* findLCARecursive(struct node *root, int num1, int num2)
{
	if(!root)
		return;

	if(root->data>num1 && root->data>num2)
	{
		// printf("Left: %d\n",root->left->data);
		return findLCARecursive(root->left,num1,num2);
	}
		
	if(root->data<num1 && root->data<num2)
	{
		// printf("Right: %d\n",root->right->data);
		return findLCARecursive(root->right,num1,num2);
	}

	return root;
}

int findLCAIterative(struct node *root, int num1, int num2)
{
	if(!root)
		return;
	while(root)
	{
		if(root->data>num1 && root->data>num2)
			root=root->left;
		else if(root->data<num1 && root->data<num2)
			root=root->right;
		else break;
	}

	return root->data;
}

int main()
{
	struct node *root=NULL,*lca;
	int p=9,q=13,num;

	insert_key(&root,20);
	insert_key(&root,7);
	insert_key(&root,21);
	insert_key(&root,3);
	insert_key(&root,11);
	insert_key(&root,9);
	insert_key(&root,13);
	
	inorder(root);
	//First make sure that both the numbers are present in the BST, otherwise LCA gives wrong answers
	if(search(root,p) && search(root,q))
	{
		lca= findLCARecursive(root,p,q);
		printf("RECURSIVE: LCA of %d and %d is: %d\n",p,q,lca->data);
		num= findLCAIterative(root,p,q);
		printf("ITERATIVE: LCA of %d and %d is: %d\n",p,q,num);
	}

	
	return 0;
}