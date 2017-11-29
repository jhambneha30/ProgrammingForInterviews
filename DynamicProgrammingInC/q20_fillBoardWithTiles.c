/*TILING PROBLEM

Given a 2*n board, and tiles of size 2*1, count the number of ways to fill the given board
using 2*1 tiles. 

Method 1: Brute force
Every tile can be filled by either vertical tile or horizontal tile => O(2^n) ways

Method 2: Using DP

Case 1: If we use a vertical tile (2*1), then the remaining 2*(n-1) board is left.
Case 2: If we use a horizontal tile, then we have to use another horizontal tile under it. We
have no other option. Thus, 2*(n-2) board is left to be filled.

Thus, at every step (there are total n steps) we have two choices: use vertical tile or
use horizontal tile. To find the total number of ways, we need to sum both of these choices.

------------------------Recursive Equation---------------------------------------

f(n)=	f(n-1)  [if we use vertical tile]
		+f(n-2) [if we use horizontal tile]
	=   1		;if n=1
	=   1 		;if n=0

NOTE: This is same as fibonacci series.

-----------------------Filling the table------------------------------------------
There are 2^n possible subproblems in fibonacci series and n unique sub problems.
Thus we need a table as an array of size (n+1)

Indices:	0	1 	2 	3	4	5....
Table:		1 	1 	2 	3	5	8....

-----------------------------------------------------------------------------------

http://www.geeksforgeeks.org/tiling-problem/

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
Count the number of ways to tile the floor of size n x m using 1 x m size tiles

f(n)=	f(n-1)  [if we use vertical tile]
		+f(n-m) [if we use horizontal tile]
	=   1		;if n=0 or 1 or 2 
	
TC=O(n)
SC=O(n)

http://www.geeksforgeeks.org/count-number-ways-tile-floor-size-n-x-m-using-1-x-m-size-tiles/

*/

#include <stdio.h>
#include <stdlib.h>
int tilingSolution_2xl(n)
{
	int fibonacci_table[n+1],i;
	fibonacci_table[0]=1;
	fibonacci_table[1]=1;
	for(i=2;i<=n;i++)
	{
		fibonacci_table[i]=fibonacci_table[i-1]+fibonacci_table[i-2];
	}
	return fibonacci_table[n];
}

int tilingSolution_nxm(n,m)
{
	//Using tiles of size 1*m
	int tiles_table[n+1],i;
	tiles_table[0]=1;
	tiles_table[1]=1;
	tiles_table[2]=1;
	for(i=3;i<=n;i++)
	{
		tiles_table[i]=tiles_table[i-1]+tiles_table[i-m];
		printf("i:%d, val:%d\n",i,tiles_table[i]);
	}
	return tiles_table[n];

}

int main()
{
	//Given 2x1 tiles to fill a 2xl board. n=user input
	int l=3;
	int res_2xl=tilingSolution_2xl(l);
	printf("No. of ways the tiles can be arranged on the board of size 2x%d: %d\n",l,res_2xl);

	int n=7,m=4;
	int res_nxm=tilingSolution_nxm(n,m);
	printf("No. of ways the tiles can be arranged on the board of size %dx%d: %d\n",n,m,res_nxm);
	return 0;
}