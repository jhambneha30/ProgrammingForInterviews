import java.io.*;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Test8_2SonamBewafa_Ranges {
	public static class Pair{
		long first;
		long second;
		
		public Pair(long f,long s)
		{
			first=f;
			second=s;
		}
		
	}
	
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			StringTokenizer st=new StringTokenizer(br.readLine());
			int numGrps=Integer.parseInt(st.nextToken());
			int numQueries=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(br.readLine());
			Pair[] marks_limits=new Pair[numGrps];
			for(int i=0;i<numGrps;i++)
			{
				long first=Long.parseLong(st.nextToken());
				long sec=Long.parseLong(st.nextToken());
				marks_limits[i]=new Pair(first,sec);
			}
			st=new StringTokenizer(br.readLine());
			long[] queries=new long[numQueries];
			for(int q=0;q<numQueries;q++)
			{
				queries[q]=Long.parseLong(st.nextToken());
			}
			
			//First create newRanks array containing the last rank of the interval
			long[] rank_upperBounds=new long[numGrps];
			for(int k=0;k<numGrps;k++)
			{
				if(k==0)
					rank_upperBounds[k]=marks_limits[k].second;
				else
				{
					rank_upperBounds[k]=rank_upperBounds[k-1]+(marks_limits[k].second-marks_limits[k].first+1);
				}
				System.out.print(rank_upperBounds[k]+" ");
			}
			int start=0,end=numGrps-1;
			//Binary search on intervals
			for(int q=0;q<numQueries;q++)
			{
				long query=queries[q];
				int index=binarySearchOnIntervals(rank_upperBounds,query,start,end);
				System.out.println("-----"+index+"--------");
				if(index>=0 && index<numGrps){
					long score=marks_limits[index].second-(rank_upperBounds[index]-query);
					System.out.print(score+" ");
				}
				else
				{
					long score=marks_limits[numGrps-1].second+(query-rank_upperBounds[numGrps-1]);
					System.out.print(score+" ");
				}
			}
			System.out.println();
					
			
		}
		
		
		
		
	}

	private static int binarySearchOnIntervals(long[] arr, long item,int start,int end) {
//		System.out.println("start:"+start+" end:"+end);
		int res=-1;
		if(start>=end && item<=arr[start])
		{
			return start;
		}
		
		if(start==end && item>=arr[end])
		{
			return end+1;
		}
			
		if(start<end)
		{
			int mid=(start+end)/2;
			if(item==arr[mid])
				return mid;
			if(item<arr[mid])
			{
				res=binarySearchOnIntervals(arr,item,start,mid-1);
			}
			if(item>arr[mid])
			{
				res=binarySearchOnIntervals(arr,item,mid+1,end);
			}
		}
		return res;
	}
}
