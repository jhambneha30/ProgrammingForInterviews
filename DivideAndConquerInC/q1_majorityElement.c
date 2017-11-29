/* Given an array of size n, find an element that occurs more than n/2 times.
Method 1: Using LINEAR SEARCH
If an element occurs at index i, then to be the majority element, it must also occur at index
i+n/2

We just need to scan half the array because for an element to be present more than half times,
it should atleast be present at the middle position.

TC=O(n/2)=O(n)
SC=O(1)
============================================================================================
Method 2: Using Binary search
We know for sure that if an element is a majority element, then it has to be present at the
mid. 

Step 1. Find the element at mid and check if it is also present at index mid-1.
To find the left bound of the element using binary search:
Step 2. If no, then mid is the left bound of this element's occurence. Break out of the loop.
If yes, then we need to find the left limit. 
Step 3. Apply binary search on left half. Whatever index i
we get, check if the same element is present at the index i-1 and repeat from step 2.
Step 4. When we find the left limit l of the element which is a candidate to be the majority 
element, we need to check if it is actually the majority element.
For this, we check if the same element is present at index l+n/2. If yes, then it is the
majority element, otherwise NO!

*/

#include <stdio.h>
#include <stdlib.h>
#define COUNT 7

int binarySearch(int arr[],int start,int end, int item)
{
	int mid,left=-1;
	if(start<=end)
	{
		mid=(start+end)/2;
		if(arr[mid]==item)
		{
			if(arr[mid-1]==item)
				left=binarySearch(arr,start,mid-1,item);
			else
				left=mid;
		}

		if(arr[mid]<item)
			left=binarySearch(arr,mid+1,end,item);

		
	}
	return left;
}

int findMajorityUsingBinarySearch(int arr[])
{
	int mid=COUNT/2, candidate=arr[mid];
	int left_bound;
	//We need to find the left bound of the candidate's occurence
	if(arr[mid-1]==candidate)
		left_bound=binarySearch(arr,0,mid-1,candidate);
	else
		left_bound=mid;

	printf("left bound is: %d\n",left_bound);
	printf("checking if majority: %d\n",arr[left_bound+(COUNT/2)]);
	if(left_bound!=-1 && arr[left_bound+(COUNT/2)]==candidate)
		return candidate;

	return -1;
		
}

int main()
{
	int arr[COUNT]={1,2,3,3,4,4,4};
	int majority=findMajorityUsingBinarySearch(arr);
	
	if(majority==-1)
		printf("No majority element exists!\n");
	else
		printf("Majority element is: %d\n",majority);



	return 0;
}