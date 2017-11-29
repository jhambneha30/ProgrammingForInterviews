import java.util.Arrays;
import java.util.Scanner;
/*Given an array, find two elements closest to zero.
 * Implemented using two methods
 * Method 1: Use nested loops to find all possible pairs. TC=O(n2) SC=O(1)
 * Method 2: Sort, then scan while having two ptrs. Whenever sum is on positive side, decrease the positive number.
 * Whenever sum is on negative side, increase the negative number. TC=O(nlogn) SC=O(1)
 */ 
public class ClosestToZero_7 {
	public static void main(String[]args)
	{
//		int arr[] = {-2,9,6,1,2,-5};
		int arr[] = {-79,-9,0,59,69,84};
		
		closestToZero_method2(arr);
	}

	private static void closestToZero_method2(int[] arr) {
		Arrays.sort(arr);
		int left=0, right=arr.length-1;
		int a=arr[left],b=arr[right];
		int sum=a+b, least_sum=99999;
		int min_a=a,min_b=b;
		while(left<right)
		{
			sum=a+b;
			
			if(sum>0)
				right--;
			else
				left++;
			
			if(Math.abs(sum)<Math.abs(least_sum))
			{
				//Update the least sum
				least_sum=sum;
				min_a=a;
				min_b=b;
			}
				
			a=arr[left];
			b=arr[right];
			
		}
		
		System.out.println("The pair closest to 0 is: " +min_a + " "+ min_b);
		System.out.println("Sum is: "+least_sum);
		
		
	}
}
