/* EDIT DISTANCE: Given two words word1 and word2, find the minimum number of operations
to convert word1 to word2. Following are the operations allowed:
i) insert a character
ii) delete a character
iii) replace a character
Note: Number of characters in word1 may or may not be equalt o number of characters in word2.
=============================================================================================
Method 1: Brute Force
Try to use all possible combinations.
w1: data, w2:parent
Then, number of combinations possible = 4^n; where n= max(w1.length,w2.length)
This is because, we have 4 options to perform on every character.
These 4 options are: 
-> no operation (if corresponding character in both strings is same)  
-> insert
-> delete
-> replace
=============================================================================================
Method 2: Using DP
We need to compare the charatcers one by one and keep going recursively trying all the 
options: replace, insert and delete. Then we should choose the one which gives minimum number
of operations.

m: Length of str1 (first string)
n: Length of str2 (second string)
1. If last characters of two strings are same, nothing much to do. Ignore last characters 
and get count for remaining strings. So we recur for lengths m-1 and n-1.
2. Else (If last characters are not same), we consider all operations on ‘str1’, 
consider all three operations on last character of first string, recursively compute minimum cost for all three operations and take minimum of three values.
	Insert: Recur for m and n-1
	Remove: Recur for m-1 and n
	Replace: Recur for m-1 and n-1

--------------------------------------Recursive equation-----------------------------------
 					               ED[i-1,j-1]	    ;if str1[i]==str2[j]
						 INSERT	  |ED[i,j-1]+1     |
ED[i,j] =			 min DELETE	  |ED[i-1,j]+1     |;OTHERWISE if str1[i]!=str2[j]
						 REPLACE  |ED[i-1,j-1]+1   |

-------------------------------------------------------------------------------------------
Refer to the editDistanceRecursionTreeAndRepeatingSubproblems.png to see the recursion tree
and notice that the subproblems are repating. So, we can use a table to find the min number
of operations required.

-------------------------------------------Algorithm-------------------------------------
While filling the table:
CORNER CASES are:
1. when i=0 and j varies; it means that converting nothing into something requires 
						  no. of operations=no. of characters in the target string.
2. when j=0 and i varies; it means that converting something into nothing requires 
						  no. of operations=no. of characters in the source string.
3. when i=j=0; no operations are required. (This is the anchor condition for recursion.)
These cells can be filled before we start filling the remaining table.

FILLING THE REMAINING TABLE:
Case 1: If the last two characters match, copy the top diagonal element to this cell.
Case 2: If they don't match, pick the min(left, top, top diagonal) and add 1 to fill this cell.
Case 2 works because:
-> the left depicts INSERT:ED[i,j-1] 
-> the top depicts DELETE:ED[i-1,j]
-> the top diagonal depicts REPLACE:ED[i-1,j-1]
	Thus, we pick the minimum of these three operations on the smaller strings and then add 1
	operation to it to get ED[i][j].




-----------------------------------------------------------------------------------------
http://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
*/

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){ return (a<b)?a:b; }

int editDistance(char *str1, char *str2,int len1,int len2)
{
	int ed_table[len1+1][len2+1];
	int i,j;
	for(i=0;i<=len1;i++)
	{
		ed_table[i][0]=i;
	}

	for(j=1;j<=len2;j++)
	{
		ed_table[0][j]=j;
	}

	for(i=1;i<=len1;i++)
	{
		for(j=1;j<=len2;j++)
		{
			if(str1[i-1]==str2[j-1])
				ed_table[i][j]=ed_table[i-1][j-1];
			else
				ed_table[i][j]=1+min(min(ed_table[i-1][j],ed_table[i][j-1]),ed_table[i-1][j-1]);
		}
	}
	return ed_table[len1][len2];
}

int main()
{
	char s1[] = {'g','e','a','k'};
	char s2[] = {'g','d','s','e','k'};
	int size1=sizeof(s1)/sizeof(s1[0]);
	int size2=sizeof(s2)/sizeof(s2[0]);
	int res=editDistance(s1,s2,size1,size2);
	printf("No. of operations required for conversion: %d\n",res);
	return 0;
}	