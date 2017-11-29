import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
public class Test3_2DetectCycleInDirectedGraph {
	public static class Graph {
		int v,e;
		LinkedList<Integer>[] adj_list;
		Graph(int vertices, int edges)
		{
			v=vertices;
			e=edges;
			adj_list=new LinkedList[vertices];
			for(int i=0;i<vertices;i++)
			{
				adj_list[i]=new LinkedList();
			}
		}
		
		void addEdge(int u,int v)
		{
			adj_list[u].add(v);
		}
	}
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			StringTokenizer st=new StringTokenizer(br.readLine());
			int vertices=Integer.parseInt(st.nextToken());
			int edges=Integer.parseInt(st.nextToken());
			Graph g=new Graph(vertices,edges);
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<edges;j++)
			{
				int u=Integer.parseInt(st.nextToken());
				int v=Integer.parseInt(st.nextToken());
				g.addEdge(u, v);
			}
			for(int j=0;j<vertices;j++)
			{
				System.out.print(j+":::");
				Iterator<Integer> adj_it=g.adj_list[j].iterator();
				 while(adj_it.hasNext())
				 {
					 int t=adj_it.next();
					 System.out.print(t+"->");
				 }
				 System.out.println();
			}
			boolean[] visited=new boolean[vertices];
			boolean[] explored=new boolean[vertices];
			
			boolean res=hasCycle(vertices,g.adj_list,visited,explored);
			if(res==true)
				System.out.println("Cycle exists");
			else
				System.out.println("Cycle doesn't exist");
		}
		
	}
	
	 public static boolean hasCycle(int v,LinkedList<Integer>[] alist,boolean[] visited,boolean[] explored) 
	 {
		 for(int i=0;i<v;i++)
         {
             visited[i]=false;
             explored[i]=false;
         }
         boolean res=false;
         for(int k=0;k<v;k++)
         {
             if(!visited[k] && dfs_detectCycle(k,alist,visited,explored))
             {
                 res= true;
//                 System.out.println("k:"+k);
                 break;
             }
                
         }
         return res;
	 }
	 
	 public static boolean dfs_detectCycle(int node,LinkedList<Integer>[] alist,boolean[] visited,boolean[] recursionStack) 
	 {
		 
		 visited[node]=true;
//		 System.out.println("adding to stack:"+node);
		 recursionStack[node]=true;
		 Iterator<Integer> adj_it=alist[node].iterator();
		 while(adj_it.hasNext())
		 {
			 int temp=adj_it.next();
//			 System.out.println("v:"+v+" temp:"+temp+" visited[temp]:"+visited[temp]+" parent"+parent);
			
			 if(!visited[temp] && dfs_detectCycle(temp,alist,visited,recursionStack))
			 {
				 return true;
			 }
			 else if(recursionStack[temp])
			 {
				 System.out.println("node:"+node+" adj:"+temp);
				 return true;
			 }
				
			 
		 }
//		 System.out.println("Removing from stack:"+node);
		 recursionStack[node]=false;
		 return false;
	 }
}
