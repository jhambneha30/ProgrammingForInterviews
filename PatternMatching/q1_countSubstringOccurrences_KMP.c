/* Given a text and a pattern, Find all occurrences of pattern in a given text. OR
Find out all occurrences of string str2 in string str1.
Length of str1=m
Length of str2=n
============================================================================================
Method 1: Naive approach
1. Find all the substrings of size=sizeof(str2) and then compare each substring with str2.
2. Whenever there is a match, increment the count by 1.

TIME COMPLEXITY:
No. of substrings of size m = O(n-m+1)
Time taken for each substring comparison=O(m)
So, TC=O((n-m)*m)=O(nm-m^2)
TC=O(nm)
============================================================================================
Method 2:Using DFA (Deterministic Finite Automata)
1. Construct DFA ending with string s2.
2. Input str1 to the given DFA and count the number of times state 4 is reached.

TIME COMPLEXITY:
If we already have the DFA, time taken to process str1=O(n)
To build DFA, time taken=O(m^3 * |Σ|)
Note:|Σ|=No. of alphabets used in the DFA=constant
Thus, TC=O(m^3)+O(n)

Note: To build a DFA, we need m+1 states for a string of size m.
In the first state, any symbol can come=>every alphabet other than the first character of string,
will loop back to state 1.
Time=O(m*|Σ|) is required to build the base DFA and to add all the outgoing edges. 

Then, to decide where these outgoing edges should go, prefixes and suffixes need to be compared.
Thus m^2 time is required for each state.
Reason: No. of suffixes/prefixes *comparison between them=m*m=O(m^2)

No. of prefixes for string of size m = No. of suffixes for string of size m = m+1
=>TC=O(m^3 * |Σ|)
============================================================================================
Method 3:Knuth Morris Pratt/ KMP Algorithm
The time taken to build the DFA is reduced to O(m) from O(.m^3).

Building DFA in O(m):
1. Build the skeleton with derterministic transitions: O(1)
2. Number of transitions to be added to every state:
For first state, all the other transitions than the one which has already been decided, will
loop back to the same stage.

Now, for remaining states, we need to add (|Σ|-1) more transisitons => O(m *|Σ|)
3. Previously, adding |Σ|-1 more transitions at every state took O(m^2). KMP will reduce this
to O(1).
For this, build up a string which goes till the state (say s) on which we need to add other transitions.
Append the character on which the transition is to be decided to this string (say x).
Now, ignore the first character and the last character (on which the transition is to be decided)
and run (mimick) the remaining string on the DFA. Wherever we reach, check the transition of that state on
x. Add the same transition state on state s on character x.

We might feel that mimicking the string on the DFA everyime will multiply a factorof O(m) to 
the time already taken -> O(m*(|Σ|-1)) but actually, we can save the previous state in a table
to make it O(1) time.

If we follow this rule, we can add the transition states in O(m*(|Σ|-1)) time.

Thus time taken to build the DFA=O(1)+OO(m*(|Σ|-1)) =O(m) [|Σ| is a constant mostly]

KMP's TC=O(m+n); where m is the size of pattern and n is the size of the text in which the pattern
has to be searched!
---------------------------------------------------------------------------

http://www.geeksforgeeks.org/searching-for-patterns-set-5-finite-automata/

https://www.youtube.com/watch?v=GTJr8OvyEVQ&t=3s

http://www.geeksforgeeks.org/?p=11902

http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lps(char *str,int n,int table[])
{
	int i=1,j=0; //j keeps moving to indicate the LPS:longest proper prefix that is also a suffix! 
	table[0]=0;
	while(str[i])
	{
		if(str[i]==str[j])
		{
			j++;
			table[i++]=j;
		}
		else
		{
			if(j==0)
			{
				table[i++]=0;
			}
			else
			{
				j=table[j-1];
			}
		}
	}
}

void search_KMP(char *txt, char *pat)
{
	int txt_len=strlen(txt);
	int pat_len=strlen(pat);
	printf("Pattern Length: %d\n",pat_len);
	int lps_table[pat_len];
	lps(pat,pat_len,lps_table);

	int i,j=0;
	for(i=0;pat[i]!='\0';i++)
	{
		printf(" %d",lps_table[i]);
	}
	printf("\n");
	i=0;
	//Now, we start the search
	//i pointer for scanning the text and j for scanning the pattern
	while(i<txt_len)
	{
		if(txt[i]==pat[j])
		{
			i++;
			j++;
		}
		if(j==pat_len)
		{
			printf("Pattern found at %d\n",i-j);
			j=lps_table[j-1];
		}
		else if(i<txt_len && txt[i]!=pat[j])
		{
			// Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if(j!=0)
            	j=lps_table[j-1];
            else
            	i++;
		}
	}

}

int main()
{
	char *text = "ABABDABACDABABCABAB";
  	char *pattern = "ABA";
  	search_KMP(text,pattern);
	return 0;
}
