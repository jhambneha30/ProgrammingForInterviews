/*Find the longest subsequence in an array, such that elements in subsequence are consecutive.
Example: 10,4,3,11,13,5,6,12,7
There are 2 consecutive subsequences: 3,4,5,6,7 and 10,11,12,13
The longest one is 3,4,5,6,7 with 5 elements

Method 1: 
1. Sort the array. 3,4,5,6,7,10,11,12,13     ---O(nlogn)
2. Scan the array to find the length of every subsequence and subsequently keep updating the
max_subsequence_length ----O(n)

TC=O(nlogn)+O(n) =O(nlogn)
SC=O(1)
============================================================================================
Method 2: Using hash table
Note: An element in the hash table can either be marked as 'T' to indicate that it is present
in the array or it can be marked as 'P' to indicate that it has already been processed i.e.
it has already been counted as part of a subsequence.

1. Build a hash table for the elements in the array and keep marking the elements in 
the array as T.-------O(n)

2. Scan the array: Check for every element in the hash table. If it is 'T', then first check if
and elemnt smaller than it is present in the array. If yes, go till the smallest element in this
run is found.
	Then check if an element larger thhan it is present in the array. If yes, then go till the
largest element in the run using the hash table.
As the elements in this subsequence are being found, change their status to 'P' i.e. processed.
Also, keep the count of elements in this subsequence.  -------O(n)

3. Repeat the same with all the elements in the array and output the max size subsequence.

Optimization: we can also keep adding the subsequence lengths in a variable and we can break out
of the loop if this variable becomes equal to the length of the array!

TC=O(n)
SC=O(n)
*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 9

int cmpfunc(const void *a, const void *b)
{
	return *(int *)a-*(int *)b;
}

int longestSubsequenceConsecutiveNumbers_1(int arr[])
{
	int i;
	qsort(arr,N,sizeof(int),cmpfunc);
	int max_subsequence_length=0,curr_subsequence_length=1;
	for(i=0;i<N;i++)
	{
		printf(" %d",arr[i]);
	}

	for(i=1;i<N;i++)
	{
		if(arr[i]==(++arr[i-1]))
		{
			curr_subsequence_length++;
		}
		else if(max_subsequence_length<curr_subsequence_length)
		{
			max_subsequence_length=curr_subsequence_length;
			curr_subsequence_length=1;
		}
		printf("\ni:%d, elt:%d, curr_subsequence_length:%d\n",i,arr[i],curr_subsequence_length);

	}
	if(max_subsequence_length<curr_subsequence_length)
	{
		max_subsequence_length=curr_subsequence_length;
		curr_subsequence_length=1;
	}
	return max_subsequence_length;
}

int findMax(int a[])
{
	int i,max=INT_MIN;
	for(i=0;i<N;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}

int longestSubsequenceConsecutiveNumbers_2(int arr[])
{
	//1=>Present, 2=>Processed
	int max=findMax(arr),i;
	int *hash=(int *)calloc(max+1,sizeof(int));
	int max_subsequence_length=0,curr_subsequence_length;
	for(i=0;i<N;i++)
	{
		hash[arr[i]]=1;
	}
	printf("max is:%d\n",max);
	for (i = 0; i < N; i++)
	{
		int k;
		curr_subsequence_length=1;
		// printf("===========i:%d,hash index:%d==========\n",i,arr[i]);
		if(hash[arr[i]]==1)
		{
			k=arr[i];
			hash[k]=2;
			// printf("Decreasing----------\n");
			while(k-1>=1 && hash[k-1]==1)
			{
				// printf("hash index: %d, hash value: %d\n",k-1,hash[k-1]);
				curr_subsequence_length++;
				hash[k-1]=2;
				k--;
			}
			k=arr[i];	
			// printf("curr_subsequence_length:%d Increasing----------\n",curr_subsequence_length);
			while(k+1<=max && hash[k+1]==1)
			{
				// printf("hash index: %d, hash value: %d\n",k+1,hash[k+1]);
				curr_subsequence_length++;
				hash[k+1]=2;
				k++;
				// printf("k:%d, hash[k+1]:%d, max:%d\n ",k,hash[k+1],max);
			}
			// printf("curr_subsequence_length:%d after increasing----------\n",curr_subsequence_length);
			if(curr_subsequence_length>max_subsequence_length)
				max_subsequence_length=curr_subsequence_length;
		}
		// printf("curr_subsequence_length:%d, max_subsequence_length:%d\n",curr_subsequence_length,max_subsequence_length);
		
	}
	return max_subsequence_length;

}

int main()
{
	int arr1[N]={10,4,3,14,13,5,9,12,11};
	int len1=longestSubsequenceConsecutiveNumbers_1(arr1);
	printf("M1:====TC=O(nlogn),SC=O(1)======Max subsequence length=%d\n",len1);
	int arr2[N]={10,4,3,14,13,5,9,12,11};
	int len2=longestSubsequenceConsecutiveNumbers_2(arr2);
	printf("M2:====TC=O(n),SC=O(n)=====Max subsequence length=%d\n",len2);
	return 0;
}