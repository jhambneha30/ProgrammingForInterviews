import java.util.Iterator;
import java.util.LinkedList;

// Find if there is a path between two vertices vi and vj in a directed graph
/*
 * Ensure that there is a path from vi->->->vj and vj->->->vi
 */
public class PathInTwoVertices {
	public static class Graph{
		static int vertices;
		private static LinkedList adjList[];
		Graph(int v){
			this.vertices = v;
			adjList=new LinkedList[v];
			for(int i=0;i<v;i++){
				adjList[i] = new LinkedList();
			}
		}

		void addEdge(int u, int v){
			adjList[u].add(v);
		}
	}
	
	public static void main(String[]args){
		int n=5;
		int u=0;
		int v=2;
		Graph g = new Graph(n);
		g.addEdge(0, 1);
		g.addEdge(0, 2);
		g.addEdge(1, 2);
		g.addEdge(2, 0);
		g.addEdge(2, 3);
		g.addEdge(3, 3);
		g.addEdge(1, 4);
		int[] visited1 = new int[n];
		Boolean res1 = checkPath(g,u,v, visited1);
		int[] visited2 = new int[n];
		Boolean res2 = checkPath(g,v,u, visited2);
		if(res1==true && res2==true)
			System.out.println("Path exists" );
		else
			System.out.println("Path doesn't exist!");
	}

	private static Boolean checkPath(Graph g, int u, int dest, int[] visited_dfs) {
		if(u==dest)
			return true;
		visited_dfs[u]=1;
		System.out.println(u);
		Boolean r;
		Iterator neighbours_it = g.adjList[u].iterator();
		while(neighbours_it.hasNext()){
			int temp = (int)neighbours_it.next();
			if(visited_dfs[temp]!=1){
				r=checkPath(g, temp, dest, visited_dfs);
				return r;
			}
				
		}
		return false;
	}
}
