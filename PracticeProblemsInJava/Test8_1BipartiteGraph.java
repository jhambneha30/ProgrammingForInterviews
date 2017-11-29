import java.io.*;
import java.util.*;
public class Test8_1BipartiteGraph {
	public static class Graph{
		int v,e;
		int matrix[][];
		Graph(int vertices,int edges)
		{
			v=vertices;
			e=edges;
			matrix=new int[v][v];
		}
	}
	
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			int vertices=Integer.parseInt(br.readLine());
			Graph g=new Graph(vertices,0);
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0;j<vertices;j++)
			{
				for(int k=0;k<vertices;k++)
				{
					g.matrix[j][k]=Integer.parseInt(st.nextToken());
				}
			}
			for(int j=0;j<vertices;j++)
			{
				for(int k=0;k<vertices;k++)
				{
					System.out.print(g.matrix[j][k]+ " "); 
				}
				System.out.println();
			}
			
			boolean result=isBipartite(g);
			if(result)
				System.out.println("Graph is bipartire");
			else
				System.out.println("Graph is not bipartire");
		}
	}
	
	private static boolean isBipartite(Graph g)
	{
		Queue<Integer> q=new LinkedList();
		int[] colors=new int[g.v];
		Arrays.fill(colors, -1);
		
		//-------------------
		int[] visited=new int[g.v];
		Arrays.fill(visited, -1);
		//-----------------
		q.add(0);
		visited[0]=1;
		for(int v=0;v<g.v;v++)
		{
			if(visited[v]!=1)
			{
				q.add(v);
				colors[0]=0;
				visited[0]=1;
				boolean res=isBipartiteUtil(g.matrix,g.v,q,colors,visited);
				if(!res){
					return false;
				}
					
			}
				
		}
		return true;
		
	}

	private static boolean isBipartiteUtil(int[][] matrix, int v,Queue<Integer> q,int colors[],int visited[]) {
		while(!q.isEmpty())
		{
			int node=q.remove();
//			System.out.println("node removed is:"+node);
			if(matrix[node][node]==1)
				return false;
			for(int i=0;i<v;i++)
			{
				if(matrix[node][i]==1 && colors[i]==-1)
				{
					q.add(i);
//					System.out.println("adding to queue:"+i);
					colors[i]=1-colors[node];
					visited[i]=1;
//					System.out.println("colors[i]:"+colors[i]);
				}
				
				else if(matrix[node][i]==1 && colors[i]==colors[node])
					return false;
				
			}
		}
		
		return true;
	}
}
