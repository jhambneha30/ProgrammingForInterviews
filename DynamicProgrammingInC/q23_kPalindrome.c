/* k-Palindrome
Given a string, find out whether it becomes a palindrome or not by doing at most k-deletions.
Example1: abxa, k=1
Ans: Yes
Example2: abdxa, k=1
Ans: No
===============================================================================================
Method 1: Brute Force
We try removing atmost k characters from the string and then check if any of the resulting 
substring forms a palindroe or not. If even one of them forms a palindrome, then we stop and
output the answer as Yes!

Number of problems we need to solve in the worst case:

For k=1, n subsequences are possible
For k=2, nC2 subsequences are possible
.
.
For k=k, nCk subsequences are possible
Summing, number of subsequences possible = n^k

TC=O(n^k)
SC=O(1)
This approach is fine for small values of k. But if k tends to n, then it becomes an exponential 
time algo. So, we try applying DP.
===============================================================================================
Method 2:Using LCS
If we find out the longest palindrome possible in the string, then we can find out the 
minimum number of deletions required to convert it into a palindrome.
For this, we reverse the string and then find the LCS in the given string and the reversed string.

Then, minimum deletions required to convert the string into a palindrome=
length of string-length of longest palindrome=x (say)
If x<=k, then answer is YES, otherwise NO!

TC=O(n^2)
SC=O(n^2), but it can be decreased to O(n) as only two rows are required at a time.
*/

#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

int max(int a,int b) { return (a>b)?a:b; }

int lcs(char *str1,char *str2,int len1,int len2)
{
	int lcs_table[len1+1][len2+1];
	int i,j;
	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
		{
			if(i==0 || j==0)
				lcs_table[i][j]=0;
			else
			{
				if(str1[i-1]==str2[j-1])
					lcs_table[i][j]=1+lcs_table[i-1][j-1];
				else
					lcs_table[i][j]=max(lcs_table[i-1][j],lcs_table[i][j-1]);	
			}
			
		}
	}

	for(i=0;i<=len1;i++)
	{
		for(j=0;j<=len2;j++)
			printf("%d ",lcs_table[i][j]);
		printf("\n");
	}
	return lcs_table[len1][len2];
}

bool isKpalindrome(char *s,int n,int k)
{
	char revStr[n];
	int i,j=n-1;
	for(i=0;i<n && j>=0;i++)
	{
		revStr[j]=s[i];
		j--;
	}

	int lcs_res=lcs(s,revStr,n,n);
	printf("lcs is: %d\n",lcs_res);

	if(n-lcs_res<=k)
		return true;
	else
		return false;
}

int main()
{
	char str[]="abxa";
	int k=1,size=strlen(str);
	bool res=isKpalindrome(str,size,k);
	if(res)
		printf("Possible!\n");
	else
		printf("Not possible!\n");
	return 0;
}