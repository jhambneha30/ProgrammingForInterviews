/* Given two strings X and Y, find the minimum cost to make two strings equal using only
delete operations. Cost to delete a character in X is S and in Y is P.

Method 1: Using LCS
If we find the LCS in the two strings of lengths m and n and delete the remaining characters 
from both the strings, then we will get the required solution.

Example: s1: neha (m=4) 	s2: erans (n=5)
LCS=ea with length l=2

Then, cost of deleteing the remining characters=  (m-l)*S  +  (n-l)*P
=>cost=2*S +3*P 
====================================================== 
Method 2: Using DP 
This is similar to computing LCS: 
Case 1- If the last characters are same, no deleteions are required. Look at the remining strings
MC(i,j)=MC(i-1,j-1)  ;if s1[i]==s2[j]

Case 2- If the last characters are not same, then we need to consider the min of two cases:
(i) Delete the last character of s1
(ii) Delete the last character of s2

MC(i,j)=	min |	MC(i-1,j)+S  ;if s1[i]!=s2[j] , delete s1[i]
				|	MC(i,j-1)+P  ;if s1[i]!=s2[j] , delete s2[j]

-------------------------------Recursive equation:-------------------------------------
MC(i,j)=MC(i-1,j-1)  		 	;if s1[i]==s2[j]
		min |	MC(i-1,j)+S  	;if s1[i]!=s2[j] , delete s1[i]
			|	MC(i,j-1)+P  	;if s1[i]!=s2[j] , delete s2[j]
		0					 	;if i=j=0
		i*S 					;if j=0
		j*P 					;if i=0
NOTE: The anchor condition is when both i=0 and j=0
Refer to the q17_makeStringsEqual_recursionTree.png
Notice that there are repeating sub problems and in worst case the sub problems can be
O(n*m). Thus a table of size (n+1)x(m+1) is required.

-------------------------------Filling the table----------------------------------------
m=n=4, S=1,P=2
The table consists of 5 columns: 0 to 4 and 5 rows: 0 to 4
The cell at (0,0) will be filled with 0 as two empty strings are equal, so cost=0

Then, fill the first row as: 0, P, 2P, 3P... =0, 2, 4, 6, 8 
And the first column as:     0, S, 2S, 3S... =0, 1, 2, 3, 4 
This means that to make the string equal to an empty string, this is the cost incurred.

Then start filling the table row wise.
For every cell, we see if the characters are same, copy the cost from the diagonal top
If the characters are not equal, compute the min of((top+S),(left+P)).

Refer to q17_makeStringsEqual_DPtable.png for the filled table.

TC=O(n^2)= SC
*/

#include <stdio.h>
#include <stdlib.h>

int min(int a,int b) { return a<b?a:b; }

int min_cost(char *s1,char *s2,int s1_cost,int s2_cost,int n1,int n2)
{
	int mc_table[n1+1][n2+1];
	int i,j;
	mc_table[0][0] = 0;
	for(i=1;i<=n1;i++)
	{
		mc_table[i][0]=i*s1_cost;
	}
	for(j=1;j<=n2;j++)
	{
		mc_table[0][j]=j*s2_cost;
	}

	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[j-1])
				mc_table[i][j]=mc_table[i-1][j-1];
			else
				mc_table[i][j]=min((s1_cost+mc_table[i-1][j]),(s2_cost+mc_table[i][j-1]));

			// printf(" %d",mc_table[i][j]);
		}
		// printf("\n");
	}

	for(i=0;i<=n1;i++)
	{
		for(j=0;j<=n2;j++)
		{
			printf("%d ",mc_table[i][j]);
		}
		printf("\n");
	}

	return mc_table[n1][n2];
}

int main()
{
	char s1[]={'n','e','h','a'};
	char s2[]={'e','r','a','n'};
	int s1_len=sizeof(s1)/sizeof(s1[0]),s2_len=sizeof(s2)/sizeof(s2[0]);
	int s1_cost=1,s2_cost=2;
	int mc=min_cost(s1,s2,s1_cost,s2_cost,s1_len,s2_len);
	printf("The cost of making strings equal= %d\n",mc);
	return 0;
}




