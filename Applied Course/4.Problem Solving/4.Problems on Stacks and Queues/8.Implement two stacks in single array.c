#include<stdio.h>
#define maxsize 100
int arr[maxsize];
int top1=-1;
int top2=maxsize;
void push1(int x)
{
	if(top1<top2-1)
		arr[++top1]=x;
	else
		printf("Stack Overflow");
}
int pop1()
{
	if(top1>=0)
		return arr[top1--];
	else
		printf("Stack Underflow");
}
void push2(int x)
{
	if(top1<top2-1)
		arr[--top2]=x;
	else
		printf("Stack Overflow");
}
int pop2()
{
	if(top1<maxsize)
		return arr[top2++];
	else
		printf("Stack Underflow");
}
int main()
{
	push1(40);
	push1(20);
	push2(10);
	push2(30);
	printf("%d\n",pop1());
	printf("%d\n",pop2());
	return 0;
}