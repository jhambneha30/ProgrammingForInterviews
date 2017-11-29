/* Search an element in row wise and column wise sorted 2d array
==============================================================================================
Method 1: Linear search in n*n 2-D array
TC=O(n^2)
==============================================================================================
Method 2: Use Divide and Conquer
Example: 4*4 matrix is as follows:
			I 		  II
		10	20	|  22	24
		15	25	|  35	45
		-------------------
		16	29	|  37	48
		18	33	|  39	50
			III		  IV

Here, middle element x=25, as mid=(4/2,4/2)=(2,2)
If a is the element to be searched, then there are 3 cases:
Case 1. If(a==x), we found the required element
Case 2. If(a<x), then a can be present in the I, II and III quadrants.
Case 3. If(a>x), then a can be present in the II, III and IV quadrants.

Thus we have broken down thw problem such that
T(k)=3T(k/4)+O(1) = O(k^(log3 base 4))   ------------------------(1)
Note: One of the quadrants can be eliminated just by one comparison every time =>O(1) extra time
(as mentioned in the above equation)

Now, if k=n^2, then TC=O(n^1.58) (substitute n^2 in eqn (1))
SC=O(1)
==============================================================================================
Method 2: 

*/

#include <stdlib.h>
#include <stdio.h>
#define COUNT 4

int search(int matrix[COUNT][COUNT],int fromRow,int toRow,int fromCol, int toCol,int item)
{
	int mid_row,mid_col,res;
	mid_row=(fromRow+toRow)/2;
	mid_col=(fromCol+toCol)/2;
	if(matrix[mid_row][mid_col]==item)
	{
		printf("Found item @:(%d,%d)\n",mid_row,mid_col);
		return 1;
	}

	// if(fromRow==toRow && fromCol==toCol)
	// 	return -1;

	//II quadrant is searched in all cases
	// Provided it is different from current call
	if(mid_row!=toRow && mid_col!=fromCol)
		return search(matrix,fromRow,mid_row,mid_col+1,toCol,item);
	
	// If middle key is lesser then search lower horizontal 
    // matrix and right hand side matrix
    //And call lower horizontal matrix only if it exists
	if(item<matrix[mid_row][mid_col] && mid_row+1<=toRow)
	{
		return search(matrix,mid_row+1,toRow,fromCol,toCol,item);
	}

	// If middle key is greater then search left vertical 
    // matrix and right hand side matrix
    //And call left vertical matrix only if it exists
	if(item>matrix[mid_row][mid_col] && mid_col<=mid_col-1)
	{
		return search(matrix,fromRow,toRow,fromCol,mid_col-1,item);
	}

	return -1;
	
}

int main()
{
	int arr2d[COUNT][COUNT]={{10, 20, 30, 40}, 
			                 {15, 25, 35, 45},
			                 {27, 29, 37, 48},
			                 {32, 33, 39, 50}};
	int key =48;
	int res=search(arr2d,0,COUNT-1,0,COUNT-1,key);
	if(res==-1)
		printf("Key not found!\n");
}
