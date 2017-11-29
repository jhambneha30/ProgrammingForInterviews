/* LONGEST INCREASING SUBSEQUENCE: Find the length of the longest subsequence of 
a given sequence such that all elements of the subsequence are sorted in increasing order. 

Method 1: Brute Force
Find out all possible subsequences (O(2^n)) after sorting the array (O(nlogn)) and 
find their lengths.
The one with max length is the answer O(n)
=============================================================================================
Method 2: Using LCS (converting one DP problem into another)
1. Sort the array -O(nlogn)
2. Apply LCS using Dynamic Programming between the sorted and the non-sorted array-O(n^2)

TC=O(n^2)
SC=O(n^2)
=============================================================================================
Method 3: Using direct DP
For this, we need to see the subproblems that exist.
--------------------------Optimal subproblems-----------------------------------
Example: 2,3,1,5,12,10,11
We notice that in the worst case, we'll have the length of LIS=1 (when the list is in decreasing 
order, say, 8,5,4,3,1, then LIS=1)
Otherwise, the LIS in the larger list =LIS in the smaller list +1 if the last element in the 
										larger list>last element in the smaller list!

---------------------------Recursive equation------------------------------------	^
=>LIS(n)=|LIS(n-1)+1 ;if arr[n]>arr[n-1]          ----n-1 comparisons			   /|\
		 |LIS(n-2)+1 ;if arr[n-1]>arr[n-2]		  ----n-2 comparisons				|
	  max|.												.							|
		 |.												.							|
		 |LIS(1)+1 	 ;if arr[2]>arr[1]			  ----1 comparison 					|
		 |1 		 ;Otherwise 				  ----0 comparisons 				|
											_____________________________			|
										   Summing----O(n^2) comparisons			|
											_____________________________				
Compressing the equation:
LIS(j)=max:for all i<j |LIS(i)+1 ; if a[j]>a[i] 
					   |1 	   ; if i=1 (if i is the first element in the array)

After evaluating the lis_table using DP, we need to find the max element in the table =>O(n)
----------------------------------------------------------------------------------
If we use the Bottom up approach, we can keep using the result of the smaller problems to
compute the result for larger problems.

TC=O(n^2) for scanning the array and for going backwards and finding the maximum for every 
element +O(n) for finding max among the table elements
=O(n^2)

SC=O(n) for lis_table
NOTE: TO COMPUTE LIS, WE NEED TO START FROM INDEX 1.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 5

int cmpfunc(const void *a,const void *b){ return *(int *)a- *(int *)b; }

int max(int a,int b){ return (a>b)?a:b; }

int lcs(int a1[],int a2[],int lcs_table[N+1][N+1])
{
	int i,j;
	printf("\n============Comparisons============\n");
	for(i=1;i<=N;i++)
	{
		for(j=1;j<=N;j++)
		{
			printf(" %d,%d",a1[i-1],a2[j-1]);
			if(a1[i-1]==a2[j-1])
				lcs_table[i][j]=1+lcs_table[i-1][j-1];
			else
				lcs_table[i][j]=max(lcs_table[i-1][j],lcs_table[i][j-1]);
		}
		printf("\n");
	}
	printf("\n============LCS_TABLE============\n");
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=N;j++)
		{
			printf(" %d",lcs_table[i][j]);
		}
		printf("\n");
	}
	return lcs_table[N][N];
}

int lis_usingLCS(int arr[])
{
	int lcs_table[N+1][N+1]={0};
	int sorted_arr[N];
	int i;
	for(i=0;i<N;i++)
	{
		sorted_arr[i]=arr[i];
	}
	qsort(sorted_arr,N,sizeof(int),cmpfunc);
	printf("sorted array\n");
	for(i=0;i<N;i++)
	{
		printf(" %d",sorted_arr[i]);
	}
	return lcs(arr,sorted_arr,lcs_table);
}

int lis(int arr[],int size,int lis_table[])
{
	int i,j,curr_len=1,max=-1;
	lis_table[0]=1;
	for(i=1;i<size;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(arr[i]>arr[j] && lis_table[j]+1>lis_table[i])
			{
				lis_table[i]=lis_table[j]+1;
			}

		}
		if(lis_table[i]>max)
			max=lis_table[i];
	}

	return max;
}


int main()
{

	int arr[N]={ 10, 22, 9, 33, 21};//, 50, 41, 20 };
	// int arr[N]={2,3,1,5,12,10,11};
	int x;
	int res1=lis_usingLCS(arr);
	printf("M1:lis length is: %d\n",res1);
	//===============================================
	int lis_table[N]={0};
	int res2=lis(arr,N,lis_table);
	printf("M2:lis length is: %d\n",res2);
	for(x=0;x<N;x++)
	{
		printf(" %d",lis_table[x] );
	}
	return 0;
}
