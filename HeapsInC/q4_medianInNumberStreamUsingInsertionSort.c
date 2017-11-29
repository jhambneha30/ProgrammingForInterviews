/* Find median in a stream of numbers.

Method1:
One method is to sort the numbers and then find the middle.
If size of array is even (say 100), then middle two elements in the sorted array will be the median.
Let us say we use merge sort - O(nlogn)
But since the numbers are continuously coming in, then after sometime the array size 
becomes 105. We'll again have to sort the array of 105 numbers to find the median, which 
is not a good method.

If we use above method, then using INSERTION SORT is better than using MERGE SORT 
as merge sort is applied on an array from scratch, while insertion sort accepts the next 
element and places it at the right position in the already sorted array.

TC using Insertion sort=O(n^2) in the worst case!
SC=O(1)
==============================================================================================
Method2: Using BST
The root will be the median, if the tree is not skewed and number of elements in LSt and RST
are equal. SO, we should construct the BST such that #nodes in LST=#nodes in RST
Then, we can simply say that the root is median.

If the stream contains even number of elements, then either 
Case1: #nodes in LST=#nodes in RST+1
or
Case2: #nodes in RST=#nodes in LST+1

If Case 1: then one median will be the root and other will be the inorder predecessor of the
root (greatest element in LST).
If Case 2: then one median will be the root and other will be the inorder successor of the
root (least element in RST).

So, we have to ensure that the difference betweennumber of nodes in LST and 
no. of nodes in RST is atmost 1.
Note: The resulting tree after applying balancing will only ensure that diff in nodes of LSt 
RST<=1 but does not ensure that the tree is balanced because, the lST and RST might still be skewed
So, TC=O(n/2)=O(n
SC=O(n/2))=O(n)
==============================================================================================
Method 3: Using Max heap to store the lower half and Min heap to store higher half.
Algo:-
When an element x comes in, compare it with the roots of the min and max heap.
If x<root of min heap, insert into min heap and update count of elements in the min-heap (say c_min)
If x>root of max heap, insert into max heap and update count of elements in the max-heap (say c_max)
Now, check balancing: if(c_min-c_max)!=0 or 1 or -1, then we need to balance the system.
For this, pick the heap with larger number of elements in it and delete its root, apply heapify and
transfer this root to other heap.

In worst case, an element may have to undergo an insertion, then deletion, then insertion =>3(logn)
So, TC=O(nlogn)
SC=O(n) for two arrays of sizes n/2 each

To print median:
At any time, check the sizes of the two heaps(c_min and c_max).
if(count is equal in both heaps) =>#elements = even => 2 medians => Pick roots of both heaps
otherwise (#elements = odd), pick the heap with larger count and print the root.
==============================================================================================
NOTE: Such algorithms implemented for continuous streams of inputs are called ONLINE
ALGORITHMS!
*/

#include <stdio.h>
#include <stdlib.h>


void medianUsingInsertionSort_1(int arr[],int last_index,int item)
{
	if(last_index==0)
	{
		printf("Median is: %d\n",arr[last_index]);
		return;
	}
		

	int j;
	
	
	//Sorting using Insertion sort
	int k=last_index-1,mid;
	while(k>=0 && arr[k]> item)
	{
		arr[k+1]=arr[k];
		k--;
	}
	arr[k+1]=item;

	// for(j=0;j<=last_index;j++)
	// {
	// 	printf("%d ",arr[j]);
	// }

	if((last_index+1) & 1)//if no. of elements=odd
	{
		mid=last_index/2;
		printf("Median is: %d\n",arr[mid]);
	}
	else
	{
		mid=last_index/2;
		printf("Indices are: %d,%d\n",mid,mid+1);
		printf("Medians are: %d,%d\n",arr[mid],arr[mid+1]);

	}
}

int main()
{
	int arr[100];
	int input,i=0;
	printf("Enter the input!To stop, enter -1!\n");
	scanf("%d",&input);
	while(input!=-1)
	{
		arr[i]=input;
		printf("Method1: Using insertion sort:\n");
		medianUsingInsertionSort_1(arr,i,input);
		printf("Method1: Using max-min heaps:\n");
		// medianUsingMaxMinHeap_2(arr,i,input);
		i++;
		printf("Enter the input!\n");
		scanf("%d",&input);
	}


}