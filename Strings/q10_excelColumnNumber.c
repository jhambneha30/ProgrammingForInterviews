/* Find excel column name for given excel column number.
In excel, the columns are numbered as A,B...Z,AA,AB....ZZ and so on.
WE USE THE NUMBER SYSTEM WITH BASE 26 (just that out no. system starts with 1 and not 0)
Example:
Binary:01, Ternary:012, Octal:01..7, Hex:01...F 
Base 26: 1...26=A...Z

From 1-26, the naming is simple, 27th column is named by computing the string as:
Keep dividing the number, until we get a number smaller than or equal to 26. Now take the remainders and put them together.
EX: For 27, quotient is 1 and remainder is 1 => string is 11==>AA
For 28, quotient is 1 and remainder is 2 => string is 12==>AB
For 26*26+2
step 1: quotient is 26, remander is 2--------------stop here!------string is 26 2=ZB
(step 2: quotient is 1, remainder is 0 ------------this is not required )

Note: In other number systems, while doing the conversion from decimal to that number system,
we stop when we get a quotient strictly less than the base (as other systems start with 0)!

Similarly, we can do the conversion in the reverse order
Given AB, column number=26^1*1+26^0*2=28 (in powers, we have positions and we know that A=1, B=2)


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 27
#define MAX 50
char hash[COUNT];

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

void getColumnName(int colNum,char output[])
{
	char arr[MAX];
	int quotient,rem,i=0;
	quotient=9999;
	// rem=colNum%26;
	// colNum=quotient;
	// output[0]=hash[rem];
	// i++;
	while(quotient>26)
	{
		quotient=colNum/26;
		printf("quotient: %d\n",quotient);
		rem=colNum%26;
		printf("rem: %d\n",rem);
		colNum=quotient;
		output[i]=hash[rem];
		printf("hash[rem]: %c\n",hash[rem]);
		i++;
	}
	output[i]=hash[quotient];
	printf("hash[quotient]: %c\n",hash[quotient]);
	output[++i]='\0';
	reverse(output,0,i-1);

}

int main()
{
	
	int i;
	char output[MAX];
	hash[1]='A';
	for(i=2;i<COUNT;i++)
	{
		hash[i]=hash[i-1]+1;
	}

	for(i=1;i<COUNT;i++)
	{
		printf("%c ",hash[i]);
	}

	getColumnName((678),output);

	int j=0;
	while(output[j])
	{
		printf("%c ",output[j]);
		j++;
	}

	return 0;
}