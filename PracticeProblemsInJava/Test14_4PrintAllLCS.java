import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Test14_4PrintAllLCS {
	static ArrayList<String> list=new ArrayList<String>();
	static int[][] table;
	static int l1;
	static int l2;
	static String str1;
	static String str2;
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			str1=st.nextToken();
			str2=st.nextToken();
//			System.out.println(str1+" "+str2);
			l1=str1.length();
			l2=str2.length();
			table=new int[l1+1][l2+1];
			for(int i=0;i<l1+1;i++) {
				table[i][0]=0;
			}
			for(int j=1;j<l2+1;j++) {
				table[0][j]=0;
			}
			for(int i=1;i<l1+1;i++) {
				for(int j=1;j<=l2;j++) {
					if(str1.charAt(i-1)==str2.charAt(j-1))
						table[i][j]=1+table[i-1][j-1];
					else
						table[i][j]=max(table[i-1][j],table[i][j-1]);
				}
			}
//			System.out.println("LCS length is: "+table[l1][l2]);
			//Now, back track the matrix to find the LCS patterns
			String res="";
			int currLcs=0;
			storeLCSPatterns(l1,l2,res,currLcs);
			
			Set<String> hs = new HashSet<>();
			hs.addAll(list);
			list.clear();
			list.addAll(hs);
			Collections.sort(list);
//			System.out.println("Final lsit len: "+list.size());
			Iterator list_it=list.iterator();
			while(list_it.hasNext()) {
				System.out.print(list_it.next()+" ");
			}
			list.clear();
			System.out.println();
		}
	}
	
	private static void storeLCSPatterns(int m, int n,String str,int currlcs) {
		if(table[l1][l2]==currlcs) {
//			String s=str+'\0';
//			System.out.println(str);
			list.add(str);
		}
		else {
			if(str1.charAt(m-1)==str2.charAt(n-1)) {
				str=str1.charAt(m-1)+str;
				currlcs++;
//				System.out.println(currlcs);
				storeLCSPatterns(m-1,n-1,str,currlcs);
			}
			else {
				if(table[m][n]==table[m-1][n]) {
					storeLCSPatterns(m-1,n,str,currlcs);
				}
				if(table[m][n]==table[m][n-1]) {
					storeLCSPatterns(m,n-1,str,currlcs);
				}
			}
				
		}
			
		
	}
	private static int max(int a,int b) {
		return a>b?a:b;
	}
}
