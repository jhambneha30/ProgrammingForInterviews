/* Given an array 2n integers in the following format a1,a2,a3,.... b1,b2,bn shuffle
the array to a1b1 a2b2 a3b3... anbn.
Example: 1 2 3 4 5 6 7 8
Output:  1 5 2 6 3 7 4 8

Method 1: Take an extra array and use two pointers to copy the elements from the first and 
second pointers.

TC=O(n)
SC=O(n)
=========================================================================================
Method 2: Using Divide and Conquer
First, divide the problem into two halves such that the 2nd part of first half is swapped with
the 1st part of second half as:
			1 2 5 6 | 3 4 7 8
And keep repeating this until 
			1 5 | 2 6       3 7 |4 8

T(n)=2T(n/2)+O(n/2) = O(nlogn) (equation is same as merge sort)
The time taken to solve the problem of n size = time taken to solve two problems of size n/2 +
												time taken to divide problem into 2 sub halves
Note: O(n/2) time will be taken to swap the elements

SC=O(log n) for recursive version
SC=O(1) for iterative version
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int arr[],int start,int mid,int end)
{
	int mid_left=(start+mid)/2, mid_right=(mid+1+end)/2;
	int l=mid_left+1,r=mid+1;
	printf("mid_left:%d mid_right:%d\n",mid_left,mid_right);
	while(l<=mid && r<=mid_right)
	{
		int temp=arr[l];
		arr[l]=arr[r];
		arr[r]=temp;
		l++;
		r++;
	}
	int i;
	for(i=0;i<=end;i++)
	{
		printf(" %d",arr[i]);
	}
	printf("\n");
}

void shuffle(int arr[],int start,int end)
{
	int mid;

	if(start<end)
	{
		mid=(start+end)/2;
		printf("mid is:%d\n",mid);
		//Divided into 2 lists, now swap the two halves
		//List 1 is from start to mid, List 2 is from mid+1 to end
		swap(arr,start,mid,end);
		shuffle(arr,start,mid);
		shuffle(arr,mid+1,end);
	}
	return;
}

int main()
{
	int arr[8]={1,2,3,4,5,6,7,8};
	int size=sizeof(arr)/sizeof(arr[0]);
	shuffle(arr,0,size-1);
	return 0;
}