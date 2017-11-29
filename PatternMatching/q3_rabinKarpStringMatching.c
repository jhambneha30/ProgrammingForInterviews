/* RABIN KARP STRING MATCHING 

1. Find out the hash value on the pattern using some hash function.
2. For every substring of the text of size=size of pattern, generate its hash
value. If the hash value is same as that of the hash value of the pattern, then 
there is a chance that it might be the same substring as the pattern. But we can't
be sure unless we compare the substring and the pattern. 
Reason: Two strings might have same hash values.

TC=time taken to calculate hash values for all substrings=
O(n-m)* O(m)

But we can reduce the time O(m) to find out the hash value of one substring
by using the hash values computed for previous substrings and then manipulating
them. Doing this, reduces the O(m) time to O(1). =>TC=O(n) to find hashes for
the substrings of the text and O(m) to find hash value for pattern.

TC=O(n+m)
*/