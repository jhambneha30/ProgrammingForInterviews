/*Just like stack, a queue is also a linear data structure.
It uses two pointers: front and rear
front points to the first element which was inserted and rear points to the last element which was inserted.

QUEUE=FIFO=LILO

To implement a queue using two stacks, S1 and S2
Enqueue: Push into S1
Dequeue: If we directly pop from S1, we get LIFO. Since we want to have FIFO,
we use another stack.

While popping, first check if S2 is empty. If not empty, pop from S2.
But if S2 is empty, pop the elements present in S1 and push them into S2 one by one.
Now, pop an element from S2.

Underflow: If S2 is empty and S1 is also empty => queue is empty!

#Every element requires 2 pushes and 2 pops individually!
But, if suppose 2 elements are inserted into the queue, and then one element needs to be dequeued,
2 pushes+2pops+2pushes+1pop is required which takes a lot of time. While the second dequeue will 
just take one pop! So, on average every element takes 2n pushes and 2n pops.

*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 4

int top1=-1,top2=-1;
int stack1[MAX];
int stack2[MAX];
void push(int stack[],int flag,int item)
{
	int top;
	if(flag==1)
		top=top1;
	else
		top=top2;
	if(top==MAX-1)
	{
		printf("Overflow!");
		return;
	}
	// top=top+1;
	stack[++top]=item;
	if(flag==1)
		top1=top;
	else
		top2=top;

}

int pop(int stack[],int flag)
{
	int temp,top;
	if(flag==1)
		top=top1;
	else
		top=top2;
	if(top==-1)
	{
		printf("Underflow!");
		return -1;
	}
	temp=stack[top--];
	if(flag==1)
		top1=top;
	else
		top2=top;
	return temp;
}

void enqueue(int item)
{
	if(top1==MAX-1)
	{
		printf("Overflow!\n");
		return;
	}
	push(stack1,1,item);

}

int dequeue()
{
	int t;
	if(top2==-1 && top1==-1)
	{
		printf("Underflow in queue!:(\n");
		return  -1;
	}
	if(top2==-1)
	{
		//pop from stack1 and push into stack2
		while(top1!=-1)
		{
			t=pop(stack1,1);
			push(stack2,2,t);
		}
		return pop(stack2,2);
		
	}
	else
	{
		return pop(stack2,2);
	}
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