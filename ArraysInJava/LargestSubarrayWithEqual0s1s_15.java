/*Find the largest sub array with equal number of 0's and 1's.
 * Implemented using two methods
 * Method 1: Find all possible subarrays and check which one has equal number of 0's ad 1's and is the largest.
 * TC=O(n3) [n2 to find all possible sub arrays * n to check equal 0's or not] 
 * Method 2: Use two hash tables to store the cumulative sum of 1's and 0's and keep subtracting the given sum at every index. If the 
 * remaining sum is present anywhere in the hashtable, then the subarr present till now.
 * Note: the method with the start and end pointers cannot be used here as 
 * we won't be able to increment decrement them due to presence of negative numbers.
 */ 
public class LargestSubarrayWithEqual0s1s_15 {
	public static void main(String[]args)
	{
		int arr[]={0,1,1,1,0,1,1,0};
		System.out.println("Using method 2: ");
		largestSubarray_method2(arr);
		System.out.println("Using method 3: ");
		largestSubarray_method3(arr);
	}

	private static void largestSubarray_method3(int[] arr) {
		int cum_sum[]=new int[arr.length];
		int sum_till_now=0, max_sum=0,min_sum=0;
		int lb=0,ub=0,max_size=0;
		int normalized_index;
		//Make hashmap after computing the range of sum
//		for(int x=0;x<arr.length;x++)
//		{
//			if(arr[x]==0)
//				arr[x]=-1;
//		}
		for(int k=0;k<arr.length;k++)
		{
//			sum_till_now+=arr[k];
			sum_till_now+=(arr[k]==0)?-1:1;
			cum_sum[k]=sum_till_now;
			if(sum_till_now>max_sum)
				max_sum=sum_till_now;
			if(sum_till_now<min_sum)
				min_sum=sum_till_now;
			System.out.println("k:"+k+" cum_sum: "+cum_sum[k]);
		}
		
		int hm[]=new int[max_sum-min_sum+1];
		for(int y=0;y<arr.length;y++)
		{
			
			
			if(cum_sum[y]>0)
			{
				//Normalize the index of hash map
				normalized_index=cum_sum[y]-min_sum;
				if(hm[normalized_index]==0)
					hm[normalized_index]=y;
				else
				{
					if(y-hm[normalized_index]>max_size)
					{
						lb=hm[normalized_index]+1;
						ub=y;
						max_size=ub-lb+1;
						//max_size=y-hm[normalized_index];
					}
					
				}
			}
			else if(cum_sum[y]==0)
			{
//				if((y+1)>size)
//				{
				//The is condn is not reqd as this sub array's size will always be greater than any other subarray which doesn't start with index 0.
					lb=0;
					ub=y;
					max_size=y+1;
//				}
			}
			
		}
		System.out.println("largest size: "+max_size);
		System.out.println("start: "+lb+ "end: "+ub);
		
		
	}

	private static void largestSubarray_method2(int[] arr) {
		int count_zeroes[]=new int[arr.length];
		int count_ones[]=new int[arr.length];
		int count_0=0,count_1=0;
		int subArr0s,subArr1s;
		int largest_size=0,size;
		int start_index=0,end_index=0;
		for(int k=0;k<arr.length;k++)
		{
			if(arr[k]==0)
			{
				count_0++;	
			}
			else if(arr[k]==1)
			{
				count_1++;	
			}	
			count_zeroes[k]=count_0;
			count_ones[k]=count_1;
			System.out.println("k:"+k+" count0:"+count_zeroes[k]+" count1:"+count_ones[k]);
		}
		for(int i=0;i<arr.length-1;i++)
		{
			for(int j=i+1;j<arr.length;j++)
			{
				size=j-i+1;
				if(i-1<0)
				{
					subArr0s=count_zeroes[j]-0;
					subArr1s=count_ones[j]-0;
				}
				else
				{
					subArr0s=count_zeroes[j]-count_zeroes[i-1];
					subArr1s=count_ones[j]-count_ones[i-1];
				}
				
//				System.out.println("subArr0s: "+subArr0s+" subArr1s: "+subArr1s);
				if(subArr0s==subArr1s && size>largest_size)
				{
					largest_size=size;
					start_index=i;
					end_index=j;
				}
			}
		}
		
		System.out.println("largest size: "+largest_size);
		System.out.println("start: "+start_index+ "end: "+end_index);
		
	}
}
