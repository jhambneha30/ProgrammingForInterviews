import java.util.Scanner;

/*1. Write a C function to find whether a positive integer is a power of two, using
   a function "void is_power_of_two (int number)".
   Hint: use the shift operator, and iterate over each bit. DO NOT COMPARE WITH SUCCESIVE
   POWERS OF TWO.
   Input: A positive integer.
   Output : "yes" if the number is power of two, else "no".    [2]
*/

public class PowerOf2 {
	static int numBits=1;
	
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter a positive integer");
		int number=input.nextInt();
		boolean result = isPowerOfTwo(number);
//		int res = number & (number-1);
//		boolean isPowerOfTwo = !(number==0) && (res==0);
		if(result==true)
			System.out.println("It is a power of 2");
		else
			System.out.println("Not a power of 2");
		
		//int array_bits[] = new int[numBits];
		//array_bits=converToBinary(number);
		
	}
	
	public static boolean isPowerOfTwo(int x)
	{
	 while (((x & 1) == 0) && x > 1) /* While x is even and > 1 */
	   x >>= 1;
	  if(x == 1)
		  return true;
	return false;
	}

//	private static int[] converToBinary(int number) {
//		if(number==0)
//		{
//			numBits=1;
//		}
//		int counter=numBits-1;
//		int arr_bits[] = new int[numBits];
//		if(number<1)
//		{
//			System.out.println("Enter a positive integer!");
//			return null;
//		}
//		
//		arr_bits[counter]=number%2;
//		counter--;
//		converToBinary(number>>1);
//			
//		return null;
//	}
}
