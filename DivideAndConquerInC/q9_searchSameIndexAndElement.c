/*Given a sorted array of non repeated integer a[1---n], check whaether there is an index i
for which a[i] =i
Method 1:
O(n) scan to check if the element matches the index.

Method 2: Using Binary search
Example:		0	1 	2	3	4	5
				-3	0	1 	3	8	10

Notice that index and element are same at index 3.
Also, notice that on the left of this index 3, the indices have to be greater than the elements,
while on the right, the indices have to be smaller than the elements. This is because the array
is sorted.
Using this idea, we can go to left or right half of the array and thus can make use of the 
divide and conquer paradigm.

*/

#include <stdio.h>
#include <stdlib.h>

int findSame(int arr[],int start, int end)
{
	int mid;
	
	if(start<=end)
	{
		mid=(start+end)/2;
		if(mid==arr[mid])
			return mid;

		if(mid<arr[mid]) //search on left
			return findSame(arr,start,mid-1);

		return findSame(arr,mid+1,end);
	}
	return -1;
}

int main()
{
	int arr[6]={-3,0,1,3,8,10};
	int size=sizeof(arr)/sizeof(arr[0]);
	int index=findSame(arr,0,size-1);
	printf("Required index/element is: %d\n",index);
	return 0;
}