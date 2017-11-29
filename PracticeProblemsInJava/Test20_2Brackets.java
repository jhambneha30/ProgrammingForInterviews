import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://www.codechef.com/problems/BRACKETS

public class Test20_2Brackets {
	public static void main(String[]args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			String str=br.readLine();
			int len=str.length();
			int bal=0,max_bal=Integer.MIN_VALUE;
			for(int i=0;i<len;i++) {
				if(str.charAt(i)=='(') {
					bal++;
				}
				else if(str.charAt(i)==')') {
					bal--;
				}
				max_bal=max(bal,max_bal);
					
			}
			String brackets_open="";
			String brackets_close="";
			if(max_bal==1)
				System.out.println("()");
			else {
				int j,k;
				for(j=0;j<max_bal-2;j+=2) {
					brackets_open+="((";
					brackets_close+="))";
				}
//				j--;
				while(j<max_bal) {
					brackets_open+="(";
					brackets_close+=")";
					j++;
				}
				brackets_open+=brackets_close;
				System.out.println(brackets_open);
			}
			
		}
	}

	private static int max(int a, int b) {
		// TODO Auto-generated method stub
		return a>b?a:b;
	}
}
