/*Check whether parenthesis balanced or not
Use a stack and keep popping the opening brackets.
Keep advancing the pointer and pop the opening brackeet if similar closing bracket is pointed.
If at the end stack contains any opening brakets=> Not balanced, otherwise balanced!
TC: Push+pop=O(1)*n=O(n)
SC=O(n)

*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20
char stack[MAX];
int top=-1;
void push(int item)
{
	if(top==MAX-1)
	{
		printf("Overflow!");
		return;
	}
	// top=top+1;
	stack[++top]=item;

}

char pop()
{
	char temp;
	if(top==-1)
	{
		printf("Underflow!");
		return -1;
	}
	temp=stack[top--];
	return temp;
}

int isMatchingPair(char a,char b)
{
	if(a=='(' && b==')')
		return 1;
	if(a=='{' && b=='}')
		return 1;
	if(a=='[' && b==']')
		return 1;
	return 0;

}


int checkBalancing(char *ptr)
{
    char ch,temp;
    while(*ptr)
    {
    	ch=*ptr;
    	if(ch=='[' || ch=='{' || ch=='(')
    	{
    		push(ch);
    		printf("Pushing: %c\n",ch);
    		ptr++;
    	}
    	else if(ch==']' || ch=='}' || ch==')')
    	{
    		temp=pop();
    		printf("Popped: %c, Current: %c\n",temp,ch);
    		if(isMatchingPair(temp,ch) && ptr)
    		{
    			printf("Matched\n");
    			ptr++;
    		}
    		else
    			return 0;
    	}
    }
    return 1;
    
}


int main()
{
	
	char expression[]="[]()[{}]";
    int size=sizeof(expression)/sizeof(expression[0]);
    int res=checkBalancing(expression);
    if(res)
    	printf("Balanced\n");
    else
    	printf("Not balanced!\n");
    

	return 0;

}