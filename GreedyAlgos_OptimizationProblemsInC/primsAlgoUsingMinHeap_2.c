/*
===============================Algorithm:====================================
Prim(G,cost,r) //r => node in the tree
{
	1. for each vertex u belongs to G ------------O(v)
	{
		2. u.key=INFINITY //key- among all the vertices added in the MST, what is the least cost wt from vertex u to one of them.	
		3. u.parent=NULL
	}
	4. r.key=0
	5. u=G.vertices  //Build min-heap basis the key attribute. --------------O(v)
	6. while(Q!=NULL)									 --------------O(vlogv + v*vlog v)
	{
		7. u=extract_min(Q);									-------------O(log v)
		8. for each vertex v adjacent to u   	
		//In worst case, all vertices can be adjacent to u			-------------O(v log v)
		{
			9. if(v belong to Q && cost[u,v]<v.key)
			{
				10. v.parent=u
				11. v.key=cost(u,v) //Cost is decreased using decrease_key(Q,new_key)--O(log v)
			}
		}
	}	
}
==============================================================================
It seems as if the TC =O(v^2 log v). But if we do AGGREGATE ANALYSIS, the TC comes out to be
O(v^2). Actually, the decrease key is called O(E) times =>O(Elog v)
Extract min is called O(vlog v) times
Build heap takes O(v) time
--------------------------------------------------------------
--> TC=O(Elogv+vlogv+v)=O(E log v) (using min-heap)
--> TC=O(vlogv +E) (using Fibonacci heap)
--------------------------------------------------------------
Que: Which one is better: Without using heap or using min heap?
Ans: 1.w/o heap - O(v^2), 2.with min-heap - O(Elogv)
So, it depends on the type of graph.
If the graph is dense, [1. w/o heap] is better as E=v^2
If the graph is sparse, [2. with min-heap] is better asE=O(v)

NOTE: PRIM'S ALGO GROWS AS ONE TREE. IT NEVER FORMS A FOREST!
*/
