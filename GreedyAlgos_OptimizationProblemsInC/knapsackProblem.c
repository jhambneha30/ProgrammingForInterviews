/* Knapsack Problem:
Rather than being greedy for profits or for weights, the best solution is to be greedy 
for profit per unit weight!

===============================Algorithm:====================================
GreedyKS()
{
	1. for i=1 to n           -----------------------O(n)
			compute profit/weight;
	2. Sort the objects in non-increasing order of the profit/weight ratio---------O(nlogn)
	3. remaining_capacity=capacityOfKS;
	4. i=0
	5. for(i=0 to n)-------------------O(n)
		{
			if(remaining_capacity>0 && weight[i]<remaining_capacity)
			{
				total_profit+=profit[i];
				remaining_capacity-=weight[i];
			}
			else
				break;
		}
	6. if(remaining_capacity>0 && i<n)
		{
			total_profit+=profit[i]*(remaining_capacity/weight[i]);-------------O(1)
		}
	return total_profit;
}
==============================================================================
NOTE: We can use max heap to store the objects and then delete max one by one rather than 
sorting in decreasing order.

1. Max heapify using p/w ratio---------------O(n)
2. Delete max n times -----------------O(nlogn)
*/

#include <stdio.h>
#include <stdlib.h>
#define OBJECT_COUNT 7
typedef struct 
{
	int profit;
	float weight;
	float pw_ratio;
	
}OBJECT;

// int struct_cmp_by_price(const void *a, const void *b)
// {
//  struct st_ex *ia = (struct st_ex *)a;
//  struct st_ex *ib = (struct st_ex *)b;
//  return (int)(100.f*ia->price - 100.f*ib->price);
// /* float comparison: returns negative if b > a
//  and positive if a > b. We multiplied result by 100.0
//  to preserve decimal fraction */

// } 

int cmpfunc(const void *a, const void *b)
{
	OBJECT *pw_a= (OBJECT *)a;
	OBJECT *pw_b= (OBJECT *)b;
	return (int)(100.f*pw_b->pw_ratio - 100.f*pw_a->pw_ratio);
	/* float comparison: returns negative if b > a
 and positive if a > b. We multiplied result by 100.0
 to preserve decimal fraction */
}

float greedyKS(OBJECT list[],int capacity)
{
	int remaining_capacity=capacity;
	float total_profit=0;
	//Sort the list as per pw_ratio in decreasing order!
	qsort(list,OBJECT_COUNT,sizeof(OBJECT),cmpfunc);
	int i;
	for(i=0;i<OBJECT_COUNT;i++)
	{
		if(remaining_capacity>0 && list[i].weight<remaining_capacity)
		{
			remaining_capacity-=list[i].weight;
			total_profit+=list[i].profit;
			printf("Inside loop, i: %d, rem_capacity: %d, total_profit: %f\n",i, remaining_capacity,total_profit);
		}
		else break;

	}
	printf("Outside loop, remaining_capacity: %d, total_profit: %f\n",remaining_capacity,total_profit);
	if(remaining_capacity>0 && i<OBJECT_COUNT)
	{
		total_profit+=list[i].profit * (remaining_capacity/list[i].weight);
		remaining_capacity=0;
	}
	return total_profit;

}

int main()
{
	int ks_capacity=15;
	OBJECT object_list[OBJECT_COUNT]={{10,2,10.0/2.0},{5,3,5.0/3.0},{15,5,15.0/5.0},{7,7,7.0/7.0},{6,1,6.0/1.0},{18,4,18.0/4.0},{3,1,3.0/1.0}};
	int j;
	for(j=0;j<OBJECT_COUNT;j++)
	{
		printf("object:%d, profit:%d, weigth:%f, ratio:%f\n",j,object_list[j].profit,object_list[j].weight,object_list[j].pw_ratio);
	}
	float profit=greedyKS(object_list,ks_capacity);
	printf("Maximum possible profit is: %f\n",profit);
}