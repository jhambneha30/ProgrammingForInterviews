import java.util.StringTokenizer;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Stack;

import javax.swing.text.html.HTMLDocument.Iterator;

/*
 * http://practice.geeksforgeeks.org/problems/topological-sort/1
 */
public class Q1_TopologicalSort {
	
	public static class Graph {
		int n;
		int e;
		LinkedList<Integer>[] adj_list;
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
		}
		
		
		void addEdge(int u, int v)
		{
			System.out.println("adding at vertex:"+u+" end: "+v);
			adj_list[u].add(v);
		}
	}
	public static void main(String[]args) throws IOException
	{
		java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int tc;
		tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			int numEdges, numVertices,start,end;
			StringTokenizer t=new StringTokenizer(br.readLine());
			numEdges=Integer.parseInt(t.nextToken());
			numVertices=Integer.parseInt(t.nextToken());
			Graph g=new Graph(numVertices,numEdges);
			t=new StringTokenizer(br.readLine());
			for(int j=0;j<numEdges;j++)
			{
				start=Integer.parseInt(t.nextToken());
				end=Integer.parseInt(t.nextToken());
				g.addEdge(start, end);
			}
			topologicalSort(g);
			
		}
	}
	
	static int topologicalSort(Graph g)
	{
		Stack st=new Stack();
		System.out.println("in topo:"+g.n);
		boolean[] visited=new boolean[g.n];
		for (int i = 0; i < g.n; i++)
            visited[i] = false;
		for(int i=0;i<g.n;i++)
		{
			if(visited[i]==false)
				dfs(g,i,visited,st);
		}
		for(int i=0;i<g.n;i++)
		{
			System.out.println(visited[i]);
		}
		while(!st.isEmpty())
		{
			System.out.println(st.pop());
		}
		return 0;
	}
	
	static void dfs(Graph g,int node,boolean visited[],Stack s)
	{
		visited[node]=true;
		Integer adj_node;
		java.util.Iterator<Integer> adjList_it=g.adj_list[node].iterator();
		while(adjList_it.hasNext())
		{
			adj_node=adjList_it.next();
			if(visited[adj_node]==false)
				dfs(g,adj_node,visited,s);
			
		}
		s.push(new Integer(node));
	}

}
