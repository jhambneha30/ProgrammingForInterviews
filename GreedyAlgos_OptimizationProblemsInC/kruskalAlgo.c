/*KRUSKAL'S ALGORITHM to find MST

===============================Algorithm:====================================
Kruskal()
{
	Pick the shortest weight and check that it doesn't form a cycle!
}
==============================================================================
NOTE: KRUSKAL'S ALGO MAY FORM A FOREST!
ALSO, IT CAN LEAD TO A CYCLE.
This is because, here we add a new edge everytime, so it may form a cycle and we have 
to eliminate it.

IF the edge weights are distinct, we will always have a distinct MST and all the algorithms
will give us the same answer.
BUT if the edge weights are repeated, then we might get multiple MSTs but the total weight
will be same for all these MSTs.

Answer to the kruskal_prim_mstQuestion.png
a) True, b) True, c) False, d)True

Answer to the kruskal_prim_mstQuestion_2.png
a) True, b) True, c) True, d)False
*/