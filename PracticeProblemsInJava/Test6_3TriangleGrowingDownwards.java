import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test6_3TriangleGrowingDownwards {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			String str=br.readLine();
			int len=str.length();
//			System.out.println(len);
			char[] arr=str.toCharArray();
			for(int i=0;i<len;i++)
			{
				for(int d=len-i-2;d>=0;d--)
					System.out.print(".");
				for(int l=0;l<=i;l++)
					System.out.print(arr[l]);
				System.out.println();
			}
		}
	}
}
