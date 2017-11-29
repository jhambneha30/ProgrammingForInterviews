/*Merge sort on LL.
Method 1. 
Algorithm: - T(n)
(i) Divide the list into two halves. -O(n)
(ii) Sort the 1st half using merge sort. - T(n/2)
(iii) Sort the 2nd half using merge sort. - T(n/2)
(iv) Merge the first and second half - O(n)

The main difference between merge sort on arrays and LLs is step (i) which takes O(1) time for
arrays and O(n) for LLs.
Though asymptotically, TC=O(nlogn) for both arrays and LLs.

Note: To find the middle node, we can also use the slow fast pointer method (saves time).
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

struct node * getMiddleNode(struct node *head)
{
	struct node *ptr;
	int count=0,mid,index,flag=0;
	ptr=head;
	// if(!ptr && !ptr->next)
	// 	return NULL;
	while(ptr)
	{
		count++;
		ptr=ptr->next;
	}
	printf("count: %d\n",count);
	if(count<=1)
		return NULL;
	mid=ceil((double)count/2);
	printf("mid: %d\n",mid);
	ptr=head;
	
	for(index=1;index<mid;index++)
	{
		ptr=ptr->next;
	}
	printf("mid ptr: %c\n",ptr->data);
	return ptr;
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


struct node * mergeSortLL(struct node *h)
{

	struct node *mid, *h2=NULL;
	mid=getMiddleNode(h);

	if(!mid)
		return h;
	printf("In merge sort: %d\n",mid->data);
	h2=mid->next;
	mid->next=NULL;
	h=mergeSortLL(h);
	h2=mergeSortLL(h2);
	return mergeSortedLists(h,h2);
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
	while(p)
	{
		printf("%d\n",p->data);
		p=p->next;
	}
}



int main()
{
	struct node *head1=NULL;
	struct node *head=NULL;
	
	insertAtFront(&head1,4);
	insertAtFront(&head1,10);
	insertAtFront(&head1,11);
	insertAtFront(&head1,9);
	insertAtFront(&head1,7);
	insertAtFront(&head1,21);
	insertAtFront(&head1,6);
	
	
	printf("%s\n","LL1 is:=============");
	traverseLL(&head1);
	

	head=mergeSortLL(head1);
	printf("%s\n","After sorting, LL is:=============");
	traverseLL(&head);
	
	return 0;
}
