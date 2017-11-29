/* WAP to compute the height of a tree.
Note: Here we assume that height of leaf=0. (it will be mentioned in the question btw.)
HEIGHT OF A NODE: The length of the longest path from that node to a leaf.
HEIGHT OF ROOT= HEIGHT OF TREE

Recursive equation:
H(T)=0; if T is NULL
	=0; if T is a leaf
	=1+max(H(LST)+H(RST))
Note: We can use a ternary operator to compute max of l and r; where l=H(LST), r=H(RST)

TC=SC=O(n) as every node is visited at most 3 times!
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

int findHeight(struct node *root)
{

	if(!root)
		return 0;
	printf("root:%d\n",root->data);
	if(!root->left && !root->right)
		return 0;
	else
	{
		int l, r;
		l=findHeight(root->left);
		r=findHeight(root->right);
		return (1+ ((l>r)?l:r));
	}
	
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
	inorder(root);
	num= findHeight(root);
	printf("Height of tree is:%d\n",num);
        	
}