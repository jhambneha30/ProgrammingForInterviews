/* Remove duplicates from a given string
Method 1: Using another array for output
For each character in the string, check if it is already present in the output array.
In case not present, then copy it in the output array.

Time taken=
For 1st character---0 comparsons
For 2nd character---1 comparson
.
.
For nth character---(n-1) comparsons
Summing up------------O(n^2) comparisons
TC=O(n^2) in worst case when all characters are distinct
SC=O(n) as the output array is extra (we could have given the ouput in the same array of chars)
NOTE: THE RELATIVE ORDERING OF THE CHARACTERS IS MAINTAINED IN THIS PROCEDURE!

==========================================================================================
Method 2:Using hash table [OUT OF PLACE]
In method 1, TC is high due to time taken in searching. Hash table can reduce the time to O(n).
Keep the count of characters in the hash table.
Thus, in one scan we can use the hash table and write the output string with unique characters.

TC=O(n) for one array scan
SC=O(1) for hash table as size is fixed + O(n) for output string
===========================================================================================
Method 3:Using hash table [IN PLACE]
For this, we need to have a pointer pointing to the point till where we have the unique 
characters (i indicates the point till where we have built the array eliminating the duplicates).

j points to the 1st element which is a duplicate and which needs to be replaced by a unique 
element. 

When we keep finding unique elements, we keep incrementing i and stop when we find a duplicate. 
When we find duplicates, we increment j so as to find a unique element to replace with i.

Whenever either i or j reaches the end, the whole array has been scanned, so we stop the procedure.
TC=O(n) to scan the array once.
SC=O(1) as hash table's size is fixed for characters in ASCII!
===========================================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 256

void removeDuplicates_1(char input[],char output[])
{
	int size=strlen(input);
	output[0]=input[0];
	int i=1,j=0,k=0,flag=0;
	while(input[i])
	{
		flag=0;
		for(j=0;j<=k;j++)
		{
			if(input[i]==output[j])
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			k++;
			
			output[k]=input[i];
		}
		printf("i: %d,k:%d\n",i,k);
		i++;
	}
	printf("k outide:%d\n",k);
	output[++k]='\0';
	
}

void removeDuplicates_2(char input[],char output[])
{
	int size=strlen(input);
	int hash[COUNT]={0};
	output[0]=input[0];
	int i=1,j=0;
	while(input[i])
	{
		if(hash[input[i]]==0)
		{
			hash[input[i]]++;
			output[j]=input[i];
			j++;
		}
		i++;
	}
	output[j]='\0';
}

removeDuplicates_3(char input[])
{
	int curIndex=0,finalIndex=0;
	//curIndex scans through the entire array while finalIndex only gets incremented when a
	//unique element is found by curIndex
	int hash[COUNT]={0};
	char temp;
	while(input[curIndex])
	{
		temp=input[curIndex];
		if(hash[temp]==0)
		{
			input[finalIndex]=temp;
			hash[temp]++;
			finalIndex++;
		}
		curIndex++;
		
	}
	input[finalIndex]='\0';
}


int main()
{
	char str[]="aaabb";
	int size=strlen(str);
	char output1[size];
	printf("\n============Method 1============\n");
	removeDuplicates_1(str,output1);
	int x=0;
	while(output1[x])
	{
		printf("%c ",output1[x]);
		x++;
	}
	printf("\n============Method 2============\n");
	char output2[size];
	removeDuplicates_2(str,output2);
	x=0;
	while(output2[x])
	{
		printf("%c ",output2[x]);
		x++;
	}
	printf("\n============Method 3============\n");
	removeDuplicates_3(str);
	x=0;
	while(str[x])
	{
		printf("%c ",str[x]);
		x++;
	}
}