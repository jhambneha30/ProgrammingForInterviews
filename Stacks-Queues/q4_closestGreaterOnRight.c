/* Find the closest greater element which is present on the right side of the element

Method 1: Brute force
For every element, scan the array on the right till we come across an element greater than this
element.
In worst case, 
#comparisons for element 1: (n-1)
#comparisons for element 2: (n-2)
.
.
.
#comparisons for element n: (1)
Summing, #comparisons=O(n^2)
TC=O(n^2)
SC=O(1)

Method 2: Using stack
Keep the indices of the elements in the stack for which the largest closest element on 
right needs to be found.

Algo: Initially, push the first element of the array in the stack.
We scan the array and check if the top of stack has greater element than current index.
If yes, then we keep popping the elements till this element is greater and fill the output
array accordingly.
Push an index on top of array only if top of the stack is greater than the element at this index.

while(top<element at index)
	keep popping and set this element as output for all these popped indices.

if(top>element at index) 
	push the index

Since, every element enters the stack and comes out, TC=O(n), SC=O(n)
Note: We push every element exactly once and pop it =>TC=O(1)*n +O(1)*n=O(n)


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
	int arr[]={10,20,1,5,25,500,60};
	int size=sizeof(arr)/sizeof(arr[0]);
	int output_arr[size];
	int i,popped_index;
	push(0);

	for(i=1;i<size;i++)
	{
		if(arr[i]>arr[stack[top]])
		{
			while(arr[stack[top]]<arr[i] && top>-1)
			{
				popped_index=pop();
				output_arr[popped_index]=arr[i];
			}
		}
		push(i);
	}

	while(top!=-1)
	{
		popped_index=pop();
		output_arr[popped_index]=9999999;
	}

	printf("Output array:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\n", output_arr[i]);
	}

}