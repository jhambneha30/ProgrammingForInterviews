/*http://www.geeksforgeeks.org/maximum-profit-by-buying-and-selling-a-share-at-most-k-times/
 * See Tushar Roy's video
 */
import java.io.*;
import java.lang.*;
import java.util.*;

public class Test12_3MaximumProfit {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int k=Integer.parseInt(br.readLine());
			int n=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			int[] arr=new int[n];
			for(int x=0;x<n;x++) {
				arr[x]=Integer.parseInt(st.nextToken());
			}
			//Let i=num of transactions remaining, j=day number we are currently at
			//Let m=days before ith day
			
			int[][] stockTable=new int[k+1][n];
			for(int i=0;i<k+1;i++) {
				stockTable[i][0]=0;
			}
			for(int j=0;j<n;j++) {
				stockTable[0][j]=0;
			}
			for(int i=1;i<k+1;i++) {
				for(int j=1;j<n;j++) {
					//Find the max profit possible if we sell the stock on ith day
					int curr_max=-1;
					for(int m=0;m<j;m++) {
						if(arr[j]-arr[m]+stockTable[i-1][m]>curr_max) {
							curr_max=arr[j]-arr[m]+stockTable[i-1][m];
						}
					}
					stockTable[i][j]=Math.max(stockTable[i][j-1], curr_max);
				}
			}
			for(int i=0;i<k+1;i++) {
				for(int j=0;j<n;j++) {
					System.out.print(stockTable[i][j]+" ");
				}
				System.out.println();
			}
			
			
			System.out.println(stockTable[k][n-1]);
		}
	}
}
