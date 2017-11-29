import java.io.*;
import java.util.*;

public class Test20_3AlienDictionary {
	static class Graph {
		private int v;
		private int e;
		private LinkedList[] adjList;
		Graph(int vertices) {
			this.v=vertices;
			adjList=new LinkedList[v];
			for(int i=0;i<vertices;i++) {
				adjList[i]=new LinkedList();
			}
		}
		
		private void addEdge(int u,int v) {
			adjList[u].add(v);
		}
	}
	public static void main(String[]args)throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int num_words=Integer.parseInt(st.nextToken());
			int alphabets=Integer.parseInt(st.nextToken());
			String[] dict=new String[num_words];
			st=new StringTokenizer(br.readLine());
			for(int i=0;i<num_words;i++) {
				dict[i]=st.nextToken();
			}
			
			Graph g=new Graph(alphabets);
			for(int i=0;i<num_words-1;i++) {
				String w1=dict[i];
				String w2=dict[i+1];
				for(int j=0;j<min(w1.length(),w2.length());j++) {
					if(w1.charAt(j)!=w2.charAt(j)) {
						g.addEdge(w1.charAt(j)-'a', w2.charAt(j)-'a');
						int a=w1.charAt(j)-'a';
						int b=w2.charAt(j)-'a';
						System.out.println(a+"--->"+b);
						break;
					}
				}
			}
			topologicalSort(g);
		}
	}
	private static void topologicalSort(Graph g) {
		boolean[] visited=new boolean[g.v];
		Arrays.fill(visited, false);
		Stack st=new Stack();
		for(int i=0;i<g.v;i++) {
			if(visited[i]==false) {
				topologicalSortMain(i,g,st,visited);
			}
		}
		String res="";
		while(!st.isEmpty()) {
			char c=(char) ((int)st.pop()+'a');
			res+=c;
		}
		System.out.println(res);
	}
	
	private static void topologicalSortMain(int node, Graph g,Stack st,boolean[] visited) {
		visited[node]=true;	
		Iterator it=g.adjList[node].iterator();
		while(it.hasNext()) {
			int adjNode=(int)it.next();
			if(visited[adjNode]==false) {
				topologicalSortMain(adjNode,g,st,visited);
			}
		}
		st.add(node);
	}
	private static int min(int a, int b) {
		
		return a<b?a:b;
	}
}
