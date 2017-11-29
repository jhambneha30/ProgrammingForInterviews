import java.util.Scanner;

public class QuickSort {
	static int arr[];
	public static void main(String[]args)
	{
		Scanner input=new Scanner(System.in);
		System.out.println("Enter the size of array");
		int size=input.nextInt();
		arr=new int[size];
		System.out.println("Enter the numbers to be sorted");
		for(int x=0;x<size;x++)
		{
			arr[x]=input.nextInt();
		}
		
		
		quickSort(0,size-1);
		
		System.out.println("Sorted array is: ");
		for(int x=0;x<arr.length;x++)
		{
			System.out.print(arr[x]+" ");
		}
	}
	private static void quickSort(int p, int r) {
		int q;
		if(p<r)
		{
			q=partition(p,r);
			quickSort(p,q-1);
			quickSort(q+1,r);
		}
		
	}
	private static int partition(int p, int r) {
		int pivot=arr[r];
		int i=p-1,temp;
		
		for(int j=p;j<r;j++)
		{
			if(arr[j]<pivot)
			{
				i++;
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		arr[r]=arr[i+1];
		arr[i+1]=pivot;
		return i+1;
	}
}
