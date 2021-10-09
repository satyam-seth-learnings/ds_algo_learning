#include <stdio.h>
#include <stdlib.h>

// initialize top =-1
int top = -1;

// function to check the stack is empty or not
int isStackEmpty()
{
	return (top == -1);
}

// function to push an element into the stack

void push(int stack[], int data, int size)
{
	if(top == size)
		printf("stack Full");
	else
		stack[++top] = data;
}

// FUnction to pop an element from the stack
int pop(int *stack)
{
	int ele ;
	if(isStackEmpty())
	{
		printf("stack Empty\n");
		return -1;
	}
	ele = stack[top];
	top--;
	return ele;
}

void calculateSpan(int *price, int n, int *stock)
{
	int stack[n], ele;
	push(stack, 0, n);
	
	//span value of first day is always 1
	stock[0] = 1;
	
	//Calculate span value of remaining days by checking previous days
	for(int i=1; i<n; i++)
	{
		//Traverse array left while the next element  on left is smaller than price[i] 
		while(!isStackEmpty() && price[stack[top]] <= price[i])
			ele = pop(stack);

		stock[i] = (isStackEmpty() ? (i+1) : (i- stack[top]));
		push(stack, i, n);
	}
}

// Function to print span on each day
void printSpan(int stock[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d  ", stock[i]);
}

int main()
{
	int price[] = {10, 4, 5, 90, 120, 80};
	int stock[6];
	calculateSpan(price, 6, stock);
	printSpan(stock, 6);
	return 0;
}