/*Convert BST to any possible max heap.

Method 1:
For this,
1. Inorder traverse the BST (numbers in ascending order or min-heap) - O(n)
2. Reverse the output - O(n)
This reversed output is the heap we require.

TC=O(n)
SC=O(1)

Method 2:
In place of taking 2 steps for conversion, just do REVERSE INORDER TRAVERSAL of the BST
Inorder traversal is: printing a node when it is visited the second time.
(i) Traverse the LST
(ii) Root
(iii) Traverse thr RST

Reverse inorder traversal is: gives numbers in descending order
(i) Traverse the RST
(ii) Root
(iii) Traverse thr LST

*/