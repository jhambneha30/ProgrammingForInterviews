/*LONGEST DECREASING SUBSEQUENCE: Find the length of the longest subsequence of 
a given sequence such that all elements of the subsequence are sorted in decreasing order. 

Method 1: Brute Force
==========================================================================================
Method 2: Using LCS
1. Sort the array in decreasing order -O(nlogn)
2. Apply LCS using Dynamic Programming between the sorted and the non-sorted array-O(n^2)

TC=O(n^2)
SC=O(n^2)
===========================================================================================
Method 3:Using direct DP: 2 approaches
-------------------------
Approach 1: Using LIS
1. Reverse the array
2. Apply LIS
TC=O(n^2)
SC=O(n)
-------------------------
Approach 2: LDS
1. Apply the same method as LIS. Start from index n.
So, LDS=LIS applied from end
TC=O(n^2)
SC=O(n)
NOTE: TO COMPUTE LDS, WE NEED TO START FROM INDEX n.

*/

#include <stdio.h>
#include <stdlib.h>
#define N 8

int lds(int arr[],int size,int lds_table[])
{
	int i,j,curr_len=1,max=-1;
	lds_table[size-1]=1;
	for(i=size-1;i>=0;i--)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]>arr[j] && lds_table[j]+1>lds_table[i])
			{
				lds_table[i]=lds_table[j]+1;
			}

		}
		if(lds_table[i]>max)
			max=lds_table[i];
	}

	return max;
}


int main()
{

	int arr[N]={ 10, 22, 9, 33, 21, 50, 41, 20 };
	// int arr[N]={2,3,1,5,12,10,11};
	int sorted_arr[N],x;
	int lds_table[N]={0};
	int res2=lds(arr,N,lds_table);
	printf("lis length is: %d\n",res2);
	for(x=0;x<N;x++)
	{
		printf(" %d",lds_table[x] );
	}
	return 0;
}
