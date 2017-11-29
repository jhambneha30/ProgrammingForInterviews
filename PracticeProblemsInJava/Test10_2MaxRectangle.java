import java.io.*;
import java.util.*;

public class Test10_2MaxRectangle {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			StringTokenizer st=new StringTokenizer(br.readLine());
			int n=Integer.parseInt(st.nextToken());
			int m=Integer.parseInt(st.nextToken());
			int[][] matrix=new int[n][m];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					matrix[i][j]=Integer.parseInt(st.nextToken());
				}
			}
//			System.out.println("n:"+n+" m:"+m+" a[n-1][m-1]"+matrix[n-1][m-1]);
			int max=maxArea(matrix,n,m);
			System.out.println(max);
		}
	}
	
	public static int maxArea(int a[][],int rows,int cols){
		int[] dp_table=new int[cols];
		Arrays.fill(dp_table, 0);
		int ultimate_max=-1,max_till_now=-1;
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<cols;j++)
			{
				if(a[i][j]==0)
					dp_table[j]=0;
				else
					dp_table[j]+=a[i][j];
				System.out.print(dp_table[j]);
			}
			
			max_till_now=findMaxRectAreaInHistogram(dp_table,cols);
			System.out.println("\ni:"+i+" max_till_now:"+max_till_now);
			if(max_till_now>ultimate_max)
				ultimate_max=max_till_now;
		}
        return ultimate_max;
    }

	private static int findMaxRectAreaInHistogram(int[] a,int n) {
		Stack<Integer> st=new Stack();
		int curr_area,max=-1;
		int i=0;
		while(i<n)
		{
			if(st.isEmpty() || a[i]>=a[st.peek()])
			{
				st.push(i);
				i++;
			}
			else
			{
				while(!st.isEmpty() && a[i]<a[st.peek()])
				{
					int popped_index=st.pop();
					curr_area=a[popped_index] * (st.isEmpty()?i:(i-st.peek()-1));
					if(curr_area>max)
						max=curr_area;
				}
			}
		}
		while(!st.isEmpty())
		{
			int popped_ht=a[st.pop()];
			curr_area= popped_ht * (st.isEmpty()?i:(i-st.peek()-1));
			if(curr_area>max)
				max=curr_area;
		}
		System.out.println("in hist func 1:"+max);
		return max;
	}
}
