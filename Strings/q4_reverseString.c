/* Reverse a string 
The best way to do it is to use two pointers: one start and other end .
Now keep incrementing the start pointer and decrementing the end pointer and 
keep swapping until the mid is reached!
This is an inplace method!
TC=O(n)
Sc=O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pass the limits begin and end so that we can even reverse a substring using this function
void reverse(char *str, int start, int end)
{

	printf("start:%d, end:%d\n",start,end);
	char temp;
	while(start<end)
	{
		printf("start:%d, end:%d\n",start,end);
		temp=str[start];
		// printf("temp:%c\n",temp);
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
	}

}

int main()
{
	char str[]="NEHA";
	int begin=0,i=0;
	int end=strlen(str)-1;
	reverse(str,begin,end);
	while(str[i])
	{
		printf("%c",str[i]);
		i++;
	}
}