/*Check if a LL is a palindrome or not.
Method 1. (i) Clone the given list - O(n)
(ii) Reverse the cloned list. -O(n)
(iii) Compare the two lists: original and cloned. If both are same, LL is a palindrome. -O(n)
TC=O(n)+O(n)+O(n)=O(n)
SC=O(n) for cloning

Improvised approach: Step (iii) can be optimized by comparing only till the middle
of the two lists. For this while cloning, count the total elements in the list. Then
count the elements till half in the step (iii). half=floor(n/2)
But, this optimization won't give any asymptotic improvement in TC. It still remains O(n)

Method 2: 

Using stack instead of cloning to reverse the list.
(i)Push all elements into the stack. Also maintain count of nodes. - O(n)
(ii) While popping, check if the elements are equal. Do this for floor(n/2) elements. -O(n)
TC=O(n) SC=O(n) for stack

Method 3: Without using up space:
(i) Find the middle element - O(n)
(ii) Reverse the second half using iterative version - O(n/2)
Note: The recursive version takes up space!
(iii) Compare the first half with the second half of the list.
For n=odd, ignore the middle element => ceil(n/2)
For n=even, take mid=(n/2)

TC=O(n) SC=)(1)
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
		printf("%c\n",p->data);
		p=p->next;
	}
}

void reverseLL(struct node **h)
{
	struct node *prev, *curr, *nex;
	prev=NULL;
	curr=*h;
	while(curr)
	{
		// printf("Reversing: %c\n",curr->data);
		nex=curr->next;
		curr->next=prev;
		prev=curr;
		curr=nex;
	}
	*h=prev;



}

int compareLists(struct node *list1,struct node *list2)
{
	while(list2 && list1->data==list2->data)
	{
		list1=list1->next;
		list2=list2->next;
	}

	if(list2==NULL)
		return 1;

	return 0;
}

struct node * getMiddleNode(struct node *head)
{
	struct node *ptr;
	int count=0,mid,index,flag=0;
	ptr=head;
	while(ptr)
	{
		count++;
		ptr=ptr->next;
	}
	printf("count: %d\n",count);
	mid=ceil(count/2);
	printf("mid: %d\n",mid);
	ptr=head;
	
	for(index=1;index<mid;index++)
	{
		ptr=ptr->next;
	}
	// printf("mid ptr: %c\n",ptr->data);
	return ptr;
}

struct node * checkPalindrome(struct node *head)
{
	struct node *middleNode, *secondHalf, *ptr2;
	middleNode=getMiddleNode(head);
	// printf("mid ptr in main: %c\n",middleNode->data);
	secondHalf=middleNode->next;
	// printf("head data: %c\n",head->data);
	// printf("halfHead data: %c\n",secondHalf->data);\
	middleNode->next=NULL;
	reverseLL(&secondHalf);
	printf("Reversed LL is:\n");
	traverseLL(&secondHalf);
	
	//Compare with second half
	int res=compareLists(head,secondHalf);
	// printf("res: %d\n",res);
	if(res==1)
		printf("It is a palindrome!\n");
	else
		printf("OOPS! Not a palindrome!\n");

	reverseLL(&secondHalf);
	traverseLL(&secondHalf);
	middleNode->next=secondHalf;
	printf("head data: %c\n",head->data);

	return head;
	
}




int main()
{
	struct node *head1=NULL;
	struct node *head2=NULL;
	// insertAtFront(&head1,5);
	insertAtFront(&head1,'b');
	insertAtFront(&head1,'a');
	insertAtFront(&head1,'c');
	insertAtFront(&head1,'a');
	insertAtFront(&head1,'b');
	
	printf("%s\n","LL1 is:=============");
	traverseLL(&head1);

	head1=checkPalindrome(head1);
	printf("%s\n","After checking, LL1 is:=============");
	traverseLL(&head1);
	

	return 0;
}
