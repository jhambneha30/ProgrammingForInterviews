/*Check wheather given two nodes are cousins in a binary tree.
Method 1: Check whether both the given nodes are at the same level or not. If yes, then 
check if they are siblings or not by checking if their parents are same or not. If this other 
node is same as the node input by the user, then these are siblings
and not cousins, so return false. In case, they are not same, then they are cousins.

This method uses 2 functions: findLevel(root,node); areSiblings(root, node1,node2);

TC=O(n) for finding level + O(n) to check if they are cousins or siblings= O(n)
SC=O(ht) for stack

Method 2:
Use the Lowest Common Ancestor method to compute the LCA and also find the level of both the
nodes side by side. If the levels are same but LCA is not their parent, then they are cousins.

Corner case, if the input nodes x and y are such that x is parent of y, then LCA will stop when
it reaches x and won't go further down to find the level of y. We need to handle this case such 
that y is recursively called even if x is the LCA of both.

TC=O(n)
SC=O(n)

Method 3:
Call the function returnLevels which returns the levels of both the nodes as well as their
parents. If the levels are same, then check parents. If the parents are not same, then they
are cousins!

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

void returnLevels(struct node *root, int node1, int node2, int *level1, int *level2,
struct node **parent1, struct node **parent2, int currLevel,struct node *parent)
{
	if(!root)
		return;
	if(root->data==node1)
	{
		*level1=currLevel;
		*parent1=parent;
	}
		

	if(root->data==node2)
	{
		*level2=currLevel;
		*parent2=parent;
	}
		

	returnLevels(root->left,node1,node2,level1,level2,parent1,parent2,currLevel+1,root);

	returnLevels(root->right,node1,node2,level1,level2,parent1,parent2,currLevel+1,root);
}

int areCousins(struct node *root, int node1, int node2)
{
	int l1, l2;
	struct node *p1, *p2;
	returnLevels(root, node1, node2,&l1, &l2, &p1, &p2,1,NULL);
	if(l1==l2 && p1==p2)
	{
		printf("They are siblings!\n");
		return;
	}

	if(l1==l2 && p1!=p2)
	{
		printf("They are cousins!\n");
		return;
	}

	printf("They are unrelated!\n");
	return;

}

int main()
{
	struct node *root=NULL;
	root = newNode(20);
    root->left = newNode(30);
    root->right = newNode(40);

    root->left->left  = newNode(45);
    root->left->right = newNode(25);
    root->right->right = newNode(55);

    root->left->left->left = newNode(50);
    root->left->right->left = newNode(49);
    root->left->right->right = newNode(57);
    root->right->right->left = newNode(80);
    root->right->right->right = newNode(100);

    root->left->left->left->left = newNode(68);
    root->left->right->left->left = newNode(67);

    int node1=45,node2=25;

    printf("\nPreorder of tree:\n");
	preorder(root);
	
	areCousins(root,node1,node2);
	
	return 0;
}