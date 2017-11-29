/* Convert a binary tree into double linked list inplace in such a way that the order of nodes 
in double linked list represents the inorder traversal of binary tree

Method 1: Out of place
As we keep traversing in order, we keep adding new nodes in the DLL.

Method 2:
1. Convert the LST into a DLL.
2. convert the RST into a DLL. 
3. Now, take the left DLL and root and right DLL and merge them such that the root is in the 
middle.
Keeping the root in the center is important as we have to follow the inorder traversal.

Time taken = T(n/2) to visit the LST  + T(n/2) to visit the RST + O(n) time taken to traverse 
the DLLs.
TC=O(n^2)
Another way to think is: It traverses O(ht)*n, O(n) to traverse the intermediate double linked 
lists => TC=O(n^2)
SC=O(1)

Method 3: Optimization of method 2
NOTE: THE BELOW METHOD IS USED TO "Convert a Binary Tree to a Circular Doubly Link List"
We can remove the O(n) time taken to traverse the DLL to reach the head or tail (depending on
whether it is the LST or RST). This can be done by returning the pointers to head and tail of 
the DLLs at each step rather than returning the pointer to the middle(root).

With this, the time taken reduces to: T(n/2) to visit the LST  + T(n/2) to visit the RST 
+ O(1) time taken to merge the DLLS and the root. 
TC=O(n)
SC=O(ht)=O(n) in worst case

OPTIMIZATION: Rather than returning both head and tail, it is better to make the tail point 
to the head and return the tail. So, we need to return just one value!
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 20

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


struct node * convertToCircularDLL(struct node *root)
{
	struct node *leftDLL, *rightDLL;
	struct node *head, *tail;
	
	if(!root)
		return root;

	if(!root->left && !root->right)
	{
		root->right=root;
		return root;
	}
		
	if(root->left)
	{
		leftDLL=convertToCircularDLL(root->left);
		head=leftDLL->right;
		leftDLL->right=root;
		root->left=leftDLL;
	}
	
	if(root->right)
	{
		rightDLL=convertToCircularDLL(root->right);
		tail=rightDLL;
		root->right=rightDLL->right;
		rightDLL->right->left=root;
	}
	
	
	tail->right=head;
	return tail;
}

struct node * convertToDLL_1(struct node *root)
{
	struct node *leftDLL, *rightDLL;
	
	if(root->left)
	{
		leftDLL=convertToDLL_1(root->left);
		while(leftDLL->right)
		{
			leftDLL=leftDLL->right;
		}
		leftDLL->right=root;
		root->left=leftDLL;
	}
	if(root->right)
	{
		rightDLL=convertToDLL_1(root->right);
		while(rightDLL->left)
		{
			rightDLL=rightDLL->left;
		}
		rightDLL->left=root;
		root->right=rightDLL;
	}
	return root;

}

int main()
{
	//Structure for DLL function
	struct node *rootDLL;
	
	struct node *root=NULL;
	root = newNode(4);

    root->left = newNode(2);
    root->right = newNode(7);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    root->right->left  = newNode(6);
    root->right->right = newNode(8);

 	preorder(root);
 	printf("\n");
 	rootDLL=convertToDLL_1(root);
 	struct node *temp=rootDLL;
 	while(temp)
 	{
 		printf("%d  ",temp->data);
		temp=temp->right;
 	}

 	printf("\nMethod 2\n");
 	//Structures for circular DLL
 	struct node *root2=NULL, *head, *tail;
	root2 = newNode(4);

    root2->left = newNode(2);
    root2->right = newNode(7);
    root2->left->left  = newNode(1);
    root2->left->right = newNode(3);
    root2->right->left  = newNode(6);
    root2->right->right = newNode(8);

 	preorder(root2);
 	printf("\n");
	tail=convertToCircularDLL(root2);
	head=tail->right;
	tail->right=NULL;
	struct node *ptr=head;
	while(ptr)
	{
		printf("%d  ",ptr->data);
		ptr=ptr->right;
	}
	// Sprintf("=======================LCA using method 1 is: %d\n",lca1);

	return 0;
}
