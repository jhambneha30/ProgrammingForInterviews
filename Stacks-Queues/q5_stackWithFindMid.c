/*Implement stack with push ,pop, find middle element, delete middle element in 0(1)

Method 1:
Using array:
Push: The problem occurs when overflow occurs. Because array needs to be reallocated space.
For this, a bigger array needs to be declared and old elements have to be copied to this array.
So, overhead is involved.

Pop: O(1)
Find middle: In array, it is possible in O(1).
Delete middle: The elements need to be shifted =>half of the elements have to be moved=>O(n/2)=O(n)

Method 2:
Using Single LL:
Push and pop: O(1)

Find mid: For first time, finding mid takes O(n) time. But consequent find mid requests will
take O(1) time given that no operations like push and pop occur in between.
In case a push occurs, then we need to move the mid ptr to the left, which won't be possible in
a SLL.
=> For every mid request, find middle taking O(n) time.

Delete min: O(1) time

Method 3: Best method!
Using DLL
Push, pop: O(1) time

Find mid: Have a ptr pointing to the mid element (takes O(n) for first time).
Whenenever pop or push occurs, move to right or left respectively.

Delete mid: O(1) time

*/
