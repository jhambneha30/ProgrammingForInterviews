import java.io.*;

class Test6_1LastMatch {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			String A=br.readLine();
			int a_len=A.length();
			String B=br.readLine();
			int b_len=B.length();
			int last=-1,l=0;
			for(int k=0;k<a_len;k++)
			{
				int temp=k;
				if(A.charAt(k)==B.charAt(l))
				{
					while(l<b_len && temp<a_len && B.charAt(l)==A.charAt(temp))
					{
						System.out.println(B.charAt(l)+"--"+A.charAt(temp));
						l++;
						temp++;
					}
					if(l==b_len)
					{
						last=k;
//						k+=b_len-1;
					}
					l=0;
				}
			}
			if(last!=-1)
				System.out.println(last+1);
			else
				System.out.println(last);
		}
	}
}
