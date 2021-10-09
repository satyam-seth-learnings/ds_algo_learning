
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

#define BLANK ' '
#define TAB '\t'
#define MAX 50



char infix[MAX], postfix[MAX];
long int stack[MAX];
int top;

void push(long int symbol)
{
	if(top>MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	stack[++top]=symbol;
}/*End of push()*/

int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}/*End of isEmpty()*/


long int pop()
{
	if( isEmpty() )
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return (stack[top--]);
}/*End of pop()*/

int white_space(char symbol)
{
	if( symbol == BLANK || symbol == TAB )
		return 1;
	else
		return 0;
}/*End of white_space()*/
/*This function returns the priority of the operator*/
int priority(char symbol)
{
	switch(symbol)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default :
		return 0;
	}
}/*End of priority()*/


void infix_to_postfix()
{
	unsigned int i,p=0;
	char next;
	char symbol;	
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(!white_space(symbol))
		{
			switch(symbol)
			{
			case '(':
				push(symbol);
				break;
			case ')':
				while((next=pop())!='(')
					postfix[p++] = next;
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
				while( !isEmpty( ) &&  priority(stack[top])>= priority(symbol) )
					postfix[p++]=pop();
				push(symbol);
				break;
			default: /*if an operand comes*/
			     postfix[p++]=symbol;
			}
		}
	}
	while(!isEmpty( )) 
		postfix[p++]=pop();
	postfix[p]='\0'; /*End postfix with'\0' to make it a string*/
}/*End of infix_to_postfix()*/




main()
{
	long int value;
	top=-1;
	printf("Enter infix : ");
	gets(infix);
	infix_to_postfix();
	printf("Postfix : %s\n",postfix);
}/*End of main()*/

