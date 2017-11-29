// INITIAL CODE
import java.util.*;
import java.lang.*;
import java.io.*;

// A Binary Tree node
class TNode
{
    int data;
    TNode left;
    TNode right;

    TNode(int item)
    {
        data = item;
        left = right = null;
    }
}



class Test8_3LRUCache
{
	void inorder(TNode node)
	{
		if(node==null)
			return ;
		else
			inorder(node.left);
			System.out.print(node.data + " ");
			inorder(node.right);
			
					
	}
	
    // driver function to test the above functions
    public static void main(String args[])
    {
    	Test8_3LRUCache CLN = new Test8_3LRUCache();
		//Index index_obj = new Index();
        // Input the number of test cases you want to run
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t > 0)
        {
            HashMap<Integer, TNode> m = new HashMap<Integer, TNode> ();
            int n = sc.nextInt();

            TNode root = null;

            while (n > 0)
            {	
			
				int n1 = sc.nextInt();
                int n2 = sc.nextInt();
				char lr= sc.next().charAt(0);
				
                //  cout << n1 << " " << n2 << " " << (char)lr << endl;
				TNode parent = m.get(n1);
                if (parent == null)
                {
                    parent = new TNode(n1);
                    m.put(n1, parent);
                    if (root == null)
                        root = parent;
                }

                TNode child = new TNode(n2);
                if (lr == 'L')
                    parent.left = child;
                else
                    parent.right = child;
                m.put(n2, child);
                n--;
            }
			
            
			
			boolean res = isHeap(root);
			if(res == true)
			System.out.println(1);
			else 
			System.out.println(0);
			//CLN.inorder(root);
			 t--;
			// System.out.println();
        }
    }

	private static boolean isHeap(TNode root) {
		boolean res;
		if(root==null) {
			return true;
		}
		
		if(root.left!=null && root.left.data>root.data) {
			return false;
		}
		if(root.right!=null && root.right.data>root.data) {
			return false;
		}
		
		res=isHeap(root.left) && isHeap(root.right);
		return res;
	}
}