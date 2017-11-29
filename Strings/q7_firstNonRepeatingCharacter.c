/* Find the first non-repeating character in a given string 
Method 1: Naive approach
Scan every character and for each character, check if it is being repeated in the string 
by scanning all the remaining characters (even to the left of the current character).

Time taken: For every character, #comparisons=(n-1)
TC=O(n^2)
SC=O(1) (as we are not using any extra space proportional to input size)
===============================================================================================
Method 2: Using BST
The tree might grow so big that it might take O(n) time for search.
But hash table will always take O(1) for searching. Also, for characters, the space taken is
constant.
TC=O(n)
SC=O(n)
===============================================================================================
Method 3: Using hash table - This is better as:-
Keep storing the elements in a hash table and keep the count alongside. The first scan is 
taken up to build the hash table.
The second scan of array is used to chec which is the first character with count 1!

TC=O(n)
SC=O(1)
===============================================================================================
Method 4: Using hash table and SINGLE SCAN
We maintain the index along with the count of the character. 
Once the hash table is built, rather than scanning the input array again, we just scan the hash
table which is O(256)
TC=O(n) single scan
SC=O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define COUNT 256

struct hashStruct
{
	int count;
	int index;
};

int firstNonRepeatingChar(char *str)
{
	struct hashStruct hash[COUNT]={0};
	int i=0,j,min=INT_MAX;
	while(str[i])
	{
		hash[str[i]].count++;
		hash[str[i]].index=i;
		i++;
	}
	for(j=0;j<=COUNT;j++)
	{
		if(hash[j].count==1 && hash[j].index<min)
			min=hash[j].index;
	}
	return min;
}

int main()
{
	char word[]="madam";
	//Method 4
	int res=firstNonRepeatingChar(word);
	printf("First non repeating char is:%c\n",word[res]);
	return 0;
}