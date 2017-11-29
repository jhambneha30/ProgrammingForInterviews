/*Find the intersection point of two linked lists:
Method 1. Naive/ Brute force: For every element of 1st LL, check if any element of
second list has same address or not.

Method 2: Using hash table. TC=O(n) best case, TC=O(n+m)=O(max(n,m)) worst case
Method 3: Find the length of both the lists.
In the longer list, leave the 1st x elements where x=difference between 
the lengths of two lists

Method 4: Use two stacks. Put the adresses of the nodes of both the lists in two 
diff stacks. Now start popping the addresses till they are same. When the addresses
popped are different, the last same address will be the starting of the common part of 
the linked list.

Method 5: Introduce a loop by pointing the end of the lists to the start of one of the
lists. The ques becomes same as finding the starting point of the loop which we did
earlier. Just make sure to remove the loop by remembering the last node's address and 
making it point to null after computing the answer.

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

void findIntersection3(struct node **h1, struct node **h2)
{
	struct node *ptr1, *ptr2;
	ptr1=*h1;
	ptr2=*h2;
	int count1=1,count2=1,diff;

	while(ptr1->next)
	{
		ptr1=ptr1->next;
		count1++;
	}
	while(ptr2->next)
	{
		ptr2=ptr2->next;
		count2++;
	}
	diff=abs(count1-count2);
	printf("count1,count2,diff: %d %d %d\n",count1,count2,diff);
	ptr1=(count1>count2)?*h1:*h2;
	ptr2=(count1<=count2)?*h1:*h2;
	printf("Larger list is: %d\n",ptr1->data);
	while(diff)
	{
		ptr1=ptr1->next;
		diff--;
	}
	while(ptr1 && ptr2)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next;
		if(ptr1==ptr2)
			break;
	}

	printf("The intersection point is: %d\n",ptr1->data);
}


void mergeLL(struct node **h1, struct node **h2)
{
	struct node *ptr1, *ptr2;
	ptr1=*h1;
	ptr2=*h2;
	int i;
	while(ptr2->next)
	{
		ptr2=ptr2->next;
	}
	for(i=0;i<3;i++)
	{
		ptr1=ptr1->next;
	}
	ptr2->next=ptr1;
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
	struct node *head2=NULL;
	insertAtFront(&head1,5);
	insertAtFront(&head1,4);
	insertAtFront(&head1,3);
	insertAtFront(&head1,2);
	insertAtFront(&head1,1);
	insertAtFront(&head1,21);
	printf("%s\n","LL1 is:=============");
	traverseLL(&head1);


	insertAtFront(&head2,100);
	insertAtFront(&head2,400);
	insertAtFront(&head2,300);
	insertAtFront(&head2,200);
	printf("%s\n","LL2 is:=============");
	traverseLL(&head2);
	mergeLL(&head1,&head2);
	

	printf("LL1 is:\n");
	traverseLL(&head1);

	printf("LL2 is:\n");
	traverseLL(&head2);
	
	
	
	printf("Method 3:-----------------\n");
	findIntersection3(&head1,&head2);
	

	return 0;
}
