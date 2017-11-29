/*Print out all numbers in the form of a3 + b3
We can generate these numbers in a matrix of size n*n.
Each of the rows of the matrix will be sorted
Example: n numbers are 0,1 and 2
Then,
                	0	1	2
                  -------------
               0 |  0	1	8
               1 |  1	2	9
               2 |  8	9	16

Here, we have k sorted rows and we need to merge them to give the output.
We have already seen how to merge k sorted lists using a min-heap - Create a min heap using
the first column; keep deleting min and keep adding the next element from the list to which 
the min belonged!

TC=O(n^2logn)
SC=O(k)

http://www.geeksforgeeks.org/merge-k-sorted-arrays/

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

void sumOfCubes(int arr[],int k)
{
	struct heapNode min_heap[k];
	int i,count=0;
	for(i=0;i<k;i++)
	{
		min_heap[i].data=(pow(arr[i],3))+(pow(arr[0],3));
		min_heap[i].list_index=i;
		min_heap[i].next_index=1;
	}

	while(count!=(k*k))
	{
		printf("Min: %d\n",min_heap[0].data);
		struct heapNode root = min_heap[0];

		if(root.next_index<k)
		{
			root.data=(pow(arr[root.list_index],3))+(pow(arr[root.next_index],3));
			root.next_index++;
		}
		else
			root.data=INT_MAX;

		replaceMin(min_heap,root,k);
		print_heap(min_heap,k);
		count++;
	}
}


int main()
{
	//Given 4 sorted lists:
	int arr[] = {0,1,2};
    int k=sizeof(arr)/sizeof(arr[0]);
    printf("k is:%d\n",k);
	sumOfCubes(arr,k);
	return 0;
}