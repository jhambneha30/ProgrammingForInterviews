import java.util.Scanner;

public class Min_Max {
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		int arr[] = new int[3];
		System.out.println("Enter three integers");
		for(int i=0;i<3;i++)
		{
			arr[i]=input.nextInt();
		}
		int temp_max = arr[0]>arr[1]?arr[0]:arr[1];
		int max = temp_max>arr[2]?temp_max:arr[2];
		
		int temp_min = arr[0]<arr[1]?arr[0]:arr[1];
		int min = temp_min<arr[2]?temp_min:arr[2];
		
		System.out.println("Max is: "+ max);
		System.out.println("Min is: "+ min);
	}
}
