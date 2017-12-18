import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class HeightOfTree {
	public static class Node {
		int data;
		Node left;
		Node right;
		Node(int d){
			this.data=d;
			this.left=null;
			this.right=null;
		}
	}
	public static void main(String[]args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(br.readLine());
		System.out.println("testcses="+tc);
		for(int t=0;t<tc;t++){
			Node root = null;
			HashMap<Integer,Node> hm = new HashMap<Integer,Node>();
			int inputs = Integer.parseInt(br.readLine());
//			System.out.println("inputs="+inputs);
			StringTokenizer st = new StringTokenizer(br.readLine());
			while(inputs>0){
				int n1 = Integer.parseInt(st.nextToken());
				int n2 = Integer.parseInt(st.nextToken());
				char c = st.nextToken().charAt(0);
//				System.out.println("n1="+n1);
//				System.out.println("n2="+n2);
//				System.out.println("c="+c);
				//If parent doesn't exist in the hashmap, it means it is the root.
				Node parent = hm.get(n1);
				if(parent==null){
					parent = new Node(n1);
					if(root==null)
						root=parent;
					hm.put(n1,parent);
//					System.out.println("Adding root"+n1);
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
			//After the tree is made, call the traversal method
			System.out.println("Inorder");
			inorder(root);
			
			System.out.println("Height of tree");
			int ht = heightOfTree(root);
			System.out.println("Height is: "+ht);
		}
		
		
	}
	private static int heightOfTree(Node root) {
		if(root==null){
			return 0;
		}
		int left = heightOfTree(root.left);
		int right = heightOfTree(root.right);
		return(1+Math.max(left,right));
		
	}
	private static void inorder(Node root) {
		if(root!=null){
			inorder(root.left);
			System.out.print(root.data + " ");
			inorder(root.right);
		}
		
	}
}
