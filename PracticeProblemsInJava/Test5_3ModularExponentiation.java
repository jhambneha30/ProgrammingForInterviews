import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Test5_3ModularExponentiation {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			StringTokenizer st=new StringTokenizer(br.readLine());
			long A=Integer.parseInt(st.nextToken());
			long B=Integer.parseInt(st.nextToken());
			long C=Integer.parseInt(st.nextToken());
			long power_result=(long)Math.pow(A, B/2);
			long mod_res=((long)power_result)%C;
			long final_res=(mod_res*mod_res)%C;
			System.out.println(final_res);
		}
	}
}
