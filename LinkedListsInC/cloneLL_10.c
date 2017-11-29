/*A nodw in a LL contains thre fields: data, random pointer and next pointer. Give 
an algo for cloning the list.
Method 1. Naive/ Brute force: Clone the LL without random pointer. Then, or every
element of 1st LL, check the random pointer and in 2nd LL set the random pointer to
address of the appropriate node.
This means for every node in LL, we need to search the complete 2nd list =>
TC=n*O(n)=O(n^2)
SC=O(1) because we should not include the output space in space complexity!
Disadvantages: High TC and does not work for duplicate data values.

Method 2: Using hash table. Maintain a mapping between the new node's address and the
old node's address in a hash table where key is old node's address and value is 
new node's address. TC=O(n) best case

After making the new list, we need to update the random pointer in the new list. For this,
we traverse the old list and check its random pointer. Then, we check the mapping of 
the old to new address, go to the new list's corresponding node and update the random
pointer by the new address of the random pointer node (for this, hash table is used).
TC=O(n)+O(n)=O(n), SC=O(n) for hash table

Method 3: Instead of maintaining the mapping in a hash table, mapping is maintained
using the random and next fields of the original list.
Step 1. Copy the data onto the new list. While doing this, maintain a temp which
contains address of the next node in the original list. Make the next of current node
point to the new list's current node. Make the random of the new node point to the old
list's current node. Do this for all the nodes while making the new list.
Step 2. Now, to update the random pointers of the new list, use the random pointer of
the new list's node to go to the old node, then go to the random pointe of the old node.
From there, go to the new address of this randomly pointed node (say x). Update the new list's
current node's random field with this address x. Then move forward in the new list.
TC=O(n)+O(n)
 SC=O(1)

Disadvantages: Original list is completely lost.

Method 4: Add the new nodes at even positions in the original list.
 old node1 -> new node1 ->old node2 -> new node2->NULL
 The new list will comntain 2n nodes (old list had n nodes say).

 Now, run a loop to update the random ptrs of the new nodes. For this, go to the
 odd nodes only and use ptr->next->random=ptr->random->next.

 After this is done, use the alternating split algo to split the lists into new 
 and old lists. The list at odd positions is the old list and at even positions is
 the new list!
 TC=O(n)+O(n)+O(n)
 SC=O(1)

*/

 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *random;
	struct node *next;
	
};

void splitAlternateLLs(struct node **h_odd,struct node **h_even)
{
	struct node *ptr, *temp;
	ptr=*h_odd;

	if(*h_odd==NULL)
		printf("LL is empty");
	else if(ptr->next==NULL)
		printf("Single element in LL");
	else
	{
		*h_even=ptr->next;
		printf("hie %d,%d\n",ptr->data,ptr->next->data);
		while(ptr->next)
		{
			temp=ptr->next;
			printf("hie22 %d,%d\n",ptr->data,temp->data);
			if(ptr->next->next)
			{
				ptr->next=ptr->next->next;
			}	
			else
			{
				ptr->next=NULL;
				temp->next=NULL;
			}
				
			
			ptr=temp;

		}

	}
}

struct node * insertAtEnd(struct node **head,int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=item;
	new->next=NULL;
	new->random=NULL;
	struct node *ptr=*head;
	if(!ptr)
	{
		*head=new;
	}
	else if(!ptr->next)
	{
		ptr->next=new;
	}
	else
	{
		while(ptr->next)
		{
			ptr=ptr->next;
		}
		ptr->next=new;
	}
	return new;
}

struct node * cloneLL3(struct node **h)
{
	struct node *new_h=NULL;
	struct node *ptr, *temp;
	ptr=*h;
	struct node *new_ptr;
	while(ptr)
	{
		temp=ptr->next;
		printf("ptr's data: %d\n",ptr->data);
		new_ptr=insertAtEnd(&new_h,ptr->data);
		printf("new ptr's data: %d\n",new_ptr->data);
		ptr->next=new_ptr;
		new_ptr->random=ptr;
		ptr=temp;
	}

	//Set up the random pointers in the new cloned LL.
	ptr=new_h;
	while(ptr)
	{
		if(ptr->random->random)
			ptr->random=ptr->random->random->next;
		else
			ptr->random=NULL;
		ptr=ptr->next;
	}
	return new_h;

}

void cloneLL4(struct node **h)
{
	
}

void makeRandomLL(struct node **h)
{
	struct node *ptr1, *ptr2;
	ptr1=*h;
	ptr2=*h;
	while(ptr1->data!=3)
	{
		ptr1=ptr1->next;
	}
	ptr2->random=ptr1; //node 1 points to node 3 through random
	ptr1=ptr1->next; //ptr1 reaches 4
	ptr2=ptr2->next; //ptr2 reaches 2
	ptr1->random=ptr2; //node 4 randomly points to node 2
}

void insertAtFront(struct node **h,int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node*));
	new->data=item;
	new->next=NULL;
	new->random=NULL;
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
		if(p->random)
			printf("Random: %d\n",p->random->data);
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
	// insertAtEnd(&head1,3);
	// insertAtEnd(&head1,4);
	// insertAtEnd(&head1,5);
	// insertAtEnd(&head1,6);
	// insertAtFront(&head1,21);
	printf("%s\n","LL1 is:=============");
	traverseLL(&head1);

	struct node *head3=NULL;
	makeRandomLL(&head1);
	printf("%s\n","LL1 with randomness is:=============");
	traverseLL(&head1);
	head3=cloneLL3(&head1);
	printf("%d\n",head3->data);
	printf("%s\n","Cloned LL is:=============");
	traverseLL(&head3);
	// printf("Method 3:-----------------\n");
	// splitAlternateLLs(&head1,&head2);
	// printf("Odd LL is:\n");
	// traverseLL(&head1);
	// printf("Even LL is:\n");
	// traverseLL(&head2);

	return 0;
}
