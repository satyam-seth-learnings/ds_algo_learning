//Stack Using Array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int a[MAX],top=-1;
void push();
void pop();
void display();
int main()
{
	int ch;
	while(1)
	{
		printf("1.Push Or Insert\n");
		printf("2.Pop Or Delete\n");
		printf("3.Display\n");
		printf("4.End Program\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					push();
					break;
			case 2:
					pop();
					break;
			case 3:
					display();
					break;
			case 4:
				exit(0);
			default:
				printf("Wrong Choice\n");
		}
	}
}
void push()
{
	int data;
	if(top==MAX-1)
		printf("Overflow Or Stack is Full\n");
	else
	{
		printf("Enter element to be Pushed:");
		scanf("%d",&data);
		top++;
		a[top]=data;
	}
}
void pop()
{
	if(top==-1)
		printf("Underflow Or Stack is empty\n");
	else
	{
		printf("Popped Element:%d\n",a[top]);
		top--;
	}
}
void display()
{
	int i;
	if(top>=0)
	{
		printf("Elements:\n");
		for(i=top;i>=0;i--)
			printf("%d\n",a[i]);
	}
	else
		printf("The Stack is empty\n");
}
