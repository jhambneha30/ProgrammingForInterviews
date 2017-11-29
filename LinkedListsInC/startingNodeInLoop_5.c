/*Find the firist node of the loop if a loop exists in a LL.

Method 1: Using hash table! Keep storing the addresses in the hash table and
as the address is stored, just check the next pointer. If it exists in the 
hash table already, it means there is a loop in the LL and the node with the
address in next is the first node in te loop.
TC=O(n) SC=O(n)

Methd 2: Use a structure for node which contains a Visited field. Initially it is 0.
The node which is getting re-visited for the first time, marks the starting of the loop.
So, we can also find the number of nodes involved in the loop and the starting node of the 
loop is the one where visited not equal to 0 for the first time.
TC=O(n), 1 bit for visited field -> n bits for n nodes.

Method 3: Floyd's cycle finding algorithm using slow and fast pointers. Refer to the 
screenshot named loopStartingNode in the folder git_prog. 
Step i) break the loop when slow and fast pointers meet.
Step ii) take the slow pointer to head of the LL again and start advancing both pointers 
one step at a time. Wherever they meet now, will e the first node of the loop in the LL.
Note: x= head to beginning of loop, y=beginning of loop to where fast and slow meet for 1st time.
z= fast to beginning of loop.
k= #rotations fast pointer makes befor meeting slow ptr for the first time.
l= #nodes/links in the loop.
TC=O(n) SC=O(1)





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

void findLoopStart3(struct node **h)
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
	{
		printf("Loop exists!\n");
		slow=*h;
		while(slow!=fast)
		{
			slow=slow->next;
			fast=fast->next;
		}
		printf("The starting node is: %d\n",slow->data);
			
	}
		
	else
		printf("No loop exists!\n");
}

//Method 4 won't work as we don't know the count of the LL in the beginning!
void findLoopStart4(struct node **h,int countTotal)
{
	struct node *slow, *fast;
	slow=fast=*h;
	int countLoop=0,pos;
	//Note: Don't write the condn slow!=fast in while loop coz loop break initially as slow=fast=*h initially!
	while(fast && fast->next && slow)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
			break;
	}

	if(slow==fast)
	{
		printf("Loop exists!\n");
		while(1)
		{
			slow=slow->next;
			fast=fast->next->next;
			countLoop++;
			if(slow==fast)
			{
				break;
			}
		}
		printf("Nodes in loop: %d\n",countLoop);
		pos=countTotal-countLoop+1;
		printf("The starting node is at: %d\n",pos);
			
	}
		
	else
		printf("No loop exists!\n");
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
	struct node *head=NULL;
	insertAtFront(&head,5);
	insertAtFront(&head,4);
	insertAtFront(&head,3);
	insertAtFront(&head,2);
	insertAtFront(&head,1);
	insertAtFront(&head,21);
	traverseLL(&head);
	int count=introduceLoopInLL(&head);
	// traverseLL(&head);
	
	
	
	printf("Method 3:-----------------\n");
	findLoopStart3(&head);
	//Below method won't work!
	printf("Method 4:-----------------\n");
	findLoopStart4(&head,count);

	return 0;
}