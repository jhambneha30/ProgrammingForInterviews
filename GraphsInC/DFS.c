/*DFS
Visited: Seen the vertex
Explored: Visited the vertex and visited all its neighbours
3 cases:
Visited 	Explored
	0			0
	1			0
	1			1

We use a Visited[] array ofsize=no. of nodes which has all 0s initially => all 
nodes are unvisited except source node.

DFS uses a stack to keep track of the explored nodes.

SPACE COMPLEXITY:
For visited[] array, SC=O(V)
In the worst case, the graph is a chain of nodes
=>For recursion stack, SC=O(V)+O(V)
SC=O(V) for visited array + O(V) for stack

TIME COMPLEXITY:
------------------Using Adjacency list-----------------
Initialize visited array - O(V)
Each eleemnt in the list is visited exactly once --->O(E)* O(1), as constant 
amount of work is done in comparison with visited array and modifying the 
visited array.

TC=O(V+E)
SC=O(V)

------------------Using Adjacency Matrix-----------------
Initialize visited array - O(V)
Each eleemnt in the matrix is visited exactly once --->O(V^2)* O(1), as constant 
amount of work is done in comparison with visited array and modifying the 
visited array.

TC=O(V^2+V)=O(V^2)
SC=O(V^2)

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{

}
