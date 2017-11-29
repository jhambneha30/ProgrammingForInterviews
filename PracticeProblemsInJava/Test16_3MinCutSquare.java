import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test16_3MinCutSquare {
	static int[][] table;
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int m=Integer.parseInt(st.nextToken());
			int n=Integer.parseInt(st.nextToken());
			table=new int[m+1][n+1];
			for(int i=0;i<=m;i++) {
				Arrays.fill(table[i], 0);
			}
			int minNum=minSquares(m,n);
			System.out.println(minNum);
		}
	}

	private static int minSquares(int m, int n) {
		if(m==n)
			return 1;
		if(table[m][n]!=0)
			return table[m][n];
		
		//Vertical cut: find min cut
		int minv=9999999;
		int curr;
		for(int i=1;i<=n/2;i++) {
			curr=minSquares(m,i)+minSquares(m,n-i);
			if(curr<minv)
				minv=curr;
		}
//		System.out.println("vertical min: "+minv);
		//Vertical cut: find min cut
		int minh=99999999;
		for(int i=1;i<=m/2;i++) {
			curr=minSquares(i,n)+minSquares(m-i,n);
			if(curr<minh)
				minh=curr;
		}
//		System.out.println("hor min: "+minh);
		table[m][n]=minv<minh?minv:minh;
		return table[m][n];
	}
}
