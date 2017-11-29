import java.util.Scanner;
/*Separate 0's and 1's in an array.
  Implemented using two methods
  Method 1: Count the occurence of 0's and 1's and store in a hash table. TC=O(n) and SC=O(n)
  Method 2: Find the sum of the array and put 1's as per the computed index. TC=O(n) SC=O(1)
  Method 3: Use start and end pointers and keep swapping the 0's and 1's. TC=O(n) SC=O(1)
  This method is also used to put together even and odd numbers. For this, use modulus to find remainder and swap accordingly.
   */ 
public class ZeroesOnesTogether_6 {
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
		
		arr=separate0s1s_method2(arr);
		System.out.println("Array using method 2:");
		for(int x=0;x<arr.length;x++)
		{
			System.out.print(arr[x]+" ");
		}
		
		arr=separate0s1s_method3(arr);
		System.out.println("Array using method 3:");
		for(int x=0;x<arr.length;x++)
		{
			System.out.print(arr[x]+" ");
		}
	}

	private static int[] separate0s1s_method3(int[] arr) {
		int start=0,end=arr.length-1;
		while(start<end)
		{
//			if(arr[start]==1 && arr[end]==0)
//			{
//				int temp=arr[start];
//				arr[start]=arr[end];
//				arr[end]=temp;
//				
//				start++;
//				end--;
//			}
//			if(arr[start]==0)
//				start++;
//			if(arr[end]==1)
//				end--;
			
			while(arr[start]==0 && start<end)
			{
				start++;
			}
			while(arr[end]==1 && end>start)
			{
				end--;
			}
			if(start<end)
			{
				arr[start++]=0;
				arr[end--]=1;
			}
		}
		return arr;
	}

	private static int[] separate0s1s_method2(int[] arr) {
		int sum=0;
		for(int i=0;i<arr.length;i++)
		{
			sum+=arr[i];
		}
		for(int j=0;j<arr.length;j++)
		{
			arr[j]=0;
			if(j>=(arr.length-sum))
				arr[j]=1;
		}
		return arr;
	}
}
