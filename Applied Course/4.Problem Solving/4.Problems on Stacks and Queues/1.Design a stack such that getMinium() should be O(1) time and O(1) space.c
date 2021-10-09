#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
int minEle = INT_MAX;;
int stack[10];
int top=-1;
 
int isEmpty(int top)
{
	return ((top) == -1);
}
 
void getMinimum()
{
    printf("Minimum value is: %d\n", minEle);
}
int pop()
{
	int element;
	if(!isEmpty(top))
	{
		if(stack[(top)] < minEle){
			element =  stack[top] + 2*(minEle);
			minEle = 2*(minEle) - stack[(top)];
 
		}
		else
			element = stack[top];
		(top)--;
		return element;
	}
	else{
		printf("Stack Is Empty");
		return -1;
	}
}
 
void push(int num)
{
	if((minEle) > num)
	{
		if(top == -1)
			stack[++top] = num;
		else
			stack[++top] = ((2*num)-minEle);
	    minEle = num;
	}
	else if((minEle <= num))
		stack[++(top)] = num;	
}
 
void display()
{
	for(int i=(top); i>=0; i--)
		printf("%d\n", stack[i]);
}
 
int main()
{
	int ele;
	push(15);
    push(25);
    push(5);
    getMinimum();
    ele = pop();
    printf("Popped element from stack is = %d\n", ele);
    ele = pop();
    printf("Popped element from stack is = %d\n", ele);
    getMinimum();
    return 0;
}