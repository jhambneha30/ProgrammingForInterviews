/* OPTIMAL MERGE PATTERN~~~~~~~~(similar to) HUFFMAN CODING
This problem also gives a solution to MINIMUM WEIGHTED EXTERNAL PATH LENGTH 
Minimize the record movement while merging the recors and the final file should 
contain sorted records.
Example:

FILES------		a 	b 	c
RECORDS----		10	20	30

Minimum movements = 10+20+60=90 = MINIMUM WEIGHTED EXTERNAL PATH LENGTH 
= Summation(Path length*number of records)

================================Algorithm:===================================
OMP(files) //C is the set of all characters and c refers to one character
{
	n=|files|;
	Make a min-heap 'Q' for files according to the number of records - Build heap-O(n)
	while(i=1 to n-1)                -O(n) * 3*log n=O(nlogn)
	{
		1. Allocate a new node z
		2. z.left=x=extract_min(Q); - O(logn)
		3. z.right=y=extract_min(Q); - O(logn)
		4. z.records=x.records+y.records;
		5. insert(Q,z);              - O(logn)
	}
	return extract_min(Q);

}
==============================================================================
TC=O(nlogn)
SC=space taken by tree=O(n) in worst case

NOTE: MINIMUM WEIGHTED EXTERNAL PATH LENGTH = Summation(Path length*number of records)
This means that we make sure that the file with the minimum number of records move the greater
number of steps, so that the record movements are minimized! So, the larger file is kept as
close as possible to the root of the tree.
*/