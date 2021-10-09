#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* q1,*q2;
struct node* front1,*front2,*rear1,*rear2;

void push(int x)
{
	if(q1==NULL)
	{
		q1=(struct node*) malloc(sizeof(struct node));
		q1->data=x;
		q1->next=NULL;
		rear1=q1;
	}

	else{
		struct node *temp=(struct node*) malloc(sizeof(struct node));
		temp->data=x;
		rear1->next=temp;
		rear1=temp;
		rear1->next=NULL;
	}
	
}
/*making pop operation costly*/
int pop()
{
	front1=q1;
	while(front1!=rear1)
	{
		if(q2==NULL)
		{
		q2=front1;
		rear2=front1;
		}

	else{
		rear2->next=front1;
		rear2=front1;
		}
		front1=front1->next;
	}
	int val=rear1->data;
	free(rear1);
	q1=q2;
	q2=NULL;
	rear1=rear2;
	return val;
}	

int main()
{
	push(10);
	push(20);
	push(30);
	push(40);
	printf("%d\n",pop());
	printf("%d\n",pop());
	printf("%d\n",pop());
	push(50);
	printf("%d\n",pop());
	push(60);
	printf("%d\n",pop());
	return 0;
}