/* Find the lowest common ancestor for two given nodes in a binary tree.
Method 1:
Gind the paths till the given nodes and store them in an array. Now, keep comparing
the corresponding indices till the path becomes different. The last same element in both arrays
gives us the LCA.

One way to find the path to each of the nodes: DFS as it stores the path in a stack.

Second way is to use preorder traversal using a stack. For this, keep storing the unexplored
nodes in the stack.
Time taken= O(n) for preorder traversal and O(n) for array comparison => TC=O(n)
SC=O(ht)=O(n)

Method 2: Simultaneous search on LST and RSTor this, we follow a kind of preorder traversal
and return -1 if none of the nodes is found or the node itself (if it is found).

The idea is to traverse the tree starting from root. If any of the given keys (n1 and n2) 
matches with root, then root is LCA (assuming that both keys are present). If root doesn’t
match with any of the keys, we recur for left and right subtree. The node which has one key 
present in its left subtree and the other key present in right subtree is the LCA. 
If both keys lie in left subtree, then left subtree has LCA also, otherwise LCA lies in right 
subtree.
TC=O(n)


SC=O(ht)=O(n)

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

int push(int stack[],int top,int data)
{
	printf("top is:%d\n",top);
	if(top==MAX)
	{
		printf("Overflow in stack!\n");
		return;
	}
	stack[++top]=data;
	return top;
}

int pop(int stack[],int top)
{
	printf("top is:%d\n",top);
	int poppedData;
	if(top==-1)
	{
		printf("Underflow!\n");
		return;
	}
	poppedData=stack[top--];
	printf("popped data:%d\n",poppedData);
	return top;
}

int findPath(struct node *root,int path[],int key,int top)
{
	int res1=0,res2=0;
	if(!root)
		return -1;
	printf("Pushing %d\n",root->data);
	top=push(path,top,root->data);
	if(root->data==key)
	{
		return 1;
	}
	
	
	//Check if key is found in left or right subtree
	res1=findPath(root->left,path,key,top);
	printf("res1 for %d is:%d\n",root->data,res1);
	if(root->left && res1==1)
	{
		printf("hi left for:%d\n",root->data);
		return 1;
	} 

	res2=findPath(root->right,path,key,top);
	printf("res2 for %d is:%d\n",root->data,res2);
	if(root->right && res2==1)
	{
		printf("hi right for:%d\n",root->data);
		return 1;
	}
		

	printf("Popping %d\n",root->data);
	top=pop(path,top);
	return -1;

}

int findLCA_1(struct node *root,int p,int q)
{
	int path1[MAX],path2[MAX];
	int i=0;
	// printf("Result of finding 5:%d\n",findPath(root,path1,p,-1));
	// int j;
	// printf("Path1 is:\n");
	// for(j=0;j<MAX;j++)
	// {
	// 	printf("%d ",path1[j]);
	// }

	// printf("Result of finding 3:%d\n",findPath(root,path2,q,-1));
	// printf("Path2 is:\n");
	// for(j=0;j<MAX;j++)
	// {
	// 	printf("%d ",path2[j]);
	// }
	if(findPath(root,path1,p,-1)==1 && findPath(root,path2,q,-1)==1)
	{
		while(path1[i]==path2[i])
		{
			i++;
		}
	}
	return path1[i-1];
	
}

struct node* findLCA_2(struct node *root,int p,int q)
{
	struct node *res_left=NULL,*res_right=NULL;
	if(!root)
		return root;

	if(root->data==p || root->data==q)
	{
		return root;
	}


	res_left= findLCA_2(root->left,p,q);
	res_right= findLCA_2(root->right,p,q);
	printf("res_left @ root %d:%d\n",root->data,(res_left?res_left->data:-1));
	printf("res_right:%d\n",(res_right?res_right->data:-1));

	if(res_left && res_right)
		return root;

	return (res_left?res_left:res_right);

}

int main()
{
	struct node *root=NULL;
	root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    int p=4, q=2;
 	preorder(root);
 	printf("\n");
	int lca1=findLCA_1(root,p,q);
	printf("=======================LCA using method 1 is: %d\n",lca1);

	struct node* lca2=findLCA_2(root,p,q);
	printf("=======================LCA using method 2 is: %d\n",lca2->data);
	return 0;
}
