import java.util.Scanner;

/*A3) 3. Write a C program to calculate the value approximate numerical value 
of sin(x), where the argument "x" (in radians) is a floating point number 
entered by the user. Use the relationship between the (n+1)-th and n-th 
term of the Taylor series expansion of sin(x) in your program. Use the 
"do....while" construct. Stop the iterations using the "break" construct 
once the difference between the absolute values of two consecutive terms
becomes less than 0.001.
   
   input: The value of x
   output: Approximate value of sin(x)                     [2] */

public class TaylorSeries {
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		float sum_sinx=0, abs_diff;
		System.out.println("Enter a floating point number");
		float number=input.nextFloat();
		int coeff=1,counter=0;
		do
		{
			float temp=sum_sinx;
			if(counter%2==0)
			{
				sum_sinx+=Math.pow(number, coeff)/factorial(coeff);
				System.out.println("number: "+number + " coeff: " + coeff + " sum_sinx: "+ sum_sinx);
			}
			else if(counter%2!=0)
			{
				sum_sinx-=Math.pow(number, coeff)/factorial(coeff);
				System.out.println("number: "+number + " coeff: " + coeff+" sum_sinx: "+ sum_sinx);
			}
				
			
			coeff+=2;
			counter++;
			
			abs_diff=Math.abs(Math.abs(temp)-Math.abs(sum_sinx));
			if(abs_diff<=0.001)
				break;
		}
		while(true);
		
		System.out.println("sin x = " + sum_sinx);
		
	}

	private static int factorial(int coeff) {
		int fact=1;
		if(coeff==0 || coeff ==1)
			return 1;
		
		else
			fact=fact*factorial(coeff-1);
				
		return 0;
	}
}
