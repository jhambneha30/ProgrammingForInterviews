import java.io.*;
import java.lang.*;
import java.util.*;
public class Test13_1MaximumCollatzSequence {
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int num=Integer.parseInt(br.readLine());
			int curr_len,max=-1;
			for(int i=1;i<=num;i++) {
				curr_len=findCollatSequenceLength(i);
//				System.out.println("i:"+i+" curr_len:"+curr_len);
				if(curr_len>max)
					max=curr_len;
				
			}
			
			System.out.println(max);
		}
	}

	private static int findCollatSequenceLength(int n) {
		int count= 1;
		while(n!=1) {
			if(n%2==0 && n/2>=1) {
				count++;
				n=n/2;
			}
			else if(n%2!=0 && 3*n+1>=1){
				count++;
				n=3*n+1;
			}
//			System.out.print(n+"->");
		}
//		System.out.println();
		return count;
	}
}
