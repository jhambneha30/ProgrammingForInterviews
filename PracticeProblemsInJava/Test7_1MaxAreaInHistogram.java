/*
 * 
 * =================Stack Algorithm===========================
 * 1. Add to stack if current value is greater than or equal to top of stack OR if stack is empty.
 * 2. Otherwise if current value is smaller than the top of stack, then keep removing
 * from the stack till a number smaller than or equal to current value is found.
 * 			Calculate area every time the element is removed using below rules:
 * 			if(stack is empty)	
 * 				area=hist[top]*i;
 * 			else
 * 				area=hist[top]*(i-stack[top]-1;
 * 
 *===========================================================
 *Note1: We push the indices of the bars onto the stack rather than the bar heights!
 *Note2: The area is calculated in a different way when the stack is empty because, the last element in
 *the stack has to be the min element (min bar height) in the histogram array. So, we check at the end if
 *the area of the rectangle formed by taking the height equal to min height in every bar (min_bar_ht*array_size)
 *is greater than the max area calculated till now.
 */
import java.io.*;
import java.util.*;

public class Test7_1MaxAreaInHistogram {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc=Integer.parseInt(br.readLine());
		for(int t=0;t<tc;t++)
		{
			int size=Integer.parseInt(br.readLine());
			StringTokenizer st=new StringTokenizer(br.readLine());
			int arr[]=new int[size];
			int arr_dup[]=new int[size];
			for(int i=0;i<size;i++)
			{
				arr[i]=Integer.parseInt(st.nextToken());
				arr_dup[i]=arr[i];
			}
			
			int maxArea=maxAreaInHistUsingStack(arr,size);
			System.out.println("Max area using stack method is:"+ maxArea);
			Arrays.sort(arr_dup);
			int min,max_area=-1;
			int curr_area=0;
			for(int i=0;i<size;i++)
			{
				min=arr_dup[i];
				curr_area=0;
				for(int j=0;j<size;)
				{
					curr_area=0;
					if(arr[j]>=min)
					{
						while(j<size && arr[j]>=min)
						{
							curr_area+=min;
							j++;
						}
						if(curr_area>max_area)
							max_area=curr_area;
//						System.out.println("max area:"+max_area);
					}
					else
						j++;
						
				}
						
			}
			System.out.println(max_area);
		}
	}

	private static int maxAreaInHistUsingStack(int[] hist, int size) {
		Stack<Integer> st=new Stack();
		int curr_area, max_area=-1;
		int i;
		for(i=0;i<size;)
		{
			if(st.isEmpty() || hist[i]>=hist[st.peek()])
			{
				st.push(i);
				i++;
			}
			else
			{
				//Keep removing from stack while we don't get an element >= current element
				while(!st.isEmpty() && hist[i]<hist[st.peek()])
				{
					int popped_ht=hist[st.pop()];
					curr_area= popped_ht * (st.isEmpty()?i:(i-st.peek()-1));
					if(curr_area>max_area)
						max_area=curr_area;
				}
				System.out.println("max__Area: "+max_area);
			}
		}
		
		while(!st.isEmpty())
		{
			int popped_ht=hist[st.pop()];
			curr_area= popped_ht * (st.isEmpty()?i:(i-st.peek()-1));
			if(curr_area>max_area)
				max_area=curr_area;
		}
		
		return max_area;
	}
}
