import java.io.*;
import java.util.*;

public class Test16_1TransitiveClosureOfGraph {
	
	public static class Graph {
		int v;
		int[][] adjMatrix;
		Graph(int vertices) {
			this.v=vertices;
			this.adjMatrix=new int[v][v];
		}
		
	}
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			int nodes=Integer.parseInt(br.readLine());
			int[][] tcMatrix=new int[nodes][nodes];
			Graph g=new Graph(nodes);
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int i=0;i<nodes;i++) {
				for(int j=0;j<nodes;j++) {
					g.adjMatrix[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<nodes;i++) {
				tcMatrix[i][i]=g.adjMatrix[i][i];
//				if(i==7)
//					System.out.println(tcMatrix[i][i]);
			}
			
			int[] visited=new int[nodes];
			for(int k=0;k<nodes;k++) {
//				Arrays.fill(visited, 0);
//				System.out.println("calling dfs for k:"+k);
				int flag=-1;
				dfs(k,tcMatrix[k],g.adjMatrix,g.v,flag);
			}
			
			for(int i=0;i<nodes;i++) {
				for(int j=0;j<nodes;j++) {
					System.out.print(tcMatrix[i][j]+" ");
				}
//				System.out.println();
			}
		System.out.println();
		}
		
	}
	
	private static void dfs(int node, int[] tc, int[][] adjMatrix,int v,int flag) {
		//We use flag here as we can't assume that a node is reachable to itself.
		//It is reachable only either if it has a self loop or is reachable back to itself via other vertices!
		//If we don't check the flag, then we'll always make the diagonal element 1
		//which means that a vertex is always reachable from itself no matter what!
		if(flag==1) {
			tc[node]=1;
		}	
		flag=1;
//		System.out.print(node + "->");
		for(int i=0;i<v;i++) {
			if(adjMatrix[node][i]==1 && node!=i && tc[i]==0) {
//				System.out.println("node:"+node+" i:"+i);
				dfs(i,tc,adjMatrix,v,flag);
			}
		}
		
	}
}
