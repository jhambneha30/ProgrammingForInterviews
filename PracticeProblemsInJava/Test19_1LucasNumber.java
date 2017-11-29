import java.io.*;
import java.util.*;
public class Test19_1LucasNumber {
	static int[] table=new int[101];
	
	public static void main(String[]args) throws IOException {
		Arrays.fill(table, -1);
		table[0]=2;
		table[1]=1;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int n=Integer.parseInt(br.readLine());
			if(n==0 || n==1) {
				System.out.println(table[n]);
			}
			else {
				int res=lucas(n)%1000000007;
				System.out.println(res);
			}
		}
	}

	private static int lucas(int n) {
		if(table[n]!=-1)
			return table[n];
		else {
			table[n]=(lucas(n-1)%1000000007 + lucas(n-2)%1000000007);
		}
		return table[n];
	}
}
