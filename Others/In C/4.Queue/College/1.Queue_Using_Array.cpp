//Queue Using Array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX],front=-1,rear=-1;
void push();
void pop();
void disp();
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
					disp();
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
	if(rear==MAX-1)
		printf("Overflow");
	else
	{
		if(front==-1)
			front=0;
		printf("Enter Elewment:");
		scanf("%d",&data);
		rear++;
		q[rear]=data;
	}
}
void pop()
{
	if(front==-1||front>rear)
		printf("Underflow\n");
	else
	{
		printf("Deleted:%d\n",q[front]);
		front++;
	}		
}
void disp()
{
	int i;
	if(front==-1)
		printf("Queue is empty\n");
	else
	{
		printf("Elements:\n");
		for(i=front;i<=rear;i++)
		printf("%d\n",q[i]);
	}
}
