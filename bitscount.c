#include <stdio.h>

int main()
{
	int i,tc;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		long long int value;
		int count=0;
		scanf("%lld",&value);
		while (value>0)
		{
			if(value%2 == 1)
			{	
				count++;
			}
			value=value/2;
		}
		printf("%d\n",count);
	}
	return 0;
}
