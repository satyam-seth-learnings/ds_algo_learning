#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* q1=NULL,*q2=NULL;
struct node* front1,*front2,*rear1,*rear2;

void push(int x)
{
	if(q2==NULL)
	{
		q2=(struct node*) malloc(sizeof(struct node));
		q2->data=x;
		q2->next=NULL;
		rear2=q2;
	}

	else{
		struct node *temp=(struct node*) malloc(sizeof(struct node));
		temp->data=x;
		rear2->next=temp;
		rear2=temp;
		rear2->next=NULL;
	}
    if(q1)
        front1=q1;
    
	while(front1)
	{
		struct node *temp=front1;
		front1=front1->next;
		rear2->next=temp;
		rear2=temp;
		rear2->next=NULL;
	}
	if(front1==NULL)
	q1=NULL;
	
	struct node *t=q1;
	q1=q2;
	q2=t;
	
}
int pop()
{
    front1=q1;
	int val=front1->data;
	struct node* temp=front1;
	front1=front1->next;
	q1=q1->next;
	free(temp);
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
    push(50);
    push(60);
    printf("%d\n",pop());
	return 0;
}