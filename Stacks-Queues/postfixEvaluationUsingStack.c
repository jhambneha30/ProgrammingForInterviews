/*POSTFIX EVALUATION:
Using the postfix expression to evaluate an expression takes O(n)
While evaluating infix expression might take O(n^2) or more time. So, most of the compilers use stack to evaluate
postfix expressions.

Only operands will be pushed onto the stack =>operand stack is used. Whenever, we come across an
operator, we'll check if it iis unary or binary and depending on that number of operands will be
popped. For unary, one operand is popped and for binary, two operands will be popped.

Note1: The operand popped first will be the second operand for this operator and the operand 
popped second will become the first operand. (In case of * or +, the order doesn't matter but 
the order matters for - and division.)
Note2: Every operand will go on to the stack atleast once.

Algorithm for postfix evaluation:
(i) Scan the postfix string from left to right.
(ii) Initialize an empty stack.
(iii) Repeat steps 4 and 5 till all the characters are scanned.
(iv) If the scanned character is an operand, push it onto the stack.
(v) If the scanned character is an operator, and if the operator is unary, then pop one element
from the stack.
	If the operator is binary, pop two elements from the stack.

After popping the elements, apply the operator to the popped elements.
Push the result onto the stack.

(vi) After all the elements are scanned, the result will be on the stack.

TC=SC=O(n)
*/

#include <stdio.h>   
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20
int stack[MAX];
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

int pop()
{
	int temp;
	if(top==-1)
	{
		printf("Underflow!");
		return -1;
	}
	temp=stack[top--];
	return temp;
}


void postfixEvaluation(char *ptr)
{
    int index=0,temp;
    char ch;
    while(*ptr)
    {
    	ch=*ptr;
    	if(isdigit(ch))
    	{
    		push(ch-'0');
    	}
    	else
    	{
    		int val2=pop();
    		int val1=pop();

    		switch(ch)
    		{
    			case '+':push(val1+val2);
    				// printf("Pushed value for ch=+: %d\n",val1+val2);
    			break;

    			case '-':push(val1-val2);
    			break;

    			case '*':push(val1*val2);
    			break;

    			case '/':push(val1/val2);
    			break;

    			default:
    				printf("Invalid character: %c\n",ch);

    		}
    	}
    	ptr++;
    }
    
}


int main()
{
	
	char expression[]="231*+9-";
    int size=sizeof(expression)/sizeof(expression[0]);
    postfixEvaluation(expression);
    printf("Result: %d\n",pop());

	return 0;

}