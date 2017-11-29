import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test9_3CheckRotatedPalindrome {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			String str=br.readLine();
			int n=str.length();
			String temp=str;
			int flag=0;
			for(int j=0;j<n;j++)
			{
				temp=temp.substring(1)+temp.charAt(0);
				if(isPalindrome(temp))
				{
					flag=1;
					break;
				}
					
//				System.out.println(temp);
			}
			if(flag==1)
				System.out.println(1);
			else
				System.out.println(0);
		}
	}

	private static boolean isPalindrome(String str) {
		int n=str.length();
		for(int i=0;i<n/2;i++)
		{
			if(str.charAt(i)!=str.charAt(n-i-1))
				return false;
		}
		return true;
	}
}
