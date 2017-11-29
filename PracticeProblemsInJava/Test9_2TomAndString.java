import java.io.*;
import java.util.*;

public class Test9_2TomAndString {
	static String initialStr="abcdefghijklmnopqrstuvwxyz1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{

			StringTokenizer st=new StringTokenizer(br.readLine());
			ArrayList<String> list=new ArrayList<>();
			while(st.hasMoreTokens())
			{
				list.add(st.nextToken());
			}
			int numStrings=list.size();
			int sum=0;
			Iterator<String> list_it= list.iterator();
			while(list_it.hasNext())
			{
				String temp=list_it.next();
				int temp_len=temp.length();
				for(int j=0;j<temp_len;j++)
				{
					sum=sum+j+initialStr.indexOf(temp.charAt(j));
				}	
			}
			sum=sum*numStrings;
			System.out.println(sum);
		
		}
	}
	
}
