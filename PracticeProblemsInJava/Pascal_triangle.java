import java.util.ArrayList;
import java.util.Scanner;

/* 1. Write a C program to print "Pascal's Triangle". 
The numbers in the r-th row of Pascal's triangle represent
the coefficients in the Binomial expansion of (a+b)^{r-1}.
The first four rows of Pascal triangle are shown below :-
       1
      1 1
     1 2 1
    1 3 3 1
  
  input: Number of rows of Pascal triangle to print
  output: Resultant Pascal's Triangle                          [3]

*/

public class Pascal_triangle {
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		System.out.println("Enter number of rows of the pascal triangle");
		int rows=input.nextInt();
		int arr[] = new int[rows];
		for(int i=0;i<rows;i++)
		{
			for(int j=rows;j>i+1;j--)
			{
				System.out.print("   ");
			}
			int arr_temp[];
			arr_temp = arr.clone();

			arr[0]=1;
			for(int x=1;x<i;x++)
			{
				arr[x]=arr_temp[x-1]+arr_temp[x];
			}
			arr[i]=1;

			
			for(int k=0;k<i+1;k++)
			{
				System.out.print(arr[k]+ "   ");
			}
			System.out.println();
		}
	}
}
