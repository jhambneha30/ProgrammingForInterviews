/* BST: To make the search easier, we create balanced BSTs to get O(log n) TC. We don't 
need to visit every node to search for a particular node.
Note: When we talk of BSTs, we generally mean that the nodes are not repeated as the keys are
stored in BSTs.

INORDER TRAVERSAL OF A BST GIVED SORTED ORDER OF ELEMENTS.

DELETION:
a. Delete a leaf - directly delete it
b. Delete a non-leaf
	i. Having one child - Make the single child point to grand parent, then delete the node
	ii. Having two children - Here, the two children cannot directly go and attach to the 
	grand parent. There are two methods to do this:

	Method 1: Go to the RST and pick the smallest element to replace this node. The smallest
	element is also called the INORDER SUCCESSOR of the node to be deleted because if we
	write down the indorder traversal, then the smallest element of the RST will follow the node
	to be deleted.

	Method 2: Go to the LST and pick the largest element to replace this node. The largest
	element is also called the INORDER PREDECESSOR of the node to be deleted because if we
	write down the indorder traversal, then the largest element of the LST will follow the node
	to be deleted.

Que: When we find out the indorder successor of inorder predecessor of a node, then it will
either be a leaf or it will have a single child. It can never have two chhildren. Why?
Ans:If an inorder successor has a left child, it means the LSt contains even smaller elements
than the node we are claiming to be the inorder successor. This is not allowed. So, inorder
successor cannot have left child and for same reasons, the inorder predecessor cannot have a 
right child!
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


	//ITERATIVE VERSION
	// 
	// while(1)
	// {
	// 	if(data <= ptr->data)
	// 	{
	// 		if(ptr->left)
	// 			ptr=ptr->left;
	// 		else
	// 		{
	// 			ptr->left=new;
	// 			return;
	// 		}
				
	// 	}

	// 	if(data > ptr->data)
	// 	{
	// 		if(ptr->right)
	// 			ptr=ptr->right;
	// 		else
	// 		{
	// 			ptr->right=new;
	// 			return;
	// 		}
				
	// 	}
	// }

}

struct node *find_min(struct node *root)
{
	struct node *result;
	if(!root)
		return;
	if(root->left)
	{
		result= find_min(root->left);
	}
	else
		result=root;
	return result;
}

// int checkNodeType(struct node *p)
// {
// 	printf("hi\n");
// 	if(!p->left && !p->right)
// 		return 1;
// 	else if(p->left && p->right)
// 		return 2;
// 	else
// 		return 3;
// }

struct node* delete_key(struct node *root,int data)
{
	// base case
	if(!root)
		return root;

	// If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if(data<root->data)
    	root->left=delete_key(root->left,data);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if(data>root->data)
    	root->right=delete_key(root->right,data);

    //if root is same as key to be deleted, then delete this
    else
    {
    	//perform deletion according to the type of this key
    	struct node *temp;
    	// node with only right child or no child
    	if(!root->left)
    	{
    		temp=root->right;
    		free(root);
    		return temp;
    	}
    	// node with only left child or no child
    	else if(!root->right)
    	{
    		temp=root->left;
    		free(root);
    		return temp;
    	}

    	//node with two children: get inorder successor (smallest in RST)
    	temp=find_min(root->right);
    	root->data=temp->data;
    	root->right=delete_key(root->right,temp->data);
    }

    return root;

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

void inorder(struct node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d  ",root->data);
		inorder(root->right);
	}
}

void postorder(struct node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d  ",root->data);
	}
}

int main()
{
	struct node *root=NULL;
	int choice,index,key;
	printf("\n1. Insert key\t2. Delete Key\n");
    printf("3. Preorder traversal\t4. Inorder traversal\n");
    printf("5. Postorder traversal\t6. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    struct node *res;
	while(choice!=6)
	{
		
        switch (choice) 
        {
        	case 1: 
    			printf("Enter the key to be inserted.\n");
        		scanf("%d",&key);
        		printf("key: %d\n",key);
        		insert_key(&root,key);
        		break;
        	case 2:
        		printf("Enter the key to be deleted.\n");
        		scanf("%d",&key);
        		printf("key: %d\n",key);
        		// res=find_min(root);
        		// printf("Min is:%d",res->data);
        		delete_key(root,key);
        		break;
        	
        	case 3: 
        		printf("Preorder traversal is:\n");
        		preorder(root);
        		break;
        	case 4: 
				printf("Inorder traversal is:\n");
        		inorder(root);
        		break;
        	case 5: 
        		printf("Postorder traversal is:\n");
        		postorder(root);
        		break;
        	
        	case 6: 
        		printf("BYE");
        		exit(0);
        		break;
        	default:
            	printf("Wrong option!!\n");
           		break; 	
        }
        printf("Enter your choice:");
    	scanf("%d", &choice);
	}

	return 0;
}