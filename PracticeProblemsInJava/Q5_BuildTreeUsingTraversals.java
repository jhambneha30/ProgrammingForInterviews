
class Q5_BuildTreeUsingTraversals {
	
	
	
	static TreeNode buildTree(int in[],int post[],int len)
	{
		int postIndex=len-1;
		TreeNode root=buildTreeUtil(in,post,0,len-1,postIndex);
		return root;
	}
	
	static TreeNode buildTreeUtil(int in[],int post[],int inStart, int inEnd,int postIndex)
	{
		if(inStart>inEnd)
			return null;
		TreeNode newNode=new TreeNode(post[postIndex]);
		postIndex--;
		if(inStart==inEnd)
			return newNode;
		
		int inIndex=searchInInorder(in, inStart, inEnd, newNode.data);
		newNode.right=buildTreeUtil(in,post,inIndex+1,inEnd,postIndex);
		newNode.left=buildTreeUtil(in,post,inStart,inIndex-1,postIndex);
		return newNode;
	}
	
	private static int searchInInorder(int[] in, int inStart, int inEnd, int data) {
		int i;
		for(i=inStart;i<=inEnd;i++)
		{
			if(in[i]==data)
				break;
		}
		return i;
	}
	
	static void preOrder(TreeNode root)
	{
		if(root!=null)
		{
			System.out.println(root.data);
			preOrder(root.left);
			preOrder(root.right);
		}
		else return;
	}

	public static void main(String[]args) {
		int in[] = new int[]{4, 8, 2, 5, 1, 6, 3, 7};
        int post[] = new int[]{8, 4, 5, 2, 6, 7, 3, 1};
        int n = in.length;
        TreeNode root=buildTree(in,post,n);
        preOrder(root);
	}
}
