//Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *prev;
	struct Node *next;
};
struct Node *start=NULL;
struct Node* CreateNode();
void InsertBeg();
void InsertEnd();
void InsertPos(int);
void InsertNode();
void DeleteFirst();
void DeleteLast();
void DeletePos(int);
void DeleteNode();
void Count();
void Reverse();
void Display();
int main()
{
	int ch;
	printf("################################################################################\n");
	printf("****************************** Doubly Linked List ******************************\n");
	while(1)
	{
		printf("################################################################################\n");
		printf("Enter the choice:\n");
		printf("1.Insertion\n");
		printf("2.Deletion\n");
		printf("3.Count Number Of Elements In The List\n");
		printf("4.Reverse The List\n");
		printf("5.Display\n");
		printf("6.Exit\n");
		printf("Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				InsertNode();
				break;
			case 2:
				DeleteNode();
				break;
			case 3:
				Count();
				break;
			case 4:
				Reverse();
				break;
			case 5:
				Display();
				break;
			case 6:
				printf("--------------------------------------Bye---------------------------------------");
				exit(0);
			default:
				printf("You entered wrong choice.\n\n");
		}
	}
}
struct Node* CreateNode()
{
	struct Node *temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	return (temp);
}
void InsertBeg()
{
	struct Node *temp=CreateNode();
	printf("Enter the data:");
	scanf("%d",&temp->data);
	temp->prev=NULL;
	temp->next=start;
	start->prev=temp;
	start=temp;
	printf("Node successfully inserted.\n\n");
}
void InsertEnd()
{
	struct Node *temp=CreateNode();
	printf("Enter the data:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	struct Node *ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	temp->prev=ptr;
	ptr->next=temp;
	printf("Node successfully inserted.\n\n");
}
void InsertPos(int pos)
{
	struct Node *temp,*ptr;
	temp=CreateNode();
	printf("Enter the data:");
	scanf("%d",&temp->data);
	if(pos==1)
	{
		temp->next=start;
		start->prev=temp;
		start=temp;
		printf("Node successfully inserted.\n\n");
	}
	else
	{
		ptr=start;
		int i;
		for(i=1;i<pos-1&&ptr!=NULL;i++)
			ptr=ptr->next;
		if(ptr==NULL)
			printf("Position out of range.\n\n");
		else
		{
			temp->prev=ptr;
			temp->next=ptr->next;
			if(ptr->next!=NULL)
				ptr->next->prev=temp;
			ptr->next=temp;
			printf("Node successfully inserted.\n\n");
		}
	}
}
void InsertNode()
{
	if(start==NULL)
	{
		struct Node *temp=CreateNode();
		printf("Enter the data:");
		scanf("%d",&temp->data);
		temp->prev=NULL;
		temp->next=NULL;
		start=temp;
		printf("Node successfully inserted.\n\n");
	}
	else
	{
		int ch;
		printf("--------------------------------------------------------------------------------\n");
		printf("Enter the choice:\n");
		printf("1.Insert node at the beginnig of the list\n");
		printf("2.Insert node at the end of the list\n");
		printf("3.Insert node at nth position\n");
		printf("4.Exit\n");
		printf("Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				InsertBeg();
				break;
			case 2:
				InsertEnd();
				break;
			case 3:
				int n;
				printf("Enter the value of n:");
				scanf("%d",&n);
				InsertPos(n);
				break;
			case 4:
				printf("--------------------------------------Bye---------------------------------------");
				exit(0);
				break;
			default:
				printf("You entered wrong choice.\n\n");
		}
	}
}
void DeleteFirst()
{		
	struct Node *ptr=start;
	start=start->next;
	start->prev=NULL;
	free(ptr);
	printf("Node successfully deleted.\n\n");
}
void DeleteLast()
{
	struct Node *ptr,*preptr;
	ptr=start;
	preptr=ptr;
	while(ptr->next!=NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	free(ptr);
	preptr->next=NULL;
	printf("Node successfully deleted.\n\n");
}
void DeletePos(int pos)
{
	struct Node *ptr,*preptr;
	if(pos==1)
		DeleteFirst();
	else
	{
		ptr=start;
		int i;
		for(i=1;i<pos&&ptr!=NULL;i++)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL)
			printf("Position out of range.\n\n");
		else
		{
			preptr->next=ptr->next;
			if(ptr->next!=NULL)
				ptr->next->prev=preptr;
			free(ptr);
			printf("Node successfully deleted.\n\n");
		}
	}	
}
void DeleteNode()
{
	if(start==NULL)
		printf("List Is Empty.\n\n");
	else if(start->next==NULL)
	{		
		struct Node *ptr=start;
		start=start->next;
		free(ptr);
		printf("Node successfully deleted.\n\n");
	}
	else
	{
		int ch;
		printf("--------------------------------------------------------------------------------\n");
		printf("Enter the choice:\n");
		printf("1.Delete the first node of the list\n");
		printf("2.Delete the last node of the list\n");
		printf("3.Delete the nth node of the list\n");
		printf("4.Exit\n");
		printf("Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				DeleteFirst();
				break;
			case 2:
				DeleteLast();
				break;
			case 3:
				int n;
				printf("Enter the value of n:");
				scanf("%d",&n);
				DeletePos(n);
				break;
			case 4:
				printf("--------------------------------------Bye---------------------------------------");
				exit(0);
				break;
			default:
				printf("You entered wrong choice.\n\n");
		}
	}
}
void Count()
{
	if(start==NULL)
		printf("List Is Empty.\n\n");
	else
	{
		int count=0;
		struct Node *temp;
		temp=start;
		while(temp!=NULL)
		{
			count++;
			temp=temp->next;
		}
		printf("Length Of The List Is:%d\n\n",count);
	}
}
void Reverse()
{
	if(start==NULL)
		printf("List Is Empty.\n\n");
	else
	{
		struct Node *tail,*currentnode,*nextnode;
		currentnode=tail=start;
		while(tail->next!=NULL)
			tail=tail->next;
		while(currentnode!=NULL)
		{
			nextnode=currentnode->next;
			currentnode->next=currentnode->prev;
			currentnode->prev=nextnode;
			currentnode=nextnode;
		}
		currentnode=start;
		start=tail;
		printf("List Is Successfully Reversed.\n\n");
	}
}
void Display()
{
	if(start==NULL)
		printf("List Is Empty.\n\n");
	else
	{
		printf("List is: ");
		struct Node *temp=start;
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n\n");
	}
}
