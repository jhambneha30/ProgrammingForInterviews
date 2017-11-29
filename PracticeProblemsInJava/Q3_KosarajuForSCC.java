/*
 * http://practice.geeksforgeeks.org/problems/strongly-connected-component-tarjanss-algo/0
 * http://www.geeksforgeeks.org/strongly-connected-components/
 */
import java.io.IOException;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;
import java.util.StringTokenizer;

public class Q3_KosarajuForSCC {
	public static class Graph{
		int n,e;
		LinkedList<Integer>[] adjList;
		Graph(int vertices, int edges)
		{
			n=vertices;
			e=edges;
			adjList=new LinkedList[n];
			for(int i=0;i<n;i++)
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
		java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++){
			StringTokenizer st=new StringTokenizer(br.readLine());
			int numVertices=Integer.parseInt(st.nextToken());
			int numEdges=Integer.parseInt(st.nextToken());
			Graph g=new Graph(numVertices,numEdges);
			st=new StringTokenizer(br.readLine());
			for(int y=0;y<numEdges;y++)
			{
				int start=Integer.parseInt(st.nextToken());
				int end=Integer.parseInt(st.nextToken());
				g.addEdge(start, end);
			}
			printSCCUsingKosaraju(g);
			System.out.println();
		}

		
	}
	private static void printSCCUsingKosaraju(Graph g) {
		//Step1: Build stack
		Stack stack=new Stack();
		boolean[] visited=new boolean[g.n];
		for(int x=0;x<g.n;x++)
			visited[x]=false;
		for(int i=0;i<g.n;i++)
		{
			if(visited[i]==false)
				fillStack(g,i,visited,stack);
		}
		
		//Step 2: Reverse graph and reset visited array
		Graph gt=transposeGraph(g);
		for(int x=0;x<gt.n;x++)
			visited[x]=false;
		//Step 3: Call DFS to print SCCs
		for(int k=0;k<gt.n;k++)
		{
//			System.out.println(k+" "+visited[k]);
			System.out.println("==========New Component===========");
			if(visited[k]==false){
				dfs(g,k,visited);
				System.out.println();
			}
				
		}
		
		
	}
	
	private static void dfs(Graph g_new, int vertex, boolean[] visited) {
		visited[vertex]=true;
		System.out.print(vertex+" ");
		Iterator<Integer> adj_it=g_new.adjList[vertex].iterator();
		while(adj_it.hasNext())
		{
			int adj_node=adj_it.next();
			if(visited[adj_node]==false)
				dfs(g_new,adj_node,visited);
		}
		
	}
	private static Graph transposeGraph(Graph g) {
		Graph gt=new Graph(g.n,g.e);
		for(int j=0;j<g.n;j++)
		{
			Iterator list_it=g.adjList[j].iterator();
			while(list_it.hasNext())
			{
				gt.adjList[(int) list_it.next()].add(j);
			}
		}
		return gt;
	}
	
	private static void fillStack(Graph g,int node, boolean[] visited, Stack stack) {
		visited[node]=true;
		Iterator<Integer> adj_it=g.adjList[node].iterator();
		while(adj_it.hasNext())
		{
			int adj_node=adj_it.next();
			if(visited[adj_node]==false)
				fillStack(g,adj_node,visited,stack);
		}
		stack.push(new Integer(node));
	
	}

}
