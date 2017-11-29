/*CUTTING A ROD
Given a rod of length n inches and an array of prices that contains the prices of all pieces of 
size smaller than 'n'. Find the max value obtainable by cutting up the rod and selling the piece.
===============================================================================================
Method 1: Brute Force
Let the given rod be -------- =>8 inches long
We can make cuts at 7 places => we have 2 choices at 7 places: either we can make a cut or we 
cannot.
1. We consider all the possible cut combinations. -O(2^n)
2. For each combination, we compute the profit by selling pieces - O(n)
3. Compute the max profit possible - O(2^n)

TC=O(2^n * n)  --> exponential
So, we try to use DP
===============================================================================================
Method 2: Using DP:-Approach 1
We have an array profit containing the profits which can be made by selling rods of various
length pieces.

-----------------------------------Recursive Equation---------------------------------
MC[i]=max{profit(k)+MC[i-k]}; where 1<=k<=i
If we try building the recurson tree, we find that the sub problems are repeating.
We'll have exactly n^2 subproblems.
This is because for every smaller part of the rod with length x, we can make x-1 cuts.

For rod length=1, cuts possible=0
For rod length=2, cuts possible=1
For rod length=3, cuts possible=2
.
.
For rod length=n, cuts possible=n-1
Total combinations of cuts possible = 0+1+2+....+(n-1)=O(n^2)
If we try building the recursion tree, we find out that the sub problems are repeating.
Refer q25_cuttingRod_recursionTree.png for the recursion tree. Notice that the subproblems for
rod of length 7 are repeating.

So we can use a table of size (n+1) * (n+1).
----------------------------------Filling the table------------------------------------
Example: Rod length=5, profits={2,5,7,8}

			--->length of the rod--->
				0			1 			2			3			4			5
		----------------------------------------------------------------------	
		(2)	1 	0			2			4			6			8			10
		(5)	2	0			2		m(4,5+0)=5 	m(6,5+2)=7 	m(8,5+5)=10	  m(10,5+7)=12
		(7)	3	0			2			4		m(7,7+0)=7 	m(10,7+2)=10  m(12,7+4)=12	
		(8)	4	0			2			4			7 		m(10,8+0)=10  m(12,8+2)=12
Note:m means max in the above matrix
So, the max profit possible=12

Algorithm used:
for(j=0 to rod_len)
	table[1,j]=j*profits[1];

for(i=2 to n)
{
	for(j=0 to rod_len)
	{
		if(i<=j)
			table[i][j]=max(table[i-1][j],profits[i]+table[i][j-profits[i])
		else
			table[i][j]=table[i-1][j]
		
	}
}

TC=O(n^2)
SC=O(n^2)

https://www.youtube.com/watch?v=IRwVmTmN6go
==========================================================================================
Method 3: Using DP:-Approach 2
For this, we use an array as a table of length n.
We use the below solution:
mc_table[i]=max{profit(k)+mc_table[i-k]}; where 1<=k<=i

TC=O(n^2)
SC=O(n)



https://www.youtube.com/watch?v=ElFrskby_7M
*/