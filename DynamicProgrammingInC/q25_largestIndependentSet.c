/* Largest Independent Set in a BT
Given a binary tree, find the size of the largest independent set [LIS] in it.

Independent set: Subset of all tree nodes such that there is no edge between any two nodes \
of the subset.Refer q11 for explanation. Instead of taking the root->data in this ques, we need 
to count that node in the independent set.
--------------------------------------------------------------------------------------------------

Note: If we directly try to solve this problem using the recursive equation, it will be an 
exponential time solution. We notice that the subproblems are repeating, so we use DP.

LISS(x)=max(1+sum(LIIS(grand children)),   sum(LISS(children)))

NOTE: We use post order traversal to compute the LISS. It means that we compute the LIS when
we visit the node for the first time. 

TC=O(n)*O(6) [because in worst case, we check 2 children and 4 grand children]
=O(n)


*/

