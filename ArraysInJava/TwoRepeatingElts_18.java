/* An array of size n+2, all elements in the range 1 to n occur once except two elts which occur twice.
 * Find the two repeating elements.
 * Method 1: Naive approach, find every possible pair and check if the elts are same.
 * TC=O(nC2)=O(n2)
 * Method 2: An array (hash table) to keep the count of the numbers from 1 to n.TC=SC=O(n)
 * Method 3: Let repeating no.s are x and y, then,
 * Step i)sum of array elts-sum of n natural no.s=(x+Y)
 * Step ii) Find product of entire array=p and factorial of n=p1, then x*y*p1=p
 * then x*y=p/p1
 * Step iii) Compute x-y using (x-y)^2=(x+y)^2-4xy
 * Step iv) Now we have value of x+y and that of x-y, so compute x and y.
 * TC=O(n) SC=O(1) but this method is computationaly very heavy due to large no. of multiplications involved
 * Note: Since prod of entire array needs to be computed, we might need to use 
 * a user defined data structure to store the value of product if the value it too large.
 * So, this method is not recommended!
 *  
 * Method 4: a xor a = 0, 0 xor b = b, xor is commutative
 * This means a xor a xor b = b, a xor b xor a = b
 * Xor all the elements of the array and the natural numbers till n, then only (x xor y) will be left.
 * Algorithm:
 * 	(i) Find XOR of all elts in the array xy=XOR arr[i]; where i=0 to n+1
 *  (ii) Find XOR of repeating elts by doing XOR with the natural no.s till n
 *  	xy=xy XOR i; where i-1 to n
 *  (iii) Find rightmost set bit in xy by
 *  	set_bit=xy & ~(xy-1)
 *  (iv) Based on set_bit, divide the array elts into two groups
 *  	Let X= XOR of all elts of one group, Y= XOR of all elts of other group
 *  	Similarly, divide the natural no.s till n into two groups based on set_bit.
 *  	Now based on set_bit, XOR with respective groups.
 *  
 *  TC=O(n) SC=O(1)
 *  
 *  Method 5: Use the negation method from Que 17 (method 2)
 *  TC=O(n) SC=O(1)
 */
public class TwoRepeatingElts_18 {
	public static void main(String[]args)
	{
//		int arr[]={2,3,1,3,2,4};
//		int arr[]={2,4,2,5,4,3,1};
		int arr[]={1,3,1,2,3};
		System.out.println("Using method 2: ");
		findRepeatedElts_method4(arr);
	}

	private static void findRepeatedElts_method4(int[] arr) {
		int max=arr.length-2;
		int xor_xy=arr[0],xor_x=0,xor_y=0;
		int set_bit;
		//Step i
		for(int i=1;i<arr.length;i++)
		{
//			if(arr[i]>max)
//				max=arr[i];
			xor_xy=xor_xy^arr[i];
		}
//		System.out.println("xor: "+xor_xy);
		//Step ii
		for(int j=1;j<=max;j++)
		{
			xor_xy=xor_xy^j;
		}
		//Step iii Find the right most set bit in xor_xy
		set_bit=xor_xy & (~(xor_xy-1));
		
//		System.out.println("set bit: "+set_bit);
		
		//Step iv Dividing array elts into 2 grps
		for(int k=0;k<arr.length;k++)
		{
			if((arr[k]& set_bit)==set_bit)
			{
				xor_x=xor_x^arr[k];
			}
			else
			{
				xor_y=xor_y^arr[k];
			}
		}
		
		//Step v Dividing natural no.s into two grps
		for(int l=1;l<=max;l++)
		{
			if((l& set_bit)==set_bit)
			{
				xor_x=xor_x^l;
			}
			else
			{
				xor_y=xor_y^l;
			}
		}
		
		System.out.println("Repeating numbers are: "+xor_x+", "+xor_y);
	}
}
