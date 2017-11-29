/*0/1 Knapsack Problem

Method 1: Greedy
We can't apply greedy method as it will give wrong answers for certain cases!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Que: Why Greedy fails?
Ans: It fails for the type of problems mentioned below:
Example:
Capacity of KS = w
				Object 1			Object 2
------------------------------------------------
Profit				2					w
Weight				1					w
------------------------------------------------
Profit/Weight		2					1

Greedy method will always pick object 2, even when w=1000 or any big number
So, the profit=2 always. Actually, the profit should be w if w>2
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
=====================================================================================================
Method 2:Brute Force
We compute all the possible combinations of the objects => 2^n combinations as each object
can either be included or not.  ----O(2^n)
Then, we check which of these combinations' weights sum upto a value less than KS capacity.--O(2^n)
Then, we see whose profit is maximum ------O(2^n)

TC=O(2^n)

==============================================================================================
Method 3: Using DP
We need to see the optimal substructures and the repeating subproblems.
So, to write the recursive equation, we see that we have two options: 
				either include the ith object or exclude it
If w is the weight remaining in the KS say,
KS[i,w] =max(p(i)+KS[i-1,w-w(i)],KS[i-1,w])  ;otherwise
		=0                                 ;if i=0 or w=0
		=KS[i-1,w]						   ;if w<w(i)

Refer nonFractionalKSRecursionTree_1.png to see the depth of the recursion tree=O(n) and also 
notice that the tree contains max 2^n nodes which is exponential. So, using recursive version
without Dp does not improve TC but increases SC!
Refer nonFractionalKSRecursionTree_2.png to notice that the repeated subproblems=O(n*w) =>
table size=O(n*w) and so is the TC
Thus, DP can be used to reduce the TC of the problem from O(2^n)->O(nw)

Here, we might think that O(nw) is linear, but it is only so if w=constant.
But w is variable. In case, w=2^n or w=n! or any exponential value, then it is better to use the brute 
force method which will take O(2^n) because then this algo will take O(w).

#The table can either be filled in row major order or in column major order!
~~~~~~~~~~~~~~~~~~~~IMPORTANT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
So, TC=min(O(nw),O(2^n))
-> Knapsack is NP-Complete
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/

#include <stdio.h>
#include <stdlib.h>
#define N 3
#define W 50

int max(int a,int b) { return (a>b)?a:b; }
int knapsack0_1(int profit[],int wt[],int table[N+1][W+1])
{
	int i,j;
	for(i=0;i<=N;i++)
	{
		for(j=0;j<=W;j++)
		{
			if(i==0 || j==0)
				table[i][j]=0;
			else //we have two options: either include the ith object or exclude it
			{
				if(wt[i]<=j)
					table[i][j]=max(profit[i]+table[i-1][j-1],table[i-1][j]);
				else
					table[i][j]=table[i-1][j];
			}

		}
	}
	return table[N][W];
}

int main()
{
	int values[] = {60, 100, 120};
    int wts[] = {10, 20, 30};
    int ks_table[N+1][W+1];
    int maxProfit=knapsack0_1(values,wts,ks_table);
    printf("max profit is: %d\n",maxProfit);
}