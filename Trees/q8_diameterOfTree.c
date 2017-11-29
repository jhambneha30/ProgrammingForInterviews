/* Find the Diameter of a given binary tree.
Note: The diamaeter of atree might not be containing the root.

Method 1:
At every node, recursively compute the height of LST(h1) and height of RST(h1),
then the diameter = h1+h2+1
Use a global variable to store the diameter and update it when the new diameter is
greater than the old one.

In this method, we have two options: to include the root or to excude it.
At every root, we want to find three things: ht of left tree, ht of right tree and diameter
of tree.

TC=O(n) (because every node is visited atleast once.)
SC=O(ht)=O(n) for recursive version.
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

int max(int a, int b)
{
	return a > b? a: b;
}

int findDiameter(struct node *root,int *ht)
{
	int leftDia=0,rightDia=0;
	int leftHt=0,rightHt=0;
	//If node is a null
	if(!root)
	{
		*ht=0;
		return 0;
	}
	
	leftDia=findDiameter(root->left,&leftHt);
	rightDia=findDiameter(root->right,&rightHt);
	//Pointer to height is taken so that the value of height can be returned along with the diameter value.
	*ht=max(leftHt,rightHt)+1;
	return max(max(rightDia,leftDia),(1+leftHt+rightHt));
}

int main()
{
	struct node *root=NULL;
	int height=0;
	root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left=newNode(6);
	
	preorder(root);
	//First make sure that both the numbers are present in the BST, otherwise LCA gives wrong answers
	int diameter=findDiameter(root,&height);
	printf("Diameter: %d, Height: %d\n",diameter,height);
	
	return 0;
}