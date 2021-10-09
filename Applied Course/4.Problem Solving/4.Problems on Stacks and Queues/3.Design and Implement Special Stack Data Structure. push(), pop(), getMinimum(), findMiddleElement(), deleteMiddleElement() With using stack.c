#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *prev, *next;
};

struct stack
{
	struct node *head, *middle;
	int count;
};

/*create a stack */
struct stack *createStack()
{
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	s->count = 0;
	return s;
}

// Function to push an element to the stack
void push(struct stack *s, int data)
{
	// create a new node
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = s->head;
	s->count += 1;
	//Change middle pointer, Linked List is empty  
    
	if(s->count == 1)
		s->middle = temp;
	//Change middle pointer, when Number of nodes in linked list is odd */
	else
	{
		s->head->prev = temp;
		if(s->count & 1)
			s->middle = s->middle->prev;
	}
	// point the head to new node
	s->head = temp;
}

// Function for pop an element from the stack
int pop(struct stack *s)
{
	if(!s->count)  // checking stack is underflow or not
	{
		printf("Stack is Empty\n" );
		return -1;
	}
	struct node *temp = s->head;
	int item = temp->data;
	s->head = temp->next;
	// If linked list doesn't become empty, update prev of new head as NULL
	if(s->head)
		s->head->prev = NULL;
	
	// update the mid pointer when we have even number of elements in the stack
	s->count -= 1;
	if(!((s->count) & 1))
		s->middle = s->middle->next;
		
	// free the temp node
	free(temp);
	return item;
}

// Function for finding middle of the stack
int getMiddleEle(struct stack *s)
{
	// if stack is empty then return -1 else return middle node data
	return !(s->count)? -1: s->middle->data; 
}


// Function for deleting middel of the stack
int deleteMiddleEle(struct stack *s)
{
	if(s->count > 0)
	{
		struct node* temp = s->middle;
		int data = temp->data;
		// if the stack count is odd then point middle node to the next node
		// other wise previous node
		s->middle = (s->count &1)? temp->next: temp->prev;
		
		// decrease the stack count by 1
		s->count -= 1;

		if(temp->prev)
			temp->prev->next = temp->next;
		if(temp->next)
			temp->next->prev = temp->prev;
		free(temp);
		
		// if stack is empty then assign head and middle node to NULL
		if(s->count == 0)
		{
			s->head = NULL;
			s->middle = NULL;
			
		}
		return data;
	}
	else
	{
		printf("Stack is empty\n");
		return -1;
	}
}

int main()
{
	struct stack *s = createStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	push(s, 50);
	push(s, 60);
	push(s, 70);
	printf("Middle element is = %d\n", getMiddleEle(s));
	printf("Item popped from stack is = %d\n", pop(s));
	printf("Item popped from stack is = %d\n", pop(s));
	printf("Middle element is = %d\n", getMiddleEle(s));
	printf("Delete Middle Element = %d\n", deleteMiddleEle(s));
	return 0;
}