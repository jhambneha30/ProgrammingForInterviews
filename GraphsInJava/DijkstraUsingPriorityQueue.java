import java.util.*;

public class DijkstraUsingPriorityQueue {
	
	private static PriorityQueue<PQueueElement> q;
	private static int dist[];
	private static boolean processedVertexFlag[];
	
	DijkstraUsingPriorityQueue(int num)
	{
		q=new PriorityQueue<PQueueElement>();
		dist = new int[num];
		PQueueElement pq_elt=new PQueueElement(0,0);
		q.add(pq_elt);
		dist[0]=0;
		for(int i=1;i<num;i++)
		{
			dist[i]=999999999;
			pq_elt=new PQueueElement(9999999,i);
			q.add(pq_elt);
		}
			
		//processedVertexFlag is the array which indicates the vertices which have already been processed
		processedVertexFlag=new boolean[num];
	}
	
	public static class Graph
	{
		int V;
		LinkedList<Node> adjList[];
		Graph(int v)
		{
			V=v;
			adjList =new LinkedList[v];
			for(int i=0;i<v;i++)
			{
				adjList[i]=new LinkedList<Node>();
			}
		}
		
		void addEdge(int u,int v,int wt)
		{
			Node newNode=new Node(v,wt);
			adjList[u].add(newNode);
		}
	}
	
	public static void dijkstra(Graph g)
	{
		int u;
		while(!q.isEmpty())
		{
			u=q.poll().vertex;
			System.out.println("Extracted vertex is: "+u+" with dist= "+q.poll().minDist_key);
			processedVertexFlag[u]=true;
			
			Iterator<Node> adj_it=g.adjList[u].iterator();
			while(adj_it.hasNext())
			{
				Node v=adj_it.next();
				if(dist[u]+v.weight<dist[v.destination])
				{
					dist[v.destination]=dist[u]+v.weight;
					q.remove(v.destination);
					PQueueElement pq=new PQueueElement(dist[v.destination],v.destination);
					q.add(pq);
					
				}
			}
		}
	}
	
	public static void main(String[]args)
	{
		int V = 5;
		DijkstraUsingPriorityQueue dpq=new DijkstraUsingPriorityQueue(V);
	    Graph graph = new Graph(V);
	    graph.addEdge(0, 1, 10);
	    graph.addEdge(0, 3, 5);
	    graph.addEdge(0, 4, 7);
	    graph.addEdge(1, 2, 1);
	    graph.addEdge(3, 1, 3);
	    graph.addEdge(3, 4, 1);
	    graph.addEdge(2, 4, 4);
	    graph.addEdge(4, 2, 6);
	   
	 
	    dpq.dijkstra(graph);
	    
	    for(int j=0;j<V;j++)
	    {
	    	System.out.println(j+": "+dist[j] + " "+processedVertexFlag[j]);
	    }
	 
	}
	
	

}
