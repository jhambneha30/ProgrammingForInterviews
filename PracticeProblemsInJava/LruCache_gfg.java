//import java.lang.*;
//import java.util.*;
//import java.io.*;
//
//
///*You are required to complete below class */
//public class Node {
//	int data;
//	TNode next;
//	TNode prev;
//	Node(int d)
//	{
//		data=d;
//		next=null;
//		prev=null;
//	}
//}
//	 class HashCell {
//		int value;
//		TNode ptr;
//		public HashCell(int v) {
//			value=v;
//			ptr=null;
//		}
//	}
//	 class DoubleLinkedList {
//		private TNode head;
//		private TNode tail;
//		private int numNodes;
//		DoubleLinkedList() {
//			numNodes=0;
//		}
//		public boolean isDLLEmpty()
//		{
//			return (head==null);
//		}
//
//		public int getNodeCount() {
//			return numNodes;
//		}
//		//The head of the DLL points to the MRU block
//		public TNode insertNodeAtStart(int block) {
//			TNode newNode=new TNode(block);
//			if(head==null)
//			{
//				head=newNode;
//				tail=newNode;
////				System.out.println("First node added");
//			}
//			else
//			{
//				newNode.next=head;
//				head.prev=newNode;
//				head=newNode;
//			}	
//			numNodes++;
//			return newNode;
//		}
//
//		//The tail points to the LRU block
//		public int deleteFromEnd() {
//			int block=-1;
//			if(head!=null && head==tail) {
//				block=tail.data;
//				head=null;
//				numNodes--;
//				
//			}
//			else if(head!=null && head!=tail) {
//				block=tail.data;
//				tail=tail.prev;
//				tail.next=null;
//				numNodes--;
//			}
//			return block;
//		}
//		public void searchNodeAndPlaceAtStart(int block, TNode ptr) {
//		    if(head==null || head.next==null)
//		    {
//		        return;
//		    }
//			if(head!=null && head.next!=null && ptr!=tail && ptr!=head) {
//				TNode ptr_prev=ptr.prev;
//				ptr_prev.next=ptr.next;
//				ptr.next=head;
//				ptr.prev=null;
//				head.prev=ptr;
//				head=ptr;
//			}
//			else if(ptr==tail) {
//				tail=tail.prev;
//				tail.next=null;
//				//ptr is a free node now, insert it at start
//				ptr.next=head;
//				ptr.prev=null;
//				head.prev=ptr;
//				head=ptr;
//			}
//// 			else
//// 				System.out.println(head==null?"LL empty":"LL has only one element");
//		}
//
//		public void searchNodeAndPlaceAtEnd(int block, TNode ptr) {
//			if(head!=null && head.next!=null && ptr!=tail && ptr!=head) {
//				TNode ptr_prev=ptr.prev;
//				ptr_prev.next=ptr.next;
//				ptr.next.prev=ptr_prev;
//
//				tail.next=ptr;
//				ptr.prev=tail;
//				ptr.next=null;
//				tail=ptr;
//			}
//			else if(ptr==head) {
//				head=head.next;
//				tail.next=ptr;
//				ptr.prev=tail;
//				ptr.next=null;
//				tail=ptr;
//			}
////			else
////				System.out.println(head==null?"LL empty":"LL has only one element");
//		}
//
//		public void traverseDLL() {
//			TNode ptr=head;
//			while(ptr!=null) {
//				System.out.print(ptr.data+"->");
//				ptr=ptr.next;
//			}
//			System.out.println();
//		}
//
//	}
//class LRUCache {
// 
//    int capacity;
//		int filled;
//		HashMap<Integer,HashCell> cache_hm;
//		DoubleLinkedList cacheBlocks;
//		/*Initialize an LRU cache with size N */
//		public LRUCache(int N) {
//			filled=0;
//			capacity=N;
//			cache_hm=new HashMap<Integer,HashCell>();
//			cacheBlocks =new DoubleLinkedList();
//
//		}
//
//		/*Returns the value of the key x if 
//	     present else returns -1 */
//		public int get(int x) {
//			if(cache_hm.containsKey(x))
//			{
//				int val= cache_hm.get(x).value;
////				System.out.println("Value in lru class: "+val);
////				System.out.println("Looking for block at:"+cache_hm.get(x).ptr);
//				cacheBlocks.searchNodeAndPlaceAtEnd(x, cache_hm.get(x).ptr);
//				return val;
//			}
//			else
//				return -1;
//
//		}
//
//		/*Sets the key x with value y in the LRU cache */
//		public void set(int x, int y) {
//			HashCell h=new HashCell(y);
//			if(filled<capacity) {
//				if(cache_hm.containsKey(x)) {
////					System.out.println("=======1(filled<cap & cache contains key=========");
//					cache_hm.replace(x, h);
//					cacheBlocks.searchNodeAndPlaceAtStart(x, cache_hm.get(x).ptr);
//				}
//				else {
////					System.out.println("=======2(filled<cap & cache NOT contains key=========");
//					h.ptr=cacheBlocks.insertNodeAtStart(x);
////					System.out.println("Storing block at:"+h.ptr);
//					cache_hm.put(x, h);
//					filled++;
//				}
//
//			}
//			else {
//				if(cache_hm.containsKey(x)) {
////					System.out.println("=======3(filled>=cap & cache contains key=========");
////					System.out.println("Looking for block at:"+cache_hm.get(x).ptr);
//					cacheBlocks.searchNodeAndPlaceAtStart(x, cache_hm.get(x).ptr);
//					HashCell temp=cache_hm.get(x);
//					temp.value=y;
//					cache_hm.replace(x, temp);
//				}
//				else {
//					//LRU is applied
////					System.out.println("=======4(filled>=cap & cache NOT contains key=========");
//					int block_num=cacheBlocks.deleteFromEnd();
//					if(block_num==-1)
//						System.out.println("No block at end returned!");
//					cache_hm.remove(block_num);
//					h.ptr=cacheBlocks.insertNodeAtStart(x);
////					System.out.println("Storing block at:"+h.ptr);
//					cache_hm.put(x, h);
//				}
//
//			}
//			
////			System.out.println("Updated DLL is:");
////			cacheBlocks.traverseDLL();
//		}
//}
