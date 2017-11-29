/*Applications of LL:
1) Storing the large numbers which can't be stored in the data types offered by C.
Each digit in the number is stored in one node of the L.
It is better to store such numbers in LLs rather than arrays because linked lists can 
be created and manipulated dynamically. While the arrays have to be specified with a
static size in the beginning.

2.) Storing polynomials. 
Ex: x^3 + 2x^2+ 12x + 2 can be stored in nodes having two integer fields and one character field.

NOTE: For the numbers and polynoomials stored this way, the addition, subtraction and
other operations (like differentiation) can be done by writing algorithms for these.
Standard operators won't work on them.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
