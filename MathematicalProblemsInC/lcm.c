/*Find LCM and GCF or GCD
LCM is the smallest positive integer that is perfectly divisible by both n1 and 
n2.
--------------------------------------------------------------------------
The HCF or GCD of two integers is the largest integer that can exactly 
divide both numbers (without a remainder).

LCM Calculation by Finding GCD:
int n1, n2, i, gcd, lcm;

printf("Enter two positive integers: ");
scanf("%d %d",&n1,&n2);

for(i=1; i <= n1 && i <= n2; ++i)
{
    // Checks if i is factor of both integers
    if(n1%i==0 && n2%i==0)
        gcd = i;
}

lcm = (n1*n2)/gcd;
------------------------------------------------------------------------
For more methods to compute GCD, visit below link!
https://www.programiz.com/c-programming/examples/hcf-gcd
*/

#include <stdio.h>
#include <stdlib.h>

int calculateGCD(int c, int d)
{
	int x,gcd;
	for(x=1;x<=c && x<=d;x++)
	{
		if(c%x==0 && d%x==0)
		{
			gcd=x;
		}
	}
	return gcd;
}

int calculateLCM(int n1, int n2)
{
	int minMultiple=(n1>n2)?n1:n2;
	while(1)
	{
		if(minMultiple%n1==0 && minMultiple%n2==0)
		{
			printf("LCM is: %d\n",minMultiple);
			break;
		}
			
		minMultiple++;
	}
	return minMultiple;
}

int main()
{
	int n1=72;
	int n2=120;
	int gcd=calculateGCD(n1,n2);
	int lcm=calculateLCM(n1,n2);

	printf("GCD is:%d\n",gcd);
	
}