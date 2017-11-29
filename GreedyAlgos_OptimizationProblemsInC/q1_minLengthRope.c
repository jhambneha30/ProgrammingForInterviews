/* Consider n ropes with different lengths, find an algorithm to tie up all the ropes 
into a single rope with minimum length.

If we have two ropes of length l1 and l2, then cost to tie up these ropes=l1+l2
Example: 2, 3, 5, 7, 9, 13

This problem is similar to HUFFMAN CODING. So, we apply similar method to compute te result.
We use a heap and keep deleting the two mins and iinserting their sum to the heap in every
iteration.
TC= Build min heap + n*(2 extract min and 1 insert)
    O(n) + 3nlogn = O(nlogn) 

*/