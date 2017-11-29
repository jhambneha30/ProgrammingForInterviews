/*BOYER-MOORE string matching
In this, we search the pattern from right to left.


This algorithm gives a better performance when the type of characters in the
text are varied. In such a case, the pointer scanning the text moves past most
of the charcters (makes long jumps as the whole window needs to be moved) and 
so the TC reduces many fold.

Suppose we have binary numbers as the characters {0,1}, then this algo might not 
give good performance as the pointer won't be able to make long jumps as the
no. of mismatches will be very less. So, we can opt for KMP!

Preprocessing: Make a hash table which contains the positions of the last
occurence of each character in the pattern.
Using this hash, we can directly compute the number of shifts required
in case of a mismatch.

Whenenever there is a mismatch, we check if the mismatched character is present
in the pattern or not by using the hash table.
Case 1: If not present, move the entire window past this mismatched character.
It means move the window by size of pattern
Case 2: If it is present in the pattern, then 
shifts required = position in pattern where comparison is taking place-
					position of mismatched character as in the hash table

Thus, the shifts can be computed in O(1) time.

NOTE: IF THE NO. OF SHIFTS REQUIRED COMES OUT TO BE A NEGATIVE NUMBER,
THEN MOVE THE WINDOW PAST THE MISMATCHED CHARACTER I.E. MOVE THE WINDOW RIGHT
BY 1.

TIME COMPLEXITY:
Worst case: when we have to move the pattern window by just one character:
we need to do O(mn) comparisons.
TC=O(mn)

Best Case: Everytime the pattern window moves by its own size.
TC=O(n/m)
sc=O(no. of sumbols)
http://www.geeksforgeeks.org/pattern-searching-set-7-boyer-moore-algorithm-bad-character-heuristic/
*/