/* Find a maximum occurring character in a given string
Method 1:
Use four variables: curr_char, curr_count, max_char, max_count.
Number of times the the array of characters needs to be traversed= n

For 1st character, elements scanned=(n-1)
For 2nd character, elements scanned=(n-2)
.
.
For last character, elements scanned=0
Summing, time taken = O(n^2)
TC=O(n^2)
SC=O(1)
=============================================================================================
Method 2: Sort the array - O(nlogn)
Array: RAVINDRAAA
Sorted: AAAADINRRV
Now, using a single scan, the max occuring element can be found. - O(n)
We need to use the same four variables: curr_char, curr_count, max_char, max_count
TC=O(nlogn)
SC=O(1) (we just used 4 variables and sorting we did is inplace!)
=============================================================================================
Method 3:
Since, this question requires searching in the array, one DS which is suitable for searching 
is BST. SO, while traversing the array buil a BST and keep count of each element in the node.
Also, maintain a max variable which contains the element whose count is max.
When, the tree is built, we will also have the max element.

TC=O(nlogn) to build the tree, O(n^2) if tree is skewed.
SC=O(n)

Here, more space is taken compared to method 2, so method 2 is better!
=============================================================================================
Method 4: Using hash table
For maintaining a hash table for characters, we use a fixed length array of size 256 and
we go to the ASCII value of a particular character and store the count.

While uodating the hash table, have a max_count variable and max_char variable. By the end
of traversing the array, we will have found the character which has occured max number of times.
TC=O(n) as one scan of array is required
SC=O(1) as constant size hash table is used.
Note: O(1) means that whatever be the size of the input, the size of hash table will always be
fixed i.e. 256

Now, we can further reduxce the space complexity by taking a hash table of size 226 (if we 
know that the input will contain only capital letters of english alphabet) 

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 256

char findMaxOccurence_1(char arr[], int n)
{
	int max_count=0, curr_count;
	char max_char,curr_char=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		curr_char=arr[i];
		curr_count=1;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]==curr_char)
			{
				curr_count++;
			}

		}
		if(curr_count>max_count)
		{
			max_count=curr_count;
			max_char=curr_char;
		}
	}
	printf("Max char is: %c, max count: %d\n",max_char,max_count);
	return max_char;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}


char findMaxOccurence_2(char arr[],int n)
{
	int i;
	qsort(arr, n, sizeof(char), cmpfunc);
	int max_count=0, curr_count=0;
	char max_char,curr_char=arr[0];
	
	for(i=0;i<n;i++)
	{
		if(curr_char==arr[i])
		{
			curr_count++;
		}
		else
		{
			
			if(curr_count>max_count)
			{
				max_count=curr_count;
				max_char=curr_char;
			}
			curr_char=arr[i];
			curr_count=1;
		}

		// printf("i:%d----Max char: %c, max count: %d\n",i,max_char,max_count);
		// printf("curr char is: %c, curr count: %d\n",curr_char,curr_count);
	}
	printf("Max char is: %c, max count: %d\n",max_char,max_count);
	return max_char;

}

char findMaxOccurence_4(char *str)
{
	int i,max_count=-1;
	char max_char;
	int n=strlen(str);
	int hash[COUNT]={0};
	for(i=0;i<n;i++)
	{
		hash[str[i]]++;
		if(hash[str[i]]>max_count)
		{
			max_count=hash[str[i]];
			max_char=str[i];
		}
	}
	printf("Max char is: %c, max count: %d\n",max_char,max_count);
	return max_char;
}

int main()
{
	char arr[]={'R','A', 'V', 'I','N','D','R','A','A','A'};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("=============Method 1=============\n");
	char max=findMaxOccurence_1(arr,size);

	printf("=============Method 2=============\n");
	max=findMaxOccurence_2(arr,size);

	printf("=============Method 4=============\n");
	max=findMaxOccurence_4(arr);
}