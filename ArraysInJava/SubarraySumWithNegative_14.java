import java.util.HashMap;

/*Find the sub array with given sum (array contains negative numbers).
 * Implemented using two methods
 * Method 1: Find all possible subarrays and find sum of each. TC=O(n2) SC=O(1)
 * Method 2: Use a hash table to store the cumulative sum and keep subtracting the given sum at every index. If the 
 * remaining sum is present anywhere in the hashtable, then the subarray contains this sum.
 * TC=O(n) SC=O(n)
 * Note: the method with the start and end pointers cannot be used here as 
 * we won't be able to increment decrement them due to presence of negative numbers.
 */ 
public class SubarraySumWithNegative_14 {
	public static void main(String[]args)
	{
		int arr[]={8,5,-2,3,4,-5,7};
		System.out.println("Using method 2: ");
		int sum=10;
		subarraySumWithNegatives_method2(arr,sum);
	}

	private static void subarraySumWithNegatives_method2(int[] arr, int sum) {
		HashMap<Integer,Integer> cumulative_sum=new HashMap<>();
		int cum_sum=0,flag=0;
		int remaining_sum;
		int left_index,right_index;
		for(int i=0;i<arr.length;i++)
		{
			cum_sum+=arr[i];
			cumulative_sum.put(cum_sum, 1);
			remaining_sum=cum_sum-sum;
			if(cumulative_sum.containsKey(remaining_sum))
			{
				left_index=cumulative_sum.get(remaining_sum);
				right_index=i;
				System.out.println("left: "+left_index+", right: "+right_index);
				flag=1;
			}
		}
		if(flag==0)
			System.out.println("No such subarray exists!");
		
	}
}
