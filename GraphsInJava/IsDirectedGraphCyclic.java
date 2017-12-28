import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;


public class IsDirectedGraphCyclic {
	private static LinkedList<Integer> adjList[];
	private static int num;
	
	
	//Constructor
	IsDirectedGraphCyclic(int v)
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
	
	public static void main(String[]args){
		int n=5;
//		int u=0;
		IsDirectedGraphCyclic g = new IsDirectedGraphCyclic(n);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
//		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);
		g.addEdge(1, 4);
		boolean r=false;
		int visited[] = new int[num];
		int st[] = new int[num];
        for(int u=0;u<num;u++)
        {
        	if(visited[u]==0)
        		r=checkCycle(u,visited, st);
        	if(r==true)
        		break;
        			
        }
        if(r==true)
        	System.out.println("Cycle exists!");
        else
        	System.out.println("Cycle doesn't exist!");
		
	}

	private static boolean checkCycle(int u, int[] visited_dfs, int[] st) {
		visited_dfs[u]=1;
		st[u]=1;
		Iterator it_queue=adjList[u].iterator();
		while(it_queue.hasNext())
		{
			boolean res;
			int temp=(int) it_queue.next();
			if(visited_dfs[temp]==0){
				res = checkCycle(temp,visited_dfs,st);
				return res;
			}
				
			else if(st[u]==1) //visited and stack both are 1
				return true;
		}
		st[u]=0;
		return false;
	}
	
}
