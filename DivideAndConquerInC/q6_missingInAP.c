/* Finding the missing number in arithmetic progression.
Since, one of the numbers is missing in the given series, the last term must be the (n+1)th 
term.
We can use this logic to compute the common difference. 
Note: We just can't see the difference between first and second element or between 
any two consecutive elements (for that matter) because, the missing element can be any. 
So, we may compute wrong common difference. However, the first and last term cannot be 
missing as that would not make any sense.
So, we use the formula for nth term to compute the common difference and use the last 
term for it.

Example: -2,0,2,4,6,8,12,14,16,18,20 => 11 elements
last term= T(n+1)=a+(n+1-1)d as the formula is: T(n)=a+(n-1)d
		 =>20=-2+(11)d 
		 =>d=2

Method 1:
Now, we can simply scan and keep adding the common difference to every element and check 
if next element is same or not.

TC=O(n)
SC=O(1)
===========================================================================================
Method 2: Using binary search

Step 1: Find the middle element. Check if it is in the right position by calculating the
(index+1)th term. 

Step 2:If it comes out to be equal to this element => none of the elements from
	the beginning of the series is missing. So, go to right and repeat this until we
	find an anomaly.

	If the element computed comes out to be different, then we go left and keep going left
	till we find the missing term. 

Example: -2,0,2,4,6,8 | 12,14,16,18,20 => 11 elements, mid= 5 =>8
		Here, if we compute T(6), it comes out to be 8 => it is at correct position => go right
		mid in right=2 =>16

		Now, T(9)=-2+8*2=14 =>not at correct position => go left and find mid
						12 14    mid=6 =>12
		If we check the 7th term, it comes out to be 10. It means an element on the left has 
		to be missing, Now, since we have checked all the elements, we return the 7th term which is
		missing (10 in this case!)

TC=O(log n)
SC=O(log n) for recursion stack, O(1) for stack.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int findTerm(int arr[],int k,int c)
{
	int element=arr[0]+(k-1)*c;
	return element;
}

int findMissingTerm(int arr[],int c,int start,int end)
{
	int mid;
	//return infinity if start moves beyond end
	if(start>end)
		return INT_MAX;
	mid=(start+end)/2;
	//if the element before or after missing element is found, return missing element
	if(mid>0 && arr[mid-1]-arr[mid]!=c)
		return findTerm(arr,mid,c);
	if(mid<end && arr[mid+1]-arr[mid]!=c)
		return findTerm(arr,mid+1,c);
	if(findTerm(arr,mid+1,c)==arr[mid])
		return findMissingTerm(arr,c,mid+1,end);
	return findMissingTerm(arr,c,start,mid-1);


}

int findCommonDiff(int arr[],int n)
{
	int a=arr[0];
	int last=arr[n-1];
	//T(n+1)=a+((n+1)-1)d
	int d=(last-a)/n;
	
	return d;

}

int main()
{
	int ap[5]={3,9,12,15,18};
	// int ap[11]={-2,0,2,4,6,8,10,12,14,16,20};
	int size=sizeof(ap)/sizeof(ap[0]);
	int cd=findCommonDiff(ap,size);
	printf("Common difference:%d\n",cd);
	int missingTerm=findMissingTerm(ap,cd,0,size-1);
	printf("missing term is %d\n", missingTerm);
	return 0;
}