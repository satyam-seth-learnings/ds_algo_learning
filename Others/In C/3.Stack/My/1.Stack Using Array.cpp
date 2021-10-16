//Stack Using Array
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 10
int stack[N];
int top=-1;
void Push(int);
void Pop();
void Peep();
void Display();
void Full();
void Empty();
int main()
{
	int ch;
	printf("################################################################################\n");
	printf("****************************** Stack Using Array *******************************\n");
	printf("################################################################################\n");
	while(1)
	{
		printf("Enter Your Choice:\n");
		printf("1.Push\n");
		printf("2.Pop\n");
		printf("3.Peep\n");
		printf("4.Display\n");
		printf("5.Check Stack Is Full\n");
		printf("6.Check Stack Is Empty\n");
		printf("7.Exit\n");
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
				Full();
				break;
			case 6:
				Empty();
				break;
			case 7:
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
	if(top==N-1)
		printf("Overflow:Stack Is Full.\n\n");
	else
	{
		top++;
		stack[top]=x;
		printf("Element %d Successfully Pushed.\n\n",x);
	}
}
void Pop()
{
	if(top==-1)
		printf("Underflow:Stack Is Empty.\n\n");
	else
	{
		int a=stack[top];
		top--;
		printf("Element %d Successfully Poped.\n\n",a);
	}
}
void Peep()
{	
	if(top==-1)
		printf("Stack Is Empty.\n\n");
	else	
		printf("Top=%d\n\n",stack[top]);
}
void Display()
{
	if(top==-1)
		printf("Stack Is Empty.\n\n");
	else
	{
		int i;
		printf("Stack Is:");
		for(i=top;i>-1;i--)
			printf(" %d",stack[i]);
		printf("\n\n");
	}
}
void Full()
{
	if(top==N-1)
		printf("Stack Is Full.\n\n");
	else
		printf("Stack Is Not Full.\n\n");
}
void Empty()
{
	if(top==-1)
		printf("Stack Is Empty.\n\n");
	else
		printf("Stack Is Not Empty.\n\n");
}
