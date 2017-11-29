/*Merge k sorted LLs.
Method 1. Naive approach: Take 1st LL as reference and consider one element of eac list
one by one and locate its position in te reference list.
For this, TC=O(k^2n^2)
Suppose when half the lements have been examined => reference list's size is O(n/2k)
Then worst case TC=O(nk)* n/2*k=O(k^2n^2)
SC=O(1)

Method 2: Using Heaps. Use temp to point to end of merged list!
Take the 1st element of all the k lists and build a min heap (store data and address) - O(n)
Now delete min from heap and go to this node using its address, point temp to it and add
the next node's data and address in the heap.

When next time, min is deleted, point temp's next to this node. Now, add the next node of
this min node to the heap and heapify if required.
Point temp = temp->next.
NOTE: At any time, the elements in heap=k, except when the lists start exhausting. Then the
number of lists unexhausted would be= #elements in the heap left.

Algorithm-------------
Step (i) Construct min heap from the first elements of each list.
Step (ii) Delete min and add the next node to the heap if it exists.
Note: The first time the min is removed, make the head to point to it.
Step (iii) Append the deleted node tot he merged list.
Step (iv) Repeat step (ii) and (iii) until heap becomes empty!

Overall analysis: Every element has to be sent into the heap once and have to be removed
once. -O(logn) 
Then when an element is removed from heap, it is added to the list - O(1)
Initially heap is built on k elements - O(k), then for remaining kn-k elements, they are added
and deleted once from the list - O(kn(2logk))
Total TC= O(k)+O(knlogk)=O(knlogk)
SC=O(k)

Method 3: Divide and Conquer
Suppose there are 8 lists to be merged. Then in earlier approaches, we required to have all
the lists in the memory at the same tiime.
In Divide and conquer, we can do 2 way merging for which we need to keep 2 lists in the memory
at a time.
In this, the list gets merged into one list after log k steps (after 1st step, we get lists
of size 2n, then next level-4n, then last level-8n)
Now, 8n=2^xn => x=log 8
Now, amount of work done at each level = Total elements = kn 
So Total TC= kn* log k, SC=O(1)

Note: The heart of thhis algorithm is 2 way merging (merge2Lists_12.c)

Method 4: Using BST
Instead of using a min heap, we could use BST. The difference is if we use a BST, the problem
is that the BSt may not always be balanced. Sometimes, the BST is completely skewed due to
which certain operations like add, delete elements take O(k) instead of O(log k) time.
Thus TC worst case = O(nk^2)
So, using heaps is better in this case.

*/

//Implement using Divide and conquer! Method 3
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
