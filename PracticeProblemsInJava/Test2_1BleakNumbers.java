/*
 * The idea is based on the fact that the largest count of set bits in 
any number smaller than n cannot exceed ceiling of Log2n. So we need to check 
only numbers from range n – ceilingLog2(n) to n.
 *  ===========Algorithm===========
	bool isBleak(n)
	1) Consider all numbers n - ceiling(Log2n) to n-1
	    a) If x + countSetBits(x) == n
	           return false
	
	2) Return true
	
This is because the number of bits in the last power of 2 has to be 1 less than the
log of this number. Therefore we subtract the log of this number from the number itself
and check for the remaining numbers.
Example:
log2(10)=4
10-4+1=7
Now, only the numbers after 7 have the possibility of being responsible for a number 
to be bleak.
======================================IMPORTANT===============================	
NOTE: To take log to the base 2 in java:
int res=(int)Math.log(num)/Math.log(2);
 */

import java.io.*;


public class Test2_1BleakNumbers {
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc;
		tc=Integer.parseInt(br.readLine());
		for(int z=0;z<tc;z++)
		{
			int flag=0;
			int num=Integer.parseInt(br.readLine());
			
			boolean res=isBleak(num);
			
//			System.out.println("fLAG IS:"+flag);
			if(res==true)
				System.out.println(1);
			else
				System.out.println(0);
		}
	}
	
	static boolean isBleak(int num)
	{
		int start=num-(int)Math.ceil(Math.log(num)/Math.log(2));
//		System.out.println("ceil"+start);
		for(int i=start+1;i<num;i++)
		{
			int setBits=countSetBits(i);
//			System.out.println("i:"+i+" setBits:"+setBits);
			if(i+setBits==num)
			{
				return false;	
			}
				
		}
		return true;
	}
	
	static int countSetBits(int num)
	{
		int count=0;
		int rem;
		int q=num;
		while(q!=0)
		{
			rem=q%2;
			if(rem==1)
				count++;
			q=q/2;
		}
		return count;
	}
}
