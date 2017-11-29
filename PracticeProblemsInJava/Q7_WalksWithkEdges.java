/*http://practice.geeksforgeeks.org/problems/possible-paths/0
 * http://www.geeksforgeeks.org/count-possible-paths-source-destination-exactly-k-edges/
 */
import java.util.*;
import java.io.*;

public class Q7_WalksWithkEdges {
	public static class Graph {
		int n;
		int e;
		LinkedList<Integer>[] adj_list;
		int[][] adj_matrix;
		Graph(int vertices, int edges)
		{
			n=vertices;
			e=edges;
			adj_list=new LinkedList[n];
			System.out.println("vertices: "+vertices+" edges: "+edges);
			for(int i=0;i<n;i++)
			{
				adj_list[i]=new LinkedList<Integer>();
			}
			adj_matrix=new int[n][n];
		}
		
		
		void addEdge(int u, int v)
		{
			System.out.println("adding at vertex:"+u+" end: "+v);
			adj_list[u].add(v);
		}
	}
	public static void main(String[]args) throws IOException {
		java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int tc;
		tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			int n=Integer.parseInt(br.readLine());
			Graph g=new Graph(n,0);
			StringTokenizer t=new StringTokenizer(br.readLine());
			for(int x=0;x<n;x++)
			{
				for(int y=0;y<n;y++)
				{
					g.adj_matrix[x][y]=Integer.parseInt(t.nextToken());
					System.out.print(g.adj_matrix[x][y]+" ");
				}
				System.out.println();
			}
			
			t=new StringTokenizer(br.readLine());
			int src=Integer.parseInt(t.nextToken());
			int dest=Integer.parseInt(t.nextToken());
			int k=Integer.parseInt(t.nextToken());
			int count=countWalks(g,src,dest,k);
			System.out.println(count);
		}
	}
	
	private static int countWalks(Graph g, int u, int dest, int k) {
		int count=0;
		if(k==0 && u==dest)return 1;
		if(k==1 && g.adj_matrix[u][dest]==1)return 1;
		if(k<=0)return 0;
		
		for(int i=0;i<g.n;i++)
		{
			if(g.adj_matrix[u][i]==0)
				count+=countWalks(g,i,dest,k-1);
		}
		
		return k;
		
		
	}
}
