/* Count number of full nodes in a binary tree
A full node is one which has all possible children.
Note: Full nodes is a subset of non leaves! But, not every non leaf is a full node.

NFN= 0;if T is NULL
	 0; if T is a leaf
	 1+NFN(LST)+NFN(RST); if T is a full node                     -------------(i)
	 0+NFN(LST)+NFN(RST); if T has one child either left or right!-------------(ii)

Note: The last decision - (i) and (ii) can be made by using aternary operator
It means:  (i) and (ii) can be combined using this statement:
NFN=NFN(LST)+NFN(RST)+(t->left && t->right)?1:0

=========================================================================================
Count number of non full nodes.

NNFN=NN-NFN

TC=SC=O(n) for both the programs!
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

int findFullNodes(struct node *root)
{

	if(!root)
		return 0;
	if(!root->left && !root->right)
		return 0;
	else if(root->left && root->right)
		return (1+ findFullNodes(root->left)+findFullNodes(root->right));
	else
		return (findFullNodes(root->left)+findFullNodes(root->right));

	
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
	num= findFullNodes(root);
	printf("Number of full nodes is:%d\n",num);
        	
}