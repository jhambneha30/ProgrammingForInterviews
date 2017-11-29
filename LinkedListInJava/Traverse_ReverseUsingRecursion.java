import java.util.Scanner;
public class Traverse_ReverseUsingRecursion {
	static Scanner input=new Scanner(System.in);
	static Node head;
	public static void main(String[]args)
	{
		int menu_selection=0;
		insertAtFront(5);
		insertAtFront(4);
		insertAtFront(3);
		insertAtFront(2);
		insertAtFront(1);
		while(menu_selection!=4)
		{
//			int newData=0;
			
			System.out.println("MENU: \n"
					+ "1: Print the list.\n"
					+ "2: Print the list in reverse order.\n"
					+ "3: Reverse the SLL using recursion.\n"
					+ "4: EXIT.");
			menu_selection=input.nextInt();

			switch (menu_selection)
			{
			case 1:
				Node p=head;
				printSLL(p);
				break;
			case 2: 
				Node q=head;
				printReverseSLL(q);
				break;
			case 3: 
				Node cur=head;
				reverseSLL(null,cur);
				break;
			case 4:
				break;
			}
			
		}
	}
	

	private static void reverseSLL(Node prev, Node cur) {
		if(cur!=null)
		{
			reverseSLL(cur,cur.link);
			cur.link=prev;
		}
		else
			head=prev;
		
	}


	private static void printReverseSLL(Node q) {
		if(q!=null)
		{
			printReverseSLL(q.link);
			System.out.println(q.data);
			
		}
		
	}

	private static void printSLL(Node p) {
		if(p==null)
			return;
		
		System.out.println(p.data);
		printSLL(p.link);
		
		
	}
	
	

	private static void insertAtFront(int newData) {
		Node newNode= new Node(newData);
		newNode.link=head;
		head=newNode;
		
		
	}

}
