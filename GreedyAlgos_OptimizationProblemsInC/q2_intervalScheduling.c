/* INTERVAL SCHEDULING : Pick maximum number of intervals which do not overlap.
Example: (10,13) , (9,14) , (7,11) , (12,16) , (20,25) , (1,50)hb

Solution 1: Greedy about small intervals: We assume that the shortest intervals if picked 
will over lap with least number of other intervals. But it fails to find optimal solution.
Ex: (2,11) , (10,12) , (12,15)
This solution will give the ans 1 (it will pick shortest interval (10,12) and then will 
fail to find any other interval which won't overlap with it.)  
While, the ans should be 2: (2,11) and (12,15) 

Solution 2: Greedy about starting point: We might think that if we choose the intervals
wich start early, then we might get the optimal solution. But then for cases like:
Ex: (2,12) , (3,4) , (5,7) , (8,11)
This solution will give ans=1 while the ans should be 3.

Solution 3: Greedy about ending time: If we choose this method, there is no way we will miss
out on any non overlapping pairs.

Step 1. Sort basis the end times. - O(nlogn)
Step 2. Keep incrementing the count if there is no overlap. - O(n^2)
TC=O(n^2)
Reason for time taken by step 2:First we will add the first interval (0 comparisons),
then to add the next interval - (1 comparison), then to add the third interval - (2 comparisons)
....at the end to add the nth interval - (n-1)comparisons
=> time taken = sum of these comparisons =sum of first (n-1) numbers = O(n^2)

Ex: A(2,11) , B(10,12) , C(12,15)
In this case, we will choose A and then C! = > we get ans=2

OPTMIZATION: Note that if we have added A,B,C,D and now we want to add E, we check E with D if
it is overlapping. If E overlaps with D, then only we need to check it with C and others.
If not, then we can directly add E as it won't overlap with any of C,B or A (because the end
time of C is less than the start time of D. If E does not overlap D, then it definitely won't 
overlap C.) => TC of step2 is reduced to O(n).
=> TC=O(n log n + n) = O(nlogn)
*/

#include <stdio.h>
#include <stdlib.h>
#define INTERVAL_COUNT 6

struct interval
{
	char id;
	int start;
	int end;
};

int cmpfunc(const void *a, const void *b)
{
	struct interval *i1= (struct interval *)a;
	struct interval *i2= (struct interval *)b;
	return (i1->end-i2->end);
}

int checkOverlap(struct interval x, struct interval y)
{
	printf("Inside func: %c start:%d <= %c end:%d\n",x.id,x.start,y.id,y.end);
	if(x.start<=y.end)
		return 1;

	return 0;
}

int nonOverlappingIntervals(struct interval list[],struct interval output[])
{
	qsort(list,INTERVAL_COUNT,sizeof(struct interval),cmpfunc);
	//Now check if the intervals are overlapping.
	int i,count=0;
	for(i=0;i<INTERVAL_COUNT;i++)
	{
		if(i==0)
		{
			output[i]=list[i];
			count++;
		}
		else
		{
			printf("count @ i:%d is:%d\n",i,count);
			int j=count-1;
			while(j>=0)
			{
				// printf("i:%d, j:%d\n",i,j);
				// printf("sending: %c and %c\n",list[i].id,output[j].id);
				if(checkOverlap(list[i],output[j])==1)
				{
					//add the interval to output
					// printf("came back with 1: %c and %c\n",list[i].id,output[j].id);
					j--;
				}
				else
				{
					output[count]=list[i];
					count=count+1;
					break;
				}
			}

		}	

	}
	return count;

}

int main()
{
	struct interval i_list[INTERVAL_COUNT]={{'A',10,13},{'B',9,14},{'C',7,11},{'D',12,16},{'E',20,25},{'F',1,50}};
	struct interval nonOverlap_ids[INTERVAL_COUNT];
	int nonOverlap_num,a=0;
	nonOverlap_num=nonOverlappingIntervals(i_list,nonOverlap_ids);
	printf("Count is:%d\n",nonOverlap_num);
	while(a<nonOverlap_num)
	{
		printf("%c ",nonOverlap_ids[a].id);
		a++;
	}
	return 0;
}