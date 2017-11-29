import java.util.*;
import java.io.*;
public class Test1_2IsomorphicStrings {
	public static void main(String[]args) throws IOException
	{
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
//		StringTokenizer st=new StringTokenizer(br.readLine());
		for(int i=0;i<tc;i++)
		{
			String s1=br.readLine();
			String s2=br.readLine();
			HashMap<Character,Character> hm=new HashMap();
			HashMap<Character,Character> hm_back=new HashMap();
//			System.out.println(s1.length());
			if(s1.length()!=s2.length())
				System.out.println(0);
			else
			{
				int j=0;
				for(j=0;j<s1.length();j++)
				{
					
					char key=s1.charAt(j);
					char value=s2.charAt(j);
//					System.out.println("s1:"+key+" s2:"+value);
					if(hm.containsKey(key))
					{
						if(!hm.containsValue(value))
							break;
					}
					else
					{
						hm.put(key, value);
					}
					
					if(hm_back.containsKey(value))
					{
						if(!hm_back.containsValue(key))
							break;
					}
					else
					{
						hm_back.put(value, key);
					}
						
				}
//				System.out.println("=====j:"+j);
				if(j==s1.length())
					System.out.println(1);
				else
					System.out.println(0);
			}
		}
	}
}
