/* Find the sum of digits in all numbers from 1 to N for a given N.
Example: N=13
then we have to find: 1+2+3+4+5+6+7+8+9+(1+0)+(1+1)+(1+2)+(1+3)
==================================================================================
Method 1:Naive approach
Algo:
sum=0
for(i=1 to N)
{
	temp=i;
	while(temp!=0)
	{
		sum+=(temp%10)
		temp=temp/10
	}
	return sum
}

TC=O(N* max no. of digits in N)
  =O(N logN base 10)
=================================================================================
Method 2:
We need to generalize a recursive formula for computing the required sum.
On analysing, we find out that the formula is:
sum(10^d -1) = sum((10^d-1))*10  +  10^(d-1)*45

sum(99999)->sum(9999)->sum(999)->sum(99)->sum(9)
To find out the sum of digits for 99999, we need to do computations=no. of digits
=>No. oc computations=logd to the base 10

TC=SC=logN base 10

SC due to the array and the stack


*/