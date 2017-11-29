/* Partition problem is to determine whether a given set can be partitioned into two subsets 
such that the sum of elements in both subsets is same.
Example: 4,10,5,15,3,1
Then the two possible partitions are:
P1: 4,15		P2: 10,5,3,1
===========================================================================================
Method 1: Brute force
1. Find out all possible partitions.
We have two choices for every number: either we can put it into P1 or into P2. Thus number of
ways = O(2^n)
2. Add the numbers in both the partitions for every possible division and check if the sum is 
equal or not---O(n)

TC=O(2^n*n)
============================================================================================
Method 2: Using DP

Following are the two main steps to solve this problem:
1) Calculate sum of the array. If sum is odd, there can not be two subsets with equal sum,
 so return false.
2) If sum of array elements is even, calculate sum/2 and find a subset of array with 
sum equal to sum/2.

So, we first compute the sum of the array (say we get sum=k): O(n)
Then, we apply subset sum problem with sum=k/2: O(nk) ----pseuso polynomial time!


*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 6

bool subsetSum(int a[],int n,int part_sum)
{
	int i,j;
	int table[n+1][part_sum+1];
	for(i=0;i<=n;i++)
	{
		table[i][0]=true;
	}
	for(j=1;j<=part_sum;j++)
	{
		table[0][j]=false;
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=part_sum;j++)
		{
			if(a[i]<=j)
				table[i][j]=table[i-1][j-a[i-1]] || table[i][j-1];
			else
				table[i][j]=table[i-1][j];
		}
	}
	return table[n][n];
	
}

int main()
{
	int arr[]={4,10,5,15,3,3};
	int i,sum=0;
	int size=sizeof(arr)/sizeof(arr[0]);
	bool res;
	for(i=0;i<size;i++)
	{
		sum+=arr[i];
	}
	if(sum%2!=0)
		printf("Partition doesn't exist!\n");
	else
	{
		res= subsetSum(arr, size, sum/2);
		if(res)
			printf("Partition exists!\n");
		else
			printf("NOPE! Doesn't exist!\n");
	}
		
	
	

	return 0;
}