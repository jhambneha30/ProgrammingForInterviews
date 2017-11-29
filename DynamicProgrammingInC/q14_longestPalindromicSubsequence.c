/* Given a sequence, find the length of the longest palindromic subsequence in it. 
For example, if the given sequence is RAUDAR, then the output should be 5 as 
"RAUAR" or "RADAR" is the longest palindromic subsequence in it.

Method 1: Brute force
1. Find out all possible subsequences =O(2^n)
2. Check which of these is a palindrome: O(n)
TC=O(n*2^n)

Method 2: Using DP: Use lCS
1. Reverse the string -O(n)
2. Apply LCS on the original string and the reversed string-O(n^2)

TC=O(n^2)=SC

Method 3: Using DP
-----------------------------------Recursive equation---------------------------
LPS(0,n-1) = 2+LPS(1,n-2)   					;if a[0]==a[n-1]
		   = max(LPS(1,n-1),LPS(0,n-2))			;otherwise

Generalizing,
LPS(i,j) = 2+LPS(i+1,j-1)   					;if a[0]==a[n-1]
		 = max(LPS(i+1,j),LPS(i,j-1))			;otherwise


Now, we need to check if there are any repeating sub problems or not. 
Refer to the q14_lps_recursionTree.png
We notice that the subproblems are repeating. So, DP can be applied.

#i can take values from o to n-1, then j can take any value from i+1 to n-1
=> n+(n-1)+(n-2)....1 subproblems
So, #subproblems=O(n^2) => we need a table
----------------------------------------------------------------------------------
We can now build a table and fill it such that i<j. So, only top right part of the matrix
will be filled.
First fill the entries of the type (0,0),(1,1)...(n-1,n-1) with 1
Then keep filling the diagonals till we reach the top right cell, which is the answer!

TC=O(n^2)
SC=O(n^2)

*/

#include <stdio.h>
#include <stdlib.h>

int max(int a,int b) { return (a>b)?a:b; }

int lcs(char str[],char rev[],int n)
{
	int table[n+1][n+1];
	int i,j;
	for(i=0;i<=n;i++)
		table[i][0]=0;
	for(j=1;j<=n;j++)
		table[0][j]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
		
			if(str[i-1]==rev[j-1])
				table[i][j]=1+table[i-1][j-1];
			else
				table[i][j]=max(table[i-1][j],table[i][j-1]);
		}
	}

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("  %d",table[i][j]);
		}
		printf("\n");
	}

	return table[n][n];
}


int lps(char s[],int n)
{
	//We need to build a table such that it will only be half filled
	int lps_table[n+1][n+1];
	int i=0,j,k=1;
	while(i<=n)
	{
		lps_table[i][i]=1;
		i++;
	}
	
	while(k<=n)
	{
		j=k;
		for(i=0;i<=n && j<=n;i++)
		{
			printf("(i,j):(%d,%d)\n",i,j);
			if(s[i]==s[j] && i<j) 
				lps_table[i][j]=2+lps_table[i+1][j-1];
			else if(s[i]==s[j] && i>j)
				lps_table[i][j]=2+0;
			else
				lps_table[i][j]=max(lps_table[i+1][j],lps_table[i][j-1]);
			j++;
		}
		printf("\n");
		k++;
	}
		
	return lps_table[0][n];

}


int main()
{
	char str[]= {'r','a','u','d','p','r'};
	int size=sizeof(str)/sizeof(str[0]);
	int i;
	char reversedStr[size];

	for(i=0;i<size;i++)
	{
		reversedStr[i]=str[size-i-1];
		printf("%c ",reversedStr[i]);
	}
	int res=lcs(str,reversedStr,size);
	printf("\nThe longest palindrome possible is: %d\n",res);

	int final=lps(str,size);
	printf("Longest palindromic subsequence= %d\n",final);
	return 0;
}