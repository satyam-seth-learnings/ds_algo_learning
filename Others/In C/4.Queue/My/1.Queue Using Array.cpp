//Queue Using Array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 10
int queue[N];
int front=-1;
int rear=-1;
void Enqueue(int);
void Dequeue();
void Display();
int main()
{
	int ch;
	printf("################################################################################\n");
	printf("****************************** Queue Using Array *******************************\n");
	printf("################################################################################\n");
	while(1)
	{
		printf("Enter Your Choice:\n");
		printf("1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				int x;
				printf("Enter The Element:");
				scanf("%d",&x);
				Enqueue(x);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Display();
				break;
			case 4:
				printf("\n------------------------------------- Bye --------------------------------------");
				exit(0);
			default:
				printf("You Enter Wrong Choice.\n\n");
		}
		printf("--------------------------------------------------------------------------------\n");
	}
}
void Enqueue(int x)
{
	if(rear==N-1)
		printf("Overflow:Queue Is Full.\n\n");
	else
	{
		if(front==-1&&rear==-1)
		{
			front=0;
			rear=0;	
		}
		else
		{
			rear++;
		}
		queue[rear]=x;
		printf("Element %d Successfully enqueued.\n\n",x);
	}
}
void Dequeue()
{
	if(front==-1)
		printf("Underflow:Queue Is Empty.\n\n");
	else if(front==rear)
	{
		int a=queue[front];
		front=-1;
		rear=-1;
		printf("Element %d Successfully dequeued.\n\n",a);
	}
	else
	{
		int a=queue[front];
		front++;
		printf("Element %d Successfully dequeued.\n\n",a);
	}
}
void Display()
{
	if(front==-1)
		printf("Queue Is Empty.\n\n");
	else
	{
		int i;
		printf("Queue Is:");
		for(i=front;i<rear+1;i++)
			printf(" %d",queue[i]);
		printf("\n\n");
	}
}
