/* NUTS AND BOLTS PROBLEM: QUICK SORT
We have two sets, one containing unsorted nuts and other containing unsorted bolts.
We need to match a nut to the bolt which fits inside it.

Constraint: Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
It means nut can only be compared with bolt and bolt can only be compared with nut to see 
which one is bigger/smaller.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IMPORTANT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Other way of asking this problem is, given a box with locks and keys where one lock can be 
opened by one key in the box. We need to match the pair.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

This algo can be written in four steps:
1. Choose last character of bolts array as pivot and use it to partition the nuts array. 
Return the correct position of the pivot.
2. Now using the same pivot nut, compare it with the bolts and partition them.
3. Recur for [low...pivot-1] for nuts and bolts array.
4. Recur for [pivot+1...high] for nuts and bolts array.

T(n)=T(a)+T(n-a)+O(n) = O(nlogn) best and average case
					  = O(n^2) worst case, when a=1 and n-a=(n-1)
*/

#include <stdlib.h>
#include <stdio.h>
#define COUNT 6

int partition(char *arr, int start, int end, int pivot)
{
	int i=-1,j=0,temp;
	for(j=0;j<end;j++)
	{
		if(arr[j]<pivot) //Increment i and swap with jth element
		{
			temp=arr[j];
			arr[j]=arr[++i];
			arr[i]=temp;
		}

		if(arr[j]==pivot) //If we find pivot, we put it at the end of the array
		{
			printf("Before swap: %c\n",arr[j]);
			temp=arr[j];
			arr[j]=arr[end];
			arr[end]=temp;
			j--;
			printf("AFter swap: %c\n",arr[j]);
		}
	}
	//Putting the pivot at its correct position
	temp=arr[end];
	arr[end]=arr[++i];
	arr[i]=temp;
	return i;
}

void matchPairs(char *nuts, char *bolts, int start, int end)
{
	printf("start: %d, end:%d\n",start,end);
	if(start<=end)
	{
		int pivot=partition(nuts,start,end,bolts[end]);
		partition(bolts,start,end,nuts[pivot]);
		matchPairs(nuts,bolts,start,pivot-1);
		matchPairs(nuts,bolts,pivot+1,end);
	}
}					  

int main()
{
	char nuts[COUNT] = {'@', '#', '$', '%', '^', '&'};
    char bolts[COUNT] = {'$', '%', '&', '^', '@', '#'};

    matchPairs(nuts,bolts,0,5);
    int i;
    for(i=0;i<=5;i++)
    {
    	printf("%c  %c\n",nuts[i],bolts[i]);
    }
	return 0;
}