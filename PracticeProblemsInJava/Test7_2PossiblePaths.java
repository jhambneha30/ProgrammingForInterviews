import java.util.*;
import java.io.*;
public class Test7_2PossiblePaths {
	public static class Graph {
		int v,e;
		LinkedList[] adjList;
		int[][] matrix;
		Graph(int vertices, int edges)
		{
			v=vertices;
			e=edges;
			adjList=new LinkedList[vertices];
			matrix=new int[v][v];
			for(int i=0;i<v;i++)
			{
				adjList[i]=new LinkedList();
			}
					
		}
		
		void addEdge(int u,int v)
		{
			adjList[u].add(v);
		}
		
		
	}
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			int vertices=Integer.parseInt(br.readLine());
			Graph g=new Graph(vertices,0);
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					g.matrix[i][j]=Integer.parseInt(st.nextToken());
				}
			}
			st=new StringTokenizer(br.readLine());
			int u=Integer.parseInt(st.nextToken());
			int v=Integer.parseInt(st.nextToken());
			int k=Integer.parseInt(st.nextToken());
			
			for(int i=0;i<vertices;i++)
			{
				for(int j=0;j<vertices;j++)
				{
					System.out.print(g.matrix[i][j]+" ");
				}
				System.out.println();
			}
			//Below is the naive approach using BFS kind of solution
			int possible_paths=findPath(u,v,k,g);
			System.out.println(possible_paths);
			
			int possible_paths_dp=findPaths_DP(u,v,k,g);
			System.out.println(possible_paths_dp);
		}
		
	}
private static int findPaths_DP(int u, int v, int k, Graph g) {
	//The table_3d contains the count of paths from i to j using e edges.
	//This solution is similar to Floyd Warshall
		int[][][] table_3d=new int[g.v][g.v][k+1];
		
		for(int e=0;e<k+1;e++)
		{
			for(int i=0;i<g.v;i++)
			{
				for(int j=0;j<g.v;j++)
				{
//					System.out.println("i:"+i+"j:"+j+"e:"+e);
					table_3d[i][j][e]=0;
					if(e==0 && i==j)
						table_3d[i][j][e]=1;
					if(e==1 && g.matrix[i][j]==1)
						table_3d[i][j][e]=1;
					
					if(e>1)
					{
						for(int adj=0;adj<g.v;adj++)
						{
							if(g.matrix[i][adj]==1)
								table_3d[i][j][e]+=table_3d[adj][j][e-1];
						}
					}
				}
			}
		}
		return table_3d[u][v][k];
	}


private static int findPath(int u, int v, int k, Graph g) {
		int p=0;
		if(k<=0)
			return 0;
//		if(k>0 && u==v && g.matrix[u][v]==1)
//			return 1;
		if(k==0 && u==v)
			return 1;
		if(k==1 && g.matrix[u][v]==1)
			return 1;
		
		for(int i=0;i<g.v;i++)
		{
			if(g.matrix[u][i]==1)
			{
				p+=findPath(i,v,k-1,g);
			}
						
		}
		return p;
	}
}
