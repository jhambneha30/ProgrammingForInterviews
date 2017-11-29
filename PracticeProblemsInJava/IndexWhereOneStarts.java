//------------------To be completed--------------------
public class IndexWhereOneStarts {
	static int[] arr={0,0,0,1,1};
	
	public static void main(String[]args)
	{
		
		method1(arr);
		//method2();
		
	}

	private static void method1(int[] arr) {
		int index=1;
		while(true)
		{
			if(arr[index-1]==1)
			{
				int final_index=binary_search(index/2-1,index-1);
				while(arr[final_index]==1)
				{
					final_index--;
				}
				System.out.println("First one occurs "+(final_index+1));
				break;
			}
			else
			{
				index*=2;
				
			}
				
		}
	}

	private static int binary_search(int start_index,int end_index) {
		for(int i=start_index;i<=end_index;i++)
		{
			int mid=(start_index+end_index)/2;
			if(arr[mid]<1)
			{
				end_index=mid;
			}
			else if(arr[mid]==1)
			{
				return mid;
			}
		}
		
		return 0;
	}
}
