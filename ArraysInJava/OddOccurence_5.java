import java.util.Scanner;

/*Find the numbers occurring odd no. of times, given exactly one no. occurs odd no. of times.
  Implemented using two methods
  Method 1: Count the occurence of each no. using nested loop. TC=O(n2) and SC=O(1)
  Method 2: Using hash table. TC=O(n) and SC=O(range)
  Method 3: Using XOR(modulo 2 sum) (a xor a = 0, a xor a xor a =a) TC=O(n) and SC=O(1)
  Note: In java, an array is automatically initialized to 0.
   */ 
public class OddOccurence_5 {
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
		
		int result=find_oddOccurenceNum_method3(arr);
		if(result==0)
			System.out.println("No number occurs odd times!");
		else
			System.out.println("Num occuring odd times is: "+result);
	}

	private static int find_oddOccurenceNum_method3(int arr[]) {
		int res=0;
		for(int i=0;i<arr.length;i++)
		{
			res=res^arr[i];
		}
		return res;
	}
}
