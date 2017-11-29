/* Given a Binary matrix, find the largest square sub matrix with all 1's. 

Method 1: Brute Force
To determine a sub matrix, we need 4 indices: (i,j) for top left cormer and 
(k,l) for right bottom corner. We might think that we have n^4 choices to choose the sub matrices.
But, it doesn't work that way.

This is because, the index l can be chosen only when feasible.
For example, in a 4x4 matrix, 
			0	1	2	3
		-----------------
	 0	|	1	1	1	1
A=	 1	|	0	0	1	1
	 2	|	1	1	1	1
	 3	|	0	1	1	1

if (i,j)=(0,1) and k=3, then for the matrix to be a square matrix, l=4
But (3,4) does not exist in this matrix, so it is not a sub square matrix for matrix A.
We can see that the no. of choices for forming sub square matrices=n^3 (because it depends on
choice of 3 variables rather than 4.)

So, for each square sub matrix, time taken to check if it contains all 1's =O(n)
=>TC=O(n^3)* O(n)=O(n^4)
==============================================================================================
Method 2: Using DP
For this, we keep examining each element of the DP table(which can be same as the input matrix
and thus space can be saved). 

We consider each number in the matrix as the bottom right of a square matrix.
=>at (0,0), sub square matrices possible is of size: 1x1
  at (1,1), sub square matrices possible are of size: 1x1, 2x2
  at (1,2), sub square matrices possible are of size: 1x1, 2x2
  at (3,2), sub square matrices possible are of size: 1x1, 2x2, 3x3 and so on.

We need to compare it with 4 numbers:
1. top element
2. left element
3. left diagonal element
4. corresponding element in the matrix

table[curr_index]= min(top element,left element,left diagonal element) + matrix[curr_index]

-----------------------------Algorithm-------------------------------------------
Step 1. Copy the elements of first row and first column as it is.

Step 2. Now, proceed in row major order (or in column major order). For every cell in the
DP table, find the min(top,left,left diagonal) and add the value at this position in the 
input matrix.
If the value at this position in the input matrix==0, then write 0 at this position in the 
DP table.
-----------------------------------------------------------------------------------

*/
#include <stdio.h>
#include <stdlib.h>
#define N 5

int min(int a, int b){ return (a<b)?a:b; }

void largestSquareSubmatrixOf1s_DP(int bMatrix[N][N],int table[N][N])
{
	int i,j;
	int max_val=-1, max_x, max_y;
	for(i=0;i<N;i++)
		table[i][0]=bMatrix[i][0];
	for(j=1;j<N;j++)
		table[0][j]=bMatrix[0][j];

	for(i=1;i<N;i++)
	{
		for(j=1;j<N;j++)
		{
			if(bMatrix[i][j]==0)
				table[i][j]=0;
			else
				table[i][j]=min(min(table[i-1][j],table[i][j-1]),table[i-1][j-1])+bMatrix[i][j];

			if(table[i][j]>max_val)
			{
				max_val=table[i][j];
				max_x=i;
				max_y=j;
			}
		}
	}

	printf("Size of square matrix: %d, Coordinates of bottom right:(%d,%d)\n",max_val,max_x,max_y);
}

int main()
{
	int binaryMatrix[N][N]={{1,1,1,1,1},
							{0,1,1,1,1},
							{1,1,1,1,1},
							{0,1,1,0,1},
							{0,0,1,1,1}};
	int dp_table[N][N];

	largestSquareSubmatrixOf1s_DP(binaryMatrix,dp_table);

	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf(" %d",dp_table[i][j]);
		printf("\n");
	}

	return 0;
}