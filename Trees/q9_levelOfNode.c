/* Find the level of a given node in a binary tree (root is at level 1 and leaves are at level log n).
This can be done using basic preorder traversal, in which:
1. Check if root->data==key
2. Go to LST to find the key
3. Go to RSt to find the key

TC=O(n) (because it is just manipulated preorder traversal)
SC=O(ht)=O(n) (because recursion stack might grow as big as the ht of tree which can be O(n))
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

int findLevel(struct node *root, int key, int level)
{
	if(!root)
		return -1;
	if(root->data==key)
	{

		return level;
	}
		
	
	int level2=findLevel(root->left,key,++level);

	//If the key has been found, then return the level, otherwise keep returning -1
	if(level2!=-1)
		return level2;
	//Only if the key hasn't been found, then only go to RST

	return findLevel(root->right, key,++level);
}

int main()
{
	struct node *root=NULL;
	int level=0,key=4;
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
	
	preorder(root);
	level=findLevel(root,key,1);
	printf("Level of %d is: %d\n",key,level);
	
	return 0;
}