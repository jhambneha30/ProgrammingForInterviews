/* Find the number of n-bit integers which do not have any two consequent zeros.
===============================================================================================
Method 1:Brute Force
1. Compute all possible combinations: O(2^n)
2. For each of these, check if it contains two consecutive zeroes or not: O(n)

TC=O(2^n *n)
===============================================================================================
Method 2: Using DP
Suppose we have n=4, then we can fill the first position either with 1 or with 0 =>
      (_ _ _ _) -> (0 _ _ _)  or  (1 _ _ _)			[2 choices]
Now,  (0 _ _ _) -> (0 1 _ _)						[1 choice when a position is filled with 0]
And,  (1 _ _ _) -> (1 0 _ _)  or  (1 1 _ _)			[2 choices]

Similarly, we can grow the tree.
If the problem is f(n), then
At every position, we can either have 0 or 1. 
Case 1: If we have 0, then we have (n-2) positions left=> f(n-2) as the next position after 0 
has to be taken up by 1.

Case 2: If we have 1, then we have (n-1) positions left=> f(n-1) as the next position after 1 
can be taken up by 0 or 1.

Thus, f(n)=f(n-1)+f(n-2)
This recursive equation is same as fibonacci series.

TC= O(2^n)

Since, the recursion tree has repeating subproblems, then we can apply DP to reduce the TC.
Since, n can take any values from 1 to n. So, the unique subproblems=n

We have a table in the form of an array of size n which contains the result of all the 
subproblems.

If we take a closer look at the pattern, we can observe that the count is actually (n+2)’th Fibonacci number for n >= 1. The Fibonacci Numbers are 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 141, ….

n = 1, count = 2  = fib(3)
n = 2, count = 3  = fib(4)
n = 3, count = 5  = fib(5)
n = 4, count = 8  = fib(6)
n = 5, count = 13 = fib(7)
*/

#include <stdio.h>
#include <stdlib.h>

int numIntegersWithoutConsecutiveZeros(int n,int tab[])
{
	int i;5
	tab[0]=1;
	tab[1]=1;
	for(i=2;i<=n;i++)
	{
		if(tab[i]==0)
		{
			tab[i]=tab[i-1]+tab[i-2];
		}
	}
	return tab[n];
}

int main()
{
	int n=4;
	int *table=(int *)calloc(n+1,sizeof(int));
	int result=numIntegersWithoutConsecutiveZeros(n,table);
	printf("Number of integers without consecutive zeroes= %d\n",result);
	return 0;
}