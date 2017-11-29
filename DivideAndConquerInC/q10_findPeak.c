/* Find the maximum element index in an array which is first increasing and then decreasing.
Example: 1,2,10,20,9,5,4
It can be viewed as a mountain with peak as 20 and number on left as 10 and number on right
as 9 (i.e. the numbers on both the sides of the ppeak have to be smaller than the peak.)
This is not the case with any other element in the array (see-2 or 5 for instance)

Method 1:
Scan the array and for every element, keep checking the left and the right elements. If we find
any element with both left and right elements less than the current element, then output it.

TC=O(n)
Sc=O(1)

Method 2: Using binary search
Find mid.
Case 1: If left element is smaller and right is smaller then required element is this one.
Case 2: If left element is smaller and right is greater then required element is on the right.
Case 3: If left element is greater and right is smaller then required element is on the left.

*/

#include <stdio.h>
#include <stdlib.h>

int findPeak(int *arr,int start, int end)
{
	int mid;
	if(start<=end)
	{
		mid=(start+end)/2;
		if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid])
			return arr[mid];

		if(arr[mid-1]>arr[mid] && arr[mid+1]<arr[mid]) //go left
			return findPeak(arr,start,mid-1);

		return findPeak(arr,mid+1,end);

	}
	return -1;
}

int main()
{
	int arr[7]={1,2,10,20,9,5,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	int peak=findPeak(arr,0,size-1);

	printf("Max element is: %d\n",peak);
	return 0;
}