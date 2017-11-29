/* Check if the given string is palindrome or not
For this, we use the same logic which we used to reverse the string.
Take two pointers start and end. If the character st these two pointers are equal, then
increment the start pointer and decrement the end pointer.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Pass the limits begin and end so that we can even reverse a substring using this function
int isPalindrome(char *str)
{
	int begin=0,end;
	end=strlen(str)-1;
	printf("start:%d, end:%d\n",begin,end);
	char temp;
	while(begin<end)
	{
		printf("start:%d, end:%d\n",begin,end);
		if(str[begin]==str[end])
		{
			begin++;
			end--;
		}
		else
			return -1;
	}
	return 1;

}


int main()
{
	char word[]="madam";
	int res=isPalindrome(word);
	if(res==1)
		printf("It is a palindrome!\n");
	else
		printf("Not a palindrome!\n");
	return 0;
}
