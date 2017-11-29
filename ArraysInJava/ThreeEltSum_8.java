import java.util.Arrays;
import java.util.Scanner;
/*Given an array, find three elements such that their sum is x.
 * Implemented using two methods
 * Method 1: Use nested loops to find all possible pairs. TC=O(n2) SC=O(1)
 * Method 2: Sort (nlogn), then optimize the third loop from method 1 by using binary search to find the remaining sum (n2logn)
 * TC=O(nlogn +n2logn)=O(n2logn) SC=O(1) 
 * Sort and fix one number. Then use two ptrs left and right for the remaining numbers in the array. TC=O(n2) SC=O(1)
 */ 
public class ThreeEltSum_8 {
	public static void main(String[]args)
	{
//		int arr[] = {2,6,5,10,9,1};
		int arr[]={0,3,44,5,9,7};
		int sum=19;
		Arrays.sort(arr);
		System.out.println("Using method 2: ");
		threeEltSum_method2(arr,sum);
		System.out.println("Using method 3: ");
		threeEltSum_method3(arr,sum);
	}

	private static void threeEltSum_method3(int[] arr,int sum) {
		int fixed, left,right,flag=0;
		for(int k=0;k<arr.length-2;k++)
		{
			fixed=arr[k];
			left=k+1;
			right=arr.length-1;
			while(left<right)
			{
				if(fixed+arr[left]+arr[right]<sum)
					left++;
				else if(fixed+arr[left]+arr[right]>sum)
					right--;
				else
				{
					System.out.println("The three numbers are: "+arr[left]+", "+arr[right]+ ", "+fixed);
					left++;
					right--;
					flag=1;
				}
					
			}
			
		}
		if(flag==0)
			System.out.println("sum doesn't exist!");
		
	}

	private static void threeEltSum_method2(int[] arr,int sum) {
		int flag=0;
		for(int i=0;i<arr.length-2;i++)
		{
			for(int j=i+1;j<arr.length-1;j++)
			{
				if(arr[i]+arr[j]<sum)
				{
					int index=-10;
					//search for remaining sum
					int remaining_sum=sum-(arr[i]+arr[j]);
					if(remaining_sum!=arr[i] && remaining_sum!=arr[j])
						index=binary_search(remaining_sum,arr);
					if(index!=-1 && index!=-10)
					{
						flag=1;
						System.out.println("The three numbers are: "+arr[i]+", "+arr[j]+ ", "+arr[index]);
					}
						
				}
			}
		}
		if(flag==0)
			System.out.println("sum doesn't exist!");
	}

	private static int binary_search(int item, int[] arr) {
		int p=0,q=arr.length;
		int index=-1;
		while(p<=q)
		{
			int mid=(p+q)/2;
//			System.out.println("mid: "+mid);
//			System.out.println("p: "+p + "q: "+q);
			if(arr[mid]>item)
			{
//				p=0;
				q=mid-1;
			}
			else if(arr[mid]<item)
			{
				p=mid+1;
//				q=arr.length-1;
			}
			else
			{
				index=mid;
				break;
			}
		}
		return index;
	}
}
