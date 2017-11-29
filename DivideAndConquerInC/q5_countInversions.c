/* Count inversions in an array. INVERSION: If an element occuring at a later index is 
smaller than the current element, then the pair forms an inversion!

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IMPORTANT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If array is already sorted then inversion count is 0. If array is sorted in reverse order 
that inversion count is the maximum. 
Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Example: 7,5,1,3,4,6
Inversions with 7: (7,5),(7,1),(7,3),(7,4),(7,6)
Inversions with 5: (5,1),(5,3),(5,4)
There are no inversions possible wiht 1, 3, 4 and 6 => Ans-8

Method 1: Brute force
For 1st element, compare (n-1) times
For 2nd element, compare (n-2) times
.
.
For (n-1)th element, compare 1 times
Summing,
TC=O(n^2)
SC=O(1)

==========================================================================================
Method 2: Modification of Merge Sort
Step 1. Keep dividing the list into halves until we reach one element.
Step 2. While merging, we check if the first element(left) is greater than 2nd(right), then,
count is incremented. Also, we put them in sorted order.

Note:Suppose the left list contains {5,7} and the right list contains {1} at an intermediate
step. So, while merging, we see that the first element of left list is greater than 1, then
we know that the rest of the elements in the left list will also be greater than 1. Thus,
the count is incremented by (last_left_index-current_left_index+1).

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~IMPORTANT~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
NOTE: This condition ((i!=n1)) is very important, otherwise,
it will keep counting even when we are just copying the right array as it is 
i.e. when left[i]==INFINITY
	if(i!=n1)
		c=c+(q-(i+p)+1);

We have to add the starting index p to i in case it is the right side of the array!.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
T(n)=2T(n/2)+O(n)=O(nlogn) [O(1) time taken to compare the elements and 
							counting the inversions for one element]
TC=O(nlogn)
SC=O(log n) ---depth of stack depends on recursion stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define COUNT 6

int merge(int arr[],int p,int q,int r)
{	
	int c=0;
	printf("In merge: p:%d,q:%d,r:%d\n",p,q,r);
	int n1=q-p+1, n2=r-q; //n2=r-(q+1)+1=r-q
	printf("After increment: n1:%d n2:%d\n",n1,n2);
	int left[n1+1];
	int right[n2+1];
	int i=0,y,j=0,k;
	left[n1]=INT_MAX;
	right[n2]=INT_MAX;
	printf("left array:\n");
	for(i=0;i<n1;i++)
	{
		left[i]=arr[p+i];
		printf(" %d",left[i]);	
	}
	printf("\n");
	
	printf("right array:\n");
	for(y=0;y<n2;y++)
	{
		right[y]=arr[q+y+1];
		printf("%d:%d ",y,right[y]);	
	}
	printf("\n");
	
	//Merging
	i=j=0;
	printf("Merged:\n");
	for(k=p;k<=r;k++)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			
			i++;
		}
			
		else
		{
			arr[k]=right[j];
			//NOTE: This condition ((i!=n1)) is very important, otherwise,
			// it will keep counting even when we are just copying the right array as it is 
			//i.e. when left[i]==INFINITY
			if(i!=n1)
				c=c+(q-(i+p)+1);
			j++;
		}
		printf(" %d",arr[k]);	
	}
	printf("\ncount: %d\n",c);
	return c;

}

int mergeSort(int arr[],int start,int end)
{
	int mid,invCount=0;
	if(start<end)
	{
		mid=(start+end)/2;
		invCount+=mergeSort(arr,start,mid);
		invCount+=mergeSort(arr,mid+1,end);
		invCount+=merge(arr,start,mid,end);
		printf("Count after merge:%d\n",invCount);
	}
	return invCount;
}

int main()
{
	int arr[COUNT]={7,5,1,3,6,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	int numInversions=0;
	numInversions=mergeSort(arr,0,size-1);
	int x;
	printf("Number of inversions:%d\n",numInversions);
	printf("Sorted array is:\n");
	for(x=0;x<size;x++)
	{
		printf(" %d",arr[x]);
	}
	return 0;
}