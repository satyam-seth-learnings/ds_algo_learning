//Queue Using Linked List
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Queue
{
	int data;
	struct Queue *link;	
};
struct Queue *front=NULL;
struct Queue *rear=NULL;
void Enqueue(int);
void Dequeue();
void Display();
int main()
{
	int ch;
	printf("################################################################################\n");
	printf("*************************** Queue Using Linked List ****************************\n");
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
	struct Queue *newnode;
	newnode=(struct Queue*)malloc(sizeof(struct Queue));
	newnode->data=x;
	newnode->link=NULL;
	if(front==NULL)
		front=rear=newnode;
	else
	{
		rear->link=newnode;
		rear=newnode;
	}
	printf("Element %d Successfully enqueued.\n\n",x);
}
void Dequeue()
{
	if(front==NULL)
		printf("Underflow:Queue Is Empty.\n\n");
	else
	{
		int a=front->data;
		struct Queue *temp=front;
		front=front->link;
		free(temp);
		printf("Element %d Successfully dequeued.\n\n",a);
	}
}
void Display()
{
	if(front==NULL)
		printf("Queue Is Empty.\n\n");
	else
	{
		struct Queue *temp=front;
		printf("Queue Is:");
		while(temp!=NULL)
		{
			printf(" %d",temp->data);
			temp=temp->link;
		}
		printf("\n\n");
	}
}
