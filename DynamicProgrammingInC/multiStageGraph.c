/* MULTI STAGE GRAPH: Find the smallest path from source to destination
Let number of nodes=n

Method 1: Brute Force:
Find out all possible paths and choose the smallest one from source to destination.
TC=O(2^(N^2)) (because for every possible edge, we either can have that edge or we can not have it)

Method 2: Using Dijkstra
TC=O(ElogV)
The problem is it finds the shortest path from source to all nodes, while we want ot find the shortest path to one defined destination. So, it unnecessarily takes more time.

Method 3: Using Greedy
TC=O(N)
It keeps choosing the shortest outgoing edge from the current node.
But, the problem is it might give wrong answer (non optimal value).

Method 4: Using DP

Optimal substructure:
						| S->A +M(2,A)
M(stage 1, source S)=min| S->B +M(2,B)
						| S->C +M(2,C)

Anchor condition at last stage when only one edge is left, take its weight
M(N-1,X)=X->D; X:node at the (N-1)th stage and D: Destination node
SC=O(no. of stages=depth of tree)=O(k)
TC=O(k^N); where k is the number of stages (reason- at every level, there can be N nodes)
This is an exponential algorithm if we implement it using normal recursion. Lets try DP!

So, now we need to check if there are any overlapping subproblems. if we notice closely, we 
fin out that the no. of subproblems=O(no. of nodes in the graph), as for every vertex, we find
the minimum remaining path to destination.
No. of subproblems=N-1 exactly (destinaton vertes is excluded, obviously!)

So, the Dp table will be an array of size N-1

=========================Algorithm Bottom Up Implementation=============================
MSG(costMatrix)
{

	for(i=n to 1)
	{
		for(j=i+1 to n)
		{
			table[i]=min(cost[i,j]+table[j]);
		}
	}
}

TC=no. of subproblems* work done to compute every subproblem
In this case, for every node, work done at the subproblem =no. of nodes greater than this node.
TC=(N-1)+(N-2)+....1=O(N^2)
This is similar to insertion sort!

*/

#include <stdio.h>
#include <stdlib.h>
#define N 8
#define INF 99999

int max(int a,int b)
{
	return (a>b)?a:b;
}

void msg_bottomUp(int cost[N][N],int table[N])
{
	int i,j;
	for(i=0;i<N-1;i++)
	{
		table[i]=INF;
	}
	table[N-1]=0;

	for(i=N-2;i>=0;i--)
	{
		// printf("============i:%d=========\n",i);
		for(j=i+1;j<N;j++)
		{
			// printf("~~~~~~~~~j:%d~~~~~~~~~~\n",j);
			if(cost[i][j]+table[j]<table[i])
				table[i]=cost[i][j]+table[j];
			// printf("if(%d+%d<%d) then table[%d]=%d+%d\n",cost[i][j],table[j],table[i],i,cost[i][j],table[j]);
		}
	}
	
}

int main()
{
	int msg_cost[N][N]={{0,1,2,5,INF,INF,INF,INF},
						{INF,INF,INF,INF,4,11,INF,INF},
						{INF,INF,INF,INF,9,5,16,INF},
						{INF,INF,INF,INF,INF,INF,2,INF},
						{INF,INF,INF,INF,INF,INF,INF,18},
						{INF,INF,INF,INF,INF,INF,INF,13},
						{INF,INF,INF,INF,INF,INF,INF,2},
						{INF,INF,INF,INF,INF,INF,INF,INF}};
	int msg_table[N],x;

	msg_bottomUp(msg_cost,msg_table);
	for(x=0;x<N;x++)
	{
		printf("%d ",msg_table[x]);
	}
	printf("\nShortest distance is: %d\n",msg_table[0]);
	return 0;
}