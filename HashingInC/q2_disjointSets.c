/*Check whether the given two sets are disjoint or not.

Method 1: Naive approach:
For every element in the list, traverse the second list to check if it exists in second list
or not. If it exists, then the sets are not disjoint.
TC=O(nm); n=array1 size, m=array2 size

Method 2: Sort first array of size m - O(mlogm)
For every element in second list, apply binary search on first list =>O(log m) * n=O(nlogm)

TC=O(max(nlogm,mlogm))
SC=O(1)

Method 3:Sort both the arrays - O(mlogm)+O(nlogn)
Now take two pointers and move over the arrays as in merge procedure, till 
we find equal elements or till both the pointers reach the end. - O(m+n)
TC=O(mlogm+nlogn)

Method 4: Using BST
Take the first array and construct a BST - O(mlogm)
Take each element of second array and apply search on BST - O(log m)*n
TC=O(mlogm)+O(nlogm)

SC=O(m) (BST will take space=O(m))

Method 5: Create hash table. For every element in first list, mark the element in the 
hash table. - m insertions - O(1)*m=O(m)
Move over the other list and search for the element in the hash table. If it is already present,
it mean sets are not disjoint. - O(n)

TC=O(m+n)
SC=O(m)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int binarySearch(int arr[],int size,int item)
{
	int start=0,end=size-1,mid;
	
	while(start<=end)
	{
		mid=(start+end)/2;	
		// printf("mid: %d\n",mid);
		if(item==arr[mid])
			return mid;
		else if(item<arr[mid])
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
			// printf("start: %d\n",start);
		}
	}
	return -1;
}

void checkDisjoint_2(int set1[],int set2[],int s1,int s2)
{
	
	qsort(set1,s1,sizeof(int), cmpfunc);
	
	printf("size1: %d\n",s1);
	printf("size2: %d\n",s2);

	int i,index;
	for(i=0;i<s2;i++)
	{
		index=binarySearch(set1,s1,set2[i]);
		// printf("set2[i]: %d ,index: %d\n",set2[i],index);
		if(index>=0)
		{
			printf("Sets are not disjoint!\n");
			return;
		}
			
	}
	printf("Sets are disjoint!\n");

}

void checkDisjoint_3(int set1[],int set2[],int s1,int s2)
{
	qsort(set1,s1,sizeof(int), cmpfunc);
	qsort(set2,s2,sizeof(int), cmpfunc);
	int x=0,y=0;
	while(x<s1 && y<s2)
	{
		if(set1[x]==set2[y])
		{
			printf("Sets are not disjoint!\n");
			return;
		}
		else if(set1[x]<set1[y])
			x++;
		else
			y++;
	}
	printf("Sets are disjoint!\n");



}

void checkDisjoint_5(int set1[],int set2[],int s1,int s2)
{
	//Create hash table for set1
	int i,j,k,max=-1;
	for(i=0;i<s1;i++)
	{
		if(set1[i]>max)
			max=set1[i];
	}

	int *hashTable;
	hashTable=(int*) calloc(max,sizeof(int));
	for(j=0;j<s1;j++)
	{
		hashTable[set1[j]]++;
	}

	for(k=0;k<s2;k++)
	{
		if(hashTable[set2[k]]>0)
		{
			printf("Sets are not disjoint!\n");
			return;
		}
			

	}

	printf("Sets are disjoint!\n");

}

int main()
{
	int set1[]={1,80,3};
	int set2[]={8,4,6,5};
	int size1=sizeof(set1)/sizeof(set1[0]);
	int size2=sizeof(set2)/sizeof(set2[0]);
	// int index=binarySearch(set1,size1,9);

	printf("Method 2:\n");
	checkDisjoint_2(set1,set2,size1,size2);

	printf("Method 3:\n");
	checkDisjoint_3(set1,set2,size1,size2);

	printf("Method 5:\n");
	checkDisjoint_5(set1,set2,size1,size2);
}