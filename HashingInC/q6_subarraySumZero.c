/*Given an array, print all subarrays in the array which has sum 0.

NOTE: Subarrays are contiguous
Subsequences can be random subsets
Method 1: Naive approach:
Find all possible sub arrays.
#subarrays of size n =1
#subarrays of size n-1 =2
.
.
#subarrays of size 1=n
Total subarays = 1+2+....n = O(n^2)
For each subarray, find sum: O(n)
TC=O(n)*O(n^2)=O(n^3)
SC=O(1)

Method 2: Reduce the time taken to compute the sum of the numbers in the subarray.
This can be done by having a cumulative sum array using which the sum can be computed in O(1)
by taking difference between the cum_arr[end of subarray index]-cum_arr[start of subarray index-1].
This is done by taking up a space of O(n) for cumulative array.
TC=O(n^2)* O(1)=O(n^2)
SC=O(n)

NOTE: If ever there is a subarray with sum 0, then cumulative sum will repeat. See below example:
int arr[]={11,10,-5,-3,-2,10,5,-1,-6};
cumulative_sum[0]: 11--------------*
cumulative_sum[1]: 21==============^
cumulative_sum[2]: 16
cumulative_sum[3]: 13
cumulative_sum[4]: 11--------------* Repeated=>subarray 1-4 gives sum 0
cumulative_sum[5]: 21==============^ Repeated=>subarray 2-5 gives sum 0
cumulative_sum[6]: 26
cumulative_sum[7]: 25
cumulative_sum[8]: 19

Given an array, print the count of subarrays in the array which has sum 0.
Method 3:
Build a cumulative sum array - O(n)
Using the concept explained above with example, we can use a hash table to store the cumulative
sum and then check if any sum is repeating! Keep count of the cumulative sum.  - O(n)
If the count for any cumulative sum becomes 2=> the subarray between these repeated cum_sums is 0.
For this, keep a count_zero variable to count the cumulative sums for which sum is zero. - O(n)

TC=O(n)
SC=O(n)
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void subarraySumZero_2(int arr[],int n)
{
	int cumulative_sum[n];
	int i,j,k,sum=0;
	int subarr_sum;

	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		cumulative_sum[i]=sum;
	}
	for(i=0;i<n;i++)
	{
		printf("cumulative_sum[%d]: %d\n",i,cumulative_sum[i]);
	}

	for(j=0;j<n;j++)
	{
		for(k=j;k<n;k++)
		{
			if(j==k && arr[j]==0)
			{
				printf("Sum is zero for indices j:%d, k:%d\n",j,k);
			}
			else
			{
				subarr_sum=cumulative_sum[k]-cumulative_sum[j-1];
				if(subarr_sum==0)
					printf("Sum is zero for indices j:%d, k:%d\n",j,k);
			}
			
			

		}
	}
}

void countSubarraySumZero_3(int arr[],int n)
{
	int cumulative_sum[n];
	int i,j,subarr_count=0,sum=0;
	int subarr_sum,max=-999999;

	for(i=0;i<n;i++)
	{
		sum+=arr[i];
		cumulative_sum[i]=sum;
		if(cumulative_sum[i]>max)
			max=cumulative_sum[i];
	}

	int *hashTable=(int *)calloc(max,sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("cumulative_sum[%d]: %d\n",i,cumulative_sum[i]);
		hashTable[cumulative_sum[i]]++;
	}

	for(j=0;j<max;j++)
	{
		if(hashTable[j]>1)
			subarr_count++;
	}
	printf("#subarrays with sum=0 are: %d\n",subarr_count);
}


int main()
{
	int arr[]={11,10,-5,-3,-2,10,5,-1,-6};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("Method 2:\n");
	subarraySumZero_2(arr,size);
	printf("Method 3:\n");
	countSubarraySumZero_3(arr,size);
	
}