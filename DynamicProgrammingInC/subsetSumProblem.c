/*SUBSET SUM PROBLEM-Given an array of elements, is it possible to have a subset whose sum=w?
NOTE: IT IS A DECISION PROBLEM. WE HAVE TO ANSWER AS YES OR NO (or as TRUE OR FALSE).
--------------------------------------------------------------------------------------------
We need to find a subset of the array given which sums to a particular number.
This problem is very similar to the 0/1 KNAPSACK PROBLEM except for the profit conditions!

We can't apply greedy method as we don't know whether to be greedy for smaller numbers or for 
larger numbers.

Recursive equation:
i=current element index, s=remaining sum, a=current element
			|SS(i-1,s)					;if s<a[i]
			|SS(i-1,s-a[i]) U SS(i-1,s) ;if s>a[i]
SS(i,s)=	|True						;if s=0
			|False 						;ifi=0,s!=0

Refer subsetSum_recursionTree.png to see the depth of the recursion tree=O(n) and also 
notice that the tree contains max 2^n nodes which is exponential. So, using recursive version
without DP does not improve TC but increases SC!
Aslo, notice that the repeated subproblems=O(n*w) [where w=required sum] =>
table size=O(n*w) and so is the TC
Thus, DP can be used to reduce the TC of the problem from O(2^n)->O(nw)

Here, we might think that O(nw) is linear, but it is only so if w=constant.
But w is variable. In case, w=2^n or w=n! or any exponential value, then it is better to use the brute 
force method which will take O(2^n) because then this algo will take O(w).

#The table can either be filled in row major order or in column major order!
~~~~~~~~~~~~~~~~~~~~IMPORTANT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
So, TC=min(O(nw),O(2^n))
-> Subset sum is NP-Complete
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 6

bool subsetSum(int arr[],int sum)
{
	int i,j;
	bool ss_table[N+1][sum+1];
	for(i=0;i<=N;i++)
		ss_table[i][0]=true;
	for(j=1;j<=sum;j++)
		ss_table[0][j]=false;

	for(i=1;i<=N;i++)
	{
		for(j=1;j<=sum;j++)
		{
			if(j>=arr[i-1])
				ss_table[i][j]=ss_table[i-1][j-arr[i-1]] || ss_table[i-1][j];
			else
				ss_table[i][j]=ss_table[i-1][j];
			
		}
	}
	return ss_table[N][sum];

}

int main()
{
	int set[] = {3, 34, 4, 12, 5, 2}, sum = 1;
	bool res=subsetSum(set,sum);
	if(res)
		printf("Given sum exists!\n");
	else
		printf("NOPE! Given sum doesn't exist!\n");
	return 0;
}