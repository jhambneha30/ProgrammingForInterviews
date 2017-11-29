/*Design a stack such that get minimum() should be constant time and space
Using a single variable current_min, we can do manipulations to store the last minimum and current min.

When a new element is pushed, we compute the min till now and store it in current_min. If the
current_min is getting updated, then, we compute the difference between the current_min and the
new element smaller than the current_min and store this difference in the stack rather than the
actual element.

There are two uses of doing this:
1. If the stack contains a number smaller than the current_min => the actual element is 
the one present in the current_min.
2. When the current_min has to be popped off from the stack, we need to retrieve the ol min.
This old min can be retrieved by manipulating this negative number!
old min=current_min-number_being_popped

TC=O(1) for getMin
SC=O(1)

Note: When the que wants us to implement a stack to retrieve some element (say min) in
contant time, we have to make sure that the actual property of the stack is not compromised i.e.
push and pop operations should still take O(1) time.
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 5

int stack[MAX];
int top=-1;
int curr_min;

void push(int item)
{
	if(top==MAX-1)
	{
		printf("Overflow!");
		return;
	}
	if(top==-1)
	{
		curr_min=item;
	}
	// top=top+1;
	if(item<curr_min)
	{
		stack[++top]=item-curr_min;
		curr_min=item;
	}
	else
		stack[++top]=item;

}

int pop()
{
	int temp;
	if(top==-1)
	{
		printf("Underflow!");
		return -1;
	}

	temp=stack[top];
	if(temp<curr_min)
	{
		temp=curr_min;
		curr_min=curr_min-temp;
		
	}
		
	top--;
	// if(top==-1)
	// 	curr_min=9999;
	return temp;
}


int main()
{
	
	int choice,key;
	printf("\n1. Push\t2. Pop\n");
    printf("3. Exit\n");
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
        		printf("Min item is: %d\n",curr_min);
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