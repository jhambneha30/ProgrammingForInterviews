/*Split the linked list into two lists: one containing the even nodes and other
containing odd nodes. */
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

	printf("Method 3:-----------------\n");
	splitAlternateLLs(&head1,&head2);
	printf("Odd LL is:\n");
	traverseLL(&head1);
	printf("Even LL is:\n");
	traverseLL(&head2);

	return 0;
}