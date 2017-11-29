/*Find duplicates in linear time, given the numbers in the array are in range n.
 * Method 1: Go to the index of the element and make it negative. TC=O(n) SC=O(1)
 * Conditions: Range has to be within n and duplicates means repeated not more than once.
 * Also, elements should be positive.
 */
public class FindDuplicatesLinear_18 {
	public static void main(String[]args)
	{
		int arr[]={2,3,1,3,2};
		System.out.println("Using method 2: ");
		findDupsLinear_method1(arr);
	}

	private static void findDupsLinear_method1(int[] arr) {
		int index;
		for(int i=0;i<arr.length;i++)
		{
//			System.out.println(arr[i]);
			index=Math.abs(arr[i])-1;
			if(arr[index]>0)
				arr[index]=-1*(arr[index]);
			else
				System.out.println(Math.abs(arr[i])+" is repeated");
			System.out.println(arr[index]);
		}
		
	}
}
