/* A queue can be implemented using single stack.
For this twop options are available
Option 1: 
Enqueue - Push into stack
Dequeue - Reverse the stack, then pop, reverse back the stack
Option 2:
Enqueue - Reverse the stack, then push, reverse back the stack
Dequeue - Pop the top of the stack
*/
#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 4

int stack[MAX];
int top=-1;
void reverseStack()
{
	int i=top,j=0,temp;

	printf("Reversing--i: %d, j: %d\n",i,j);
	while(j<i)
	{
		temp=stack[j];
		stack[j]=stack[i];
		stack[i]=temp;
		i--;
		j++;
	}
}

void push(int item)
{
	if(top==MAX-1)
	{
		printf("Overflow!\n");
		return;
	}
	// top=top+1;
	stack[++top]=item;

}

int pop()
{
	int temp;
	if(top==-1)
	{
		printf("Underflow!\n");
		return -1;
	}
	temp=stack[top--];
	return temp;
}

void enqueue(int item)
{
	push(item);
}

int dequeue()
{
	reverseStack();
	int element= pop();
	reverseStack();

	return element;
}


int main()
{
	int choice,key;
	printf("\n1. Enqueue\t2. Dequeue\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
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
        printf("Enter your choice: ");
    	scanf("%d", &choice);
	}
	return 0;
}