/* FLOYD WARSHALL: ALL PAIRS SHORTEST PATH
In this, we want to compute the shortes path between every possible pair of vertices in a graph.
We have seen Dijkstra (single source shortest path), which computes the shortest distance from 
one source to all possible nodes.

Method 1: Greedy method:
One way to compute all pairs shortest path is to apply Dijkstra algo on every vertex, but,
it is computationally very heavy.
TC  =V*O(ElogV) for sparse graphs
    =V*O(V^2logV) =O(V^3 log V) for dense graphs

Another problem is we can't use Dijkstra for negative weight edges. So, we need to use Bellman
Ford algorithm with TC=O(VE)
=> TC for dense graps =O(V^4) which is very very high
We can try reducing it using DP.

Method 2: Using DP (Floyd Warshall)
V={1,2...n} =>we have n vertices
i,j belong to V

--------------------------------------Recursive eqn:--------------------------------------
Case 1: if k>0
d(from i to j including vertices from 1 to k)=p
				=min(path p contains vertex k,path p does not contain vertex k)
				=min[d(from i to j excluding kth vertex (or using previous matrix)),
					d(from i to k (using k-1 vertices or using previous matrix)) + 
								d(from k to j(using k-1 vertices or using previous matrix))]
Case 2: if k=0 (i.e. if no vertex occurs between 2 vertices=>anchor condn for recursion)
d(from i to j)=weight of edge ij
--------------------------------------------------------------------------------------------


No. of subproblems=n^2 as we have to compute the every value in the matrix at each step.
No. of steps/iterations = No. of vertices that can be included in the path = n=O(n)
Therfore, TC=No. of subproblems *No. of steps/iterations=O(n^3)

SC=O(n^2) as at any time, we need two matrices only by reusing the matrices.

====================================Algorithm: BOTTOM UP=========================================

floyd_warshall(W) //W is the weight matrix for graph
{
	n=w.rows //n=no. of vertices
	D(0)=W
	for(k=1 to n) //we have to compute n matrices in n steps
	{
		Let D(k) be a new n*n matrix //SC=O(n^3) for this algo as new matrix for each step is created 
		for(i=1 to n)
		{
			for(j=1 to n)
			{
				D(k)[i,j]=min(D(k-1)[i,j],D(k-1)[i,k]+D(k-1)[k,j])
			}
		}
	}
	return D(n)
}
TC=SC=O(n^3)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 4

int min(int a,int b)
{
	return (a<b)?a:b;
}
//This implementation takes SC=O(n^2) :)
void floyd_warshall(int w[N][N],int dist[N][N])
{
	int i,j,k;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			dist[i][j]=w[i][j];
	}

	for(k=0;k<N;k++)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
					dist[i][j]=dist[i][k]+dist[k][j];
			}
				
		}
	}


}

int main()
{
	int w[N][N]={{0,11,1,6},
				 {11,0,7,3},
				 {1,7,0,2},
				 {6,3,2,0}};
	int output[N][N];
	floyd_warshall(w,output);

	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
			printf(" %d",output[i][j]);
		printf("\n");
	}

	return 0;
}