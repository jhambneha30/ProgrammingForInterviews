import java.util.Scanner;

public class CountingSort {
	public static void main(String[]args)
	{
		
		Scanner input=new Scanner(System.in);
		System.out.println("Enter the range of the numbers");
		int range=input.nextInt();
		System.out.println("Enter the size of array");
		int size=input.nextInt();
		int arr[]=new int[size];
		
		
		System.out.println("Enter the numbers to be sorted");
		for(int x=0;x<size;x++)
		{
			arr[x]=input.nextInt();
		}
		arr=countSort(arr,range);
		System.out.println("Sorted array is: ");
		for(int x=0;x<arr.length;x++)
		{
			System.out.print(arr[x]+" ");
		}
		
	}

	private static int[] countSort(int[] arr, int range) {
		int size=arr.length;
		int count[]= new int[range];
		int output[]=new int[size];
		
		for(int i=0;i<range;i++)
		{
			count[i]=0;
		}
		for(int i=0;i<size;i++)
		{
			count[arr[i]-1]=count[arr[i]-1]+1;
//			System.out.println("count is: "+count[arr[i]-1]);
		}
		
		
		
		for(int j=1;j<range;j++)
		{
			count[j]=count[j]+count[j-1];
		}
		
//		System.out.println("printing count....");
		//printing count
//		for(int i=0;i<range;i++)
//		{
//			System.out.println(count[i]);
//		}
		for(int k=size-1;k>=0;k--)
		{
			output[count[arr[k]-1]-1]=arr[k];
			count[arr[k]-1]--;
		}
		
		
		
		return output;
	}
}
