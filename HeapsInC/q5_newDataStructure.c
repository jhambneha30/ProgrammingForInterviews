/*Design a DS with operations: 
Find min, Find max, Delete min, Delete max, Insert, Delete

Soln: Use a min heap and a max heap for all the elements and a Double Linked list with nodes 
made up of a structure containing 3 fields: 
------------------------------------------------
| index in max heap | data | index in min heap |
------------------------------------------------
The min and max heaps will comtain addresses of the nodes instead of the data, so these will 
be arrays of pointers.
Time complexities:
1. Find min - O(1)
2. Find max - O(1)
3. Delete min - O(logn) 
Delete root from min heap, go to LL, go to max heap and delete the
corresponding index in max heap, then delete the node from LL inO(1)
4. Delete max - O(logn) - similar as above!
5. Insert - O(log n)
Insert in Min heap and Max heap - O(log n) and insert into LL - O(1)
6. Delete - O(n)
Search in min or max heap or in LL - O(n), then delete from heap -O(logn) and
delete from LL-O(1)

Note: Deletion can be improved by using a BST in place of Double LL as in BST, the deletion mostly
takes O(log n) [when the tree is not skewed]

*/

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
/*Ques: Convert max heap to min heap.
We cannot make use of max heap in this case because if we delete the max and keep inserting 
into min heap, TC=O(nlogn)
Better way is to consider the max heap as an array and build a min heap out of it
TC=O(n)
*/