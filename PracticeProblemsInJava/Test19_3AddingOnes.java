import java.io.*;
import java.lang.*;
import java.util.*;

public class Test19_3AddingOnes {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int n=Integer.parseInt(st.nextToken());
			int k=Integer.parseInt(st.nextToken());
			int[] arr=new int[n];
			Arrays.fill(arr, 0);
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<k;i++) {
				int index=Integer.parseInt(st.nextToken());
				for(int j=index-1;j<n;j++) {
					arr[j]++;
				}
			}
			
			for(int l=0;l<n;l++) {
				System.out.println(arr[l]+" ");
			}
			System.out.println();
		}
	}
}
