/* RUN LENGTH ENCODING
In a file, there can be a run of characters 
Example: SSMMMAAAAPP
Then, while compressing the file, these can be encoded as: S2M3A4P2

For this, we just keep the count of characters while scanning. We start with S, count=1, then
check next character, if it is same as previous one increment the count, otherwsie print the count 
and make count=1

TC=O(n)
SC=O(1)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runLengthEncoding(char str[],char output[])
{
	int count=1,i=1,j=0;
	int len=strlen(str);
	for(i=0;i<=len;i++)
	{
		if(str[i]==str[i-1])
		{
			count++;
		}
		else
		{
			output[j]=str[i-1];
			output[j+1]=count;
			j+=2;
			printf("%c%d",str[i-1],count);
			count=1;
			
		}
				
	}
}

int main()
{
	char str[]="SSMMMAAAAPP";
	char output[strlen(str)];
	runLengthEncoding(str,output);
	return 0;
}