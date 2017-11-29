/*Memory efficient Double LL.
Property used: A xor B xor A = B, B xor A xor B = A

Using this property of xor, we can save space taken up by pointers.
Suppose we have nodes: A --> B --> C (double LL)
A's extra field will contain 0 xor B
B's extra field will contain A xor C
C's extra field will contain B xor 0

Now none of the nodes will be pointing to anything, so LL appears to be disconnected.
But given one of the end points (either front or end), we can traverse the list.

Suppose we are given front node's address i.e. A. To move forward, xor with previous node's address.
We are at A, to go to B, Take extra field and xor with prev address => 0 xor extra=0 xor(0 xor B)=B
Thus wefind out the address of next node B and so on.

Similarly, given the address of last node, we can move backward by xorring with the address of next
node. 

Insertion into Double LL suing extra field. - O(n)

Insertion into Double LL suing extra field. - O(n)
For deletion, we need to remember the predecessor and the previous predecessor of the node to be 
deleted. 


*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
	struct node *arbitrary;
	struct node *prev;
};