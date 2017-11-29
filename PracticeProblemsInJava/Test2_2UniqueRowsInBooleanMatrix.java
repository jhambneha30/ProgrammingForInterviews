import java.io.IOException;

public class Test2_2UniqueRowsInBooleanMatrix {
	public static void main(String[]args) throws IOException
	{
		int r=3,c=4;
		int a[][]={{1,1,0,1},{1,0,0,1},{1,1,0,1}};
		int[] hash_map=new int[r];
        int flag=0;
        for(int i=0;i<r;i++)
        {
            for(int z=i+1;z<r;z++)
            {
            	flag=0;
            	for(int j=0;j<c;j++)
            	{
            		if(a[i][j]!=a[z][j])
            		{
            			flag=1;
            			break;
            		}
            			
            	}
            	if(flag==0)
            	{
            		hash_map[z]=1;
            	}
                
            }
        }
        
        for(int k=0;k<r;k++)
        {
        	if(hash_map[k]==0)
        	{
        		//Print row;
        		for(int y=0;y<c;y++)
        		{
        			System.out.print(a[k][y]+" ");
        		}
        		System.out.print("$");
        	}
        }
	}
}
