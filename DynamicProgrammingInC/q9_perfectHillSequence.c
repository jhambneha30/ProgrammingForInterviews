/* PERFECT HILL SEQUENCE
Find out a sequence of length 2k+1 where the first (k+1) integers are strictly increasing 
and last (k+1) integers are strictly decreasing.

Method 1: Using LIS (longest increasing subsequence) and LDS (longest decreasing subsequence)

If we have an array with the numbers 1,2,10,5,11 then we need to arrange them such 
that they are first increasing and then decreasing and the largest number is in the middle.
=> 2,10,5 or 1,10,5 are the two possible perfect hills.


Step 1: Compute the lis_table using DP
Step 2: Compute the lds_table using DP
Step 3: Compare the corresponding values in the two tables and find min(lis__value,lds_value)-1
Then, the size of hill possible=(2*(min(lis__value,lds_value)-1))+1
We need to find the maximum of these values and then we can chop off the extra elements to form
a perfect hill.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 8

int min(int x,int y) {return (x<y)?x:y; }

void lis(int a[],int lis_table[])
{
	int i,j;
	lis_table[0]=1;
	for(i=1;i<N;i++)
	{
		for(j=i-1;j>=0;j--)
		{
			if(a[j]<a[i] && lis_table[j]+1>lis_table[i])
				lis_table[i]=lis_table[j]+1;
		}
	}
}

void lds(int b[], int lds_table[]) //To find lds, find lis starting from end of the array
{
	int i,j;
	lds_table[N-1]=1;
	for(i=N-2;i>=0;i--)
	{
		for(j=i+1;j<N;j++)
		{
			if(b[i]>b[j] && lds_table[i]<lds_table[j]+1)
				lds_table[i]=lds_table[j]+1;
		}
	}
}

int findPerfectHillSize(int arr[])
{
	int i,max_hill=0,peak;
	int lis_table[N]={0}, lds_table[N]={0}, hill_table[N];
	lis(arr,lis_table);
	lds(arr,lds_table);
	for(i=0;i<N;i++)
	{
		int minimum=min(lis_table[i],lds_table[i]);
		hill_table[i]=(minimum-1)*2 +1;
		if(hill_table[i]>max_hill)
		{
			peak=arr[i];
			max_hill=hill_table[i];
		}
			
	}
	printf("Peak is: %d\n",peak);
	return max_hill;
}

int main()
{
	int arr[]={10,12,15,55,4,3,11,1};
	int largestHillPossible=findPerfectHillSize(arr);
	printf("Largest possible hill's size is: %d\n",largestHillPossible);
	return 0;
}