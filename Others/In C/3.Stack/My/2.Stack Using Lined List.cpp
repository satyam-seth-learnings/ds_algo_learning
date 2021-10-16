//Stack Using Linked List
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Stack
{
	int data;
	struct Stack *link;	
};
struct Stack *top=NULL;
void Push(int);
void Pop();
void Peep();
void Display();
int main()
{
	int ch;
	printf("################################################################################\n");
	printf("*************************** Stack Using Linked List ****************************\n");
	printf("################################################################################\n");
	while(1)
	{
		printf("Enter Your Choice:\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peep\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		printf("Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				int x;
				printf("Enter The Element:");
				scanf("%d",&x);
				Push(x);
				break;
			case 2:
				Pop();
				break;
			case 3:
				Peep();
				break;
			case 4:
				Display();
				break;
			case 5:
				printf("\n------------------------------------- Bye --------------------------------------");
				exit(0);
			default:
				printf("You Enter Wrong Choice.\n\n");
		}
		printf("--------------------------------------------------------------------------------\n");
	}
}
void Push(int x)
{
	struct Stack *newnode;
	newnode=(struct Stack*)malloc(sizeof(struct Stack));
	newnode->data=x;
	newnode->link=top;
	top=newnode;
	printf("Element %d Successfully Pushed.\n\n",x);
}
void Pop()
{
	if(top==NULL)
		printf("Underflow:Stack Is Empty.\n\n");
	else
	{
		struct Stack *temp=top;
		printf("Element %d Successfully Poped.\n\n",temp->data);
		top=top->link;
		free(temp);
	}
}
void Peep()
{	
	if(top==NULL)
		printf("Stack Is Empty.\n\n");
	else	
		printf("Top=%d\n\n",top->data);
}
void Display()
{
	if(top==NULL)
		printf("Stack Is Empty.\n\n");
	else
	{
		struct Stack *temp=top;
		printf("Stack Is:");
		while(temp!=NULL)
		{
			printf(" %d",temp->data);
			temp=temp->link;
		}
		printf("\n\n");
	}
}
