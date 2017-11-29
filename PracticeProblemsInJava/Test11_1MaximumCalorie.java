import java.io.*;
import java.util.*;
class Test11_1MaximumCalorie {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int n=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			int[] arr=new int[n];
			for(int i=0;i<n;i++) {
				arr[i]=Integer.parseInt(st.nextToken());
			}
			
			int[] table=new int[n];
			table[0]=arr[0];
			table[1]=arr[1]+table[0];
			table[2]=Math.max(Math.max(arr[0]+arr[1], arr[1]+arr[2]), arr[0]+arr[2]);
			for(int j=3;j<n;j++) {
				table[j]=Math.max(Math.max(arr[j]+table[j-2], arr[j]+arr[j-1]+table[j-3]),table[j-1]);
			}
			System.out.println(table[n-1]);
		}
	}
	
	
}
