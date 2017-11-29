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
	insertAtFront(&head,1);
	// insertAtFront(&head,4);
	insertAtFront(&head,10);
	insertAtFront(&head,3);
	insertAtFront(&head,5);

	traverseLL(&head);

	reverseLL(&head);

	traverseLL(&head);
	

	return 0;
}	