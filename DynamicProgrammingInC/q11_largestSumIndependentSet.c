/* Largest sum independent set or(largest sum independent set: LISS) in binary tree.
Independent nodes are those which are not adjacent. Independent set is one which does not 
contain adjacent nodes.
=============================================================================================
Method 1: Naive approach
1. For a binary tree, find all possible subsets: O(2^n)
2. Then, check if each of these is independent or not: O(n^2) algo as we need to check if each 
node is adjacent to each of the other nodes in the set.
3. After finding the independent sets, we need to find the set with maximum size: O(2^n)

TC=O(2^n * n^2) => exponential
=============================================================================================
Method 2: Using DP

----------------------------Optimal Substructure:---------------------------------------
Let LISS(X) indicates size of largest independent set of a tree with root X.

     LISS(X) = MAX { (1 + sum of LISS for all grandchildren of X),
                     (sum of LISS for all children of X) }
The idea is simple, there are two possibilities for every node X, either X is a member of 
the set or not a member. If X is a member, then the value of LISS(X) is sum of this node
plus LISS of all grandchildren. If X is not a member, then the value is sum of LISS of 
all children.

----------------------------Recursive Equation:-----------------------------------------
LISS(root)		|LISS(root->left) + LISS(root->right)   ;if root is not included
		  =max  |LISS(root->left->left)+LISS(root->left->right)+
		  			LISS(root->right->left)+LISS(root->right->right) ;if root is included

-----------------------------Repeating subproblems:-------------------------------------------
It should be noted that the above function computes the same subproblems again and again. 
For example, LISS of node with value 50 is evaluated for node with values 10 and 20 as 50 
is grandchild of 10 and child of 20.

BinaryTree is: 
struct node *root             = newNode(10);
    root->left                = newNode(20);
    root->left->left          = newNode(40);
    root->left->right         = newNode(50);
    root->left->right->left   = newNode(70);
    root->left->right->right  = newNode(80);
    root->right               = newNode(30);
    root->right->right        = newNode(60);

Thus, we can apply DP to compute the result as we can store the subproblem's result and later 
use it.
 

*/

#include <stdio.h>
#include <stdlib.h> 

struct node{
    int data;
    int ls;
    struct node *left, *right;
};

int max(int a,int b){ return (a>b)?a:b; }

struct node *newNode(int data)
{
    struct node *new=(struct node *)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    new->ls=0;
    return new;
}

int lsis(struct node *root)
{
    int sum_excl=0, sum_incl;
    if(!root)
        return 0;

    if(root->ls)
        return root->ls;

    if(!root->left && !root->right)
        return (root->ls=root->data);

    //Calculate sum excluding the current node
    sum_excl+=lsis(root->left)+lsis(root->right);

    //Calculate sum including the current node
    sum_incl=root->data;
    if(root->left)
        sum_incl+=lsis(root->left->left)+lsis(root->left->right);
    if(root->right)
        sum_incl+=lsis(root->right->left)+lsis(root->right->right);

    root->ls=max(sum_excl,sum_incl);
    return root->ls;

}

int main()
{
    struct node *root         = newNode(10);
    root->left                = newNode(20);
    root->left->left          = newNode(40);
    root->left->right         = newNode(50);
    root->left->right->left   = newNode(70);
    root->left->right->right  = newNode(80);
    root->right               = newNode(30);
    root->right->right        = newNode(60);

    int largestSum= lsis(root);
    printf("Sum of largest independent set= %d\n",largestSum);
    return 0;
}
