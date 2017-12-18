import java.io.*;
import java.util.*;
/*Find the start node of a loop in a LL
 * a) Use hash table and keep marking 1 as we traverse the LL.
 *  If we visit a cell with already 1 present => start node of the loop
 * b) Use a flag in the class Node
 * c) Use slow and fast pointers. When they meet, take the fast pointer to the beginning
 * of LL and move both slow and fast pointers one node at a time
 * until they meet. This meeting pt is the start of the loop!
 */
public class StartNodeOfLoopInLL {
	static Node head;
	public static void main(String[]args) {
		Node n1 = new Node(10);
		Node n2 = new Node(20);
		Node n3 = new Node(30);
		Node n4 = new Node(40);
		head = n1;
		n1.link = n2;
		n2.link = n3;
		n3.link = n4;
		n4.link = n2;
		
		findStartOfLoop();
	}
	
	private static void findStartOfLoop() {
		Node slow = head.link;
		Node fast = head.link.link;
		while(slow!=fast){
			slow = slow.link;
			fast = fast.link.link;
		}
		fast=head;
		while(slow!=fast) {
			slow=slow.link;
			fast=fast.link;
		}
		System.out.println("Start of loop is: "+ slow.data +" or "+fast.data);
	}
}
