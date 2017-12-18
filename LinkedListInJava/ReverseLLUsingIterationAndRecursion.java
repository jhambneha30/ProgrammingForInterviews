import java.io.*;
import java.util.*;
public class ReverseLLUsingIteration {
	static NodeSLL head;
	public static void main(String[]args) {
		Scanner input = new Scanner(System.in);
		int choice=100;
		while(choice!=0) {
			System.out.println("1: Insert at beginning\n"
					+ "2: Delete from beginning\n"
					+ "3: Reverse using iteration\n"
					+ "4: Reverse using recursion\n"
					+ "5: Traverse\n"
					+ "0: Exit");
			choice = input.nextInt();
			int data;
			switch(choice){
			case 1:
				System.out.println("Enter the data to be inserted!");
				data = input.nextInt();
				insertAtFront(data);
				break;
			case 2: 
				deleteFromFront();
				break;
			case 3: 
				reverseUsingIteration();
				break;
			case 4:
				reverseUsingRecursion(null,head);
				break;
			case 5:
				traverseLL();
				break;
			default: System.out.println("Please enter a valid choice!");
			}
		}
		
	}
	private static void traverseLL() {
		NodeSLL ptr = head;
		if(head==null)
			System.out.println("LL is empty!");
		else {
			while(ptr!=null) {
				System.out.print(ptr.data + "->");
				ptr=ptr.next;
			}
			System.out.println();
		}
		
	}
	private static void reverseUsingRecursion(NodeSLL prev, NodeSLL curr) {
		if(head==null || head.next==null)
			return;
		if(curr==null) {
			head=prev;
			return;
		}
		reverseUsingRecursion(curr,curr.next);
		curr.next=prev;
		
	}
	
	private static void reverseUsingIteration() {
		// 3 pointers are required: prev, curr, nxt
		if(head==null || head.next==null)
			return;
		NodeSLL prev,curr,nxt;
		prev=null;
		curr=head;
		while(curr!=null) {
			nxt=curr.next;
			curr.next=prev;
			prev=curr;
			curr=nxt;
		}
		head=prev;
	}
	
	private static void deleteFromFront() {
		int temp;
		if(head==null){
			System.out.println("LL is empty!");
			return;
		}
		temp=head.data;
		System.out.println("Deleted-"+temp);
		head = head.next;
	}
	public static void insertAtFront(int data) {
		NodeSLL newNode = new NodeSLL(data);
		if(head==null) {
			head = newNode;
			return;
		}
		newNode.next = head;
		head = newNode;
		
	}
}
