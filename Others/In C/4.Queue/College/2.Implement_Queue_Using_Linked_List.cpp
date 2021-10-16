#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct queue
{
	int data;
	struct queue *next;
};
struct queue *front,*rear;
void insertion();
void deletion();
void display();
int main()
{
	int choice;
	printf("Linked list imp of Queue\n");
	do
	{
		printf("Enter choice:-\n1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insertion();
				break;
			case 2:
				deletion();
				break;
			case 3:
				display();
				break;
		}
	}while(choice!=4);
	return 0;
}
void insertion()
{
	struct queue *newnode;
	int num;
	newnode=(struct queue *)malloc(sizeof(struct queue));
	printf("Enter data:");
	scanf("%d",&num);
	newnode->data=num;
	if(front==NULL)
	{
		front=rear=newnode;
		front->next=rear->next=NULL;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
		rear->next=NULL;
	}
}
void deletion()
{
	struct queue *ptr;
	ptr=front;
	front=front->next;
	free(ptr);
}
void display()
{
	struct queue *ptr;
	ptr=front;
	if(front==NULL)
		printf("Queue is empty\n");
	else
	{
		printf("Display:\n");
		while(ptr!=NULL)
		{
			printf("%d\n",ptr->data);
			ptr=ptr->next;	
		}
		printf("\n");
	}	
}
