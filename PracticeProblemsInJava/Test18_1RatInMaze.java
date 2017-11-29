import java.io.*;
import java.util.*;
import java.lang.*;
public class Test18_1RatInMaze {
	static ArrayList<String> list=new ArrayList<String>();
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int n=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			int[][] matrix;
			matrix=new int[n][n];
			for(int i=0;i<n;i++) {
				for(int j=0;j<n;j++) {
					matrix[i][j]=Integer.parseInt(st.nextToken());
				}
			}

			if(matrix[0][0]==0 || matrix[n-1][n-1]==0)
				break;
			list.clear();
			String str="";
			directions(0,0,str,n,'N',matrix);

			Collections.sort(list);

			Iterator it =list.iterator();
			while(it.hasNext()) {
				System.out.println(it.next());
			}



		}		
	}

	private static boolean isSafe(int i,int j,int n,int[][] matrix) {
		return ((i>=0 && i<n) && (j>=0 && j<n) && matrix[i][j]==1)?true:false;
	}
	private static void directions(int i, int j, String str,int n,char direction,int[][] matrix) {
		if(i==n-1 && j==n-1) {
			str=str+direction;
//			System.out.println(str);
			list.add(str);
			return; //If we dont return, then it goes down and since (n-1,n-1) is safe, it calls the function again!
		}

		if(isSafe(i,j,n,matrix)) {
			
			matrix[i][j]=2;
			if(direction!='N')
				str=str+direction;
			directions(i+1,j,str,n,'D',matrix);

			directions(i-1,j,str,n,'U',matrix);
			directions(i,j+1,str,n,'R',matrix);

			directions(i,j-1,str,n,'L',matrix);
			matrix[i][j]=1;
		}

	}
}
