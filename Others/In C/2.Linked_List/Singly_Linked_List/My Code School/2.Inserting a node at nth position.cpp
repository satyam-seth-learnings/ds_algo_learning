//Linked List: Inserting a node at nth position
#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;
void Insert(int data,int n);
void Print();
int main()
{
	head=NULL;	//empty list
	int ch,data,position;
	while(1)
	{
		Print();
		printf("1.Insert at nth Position\n");
		printf("3.End Program\n");
		printf("Enter Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter Element: ");
				scanf("%d",&data);
				printf("Enter Position: ");
				scanf("%d",&position);
				Insert(data,position);
				break;
			case 2:
				exit (0);
			default:
				printf("Worng Choice!\n");		
		}
	}
}
void Insert(int data,int n)
{
	struct Node* temp1;
	temp1=(Node*)malloc(sizeof(Node));
	temp1->data=data;
	temp1->next=NULL;
	if(n==1)
	{
		temp1->next=head;
		head=temp1;
		return;
	}
	struct Node* temp2;
	temp2=head;
	for(int i=0;i<n-2;i++)
	{
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
}
void Print()
{
	struct Node* temp=head;
	printf("List is: ");
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
