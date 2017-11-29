/*Find the sub array with given sum (array does not contain negative numbers).
 * Implemented using two methods
 * Method 1: Find all possible subarrays and find sum of each. TC=O(n2) SC=O(1)
 * Method 2: Use two pointers start and end of the subarray ad keep incrementing depending on the current sum.
 * TC=O(n) SC=O(1)
 */ 
public class SubarraySumWithoutNegative_13 {
	public static void main(String[]args)
	{
		int arr[]={8,5,3,1,2,7};
		System.out.println("Using method 2: ");
		int sum=9;
		subarraySum_method2(arr,sum);
	}

	private static void subarraySum_method2(int[] arr, int sum) {
		int start=0,end=0,current_sum=arr[start];
		while(end<arr.length || current_sum!=sum)
		{
			
			if(current_sum<sum)
			{
				end++;
				if(end>arr.length-1)
				{
					System.out.println("No subarray with this sum is present!");
					break;
				}
				current_sum+=arr[end];
			}
				
			else if(current_sum>sum)
			{
				current_sum-=arr[start];
				start++;
			}
			else
			{
				System.out.println("Subarray indices are: "+start +" "+end);
				start++;
//				break;
			}
		}
		
	}

}
