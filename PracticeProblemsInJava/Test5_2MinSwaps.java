/*http://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/
The graph method i smore or less same as the one implemented below. The only 
difference is that number of swaps can be found out by finding the cycle length.
TC=O(nlogn) for both the solutions.
*/
import java.io.*;
import java.util.*;

public class Test5_2MinSwaps {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			int size=Integer.parseInt(br.readLine());
			int[] arr=new int[size];
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int i=0;i<size;i++)
			{
				arr[i]=Integer.parseInt(st.nextToken());
			}
			//First make hash table to store positions
			//Use java hash table inbuilt to save space
			int[] hash=new int[1200];
			for(int i=0;i<1200;i++)
			{
			    hash[i]=-1;
			}
			int[] arr_dup=new int[size];
			for(int j=0;j<size;j++)
			{
				hash[arr[j]]=j;
				System.out.println("hash index:"+arr[j]+" value: "+j);
				arr_dup[j]=arr[j];
			}
			
			int min_swaps=0;
			Arrays.sort(arr);
			for(int x=0;x<size;x++)
			{
				System.out.println(arr[x]+" ");
			}
			
			for(int k=0;k<size;k++)
			{
				if(hash[arr[k]]!=-1 && hash[arr[k]]!=k)
				{
					min_swaps++;
					System.out.println("swaps:"+arr[k]+" & "+ arr_dup[k]);
					//update the hash table and then swap
					hash[arr_dup[k]]=hash[arr[k]];
					int temp=arr_dup[k];
					arr_dup[k]=arr[k];
					arr_dup[hash[arr[k]]]=temp;
					//The kth element has been kept at its correct position,
					//So, make the hash table's value for it=-1
					hash[arr[k]]=-1;
					
					
				}
			}
			
			System.out.println(min_swaps);
		}
		
		
	}
}
