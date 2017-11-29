/* Given an array containing 1's and 0's in which all 0's appear before all 1's then 
count the number of 1's in an array.
Example: 00000000000000...0000111111111, given array size=n

Step 1. Find the middle of the array.
If it is 0 =>go right
If it is 1 =>then check the number left to it. 
	If the left number is 0 => this is the starting index and so we can compute 
	number of 1's=n-this+1
	If the left number is 1, then call left and repeat step 1.


T(n)=T(n/2)+O(1) = O(logn)
TC=O(log n)


*/

#include <stdio.h>
#include <stdlib.h>

int findStartPos(int *arr,int start,int end)
{
	int mid;
	if(start==end)
		return start;
	if(start<end)
	{
		mid=(start+end)/2;
		if(arr[mid]==0)
		{
			return findStartPos(arr,mid+1,end);
		}

		if(arr[mid-1]==0)
			return mid;
		else
			return findStartPos(arr,start,mid-1);
	}
}

int main()
{
	int arr[15]={0,0,0,0,0,0,1,1,1,1,1,1,1,1,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	int pos=findStartPos(arr,0,size-1);
	printf("Starting position of 1 is: %d\n",pos);
	int numOnes=size-pos;
	printf("Number of 1's= %d\n",numOnes);
	return 0;
}