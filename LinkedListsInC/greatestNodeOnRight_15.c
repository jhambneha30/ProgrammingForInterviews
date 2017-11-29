/*Consider a single LL with each node having an arbitrary pointer with initial value  NULL.
Give an algorithm to make the arbitrary pointer point to the greatest value node in a LL on
its right side.

Method 1: Naive approach:
For every element in the list, traverse the right side of the list to find the largest element.
TC= (n-1) + (n-2) +..........+1 = O(n^2)

Method 2: Using reversal
(i) Reverse the LL. - O(n)
(ii) Maintain a pointer to the largest element till this node and make this node point to the
largest element. - O(n)
(iii) Reverse the LL. - O(n)

TC=O(n)
SC=O(1)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
	struct node *arbitrary;
	struct node *prev;
};

struct node * setArbitrary(struct node *h)
{
	struct node *ptr,*largest;
	ptr=h;
	largest=ptr;
	ptr=ptr->next;

	while(ptr)
	{
		ptr->arbitrary=largest;
		// printf("arbitrary yo: %d\n",ptr->arbitrary->data);
		if(largest && ptr->data>largest->data)
			largest=ptr;
		ptr=ptr->next;
		
	}
	return h;
}
void reverseLL(struct node **h_addr)
{
	printf("%s\n","Reversing......");
	struct node *curPtr, *prevPtr, *nextPtr;
	curPtr=*h_addr;
	prevPtr=NULL;
	while(curPtr)
	{
		nextPtr=curPtr->next;
		curPtr->next=prevPtr;
		prevPtr=curPtr;
		curPtr=nextPtr;

	}
	*h_addr=prevPtr;
}

void insertAtFront(struct node **h,int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=item;
	new->arbitrary=NULL;
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
		if(p->arbitrary)
			printf("arbitrary: %d\n",p->arbitrary->data);
		p=p->next;
	}
}

int main()
{
	struct node *head;
	insertAtFront(&head,1);
	insertAtFront(&head,10);
	insertAtFront(&head,3);
	insertAtFront(&head,5);
	// insertAtFront(&head,1);

	traverseLL(&head);

	reverseLL(&head);

	traverseLL(&head);

	head=setArbitrary(head);
	reverseLL(&head);
	traverseLL(&head);

	return 0;
}
