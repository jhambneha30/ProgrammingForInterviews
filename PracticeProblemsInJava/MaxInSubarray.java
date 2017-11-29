/*Given an array and an integer k, fin max element for
 *  each and every contiguous subarray of size k.
 */

public class MaxInSubarray {
	public static void main(String[]args)
	{
		//int[] arr={10,4,2,11,3};
		int[] arr={10,4,2,11,3,15,12,8,7,9,21,14};
		int k=3;
		int size=arr.length;
		int max=0;
		for(int j=0;j<k;j++)
		{
			if(arr[j]>max)
				max=arr[j];
		}
		System.out.println("Max in subarray1 is:"+max );
		for(int i=1;i<size-k+1;i++)
		{
			if(arr[i+(k-1)]>max)
				max=arr[i+(k-1)];
			System.out.println("Max in subarray" +(i+1)+" is:"+max );
		}
	}
}
