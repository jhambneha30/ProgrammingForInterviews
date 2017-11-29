import java.util.*;
import java.io.*;
public class Test17_2SubstringRepetition {
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int len=Integer.parseInt(br.readLine());
			String str=br.readLine();
			int k=Integer.parseInt(br.readLine());
			int res=0;
			if(len%k!=0) {
				System.out.println(res);
			}
			else {
				HashMap<String,Integer> hm=new HashMap<String,Integer>();
				for(int i=0;i<len;i+=k) {
					String sub=str.substring(i, i+k);
					if(hm.containsKey(sub)) {
						int num=hm.get(sub);
						num++;
						hm.put(sub, num);
					}
					else {
						hm.put(sub, 1);
					}
						
				}
				
				if(hm.size()==1)
					System.out.println(1);
				else if(hm.size()==2 && hm.containsValue(1)){
					System.out.println(1);
				}
				else {
					System.out.println(0);
				}
			}
		}
	}
}
