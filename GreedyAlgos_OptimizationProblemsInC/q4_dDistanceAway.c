/* Rearrange the characters of the given string such that the same characters occur d-
distance away from each other.

Solution 1: Greedy about frequencies:
1. Build a hash table containing the frequency of each character.  ---O(n)
2. Build max heap. Note that max number of characters can be 256. So, build heap will 
take O(m)<O(256)  ----------O(1)
3. Delete max and keep arranging the characters at distance d starting with appropriate index.
Delete max happens m times.  ----------O(mlogm)=O(1)
TC=O(n)
SC=O(m)=O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define HASH_COUNT 256
int char_hash[HASH_COUNT]={0};

struct heapNode
{
	char ch;
	int count;
};

void max_heapify(struct heapNode arr[],int size,int index)
{
	int left=index*2+1, right=index*2+2;
	int largest=index;
	if(left<size && arr[left].count>arr[largest].count)
	{
		largest=left;
	}

	if(right<size && arr[right].count>arr[largest].count)
	{
		largest=right;
	}

	if(largest<size && largest!=index)
	{
		struct heapNode temp=arr[index];
		arr[index]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr,size,largest);
	}
}

void print_heap(struct heapNode heapArr[],int size)
{
	int i;
	printf("Heap is:\n");
	for(i=0;i<size;i++)
	{
		printf("%c:%d  ",heapArr[i].ch,heapArr[i].count);
	}
	printf("\n");
}

struct heapNode extract_max(struct heapNode harr[],int *heapsize)
{
	printf("Heapsize before:%d\n",*heapsize);
	struct heapNode max=harr[0];
	harr[0]=harr[*heapsize-1];
	max_heapify(harr,*heapsize,0);
	*heapsize=*heapsize-1;
	printf("Heapsize now:%d\n",*heapsize);
	return max;

}

void build_maxHeap(struct heapNode harr[],int heapsize)
{

	int k=heapsize/2 -1;
	while(k>=0)
	{
		max_heapify(harr,heapsize,k);
		k--;
	}
	printf("Right after building\n");
	print_heap(harr,heapsize);
}

int main()
{
	char str[]="abcdada";
	int d=2,i;
	int size=strlen(str),unique=0,j=0;
	
	for(i=0;i<size;i++)
	{

		char_hash[str[i]]++;
		if(char_hash[str[i]]==1)
			unique++;
		printf("For %c, count @index:%d is: %d\n",str[i],i,char_hash[str[i]]);
		//We replace str with null chars as we need to store the output in the same character array
		str[i]='\0';
	}
	struct heapNode heap_arr[unique];
	printf("unique:%d\n",unique);
	for(i=0;i<HASH_COUNT;i++)
	{
		if(char_hash[i]>0 && j<unique)
		{
			heap_arr[j].ch=i;
			heap_arr[j].count=char_hash[i];
			printf("count @index:%c is: %d\n",heap_arr[j].ch,heap_arr[j].count);
			j++;
		}

		
	}

	build_maxHeap(heap_arr,unique);
	print_heap(heap_arr,unique);
	struct heapNode top_node;
	int ind=0,heapSize=unique;
	for(i=0;i<unique;i++)
	{

		struct heapNode top_node=extract_max(heap_arr,&heapSize);
		printf("Extracted: %c Heapsize:%d\n",top_node.ch,heapSize);
		while(str[ind]!='\0')
			ind++;
		printf("Putting %c @ index:%d\n",top_node.ch,ind);
		str[ind]=top_node.ch;
		
		if(top_node.count>1 && i+(d+1)*(top_node.count-1)<size)
		{
			for(j=1;j<top_node.count;j++)
			{
				printf("Putting %c @ index:%d\n",top_node.ch,i+(d+1)*(j));
				str[i+(d+1)*(j)]=top_node.ch;
			}
		}
		ind++;

	}

	printf("%s\n",str);
	// printf(" %d%c",1,str[1]);
	// printf(" %d%c",2,str[2]);
	// printf(" %d%c",3,str[3]);
	// printf(" %d%c",4,str[4]);
	// printf(" %d%c",5,str[5]);
	// printf(" %d%c",6,str[6]);


	return 0;
}
