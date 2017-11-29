#include <stdio.h>
#include <stdlib.h>


int main()
{
	int tc,t,N;
	
	scanf("%d",&tc);
	for(t=0;t<tc;t++)
	{
		scanf("%d",&N);
		
		int lower_limit[N], upper_limit[N],k,l,s,count=0,max=1;
		int min=0,tmp1,tmp2;
		//printf("index=%d\n",ind);
		for(k=0;k<N;k++)
		{
			scanf("%d %d", &lower_limit[k], &upper_limit[k]);
		}
		int ind;
		ind=2*N;
		
		int o,p,q,r,c=0,d=0,i=0;
		for(o=0;o<N-1;o++)
		{
			min=o;
			for(p=o+1;p<N;p++)
			{
				if(lower_limit[p]<lower_limit[min])
					min=p;
			}
			if(min!=o)
			{
			tmp1=lower_limit[o];
			lower_limit[o]=lower_limit[min];
			lower_limit[min]=tmp1;
			}
		}

		for(q=0;q<N-1;q++)
		{
			min=q;
			for(r=q+1;r<N;r++)
			{
				if(upper_limit[r]<upper_limit[min])
					min=r;
			}
			if(min!=q)
			{tmp2=upper_limit[q];
			upper_limit[q]=upper_limit[min];
			upper_limit[min]=tmp2;}
			
		}
		char ab[ind];
		while(c<N && d<N )
		{
			if(lower_limit[c]<upper_limit[d])
			{
				//arr[i]=lower_limit[c];
				ab[i]='s';
				c++;

			}
			else if(lower_limit[c]>upper_limit[d])
			{
				//arr[i]=upper_limit[d];
				ab[i]='e';
				d++;
			}
			else if(lower_limit[c]==upper_limit[d])
			{
				ab[i]='e';
				d++;
			}
			i++;
			
		}

		//printf("%d",max);
		//printf("%d",ind);
		
		for(s=0;s<ind;s++)
		{
			//printf("blaa");
			//printf("%c",ab[s]);
			if(ab[s]=='s')
			{
				count++;
				if(count>max)
					max=count;
				//printf("%d",max);
			}
			else if(ab[s]=='e')
				count--;
		}
				
			printf("%d\n",max);

	}
	return 0;
}