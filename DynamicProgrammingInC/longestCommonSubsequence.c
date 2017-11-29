/* LONGEST COMMON SUBSEQUENCE
Difference between substring and subsequence:
Example: RAVINDRA
SUBSTRING: RA, VI, AVI, RAVI etc.
SUBSEQUENCES: RAI, ANA etc. (some characters can be missing as long as the characters are in ascending order)

NOTE: All substrings are subsequences!
#substrings possible=n+(n-1)+...1 = n*(n-1)/2
#subsequences possible=2^n
(every character has 2 choices-either it can be included or not)

This method is generally used to compute the similarity between the genes of two species.
Example:
s1=RAVINDRA and s2=AJAY

==============================Brute force Algorithm=========================================
1. Find all subsequences of s1. -O(2^m)
2. For each subsequence of s1, check if it is a subsequence of s2- O(n*2^m)
3. Among the common subsequences, find the longest- O(2^m) (linear search)

TC=O(n*2^m) -----exponential

=============================Dynamic Programming=============================================
X: x1 x2....xn
Y: y1 y2....yn
If xn=yn, then we can say that the LCS of the complete strings is same as the LCS of the smaller
strings after removing the last character and then appending it later! This forms the optimal
substructure because the solution to the smaller problem forms the solution to the main problem.
Let c[i,j] is the length of the longest common subsequence, then:-
Recursive equation: 
			
c[i,j]		=0                            ;i=0 or j=0
			=1+c[i-1,j-1]                 ;i,j>0 and xi = yj
			=max(c[i-1,j],c[i,j-1])       ;otherwise if xi != yj

WORST CASE: When the strings are completely different
s1: AAA, s2: BBB
In this, at every step, the length of one of the strings will be decremented by 1=>
Depth of tree in worst case = O(n+m) => SC=O(n+m)
Number of recursive calls = O(2^(n+m)) => TC=O(2^(n+m))

We notice that by using the recursive method, the TC worsened rather than improving as SC is
also introduced.
So, we try to use DP as there are overlapping problems.
QUE: How many unique subproblems are present? ANS: m*n
For two strings of size n=3 and m=3, there are 16 unique subproblems. 
(refer LCS-RecursionTreeAndUniqueSubproblems.png) =>O(m*n) is the table size we need
Using this table, the TC is reduced to the size of table=> TC=SC=O(mn)

====================================Algorithm: LCS-BOTTOM UP=====================================
LCS(x,y)
{
	m=X.length;
	n=Y.length;
	Create a matrix of size m+1,n+1: C[0..m,0..n]
	for(i=0 to m)
		C[i,0]=0;
	for(j=1 to n)
		C[0,j]=0;
	//Filling the table in row major order
	for(i=1 to m)
	{
		for(j=1 to n)
		{
			if(xi==yj)
				C[i,j]=1+C[i-1,j-1];
			else
				C[i,j]=max(C[i-1,j],C[i,j-1]);
		}
	}
	return C[m,n];
}
*/

#include <stdio.h>
#include <stdlib.h>
#define M 4
#define N 4

int max(int a,int b)
{
	return (a>b)?a:b;
}

void lcs_bottomUp(char *s1, char *s2,int table[M+1][N+1])
{
	int i,j;
	for(i=0;i<=M;i++)
		table[i][0]=0;
	for(j=1;j<=N;j++)
		table[0][j]=0;

	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			if(s1[i-1]==s2[j-1])
				table[i][j]=1+table[i-1][j-1];
			else
				table[i][j]=max(table[i-1][j],table[i][j-1]);
		}
	}
}

int main()
{
	char str1[M]="abbc";
	char str2[N]="abbc";
	int lcs_table[M+1][N+1];

	lcs_bottomUp(str1,str2,lcs_table);
	printf("Optimized LCS=%d\n",lcs_table[M][N]);
	return 0;
}