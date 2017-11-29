/*Job sequencing with deadlines
For this, we have two options:
Greedy about profit OR Greedy about deadlines.
=========================================================================================
Greedy about profit: Take the job with highest profit first without considering the deadline.
Just check if that job can be placed in the first cell (if deadline is less than the endoing
point of the cell). This DOES NOT give the optimized solution as we are not considering the 
deadlines
=========================================================================================
Greedy about deadlines: 
Total jobs which can be placed=Max deadline possible

================================Algorithm:===================================
JobSequencing(jobs) //job will be give  with its deadline and profit
{
	1. Make an output array of size= max deadline possible  -----O(n)
	2. if(deadline>num_jobs)
			output array size=num_jobs
	3. Sort the array in decreasing order of jobs           ------O(nlogn)
	4. for(i=1 to n)                                        ------O(n^2)
		{
			->Pick the job at index i, check its deadline and place it just before the deadline or at the 
			end of the output array if its deadline is greater than size of output array.
			->In case, this position is already filled, traverse the output array backward, till
			an empty slot is found.
		}

}

TC=O(n^2)
SC=O(n)
*/

#include <stdio.h>
#include <stdlib.h>
#define COUNT 4

typedef struct
{
	int id;
	int deadline;
	int profit;
	
}JOB;

int cmpfunc(const void *a,const void *b)
{
	JOB *job_a=(JOB *)a;
	JOB *job_b=(JOB *)b;
	return (int)(job_b->profit - job_a->profit);
}

int jobSequencing(JOB j_list[],int output_list[])
{
	qsort(j_list,COUNT,sizeof(JOB),cmpfunc);
	int i,total_profit=0;
	for(i=0;i<COUNT;i++)
	{
		int index=j_list[i].deadline-1;
		printf("i:%d, output[i]:%d, index:%d\n",i,output_list[i],index);
		if(output_list[index]==0)
		{
			output_list[index]=j_list[i].id;
			total_profit+=j_list[i].profit;
		}
		else
		{
			index--;
			while(index>=0)
			{
				if(output_list[index]==0)
				{
					output_list[index]=j_list[i].id;
					total_profit+=j_list[i].profit;
					break;
				}
				index--;
			}
		}
	}
	return total_profit;
}

int main()
{
	JOB job_list[COUNT]={{1,2,6},{2,1,8},{3,1,5},{4,2,10}};
	int i,max=0,flag=0;
	//Find the max deadline and check if it less than number of jobs
	for(i=0;i<COUNT;i++)
	{
		if(job_list[i].deadline>max)
		{
			max=job_list[i].deadline;
		}
			
	}
	printf("max1: %d\n",max);

	if(max>COUNT)
	{
		max=COUNT;
		flag=1;
	}
	printf("max2: %d\n",max);

	int *output_list=(int *)calloc(max,sizeof(int));
	int max_profit=jobSequencing(job_list,output_list);
	printf("Max possible profit is:%d\n",max_profit);
	--max;
	while(max>=0)
	{
		printf("%d ",output_list[max]);
		max--;
	}
	return 0;
}