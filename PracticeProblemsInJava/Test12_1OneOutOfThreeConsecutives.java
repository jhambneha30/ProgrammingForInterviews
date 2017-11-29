import java.io.*;
import java.util.*;
public class Test12_1OneOutOfThreeConsecutives {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int n=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			int[] arr=new int[n];
			for(int x=0;x<n;x++) {
				arr[x]=Integer.parseInt(st.nextToken());
			}
			int sum;
			int[] sum_table=new int[n];
			if(n==1) {
			    System.out.println(arr[0]);
			}
			else if(n==2) {
				System.out.println(Math.min(arr[0], arr[1]));
			}
			else if(n==3) {
				sum=Math.min(Math.min(arr[0], arr[1]),arr[2]);
				System.out.println(sum);
			}
			else {
				sum_table[0]=arr[0];
				sum_table[1]=arr[1];
				sum_table[2]=arr[2];
				for(int j=3;j<n;j++) {
					sum_table[j]=arr[j]+Math.min(Math.min(sum_table[j-1], sum_table[j-2]),sum_table[j-3]);
				}
				sum=Math.min(Math.min(sum_table[n-1], sum_table[n-2]),sum_table[n-3]);
				System.out.println(sum);
			}
			
		}
	}
}
