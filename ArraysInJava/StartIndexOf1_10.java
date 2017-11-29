/*Given an array of unknown size, with 0's first followed by 1's in the end. Find the index where 1's start.
 * Implemented using two methods
 * Method 1: Linear search 
 * Method 2: Go in multiples of a number, say 2 and stop when 1 is found. Then between this index and between the last index 
 * explored, apply binary search (as w know the bound now).
 * 
 * Note: TC and SC can't be determined as the size of input array is unknown.
 */ 
public class StartIndexOf1_10 {
	public static void main(String[]args)
	{
		int arr[]={0,0,0,0,0};//1,1,1,1,1,1,1};
		System.out.println("Using method 2: ");
		int index=findIndexOf1_method1(arr);
		if(index==-1)
			System.out.println("1 doesn't exist");
		else
			System.out.println("Index of 1 is: "+ index);
	}

	private static int findIndexOf1_method1(int[] arr) {
		int i=0;
		try
		{
			while(arr[i]!=1)
			{
				i+=2;
			}
		}
		catch(Exception e)
		{
			i=-1;
		}
		if(i==-1)
			return i;
		else
		{
			int start=i/2, end=i;
			int index=binary_search(1, arr, start, end);
			return index;
		}
		
	}
	
	private static int binary_search(int item, int[] arr, int start, int end) {
		int p=start,q=end;
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
