/*Write a program to reverse a stack using recursion.and you can only use the following ADT functions on Stack S:
isEmpty(S)
push(S)
pop(S)*/

#include <stdio.h>
int stack[100];
int top=-1;

void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	if(top==-1)
		return 0;
	int d=stack[top--];
	return d;
}
int isEmpty()
{
	if(top==-1)
		return 0;
	else
		return 1;
}
int peek()
{
	if(top!=-1)
		return stack[top];
}

int size()
{
	int count=0;
	int top1=top;
	while((top1--)>-1)
		count++;
	return count;
}

void insert(int x)
{
	if(size()==0){
		push(x);
	}

	else{
		char c=pop();
		insert(x);

		push(c);
	}
}

void reverse()
{
	if(size()>0)
	{
		char c=pop();
		reverse();

		insert(c);
	}
}
int main()
{
	push(1);
	push(2);
	push(3);
	push(4);
	int n=size();
	printf("Before reverse\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n",pop());
	}
	top=n-1;
	reverse();
	n=size();
	printf("After reverse\n");
	for(int i=0;i<n;i++)
		printf("%d\n",pop());
	return 0;
}