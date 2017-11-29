/* We used a circular array to implement queue to avoid wastage of space. But if we implement
the queue using LL, we don't need to worry about space wastage as nodes can be freed up 
as and when dequeued.
Enqueue at rear
Dequeue at front
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front, *rear;


struct node * createNode(int item)
{
	struct node *new= (struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->next=NULL;
	return new;
}

void enqueue(int item)
{
	struct node *new=createNode(item);
	if(!rear)
	{
		front=rear=new;
		return;
	}
	rear->next=new;
	rear=new;
		
}

int dequeue()
{
	struct node *temp;
	if(!front)
	{
		printf("Underflow in queue!\n");
		return -1;
	}
	temp=front;
	front=front->next;

	//IMPORTANT: If front and rear become null i.e. queue becomes empty, 
	//then point rear also to null
	if(!front)
	{
		front=rear=NULL;
	}
	return temp->data;

}

int main()
{
	int choice,key;
	front=rear=NULL;
	printf("\n1. Enqueue\t2. Dequeue\n");
    printf("3. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    int dequeued_key;
	while(choice!=3)
	{
		
        switch (choice) 
        {
        	case 1: 
        		printf("Enter the key to enqueue\n");
        		scanf("%d",&key);
        		printf("key: %d\n",key);
        		enqueue(key);
        		break;
        	case 2:
        		dequeued_key=dequeue();
        		if(dequeued_key>=0)
        			printf("Dequeued item is: %d\n",dequeued_key);
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
