#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node* queue=NULL,*front=NULL,*rear=NULL;

void push(int x)
{
	/*
	If queue is empty insert the first node
	*/
	if(queue==NULL)
	{
		queue=(struct node*) malloc(sizeof(struct node));
		queue->data=x;
		queue->next=NULL;
		rear=queue;
		front=queue;
	}
	/*add the elements to rear node*/
	else
	{
		struct node *temp=(struct node*) malloc(sizeof(struct node));
		temp->data=x;
		rear->next=temp;
		rear=temp;
	}
	/*move the nodes from front to rear */
	struct node *temp=rear;
	while(front!=temp)
	{
		struct node *t=front;
		front=front->next;
		rear->next=t;
		rear=t;
		rear->next=NULL;
	}
}

int pop()
{
    struct node *temp=front;
    int val=front->data;
    front=front->next;
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
    printf("%d\n",pop());

	return 0;
}