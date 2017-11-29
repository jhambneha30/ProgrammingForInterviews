/*Find k-largest elements from an array.

Method 1: Naive approach
1. Find largest element and delete it from array - O(n-1)comparisons+O(n)
2. Find largest element and delete it from array - O(n-2)comparisons+O(n)
.
.
k. Find largest element and delete it from array - O(n-k)comparisons+O(n)

Summing up: (n-1)+(n-2)+.........+(n-k)=nk-(1+2+.....+k)=nk-O(k^2)=O(nk) [given n>>k]
SC=O(1)

Method 2:  Sort the array in descending order - O(nlogn)
Pick first k elements - O(k)
Since, k<<n TC=O(nlogn)
SC=O(1)

Method 3:
Build a max heap - O(n)
Delete 1st k elements - O(klogn)

TC=O(n+klogn)
SC=O(1)

Method 4:
Using BST
Build a BST using given array (we won't be balancing the tree here), then in worst case,
#comparisons=1+2+.....(n-1)=O(n^2)

Then, perform delete max k times - O(kn) [because, the tree can be skewed in the worst case]

TC=O(n^2 +kn)
SC=O(n) [In worst case, the tree can be skewed and so takes O(n) space]

Method 5:
1.) Build min heap using first k elements. - O(n)
2.) For the remaining (n-k) elements, ------------O((n-k)logk)=O(nlog k) [if n>>k]
	{
		compare the root of heap with next array element.
		If(root<array element)
			replace root with array element and min heapify!
	}

TC=O(nlogk)
SC=O(1) [For heap, we can use the first k elements of the array itself to build the min-heap,
so, no extra space is required to build a heap!]

*/

#include <stdio.h>
#include <stdlib.h>

void max_heapify(int heapArr[],int size,int i)
{
	int left,right,largest=i;
	left=2*i+1;
	right=2*i+2;
	int temp;
	// printf("index:%d,left:%d,right:%d\n",i,left,right);
	// printf("node:%d,left child:%d,right child:%d\n",heapArr[i],heapArr[left],heapArr[right]);
	if(left<size && heapArr[left]>heapArr[i])
		largest=left;	
	if(right<size && heapArr[right]>heapArr[largest])
		largest=right;
	// printf("Outside last condn: %d\n",largest);
	if(largest<size && largest!=i)
	{
		//swap heapArr[i] with heapArr[largest]
		temp=heapArr[i];
		heapArr[i]=heapArr[largest];
		heapArr[largest]=temp;
		// printf("Recursion: %d\n",largest);
		max_heapify(heapArr,size,largest);
	}
}

void min_heapify(int heap[],int heapsize,int index)
{
	int left=2*index+1,right=2*index+2;
	int smallest=index,temp;

	if(left<heapsize && heap[left]<heap[index])
		smallest=left;
	if(right<heapsize && heap[right]<heap[smallest])
		smallest=right;

	if(smallest<heapsize && smallest!=index)
	{
		temp=heap[smallest];
		heap[smallest]=heap[index];
		heap[index]=temp;
		min_heapify(heap,heapsize,smallest);
	}
}

void print_heap(int heapArr[],int size)
{
	int i;
	printf("Heap is:\n");
	for(i=0;i<size;i++)
	{
		printf("%d  ",heapArr[i]);
	}
	printf("\n");
}

void build_heap(int heap_arr[],int n)
{
	int k=n/2-1;
	//root at zeo
	while(k>=0)
	{
		printf("k: %d\n",k );
		max_heapify(heap_arr,n,k);
		k--;
	}
}

void build_Minheap(int heap_arr[],int n)
{
	int k=n/2-1;
	//root at zeo
	while(k>=0)
	{
		printf("k: %d\n",k );
		min_heapify(heap_arr,n,k);
		k--;
	}
}

int delete_max(int heap[],int n)
{
	int max=heap[0];
	heap[0]=heap[n-1];
	n--;
	printf("Deleted max: %d\n",max);
	max_heapify(heap,n,0);
	print_heap(heap,n);
	return n;
}

int find_kLargest_3(int heap[],int n,int k)
{
	int i=1;
	while(k>=0)
	{
		printf("Largest i: %d\n",heap[0]);
		n=delete_max(heap,n);
		k--;
		i++;
	}
	return n;
}

int find_kLargest_5(int heap[],int n,int k)
{
	build_Minheap(heap,k);
	int index=k,temp;
	while(index<n)
	{
		if(heap[0]<heap[index])
		{
			//swap heap[index] and heap[0]
			temp=heap[0];
			heap[0]=heap[index];
			heap[index]=temp;
			min_heapify(heap,k,0);
		}
		index++;
	}

	printf("Largest k elements are:\n");
	index=0;
	for(index=0;index<k;index++)
	{
		printf("%d  ",heap[index]);
	}
}

int main()
{
	int heap_arr[]={23,44,1,50,48,12,19};
	int size=sizeof(heap_arr)/sizeof(heap_arr[0]);
	int k;
	printf("Enter the value of k: number of k largest keys to be found\n");
	scanf("%d",&k);
	printf("Method 5------\n");
	find_kLargest_5(heap_arr,size,k);

	build_heap(heap_arr,size);
	print_heap(heap_arr,size);
	
	printf("Method 3------\n");
	size=find_kLargest_3(heap_arr,size,k);

	

}
