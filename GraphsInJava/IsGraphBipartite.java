import java.util.*;
/*
 * http://www.geeksforgeeks.org/bipartite-graph/
 * Use BFS to check it.
 */
public class IsGraphBipartite {
	public static class Graph {
		private int v;
		private int e;
		private LinkedList<Integer>[] adjList;
		Graph(int vert,int edges) {
			this.v=vert;
			this.e=edges;
			adjList=new LinkedList[v];
			for(int i=0;i<v;i++) {
				adjList[i]=new LinkedList<>();
			}
		}
		
		void addEdge(int u,int v) {
			adjList[u].add(v);
//			adjList[v].add(u);
		}
		
		void displayGraph() {
			for(int i=0;i<v;i++) {
				Iterator it=adjList[i].iterator();
				System.out.print(i+": ");
				while(it.hasNext()) {
					System.out.print("->"+it.next());
				}
				System.out.println();
			}
		}
	}
	
	public static void main(String[]args) {
		System.out.println("============first graph============");
        Graph g1 = new Graph(3,3);
        g1.addEdge(0, 1);
//        g1.addEdge(0, 3);
        g1.addEdge(1, 2);
//        g1.addEdge(1, 2);
        g1.addEdge(2, 0);
//        g1.addEdge(2, 1);
//        g1.addEdge(2, 0);
//        g1.addEdge(3, 0);
//        g1.addEdge(3, 2);
        g1.displayGraph();
        if(isBipartite(g1)==true)
        	System.out.println("Graph is bipartite");
        else
        	System.out.println("Not bipartite");
 
        
	}

	private static boolean isBipartite(Graph g) {
		int[] visited=new int[g.v];
		int[] color=new int[g.v];
		for(int i=0;i<g.v;i++) {
			visited[i]=0;
			color[i]=-1;
		}
		Queue<Integer> q=new LinkedList<>();
		q.add(0);
		visited[0]=1;
		color[0]=0;
		while(!q.isEmpty()) {
			int popped=q.poll();
			Iterator it=g.adjList[popped].iterator();
			while(it.hasNext()) {	
				
				int adj=(int) it.next();
				if(visited[adj]==0) {
					visited[adj]=1;
					int opposite_color=1-color[popped];
					if(color[adj]==-1)
						color[adj]=opposite_color;
					else if(color[adj]!=opposite_color) 
						return false;
					
					q.add(adj);
				}
				else {
					int opposite_color=1-color[popped];
					if(color[adj]!=opposite_color) 
						return false;
				}
				
			}
		}
		return true;
	}
	
}
