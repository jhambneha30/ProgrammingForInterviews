import java.util.Scanner;

public class Pattern_occurence {
	public static void main(String[]args)
	{
		Scanner input = new Scanner(System.in);
		int arr[]=new int[10];
		int counter=0;
		System.out.println("Enter 0 or 1, 10 times");
		arr[0]=input.nextInt();
		arr[1]=input.nextInt();
		arr[2]=input.nextInt();
		arr[3]=input.nextInt();
		arr[4]=input.nextInt();
		arr[5]=input.nextInt();
		arr[6]=input.nextInt();
		arr[7]=input.nextInt();
		arr[8]=input.nextInt();
		arr[9]=input.nextInt();
		
		if(arr[0]==0 && arr[1]==1 && arr[2]==0 && arr[3]==0) 
		{
			counter++;
		}
		
		if(arr[1]==0 && arr[2]==1 && arr[3]==0 && arr[4]==0) 
		{
			counter++;
		}
		
		if(arr[2]==0 && arr[3]==1 && arr[4]==0 && arr[5]==0) 
		{
			counter++;
		}
		
		if(arr[3]==0 && arr[4]==1 && arr[5]==0 && arr[6]==0) 
		{
			counter++;
		}
		
		if(arr[4]==0 && arr[5]==1 && arr[6]==0 && arr[7]==0) 
		{
			counter++;
		}
		
		if(arr[5]==0 && arr[6]==1 && arr[7]==0 && arr[8]==0) 
		{
			counter++;
		}
		
		if(arr[6]==0 && arr[7]==1 && arr[8]==0 && arr[9]==0) 
		{
			counter++;
		}
		
		System.out.println("Number of occurences: " + counter);
				
	}
}
