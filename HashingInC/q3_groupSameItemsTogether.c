/*Group all the occurrences of elements order by their first occurrence.

Method 1: Naive approach:
For every element in the list, traverse the remaining list on the right to find its occurences.
Note: For each element TC taken is O(n) to search array +O(n) to shift elements
TC=n*O(n)=O(n^2)
SC=O(1)

Method 2: Using balanced BST - AVL tree.
(i) Insert key with frequency in the tree. To find (elt,frequency) pairs, TC=O(n)
(ii) Then build balanced BST - O(nlogn)
(iii) After building BST, traverse the array and check BST for that key. If present, print the key
=frequency of key. Then, delete this key from BST. Keep doing this till BST is empty.
Inserting+deletion - O(n log n)

Note: In place of deleting the node, we can reduce the frequency to 0 once that element has been
printed.

Note: It is out of place. If we try to do it in place, TC=O(n^2)

TC=O(nlogn)
SC=O(n)

Method 3: Use hash table to store the frequency in the hash table. - O(n)
Then scan the array and print the element = frequency no. of times. -O(n)
Make the frequency of the printed element=0

TC=O(n)
SC=O(n) for hash table
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int arr[]={3,2,4,5,2,5,3,4,3};
	int size=sizeof(arr)/sizeof(arr[0]);

	int i,j,k,l,max=-1;
	for(i=0;i<size;i++)
	{
		if(arr[i]>max)
			max=arr[i];
	}
	printf("max: %d\n",max);
	int *hashTable;
	hashTable=(int *)calloc(max,sizeof(int));
	//Building the hash table
	for(j=0;j<size;j++)
	{
		hashTable[arr[j]]++;
	}

	//Traversing the array
	for(k=0;k<size;k++)
	{
		int freq=hashTable[arr[k]];
		for(l=0;l<freq;l++)
		{
			printf("%d\t",arr[k]);
		}
		hashTable[arr[k]]=0;
	}



}