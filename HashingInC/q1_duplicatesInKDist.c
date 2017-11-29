/*Check whether given array contains duplicates in k-distance or not.

Method 1: Naive approach:
For every element in the list, traverse till distance k in the array to check if it is
repeated or not.
TC=O(nk)

Note: distance k means the number of characters present between the repeated characters.

Method 2: Using hash table window of size k.
We use a hash table to bring down the factor O(k) to O(1)

TC=O(n)
SC=O(k)
In my implmentation, SC=O(256)=O(1)
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// struct Hash
// {
// 	int count;
// 	char data;
// };

int hashTable[256];

int main()
{
	int k=2,i,j,x,y,flag=0;
	char arr[]={'d','a','d','c','a'};
	int n=sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<256;i++)
	{
		hashTable[i]=0;
	}
	//Since ke=2, we'll take a window of size k+1=3
	for(j=0;j<(n-k);j++)
	{
		if(j==0)
		{
			for(x=0;x<(k+1);x++)
				hashTable[arr[j+x]]++;
		}
		else
		{
			hashTable[arr[j-1]]--;
			hashTable[arr[j+k]]++;
		}
		
		
		for(y=0;y<(k+1);y++)
		{
			if(hashTable[arr[j+y]]>1)
			{
				printf("j: %d\t y: %d\n",j,y);
				printf("%c is repeated\n",arr[j+y]);
				flag=1;
			}
		}
			
	}
	if(flag==0)
		printf("None is repeated\n");

	return 0;
}