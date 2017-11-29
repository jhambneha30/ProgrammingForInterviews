/*Que 1) Implement a stack using two queues.
This means we have to implement push and pop using enqueue and dequeue.

At any time, one queue will be empty. So, while pushing, the element is enqueued onto the empty
stack. Then, the elements from the other queue are dequeued one by one and enqueued into this stack.

When we have to pop, dequeue the elements from the non empty queue.

Pop: TC=O(1)
Push: TC=O(n) worst case because in worst case, we have to enqueue the element into the empty queue
and then move the n elements from the non-empty queue to this queue.

NOTE: We can also modify the implementation to make pop O(n) time and push O(1) time.
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 3


int front1=0,rear1=0,front2=0,rear2=0;
int queue1[MAX];
int queue2[MAX];
void enqueue(int qFlag,int item)
{
	int n=MAX,front,rear;
	int *queue;
	if(qFlag==1)
	{
		front=front1;
		rear=rear1;
		queue=queue1;
	}
	else
	{
		front=front2;
		rear=rear2;
		queue=queue2;
	}
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
	if(qFlag==1)
	{
		front1=front;
		rear1=rear;
		//queue1=queue;
	}
	else
	{
		front2=front;
		rear2=rear;
		//queue2=queue;
	}
}

int dequeue(int qFlag)
{
	int n=MAX,temp,front,rear;
	int *queue;
	if(qFlag==1)
	{
		front=front1;
		rear=rear1;
		queue=queue1;
	}
	else
	{
		front=front2;
		rear=rear2;
		queue=queue2;
	}
	if(front==rear)
	{
		printf("front: %d, rear: %d\n",front,rear);
		printf("Underflow!\n");
		return -1;
	}
	temp=queue[++front];
	printf("front: %d\n",front);
	if(qFlag==1)
	{
		front1=front;
		rear1=rear;
		// queue1=queue;
	}
	else
	{
		front2=front;
		rear2=rear;
		// queue2=queue;
	}
	return temp;
}

void push(int item)
{
	int other;
	if(front1==rear1)//If queue1 is empty, then enqueue item into queue1, otherwise into queue2
	{
		enqueue(1,item);
		other=2;
	}
	else if(front2==rear2)
	{
		enqueue(2,item);
		other=1;
	}

	if(other==2 && front2!=rear2)
	{
		while(front2!=rear2)
		{
			int temp=dequeue(2);
			if(temp!=-1 && (rear1+1)%MAX!=0)
			{
				enqueue(1,temp);
				printf("Dest queue: %d, dequeued: %d\n",1,temp);
			}
			else
			{
				printf("Overflow in stack!\n");
				return;
			}
			
		}
	}
	else if(other==1 && front1!=rear1)
	{
		while(front1!=rear1)
		{
			int temp=dequeue(1);
			
			if(temp!=-1 && (rear2+1)%MAX!=0)
			{
				enqueue(2,temp);
				printf("Dest queue: %d, dequeued: %d\n",2,temp);
			}
			else
			{
				printf("Overflow in stack!\n");
				return;
			}
		}
	}
}

int pop()
{
	int data;
	if(front1!=rear1)
	{
		data=dequeue(1);
	}
	else if(front2!=rear2)
	{
		data=dequeue(2);
	}
	else
	{
		printf("Underflow in stack!\n");
		return -1;
	}
	return data;
}

int main()
{
	int choice,key;
	printf("\n1. Push\t2. Pop\n");
    printf("3. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    int top_key;
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
        		printf("Popped item is: %d\n",top_key);
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