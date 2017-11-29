/*NOTE: TO BE DONE AFTER LONGEST INCREASING SUBSEQUENCE
Que: Maximum sum increasing subsequence

Method 1: Brute Force
=================================
Method 2:Using DP

---------------------------Recursive equation------------------------------------	        ^
 MSIS(n)=|MSIS(n-1)+a[n]   ;if arr[n]>arr[n-1]            ----n-1 comparisons			   /|\
		 |MSIS(n-2)+a[n-1] ;if arr[n-1]>arr[n-2]		  ----n-2 comparisons				|
	  max|.												   .							    |
		 |.												   .							    |
		 |MSIS(1)+a[2] 	   ;if arr[2]>arr[1]			  ----1 comparison 					|
		 |a[1] 		 	   ;Otherwise 				      ----0 comparisons 				|
														_____________________________			    |
														Summing----O(n^2) comparisons			    |
														_____________________________				
Compressing the equation:
MSIS(j)=max:for all i<j |MSIS(i)+a[j] ; if a[j]>a[i] 
					    |a[1] 	      ; if i=1 (if i is the first element in the array)

After evaluating the lis_table using DP, we need to find the max element in the table =>O(n)

If we use the Bottom up approach, we can keep using the result of the smaller problems to
compute the result for larger problems.

TC=O(n^2) for scanning the array and for going backwards and finding the maximum for every 
element +O(n) for finding max among the table elements
=O(n^2)

SC=O(n) for lis_table
NOTE: TO COMPUTE MSIS, WE NEED TO START FROM INDEX 1.
----------------------------------------------------------------------
Example 1:
Array								20,3,1,15,16,2,12,13
Table 								20,3,1,18,34,3,15,25
It means the MSIS=34

Example 2:
Array 								50,20,3,1,15,16
Table 								50,20,3,1,18,34
MSIS=50
*/

#include <stdio.h>
#include <stdlib.h>
#define N 7

int maxSumIncreasingSubsequence(int arr[],int table[])
{
	int i,j,max=-1;
	table[0]=arr[0];
	for(i=1;i<N;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(arr[j]<arr[i] && table[j]+arr[i]>table[i])
			{
				table[i]=table[j]+arr[i];
				
			}
		}
		if(max<table[i])
			max=table[i];
	}
	return max;
}

int main()
{
	int arr[N]={2,3,1,11,10,4,16};
	int msis_table[N]={0};
	int maxSum=maxSumIncreasingSubsequence(arr,msis_table);
	printf("M1:max sum is: %d\n",maxSum);
	return 0;
}