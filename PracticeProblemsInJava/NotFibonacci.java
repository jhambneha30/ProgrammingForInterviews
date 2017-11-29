/*A3)The Fibonacci Sequence is the series of numbers:
   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...n terms
   The next number is found by adding up the two numbers before it. 0 and 1 are the starting numbers.
   Write a C program to print the numbers that do not appear in the Fibonacci series.
   
   input: Number of terms 👎 in Fibonacci sequence to be considered.  
   output: The numbers that are not in Fibonacci sequence. For
   example, if the user enters n=7, the values to be printed are: 4 6 7     [3]*/

import java.util.Scanner;

public class NotFibonacci {
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter no. of terms in Fibonacci sequence to be considered");
		int number=input.nextInt();
		int temp1=0,temp2=1;
		for(int i=0;i<number;i++)
		{
			if(i==0 || i==1)
				continue;
			int fib_num = temp1+temp2;
			temp1=temp2;
			temp2=fib_num;
			
			for(int j=temp1+1;j<temp2 && j<=number;j++)
			{
				System.out.println(j);
			}
			if(fib_num>number)
				break;
		}
	}
}
