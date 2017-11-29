/*Find kth node from the end.
Method 1: Stepi: Traverse the entire list to find count - O(n)
Stepii: Compute placement of the element from start. - O(1)
Stepiii: Traverse the list till you reach the required element. - O(n)
TC=O(n)+O(n)=O(n) SC=O(1)

Method 2: Find the count of elts in LL and keep making a hash table for the elements' addreses,
find placement of kth node from end and go to this element in O(1) time using hash table.
This implementation is useful only when search has to be done multiple times. It is not optimal if 
search has to be done only once.
TC=O(n) SC=O(n)

Methd 3: Take two ptrs: p and q, initialize q to the kth position.
Now keep advancing both the pointers one node at a time till q reaches the end.
When q reaches last node, p will be at the position required.

*/

/*Find middle element
Method 1: Find the count of elts in LL, find mid and traverse till mid to print it.
TC=O(n)+O(n/2)=O(n) SC=O(1)

Method 2: Find the count of elts in LL and keep making a hash table for the elements' addreses,
find mid and got to middle element in O(1) time.
TC=O(n) SC=O(n)

Methd 3: Take two ptrs: slow and fast, fast traverses the LL by crossing two elements at a time.
When fast reached end (null), slow reaches middle.
Handle the conditions: k<n, k>n, k=n

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

void kthNodeFromEnd1(struct node **h,int k)
{
	struct node *ptr;
	ptr=*h;
	int count=0,pos;
	while(ptr)
	{
		ptr=ptr->next;
		count++;
	}
	printf("Count: %d\n",count);
	if(k<=count)
	{
		pos=count-k+1;
		ptr=*h;
		count=1;
		while(count!=pos)
		{
			ptr=ptr->next;
			count++;
		}
		printf("The reqd elt is: %d\n",ptr->data);
	}
	else
		printf("k is greater than count\n");
	
}

void kthNodeFromEnd2(struct node **h,int range,int k)
{
	struct node *ptr;
	ptr=*h;
	int count=0,pos;
	struct node *hash_table[range];
	while(ptr)
	{
		hash_table[(ptr->data)-1]=ptr;
		ptr=ptr->next;
		count++;

	}
	printf("Count: %d\n",count);
	if(k<=count)
	{
		pos=count-k+1;
		printf("Position: %d\n",pos);
		
		if(count%2)
			printf("The reqd elt is: %d\n",hash_table[pos]->data);
		else
			printf("The reqd elt is: %d\n",hash_table[pos-1]->data);
	}
	else
		printf("k is greater than count\n");
	
}

void kthNodeFromEnd3(struct node **h,int k)
{
	struct node *p,*q;
	p=*h;
	q=*h;
	int count=k;
	if(k<=0 || !p)
		printf("Meaningless!");	
	while(count && q)
	{
		q=q->next;
		count--;

	}
	if(!q)
		printf("k is greater tahn count and q is NULL\n");
	else
		printf("q is at: %d\n",q->data);
	while(q)
	{
		p=p->next;
		q=q->next;
	}
	
	if(q)
		printf("The reqd elt is: %d\n",p->data);
}

void insertAtFront(struct node **h,int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=item;
	new->next=NULL;
	if(*h==NULL)
	{
		*h=new;
	}
	else
	{
		new->next=*h;
		*h=new;
	}
}

void traverseLL(struct node **h)
{
	struct node* p=*h;
	printf("%s\n","LL is:=============");
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

int main()
{
	struct node *head;
	int k=7;
	insertAtFront(&head,5);
	insertAtFront(&head,4);
	insertAtFront(&head,3);
	insertAtFront(&head,2);
	insertAtFront(&head,1);
	insertAtFront(&head,21);
	printf("----------ODD COUNT---------\n");
	traverseLL(&head);
	
	printf("Method 1:----------------\n");
	kthNodeFromEnd1(&head,k);
	printf("Method 2:-----------------\n");
	kthNodeFromEnd2(&head,5,k);
	printf("Method 3:-----------------\n");
	kthNodeFromEnd3(&head,k);

	// printf("----------EVEN COUNT---------\n");
	
	// insertAtFront(&head,21);
	// traverseLL(&head);
	// printf("Method 1:-----------------\n");
	// findMiddle1(&head);
	// printf("Method 2:-----------------\n");
	// findMiddle2(&head,5);
	// printf("Method 3:-----------------\n");
	// findMiddle3(&head);
	return 0;
}