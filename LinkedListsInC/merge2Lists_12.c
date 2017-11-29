/*Merge two sorted LLs.
Method 1. Naive approach: For every element in first LL, find its appropriate
position in second LL (as in insertion sort). Then insert the node at its 
appropriate position.
LL1 size=m, LL2 size=n
For this, TC=O(mn)
SC=O(1)

Method 2: Like in merge sort.
First set the head to the smaller of two heads. - O(1)
Use three pointers: l1, l2 and temp, where li points to current node of LL1, l2 points 
to current node of LL2 and temp points to the node till where the list has been merged. - O(n+m)
TC=O(m+n) SC=O(1)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	char data;
	struct node *next;
	
};

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
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}

struct node * mergeSortedLists(struct node *head1,struct node *head2)
{
	struct node *l1, *l2, *temp;
	struct node *head=NULL;
	if(!head1 || !head2)
		return (!head1)? head2:head1;
	l1=head1;
	l2=head2;
	//First set the head to the smaller of two heads.	
	if(head1->data < head2->data)
	{
		head=head1;
		l1=l1->next;
	}
	else
	{
		head=head2;
		l2=l2->next;
	}
	
	
	temp=head;
	// printf("Merged list's head: %d\n",temp->data );
	// printf("l1: %d\n",l1->data );
	// printf("l2: %d\n",l2->data );
	while(l1 && l2)
	{
		if(l1->data<=l2->data)
		{
			temp->next=l1;
			l1=l1->next;
			temp=temp->next;
		}
		else
		{
			temp->next=l2;
			l2=l2->next;
			temp=temp->next;
		}
	}

	temp->next=(!l1)?l2:l1;
	// if(!l1)
	// 	temp->next=l2;
	// else
	// 	temp->next=l1;
	return head;
}

int main()
{
	struct node *head1=NULL;
	struct node *head2=NULL;
	struct node *head=NULL;
	// insertAtFront(&head1,5);
	//------------List 1-----------
	insertAtFront(&head1,10);
	insertAtFront(&head1,7);
	insertAtFront(&head1,6);
	//------------List 2-----------
	insertAtFront(&head2,21);
	insertAtFront(&head2,13);
	insertAtFront(&head2,11);
	insertAtFront(&head2,9);
	insertAtFront(&head2,8);
	insertAtFront(&head2,4);
	
	printf("%s\n","LL1 is:=============");
	traverseLL(&head1);
	printf("%s\n","LL2 is:=============");
	traverseLL(&head2);

	head=mergeSortedLists(head1,head2);
	printf("%s\n","After merging, LL is:=============");
	traverseLL(&head);
	
	return 0;
}
