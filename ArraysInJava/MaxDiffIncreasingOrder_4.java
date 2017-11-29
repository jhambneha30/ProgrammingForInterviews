import java.util.Scanner;
/*Find the max difference in an array such that the larger element occurs after the smaller element
Implemented using three methods
Method 1: Take an elt, compare with remaining elts on right, find the max difference TC=O(n) SC=O(1)
Method 2: Use the max sum subarray by computing the diff array TC=O(n) SC=O(n)-taken by diff array
Algo is:
	Construct the diff array from given array using TC=O(n)
		diff(i)=arr(i+1)-arr(i)
		
	Find the max sum subarray i the diff array
		current_diff=diff(0)
		for all arr(i) i=1:n
			Check diff(i-1)>0
				update diff(i)=diff(i-1)+diff(i)
			current_diff=maximum(current_diff,diff(i))
			
	return current_diff
	
Note: Method 2(improved): The SC in this algo can be reduced to constant by implementing the max sum subarray algo along with computing the diff array
Method 3: To get the max difference, the elt on the left has to be the minimum elt so far. Use min_so_far and maxDiff_so_far TC=O(n) SC=O(1)
 */ 
public class MaxDiffIncreasingOrder_4 {
	public static void main(String[]args)
	{
		
		Scanner input=new Scanner(System.in);
		System.out.println("Enter the size of array.");
		int size=input.nextInt();
		int arr[]=new int[size];
		System.out.println("Enter the numbers in the array.");
		for(int x=0;x<size;x++)
		{
			arr[x]=input.nextInt();
		}
		int maxDiff;
		System.out.println("Method 1: Take an elt, compare with remaining elts on right, find the max difference TC=O(n) SC=O(1)");
		maxDiff=maxDiff_method1(arr);
		System.out.println("Max diff using method 1: "+ maxDiff);
	
		System.out.println("Method 2: Use the max sum subarray by computing the diff array TC=O(n) SC=O(n)-taken by diff array");
		maxDiff=maxDiff_method2(arr);
		System.out.println("Max diff using method 2: "+ maxDiff);
		
		maxDiff=maxDiff_method2_improved(arr);
		System.out.println("Max diff using method 2 improved: "+ maxDiff);
		
		System.out.println("Method 3: To get the max difference, the elt on the left has to be the minimum elt so far. TC=O(n) SC=O(1)");
		maxDiff=maxDiff_method3(arr);
		System.out.println("Max diff using method 3: "+ maxDiff);
	}

	private static int maxDiff_method3(int[] arr) {
		int min_so_far=arr[0],elt1,elt2;
		int max_diff_so_far=arr[1]-arr[0];
		for(int k=1;k<arr.length;k++)
		{
			if(arr[k]<min_so_far)
				min_so_far=arr[k];
			else //Because we need to carry out below step only if this let is not an elt smaller than the min_so_far
			{
				if(arr[k]-min_so_far > max_diff_so_far)
				{
					max_diff_so_far=arr[k]-min_so_far;
					elt1=arr[k];
					elt2=min_so_far;
				}
			}
				
		}
		if(max_diff_so_far<=0)
			max_diff_so_far=0;
		return max_diff_so_far;
	}

	private static int maxDiff_method2_improved(int[] arr) {
		//Compute difference array
		int diff[] =  {arr[1]-arr[0],arr[2]-arr[1]};
		
		int current_diff=diff[0];
		for(int j=2;j<arr.length-1;j++)
		{
			
			if(diff[0]>0)
			{
				diff[1]=diff[1]+diff[0];
			}
			if(diff[1]>current_diff)
				current_diff=diff[1];
//			System.out.println("j:"+j+" diff[0]: "+ diff[0]+ " diff[1]: " +diff[1]);
			diff[0]=diff[1];
			diff[1]=arr[j+1]-arr[j];
//			System.out.println("j:"+j+" diff[0]: "+ diff[0]+ " diff[1]: " +diff[1]);
		}
		return current_diff;
	}

	private static int maxDiff_method2(int[] arr) {
		//Compute difference array
		int[] diff =  new int[arr.length-1]; 
		for(int i=0;i<arr.length-1;i++)
		{
			diff[i]=arr[i+1]-arr[i];
		}
		
		int current_diff=diff[0];
		for(int j=1;j<diff.length;j++)
		{
			if(diff[j-1]>0)
			{
				diff[j]+=diff[j-1];
			}
			if(diff[j]>current_diff)
				current_diff=diff[j];
		}
		return current_diff;
	}

	private static int maxDiff_method1(int[] arr) {
		int current_max=0;
		for(int i=0;i<arr.length;i++)
		{
			for(int j=i+1;j<arr.length;j++)
			{
				if(arr[j]-arr[i]>current_max)
				{
					current_max=arr[j]-arr[i];
				}
			}
		}
		return current_max;
	}
}
