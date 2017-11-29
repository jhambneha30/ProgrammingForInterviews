/* Check whether given two strings are rotations of each other or not 
NUMBER OF POSSIBLE STRINGS POSSIBLE AFTER ALL POSSIBLE ROTATIONS=n (n is number of chars in the
string)

First check: size of both strings should be same.

Method 1:
Form all possible rotations of string 1 and compare with string 2
TC=O(n^2)
SC=O(1) as the rotation can be done inplace

Method 2:
1. First check the size of 2 strings.
2. Concatenate the first string with itself-O(1)
3. Check if the second string is a substring of the concatenated string. If yes, it is a
rotation of string 1.

Note: For substring checking, we use KMP ALGORITHM! - O(n)
TC=O(n)
SC=O(n) for concatenated string.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isRotation(char *s1, char *s2)
{
	int l1=strlen(s1), l2=strlen(s2);
	if(l1!=l2)
		return -1;
	char *temp=(char *)malloc(sizeof(char)*(l1*2+1));
	if(!temp)
		return -1;
	temp[0]='\0';
	strcat(temp,s1);
	strcat(temp,s1);
	char *ptr=strstr(temp,s2);
	/*This function returns a pointer to the first occurrence in haystack of any of 
	the entire sequence of characters specified in needle, or a null pointer if the 
	sequence is not present in haystack. */
	return ptr?0:-1;
}

int main()
{
	char *str1="ravi";
	char *str2="iarv";

	int result=isRotation(str1,str2);
	if(result==0)
		printf("str2 is a rotation of str1\n");
	else
		printf("str2 is a NOT a rotation of str1\n");

}