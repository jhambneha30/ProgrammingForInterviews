/* Write a custom c-function to implement pow() function.
Method 1:
To find base^n,
Multiplication of base n times. => TC=O(n)

Method 2: DIVIDE AND CONQUER
x^10 = x^5 * x^5
x^11 = x^5 * x^5 * x
pow(x,n)=pow(x,n/2)*pow(x,n/2)   => T(n)=T(n/2)+constant = O(log n)
SC=O(logn) as stack requires log n cells (n -> n/2 -> n/4 ->.....-> 1, 
											where 1=n/2^k and 2^k=n => k=logn)

*/

#include <stdio.h>
#include <stdlib.h>

int powDC(int base,int power)
{
	int res;
	//anchor condition
	if(power==0)
		return 1;
	//if odd
	if(power & 1==1)
	{
		res=powDC(base,power/2)*powDC(base,power/2)*base;
	}
	else
	{
		res=powDC(base,power/2)*powDC(base,power/2);
	}
	return res;
}

int main()
{
	int base=2, n=5;
	int result = powDC(2,10);
	printf("Result is: %d\n",result);
	return 0;
}