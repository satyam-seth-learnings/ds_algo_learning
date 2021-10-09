#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};
/*Inserting the elements into the list 
from the front*/
void push(struct node** head,int data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=*head;
	*head=new_node;
}
/*Printing the values in the list*/
void printList(struct node* temp)
{
	while(temp)
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
/*Creating a new node for storing the value and to store carry*/
struct node* newNode(int data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
}
/* Function is used to add the two linked lists*/
void addLists(struct node* first,struct node* second)
{
	int sum,q=0,r;
	struct node* head,*temp=NULL;
	while(first || second)
	{
		/*below statement is used to check first and second list are null or not*/
		sum=q+((first?first->data:0)+(second? second->data: 0));

		r=sum%10;
		q=sum/10;
		if(temp==NULL){
			temp=newNode(r);/* creation of new node to store the sum of the 2 linked list*/
			head=temp;
		}
		else{
			temp->next=newNode(r);/* creation of new node to store the sum of the 2 linked list*/
			temp=temp->next;
		}
		/*Below statements are moving the pointer to next node 
		  if they are not null*/
		if(first)
		first=first->next;
		if(second)
		second=second->next;

	}
	/* Below condition is if there is carry in last node
	   we have to create new node to store the carry*/
	if(q>0)
	{
		temp->next=newNode(r);
		temp=temp->next;	
	}

	printf("After Addition\n");
	printList(head);
}

int main()
{
	struct node* first=NULL;
	struct node* second=NULL;

	
	push(&first,4);
	push(&first,8);

	push(&second,6);
	push(&second,4);

	printList(first);
	printList(second);

	addLists(first,second);
	return 0;
}
