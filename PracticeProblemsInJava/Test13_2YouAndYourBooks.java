import java.io.*;
import java.util.*;
public class Test13_2YouAndYourBooks {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int n=Integer.parseInt(st.nextToken());
			int k=Integer.parseInt(st.nextToken());
			int[] bookStacks=new int[n];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				bookStacks[i]=Integer.parseInt(st.nextToken());
			}
			int j=0,sum=0,max_books=-1;
			while(j<n) {
				sum=0;
				if(bookStacks[j]<=k) {
					while(j<n && bookStacks[j]<=k) {
						sum+=bookStacks[j];
						j++;
					}
					j--;
				}
				
				if(sum>max_books) {
					max_books=sum;
				}
				j++;
			}
			System.out.println(max_books);
		}
	}
}
