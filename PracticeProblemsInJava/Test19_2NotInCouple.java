import java.io.*;
import java.util.*;

public class Test19_2NotInCouple {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int n=Integer.parseInt(br.readLine());
			int[] hash=new int[501];
			Arrays.fill(hash, 0);
			int[] arr=new int[n];
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				arr[i]=Integer.parseInt(st.nextToken());
				hash[arr[i]]++;
			}
			for(int j=0;j<n;j++) {
				if(hash[arr[j]]%2!=0) {
				    System.out.println(arr[j]);
				    break;
				}
					
			}
		}
	}
}
