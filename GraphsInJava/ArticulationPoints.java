import java.util.*;



public class ArticulationPoints {
	static int time=0;
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
			adjList[v].add(u);
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
		System.out.println("Articulation points in first graph ");
        Graph g1 = new Graph(5,5);
        g1.addEdge(1, 0);
        g1.addEdge(0, 2);
        g1.addEdge(2, 1);
        g1.addEdge(0, 3);
        g1.addEdge(3, 4);
//        g1.displayGraph();
        articulationPts(g1);
        System.out.println();
 
        System.out.println("Articulation points in Second graph");
        Graph g2 = new Graph(4,3);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        g2.addEdge(2, 3);
        articulationPts(g2);
        System.out.println();
 
        System.out.println("Articulation points in Third graph ");
        Graph g3 = new Graph(7,8);
        g3.addEdge(0, 1);
        g3.addEdge(1, 2);
        g3.addEdge(2, 0);
        g3.addEdge(1, 3);
        g3.addEdge(1, 4);
        g3.addEdge(1, 6);
        g3.addEdge(3, 5);
        g3.addEdge(4, 5);
        g3.displayGraph();
        articulationPts(g3);
	}

	private static void articulationPts(Graph g) {
		int[] visited =new int[g.v];
		int[] discoveryTime = new int[g.v];
		int[] lowTime = new int[g.v];
		int[] parent = new int[g.v];
		Arrays.fill(parent, -1);
		int[] artPts = new int[g.v];
		Arrays.fill(artPts, 0);
//		discoveryTime[0]=lowTime[0]=0;
		for(int i=0;i<g.v;i++) {
			if(visited[i]==0)
				articulationPtsUtil(g,i,visited,discoveryTime,lowTime,parent,artPts);
		}
		
		System.out.println("Articulation Pts are:");
		for(int x=0;x<g.v;x++) {
			if(artPts[x]==1)
				System.out.println(x);
		}
		
	}
	//u is the node on which the recursive func is called and v is the adjacent vertex
	private static void articulationPtsUtil(Graph g, int u, int[] visited, int[] discoveryTime, int[] lowTime,
			int[] parent,int[] ap) {
		visited[u]=1;
		discoveryTime[u]=lowTime[u]=++time;
		int children=0;
		Iterator it=g.adjList[u].iterator();
		while(it.hasNext()) {
			int v=(int)it.next();
			if(visited[v]==0) {
				children++;
//				System.out.println("#Children of: "+u+" are:"+children);
//				System.out.println("Child is: "+v);
				parent[v]=u;
				articulationPtsUtil(g,v,visited,discoveryTime,lowTime,parent,ap);
				
				//Now, check if this node u is an AP
				//Condition 1 for root
				if(parent[u]==-1 && children>1)
					ap[u]=1;
				//Condition 2 for other nodes
				if(parent[u]>=0 && lowTime[v]>=discoveryTime[u])
					ap[u]=1;
				
				//Update the low value of u using the adjacent node v
				lowTime[u]=Math.min(lowTime[u], lowTime[v]);
			}
			else if(v!=parent[u]) {
				//This means it is a back edge forming a cycle and so this can't be AP. update the lowTime
				lowTime[u]=Math.min(lowTime[u], lowTime[v]);
			}
		}
		
		
	}
}
