/*Print nodes which are at k distance from a given key in a binary tree.


http://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
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

void nodesAtLevel(struct node *root, int targetDist, int currDist)
{
	if(!root)
		return;
	
	// printf("In old func: %d with targetDisr: %d\n",root->data, targetDist);
	if(currDist==targetDist)
	{
		printf("%d  ",root->data);
	}
	if(currDist<targetDist)
	{
		++currDist;
		if(root->left)
			nodesAtLevel(root->left,targetDist,currDist);
		if(root->right)
			nodesAtLevel(root->right, targetDist,currDist);
	}
}

int nodesAtDistK(struct node *root,int target,int k)
{
	if(!root)
		return -1;
	
	if(root->data==target)
	{
		return 0;
	}

	int dist_LST=nodesAtDistK(root->left,target,k);
	if(dist_LST!=-1) //It means that target is in the LST
	{
		if(dist_LST+1==k)
		{
			printf("%d  ",root->data);
		}
		else
			nodesAtLevel(root->right,k-dist_LST-2,0);
		return dist_LST+1;
	}
	
	int dist_RST=nodesAtDistK(root->right,target,k);
	if(dist_RST!=-1) //It means that target is in the RST
	{
		if(dist_RST+1==k)
		{
			printf("%d  ",root->data);
		}
		else
			nodesAtLevel(root->left,(k-dist_RST-2),0);
		return dist_RST+1;
	}
	//it is incomplete: write code to print 13 which is also at dist 3 from 5
    return -1;
}

int main()
{
	struct node *root=NULL;
	int target=5;
	root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);

    root->left->left->left  = newNode(9);
    root->left->left->right  = newNode(8);
    root->left->right->right = newNode(7);
    root->left->right->right->right = newNode(12);
    root->left->right->right->right->right = newNode(13);


	
	preorder(root);
	printf("\n");
	nodesAtDistK(root,target,3);
	
	return 0;
}