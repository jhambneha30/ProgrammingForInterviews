/*Given an array A of size n, Count the distinct elements in all windows of size K.

Method 1: Naive approach:
No. of windows possible = n-(k-1)=n-k+1
For every window in the array, check if any of the k elements is distinct.
Checking if an element in a window is distinct takes O(k^2) time.

TC=(n-k+1)*O(k^2) = O(nk^2)
SC=O(1)

Method 2: Sort every window. - O(klogk)
In every window, scan once to check the distinct elements because the duplicate elements will
be present side by side. So, k^2 comparisons are not required, only O(k) scan is enough.
TC=O(n-k+1)*(klogk+k)=O(nklogk)
SC=O(1) (In my implementation, O(k) space is being used)

Method 3: For every window, store the elements in the hash table. Then, sorting won't be required.
Then, traverse every window once to count distinct elements
TC=O((n-k+1)k)=O(nk)
SC=O(k) for hash table

Method 4: For every window, store the elements in the hash table. Then, sorting won't be required.
Then, in place of traversing every window once to count distinct elements, keep a variable count
which keeps the count of distinct elements as we traverse the array.
TC=O(n) to build hash table +O(n) to find count=O(n)
SC=O(k) for hash table
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void distinctEltsInKDist_2(int a[],int n, int k)
{
	int j,x,y,distinct=0,temp;
	int window[k];
	for(j=0;j<(n-k+1);j++)
	{
		
		for(x=0;x<k;x++)
		{
			window[x]=a[j+x];
		}
		qsort(window,k,sizeof(int), cmpfunc);
		// for(x=0;x<k;x++)
		// {
		// 	printf("window: %d\n",window[x]);
		// }
		
		distinct=0;
		y=0;
		while(y<(k-1))
		{
			temp=window[y];
			// printf("window[y]: %d\n",window[y]);
			// printf("window[y+1]: %d\n",window[y+1]);
			if(window[y]!=window[y+1])
			{
				distinct++;
				y++;
			}
				
			else
			{
				while(window[y]==temp)
					y++;
				// distinct++;
			}
		}
		if(y==(k-1) && window[y]!=window[y-1])
			distinct++;
		printf("Distinct elements in window %d are: %d\n",j,distinct);
		
	}
}

void distinctEltsInKDist_3(int a[],int n, int k)
{
	int i,max=-1,j,y,distinct,x;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	int *hashTable=(int *)calloc(max,sizeof(int));
	for(j=0;j<(n-k+1);j++)
	{
		distinct=0;
		if(j==0)
		{
			for(x=0;x<k;x++)
				hashTable[a[j+x]]++;
		}	
		else
		{
			hashTable[a[j-1]]--;
			hashTable[a[j+k-1]]++;
		}
		
		for(y=0;y<k;y++)
		{
			// printf("[a[j+y]:  %d\n",a[j+y]);
			// printf("hashTable[a[j+y]:  %d\n",hashTable[a[j+y]]);
			if(hashTable[a[j+y]]==1)
			{
				distinct++;
				// hashTable[a[j+y]]--;
			}
			// else
			// 	hashTable[a[j+y]]--;
			
		}
		printf("Distinct elements in window %d are: %d\n",j,distinct);
			
	}
}

void distinctEltsInKDist_4(int a[],int n, int k)
{
	int i,max=-1,j,y,distinct,x;
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	int *hashTable=(int *)calloc(max,sizeof(int));
	for(j=0;j<(n-k+1);j++)
	{
		// distinct=0;
		if(j==0)
		{
			for(x=0;x<k;x++)
			{
				hashTable[a[j+x]]++;
				if(hashTable[a[j+x]]==1)
					distinct++;
				else
					distinct--;
			}
				
		}	
		else
		{
			//The count of the element which leaves the window decreases
			hashTable[a[j-1]]--;
			//If the element count becomes 1 => distinct
			if(hashTable[a[j-1]]==1)
				distinct++;
			//If the element is not present in this window, decrease the distinct count
			else if(hashTable[a[j-1]]==0)
				distinct--;

			//The count of the element which enters the window increases
			hashTable[a[j+k-1]]++;
			if(hashTable[a[j+k-1]]==1)
				distinct++;
			else if(hashTable[a[j+k-1]]>1)
				distinct--;
			
		}
		printf("Distinct elements in window %d are: %d\n",j,distinct);
			
	}
}


int main()
{
	int k=3;
	int arr[]={10,10,20,30,30,40,10};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("Method 2:\n");
	distinctEltsInKDist_2(arr,size,k);
	printf("Method 3:\n");
	distinctEltsInKDist_3(arr,size,k);
	printf("Method 4:\n");
	distinctEltsInKDist_4(arr,size,k);



	
}