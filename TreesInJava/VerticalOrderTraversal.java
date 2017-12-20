/* VERTICAL ORDER TRAVERSAL

For this, we compute the horizontal distance of each node from the root.
Root's horizontal dist from root=0,
if we go left, we subtract 1 and if we go right , we add 1.

Thus the roots at the same horizontal distances form a vertical straight line.

Method 1: First find the range of the horizontal distances (say [-2,2]) using any traversal.
So, we do a traversal and keep computing the horizontal distance on the fly and keep updating
the min and max variable which will finally give the range.

Now, for every number in the range, call the traversal function and print the nodes with
horizontal dist = that number.

TC=O(n) to compute the range + k*O(n); where k=total numbers in the range
SC=O(n) taken by stack.
=============================================================================================
Method 2: Using a hash table and chaining
If we store the nodes in hash table along with computing the horizontal distance, then we can
save traversing the tree so many times.

Deciding hash table size: We know that the max range possible is -(n-1) to (n-1) if the tree
is left/right skewed.
So, we take a hash table of size 2(n-1)+1

Now, as we compute the horizontal dist of each node, add it to the Linked list corresponding
to that index in hash table.

TC=O(n) as tree is traversed atmost once + traversing the hash table in O(numbers in range)
=>TC=O(n)
SC=O(n) for stack and for hash table O(n)=O(n)
==============================================================================================
Method 3:OPTIMIZATION of method 2 by reducing the size of hash table.
Use a DOUBLY LINKED LIST in the place of using a hash table:-This can be created as we are 
computing the horizontal distance of nodes.
Refer to the diagram to see the structure of the DLL

TC=O(n) for single preorder traversal
SC=O(n) for stack and DLL
==============================================================================================
Method 4: Using level order traversal
http://www.geeksforgeeks.org/print-a-binary-tree-in-vertical-order-set-3-using-level-order-traversal/
*/

import java.io.*;
import java.util.*;

public class VerticalOrderTraversal {
	public static class Node{
		int data;
		Node left,right;
		Node(int d){
			this.data=d;
			this.left=null;
			this.right=null;
		}
	}
	public static class SLLNode{
		int sll_data;
		SLLNode link;
		SLLNode(int d){
			this.sll_data = d;
			this.link=null;
		}
	}
	public static class DLLNode{
		int vertical_num;
		DLLNode left, right;
		SLLNode below;
		DLLNode(int num){
			this.vertical_num=num;
			this.left=null;
			this.right=null;
			this.below=null;
		}
		
	}
	static DLLNode centre=null;
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
		System.out.println("\nvertical order traversal is:");
		centre = verticalOrderTraversal(root,0,'h',centre);
		//Now, the DLL structure has been created. We need to traverse it and print the nodes.
		//Currently, our centre pointer points to the centre. We find the head of the DLL
		DLLNode dll_head = centre;
		while(dll_head.left!=null){
			dll_head = dll_head.left;
		}
		//Now, we start printing the nodes.
		
		DLLNode ptr= dll_head;
		while(ptr!=null){
			System.out.println("Vertical id is: "+ptr.vertical_num);
			SLLNode p = ptr.below;
			while(p!=null){
				System.out.print(p.sll_data+ " ");
				p=p.link;
			}
			System.out.println();
			ptr=ptr.right;
			
		}
		
	}
	
	private static SLLNode insertInSLL(SLLNode head, int data){
		if(head==null){
			head = new SLLNode(data);
			return head;
		}
		SLLNode newNode = new SLLNode(data);
		newNode.link=head;
		head=newNode;
		
		return head;
		
	}
	
	private static DLLNode verticalOrderTraversal(Node root,int vertical_id, char flag, DLLNode mid) {
		//Flag h means this is the call to the root of the tree
		//Flag l means this is the call to the LST
		//Flag r means this is the call to the RST
		if(root==null)
			return null;
		if(mid==null && flag=='h'){
			//This means that root in the tree exists but there is no root node created for it in the DLL.
			//So, we create a new DLL node
			DLLNode newNode = new DLLNode(vertical_id);
			//Now, add the data present in the tree node in the LL below this DLLNode
			newNode.below = new SLLNode(root.data);
			mid = newNode;
			
		}
		System.out.println("root data is "+root.data);
		if(flag=='l'){
			if(mid.left==null){
				DLLNode newNode = new DLLNode(vertical_id);
				//Now, add the data present in the tree node in the LL below this DLLNode
				newNode.below = new SLLNode(root.data);
				newNode.right=mid;
				mid.left = newNode;
				mid = mid.left;
			}
			else{
				//We just need to add the SLLNode under the DLLNode already existing
				mid.left.below = insertInSLL(mid.left.below,root.data);
			}
		}
		
		if(flag=='r'){
			if(mid.right==null){
				DLLNode newNode = new DLLNode(vertical_id);
				//Now, add the data present in the tree node in the LL below this DLLNode
				newNode.below = new SLLNode(root.data);
				newNode.left=mid;
				mid.right = newNode;
				mid = mid.right;	
			}
			else{
				//We just need to add the SLLNode under the DLLNode already existing
				mid.right.below=insertInSLL(mid.right.below,root.data);
			}
		}
		
		if(root.left!=null)
			verticalOrderTraversal(root.left,vertical_id-1,'l',mid);
		if(root.right!=null)
			verticalOrderTraversal(root.right,vertical_id+1,'r',mid);
		
		return mid;
		
	}

	private static void inorder(Node root) {
		if(root!=null){
			inorder(root.left);
			System.out.print(root.data + " ");
			inorder(root.right);
		}	
	}
}
