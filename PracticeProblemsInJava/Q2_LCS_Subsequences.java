/*
 * If last character of strings are equal then they must be in lcs. 
 * If they are not equal lcs will be either constructed from upper side of matrix or left side of matrix 
 * depending upon which value is greater. If both the value is equal then lcs will be constructed from 
 * both the side. So keep constructing the lcs until you have constructed all the lcs and store them in a set.
 */
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;
public class Q2_LCS_Subsequences {
	public static void main(String[]args) throws IOException
	{
		java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int tc;
		tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			StringTokenizer sk=new StringTokenizer(br.readLine());
			String str1= sk.nextToken();
			String str2=sk.nextToken();
			System.out.println(str1+" "+str2);
			int n1,n2;
			n1=str1.length();
			n2=str2.length();
			int[][] lcs_table=new int[n1+1][n2+1];
			int lcs_size=lcs(str1,str2,n1,n2,lcs_table);
			System.out.println("Longest subsequence possible is of size: "+lcs_size );
			Set<String> result_set=findLCS(str1,str2,n1,n2,lcs_table);
			ArrayList<String> res=new ArrayList<String>(result_set);
			Collections.sort(res);
			for(String str:res)
				System.out.println(str);
			
		}
		
	}
	
	private static Set<String> findLCS(String str1, String str2, int n1, int n2, int[][] lcs_table) {
		if(n1==0 || n2==0){
			Set<String> s=new HashSet<String>();
			s.add("");
			return s;
		}
		if(str1.charAt(n1-1)==str2.charAt(n2-1))
		{
			Set<String> set=new HashSet<String>();
			Set<String> set_ret=new HashSet<String>();
			set=findLCS(str1,str2,n1-1,n2-1,lcs_table);
			//Add the new character to each string in the returned set and return
			for(String temp:set)
			{
				temp=temp+str1.charAt(n1-1);
				set_ret.add(temp);
			}
			return set_ret;
		}
		else
		{
			Set<String> set_top=new HashSet<String>();
			Set<String> set_left=new HashSet<String>();
			if(lcs_table[n1-1][n2]>=lcs_table[n1][n2-1])
			{
				set_top=findLCS(str1,str2,n1-1,n2,lcs_table);
			}
			if(lcs_table[n1][n2-1]>=lcs_table[n1-1][n2])
			{
				set_left=findLCS(str1,str2,n1,n2-1,lcs_table);
			}
			//Add the strings obtained from top and left
			for(String tmp:set_top){
				set_left.add(tmp);
			}
			return set_left;
		}
		
	}

	static int max(int a,int b) {
		return a>b?a:b;
	}
	
	static int lcs(String s1,String s2,int n1,int n2,int lcs_table[][])
	{
//		int num=0;
		for(int i=0;i<=n1;i++){
			lcs_table[i][0]=0;
		}
		for(int j=1;j<=n2;j++){
			lcs_table[0][j]=0;
		}
		for(int x=1;x<=n1;x++){
			for(int y=1;y<=n2;y++){
				if(s1.charAt(x-1)==s2.charAt(y-1)){
					lcs_table[x][y]=1+lcs_table[x-1][y-1];
				}
				else{
					lcs_table[x][y]=max(lcs_table[x-1][y],lcs_table[x][y-1]);
				}
				
			}
		}
			
			
		return lcs_table[n1][n2];
	}
}
