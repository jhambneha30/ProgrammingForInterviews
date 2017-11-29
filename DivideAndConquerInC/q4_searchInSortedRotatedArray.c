/*Search an element in sorted rotated array.
Ex: 7,8,9,10,1,2,3,4,5,6
Search 4.
==========================================================================================
Method 1: Find out the number where the array should have ended if it was sorted. In the
above example, find where 10 is.

Step 1. Check mid: (here mid position has 2 - not ending of the given increasing sequence)
First, we need to check if this is the ending of an increasing sequence or not. So, we
the immediate left and right elements. if left element is smaller and right is also smaller,
then, itis the ending of the sequence. Otherwise, we need to search further! 
Now, we need to check whether we should search for the last element on left or on right.

Step 2. For this, we check the numbers at start (here 7) and at end (here 6).
if(arr[start]>arr[mid]) =>last element lies on left of mid
if(arr[start]<arr[mid]) =>last element lies on right of mid
In the above example, we search on left.  ----O(logn)
Repeat steps 1 and 2 till we find the required element x. Once found, our lists get divided
into two lists : (start to x) and (x to end)

Step 3. Now, to search for the given item, we check in which of these two lists does it lie.
And then apply binary search! --O(logn)

TC=O(logn)+ O(logn)=O(logn)

But using this method requires two scans. We now try to do it in single scan!
==========================================================================================
Method 2:
Step 1. Find mid and check which side of the mid is a sorted array. In the ex given above,
If mid=2, right side is a sorted array.

Step 2. If the item to be searched lies on the side of sorted array, then we can apply 
binary search on it and find it's index.
Otherwise, go to the non sorted side and repeat from step 1.


*/
#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int p, int q,int item)
{
	int mid,res=-1;
	if(p<=q)
	{
		mid=(p+q)/2;
		if(item==arr[mid])
			return mid;
		if(item<arr[mid])
			res=binarySearch(arr,p,mid-1,item);
		else
			res=binarySearch(arr,mid+1,q,item);

	}
	return res;
}

int findEnd(int a[],int start,int end)
{
	int res;
	if(start<=end)
	{
		int mid=(start+end)/2;
		printf("Mid elt:%d\n",a[mid]);
		
		if(a[mid-1]<a[mid] && a[mid]>a[mid+1])
			return mid;
		if(a[start]>a[mid])
		{
			//search left
			res=findEnd(a,start,mid-1);
		}
		else
		{
			//search right
			res=findEnd(a,mid+1,end);
		}
	}
	
	return res;

}

int searchInRotatedArr_1(int arr[],int item,int size)
{
	
	int endPosition=findEnd(arr,0,size-1);
	int index=-1;
	printf("end is: %d, @ index:%d\n",arr[endPosition],endPosition);
	//List 1 is from 0 to endPosition, List 2 is from endPosition to size-1
	if(item>=arr[0] && item< arr[endPosition])
	{
		printf("item is on left\n");
		index=binarySearch(arr,0,endPosition,item);
	}
		
	if(item>arr[endPosition+1] && item<=arr[size-1])
	{
		printf("item is on right\n");
		index=binarySearch(arr,endPosition,size-1,item);
	}
		

	return index;
}

int searchInRotatedArr_2(int arr[],int item, int start, int end)
{
	//First check which side of the array is sorted
	int mid=(start+end)/2;
	int index=-1;
	if(start<=end)
	{
		if(item==arr[mid])
			return mid;
		//If array is completely sorted and not rotated
		if(arr[start]<arr[mid] && arr[mid]<arr[end])
			index=binarySearch(arr,start,end,item);
		//Check if left side is sorted
		if(arr[0]<arr[mid])
		{
			//Left side is sorted. Check if item lies there
			if(arr[start]<=item && item<arr[mid])
				index=binarySearch(arr,start,mid-1,item);
			else
				index=searchInRotatedArr_2(arr,item,mid+1,end);
		}
		//Check if right side is sorted
		if(arr[mid]<arr[end])
		{
			if(arr[mid]<item && item<arr[end])
				index=binarySearch(arr,mid+1,end,item);
			else
				index=searchInRotatedArr_2(arr,item,start,mid-1);
		}
	}

	return index;
	
}

int main()
{
	int arr[10]={6,7,8,9,10,1,2,3,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	int item=21;
	int index=searchInRotatedArr_1(arr,item,size);
	if(index!=-1)
	{
		printf("Element is at location:%d\n",index);
	}
	else
		printf("Element not found\n");

	int index2 = searchInRotatedArr_2(arr,item,0, size-1);
	if(index2!=-1)
	{
		printf("Element is at location:%d\n",index2);
	}
	else
		printf("Element not found\n");
	return 0;
}
