import java.io.IOException;
import java.util.*;
/*
 * http://practice.geeksforgeeks.org/problems/chinky-and-diamonds/0
 */
public class Q8_ChinkyMaxDiamonds {
	public static class Heap {
		int heapsize;
		Heap(int size) {
			heapsize=size;
		}
		
		void buildHeap(int arr[],int n)
		{
			int internalNode=n/2-1;
			while(internalNode>=0)
			{
				maxHeapify(arr,internalNode);
				internalNode--;
			}
		}
		
		boolean isLeaf(int pos)
		{
			if(pos>=heapsize/2 && pos<heapsize)
				return true;
			return false;
		}
		
		void maxHeapify(int heap_arr[],int index)
		{
//			System.out.println("index:"+ index+"arr[index]: "+heap_arr[index]);
			if(isLeaf(index)!=true)
			{
				int left=index*2+1;
				int right=index*2+2;
				int largest=index;
				if(left<heapsize && heap_arr[left]>heap_arr[largest])
					largest=left;
				if(right<heapsize && heap_arr[right]>heap_arr[largest])
					largest=right;
				if(largest<heapsize && index!=largest)
				{
					int temp=heap_arr[index];
					heap_arr[index]=heap_arr[largest];
					heap_arr[largest]=temp;
					maxHeapify(heap_arr,largest);
				}
			}
//			else
//				System.out.println("end of max heapify");
			
				
		}
		
		int returnMaxAndReduceKey(int heap_arr[])
		{
			int max=heap_arr[0];
			heap_arr[0]=heap_arr[0]/2;
			maxHeapify(heap_arr,0);
			return max;
			
		}
		
	}
	public static void main(String[]args) throws IOException
	{
		java.io.BufferedReader br=new java.io.BufferedReader(new java.io.InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int i=0;i<tc;i++)
		{
			StringTokenizer st =new StringTokenizer(br.readLine());
			int numBags=Integer.parseInt(st.nextToken());
			int k=Integer.parseInt(st.nextToken());
			int[] arr=new int[numBags];
			st=new StringTokenizer(br.readLine());
			for(int j=0;j<numBags;j++)
			{
				arr[j]=Integer.parseInt(st.nextToken());
			}
			Heap heap=new Heap(numBags);
			int len=arr.length;
			heap.buildHeap(arr,len);
			int max_diamonds=0;
			for(int x=0;x<k;x++)
			{
				max_diamonds+=heap.returnMaxAndReduceKey(arr);
			}
			System.out.println(max_diamonds);
		}
	}
}
