import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test1_1LongestPrefixSuffix {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			int curr_lps=0,i=1;
			String str=br.readLine();
			int n=str.length();
			int[] lps=new int[n];
			lps[0]=0;
			while(i<n) {
				if(str.charAt(i)==str.charAt(curr_lps)) {
					curr_lps++;
					lps[i]=curr_lps;
//					System.out.println("i:"+i+" lps[i]:"+lps[i]+"curr_lps:"+curr_lps);
					i++;
					
				}
				else {
					if(curr_lps!=0) {
						curr_lps=lps[curr_lps-1];
					}
					else {
						lps[i]=0;
//						System.out.println("i--:"+i+" lps[i]--:"+lps[i]);
						i++;
					}
				}
			}
			System.out.println(lps[n-1]);
		}
	}
}
