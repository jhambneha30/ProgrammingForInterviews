import java.util.Iterator;
import java.util.LinkedList;

public class Graph {
	
	private static LinkedList<Integer> adjList[];
	private static int num;
	
	
	//Constructor
	Graph(int v)
	{
		num=v;
		adjList =new LinkedList[v];
		//Initialize all the lists in this array of Linked lists.
		for(int i=0;i<num;i++)
		{
			adjList[i]= new LinkedList<Integer>();
		}
	}
	
	void addEdge(int src, int dest)
	{
		adjList[src].add(dest);
	}
	
	public static void dfs(int vertex,int visited_dfs[])
	{
		System.out.print(vertex+"->");
		visited_dfs[vertex]=1;
		
		Iterator it_queue=adjList[vertex].iterator();
		while(it_queue.hasNext())
		{
			int temp=(int) it_queue.next();
			if(visited_dfs[temp]==0)
				dfs(temp,visited_dfs);
		}
		
	}
	
	public static void bfs(int vertex,int n)
	{
		int[] visited=new int[n];
		
		LinkedList<Integer> q = new LinkedList();
		int u=vertex;
		visited[u]=1;
		q.add(u);
		while(q.size()!=0)
		{
			u=q.poll();
			System.out.print(u+"->");
			Iterator it_queue=adjList[u].iterator();
			while(it_queue.hasNext())
			{
				int temp=(int) it_queue.next();
				if(visited[temp]==0)
				{
					visited[temp]=1;
					q.add(temp);
				}
			}
		
		}
		System.out.println("\n");
		
	}
	
	public static void main(String args[])
	{
		int n=4;
		Graph g = new Graph(n);
		g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        System.out.println("BFS--------------");
        bfs(2,n);
        int visited_dfs[]=new int[n];
        System.out.println("DFS--------------");
        dfs(2,visited_dfs);
	}
}
