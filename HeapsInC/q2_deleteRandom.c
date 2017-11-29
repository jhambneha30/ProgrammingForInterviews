/*Deleting an arbitary element from a min-heap.
deleting random = linear search (O(n))+delete (O(logn))=O(n)
TC=O(n)

Note: If the ques is to delete an element present at index x. Then it is very easy to delete
the element at that index followed by calling min-heapify. 
TC=O(log n)


*/

#include <stdio.h>
#include <stdlib.h>

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

void build_heap(int heap_arr[],int n)
{
	int k=n/2-1;
	while(k>=0)
	{
		min_heapify(heap_arr,n,k);
		k--;
	}

}

void print_heap(int heap[],int size)
{
	int i;
	printf("Heap is:\n");
	for(i=0;i<size;i++)
	{
		printf("%d ",heap[i]);
	}
	printf("\n");
}

int delete_random(int heap[],int heapsize,int item)
{
	int deletion_index=-1,flag=0,i=0;
	while(i<heapsize)
	{
		if(heap[i]==item)
		{
			deletion_index=i;
			flag=1;
		}
		i++;
			

	}
	if(flag==0)
		printf("item not found\n");
	else
	{
		heap[deletion_index]=heap[heapsize-1];
		heapsize=heapsize-1;
		min_heapify(heap,heapsize,deletion_index);
	}

	return heapsize;

}

int main()
{
	int deletion;
	int heap_arr[]={23,445,1,500,480};
	int size=sizeof(heap_arr)/sizeof(heap_arr[0]);
	build_heap(heap_arr,size);
	print_heap(heap_arr,size);

	printf("Enter the element to be deleted!\n");
	scanf("%d",&deletion);

	size=delete_random(heap_arr,size,deletion);
	print_heap(heap_arr,size);

}