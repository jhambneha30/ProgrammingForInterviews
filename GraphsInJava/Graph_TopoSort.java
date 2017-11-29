import java.util.LinkedList;

/*Topological sort:
 * Step 1) Identify vertices for which indegree=0 - O(v^2)
 * Step 2) Delete this vertex of indegree 0 and all its outgoing edges from the
 * graph. Place the vertex in the output. -O(E) [because every edge is visited once]
 * Repeat step 1 and 2 until graph is empty
 * 
 * OPTIMIZATION:
 * We can decrease the time taken in step 1 using an array to O(v)
 * 
 * METHOD 1: Using Kahn's algorithm -o(V+E)
 * 1. Using the adjacency list, build an array to store the in degree of the vertices.-O(V+E)
 * 2. Loop through the array and find the vertices with in degree=0. Print such vertices first.
 * For every vertex v that is printed, 
 * (i) make its in degree as -1 
 * (ii) For all the vertices adjacent to this vertex v, reduce the in degree by 1. (we assume 
 * that the vertex v has been deleted from the adjacency list).
 *
 *TC=O(V^2) + O(V+E)
 *
 *OPTIMIZATION: Maintain a queue to store the the vertices with in degree 0, update it every time
 *a vertex is printed or a vertex's in degree becomes 0.
 *
 *http://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
 *
 *Method 2: Using stack: TC=O(V+E)
 *http://www.geeksforgeeks.org/topological-sorting/
 *
 *APPLICATIONS: resolving dependencies in various systems
 *https://www.quora.com/What-are-some-real-world-applications-of-topological-sort
 */
public class Graph_TopoSort {
	private static LinkedList<Integer> adjList[];
	private static int num;
	
	
	//Constructor
	Graph_TopoSort(int v)
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
	
	public static void main(String[]args)
	{
		
	}
}
