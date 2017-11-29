import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Test14_2FascinatingNumber {
	static int[] hash=new int[10];
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int num=Integer.parseInt(br.readLine());
//			int[] hash=new int[10];
			Arrays.fill(hash, 0);
			if(num/100<1)
				System.out.println("Number should be atleast three digits");
			else {
				int m2=num*2;
				int m3=num*3;
				fillHash(num);
				fillHash(m2);
				fillHash(m3);
				int i=1;
				for(i=1;i<=9;i++) {
					if(hash[i]!=1)
					{
						System.out.println("Not Fascinating");
						break;
					}
				}
				if(i==10) {
					System.out.println("Fascinating");
				}
			}
			
		}
	}
	private static void fillHash(int n) {
		while(n>0) {
			int rem=n%10;
			hash[rem]++;
			n=n/10;
		}
	}
}
