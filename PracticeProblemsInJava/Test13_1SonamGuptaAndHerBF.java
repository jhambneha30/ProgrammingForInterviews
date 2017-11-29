import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.lang.*;

public class Test13_1SonamGuptaAndHerBF {
	
	public static void main(String[]args) throws IOException
	{
		
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		
		for(int t=0;t<tc;t++) {
			String str=br.readLine();
			int n=str.length();
			int flag=1;
			
			int dist=0,curr=0;
			int[] hash=new int[256];
			Arrays.fill(hash, -1);
			if(str.charAt(0)!='a') {
				dist=-1;
			}
			else
			{
				for(int i=0;i<n;i++) {
					if(str.charAt(i)!='a' && i>hash[str.charAt(i)])
						hash[str.charAt(i)]=i;
//					System.out.println("i:"+str.charAt(i)+"hash:"+hash[str.charAt(i)]);
				}
				for(int j='b';j<='z';j++) {
//					System.out.println(j+" "+hash[j]+" "+hash[j-1]);
					if(hash[j]>hash[j-1]) {
						curr=hash[j]+1;
						if(curr>dist)
							dist=curr;
					}
					else
					{
						break;
					}	
				}
			}
			
			System.out.println(dist==0?-1:dist);


		}
	}
}
