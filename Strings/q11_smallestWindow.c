/*Find the smallest window in a string s1 containing all characters of another string s2.
Example: 
s1: a string containing
s2: aig
possible windows: 
window1- a string, window2- ing conta, window3- aining
So, the smallest window is window3 with size 6.

Method 1: Naive approach
Find all possible windows and then filter out the windows containing s2. Then find the smallest
window out of these.

TC=O(n^2) to find all possible windows * O(n) to check if all the chars from s2 are present
or not using hash table =O(n^3)

SC=O(1) for hash table

Method 2: ---BEST METHOD
NOTE: THIS METHOD IS BETTER THAN THE Geeksforgeeks METHOD!
Examine only relevant windows, rather than examining all possible windows.
1. Replace all extra chars in s1 by white space.
2. Use a hash table to store the characters in the string s2 and keep the count of these characters.
3. Now we take left and right pointers which points to the beginning of s1 initially. Then, we 
move last till we have all the chars from s2 in our window. Simultaneously, while moving last,
keep updating the count of chars in the hash table by subtracting 1 each time a char is 
encountered.
As we find a window having all the required chars, we store the window size in a variable
min_windowSize and also store the start and end index of theis window.

4. Try to shrink the window by moving the left pointer till a char is found (skip the white spaces).
Go to hash table and increment the count for the character which is removed from the
window. Now, if the remaining required count<=0 => this char is still present in the window,
otherwise move the last pointer to find this char. Keep updating the hash table on the way.
When last pointer finds this char, then another window is found, wo we compare the size of this 
window with the min_windowSize. If this is smaller, update the min_windowSize, otherwise, repeat
step 4 till the \0 is encountered!

Since, every character is examined twice, once by right pointer and then by left ponter, so
TC=@*O(n)=O(n)
SC=O(1) for fixed size hash table.

Method 3:
1- First check if length of string (s1) is less than
   the length of given pattern (s2), if yes
       then "no such window can exist ".
2- Store the occurrence of characters of given 
   pattern in a hash_pat[].
3- Start matching the characters of pattern with 
   the characters of string i.e. increment count 
   if a character matches
4- Check if (count == length of pattern ) this 
   means a window is found
5- If such window found, try to minimize it by 
   removing extra characters from beginning of
   current window.
6- Update min_length.
7- Print the minimum length window.

http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 256
int hash_str[COUNT]={0};
int hash_pat[COUNT]={0};

int findSmallestWindow(char str[],char pat[],int *start, int *end)
{
	int i,left=0,right=0;
	int len_pat=strlen(pat),len_str=strlen(str),count=0;
	int minWindow=999999;

	while(pat[i])
	{
		hash_pat[pat[i]]++;
		i++;
	}

	while(str[right])
	{
		hash_str[str[right]]++;
		// If string's char matches with pattern's char
        // then increment count
		if(hash_pat[str[right]]!=0 && hash_pat[str[right]]>=hash_str[str[right]])
		{
			count++;
		}

		// if all the characters are matched
		if(count==len_pat)
		{
			//Minimize the window by removing extra chars if any
			while(hash_str[str[left]]>hash_pat[str[left]] || hash_pat[str[left]]==0)
			{
				if(hash_str[str[left]]>hash_pat[str[left]])
					hash_str[str[left]]--;
				left++;
			}

			//Update minWindow if required!
			if((right-left+1)<minWindow)
			{
				minWindow=right-left+1;
				*start=left;
				*end=right;
			}

		}

		right++;
	}
	return minWindow;
}

int main()
{
	// char str[]="this is a test string";
	// char pat[]="ing";

	char str[]="ty nama tan";
	char pat[]="ata";
	int smallestWindow,start,end;
	smallestWindow=findSmallestWindow(str,pat,&start,&end);
	int i=start;
	
	while(i<=end)
	{
		printf("%c",str[i]);
		i++;
	}
	printf("\nSmallest window size is: %d\n",smallestWindow);
	return 0;
}