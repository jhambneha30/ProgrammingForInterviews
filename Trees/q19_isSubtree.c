/*Check whether a given binary tree is sub tree of another binary tree. 
Method 1:
We will be given with a sub tree and another big tree. Now we find the root of the subtree 
in the main tree and then check if the subtree rooted at that node is identical to given 
sub tree (by calling checkIdentical()). 
Note: The root of the sub tree might be present multiple times in the main tree.

TC=O(m*n)
In worst case, we might end up looking all the n nodes m times. m=number of times the root 
of the subtree is present in the main tree, so time taken to run checkIdentical()=m*O(n)
So, TC=O(n)+m*O(n)=O(m*n)

SC=O(ht of main tree taken by searchRoot())+O(ht of subtree in checkIdentical())=O(n)+O(p), 
where p=number of nodes in subtree
So, SC=O(m)+O(n
=============================================================================================
Method 2:
NOTE: The nodes of a subtree will always occur together in all the traversals.
Example: Pre - ABD(EFG)C, In - DB(FEG)AC, Post - D(FGE)BCA
The nodes of subtree EFG are occuring together in all the three traversals, just the order is
different. This is because the LST and RST are always together in all the three traversals. 

Now, for method 2, we need to find out any traversal of both the tree (pre_main[]) and 
the subtree(pre_sub[], say pre order traversal. Then, if pre_sub[] is a substring of pre_main[]
then the smaller tree MIGHT BE a subtree of the main tree. But to be sure, we need to check
another traversal, say inorder - in_main[] and in_sub[]. Again check if latter is a substring
of the former. If yes, then we are sure that the smaller tree is a subtree of the main tree.

TC=O(m+n)+O(m+n)=O(n) [Substring matching can be done in O(n) linear time, m=size of smaller tree]
SC=O(ht) for stack+O(n)for array+O(m) for smaller array=O(n)

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
int isIdentical(struct node *root, struct node *subRoot)
{

	if(!root && !subRoot)
		return 1;
	if(!root || !subRoot)
		return -1;
	// printf("in identical==this root data: %d, subroot:%d\n",root->data,subRoot->data);
	int res_left=isIdentical(root->left,subRoot->left);
	
	int res_right=isIdentical(root->right,subRoot->right);
	
	
	if(root->data==subRoot->data && res_left==1 && res_right==1)
		return 1;

	return 0;
}

int isSubtree(struct node *root, struct node *sub_root)
{
	int res;
	if(!root)
		return -1;
	// printf("this root data: %d, subroot:%d\n",root->data,sub_root->data);
	if(root->data==sub_root->data)
	{	
		// printf("inside this root data: %d, subroot:%d\n",root->data,sub_root->data);
		res=isIdentical(root,sub_root);
		// printf("root:%d and subroot: %d and isIdentical result: %d",root->data,sub_root->data,res);
		if(res==1)
			return 1;
	}

	int res_left=isSubtree(root->left,sub_root);
	int res_right=isSubtree(root->right,sub_root);
	if(res_left==1 || res_right==1)
		return 1;

	return -1;

}

int main()
{
	struct node *root=NULL;
	root = newNode(20);
    root->left = newNode(30);
    root->right = newNode(40);

    root->left->left  = newNode(45);
    root->left->right = newNode(45);
    root->right->right = newNode(45);

    root->left->left->left = newNode(50);
    root->left->right->left = newNode(50);
    root->left->right->right = newNode(57);
    root->right->right->left = newNode(80);
    root->right->right->right = newNode(100);

    root->left->left->left->left = newNode(67);
    root->left->right->left->left = newNode(67);

    struct node *sub_root=NULL;
    sub_root = newNode(45);

    sub_root->left = newNode(50);
    sub_root->right = newNode(57);
    sub_root->left->left = newNode(67);

    printf("\nPreorder of tree:\n");
	preorder(root);
	printf("\nPreorder of smaller tree:\n");
	preorder(sub_root);
	
	int result=isSubtree(root,sub_root);
	if(result==1)
		printf("\nSubtree exists!\n");
	else
		printf("\nSubtree does not exist!\n");
	return 0;
}