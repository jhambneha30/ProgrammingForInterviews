/* Find the maximum sum subarray | Largest Sum Contiguous Subarray
Method 1: Brute Force
Find all possible subarrays (O(n^2)) and compute the sum for each (O(n)).
Then, find the max among these.

TC=O(n)
==========================================================================================
Method 2: Using hash table
Take an extra array to store the cumulative sum. -O(n)
Now, find all possible subarrays (O(n^2)).
The sum of these subarrays can be found in O(n) using the cumulative array.
Then find max in O(n)

TC=O(n^2)*O(1)+O(n) = O(n^2)
==========================================================================================
Method 3: KADANE'S ALGORITHM
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IMP~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Constraint: The array should contain atleast one positive number.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

We need to maintain 3 variables: max_sum_so_far, curr_sum, index

We keep updating the current sum at every step (when we do not encounter a bnegative number).
In case we get curr_sum<0, we make it 0 to avoid carrying the negative part to the subarray
starting from next number.
We update the max_sum_so_far only when the new curr_sum is greater than the old max_sum_so_far.
And we keep updating the index alongside, when the max_sum_so_far is updated!

After we get the max_sum_so_far in one scan, we traverse from the index till we get sum=max_sum_so_far.
Thus, we are able to find the subarray with max sum!



*/

#include <stdio.h>
#include <stdlib.h>
#define N 9

int maxSumContiguousSubarray_Kadane(int arr[],int *start,int *end)
{
	int max_sum_so_far=0,curr_sum=0,index=-1,i;
	for(i=0;i<N;i++)
	{
		curr_sum+=arr[i];
		// if(curr_sum<0)
		// {
		// 	curr_sum=0;
		// 	continue;
		// }
			
		if(curr_sum>max_sum_so_far)
		{
			max_sum_so_far=curr_sum;
			index=i;
		}
	}
	printf("curr sum is: %d\n",curr_sum);
	curr_sum=0;
	*end=index;
	while(index>=0)
	{
		curr_sum+=arr[index];
		if(curr_sum==max_sum_so_far)
			break;
		index--;
	}

	*start=index;

	return max_sum_so_far;
}

int main()
{
	// int arr[N]={10,-5,-3,4,2,12,-8,-12,19};
	int arr[N]={-3,10,5,-20,4,11,-5,7};
	int start,end;
	int sum=maxSumContiguousSubarray_Kadane(arr,&start,&end);
	printf("Subarray is: %d to %d AND max sum: %d\n",start,end,sum);
	return 0;
}