/*Just like stack, a queue is also a linear data structure.
It uses two pointers: front and rear
front points to the first element which was inserted and rear points to the last element which was inserted.

QUEUE=FIFO=LILO

If we use a normal array is used, then if we dequeue elements, space is waste at the front.
So, we use a circular array instead, to implement a queue.It means we visualize a normal array
as circular array. We leave one space as blank to point the beginning of the queue.
It means if array has size 4, then we use 3 spaces.
This is because if we don't leave a gap, then we won't be able to distinguish between the 
overflow and underflow conditions.

Note: Modular incrementation is used in circular arrays!
Enqueue: Increment the rear and insert item
Dequeue: Front pointer always points to one element less than the beginning of the queue =>
Increment front and then delete it (the element will actually stay there, we just increment the ptr)

Overflow:  if((rear+1)mod n == front) (after incrementing rear,check)
Underflow: if(front==rear)
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 4

int front=0,rear=0;
int queue[MAX];
void enqueue(int item)
{
	int n=MAX;
	//check overflow
	if(((rear+1) % n)==front)
	{
		printf("front: %d, rear: %d\n",front,rear);
		printf("Overflow!\n");
		return;
	}
	rear=(++rear % n);
	printf("rear: %d\n",rear);
	queue[rear]=item;
	printf("Enqueued!\n");
}

int dequeue()
{
	int n=MAX,temp;
	if(front==rear)
	{
		printf("front: %d, rear: %d\n",front,rear);
		printf("Underflow!\n");
		return -1;
	}
	temp=queue[++front];
	printf("front: %d\n",front);
	return temp;
}

int main()
{
	int choice,key;
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