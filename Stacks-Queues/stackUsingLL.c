/*Stack can be implemented using arrays (static memory) or linked lists (dynamic from heap)
top is in the head of the LL.
Whenever an element is to be pushed, a node is created and is inserted at the head of the LL
in O(1) time.
For popping, copy the data in a temp and then make the head point to the next element. - O(1)

=> overflow -- No overflow in case of LL implementation as size is not fixed.
To check overflow, just check if malloc returns NULL. That would mean that the entire heap has
been exhausted and so no more memory can be allocated!
 => underflow -- This can occur if head==NULL!

STACK=LIFO=FILO
 Remember to free the space after popping an element.
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node *head=NULL;
struct node
{
	int data;
	struct node *next;
};

void push(int item)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	if(new==NULL)
	{
		printf("Heap out of memory! Overflow!\n");
		return;
	}
		
	new->data=item;
	new->next=NULL;

	if(head==NULL)
	{
		head=new;
	}
	else
	{
		new=head;
		head=new;
	}

}

struct node* pop()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("Underflow!");
		return NULL;
	}
	temp=head;
	head=head->next;
	return temp;
}

int main()
{
	int choice,key;
	printf("\n1. Push\t2. Pop\n");
    printf("3. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    struct node *top_key;
	while(choice!=3)
	{
		
        switch (choice) 
        {
        	case 1: 
        		printf("Enter the key to push\n");
        		scanf("%d",&key);
        		printf("key: %d\n",key);
        		push(key);
        		break;
        	case 2:
        		top_key=pop();
        		if(top_key)
        			printf("Popped item is: %d\n",top_key->data);
        		free(top_key);
        		break;
        	
        	case 3: 
        		printf("BYE");
        		exit(0);
        		break;
        	default:
            	printf("Wrong option!!\n");
           		break; 	
        }
        printf("Enter your choice:");
    	scanf("%d", &choice);
	}
	return 0;
}