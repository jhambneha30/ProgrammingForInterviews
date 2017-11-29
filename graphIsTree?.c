#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int N=0,M=0;
int matrix[10000][10000];


int cycleExists(int vertex, int parent, int *ptr)
{
	int k,r;
	ptr[vertex]=1;
	//printf("vertex and parent are:%d %d\n",vertex,parent);
	for(k=1;k<=N;k++)
	{
		if(matrix[vertex][k]==1)
		{	
			// printf("Adjacent node is:%d\n",k);
			// printf("Adjacent node's count is:%d\n",ptr[k]);
			if(ptr[k]==0)
			{
				r=cycleExists(k,vertex,ptr);
				// printf("returned value is:%d\n",r);
				if(r==1)
					return 1;
			}
			else if(ptr[k]==1)
			{
				if(k!=parent)
				{
					// printf("vertex and parent inside condn:%d %d\n",vertex,parent);
					// printf("Adjacent node is inside condn:%d\n",k);
					// printf("Adjacent node's count is inside condn:%d\n",ptr[k]);
					return 1;
				}
					
			}
		}
	}
	return 0;
}
int main()
{
	int t=0, tc, j, i, l, c, d;
	int p,q,z;
	int flag=0;
	scanf("%d",&tc);
	for(t=0;t<tc;t++)
	{
		//N is the no. of edges
		//M is the no. of edges
		scanf("%d %d",&N,&M);
		int beg[M], end[M], arr[N];
		for(j=1;j<=M;j++)
		{
			scanf("%d %d", &beg[j],&end[j]);
		}
		// printf("N and M are:%d %d\n", N, M);
		//Creating adj matrix
		for(c=1;c<=N;c++)
		{
			arr[c]=0;
			for(d=1;d<=N;d++)
			{
				matrix[c][d]=0;
			}
		}
		for(i=1;i<=M;i++)
		{
			matrix[beg[i]][end[i]]=1;
			matrix[end[i]][beg[i]]=1;
		}
		// for(p=1;p<=N;p++)
		// {
		// 	arr[c]=0;
		// 	for(q=1;q<=N;q++)
		// 	{
		// 		printf("%d ",matrix[p][q]);
		// 	}
		// 	printf("\n");
		// }
		int result=cycleExists(1, -1, arr);
		// printf("Array is:\n");
		// for(z=1;z<=N;z++)
		// {
		// 	printf("%d\n",arr[z]);
		// }
		for(l=1;l<=N;l++)
		{
			if(arr[l]==0)
			{
				flag=1;
				break;
			}
				
		}

		
		// printf("flag is:%d\n",flag);
		// printf("result is:%d\n",result);
		if(flag==0 && result==0)
			printf("YES\n");
		else 
			printf("NO\n");

	}
	return 0;
}