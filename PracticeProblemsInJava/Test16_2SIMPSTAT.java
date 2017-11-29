import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Test16_2SIMPSTAT {
	public static class MinHeap {
		int heapsize;
//		int[] heap;
		MinHeap(int size) {
			this.heapsize=size;
//			heap=new int[size];
		}
		
		private void makeMinHeap(int[] heap) {
			int internalNode=heapsize/2-1;
//			System.out.println("internalNode"+internalNode);
			while(internalNode>=0) {
				minHeapify(internalNode,heap);
				internalNode--;
			}
		}

		private void minHeapify(int index,int[] heap) {
			if(index>=0 && index<heapsize) {
				int left=index*2+1;
				int right=index*2+2;
				int smallest=index;
				if(left<heapsize && heap[smallest]>heap[left])
					smallest=left;
				if(right<heapsize && heap[smallest]>heap[right])
					smallest=right;
				if(smallest<heapsize && smallest!=index) {
					//swap smallest and index and call minheapify
					int temp=heap[index];
					heap[index]=heap[smallest];
					heap[smallest]=temp;
					minHeapify(smallest,heap);
				}
			}
			
		}
		
		private int extractMin(int[] heap) {
			int extraction=heap[0];
			heap[0]=heap[heapsize-1];
			heapsize--;
			minHeapify(0,heap);
			return extraction;
		}
		
		
	}
	public static class MaxHeap {
		int heapsize;
//		int[] heap;
		MaxHeap(int size) {
			this.heapsize=size;
//			heap=new int[size];
		}
		
		private void makeMaxHeap(int[] heap) {
			int internalNode=heapsize/2-1;
//			System.out.println("internalNode"+internalNode);
			while(internalNode>=0) {
				maxHeapify(internalNode,heap);
				internalNode--;
			}
		}
		private void maxHeapify(int index,int[] heap) {
			if(index>=0 && index<heapsize) {
				int left=index*2+1;
				int right=index*2+2;
				int largest=index;
				if(left<heapsize && heap[largest]<heap[left])
					largest=left;
				if(right<heapsize && heap[largest]<heap[right])
					largest=right;
				if(largest<heapsize && largest!=index) {
					//swap smallest and index and call minheapify
					int temp=heap[index];
					heap[index]=heap[largest];
					heap[largest]=temp;
					maxHeapify(largest,heap);
				}
			}
			
		}
		
		private int extractMax(int[] heap) {
			int extraction=heap[0];
//			System.out.println("extractMax heapsize"+heapsize);
			heap[0]=heap[heapsize-1];
			heapsize--;
			maxHeapify(0,heap);
			return extraction;
		}
	}
	
	public static void main(String[]args) throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++) {
			StringTokenizer st=new StringTokenizer(br.readLine());
			int num=Integer.parseInt(st.nextToken());
			int k=Integer.parseInt(st.nextToken());
			st=new StringTokenizer(br.readLine());
			int[] arr=new int[num];
			
			for(int i=0;i<num;i++) {
				arr[i]=Integer.parseInt(st.nextToken());
			}
			MinHeap min_h=new MinHeap(num);
			min_h.makeMinHeap(arr);
			
			for(int j=0;j<k;j++) {
				int e=min_h.extractMin(arr);
				num--;
//				System.out.println("extrated: "+e+" arrSize: "+num);
			}
//			for(int l=0;l<num;l++) {
//				System.out.println(arr[l]);
//			}
			MaxHeap max_h=new MaxHeap(num);
			max_h.makeMaxHeap(arr);
//			for(int l=0;l<num;l++) {
//				System.out.println(arr[l]);
//			}
			for(int l=0;l<k;l++) {
				int e=max_h.extractMax(arr);
				num--;
//				System.out.println("extrated: "+e+" arrSize: "+num); 
			}
			
			double sum=0;
			for(int x=0;x<num;x++) {
//				System.out.println(arr[x]);
				sum+=arr[x];
			}
			double avg=sum/num;
			System.out.println(avg);
		}
	}
}
