/*Que 2) Design a stack such that get minimum () should be 0(1).
For this, two stacks will be used. While building the main stack1, we push the minimum seen 
till now in stack2.

TC=O(1)
SC=O(1) [because an extra stack is used!]
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 5

int stack[MAX];
int min_stack[MAX];
int top=-1, min_top=-1;
int min=999999;

void pushIntoMinStack(int m)
{
	if(min_top==MAX-1)
	{
		printf("Overflow in min stack!");
		return;
	}
	min_stack[++min_top]=m;
}

int popFromMinStack()
{
	int min_temp;
	if(min_top==-1)
	{
		printf("Underflow in min stack!");
		return -1;
	}

	min_temp=min_stack[min_top--];
	if(min_top==-1)
		min=99999;
	return min_temp;
}

void push(int item)
{

	if(top==MAX-1)
	{
		printf("Overflow!");
		return;
	}
	// top=top+1;
	stack[++top]=item;
	if(item<min)
	{
		min=item;
		pushIntoMinStack(min);
	}
		

}

int pop()
{
	int temp;
	if(top==-1)
	{
		printf("Underflow!");
		return -1;
	}
	temp=stack[top--];
	if(min_stack[min_top]==temp)
		popFromMinStack();
	return temp;
}

int main()
{
	int choice,key;
	printf("\n1. Push\t2. Pop\n");
    printf("3. Print Min\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    int top_key;
	while(1)
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
        		printf("Min is: %d\n",min_stack[min_top]);
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
