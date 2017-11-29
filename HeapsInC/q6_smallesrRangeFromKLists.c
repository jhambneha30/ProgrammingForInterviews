/*Find smallest range containing elements from k lists
Method1: Naivest approach
Find the max range covered by the smallest element (say x) from the k lists and the largest 
element (say y) from k lists. Now try all the ranges and check if the elements in the range are present in
the four lists or not.
Also, compute the minimum of these ranges which satisfies above condition.
TC=(y-x)c2 - all possible ranges

This method can be improved a little by taking only those starting points which are present in
the given lists.
TC=nC2=O(n^2)
=============================================================================================
Method2: Using heaps
The idea is to use min heap. Below are the steps –

1. Create a min heap of size k with struct nodes containing three fields: data, list_index
and next_index and insert first elements of all k lists into the heap.
2. Maintain two variables min and max to store minimum and maximum values present in the heap at any point. Note min will always contain value of the root of the heap.
	Repeat following steps
	a) Get minimum element from heap (minimum is always at root) and compute the range.
	b) Replace heap root with next element of the list from which the min element is extracted. After replacing the root, heapify the tree. Update max if next element is greater. If the list doesn’t have any more elements, break the loop.
Tc=O(nk)
SC=O(k)

http://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 5
#define INT_MAX 99999
#define INT_MIN -99999

struct heapNode
{
	int data;
	//Index of the list this element belomgs to
	int list_index;
	//The index of the next element from this list
	int next_index;
};

void min_heapify(struct heapNode heapArr[],int size,int i)
{
	int left,right,smallest=i;
	left=2*i+1;
	right=2*i+2;
	struct heapNode temp;
	// printf("index:%d,left:%d,right:%d, size:%d\n",i,left,right,size);
	// printf("node:%d,left child:%d,right child:%d\n",heapArr[i].data,heapArr[left].data,heapArr[right].data);
	if(left<size && heapArr[left].data<heapArr[i].data)
		smallest=left;	
	if(right<size && heapArr[right].data<heapArr[smallest].data)
		smallest=right;
	// printf("Outside last condn: %d\n",smallest);
	if(smallest<size && smallest!=i)
	{
		//swap heapArr[i] with heapArr[smallest]
		temp=heapArr[i];
		heapArr[i]=heapArr[smallest];
		heapArr[smallest]=temp;
		// printf("Recursion: %d\n",smallest);
		min_heapify(heapArr,size,smallest);
	}
}



void build_heap(struct heapNode heap_arr[],int n)
{
	int k=n/2-1;
	//root at zeo
	while(k>=0)
	{
		printf("k: %d\n",k );
		min_heapify(heap_arr,n,0);
		k--;
	}
}

void replaceMin(struct heapNode heap[],struct heapNode new,int size)
{
	heap[0]=new;
	// int size=sizeof(heap)/sizeof(heap[0]);
	min_heapify(heap,size,0);
}

void print_heap(struct heapNode heapArr[],int size)
{
	int i;
	printf("Heap is:\n");
	for(i=0;i<size;i++)
	{
		printf("data:%d,list_index:%d,next:%d\n",heapArr[i].data,heapArr[i].list_index,heapArr[i].next_index);
	}
	printf("\n");
}

void findSmallestRange_2(int lists[][N],int k)
{
	struct heapNode heap_arr[k];
	int i,range,min_range=INT_MAX;
	int start,end;
	int min=INT_MAX,max=INT_MIN;
	printf("min is: %d, max: %d\n",min,max);
	for(i=0;i<k;i++)
	{
		heap_arr[i].data=lists[i][0];
		heap_arr[i].list_index=i;
		heap_arr[i].next_index=1;

		if(heap_arr[i].data>max)
		{
			max=heap_arr[i].data;
			// max_index=i;
		}
		
	}
	printf("min is: %d, max: %d\n",min,max);
	//Now, create a min heap of size k
	build_heap(heap_arr,k);
	print_heap(heap_arr,k);

	while(1)
	{
		struct heapNode root=heap_arr[0];
		range=max-heap_arr[0].data+1;
		if(range<min_range)
		{
			min_range=range;
			start=heap_arr[0].data;
			end=max;
			printf("Min range is:%d\n",min_range);
		}

		//Find the next element to replace the root of the heap
		//This element should belong to the same list as the element getting replaced
		if(root.next_index<N)
		{

			// printf("List index for root %d:%d\n",root.data,root.list_index);
			root.data=lists[root.list_index][root.next_index];
			root.next_index++;

			if(root.data>max)
			{
				max=root.data;
			}
		}
		else
			break;

		replaceMin(heap_arr,root,k);
		print_heap(heap_arr,k);
			
	}

	printf("Smallest range is:%d-%d\n",start,end);
}

int main()
{
	//Given 4 sorted lists:
	int arr[][N] = {
                    {4, 7, 9, 12, 15},
                    {0, 8, 10, 14, 20},
                    {6, 12, 16, 30, 50}
                    };
    int k=sizeof(arr)/sizeof(arr[0]);
    printf("k is:%d\n",k);
	findSmallestRange_2(arr,k);
	return 0;
}