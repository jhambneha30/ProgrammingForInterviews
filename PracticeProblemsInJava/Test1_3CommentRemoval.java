//http://www.geeksforgeeks.org/remove-comments-given-cc-program/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Test1_3CommentRemoval {
	public static void main(String[]args) throws NumberFormatException, IOException
	{
		Scanner input=new Scanner(System.in);
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			String bigCode=br.readLine();
			
//			String bigCode="hello // jwj \n ee";
//			System.out.println(bigCode);
			int len=bigCode.length();
//			System.out.println("len is:"+len);
			String smallCode="";
			
			int j=0;
			while(j<len)
			{
				if(bigCode.charAt(j)=='/' && bigCode.charAt(j+1)=='/')
				{
					j+=2;
//					System.out.println("====="+bigCode.charAt(j)+bigCode.charAt(j+1));
					while(j<len && bigCode.charAt(j)!='\\' && bigCode.charAt(j)!='n')
					{
//						System.out.println("-----"+bigCode.charAt(j)+"-----");
						j++;
					}
//					System.out.println(bigCode.charAt(j));
					j+=2;
				}
				else if(bigCode.charAt(j)=='/' && bigCode.charAt(j+1)=='*')
				{
					j+=2;
					while(bigCode.charAt(j)!='*' && bigCode.charAt(j+1)!='/')
					{
						j++;
					}
					j+=2;
				}
				else
				{
					smallCode+=bigCode.charAt(j);
					j++;
				}
					
				
			}
			System.out.println(smallCode);
		}
	}
}
