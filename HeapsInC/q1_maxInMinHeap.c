/* Find max element in min heap.
Max element will definitely be present in a leaf. #leaves in a heap=ceil(n/2)-1
#comparisons required to find max=#leaves-1
TC=O(n)
SC=O(1)

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void min_heapify(int heapArr[],int size,int i)
{
	int left,right,smallest=i;
	left=2*i+1;
	right=2*i+2;
	int temp;
	// printf("index:%d,left:%d,right:%d\n",i,left,right);
	// printf("node:%d,left child:%d,right child:%d\n",heapArr[i],heapArr[left],heapArr[right]);
	if(left<size && heapArr[left]<heapArr[i])
		smallest=left;	
	if(right<size && heapArr[right]<heapArr[smallest])
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



void build_heap(int heap_arr[],int n)
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

int findMax(int heap[],int heapsize)
{
	int l=heapsize/2 - 1;
	int max=-9999;
	while(l<heapsize)
	{
		if(heap[l]>max)
			max=heap[l];
		l++;
	}
	printf("Max is: %d\n",max);
}

int main()
{
	int heap_arr[]={23,445,1,500,480};
	int size=sizeof(heap_arr)/sizeof(heap_arr[0]);
	build_heap(heap_arr,size);
	print_heap(heap_arr,size);

	int max=findMax(heap_arr,size);
}