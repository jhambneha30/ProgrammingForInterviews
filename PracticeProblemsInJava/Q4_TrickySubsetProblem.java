import java.io.IOException;
import java.util.*;

/*
 * http://practice.geeksforgeeks.org/problems/tricky-subset-problem/0
 */
public class Q4_TrickySubsetProblem {
	public static void main(String[]args) throws IOException{
		java.io.BufferedReader br= new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			StringTokenizer st=new StringTokenizer(br.readLine());
			int numByTeacher=Integer.parseInt(st.nextToken());
			int numStudents=Integer.parseInt(st.nextToken());
			int sum=Integer.parseInt(st.nextToken());
			int[] arr=new int[numStudents+1];
			arr[0]=numByTeacher;
			st=new StringTokenizer(br.readLine());
			int sum_till_now=0;
			for(int j=1;j<numStudents+1;j++)
			{
				sum_till_now=0;
				int new_num=Integer.parseInt(st.nextToken());
				for(int x=j-1;x>=0;x--)
					sum_till_now+=arr[x];
				arr[j]=sum_till_now+new_num;
				System.out.println(arr[j]);
			}
			int len=arr.length;
			boolean res=subsetSum(arr,len,sum);
			if(res)
				System.out.println("Yes");
			else
				System.out.println("No");
		}
	}

	private static boolean subsetSum(int[] arr, int n,int sum) {
		boolean[][] ss_table=new boolean[n+1][sum+1];
		for(int i=0;i<=n;i++)
		{
			ss_table[i][0]=true;
		}
		for(int j=1;j<=sum;j++)
		{
			ss_table[0][j]=false;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=sum;j++){
				if(j-arr[i-1]>=0)
					ss_table[i][j]=ss_table[i-1][j-arr[i-1]] || ss_table[i-1][j];
				else
					ss_table[i][j]=ss_table[i-1][j];
			}
		}
		return ss_table[n][sum];
	}

}
