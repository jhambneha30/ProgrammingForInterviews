/*Stack is used to convert an infix expression to postfix expression. We need
to build an operators stack. Operands will never be pushed onto this stack.
Examples:  
1.) a+b*c to abc*+ (* has higher precedence than +) 
2.) a+b-c to ab+c- (because + and - have equal presedence, so associativity is considered.

They are left associative, so first ab+ is computed and then ab+c-) 3.)
a+(b-c) to abc-+ (because, parenthesis has highest precedence) Note: [+ < (]
and [+ > (  )]. This means that the opening parenthesis has higher precedence
than the operator lying outside. While the opening parenthesis has lower
precedence than the  operator inside it.

Note1: Closing parenthesis will never be pushed onto the stack.
Note2: Left or right parenthesis will never be printed in the output.

ALgorithm: Let size of expression=n
(i) Create a stack. Largest stack will contain all operators in the expression sc=o(n)
(ii) For each character 't' in the input
    if(t is an operand)
        output t
    else if(t is a right parenthesis)
    {
    pop and output operators till the left parenthesis is popped out (but don't output)
    }
    else // t is an operator or left parenthesis
    {
        Pop and output the tokens until one of the lower priority tokens than t is encountered
        or stack gets empty.
    }

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

int priority(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
}

void infixToPostfix(char expr[],int n)
{
    int index=0,temp;
    char ch;
    while(index<n)
    {
        ch=expr[index];
        if(isalnum(ch))
        {
           printf("%c ",ch); 
        }
        else if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while((temp=pop())!='(')
            {
                printf("%c ",temp); 
            }
        }
        else
        {
            if(priority(stack[top])>=priority(ch))
            {
                temp=pop();
                printf("%c ",temp); 
            }
            push(ch);
        }
        index++;
    }
    while(top!=-1)
        printf("%c ",pop()); 
}


int main()
{
	
	char expression[]={'a','+','(','b','-','c',')'};
    int size=sizeof(expression)/sizeof(expression[0]);
    infixToPostfix(expression,size);

	return 0;

}