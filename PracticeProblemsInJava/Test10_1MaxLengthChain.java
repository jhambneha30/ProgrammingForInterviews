import java.io.*;
import java.util.*;
public class Test10_1MaxLengthChain {
	public static class Pair{
		Integer first;
		Integer second;
		
		public Pair(int f,int s)
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
			int numPairs=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			Pair[] p=new Pair[numPairs];
			for(int i=0;i<numPairs;i++)
			{
				int first=Integer.parseInt(st.nextToken());
				int sec=Integer.parseInt(st.nextToken());
				p[i]=new Pair(first,sec);
			}
			
			Arrays.sort(p, new Comparator<Pair>(){
				@Override
				public int compare(Pair p1, Pair p2) {
					return p1.second.compareTo(p2.second);
				}
			});
			Pair[] res=new Pair[numPairs];
			int maxLength=1,k=1;
			res[0]=new Pair(p[0].first,p[0].second);
			for(int j=1;j<numPairs;j++)
			{
				if(p[j].first>res[k-1].second){
					maxLength++;
					res[k]=new Pair(p[j].first,p[j].second);
					k++;
				}
					
			}
			System.out.println(maxLength);
		}
	}
}
