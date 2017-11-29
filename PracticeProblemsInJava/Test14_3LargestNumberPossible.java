import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Test14_3LargestNumberPossible {
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int digits=Integer.parseInt(st.nextToken());
			int sum=Integer.parseInt(st.nextToken());
			int possible_sum=9*digits;
			if(sum>possible_sum || sum<=0)
				System.out.println(-1);
			else {
				int num_nines=sum/9;
				int remaining=sum-(9*num_nines);
				String str="";
				
				while(num_nines>0) {
					str+='9';
					num_nines--;
				}
				str+=remaining;
				int left_digits=digits-str.length();
//				System.out.println("left digits:"+left_digits);
				while(left_digits>0) {
					str+='0';
					left_digits--;
				}
				
				System.out.println(str);
				
			}
		}
	}
}
