import java.util.Scanner;

public class MajorityUnsortedMoore_3 {
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
			
			moore_majority(arr);
		}

	private static void moore_majority(int[] arr) {
		int voter=arr[0],votes=1;
		double half=(double)arr.length/2;
		for(int i=1;i<arr.length;i++)
		{
			if(votes==0)
			{
				voter=arr[i];
				votes++;
			}
				
			if(arr[i]==voter)
				votes++;
			else
				votes--;
			
		}
		int count=0;
		if(votes>=1)
		{
			//Scan the array to find the occurences of voter
			for(int j=0;j<arr.length;j++)
			{
				if(arr[j]==voter)
					count++;
			}
		}
		
		if(count>half)
			System.out.println("Majority is: "+voter);
		else
			System.out.println("No majority element exists!");
		
	}
}