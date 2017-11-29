import java.util.Scanner;

public class MergeSort {
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
		
		mergeSort(0,(size-1));
		System.out.println("Sorted array is: ");
		for(int x=0;x<arr.length;x++)
		{
			System.out.print(arr[x]+" ");
		}
	}

	private static void mergeSort(int start, int end) {
		int mid;
		if(start<end)
		{
			mid=(start+end)/2;
			System.out.println("mid is: "+mid);
			mergeSort(start,mid);
			mergeSort(mid+1,end);
			merge(start,mid,end);
		}
		
		
		
		
	}

	private static void merge( int start, int mid, int end) {
		
		int n1=mid-start+1;
		int n2=end-mid;
		
		int left[] = new int[n1+1];
		int right[] = new int[n2+1];
		System.out.println("left size n1 "+left.length);
		System.out.println("right size n2 "+right.length);
		left[n1]=999999999;
		right[n2]=999999999;
		System.out.println("Left array is: ");
		for(int i=0;i<n1;i++)
		{
			left[i]=arr[start+i];
			System.out.print(left[i]+" ");
		}
		
		System.out.println("Right array is: ");
		for(int j=0;j<n2;j++)
		{
			right[j]=arr[mid+j+1];
			System.out.print(right[j]+" ");
		}
		
		int l=0,r=0;
		for(int k=start;k<=end;k++)
		{
			if(left[l]<=right[r])
			{
				arr[k]=left[l];
				l++;
			}
			else
			{
				arr[k]=right[r];
				r++;
			}
		}
		
		
		
		
	}
}
