/* Fibonacci series using Dynamic Programming
The recursive equation is:
f(n)=f(n-1)+f(n-2);  otherwise
	=0;				 if n==0
	=1;				 if	n==1

Now, this recursive program is constituted of repeated function calls and gives a TC of O(2^n).
If somehow, we are able to store the already computed values of certain function calls, then
we can reduce the TC.

Check the table for T(n):
if(T(n) is empty)
	call f(n)
	add result of f(n) to T(n)


If tabularisation/DP is used, then TC can be reduced to O(n) from O(2^n)

Note: This method can't be applied on merge sort as the sub problems do not repeat in that 
method.

IN ORDER TO APPLY DP, WE NEED TO HAVE 
1. OPTIMAL SUBSTRUCTURE (able to divide the problem into smaller problems)
2. RECURSIVE EQUATION
3. OVERLAPPING SUBPROBLEMS

NOTE: If there are no repeating sub problems (point 3), then the problem is same as Divide
and Conquer!
*/

