/*Number of ways to reach the top of n-stairs: Given n stairs, how many ways can a person climb to the top from bottom using 1 step or 2 steps.

Method 1: Brute force
We have n stairs and for every stair, there are 2 choices: either use it or skip it.
		1	2......n
		2 x 2......2 = 2^n
For every way, we need to check if that is a valid way to be ounted or not (it should either 
include 1 step or 2 steps): O(n)

TC=O(2^n *n)

Method 2: Using DP
To reach the nth step, we need to have total number of ways required to reach step n-1 and 
total number of ways required to reach step n-2.
This, we can write a bigger problem as sum of two smaller problems.

---------------------------_Recursive equation---------------------------
f(n)=f(n-1)+f(n-2)

We need to check overlapping problems now. Refer to the q15_stepsProblem_recursionTree.png for 
the recursion tree and repeating sub problems.
The depth of this tree =O(n) in worst case and the number of recursion calls=O(2^n)
----------------------------Filling the table----------------------------
f(1)=1, f(2)=2 (we have 2 ways to reah step 2: either jump directly or take one step at a time)
Number of subbproblems=O(n)

The table will contaiin the following numbers:
1,2,3,5,8....

If we notice closely, this is same as fibonacci series.

TC=O(n)
SC=O(n)

*/

#include <stdio.h>
#include <stdlib.h>

int computeWaysToClimbSteps(int n)
{
	int table[n+1],i;
	table[0]=0;
	table[1]=1;
	table[2]=2;
	for(i=3;i<=n;i++)
	{
		table[i]=table[i-1]+table[i-2];
	}
	return table[n];
}

int main()
{
	int steps=4;
	int res=computeWaysToClimbSteps(steps);
	printf("Number of ways to climb %d steps using 1 or 2 steps=%d\n",steps,res);
	return 0;
}