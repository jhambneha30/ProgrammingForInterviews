/*Even Length substring such that sum of first half is equal to second half:
Que: Given a string of digits, find length of the longest substring such that the length of the
substring is 2k digits and sum of the left k digits =sum of right k digits.

Method 1: Brute force
Considering n is even,
Find out all the substrings of lengths: 2,4,6,8...
#substrings of length 2: n-1
#substrings of length 4: n-3
.
.
#substrings of length n:1
Summing: we get total n^2 sub strings approx.

Similarly, if n is odd, number of substrings = O(n^2) approx.

We can start with the substrings of size n and keep checking if any of these has 
sum of first half (first k digits)=sum of second half (second k digits). If yes, we return the 
size of this susbstring =2k. -O(n) to check a substring

TC=O(n^2 *n)=O(n^3)
===============================================================================================
Method 2: Using DP
If we store the sum of substrings in a table, then we can compute the result in O(n^2) time 
and space.

1. Build a table with n+1 rows and n+1 columns. This table will be filled only at the cells 
where i<=j
2. Fill the diagonal elements (0,0),(1,1).... with the values at indices 0,1... in the given 
string.
3. Fill the remaining table using 3 variables such that:
table[i][j]=table[i][(i+j)/2]+table[(i+j)/2  +1][j]
if(length of substring:l is even && table[i][(i+j)/2]==table[(i+j)/2  +1][j] && l>max_len)
	max_len=l;


TC=SC= O(n^2)
http://www.geeksforgeeks.org/longest-even-length-substring-sum-first-second-half/

*/