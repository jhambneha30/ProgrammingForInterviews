import java.util.Arrays;

/*
 * Given an unsorted array of positive integers. The no. of triangles 
 * that can be formed with three different elements as three sides of triangle
 * Method 1: Brute force: Check the condition a+b>c for all the three sides. 
 * The number of triplets possible=nC3. TC=O(n3) 
 * Method 2: 
 * (i) Sort the array in non-decreasing order
 * (ii) Take two ptrs - i and j
 * 	i-points to 1st element
 * 	j-points to 2nd element
 * sum=0
 * for(i= 0 to n-3
 * 		k=i+2
 * 		for j=i+1 to n-2
 * 			repeat until: k<n & arr[i]+arr[j]>arr[k]
 * 				k=k+1
 * 			sum=sum+k-j-1
 * return sum
 * 
 * TC=O(n2) SC=O(1)
 */
public class TrianglesPossible_21 {
	public static void main(String[]args)
	{

		int arr[]={6,7,8,10,12,14,50};
		System.out.println("Using method 1: ");
		int numTriangles=trianglesPossible_method2(arr);
		
		System.out.println("Number of triangles possible: "+numTriangles);
	}

	private static int trianglesPossible_method2(int[] arr) {
		int sum=0;
		int k;
		Arrays.sort(arr);
		for(int i=0;i<arr.length-2;i++)
		{
//			k=i+2;
			for(int j=i+1;j<arr.length-1;j++)
			{
				k=j+1;
				
				while(k<arr.length && arr[i]+arr[j]>arr[k])
				{
					System.out.println(arr[i]+" "+arr[j]+" "+arr[k]);
					k++;
					
				}
				sum=sum+k-j-1;
				System.out.println("sum is: "+sum);
			}
			
		}
		return sum;
	}
}
