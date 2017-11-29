
public class EquilibriumIndexOfArrayM2 {
	public static void main(String[]args)
	{
		//method1();
		//method2();
		method3();
	}
	
	public static void method1()
	{
		int[] input_arr = {10,5,15,3,4,21,2};
		int end=input_arr.length-1;
		int start = 0;
		int mid=(start+end)/2;
		int left_sum=0,right_sum=0;
		System.out.println(mid);
		while(mid>=0 && mid<=end)
		{
			left_sum=right_sum=0;
			for(int i=0;i<=mid;i++)
			{
				left_sum+=input_arr[i];
			}
			for(int j=end;j>mid;j--)
			{
				right_sum+=input_arr[j];
			}
			System.out.println("left sum= "+left_sum);
			System.out.println("right sum= "+right_sum);
			if(left_sum==right_sum)
			{
				System.out.println("Equilibrium point is: "+mid);
				break;
			}
			else if(left_sum<right_sum)
			{
				mid++;
			}
			else
			{
				mid--;
			}
		}
		
	}
	
	public static void method2()
	{
		int[] input_arr = {10,5,15,3,4,21,2};
		int size=input_arr.length;
		int left_sum=0,right_sum=0;
		for(int i=0;i<size;i++)
		{
			left_sum+=input_arr[i];
			right_sum=0;
			for(int j=i+1;j<size;j++)
			{
				right_sum+=input_arr[j];
			}
			System.out.println("left sum= "+left_sum);
			System.out.println("right sum= "+right_sum);
			if(left_sum==right_sum)
			{
				System.out.println("Equilibrium point is: "+(i));
				break;
			}
		}
		if(left_sum!=right_sum)
		{
			System.out.println("No Equilibrium point present");
		}
	}
	
	public static void method3()
	{
		int[] input_arr = {10,5,15,3,4,21,2};
		int size=input_arr.length;
		int left_sum=0,sum=0;
		
		for(int i=0;i<size;i++)
		{
			sum+=input_arr[i];
		}
		
		for(int j=0;j<size;j++)
		{
			left_sum+=input_arr[j];
			sum-=input_arr[j];
			
			if(left_sum==sum)
			{
				System.out.println("Equilibrium point is: "+(j));
				break;
			}
		}
			
	}
}
