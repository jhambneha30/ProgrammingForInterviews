/*HUFFMAN CODING/ VARIABLE SIZED ENCODING

we give the smallest code to the character ooccuring max number of times 
in a file, to reduce/compress the file size. For this, we use "prefix encoding".

Example:
Character   Frequency		Code
	a			50			0
	b			40			10
	c 			5 			110
	d			5 			111

Total bits used=1*50+2*40+3*5+3*5=160 (This is also the MINIMUM WEIGHTED EXTERNAL PATH LENGTH 
possible)
Bits used in fixed encoding=2*100=200

In prefix encoding, it is made sure that none od the codes is a prefix to another code.
To ensure this, the construction of the tree is done in such a way that the characters are 
always at the leaves. This will make sure that no other character follows the same path as 
any other character.

================================Algorithm:===================================
Huffman(C) //C is the set of all characters and c refers to one character
{
	n=|C|;
	Make a min-heap 'Q' for C according to the frequencies of the characters. - Build heap-O(n)
	while(i=1 to n-1)                -O(n) * 3*log n=O(nlogn)
	{
		1. Allocate a new node z
		2. z.left=x=extract_min(Q); - O(logn)
		3. z.right=y=extract_min(Q); - O(logn)
		4. z.freq=x.freq+y.freq;
		5. insert(Q,z);              - O(logn)
	}
	return extract_min(Q);

}
==============================================================================
Note: During the execution of the problem, we might even get a forest. It is not necessary 
that we get a singke tree and we keep growing it.
Note: The most expensive step is 2nlogn taken by extract min

TC=O(nlogn)
SC=space taken by tree=O(n) in worst case

Que: Why did not we use sorting algo to sort the elements rather than using heap
Ans: Because after every tqo extractions, we need to insert an element again, after which 
we again need min element. Heap  automatically adjusts itself to bring min to the top
whenever an element is inserted. While if we use sorting algo after every insert, then time
taken is O(nlogn)*n=O(n^2logn) which is worse.
		In case of Knapsack problem, we do not put back anything into the array, we just 
extract the max. So, we can do without using heaps. But here using heaps improves the TC by 
a factor of O(n).
*/