import java.util.*;
import java.io.*;
public class Test3_3BinarySearch {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			int arraySize=Integer.parseInt(br.readLine());
			int arr[]=new int[arraySize];
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int i=0;i<arraySize;i++)
			{
				arr[i]=Integer.parseInt(st.nextToken());
						
			}
			int item=Integer.parseInt(br.readLine());
			
			int index=binarySearch(arr,arraySize,item);
			System.out.println(index);
		}
	}
	
	
	public static int binarySearch(int arr[],int n,int item)
	{
		int start=0,end=n-1;
		int mid=0;
		while(start<end)
		{
			mid=(start+end)/2;
			if(item<arr[mid])
			{
				end=mid-1;
			}
			else if(item>arr[mid])
			{
				start=mid+1;
			}
			else
				return mid;
				
		}
		return mid;
	}
}
