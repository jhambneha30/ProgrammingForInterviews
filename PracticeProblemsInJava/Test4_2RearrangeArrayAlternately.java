import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Test4_2RearrangeArrayAlternately {
	public static void main(String[]args) throws IOException
	{
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			int size=Integer.parseInt(br.readLine());
			int arr[]=new int[size];
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0;j<size;j++)
			{
				arr[j]=Integer.parseInt(st.nextToken());
			}
			
//			buildMinHeap(arr,size);
//			buildMaxHeap(arr,size);
			int res_arr[]=new int[size];
			int left=0,right=size-1;
			int k=0;
			while(left<=right && k+1<size)
			{
				res_arr[k]=arr[right];
				res_arr[k+1]=arr[left];
				k+=2;
				left++;
				right--;
			}
			
			if(k<size)
			{
				res_arr[k]=arr[left];
			}
			
			for(int j=0;j<size;j++)
			{
				System.out.println(res_arr[j]);
			}
		}
	}
	
}
