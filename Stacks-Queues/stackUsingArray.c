/*Stack can be implemented using arrays (static memory) or linked lists (dynamic from heap)
Initially, top=-1
We use an int pointer called top to point to the index which is the top of the stack currently.

TC: Push=pop=O(1)
If top==MAX-1 => overflow
If top==-1 => underflow
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int item)
{
	if(top==MAX-1)
	{
		printf("Overflow!");
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
		printf("Underflow!");
		return -1;
	}
	temp=stack[top--];
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