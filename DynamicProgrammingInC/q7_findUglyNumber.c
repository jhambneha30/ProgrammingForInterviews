/* Find the kth ugly number.
An ugly number is one whose prime factors consist of either 2, 3 or 5 and 
no other prime number.
An exception is that 1 is also an ugly number.
=============================================================================================
Method 1: Brute Force
To find kth ugly number, keep on generating the ugly numbers until we reach kth ugly number.

Que: How to check if a number is ugly or not?
Ans: 
Step 1: Keep dividing with 2 until we are getting remainder 0.
Step 2: If the quotient==1, then it is ugly, otherwise keep dividing by 3 until remainder!=0.
Step 3: If the quotient==1, then it is ugly, otherwise keep dividing by 5 until remainder!=0.
If the quotient==1 => it is ugly, otherwise not ugly!

It is computationally very heavy. Also, it is difficult for us to compute the TC.

So, brute force method is not a feasible solution.
=============================================================================================
Method 2: Using DP
If we have formed an ugly number, then it is easier to form the next ugly number.
The next ugly number after x can be one of the following:
x*2 or x*3 or x*5

Now, while generating first k ugly numbers, we need to have three variables,say, i,j and k.
i will be pointing to the number a which gives the next potential ugly number candidate as 
a*2, j will point to the number b which gives the next potential ugly number candidate as 
b*3 and k will point to the number c which gives the next potential ugly number candidate as 
c*5.

This is a DP solution as a bigger ugly number (main problem) is being computed using the 
smaller ugly number (sub problem).


*/

#include <stdio.h>
#include <stdlib.h>

int min(int a,int b) { return (a<b)?a:b; }

int findKthUgly(int ugly_arr[],int size)
{
	ugly_arr[0]=1;
	int i2=0,i3=0,i5=0,x;
	int next_i2=ugly_arr[i2]*2,next_i3=ugly_arr[i3]*3,next_i5=ugly_arr[i5]*5;
	for(x=1;x<size;x++)
	{
		ugly_arr[x]=min(min(next_i2,next_i3),next_i5);

		if(ugly_arr[x]==next_i2)
		{
			i2++;
			next_i2=ugly_arr[i2]*2;
		}

		if(ugly_arr[x]==next_i3)
		{
			i3++;
			next_i3=ugly_arr[i3]*3;
		}

		if(ugly_arr[x]==next_i5)
		{
			i5++;
			next_i5=ugly_arr[i5]*5;
		}
	}
	return ugly_arr[size-1];

}

int main()
{
	printf("I'll find the kth ugly number for you. Enter the value of k!\n");
	int k;
	scanf("%d",&k);
	int ugly_list[k];
	int kth_ugly= findKthUgly(ugly_list,k);
	printf("kth ugly is: %d\n",kth_ugly);
	return 0;
}