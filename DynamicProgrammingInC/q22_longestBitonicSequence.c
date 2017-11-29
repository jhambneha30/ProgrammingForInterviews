/* LONGEST BITONIC SEQUENCE
Que: How is it different from PERFECT HILL SEQUENCE.
Ans: The only difference is that it need not have same height of LIS and LDS =>
A sequence, sorted in increasing order is considered Bitonic with the decreasing part as empty. 
Similarly, decreasing order sequence is considered Bitonic with the increasing part as empty.
However, completely sorted arrays won't form perfect hill sequences!

Method 1: Using LIS (longest increasing subsequence) and LDS (longest decreasing subsequence)

Input arr[] = {1, 11, 2, 10, 4, 5, 2, 1};

Output: 6 (A Longest Bitonic Subsequence of length 6 is 1, 2, 10, 4, 2, 1)

Step 1: Compute the lis_table using DP
Step 2: Compute the lds_table using DP
Step 3: Compare the corresponding values in the two tables and find max(lis_table[]+lds_table[]-). This will be the longest bitonic sequence.

http://www.geeksforgeeks.org/dynamic-programming-set-15-longest-bitonic-subsequence/
*/

#include <stdio.h>
#include <stdlib.h>

void lis(int a[],int lis_table[],int len)
{
	int i,j;
	lis_table[0]=1;
	for(i=1;i<len;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j]<a[i] && (lis_table[j]+1)>lis_table[i])
			{
				lis_table[i]=lis_table[j]+1;
				break;
			}

		}
	}
}

void lds(int a[],int lds_table[],int len)
{
	int i,j;
	lds_table[len-1]=1;
	for(i=len-1;i>=0;i--)
	{
		for(j=i+1;j<len;j++)
		{
			if(a[j]<a[i] && (lds_table[j]+1)>lds_table[i])
			{
				lds_table[i]=lds_table[j]+1;
				break;
			}
		}
	}
}

int longestBitonicSubsequence(int arr[],int n)
{
	int *lis_table=(int *)calloc(n,sizeof(int));
	int *lds_table=(int *)calloc(n,sizeof(int));
	int lbs[n],i,max=-9999;
	lis(arr,lis_table,n);
	lds(arr,lds_table,n);
	for(i=0;i<n;i++)
	{
		lbs[i]=lis_table[i]+lds_table[i]-1;
		if(lbs[i]>max)
			max=lbs[i];
	}
	return max;
}

int main()
{

	int arr[]={1, 11, 2, 10, 4, 5, 2};
	int size=sizeof(arr)/sizeof(arr[0]);
	int res=longestBitonicSubsequence(arr,size);
	printf("Longest bitonic sequence: %d\n",res);
	return 0;
}