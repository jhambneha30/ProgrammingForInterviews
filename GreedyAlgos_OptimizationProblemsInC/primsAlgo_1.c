/* MST and PRIM'S ALGORITHM
#MSTs in a complete graph=n^(n-2). If we try to find the least cost MST, then we 
may have to check all the STs which will take (n^n) exponential time.

How does Prim’s Algorithm Work? The idea behind Prim’s algorithm is simple, a spanning tree 
means all vertices must be connected. So the two disjoint subsets of vertices (one already 
included in ST and other containing the left over vertices) must be connected to make a 
Spanning Tree. And they must be connected with the minimum weight edge to make it a Minimum 
Spanning Tree.

===============================Algorithm:====================================
Prim()
{
	
}
==============================================================================
NOTE: PRIM'S ALGO GROWS AS ONE TREE. IT NEVER FORMS A FOREST!
ALSO, IT WON'T EVER LEAD TO A CYCLE.
This is because, here we add a new node everytime.
*/