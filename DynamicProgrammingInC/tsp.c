/* TRAVELLING SALESMAN PROBLEM (Find Hamiltonian cycle with min cost)
Find out a set of edges which when traversed will cover all the vertices so that the sum of
weights on edges is as minimum as possible.

Method 1: BRUTE FORCE
Find out all possible paths (cycles) and find the one with min cost.
TC=O(n!), even worse than O(2^n)

Method 2: Using DP
Refer to tspDPExample.png for example 

Recursive Equation:
i: current node, S: remaining nodes to be traversed
T(i,S)=min{(i,j)+(j,S-{j})} ; if s!=NULL
	  =(i,1)				; if S=NULL (assuming that the starting node is 1)

~~~~~~~~~~~~~~~~~~~~~IMPORTANT AND TYPICAL~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
It is important to know the number of subproblems to compute the TC and the number of unique 
subproblems to compute the table size required for DP.
Number of subproblems=for each level, possibilities for i * possible values for set S
Level 1: 1*n-1 = (n-1)*(n-2 C n-2)
Level 2: (n-1)*(n-2 C n-3)
Level 3: (n-1)*(n-2 C n-4)
.
.
Level n: (n-1)*((n C 2) C 0)

Summing:(n-2)* summation(n-2 C k), k=0 to n-2 =(n-1) * 2^(n-2)=O(n*2^n)
Therefore, the table size required= (n-1) * 2^(n-2) which is exponential, so DP is also 
exponential for TSP. It is NP-COMPLETE.

This TC is lesser than the brute force algo with TC=O(n!) but is not feasible practically.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

TC= No. of subproblems * time taken to solve 1 subproblem
	=O(n*2^n)*n
	=O(n^2 * 2^n)
SC=O(n*2^n)
*/