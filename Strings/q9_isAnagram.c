/* Check whether given two strings are anagrams of each other.

Example: angle and glean, heater and reheat

Method 1: Sort the two strings-O(nlogn) and then compare them to see if all the letters are 
same-O(n).
TC=O(nlogn)
SC=O(1) as no extra space is taken.
===============================================================================================
Method 2: Use a hash table to keep the count of letters in a hash table.
While scanning the second string, keep decrementing the count.
If at the end, the count of all the characters in the hash are 0, then the two strings are 
anagrams!

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 256

int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

int isAnagram_1(char s1[],char s2[])
{
	int len1=strlen(s1),len2=strlen(s2);
	printf("len1: %d, len2: %d",len1,len2);
	qsort(s1, len1, sizeof s1[0], cmpfunc);
	qsort(s2,len2,sizeof s2[0],cmpfunc);
	int i=0;
	if(len1!=len2)
		return -1;
	while(s1[i])
	{
		if(s1[i]!=s2[i])
			return -1;
	}
	return 1;
}

int isAnagram_2(char *s1,char *s2)
{
	int hash[COUNT]={0};
	int i=0;
	while(s1[i])
	{
		hash[s1[i]]++;
		i++;
	}

	i=0;
	while(s2[i])
	{
		hash[s2[i]]--;
		i++;
	}

	for(i=0;i<COUNT;i++)
	{
		if(hash[i]>0)
			return -1;

	}
	return 1;
}


int main()
{
	char str1[]="heater";
	char str2[]="reheat";
	int len1=strlen(str1);
	int len2=strlen(str2);
	printf("======Method 1======\n");
	// qsort(str1,len1,sizeof str1[0],cmpfunc);
	
	int result1=isAnagram_1(str1,str2);
	if(result1==1)
		printf("ANAGRAMS!\n");
	else
		printf("NOPE!\n");
	// char str3[]="angle";
	// char str4[]="glaan";
	// printf("======Method 2======\n");
	// int result2=isAnagram_2(str3,str4);
	// if(result2==1)
	// 	printf("ANAGRAMS!\n");
	// else
	// 	printf("NOPE!\n");
	return 0;
}