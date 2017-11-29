import java.io.*;
import java.util.*;

public class Q6_ReverseAlternateNodes {
	public static class LinkedList {
		Node head;
		int count;
		
		LinkedList()
		{
			head=null;
			count=0;
		}
		
		void inserNodeAtEnd(int data)
		{
			Node new_node=new Node(data);
			Node ptr=head;
			if(head==null)
			{
				head=new_node;
			}
			else
			{
				while(ptr.next!=null)
				{
					ptr=ptr.next;
				}
				ptr.next=new_node;
			}
		}
		
		void displayLL()
		{
			Node temp=head;
			while(temp.next!=null)
			{
				System.out.print(temp.data+"->");
				temp=temp.next;
			}
				
			System.out.println(temp.data);
		}
		
		void reverseLL()
		{
			Node prev=null,curr=head,curr_next=head.next;
			while(curr_next!=null)
			{
//				System.out.println(curr.data+" "+curr_next.data);
				curr.next=prev;
				prev=curr;
				curr=curr_next;
				curr_next=curr_next.next;
			}
			head=curr;
			head.next=prev;
		}
		
	}
	
	public static void main(String[]aregs) throws IOException {
		java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			int node_count=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			LinkedList ll=new LinkedList();
			for(int j=0;j<node_count;j++)
			{
				ll.inserNodeAtEnd(Integer.parseInt(st.nextToken()));
			}
			//create a new linked list with alternate nodes
			LinkedList ll_new=new LinkedList();
			ll_new.head=ll.head.next;
			Node ptr1=ll.head,ptr2=ll_new.head;
			while(ptr2.next!=null)
			{
				ptr1.next=ptr2.next;
				ptr1=ptr2.next;
				ptr2.next=ptr1.next;
				ptr2=ptr1.next;
			}
			ptr1.next=null;
			ptr2.next=null;
			ll.displayLL();
			ll_new.displayLL();
			ll_new.reverseLL();
			ll_new.displayLL();
			//Now, we append the new_ll afteer the old ll
			
			ptr1=ll.head;
			while(ptr1.next!=null)
			{
				ptr1=ptr1.next;
			}
			ptr1.next=ll_new.head;
			ll.displayLL();
		}
	}
}
