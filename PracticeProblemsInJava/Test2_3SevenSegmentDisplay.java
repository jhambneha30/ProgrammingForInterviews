import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test2_3SevenSegmentDisplay {
	static int[] sevenSegHM=new int[10];
	public static void main(String[]args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int tc;
		tc=Integer.parseInt(br.readLine());
		sevenSegHM[0]=6;
		sevenSegHM[1]=2;
		sevenSegHM[2]=5;
		sevenSegHM[3]=5;
		sevenSegHM[4]=4;
		sevenSegHM[5]=5;
		sevenSegHM[6]=6;
		sevenSegHM[7]=3;
		sevenSegHM[8]=7;
		sevenSegHM[9]=5;
		for(int z=0;z<tc;z++)
		{
			int digits=Integer.parseInt(br.readLine());
			int num=Integer.parseInt(br.readLine());
			int numSegments=countSegments(num);
			System.out.println(numSegments);
			if(digits==1)
				System.out.println(num);
			else
			{
				for(int i=0;i<digits;i++)
				{
					for(int j=0;j<=9;j++)
					{
						int val=sevenSegHM[j];
						int rem=numSegments-val;
						int remainingNumDigits=digits-i-1;
						if(rem>=2*remainingNumDigits && rem<=7*remainingNumDigits)
						{
							numSegments-=val;
							System.out.print(j);
							break;
						}
					}
				}
			}
			
		}
	}
	
	static int countSegments(int n)
	{
		int count=0;
		while(n>0)
		{
			int rem=n%10;
			count+=sevenSegHM[rem];
			n=n/10;
		}
		return count;
	}
}
