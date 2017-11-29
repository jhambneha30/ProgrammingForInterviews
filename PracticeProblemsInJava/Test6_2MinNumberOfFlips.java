import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test6_2MinNumberOfFlips {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		int min_flips=0;
		for(int t=0;t<tc;t++)
		{
			String str=br.readLine();
			char[] str_arr=str.toCharArray();
			int len=str.length();
			char[] alt1=new char[len];
			char[] alt2=new char[len];
			for(int x=0;x<len;x+=2)
			{
				alt1[x]='1';
				alt2[x]='0';
			}
			for(int y=1;y<len;y+=2)
			{
				alt1[y]='0';
				alt2[y]='1';
			}
			int flips1=0,flips2=0;
			for(int i=0;i<len;i++)
			{
//				System.out.println(alt1[i]+"  "+alt2[i]);
				if(str_arr[i]!=alt1[i])
					flips1++;
				if(str_arr[i]!=alt2[i])
					flips2++;
			}
			
			int num_flips = flips1<flips2?flips1:flips2;
			System.out.println(num_flips);

		}
	}
	
	static char flip(char c)
	{
		if(c=='0')
			return '1';
		else
			return '0';
	}
}
