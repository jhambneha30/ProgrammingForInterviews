import java.io.*;
import java.util.*;

public class Test13_1WordBreak_Part2 {
	static HashMap<String,Integer> list= new HashMap<String,Integer>();
	static int[][] dp_table;
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++) {
			int numDictWords=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0;j<numDictWords;j++) {
				list.put(st.nextToken(), 1);
			}
			String str=br.readLine();
//			long startTime = System.currentTimeMillis();
			int len=str.length()-1;
			dp_table=new int[len+2][len+2];
			for(int x=0;x<len+2;x++)
				Arrays.fill(dp_table[x], -1);
			int res=checkWordBreak(str,0,len);
			System.out.println(res);
//			long endTime   = System.currentTimeMillis();
//			long totalTime = endTime - startTime;
//			System.out.println(totalTime);
			
		}
	}
	private static int checkWordBreak(String str, int i, int len) {
		if(i>len)
			return 0;
		if(dp_table[i][len]!=-1) {
//			System.out.println("i:"+i+" len:"+len+"---"+dp_table[i][len]);
			return dp_table[i][len];
		}
			
		String temp=str.substring(i, len+1);
//		System.out.println("checking: "+temp);
		if(list.containsKey(temp)) {
			dp_table[i][len]=1;
			return 1;
		}	
		else{
			for(int k=i;k<len;k++) {
//				System.out.println("k:"+k+" "+ str.substring(i, k+1)+" & "+str.substring(k+1, len+1));
				if(checkWordBreak(str,i,k)==1 && checkWordBreak(str,k+1,len)==1) {
					dp_table[i][len]=1;
					return 1;
				}	
			}
		}
//		System.out.println("returning: "+temp);
		dp_table[i][len]=0;
		return 0;
	}
}
