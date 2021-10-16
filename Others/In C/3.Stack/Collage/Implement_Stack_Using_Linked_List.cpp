#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct stack
{
	int data;
	struct stack *next;
};
struct stack *top=NULL;
void push();
void pop();
void display();
int main()
{
	int choice;
	printf("Linked list imp of stack\n");
	do
	{
		printf("Enter choice:-\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
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
		}
	}while(choice!=4);
	return 0;
}
void push()
{
	int num;
	struct stack *newnode;
	newnode=(struct stack*)malloc(sizeof(struct stack));
	printf("Enter data:");
	scanf("%d",&num);
	newnode->data=num;
	if(top==NULL)
	{
		newnode->next=NULL;
		top=newnode;
	}
	else
	{
		newnode->next=top;
		top=newnode;
	}
}
void pop()
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
		printf("Stack is empty\n");
	else
	{
		printf("%d is deleted\n",top->data);
		top=top->next;
		free(ptr);
	}		
}
void display()
{
	struct stack *ptr;
	ptr=top;
	if(top==NULL)
		printf("Stack is empty\n");
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
