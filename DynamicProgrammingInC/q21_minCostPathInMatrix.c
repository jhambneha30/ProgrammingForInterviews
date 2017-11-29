/* MINIMUM COST PATH
Given a cost matrix m*n having a cost at each cell. Find the minimum cost it will take to reach 
each cell (m-1,n-1) from top left corner cell (0,0) if the only allowed directions to move from 
a cell are right, down and diagonally down.

Method 1: Brute force
At every cell, we have 3 choices: go right, down or diagonally down.
Thus, using brute force, we will have O(3^(m*n)) TC, where size of matrix=m*n
============================================================================================
Method 2: Using Greedy approach (wrong answer)

If we are greedy about minimum cost, we will get wrong answers.
Example: 
	10	3	4
	5	6	17
	13	4	11
Greedy result: 10->3->4->17->11 =45
Min cost:10->6->11=27
============================================================================================
Method 3: Using DP
At every cell, we have 3 choices: 
go right => (i,j+1)
go diagonal down => (i+1,j+1)
go down => (i+1,j)

Corner cases:

-----------------------Recursive equation---------------------------
MC[i,j]= 	|cost[i,j]+MC[i,j+1]
		min	|cost[i,j]+MC[i+1,j+1]		;otherwise
			|cost[i,j]+MC[i+1,j]
		0								;if i==m ||j==n		


Refer the q21_minCostPath_recursionTree.png to see the repeating sub problems. Thus we compute
the unique sub problems possible.
Unique sub problems = number of cells in the cost matrix = m*n
Thus we need a table of size m*n to store the results of sub problems.

----------------------Filling the table------------------------------
We start filling from the last cell and go row wise in the reverse order.

Example: 
	10	3	4
	5	6	17
	13	4	11	

DP table:		^
	27	20	32 / \
	20	17	28	|
	28	15	11	|
	<--------- 

The optimized min cost is 27.
TC=O(m*n) for DP solution to find the min cost.
SC=O(m*n)
---------------------------------------------------------------------------------------------
NOTE: WE CAN CONVERT THIS PROBLEM'S COST MATRIX INTO A GRAPH (with m*n nodes) AND THEN FIND THE 
MIN DIST BETWEEN THE NODES AT (0,0) AND (M-1,N-1). BUT THIS SOLUTION WOULD TAKE MORE TIME 
COMPARED TO DP IMPLEMENTATION.
---------------------------------------------------------------------------------------------
Sometimes, the question can be: find out the path followed to compute the min cost.
Then, we need to trace back the path in O(n) time.

OPTIMIZATION:
But, if we are asked to just compute the min cost and not the path, then we can reduce the SC
as at any time we just need two rows: current row and the next row. Thus, we can keep rewriting
the values in a matrix with 2xn cells.
*/

#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLS 4

int min(int a, int b)
{
	return a < b ? a: b;
}

int minCostPath(int cost_matrix[ROWS][COLS])
{
	int i,j;
	int dp_matrix[ROWS][COLS];
	dp_matrix[ROWS-1][COLS-1]=cost_matrix[ROWS-1][COLS-1];
	for(i=ROWS-2;i>=0;i--)
		dp_matrix[i][COLS-1]=dp_matrix[i+1][COLS-1]+cost_matrix[i][COLS-1];
	for(j=COLS-2;j>=0;j--)
		dp_matrix[ROWS-1][j]=dp_matrix[ROWS-1][j+1]+cost_matrix[ROWS-1][j];
	for(i=ROWS-2;i>=0;i--)
	{
		for(j=COLS-2;j>=0;j--)
		{
			dp_matrix[i][j]=cost_matrix[i][j]+ min(min(dp_matrix[i+1][j],dp_matrix[i][j+1]),dp_matrix[i+1][j+1]);
		}
	}

	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
			printf("%d ",dp_matrix[i][j]);
		printf("\n");
	}
	return dp_matrix[0][0];
}

int main()
{
	int cost[ROWS][COLS] = { {10, 2, 3, 4},
							 {4, 5, 8, 3},
							 {1, 5, 9, 2},
							 {6, 2, 4, 3}};
	int min_cost=minCostPath(cost);
	printf("Min cost path is: %d\n",min_cost);
	return 0;
}