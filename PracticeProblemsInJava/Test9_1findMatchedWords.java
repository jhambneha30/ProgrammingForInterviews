import java.util.*;
import java.io.*;
public class Test9_1findMatchedWords {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			int numStrings=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			ArrayList<String> dictionary=new ArrayList<>();
			for(int i=0;i<numStrings;i++)
			{
				dictionary.add(st.nextToken());
			}
			String input_str=br.readLine();
			
			findMatchedWords(dictionary,input_str);
		
		}
	}
	
	public static ArrayList<String> findMatchedWords(ArrayList<String> dict, String pattern)
	{
		ArrayList<String> mappedPatterns= new ArrayList<>();
		Iterator<String> dict_it= dict.iterator();
		while(dict_it.hasNext())
		{
			String str=dict_it.next();
			if(isMapped(str,pattern))
				mappedPatterns.add(str);
		}
		Collections.sort(mappedPatterns);
		return mappedPatterns;
	}

	private static boolean isMapped(String str, String pattern) {
		char[] hash_forward=new char[256];
		char[] hash_backward=new char[256];
		for(int f=0;f<256;f++)
		{
			hash_forward[f]='!';
			hash_backward[f]='!';
		}
		int str_len=str.length();
		int patt_len=pattern.length();
		if(str_len!=patt_len)
			return false;
		for(int i=0;i<str_len;i++)
		{
			if(hash_forward[str.charAt(i)]=='!')
				hash_forward[str.charAt(i)]=pattern.charAt(i);
			else if(hash_forward[str.charAt(i)]!=pattern.charAt(i))
				return false;
			
			if(hash_backward[pattern.charAt(i)]=='!')
				hash_backward[pattern.charAt(i)]=str.charAt(i);
			else if(hash_backward[pattern.charAt(i)]!=str.charAt(i))
				return false;
		}
		return true;
	}
}
