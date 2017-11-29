/*Count the number of times a string occurred as a sub sequence of other string.
Example: 
Indices:	01234
s1: 		abade
s2: 		ae
So, the string s2 has occured twice in s1 as 02 and 04

Method 1: Brute force
1. Find out all possible subsequences -O(2^n)
2. Then, compare each subsequence with the given string - O(n)

TC=O(2^n *n)
Optimization: Do not find out all the substrings if the string s2 is smaller. Only find the 
substrings with length less than equal to  length of s2.
================================================================================================
Method 2: Using DP

---------------------------Recursive equation:---------------------------------
// Returns count of subsequences of S (first string: abade) that match T (second string: ae)
// m is length of T and n is length of S
subsequenceCount(S, T, n, m)

   // An empty string is subsequence of all.
   1) If length of T is 0, return 1.

   // Else no string can be a sequence of empty S.
   2) Else if S is empty, return 0.
    
   3) Else if last characters of S and T don't match,
      remove last character of S and recur for remaining
        return subsequenceCount(S, T, n-1, m)

   4) Else (Last characters match), the result is sum
      of two counts.
        
        // Remove last character of S and recur.
        a) subsequenceCount(S, T, n-1, m) + 

        // Remove last characters of S and T, and recur.
        b) subsequenceCount(S, T, n-1, m-1)        

CORNER CASES:
1. If second string is empty =>1 substrings (because every string has empty string as subsequence)
2. If first string is empty => 0 substrings (because an empty string cannot have a subsequence)


CS(i,j)=CS(i-1,j-1)+CS(i-1,j)		;if s1[i]==s2[j]
	   =CS(i-1,j)					;otherwise
	   =0 							;if i==0 
	   =1 							;if i==0 && j==0 OR j==0

----------------------------Overlapping subproblems-------------------------------
If we try building the recursion tree for this problem, we find out that there are repeating
sub problems. We need a 2-d table for this problem=>O(m*n)

---------------------------Filling the table--------------------------------------
				a 		e
		0 		1 		2
	-------------------------
	0|	1  		0 		0
a	1|	1 		1+0 	0
b	2|	1 		1 		0
a	3|	1 		1+1 	0
d	4|	1 		2 		0
e	5|	1 		2 		2+0=2(ans)

Thus, ae occurs twice in string s1!

TC=O(m*n)
SC=O(m*n)
-------------------------------------------------------------------------------------------
http://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/
http://www.geeksforgeeks.org/count-distinct-occurrences-as-a-subsequence/

*/

#include <stdio.h>
#include <stdlib.h>

int countSubsequences(char *str1, char *str2, int n1, int n2)
{
	int dp_table[n1+1][n2+1];
	int i,j;
	for(i=0;i<=n1;i++)
		dp_table[i][0]=1;
	for(j=1;j<=n2;j++)
		dp_table[0][j]=0;
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			if(str1[i-1]==str2[j-1])
				dp_table[i][j]=dp_table[i-1][j-1]+dp_table[i-1][j];
			else
				dp_table[i][j]=dp_table[i-1][j];
		}
	}
	for(i=0;i<=n1;i++)
	{
		for(j=0;j<=n2;j++)
		{
			printf("%d ",dp_table[i][j]);
		}
		printf("\n");
	}

	return dp_table[n1][n2];
}

int main()
{
	char s1[]={'a','b','a','b','a'};
	char s2[]={'a','b','a'};
	int l1=sizeof(s1)/sizeof(s1[0]);
	int l2=sizeof(s2)/sizeof(s2[0]);

	int count=countSubsequences(s1,s2,l1,l2);
	printf("The number of times s2 occurs in s1: %d\n",count);
	return 0;
}