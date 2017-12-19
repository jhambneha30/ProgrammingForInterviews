import java.io.*;
import java.util.*;

public class BST {
	public static class Node{
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
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("2 5 1 3 9 6 4"," ");
		Node root = null;
		while(st.hasMoreTokens()){
			int data = Integer.parseInt(st.nextToken());
			root=insert(root, data);
		}
		inorder(root);
		delete(root, 3);
		inorder(root);
		delete(root, 9);
		inorder(root);
		
	}
	private static Node insert(Node root, int data) {
		
		if(root==null){
			Node newNode = new Node(data);
			return newNode;
		}
		
		if(data<=root.data){
			root.left = insert(root.left,data);
			return root;
		}
		else{
			root.right = insert(root.right,data);
			return root;
		}
		
	}
	
	private static Node delete(Node root, int data){
		if(root==null){
			System.out.println("Node not found!");
			return root;
		}
		else if(data<root.data){
			root.left = delete(root.left,data);
			return root;
		}
		else if(data>root.data){
			root.right= delete(root.right,data);
			return root;
		}
		else //(root.data==data)
		{
			if(root.left==null && root.right==null){
				return null;
			}
			else if(root.left==null){
				return root.right;
			}
			else if(root.right==null){
				return root.left;
			}
			else{
				Node temp = inorderPredecessor(root);
				root.data = temp.data;
				root=delete(root, temp.data);
				return root;
			}
		}
	}
	
	private static Node inorderPredecessor(Node root) {
		if(root.right==null)
			return root;
					
		Node pred = inorderPredecessor(root.right);
		return pred;
	}
	private static void inorder(Node root) {
		if(root!=null){
			inorder(root.left);
			System.out.print(root.data + " ");
			inorder(root.right);
		}
		
	}
}
