/*Find middle element
Method 1: Find the count of elts in LL, find mid and traverse till mid to print it.
TC=O(n)+O(n/2)=O(n) SC=O(1)

Method 2: Find the count of elts in LL and keep making a hash table for the elements' addreses,
find mid and got to middle element in O(1) time.
TC=O(n) SC=O(n)

Methd 3: Take two ptrs: slow and fast, fast traverses the LL by crossing two elements at a time.
When fast reached end (null), slow reaches middle.

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

void findMiddle1(struct node **h)
{
	struct node *ptr;
	ptr=*h;
	int count=0;
	while(ptr)
	{
		ptr=ptr->next;
		count++;
	}
	printf("Count: %d\n",count);

	int mid=ceil(count/2);
	count=0;
	ptr=*h;
	while(count!=mid)
	{
		ptr=ptr->next;
		count++;
	}
	printf("The mid elt is: %d\n",ptr->data);
}

void findMiddle2(struct node **h,int range)
{
	struct node *ptr;
	ptr=*h;
	int count=0;
	struct node *hash_table[range];
	while(ptr)
	{
		hash_table[(ptr->data)-1]=ptr;
		ptr=ptr->next;
		count++;

	}
	printf("Count: %d\n",count);

	int mid=ceil(count/2);
	printf("Mid: %d\n",mid);
	if(count%2)
		printf("The mid elt is: %d\n",hash_table[mid]->data);
	else
		printf("The mid elt is: %d\n",hash_table[mid-1]->data);
}

void findMiddle3(struct node **h)
{
	struct node *slow,*fast;
	slow=*h;
	fast=*h;
	while(fast && fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;

	}
	
	printf("The mid elt is: %d\n",slow->data);
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
	insertAtFront(&head,5);
	insertAtFront(&head,4);
	insertAtFront(&head,3);
	insertAtFront(&head,2);
	insertAtFront(&head,1);
	printf("----------ODD COUNT---------\n");
	traverseLL(&head);
	
	printf("Method 1:----------------\n");
	findMiddle1(&head);
	printf("Method 2:-----------------\n");
	findMiddle2(&head,5);
	printf("Method 3:-----------------\n");
	findMiddle3(&head);

	printf("----------EVEN COUNT---------\n");
	
	insertAtFront(&head,21);
	traverseLL(&head);
	printf("Method 1:-----------------\n");
	findMiddle1(&head);
	printf("Method 2:-----------------\n");
	findMiddle2(&head,5);
	printf("Method 3:-----------------\n");
	findMiddle3(&head);
	return 0;
}