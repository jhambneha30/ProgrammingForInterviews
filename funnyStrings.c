#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int main()
{
	int counter,T=100,f,i,j,v1,v2;
	char *S[T];
	bool isFunny[T];
	
	printf("Enter number of testcases\n");
	scanf("%d",&T);
	if(T<1 || T>100)
	{
		printf("Invalid input\n");
	}
	else
	{
	for(f=0;f<T;f++)
	{
		isFunny[f]=true;
	}
	for(counter=0;counter<T;counter++)
	{	
		char temp[1000];
		printf("Enter the string: ");
		scanf("%s",temp);
		if(strlen(temp) < 2 || strlen(temp) > 1000){
			printf("Invalid input\n");
			counter--;
			continue;
		}else{
			S[counter]=(char *)malloc(strlen(temp) + 1);
			strcpy(S[counter],temp);				
		}
		
		j=strlen(S[counter])-1;
		for(i=1;i<j;i++)
		{
			v1=abs((int)(S[counter][i-1])-(int)(S[counter][i]));
			if(j>=0)
			{
				v2=abs((int)(S[counter][j])-(int)(S[counter][j-1]));
				j--;
				
			}
			if(v1!=v2)
			{
				isFunny[counter]=false;
				break;
			}
		}
				
		
	}
	
	for(counter=0;counter<T;counter++)
	{
		if(isFunny[counter]==true)
		{
			printf("Funny\n");
		}
		else
		{
			printf("Not funny\n");			
		}		
		
	}
	}

	return(0);
}
