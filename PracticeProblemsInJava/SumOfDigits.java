import java.util.Scanner;

/*2. Write a C program to find the sum of digits of a positive integer.
Note that the positive integer can have any value within the allowed range 
of positive integers on your computer.                         
Example- If number is 12345 then sum is 1+2+3+4+5=10 
  
  input: the number
  output: the sum of digits of the number                       [2]  */

public class SumOfDigits {
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter positive integer");
		int number=input.nextInt();
		int temp=number,sum=0;
		while(temp!=0)
		{
			sum+=temp%10;
			temp=temp/10;
		}
		System.out.println("Sum of digits is: " + sum);
	}
}
