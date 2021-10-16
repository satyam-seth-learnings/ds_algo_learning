#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int rear=-1,front=-1;
void insert();
void del();
void display();
int main()
{
	int ch;
	printf("To implementation of Circular Queue using array\n");
	while(1)
	{
		printf("1.Enter the choice:-\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
				case 1:
					insert();
					break;
				case 2:
					del();
					break;
				case 3:
					display();
					break;
				case 4:
					exit(0);
				default:
					printf("Invalid Choice!.\n");
		}
	}
}
void insert()
{
	int x;
	if((front==0&&rear==MAX-1)||(rear+1==front))
		printf("Queue is overflow\n");
	else
	{
		printf("Enter the element to be inserted:");
		scanf("%d",&x);
		if(rear==-1)
			front=0,rear=0;
		else if(rear==MAX-1)
			rear=0;
		else
			rear++;
		queue[rear]=x;
	}
}
void del()
{
	int a;
	if(front==-1)
		printf("Queue is underflow.\n");
	else
	{
		a=queue[front];
		if(front==rear)
			front=-1,rear=-1;
		else if (front==MAX-1)
			front=0;
		else
			front++;
		printf("%d is deleted.\n",a);
	}
}
void display()
{
	int i,j;
	if(front==-1&&rear==-1)
		printf("Queue is empty\n");
	else if(front>rear)
	{
		for(i=front;i<MAX;i++)
			printf("%d\t",queue[i]);
		for(j=0;j<=rear;j++)
			printf("%d\t",queue[j]);
	}
	else
		for(i=front;i<=rear;i++)
			printf("%d\t",queue[i]);
	printf("\n");
}
