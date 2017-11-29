import java.util.Arrays;

/*
 * Given an array of positive numbers, find the smallest number that can't be 
 * formed with the sum of numbers from the array.
 * Method 1: Brute force: Find all possible sub arrays and check which 
 * smallest sum is not possible. TC=O(2^n)-exponential
 * Method 2: 
 * (i) Sort the array in non-decreasing order - nlogn
 * (ii) Let p be the smallest sum we cannot make, p=1
 * (iii) If the current number is bigger than the smallest number you can't make so far(i.e. p=1)
 * 		i.e. if(a(i)>p), then p is the smallest number you can't make so far with the sum of no.s
 * (iv)Else if the no. is smaller than the smallest no. we can't make so far
 * 		i.e. a(i)<=p
 * 			then update p=a(i)+p
 * 
 * 
 * TC=O(nlogn) SC=O(1)
 */
public class SmallestSumNotPossible_22 {
	public static void main(String[]args)
	{

		int arr[]={1,2,3,4,11,44,12};
		System.out.println("Using method 1: ");
		smallestSumNotPossible(arr);
	}

	private static void smallestSumNotPossible(int[] arr) {
		Arrays.sort(arr);
		int sum_not_possible=1;
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]<=sum_not_possible)
				sum_not_possible+=arr[i];
			else
			{
				break;
			}
		}
		System.out.println("Least sum not possible: "+sum_not_possible);
		
	}
}
