/*Find if a loop exists in a LL.
Method 1: Find if the next of any node, contains the address of the current node.
It works only if the loop comes back to the first node, otherwise it is stuck in an infinite loop.
TC=O(n) SC=O(1)

Method 2: Using hash table! Keep storing the addresses in the hash table and
as the address is stored, just check the next pointer. If it exists in the 
hash table already, it means there is a loop in the LL.
TC=O(n) SC=O(n)

Methd 3: Use a structure for node which contains a Visited field. Initially it is 0.
The node which is getting re-visited for the first time, marks the starting of the loop.
So, we can also find the number of nodes involved in the loop.
TC=O(n), 1 bit for visited field -> n bits for n nodes.

Method 4: Floyd's cycle finding algorithm using slow and fast pointers.


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	int visited;
	struct node *next;
	
};

// void checkLoop2(struct node **h, int llCount)
// {
// 	struct node *ptr;
// 	ptr=*h;
// 	struct node *hash_table[llCount];
// 	for(int i=0;i<llCount;i++)
// 	{
// 		if(hash_table() contains the next of this node, then loop exists. so, break!
// 		hash_table[i]=ptr;
// 		ptr=ptr->next;
// 	}

// }

void checkLoop3(struct node **h)
{
	struct node *ptr;
	ptr=*h;
	while(ptr && !ptr->visited)
	{
		ptr->visited=1;
		ptr=ptr->next;
	}

	if(ptr)
		printf("Loop exists! \n");
	else
		printf("No loop exists!\n");


}

void checkLoop4(struct node **h)
{
	struct node *slow, *fast;
	slow=fast=*h;
	//Note: Don't write the condn slow!=fast in while loop coz loop break initially as slow=fast=*h initially!
	while(fast && fast->next && slow)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			break;
	}

	if(slow==fast)
		printf("Loop exists!\n");
	else
		printf("No loop exists!\n");
}

void insertAtFront(struct node **h,int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=item;
	new->next=NULL;
	new->visited=0;
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

int introduceLoopInLL(struct node** h)
{
	struct node *loopStart, *loopEnd;
	loopStart=*h;
	loopEnd=*h;
	int count=1;
	while(loopEnd->next)
	{
		loopEnd=loopEnd->next;
		count++;
	}
	printf("Count: %d\n",count);
	if(count>1)
	{
		loopEnd->next=loopStart;
	}

	return count;

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
	insertAtFront(&head,21);
	traverseLL(&head);
	// int count=introduceLoopInLL(&head);

	
	
	// printf("Method 1:----------------\n");
	// checkLoop2(&head,count);
	printf("Method 3:-----------------\n");
	checkLoop3(&head);
	printf("Method 4:-----------------\n");
	checkLoop4(&head);

	return 0;
}