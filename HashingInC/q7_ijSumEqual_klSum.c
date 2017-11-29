/*Find four elements i,j,k and l in an array such that i+j=k+l
Method 1: Brute force
for(i=1 to n)
	for(j=i+1 to n)
		for(k=j+1 to n)
			for(l=k+1 to n)

TC=O(n^4) - useless!
SC=O(1)

Method 2: For every pair of elements in the array, add a node to the balanced BST.
Each node contains (sum of pair,#pairs with this sum or frequency) -->(pair 1) -->(pair 2)
So, a node contains the sum, count of pairs with this sum and this node points to a LL which
contains all the pairs with this sum!

When the frequency of any existing node is incremented, we understand that these pairs have same sum.

All possible pairs can be found in - O(nc2)=O(n^2)
Time to build BST = n^2logn^2=O(2n^2logn) = O(n^2logn)

TC=O(n^2logn)
SC=O(n^2)

Method 3: Use hash table in place of BBST to reduce the TC to linear
Finding possible pairs - O(n^2)
Build a hash table for each of the possible sums - O(n^2)*O(1)
Each cell of hash table is a structure containing a sum, a count and a pointer pointing to a LL
containing the pairs which sum to this particular sum.

Traverse the hash table to find out the sums for which the count is >1. These pairs will have
same sum! - O(n^2)

TC=O(n^2)
SC=O(n^2)
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct data
{
	int count;
	struct node *head;
};

struct node
{
	int first;
	int second;
	struct node *next;
};



void ijkl_equalSum_3(int arr[],int n)
{
	int i,j,pair_sum,k;
	struct data *hashTable;
	hashTable = (struct data *)calloc(50,sizeof(struct data));
	printf("hash table[0].count: %d  head: %p\t:",hashTable[0].count,hashTable[0].head);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			pair_sum=arr[i]+arr[j];
			struct node *new=(struct node*)malloc(sizeof(struct node*));
			new->first=arr[i];
			new->second=arr[j];
			new->next=NULL;
			if(hashTable[pair_sum].count==0)
			{
				hashTable[pair_sum].count++;
				hashTable[pair_sum].head=new;
			}
			else //add the node at the head of the list
			{
				hashTable[pair_sum].count++;
				new->next=hashTable[pair_sum].head;
				hashTable[pair_sum].head=new;
			}
			
		}
	}

	for(k=0;k<50;k++)
	{
		if(hashTable[k].count==0)
			continue;
		else if(hashTable[k].count==1)
		{
			printf("pair sum: %d  count: %d\t:",k,hashTable[k].count);
			printf("pair: %d-%d\n",hashTable[k].head->first,hashTable[k].head->second);
			printf("\n");

		}
		else
		{
			printf("The following pairs have same sum:\n");
			printf("pair sum: %d  count: %d\t:",k,hashTable[k].count);
			printf("\n");
			struct node *ptr;
			ptr= hashTable[k].head;
			while(ptr)
			{
			 	printf("pair: %d-%d\n",ptr->first,ptr->second);
					ptr=ptr->next;
			}

		}
	}
}

int main()
{
	int arr[]={6,2,3,4,5};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	printf("Method 3:\n");
	ijkl_equalSum_3(arr,size);
}