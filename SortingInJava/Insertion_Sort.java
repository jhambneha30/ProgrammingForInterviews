import java.util.Scanner;
/*Sort a nearly sorted array in which each element is displaced by atmost k positions
 * Method 1: Use quick sort or merge sort TC=O(nlogn)
 * Method 2:(BEST) Use Insertion sort. In this, the displaced elements will be required to be moved 
 * at most by k positions and hence TC=O(nk). If k<<n or k<logn, this is better than quick sort and merge sort.
 * */ 
public class Insertion_Sort {
	public static void main(String[]args)
	{
		
		Scanner input=new Scanner(System.in);
		System.out.println("Enter the size of array");
		int size=input.nextInt();
		int arr[]=new int[size];
		System.out.println("Enter the numbers to be sorted");
		for(int x=0;x<size;x++)
		{
			arr[x]=input.nextInt();
		}
		int i;
		for(int j=1;j<size;j++)
		{
			int key=arr[j];
			i=j-1;
			while(i>=0 && arr[i]>key)
			{
				arr[i+1]=arr[i];
				i=i-1;
			}
			arr[i+1]=key;
		}
		
		System.out.println("Sorted array is:");
		for(int k=0;k<size;k++)
		{
			System.out.print(arr[k] + "\t");
		}
		
	}
}
