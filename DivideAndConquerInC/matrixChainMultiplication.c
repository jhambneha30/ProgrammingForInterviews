/* MATRIX CHAIN MULTIPLICATION
In order to multiply two matrices of size: p*r and r*q, we need to do (p*r*q) scalar 
multiplications.

# The way we parenthesize has a significant impact on the number of multiplications 
required to carry out matrix chain multiplication.

To parenthesize matrices, number of ways differ depending on the way the matrices are 
multiplied.
		Number of matrices		No. of ways
				2					1
				3					2			((AB)C) and (A(BC))
				4					5
				5					14
				n+1 				(2n)! /((n+1)! * n!)

=============================================================================================
Recursive equation:
If we have matrices from i to j as: A(i) A(i+1).................A(j)
The size of matrix A(i) is p(i-1)*p(i).....and that of A(j) is p(j-1)*p(j)
and m is the minimum number of scalar multiplications required, then:
-----------------------------------------------------------------------------
m[i,j]=min(m[i,k]+m[k+1,j]+(p(i-1)*p(k)*p(j))) where i<=k<j; otherwise(i<j)
	  = 0; when i=j
-----------------------------------------------------------------------------
Overlapping subrpoblems: Refer to the "matrixChainMultiplication_RecursionTree.png" to see the
recursion tree. Notice that the size of the tree is around 2^n and many subproblems 
are repeating. Thus if we store the repeating subproblems in a table, we can reduce the TC
from O(2^n) toO(n^3).

We can use two approaches: 
1. TOP DOWN (as we recursively go down the tree, keep storing the results when we find a new
subproblem not stored already!)

MCM table:									Subrpoblem size				Number of subproblems
(1,1)	(2,2)	(3,3)	(4,4)						1 							4
(1,2)	(2,3)	(3,4)								2 							3
(1,3)	(2,4)										3 							2
(1,4)												4							1

Thus, #subproblems for a problem with n matrices=n+(n-1)+........1= O(n^2)
#subproblems=O(n^2) and time taken to compute one subproblem =O(n) [as n splits need to be examined]
Thus, TC=O(n^3)
SC=time taken to store the tabe=O(n^2)


2. BOTTOM UP (store the smaller unique problems in the table first followed by the larger ones 
we move up the tree!)
These are always implemented in an iterative manner and so we use the already computed 
subproblems to uild the final solution.

====================================Algorithm: BOTTOM UP=========================================
First, we take as input an array containing the sizes of the matrices to be multiplied:
				A1   *   A2   *   A3   *   A4
			   (1*2)    (2*3)    (3*4)    (4*1)
			 (p0*p1)  (p1*p2)   (p2*p3)   (p3*p4) 
In the array, we have: p0,p1,p2,p3,p4
So, we first count the number of matrices as arr.length-1

matrix_chain(p) //p is the array of sizes
{
	int n=p.length-1;
	//Declare two matrices of sizes n*n: m[n,n] to store the optmized values, 
	//s[n,n] to store the split so that we can compute the exact result

	//make the first row of matrix m=0 [when a single matrix needs to be multiplied]
	for(i=0 to n-1)
		m[i,i]=0;
	for(l=1 to n-1) //defines the number of matrices to be multiplied (moving over rows)
	{
		for(i=1 to n-l+1) (moving over columns)
		{
			j=i+l-1
			m[i,j]=infinity;
			for(k=i to j-1) (splitting the chains)
			{
				res=m[i,k]+m[k+1,j]+(p[i-1]*p[k]*p[j]);
				if(m[i,j]>res)
				{
					m[i,j]=min;
					s[i,j]=k;
				}
			}

		}
			
	}
	return m and s;
}

NOTE: BOTH THE APPROACHES HAVE THE SAME UNIQUE SUBPROBLEMS.
=============================Algorithm: TOP DOWN/MEMOIZATION (USING RECURSION)===============
memoized_matrix_chain(p)
{
	n=p.length
	make an n*n matrix m[n,n]
	for(i=1 to n)
		for(j=1 to n)
			m[i,j]=infinity

	return lookup_chain(m,p,i,j);
}

lookup_chain(m,p,i,j)
{
	if(m[i,j]<infinity)
		return m[i,j];

	if(i==j)
		m[i,j]=0;
	else
	{
		for(k=i too j-1)
		{
			res=m[i,k]+m[k+1,j]+(p[i-1]*p[k]*p[j]);
			if(m[i,j]>res)
				m[i,j]=res;
		}
	}
	return m[i,j];
}

TC=O(n^3) SC=O(n^2) for table + O(n) for recursion stack = O(n^2)
*/