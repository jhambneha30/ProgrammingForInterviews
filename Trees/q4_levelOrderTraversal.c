/* LEVEL ORDER TRAVERSAL:
Push the root into a queue, then dequeue.
Enqueue the children of the root into the queue, then dequeue. As the nodes are being dequeued,
enqueue the children of these nodes.
and so on.............

Note: The order of children should be first left and then right.

TC=O(n)
SC=O(n/2)=O(n), because the number of nodes present in the queue at any level=n/2 (in the last level).

NOTE: LEVEL ORDER TRAVERSAL in trees ~ BFS in graphs (because both use queues)
	  PREORDER/INORDER/POSTORDER in trees ~ DFS in graphs (because both use stacks)

	  The only difference is that in case of trees, the left to right order of nodes has to be
	  preserved.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

struct node
{
	int data;
	struct node *left, *right;
};

int front=0,rear=0;
struct node *queue[MAX];
void enqueue(struct node *item)
{
	int n=MAX;
	//check overflow
	if(((rear+1) % n)==front)
	{
		// printf("front: %d, rear: %d\n",front,rear);
		printf("Overflow!\n");
		return;
	}
	rear=(++rear % n);
	// printf("rear: %d\n",rear);
	queue[rear]=item;
	// printf("Enqueued!\n");
}

struct node* dequeue()
{
	int n=MAX;
	struct node *temp;
	if(front==rear)
	{
		// printf("front: %d, rear: %d\n",front,rear);
		printf("Underflow!\n");
		return NULL;
	}
	temp=queue[++front];
	// printf("front: %d\n",front);
	return temp;
}



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


void levelOrder(struct node *root)
{
	if(!root)
		return;
	struct node *t;
	enqueue(root);
	while(front!=rear)
	{
		t=dequeue();
		if(!t)
			break;
		printf("%d  ",t->data);
		if(t->left)
			enqueue(t->left);
		if(t->right)
			enqueue(t->right);
	}
}

int main()
{
	struct node *root=NULL;
	root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
 	preorder(root);
 	printf("\n");
	levelOrder(root);
	return 0;
}
