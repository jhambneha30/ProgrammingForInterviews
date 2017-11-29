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

int max_heap[50];
int min_heap[50];
int minh_last=-1,maxh_last=-1;

void print_heap(int max_heap[],int size)
{
	int i;
	printf("Heap is:\n");
	for(i=0;i<size;i++)
	{
		printf("%d  ",max_heap[i]);
	}
	printf("\n");
}

void max_heapify(int i)
{
	int left,right,largest=i;
	int size=maxh_last;
	left=2*i+1;
	right=2*i+2;
	int temp;
	// printf("index:%d,left:%d,right:%d\n",i,left,right);
	// printf("node:%d,left child:%d,right child:%d\n",max_heap[i],max_heap[left],max_heap[right]);
	if(left<=size && max_heap[left]>max_heap[i])
		largest=left;	
	if(right<=size && max_heap[right]>max_heap[largest])
		largest=right;
	// printf("Outside last condn: %d\n",largest);
	if(largest<=size && largest!=i)
	{
		//swap max_heap[i] with max_heap[largest]
		temp=max_heap[i];
		max_heap[i]=max_heap[largest];
		max_heap[largest]=temp;
		// printf("Recursion: %d\n",largest);
		max_heapify(largest);
	}
}

void min_heapify(int i)
{
	int left,right,smallest=i;
	int size=minh_last;
	left=2*i+1;
	right=2*i+2;
	int temp;
	// printf("index:%d,left:%d,right:%d\n",i,left,right);
	// printf("node:%d,left child:%d,right child:%d\n",min_heap[i],min_heap[left],min_heap[right]);
	if(left<=size && min_heap[left]<min_heap[i])
		smallest=left;	
	if(right<=size && min_heap[right]<min_heap[smallest])
		smallest=right;
	// printf("Outside last condn: %d\n",smallest);
	if(smallest<=size && smallest!=i)
	{
		//swap min_heap[i] with min_heap[smallest]
		temp=min_heap[i];
		min_heap[i]=min_heap[smallest];
		min_heap[smallest]=temp;
		// printf("Recursion: %d\n",smallest);
		min_heapify(smallest);
	}
}

int delete_max()
{
	int max=max_heap[0];
	int n;
	max_heap[0]=max_heap[maxh_last];
	maxh_last--;
	n=maxh_last+1;
	printf("Deleted max: %d\n",max);
	max_heapify(0);
	print_heap(max_heap,n);
	return max;
}

int delete_min()
{
	int min=min_heap[0];
	int n;
	min_heap[0]=min_heap[minh_last];
	minh_last--;
	n=minh_last+1;
	printf("Deleted max: %d\n",min);
	min_heapify(0);
	print_heap(min_heap,n);
	return min;
}



void increase_key(int heap[],int n,int index,int key,int flag)
{
	heap[index]=key;
	int i=index,temp;
	switch(flag)
	{
		case 1: //max flag
			while(i>=1 && heap[i]>heap[i/2])
			{
				temp=heap[i/2];
				heap[i/2]=heap[i];
				heap[i]=temp;
				i/=2;
			}
		break;
		case 2://min flag
			while(i>=1 && heap[i]<heap[i/2])
			{
				temp=heap[i/2];
				heap[i/2]=heap[i];
				heap[i]=temp;
				i/=2;
			}
		break;
		default:
			printf("Something wrong with the flags!\n");

	}
	
	print_heap(heap,n);
}

int insert_key(int heap[],int last_index,int key,int flag)
{
	heap[++last_index]=-99999;
	increase_key(heap,(last_index+1),last_index,key,flag);
	return last_index;
}

void balance()
{
	int deleted_item;
	int min_flag=2,max_flag=1;
	if(maxh_last>minh_last)
	{
		deleted_item=delete_max();
		minh_last=insert_key(min_heap,minh_last,deleted_item,min_flag);
		
	}
	else if(maxh_last<minh_last)
	{
		deleted_item=delete_min();
		maxh_last=insert_key(max_heap,maxh_last,deleted_item,max_flag);
	}
}

void medianUsingMaxMinHeap_3(int arr[],int lastOfArr,int item)
{
	int min_flag=2,max_flag=1;
	if(lastOfArr==0)
	{
		// printf("Median is: %d\n",arr[lastOfArr]);
		maxh_last=insert_key(max_heap,maxh_last,item,max_flag);
		printf("Median is: %d\n",max_heap[maxh_last]);
		return;
		
	}
	// if(lastOfArr==1)
	// {
	// 	printf("Median is: %d\n",arr[lastOfArr]);
	// 	minh_last=insert_key(min_heap,minh_last,item);
	// 	printf("Median is: %d\n",min_heap[minh_last]);
	// 	return;
	// }

	// int diff_maxRoot,diff_minRoot;
	// diff_maxRoot=abs(max_heap[0]-item);
	// diff_minRoot=abs(min_heap[0]-item);

	if(item<=max_heap[0])
	{
		maxh_last=insert_key(max_heap,maxh_last,item,max_flag);
	}
	else
	{
		minh_last=insert_key(min_heap,minh_last,item,min_flag);
	}
	
	if(abs(maxh_last-minh_last)>1)
	{
		printf("imbalance\n");
		balance();

	}

	int diff=maxh_last-minh_last;

	switch(diff)
	{
		case 0:
			printf("Medians are: %d, %d\n",max_heap[0],min_heap[0]);
		break;

		case 1:
			printf("Median is: %d\n",max_heap[0]);
		break;

		case -1:
			printf("Median is: %d\n",min_heap[0]);
		break;

		default:
			printf("diff is: %d\n",diff);
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
		// printf("Method1: Using insertion sort:\n");
		// medianUsingInsertionSort_1(arr,i,input);
		printf("Method3: Using max-min heaps:\n");
		medianUsingMaxMinHeap_3(arr,i,input);
		i++;
		printf("Enter the input!\n");
		scanf("%d",&input);
	}


}