/*In an array of n integers, construct product array such that prod[i] is equal to product of 
 * all elements except arr[i] without using division operator.
 * Implemented using two methods
 * Method 1: Naive approach TC=O(n2) SC=O(1)
 * Method 2: Find two cumulative product arrays: left_prod and right_prod
 * TC=O(n) SC=O(2n)=O(n)
 * Note: The easiest method is to find the product of all numbers in the array and divide this
 * product with the number at that index. But we are asked not to use division operator in the question.
 */ 
public class ProductArrElts_17 {
	public static void main(String[]args)
	{
//		int arr[]={2,3,4,5};
		int arr[]={10,3,5,6,2};
		System.out.println("Using method 2: ");
		prodElts_method2(arr);
	}

	private static void prodElts_method2(int[] arr) {
		int[] left_prod=new int[arr.length];
		int[] right_prod=new int[arr.length];
		int[] prod=new int[arr.length];
		left_prod[0]=arr[0];
		right_prod[arr.length-1]=arr[arr.length-1];
		System.out.println("i:0"+" left: "+left_prod[0] + " right: "+right_prod[arr.length-1]);
		for(int i=1;i<arr.length;i++)
		{
			left_prod[i]=left_prod[i-1]*arr[i];
			right_prod[arr.length-1-i]=right_prod[arr.length-i]*arr[arr.length-i-1];
			System.out.println("i:"+i+" left: "+left_prod[i] + " right: "+right_prod[arr.length-1-i]);
		}
		prod[0]=right_prod[1];
		prod[arr.length-1]=left_prod[arr.length-2];
		for(int j=1;j<arr.length-1;j++)
		{
			prod[j]=left_prod[j-1]*right_prod[j+1];
		}
		
		System.out.println("Output product array is: ");
		for(int j=0;j<arr.length;j++)
		{
			System.out.print(prod[j]+" ");
		}
		
	}
}
