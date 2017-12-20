import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

//Here, we consider that the nodes are >1
public class LowestCommonAncestorForBT {
	public static class Node{
		int data;
		Node left,right;
		Node(int d){
			this.data=d;
			this.left=null;
			this.right=null;
		}
	}
	public static void main(String[]args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		HashMap<Integer,Node> hm = new HashMap<Integer,Node>();
		int inputs = 4;
		Node root=null;
		int a = 4;
		int b = 1;
		StringTokenizer st = new StringTokenizer("1 3 L 1 2 R 2 5 L 2 4 R"," ");
		while(inputs>0){
			int n1 = Integer.parseInt(st.nextToken());
			int n2 = Integer.parseInt(st.nextToken());
			char c = st.nextToken().charAt(0);
//			System.out.println("n1="+n1);
//			System.out.println("n2="+n2);
//			System.out.println("c="+c);
			//If parent doesn't exist in the hashmap, it means it is the root.
			Node parent = hm.get(n1);
			if(parent==null){
				parent = new Node(n1);
				if(root==null)
					root=parent;
				hm.put(n1,parent);
//				System.out.println("Adding root"+n1);
			}
			//If parent exists in the hashmap, just make a new node for the child and attach it to the tree.
			Node treeNode = new Node(n2);
			if(c=='L'){
				parent.left=treeNode;
			}
			else if(c=='R'){
				parent.right=treeNode;
			}
			hm.put(n2,treeNode);
			inputs--;
		}
		System.out.println("inorder traversal is:");
		inorder(root);
		int lca = lcaForBT(root,a,b);
		System.out.println("\nLCA is: "+ lca);
	}
	private static int lcaForBT(Node root, int n1, int n2) {
		if(root==null){
			return -1;
		}
		if(root.data==n1 || root.data==n2)
			return root.data;
		int left = lcaForBT(root.left,n1,n2);
		int right = lcaForBT(root.right,n1,n2);
		System.out.println("root->"+root.data);
		System.out.println("left: "+ left+" right: "+right);
		
		if(left>0 && right>0)
			return root.data;
		
		return left>0?left:right;
	}
	private static void inorder(Node root) {
		if(root!=null){
			inorder(root.left);
			System.out.print(root.data + " ");
			inorder(root.right);
		}
		
	}
	
}
