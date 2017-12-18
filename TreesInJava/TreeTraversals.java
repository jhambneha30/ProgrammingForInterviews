/*Taken the input format from Geeks for Geeks
 * https://practice.geeksforgeeks.org/problems/inorder-traversal/1
 * ---------INORDER TRAVERSAL OF A BINARY TREE-------------
Input: No. of test cases, No. of inputs apart from root(1 2 R, 1 3 L ~ 2 inputs)
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
3 1 2
40 20 60 10 30
 * ------------------------------------------------------- 
 * To build a tree, we need to use a hashmap here which contains the data and the address of
 * corresponding node in the tree.
 */
import java.io.*;
import java.util.*;
import java.lang.*;
public class TreeTraversals {
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
			System.out.println("Preorder");
			preorder(root);
			System.out.println("Postorder");
			postorder(root);
			
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
	
	private static void preorder(Node root) {
		if(root!=null){
			System.out.print(root.data + " ");
			preorder(root.left);
			preorder(root.right);
		}
	}
	
	private static void postorder(Node root) {
		if(root!=null){
			postorder(root.left);
			postorder(root.right);
			System.out.print(root.data + " ");
		}
	}

}
