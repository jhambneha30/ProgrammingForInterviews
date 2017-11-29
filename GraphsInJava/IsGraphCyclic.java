/*
 * 
 * For UNDIRECTED GRAPHS,
 * Method 1: Using DFS:Check if the node is visited and the parent is not same as this vertex
 * Method 2: Using disjoint sets: Keep checking the end points of the edges, picking the
 * edges one by one. If, for any two end points u and v, find(u)=find(v) i.e. they are present in
 * the same subset => cycle exists.
 * TC=O(V+E) SC=O(V)
 * 
 * http://www.geeksforgeeks.org/detect-cycle-undirected-graph/
 * ==========================================================================================
 * Idea behind method 2: Create the subsets=no. of vertices initially. pick the ends of the 
 * edge and check if they are in the same set or not. If they are in a different set, then union
 * the sets together. Otherwise, it means that there is another edge which made them unite 
 * together and so this edge must be creating a cycle in the graph.
 * TC=O(V+E) SC=O(V)
 * 
 * $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
 * 
 * FOR DIRECTED GRAPHS:
 * Method 1: Using DFS and a recursion stack
 * TC=O(V+E) SC=O(V)
 * ==========================================================================================
 * Method 2: Using three sets and doing DFS:
 * 1. With white nodes: unvisited and unexplored
 * 2. WIth gray nodes: visited but not completely explored
 * 3. With black nodes: completely explored
 * The idea is while doing a DFS if we encounter a vertex in a gray set => there is a cycle.
 * The reason is that when a vertex is in gray set, it means that it's neighbors or neighbour's 
 * neighbors or somebody in that hierarchy is still being explored and that vertex found a path
 * back to a vertex in the gray set, indicating the presence of a cycle.
 * TC=O(V+E) SC=O(V)
 */
import java.util.Iterator;
import java.util.LinkedList;

public class IsGraphCyclic {

	private static LinkedList<Integer> adjList[];
	private static int num;
	
	
	//Constructor
	IsGraphCyclic(int v)
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
	
	
	public static boolean dfs(int vertex,int visited_dfs[],int parent)
	{
		System.out.println(vertex+"->");
		visited_dfs[vertex]=1;
		
		Iterator it_queue=adjList[vertex].iterator();
		while(it_queue.hasNext())
		{
			int temp=(int) it_queue.next();
			if(visited_dfs[temp]==0)
				dfs(temp,visited_dfs,vertex);
			else if(temp!=parent)
				return true;
		}
		return false;
		
	}
	
	public boolean isCyclic()
	{
		boolean r=false;
		int visited[] = new int[num];
//        for (int i = 0; i < num; i++)
//            visited[i] = 0;
        for(int u=0;u<num;u++)
        {
        	if(visited[u]==0)
        		r=dfs(u,visited,-1);
        }
		
		return r;
	}
	
	public static void main(String[]args)
	{
		int n=4;
		IsGraphCyclic g = new IsGraphCyclic(n);
		g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);
        boolean res=g.isCyclic();
        if(res)
        	System.out.println("Cycle exists!");
        else
        	System.out.println("Cycle doesn't exist!");
        
        IsGraphCyclic g2 = new IsGraphCyclic(3);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        if (g2.isCyclic())
        	System.out.println("Cycle exists!");
        else
        	System.out.println("Cycle doesn't exist!");
	}
}
