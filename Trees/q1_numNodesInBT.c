/* Program to count number of nodes in a binary tree OR Find the size of BT.
Method 1:
Use a global variable and keep counting the nodes while traversing
TC=O(n), SC=O(logn) if balanced, otherwise O(n)

Method 2:
Use recursion: NN(t)=1+NN(t->left)+NN(t->right)
It means: num=1+num in LSt+num in RST
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

struct node *find_max(struct node *root)
{
	struct node *result;
	if(!root)
		return root;
	if(root->right)
	{
		result= find_max(root->right);
	}
	else
		result=root;
	return result;
}

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
int find_numNodes(struct node *root)
{
	if(!root)
		return 0;
	else
	{
		return (1+find_numNodes(root->left)+find_numNodes(root->right));
	}
}

int main()
{
	struct node *root=NULL;
	int choice,index,key,num;
	printf("\n1. Insert key\t2. Delete Key\n");
    printf("3. Find min\t4. Inorder traversal\n");
    printf("5. Find max\t6. Find number of nodes\t7. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    struct node *res;
	while(choice!=7)
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
        		res=find_min(root);
        		printf("Min is:%d\n",res->data);
        		break;
        	case 4: 
				printf("Inorder traversal is:\n");
        		inorder(root);
        		break;
        	case 5: 
        		res=find_max(root);
        		printf("Max is:%d\n",res->data);
        		break;
        	
        	case 6: 
        		num=find_numNodes(root);
        		printf("Number of nodes in BST is:%d\n",num);
        		break;
        	case 7: 
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

