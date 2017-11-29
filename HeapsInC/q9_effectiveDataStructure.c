/* Consider  an application that has a huge number of insert operations but only a few 
remove the maximum operations. Which priority queue implementation would be most effective?

Solution:
				Max heap		Unordered array			Ordered array
1. insert   |  	O(log n)			O(1)					O(n)
2. Delete max|  O(1)				O(n)					O(1)

Best data structure to go with is unordered array as the insert operations are going to be large
in number and delete operations will be few!
*/