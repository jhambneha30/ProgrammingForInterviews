/*Heaps are stored in arrays as they are almost complete binary trees.
Let parent index=r
Left child: 2*r, Right child: 2*r+1
if index of heap starts from 0, then left=(2*r)+1 and right=(2*r)+2

Parent of index i: floor(i/2)
Max heapify: O(log n)
Build heap: O(n) ammortized!
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>

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

void increase_key(int heap[],int n,int index,int key)
{
	heap[index]=key;
	int i=index,temp;
	while(i>=0 && heap[i]>heap[i/2])
	{
		temp=heap[i/2];
		heap[i/2]=heap[i];
		heap[i]=temp;
		i/=2;
	}
	print_heap(heap,n);
}

void insert_key()
{
	printf("Move on! I don't have more space :P\n");
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

void heapsort(int heap[],int n)
{
	int max,heapsize=n,j;
	for(j=n-1;j>=0;j--)
	{
		max=heap[0];
		heap[0]=heap[j];
		heap[j]=max;
		heapsize--;
		max_heapify(heap,heapsize,0);
	}

	printf("Sorted list is:\n");
	for(j=0;j<n;j++)
	{
		printf("%d  ",heap[j]);
	}
	printf("/n");

	build_heap(heap,n);
	

}

int main()
{
	int num,i;
	printf("Enter the number of elements in the heap:\n");
    scanf("%d", &num);
	int heap[num];
	printf("num: %d\n",num);
	printf("Enter the elements of the heap\n");
	for(i=0;i<num;i++)
	{

		scanf("%d", &heap[i]);
		printf("i: %d,i: %d\n",i,heap[i]);
	}

	build_heap(heap,num);


	int choice,index,key;
	printf("\n1. Increase key\t2. Find Max\n");
    printf("3. Delete Max\t4. Insert using increase key\n");
    printf("5. Heapsort\t6. Print heap\t7. Exit\n");
    printf("Enter your choice:");
    scanf("%d", &choice);
	while(choice!=7)
	{
		
        switch (choice) 
        {
        	case 1: 
        		printf("Enter the index at which key is to be increased.\n");
        		scanf("%d",&index);
    			printf("Enter the increased key.\n");
        		scanf("%d",&key);
        		printf("key: %d\n",key);
        		increase_key(heap,num,index,key);
        		break;
        	case 2:
        		printf("Max is: %d\n",heap[0]);
        		break;
        	
        	case 3: 
        		num=delete_max(heap,num);
        		break;
        	case 4: 

        		insert_key();
        		break;
        	case 5: 
        		heapsort(heap,num);
        		break;
        	case 6: 
        		print_heap(heap,num);
        		break;
        	case 7: 
        		printf("BYE");
        		exit(0);
        		break;
        	default:
            	printf("Wrong option!!\n");
           		break; 	
        }
        printf("Enter your choice:");
    	scanf("%d", &choice);
	}
	return 0;
}