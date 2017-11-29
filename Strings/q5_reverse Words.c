/*Reverse the words in a given sentence.
Method 1:
Example: i am neha
1. First reverse the words in the string. Words can be found using white spaces in the string.
I ma ahen ---------O(n)
2. Then reverse the entire string as a whole
neha am i  ------------O(n)

We can also do this by carrying out step 2 first and then step 1.
TC=O(n)+O(n)=O(n)
SC=O(1) as everything is done in place
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
		// printf("start:%d, end:%d\n",start,end);
		temp=str[start];
		// printf("temp:%c\n",temp);
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
	}

}

void reverseWords(char *sentence)
{
	int i;
	int size=strlen(sentence);
	int start=0,end;
	for(i=0;i<=strlen(sentence);i++)
	{
		if(sentence[i]==' ' || sentence[i]=='\0')
		{
			end=i-1;
			reverse(sentence,start,end);
			start=i+1;
		}
	}

	reverse(sentence,0,size-1);
}

int main()
{
	char sentence[]="meet my friend";
	reverseWords(sentence);
	int j=0;
	while(sentence[j])
	{
		printf("%c",sentence[j]);
		j++;
	}
	return 0;
}
