import java.util.Arrays;

/*Find the equilibrium index in an array.
 * Implemented using three methods
 * Method 1: For each index, check if it is an equilibrium index. TC=O(n2) SC=O(1)
 * Method 2: Compute cumulative leftSum and rightSum arrays and compare them. TC=O(n) SC=O(n)
 * Method 3: Use two pointers left and right and keep changing the ptrs till the eq index is reached or these ptrs cross each other.
 * TC=O(n) SC=O(1)
 */ 
public class EquilibriumIndex_9 {
	public static void main(String[]args)
	{
		int arr[]={8,2,1,3,6};
		System.out.println("Using method 1: ");
		eqIndex_method1(arr);
		System.out.println("Using method 2: ");
		threeEltSum_method2(arr);
		System.out.println("Using method 3: ");
		threeEltSum_method3(arr);
	}

	private static void threeEltSum_method3(int[] arr) {
		int left=0,right=arr.length-1;
		int leftSum=arr[left],rightSum=arr[right],flag=0;
		while(left<right)
		{
//			System.out.println("leftsum:"+leftSum + " rightsum: "+rightSum);
			if(leftSum<rightSum)
			{
				left++;
				leftSum+=arr[left];
			}
			else if(leftSum>rightSum)
			{
				right--;
				rightSum+=arr[right];
			}
			else
			{
				flag=1;
				System.out.println("Equilibrium index is: "+left);
				break;
			}
		}
		if(flag==0)
			System.out.println("No equilibrium index exists!");
		
	}

	private static void threeEltSum_method2(int[] arr) {
		int leftSum[]=new int[arr.length];
		int rightSum[]=new int[arr.length];
		int ls=0,rs=0,flag=0;
		for(int i=0;i<arr.length;i++)
		{
			ls+=arr[i];
			rs+=arr[arr.length-i-1];
			leftSum[i]=ls;
			rightSum[arr.length-i-1]+=rs;
//			System.out.println("leftSum[i]: "+leftSum[i] + " rightSum[arr.length-i-1]: "+rightSum[arr.length-i-1]);
		}
		
		for(int j=0;j<arr.length-1;j++)
		{
			if(rightSum[j+1]==leftSum[j])
			{
				System.out.println("Equilibrium index is: "+(j));
				flag=1;
				break;
			}
		}
		if(flag==0)
			System.out.println("No equilibrium index exists!");
		
		
	}

	private static void eqIndex_method1(int[] arr) {
		int leftSum=0,rightSum=0,flag=0;
		for(int i=0;i<arr.length-1;i++)
		{
			leftSum+=arr[i];
			rightSum=0;
			for(int j=i+1;j<arr.length;j++)
			{
				rightSum+=arr[j];
			}
//			System.out.println("leftsum:"+leftSum + " rightsum: "+rightSum);
			if(leftSum==rightSum)
			{
				System.out.println("Equilibrium index is: "+i);
				flag=1;
				break;
			}
		}
		if(flag==0)
			System.out.println("No equilibrium index exists!");
		
	}
}
