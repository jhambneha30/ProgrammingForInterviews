/*COIN CHANGE PROBLEM
Example: We are given the following coins. We can take any number of each coin to form a 
given amount. We need to find out the number of ways in which the given amount can be 
formed using the given coins.

coins[]={1,2,5,10,20}
amount=25
Way 1: 1*25
Way 2: 1*1 + 2*25
.
.
and so on!
=============================================================================================
Method 1: Brute force

First we need to see how many maximum number of times a given coin can be taken.
1:  25/1= 25 times
2:  25/2= 12 times
5:  25/5=  5 times
10: 25/10= 2 times
20: 25/20= 1 time

Thus the number of solutions possible=
		1 	 2 	  5   10    20
		25 * 12 * 5  * 2  * 1

The result can be taken as equivaent to 25^5 or n^m =>amount^(no. of coins).
TC=O(a^n); where n= amount given and m=number of coins given!

=============================================================================================
Method 2: Using DP
We can notice that to form an amount of 25, we can either 
Case 1: use a coin atleast once (then, the amount (say m) decreases by the value of the coin but coins remain the same)
Case 2: not use that coin at all (then, amount remains same but this coin is eliminated)

Now, refer to the picture q19_coinChange_recursionTree.png to see the repeating sub problems.
So, we can use DP.
To compute number of repeating sub problems, we see that we can have any value of amount=>(n+1)
and m possible combinations of coins.

Thus number of distinct sub problems=(n+1)*m 
-----------------------------------------------------------------------------------
Que: Why can't we have 2^m combinations of coins, rather just m combinations?
Ans: Because at every step, we are just discarding the largest coin and thus we cannot jumble
the coins while making combinations:
Possible coin combinations are
c1,c2,c3....cm
c1,c2,c3...c(m-1)
.
.
c1,c2
c1
These are m possible combinations only!
---------------------------------Recursive Equation----------------------------
coin[] is an array containing the coins.

CC[i,j]=	0			;if i==0
			1 			;if j==0
			CC[i-1,j]+CC[i,j-coin(i-1)]		;if coin[i-1]<=j
			CC[i-1,j]						;if coin[i-1]>j

-------------------------------Filling the table--------------------------------
Refer to the picture q19_coinChange_table.png to see the table

Use the above recursive equation to fill the table:
cc_table[i,j]=0			    ;if i==0
			  1 			;if j==0
			  cc_table[i-1,j]+cc_table[i,j-coin(i-1)]		;if coin[i-1]<=j
			  cc_table[i-1,j]								;if coin[i-1]>j

NOTE: We have taken coin[i-1] because the array coin starts from 0:
indices:		0	1 	2
coins_arr:		1 	2 	3
So, coin[i-1] refers to the coin at index i in the table!
--------------------------------------------------------------------------------
TC=O(n+1*m+1)=O(n*m) [To fill every cell, O(1) time is required.]
SC=O(n+1*m+1)=O(n*m)

*/

#include <stdio.h>
#include <stdlib.h>

coinChange(int coin_arr[],int n,int amt)
{
	int i,j,cc_table[n+1][amt+1];
	for(i=0;i<=n;i++)
		cc_table[i][0]=1;
	for(j=1;j<=amt;j++)
		cc_table[0][j]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=amt;j++)
		{
			if(coin_arr[i-1]<=j) //sum of 2 cases: used the coin+didnt use the coin
				cc_table[i][j]=cc_table[i][j-coin_arr[i-1]] + cc_table[i-1][j];
			else
				cc_table[i][j]=cc_table[i-1][j];
		}
	}
	return cc_table[n][amt];
}

int main()
{
	int coin_arr[]={2,5,3,6};
	int sum=10, size=sizeof(coin_arr)/sizeof(coin_arr[0]);
	int ways=coinChange(coin_arr,size,sum);
	printf("Number of ways in which the change can be given: %d\n",ways);
	return 0;
}