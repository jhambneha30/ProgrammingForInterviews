/*Word breaking problem: A sentence is given without spaces. Break the sentence into words 
such that the words are meaningful. A dictionary in the form of a hash table is given in which
the keys are the words.
==============================================================================================
Method 1: Brute force
We can insert space after any letter and there are (n-1) places where the spaces can be 
inserted.
Since we have two choices: either we can insert a space or we can skip inserting space =>
possible combinations=O(2^(n-1)).

Now, in worst case, there will be space after every letter =>O(n) time will be taken to 
search them in the hash table dictionary.

TC=O(2^n * n)
==============================================================================================
Method 2: Using DP
We can add the spaces at any of the (n-1) slots at level 1,
Then at next level, we can again add the spaces anywhere in the smaller string and so on.
Refer to the recursion tree in the q13_wordBreakingProblem.png
We notice that the sub problems are repeating in the recursion tree.

So, we find out the number of unique subproblems:
If the problem is valid(i,j), then i,j can take values as:
i:1, j:2 to n =>n
i:2, j:3 to n =>n-1
i:3, j:4 to n =>n-2
.
.
i:n-1, j:n    =>1
Summing:      =>n + (n-1) +(n-2) +....1 = O(n^2) unique subproblems!
THUS, using tabular/memoization method, the solution can be built using DP.
*/