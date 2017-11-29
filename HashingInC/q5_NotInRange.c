/*Given an array and a range[low, high], find the lements  that are in the range but not
in the array

Method 1: Naive approach:
For every element in the range (high-low+1=m say), search linearly in the given array if it is present in the
array or not.
TC=O(mn)
SC=O(1)

Method 2: Sort the array - O(nlogn)
Now, apply binary search on the numbers from the range until we find a match in the array.
Every binary search till a number from range is found in the array O(log n)

Once, a matching number is found, linear search in the array is done till the elements belong 
to the range - O(m+n)

TC= O(nlogn)+O(mlogn)+O(m+n) - will depend on the leading factor
SC=O(1)

Method 3:
Build a hash table of array - O(n)
For every element in the range, search it in the hash table - m*O(1)
TC=O(m+n)
SC=O(n)
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int binarySearch(int arr[],int size,int item)
{
	int start=0,end=size-1,mid;
	
	while(start<=end)
	{
		mid=(start+end)/2;	
		// printf("mid: %d\n",mid);
		if(item==arr[mid])
			return mid;
		else if(item<arr[mid])
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
			// printf("start: %d\n",start);
		}
	}
	return -1;
}

void inRangeButNotInArray_2(int arr[],int n,int low,int high)
{
	int index;
	qsort(arr,n,sizeof(int), cmpfunc);
	while(low<=high)
	{

		index=binarySearch(arr,n,low);
		// printf("low:%d, index: %d\n",low,index);
		if(index>=0)
		{
			index++;
			low++;
			break;
		}
			
		else
			printf("%d\t",low);
		low++;
	}

	while(low<arr[index] && index<n)
	{
		if(arr[index]>high)
			break;

		printf("%d\t",low);
		low++;
		if(low==arr[index])
		{
			index++;
			low++;
			continue;
		}
	}

	while(low<=high)
	{
		printf("%d\t",low);
		low++;
	}
}

void inRangeButNotInArray_3(int arr[],int n,int low,int high)
{
	int max=-1,i,j;
	for(i=0;i<n;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	int hashTable[max];
	for(j=0;j<n;j++)
	{
		hashTable[arr[j]]=1;
	}

	while(low<=high)
	{
		if(hashTable[low]!=1)
		{
			printf("%d\n",low );
		}
		low++;
	}
}

int main()
{
	int low=43, high=52;
	int arr[]={9,10,3,5,50,15,53,45,32};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("Method 2:\n");
	inRangeButNotInArray_2(arr,size,low,high);

	printf("Method 3:\n");
	inRangeButNotInArray_3(arr,size,low,high);
	
}