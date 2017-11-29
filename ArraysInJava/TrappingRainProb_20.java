/*TRAPPING RAIN WATER PROBLEM:
 * Given n non-negative integers representing an elevation map , where the width of each bar is 1.
 * Compute the amount of water that is trapped inside these bars after raining.
 * Method 1: Find the water that can be stored on top of each tile. For this, take the max of all the elements
 * on left of each tile including this one (=x say). Similarly, take the max of all the elements
 * on right of each tile including this one (=y say). Then water stored on top of this tile=Min(x,y)-height of this tile.
 * TC=O(n) SC=O(n)
 * To find max on left and right, use two temporary arrays: one containing max elt on the left for each tile and another containing
 * max elt on the right for each tile.
 */
public class TrappingRainProb_20 {
	public static void main(String[]args)
	{

		int arr[]={1,0,2,0,1,0,3,1,0,2};
		System.out.println("Using method 1: ");
		trappingRainProb(arr);
	}

	private static void trappingRainProb(int[] arr) {
		int max_right=0, max_left=0,temp;
		int water_stored=0;
		int maxRight_arr[]=new int[arr.length];
		for(int i=arr.length-1;i>=0;i--)
		{
			if(arr[i]>max_right)
			{
				max_right=arr[i];
				
			}
			maxRight_arr[i]=max_right;
		}
		
		for(int i=arr.length-1;i>=0;i--)
		{
			System.out.println(maxRight_arr[i]);
		}
		for(int j=0;j<arr.length;j++)
		{
			if(arr[j]>max_left)
			{
				max_left=arr[j];
				
			}
			temp=min(max_left,maxRight_arr[j])-arr[j];
			water_stored+=temp;
			System.out.println("j:"+j+" temp: "+temp);
		}
		
		System.out.println("Total water stored= "+water_stored);
		
	}

	private static int min(int a, int b) {
		return (a<b)?a:b;
	}
}
