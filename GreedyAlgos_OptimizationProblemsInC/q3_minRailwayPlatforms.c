/* NUMBER OF RAILWAY PLATFORMS:
What is the min number of platforms required so that the trains arriving at the station 
can stand there without colliding?
		TRAIN 				ARRIVAL TIME 				DEPARTURE TIME
		  A  					10:00						10:20
		  B						10:15						14:00
		  C 					10:30						15:00
		  D 					10:40						10:55
 Sort all the times: arrival as well as departure times. Now check the number of trains 
 at all these times and the number of platfoms required = max of these.
 Solution:
 										TIME LINE
 --------------------------------------------------------------------------------------------
 TIME-  10:00(A)	10:15(A)	10:20(D)   10:30(A)	10:40(A)	10:55(D)   2:00(D)	3:00(D)	
 #trains 1 			2 			1 			2 		  3 		  2 		1 		  0

 Minimum platforms required=3

 TC=O(nlogn) to sort + O(n) to count the trains = O(nlogn)
*/