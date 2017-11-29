/* DIJKSTRA'S ALGORITHM: To find SINGLE SOURCE SHORTEST PATH
For this, we use: relaxing and edge (v,u)
	if(d(u)>d(v)+d(u,v))
		d(u)=d(v)+d(u,v)
d(u): distance from source to u
d(v): distance from source to v
d(u,v): distance on the edge (u,v)

===============================Algorithm:====================================
Dijkstra(G,w,s) //w is the weight matrix, S: set of vertices whose shortest path has been decided
{
	1. Initialize single source(G,s) //O(v) taken: Give the values to every node: give 0 to source and INFINITY to others
	2. S=NULL
	3. Q=G.v  //Build min heap - O(v)
	4. while(Q!=NULL)      -----O(vlogv for extract min+Elogv for relaxations )=O(v^2 log v)
	{
		5. u=Extract_min(Q)    -------O(log v)
		6. Add u to set S => S=S union {u}
		7. for each vertex v belongs to G.adjacent(u)    -----O(E)
		{
			8. Relax(u,v,w)   //executed by calling decrease_key() ---O(log v)
		}
	}
}
==============================================================================
TC is computed using AGGREGATE ANALYSIS
No. of relaxations <= No. of edges ---- O(E)
So, TC=O(v+v+vlogv+Elogv) = O(E log v)


NOTE: 
1. DIJKSTRA ALGO DOES NOT WORK FOR GRAPHS WITH NEGATIVE WEIGHT CYCLES. The problem is that
Dikstra algo does not have the capacity to output that the graph contains negative weight 
cycle (it can't differentiate if the graph contains negative wt edge or negative wt cycle),
so we avoid giving graphs with negative wts to it to avoid wrong answers.
2. If a graph is disconnected, no algo can find out the shortest paths.
*/

#include <stdio.h>
#include <stdlib.h>
#define OBJECT_COUNT 7

