/* STOCK SPAN PROBLEM:  This is a financial problem where we have a series of n-daily 
price quotes and we need to calculate span of stock's price for all n-days.

At the current index (on current day), the number of consecutive days 
for which you have been in profit in the past. 
Ex: 				10, 2, 3, 15, 22, 9, 25, 29
Op:  				 0, 0, 1,  3,  4, 0,  6,  7
#comparisons:        0+ 1+ 2+  3+  4.........+(n-1) = O(n^2) - method 1

Method 1: Naive approach
For every current day stock, traverse the numbers to the left of it, till these numbers are
smaller (and keep counting them = span). Stop the traversal, when a larger number is found. 
TC=O(n^2)
SC=O(1)

Method 2:
 0   1  2  3  4  5  6  7   8
100,30,10,20,25,40, 26,35,45
If we check the span for 45, we check with the prev number i.e. 35. If prev<45, then we don't
need to check the numbers which are less than 35 and before 35. We somehow, need to surpass them
and check with only the numbers >prev and thus count the span.
For this, we use a stack.

Remember the checkpoints for a particular number in the stack.

TC=O(n)
SC=O(n)

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

void stocksSpan(int stocks_arr[],int n,int output[] )
{
	int i=1;
	push(0);
	output[0]=0;

	while(i<n)
	{

		if(stocks_arr[i]<stocks_arr[stack[top]])
		{
			output[i]=0;
			printf("i: %d, top: %d, span0: %d\n",i,stocks_arr[stack[top]],output[i]);
		}
			
		else
		{
			while(top!=-1 && stocks_arr[i]>=stocks_arr[stack[top]] )
			{
				pop();
			}
			if(top==-1)
				output[i]=i;
			else
				output[i]=i-stack[top]-1;
			printf("i: %d, top: %d, spanNot0: %d\n",i,stocks_arr[stack[top]],output[i]);
		}
		push(i);
		i++;
	}
	

}

int main()
{
	int j,size;
	int stocks[]={100,30,10,20,25,40,26,35,45};
	size= sizeof(stocks)/sizeof(stocks[0]);
	int span[size];
	stocksSpan(stocks,size,span);



	for(j=0;j<size;j++)
	{
		printf("%d\n",span[j]);
	}
	return 0;
}