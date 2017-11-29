/*Consider a set of intervals, merge all overlapping intervals.
(6,8) (2,5) (1,3) (13,20) (100,200)

Method 1: Naive approach - For every interval, scan the intervals on the right and merge the
intervals if any overlap.
In worst case, 
#comparisons for interval 1: (n-1)
#comparisons for interval 2: (n-2)
.
.
.
#comparisons for interval n: (1)
Summing, #comparisons=O(n^2)
TC=O(n^2)
SC=O(1)

Method 2: Using stack
1. Sort the array based on the first member of the interval - O(nlogn)
2. Push the first interval on to a stack.
3. For each interval do the following
   a. If the current interval does not overlap with the stack 
       top, push it.
   b. If the current interval overlaps with stack top and ending
       time of current interval is more than that of stack top, 
       update stack top with the ending  time of current interval.
4. At the end stack contains the merged intervals. 

TC=O(n) SC=O(n)

Method 3: Using single variable (in place of stack) to remember the last interval - SC=O(1)
1) Sort all intervals in decreasing order of start time.
2) Traverse sorted intervals starting from first interval, 
   do following for every interval.
      a) If current interval is not first interval and it 
         overlaps with previous interval, then merge it with
         previous interval. Keep doing it while the interval
         overlaps with the previous one.         
      b) Else add current interval to output list of intervals.

*/
#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 10


struct range
{
	int first,second;
};

struct range stack[MAX];
int top=-1; 

// int cmpfunc (const void * a, const void * b)
// {
//    return ( *(int*)a - *(int*)b );
// }
int cmp(const void *p1, const void *p2)
{
        int y1 = ((const struct range*)p1)->first;
        int y2 = ((const struct range*)p2)->first;

        if (y1 < y2)
            return -1;
        else if (y1 > y2)
            return 1;

        
}

int cmpDecreasing(const void *p1, const void *p2)
{
        int y1 = ((const struct range*)p1)->first;
        int y2 = ((const struct range*)p2)->first;

        if (y1 < y2)
            return 1;
        else if (y1 > y2)
            return -1;

        
}

int max(int a,int b)
{
  return ((a>=b)?a:b);
}

int min(int a,int b)
{
  return ((a<=b)?a:b);
}

void push(struct range item)
{
  if(top==MAX-1)
  {
    printf("Overflow!");
    return;
  }
  // top=top+1;
  stack[++top]=item;

}

struct range pop()
{
  struct range temp;
  if(top==-1)
  {
    printf("Underflow!");
    return;
  }
  temp=stack[top--];
  return temp;
}

void mergeUsingStack_2(struct range intervals[],int size)
{
  int i;

  qsort(intervals,size,sizeof(struct range), cmp);
  stack[++top]=intervals[0];

  struct range temp;
  for(i=1;i<size;i++)
  {
    //check overlap
    if(stack[top].second<intervals[i].second)
    {
      temp=pop();
      temp.second=intervals[i].second;
      push(temp);
    }
    else if(stack[top].second<intervals[i].first)
    {
      push(intervals[i]);
    }
  }

  while(top!=-1)
  {
    temp=pop();
    printf("%d-%d\n",temp.first,temp.second);
  }
}

void mergeWithoutStack_3(struct range intervals[],int n)
{
  qsort(intervals,n,sizeof(struct range), cmpDecreasing);
  struct range merged_range=intervals[0];
  int i=1;
  while(i<n)
  {
    if(intervals[i].second>=merged_range.first)
    {
      while(intervals[i].second>=merged_range.first && i<n)
      {
        // merged_range.first=intervals[i].first;
        merged_range.second = max(merged_range.second, intervals[i].second);
        merged_range.first = min(merged_range.first, intervals[i].first);
        i++;
      }
      printf("%d-%d\n",merged_range.first,merged_range.second);
    }
    else
    {
      
      printf("%d-%d\n",merged_range.first,merged_range.second);
      merged_range=intervals[i];
      i++;
    }
  }
  
  

}

int main()
{
	struct range arr_intervals[]={ {6,8}, {1,9}, {2,4}, {4,7} };
  //{{6,8}, {2,5},{1,3} , {13,20},{100,200}};
	
	int size= sizeof(arr_intervals)/sizeof(arr_intervals[0]);
  printf("-----Method2--------\n");
  mergeUsingStack_2(arr_intervals,size);
  printf("-----Method3--------\n");
  mergeWithoutStack_3(arr_intervals,size);
  
}