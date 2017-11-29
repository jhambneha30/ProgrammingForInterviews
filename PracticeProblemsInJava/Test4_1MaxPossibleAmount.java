//The opponent intends to choose the coin which leaves the user with minimum value.
//http://practice.geeksforgeeks.org/problems/max-possible-amount/0
//http://www.geeksforgeeks.org/dynamic-programming-set-31-optimal-strategy-for-a-game/
import java.util.*;
import java.io.*;
public class Test4_1MaxPossibleAmount {
	
	public static void main(String[]args) throws IOException
	{
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			int numCoins=Integer.parseInt(br.readLine());
			int arr_coins[]=new int[numCoins];
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0;j<numCoins;j++)
			{
				arr_coins[j]=Integer.parseInt(st.nextToken());
			}
			
			int max_amt=computeMyAmt(arr_coins,numCoins);
			System.out.println(max_amt);
		}
	}
	
	static int max(int a,int b)
	{
		return a>b?a:b;
	}
	
	static int min(int a,int b)
	{
		return a<b?a:b;
	}
	
	static int computeMyAmt(int arr[],int n)
	{
		int max_table[][]=new int[n][n];
		int gap,i,j=0,term1,term2,term3;
		for(gap=0;gap<n;gap++)
		{
			for(i=0,j=gap;j<n;i++,j++)
			{
				term1=((i+2)<=j) ? max_table[i+2][j]:0;
				term2=((i+1)<=(j-1)) ? max_table[i+1][j-1]:0;
				term3=(i<=(j-2)) ? max_table[i][j-2]:0;
				
				max_table[i][j]=max(arr[i]+min(term1,term2), arr[j]+min(term2,term3));
			}
		}
		
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<n;j++)
//			{
//				System.out.print(max_table[i][j] +" ");
//			}
//			System.out.println();
//		}
		return max_table[0][n-1];
	}
	
	//RECURSIVE SOLUTION (Time limit very high on large inputs=>use DP)
//	static int computeMyAmt(int arr[],int start,int end)
//	{
//		int my_amt=0;
//		if(start==end)
//			return arr[start];
//		else if(end==start+1)//only 2 elements are left, choose the greater one
//			return max(arr[start],arr[end]);
//		else
//		{
//			int include_start=arr[start]+min(computeMyAmt(arr,start+2,end),computeMyAmt(arr,start+1,end-1));
//			int include_end=arr[end]+min(computeMyAmt(arr,start+1,end-1),computeMyAmt(arr,start,end-2));
//			my_amt+=max(include_start,include_end);
//			return my_amt;
//		}
//		
//	}

}
