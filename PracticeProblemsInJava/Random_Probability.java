/*2. Write a C program that generates a random number between 5 and 10, using 
   the "rand()" function in stdlib.h, and outputs 'a', 'b' , 'c' , 'd' 
   with prob('a')=2/10, prob('b')=3/10, prob('c')=3/10, prob('d')=2/10 respectively.
        output: 10 numbers generated. DO NOT USE LOOPS.   [3]*/


import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
public class Random_Probability {
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		int x = 0;
		while(x!=10)
		{
			int randomNum = random_generation();
			if(randomNum<3)
				System.out.println("a");
			else if(randomNum<6)
				System.out.println("b");
			else if(randomNum<9)
				System.out.println("c");
			else if(randomNum<11)
				System.out.println("d");
			System.out.println("Enter 10 to exit, any other number to continue");
			x = input.nextInt();
		}
		
	}
	
	public static int random_generation()
	{
		return ThreadLocalRandom.current().nextInt(1,10+1);
	}
}
