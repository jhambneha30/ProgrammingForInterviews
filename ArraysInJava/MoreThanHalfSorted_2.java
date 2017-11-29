import java.util.Arrays;
import java.util.Scanner;

/*Given a sorted array of size n, find an element that occurs more than n/2 times
  Implemented using two methods
  Method 1: Use the count array to store the number of occurences of an element TC=O(n+k) SC=O(k)
  Method 2: While scanning array, count the occurences and if #occurences>half, print the element TC=O(n) SC=O(1)
  Method 3: Simply jump to the index arr(i+half) to check if the elt occurs enough no. of times TC=O(n) SC=O(1)
   */ 
public class MoreThanHalfSorted_2 {
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
		Arrays.sort(arr);
		
		//Method 1
		//Method 2
		System.out.println("Method 1: Use the count array to store the number of occurences of an element TC=O(n+k) SC=O(k)");
		System.out.println("Method 2: While scanning array, count the occurences and if #occurences>half, print the element TC=O(n) SC=O(1)");
		majority_method2(arr);
		//Method 3
		System.out.println("Method 3: Simply jump to the index arr(i+half) to check if the elt occurs enough no. of times TC=O(n) SC=O(1)");
		majority_method3(arr);
		
	}

	private static void majority_method3(int[] arr) {
		double len=arr.length;
		int half=(int) Math.ceil(len/2);
		int index,flag=0;
		if(arr.length%2==0)
			index=half;
		else
			index=half-1;
		
		System.out.println("half: "+half);
		for(int j=0;j<half;j++)
		{
			int num=arr[j];
			if(arr[j+index]==num)
			{
				System.out.println("Majority elt is: "+num);
				flag=1;
				break;
			}
		}
		if(flag==0)
			System.out.println("No majority element exists!");
		
	}

	private static void majority_method2(int[] arr) {
		double half=(double)arr.length/2;
		System.out.println("half is: "+half);
		int flag=0,temp=arr[0];
		int count=0;
		for(int i=0;i<arr.length;i++)
		{
			if(arr[i]==temp)
				count++;
			else
			{
//				System.out.println("temp: "+temp + " count: " + count);
				if(count>half)
				{
					flag=1;
					System.out.println("Majority element is: "+ temp);
					break;
				}
				temp=arr[i];
				count=1;
			}
		}
//		System.out.println("temp: "+temp + " count: " + count);
		if(count>half)
		{
			flag=1;
			System.out.println("Majority element is: "+ temp);
		}
		if(flag==0)
			System.out.println("No majority element exists!");
	}
}
