import java.util.Scanner;

/*
 * LINKED LIST: Only sequential access, random access not possible in O(1) time
 * Searching on unsorted array- O(n) for linked lists and arrays
 * Traversing- Moving head pointer is very dangerous, as we'll lose the LL. So, use a temp variable.
 * ------------------------------------------------------------------------------------
 * CIRCULAR LINKED LIST: Last node points to the first node instead of pointing to null.
 * Advantages: 1. Last pointer is not wasted
 * 2. We can go back to a node without having to traverse the whole LL from the beginning.
 * Disadvantage: We might fall into an infinite loop while traversing the LL as no node ever points to null.
 * To avoid this, sentinal node is introduced to which head points. 
 * The strcuture of this node is different from other nodes and is generally used to save the count of nodes in the LL.
 * Note: The sentinal node can also be added at the end of the LL.
 */
public class LinkedListMain {
	static Scanner input=new Scanner(System.in);
	static Node head;
	public static void main(String[]args)
	{
		int menu_selection=0;
		while(menu_selection!=8)
		{
			int newData=0;
			System.out.println("MENU: \n"
					+ "1: Insert a new node to the front.\n"
					+ "2: Insert a new node after a given node.\n"
					+ "3: Insert a new node at the end.\n"
					+ "4: Delete a node.\n"
					+ "5: Traverse the linked list and print data.\n"
					+ "6: Move last node to front of the SLL.\n"
					+ "7: Reverse the SLL.\n"
					+ "8: EXIT");
			menu_selection=input.nextInt();

			if(menu_selection==1 || menu_selection==2 || menu_selection==3)
			{
				System.out.println("Enter the data to be stored in the new node.");
				newData=input.nextInt();
			}
			switch (menu_selection)
			{
			case 1: 

				insertAtFront(newData);
				break;
			case 2: 
				System.out.println("Enter the element after which new node should be inserted.");
				int elt=input.nextInt();
				insertAfterElt(newData,elt);
				break;
			case 3: 

				insertAtEnd(newData);
				break;
			case 4: 
				System.out.println("Enter the element to be deleted.");
				int deletion=input.nextInt();
				deleteElement(deletion);
				break;
			case 5: 
				traverseSLL();
				break;
			case 6: 
				moveLastToFront();
				break;
			case 7: 
				reverseSLL();
				break;
			case 8:
				System.out.println("BYE!");
				break;
			default: System.out.println("Please choose from the menu below!");
			}
		}
	}
	private static void reverseSLL() {
		Node prev,cur,next;
		if(head==null || head.link==null) //If LL is empty
			System.out.println("Too short to be reversed!");
		else
		{
			prev=null;
			cur=head;
			
			while(cur!=null)
			{
				next=cur.link;
				cur.link=prev;
				prev=cur;
				cur=next;
				
			}
			head=prev;
			
		}
			
		
	}
	private static void moveLastToFront() {
		Node temp;
		if(head==null)
			System.out.println("LL is empty!");
		else if(head.link==null)
			System.out.println("Only one element exists!");
		else
		{
			temp=head;
			while(temp.link.link!=null)
			{
				temp=temp.link;
			}
			temp.link.link=head;
			head=temp.link;
			temp.link=null;
		}
		
	}
	private static void deleteElement(int deletion) {
		Node temp=head;
		

		if(head==null) //If LL is empty
			System.out.println("LL is empty!");
		else if(head.link==null && head.data==deletion) //If one node exists and it has to be deleted
		{
			head=null;
		}
		else
		{
			if(head.data==deletion) //Deletion at beginning
			{
				head=head.link;
			}
			else
			{
				temp=head;
				while(temp.link!=null && temp.link.data!=deletion)
				{
					temp=temp.link;
				}
				if(temp.link.data==deletion && temp.link.link!=null)
				{
					temp.link=temp.link.link;
				}
				else //If last node has to be deleted
					temp.link=null;
			}

		}



	}
	private static void insertAfterElt(int newData, int elt) {
		Node temp=head;
		if(head==null)
		{
			System.out.println("OOPS! Linked list is empty!");
		}
		//		else if(head.link==null)
		//		{
		//			
		//		}
		else
		{
			Node newNode= new Node(newData);
			while(temp!=null && temp.data!=elt )
			{
				//				if(temp!=null)
				temp=temp.link;
			}
			if(temp!=null)
			{
				newNode.link=temp.link;
				temp.link=newNode;
			}
			else
				System.out.println("Data not found!");

		}

	}
	private static void insertAtEnd(int newDataEnd) {
		Node newNodeEnd= new Node(newDataEnd);
		if(head==null)
		{
			head=newNodeEnd;
		}
		else
		{
			Node temp=head;
			while(temp.link!=null)
			{
				temp=temp.link;
			}
			temp.link=newNodeEnd;
		}


	}
	private static void traverseSLL() {
		Node p=head;
		if(p==null)
			System.out.println("LL is empty");
		else
		{
			while(p!=null)
			{
				System.out.println(p.data);
				p=p.link;
			}
		}


	}
	private static void insertAtFront(int newData) {
		Node newNode= new Node(newData);
		newNode.link=head;
		head=newNode;
	}

}
