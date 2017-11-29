/*KIRCHOFF THEOREM
No. of spanning trees of a complete graph=n^(n-2)
No. of spanning trees in incomplete graph can be found using Kirchoff theorm.

NOTE: For the simple graphs, there are no loops => all the diagonal elements will always be 0!
================================Algorithm:===================================
Kirchoff(matrix G) //G is the adjacency matrix
{
	1. Replace the diagonal 0's with degree of the nodes
	2. Replace the non diagonal 1's with -1
	3. Non diagonal 0's remain as it is.

	//Now, find the cofactor of any element  
	return cofactor(matrix G)
}
============================================================================== 
Kirchoff theorem will also give correct answer for complete graphs!
*/