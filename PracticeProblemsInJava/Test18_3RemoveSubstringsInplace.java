import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test18_3RemoveSubstringsInplace {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			String str=br.readLine();
			StringBuilder st=new StringBuilder(str);
			int len=str.length();
			if(len==0)
				System.out.println("");
			else {
				int i=0,replace=0;
				while(i<len) {
					if(i+1<len && str.charAt(i)=='a' && str.charAt(i+1)=='c') {
						i+=2;
					}
					else if(str.charAt(i)=='b') {
						i++;
					}
					else {
						st.setCharAt(replace, str.charAt(i));
						replace++;
						i++;
					}
				}
//				System.out.println(replace);
				System.out.println(st.substring(0, replace));
			}
			
		}
	}
}
