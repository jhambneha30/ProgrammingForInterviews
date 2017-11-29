import java.util.*;
import java.lang.Integer;
import java.util.HashMap;
//import java.lang.Math;
import java.util.Queue;
import java.util.LinkedList;
import java.io.*;

// A Binary Tree CustomNode
class CustomNode
{
    int data;
    CustomNode left, right, nextRight;

    CustomNode(int item)
    {
        data = item;
        left = right = nextRight = null;
		
    }
}



class Test17_3ConnectLevelCustomNodes
{
void inorder(CustomNode CustomNode)
	{
		if(CustomNode==null)
			return ;
		else
			inorder(CustomNode.left);
			System.out.print(CustomNode.data + " ");
			inorder(CustomNode.right);
		
	}
	void printSpecial(CustomNode root)
	{
		if(root == null)
			return ;
		CustomNode CustomNode = root;
		while(CustomNode != null)
		{
			System.out.print(CustomNode.data+" ");
			CustomNode = CustomNode.nextRight;
		}
		if(root.left != null)
			printSpecial(root.left);
		else 
			printSpecial(root.right);
		
	}
	
	
	
	// driver function to test the above functions
    public static void main(String args[])
    {
		
        // Input the number of test cases you want to run
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        Test17_3ConnectLevelCustomNodes  can = new Test17_3ConnectLevelCustomNodes ();
		//CustomNode root=null;
		

        while (t > 0)
        {
            HashMap<Integer, CustomNode> m = new HashMap<Integer, CustomNode> ();
            int n = sc.nextInt();

            CustomNode root=null;

            while (n > 0)
            {
                int n1 = sc.nextInt();
                int n2 = sc.nextInt();
                char lr = sc.next().charAt(0);

                //  cout << n1 << " " << n2 << " " << (char)lr << endl;
                CustomNode parent = m.get(n1);
                if (parent == null)
                {
                    parent = new CustomNode(n1);
                    m.put(n1, parent);
                    if (root == null)
                        root = parent;
                }

                CustomNode child = new CustomNode(n2);
                if (lr == 'L')
                    parent.left = child;
                else
                    parent.right = child;
                m.put(n2, child);
                n--;
            }
		
            //GfG g = new GfG();
			
			connect(root);
			can.printSpecial(root);
			System.out.println();
			can.inorder(root);
			System.out.println();
         t--;
			
        }
    }
    
    public static void connect(CustomNode root)
    {
       // Your Code Here
    }
}