import java.io.*;
import java.util.*;
public class Test20_1LCSOfThreeStrings {
	public static void main(String[]args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int x_len=Integer.parseInt(st.nextToken());
			int y_len=Integer.parseInt(st.nextToken());
			int z_len=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(br.readLine());
			String x=st.nextToken();
			String y=st.nextToken();
			String z=st.nextToken();
			
			int[][][] lcs_table=new int[x_len+1][y_len+1][z_len+1];
			int l=lcs(x_len,y_len,z_len,x,y,z,lcs_table);
			
			System.out.println(l);
			
			
		}
	}

	private static int lcs(int l1,int l2,int l3,String x, String y, String z, int[][][] lcs_table) {
		for(int i=0;i<=l1;i++) {
			lcs_table[i][0][0]=0;
		}
		for(int j=0;j<=l2;j++) {
			lcs_table[0][j][0]=0;
		}
		for(int k=0;k<=l3;k++) {
			lcs_table[0][0][k]=0;
		}
		for(int i=1;i<=l1;i++) {
			for(int j=1;j<=l2;j++) {
				for(int k=1;k<=l3;k++) {
					if(x.charAt(i-1)==y.charAt(j-1) && y.charAt(j-1)==z.charAt(k-1)) {
						lcs_table[i][j][k]=1+lcs_table[i-1][j-1][k-1];
					}
					else {
						lcs_table[i][j][k]=max(max(lcs_table[i-1][j][k],lcs_table[i][j-1][k]),lcs_table[i][j][k-1]);
					}
				}
				
			}
		}
		return lcs_table[l1][l2][l3];
	}

	private static int max(int a, int b) {
		
		return a>b?a:b;
	}
}
