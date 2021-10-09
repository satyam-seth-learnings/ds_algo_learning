#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int detectLoop(struct node *head)
{
	struct node *fastPtr, *slowPtr;
	for(fastPtr=head, slowPtr=head; fastPtr&&fastPtr->next;)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
		if (fastPtr == slowPtr) return 1;
	}	 	 
	return 0;
}
 
void push(struct node** head, int new_data) 
{ 
	/* create temp node */
	struct node* temp = (struct node*) malloc(sizeof(struct node)); 
	temp->data  = new_data; 
	temp->next = (*head);     
	(*head) = temp; 
} 
  
int main() 
{ 
	struct node* head = NULL; 
	push(&head, 10); 
	push(&head, 3); 
	push(&head, 5); 
	push(&head, 20);
	push(&head, 50); 
	/* Create a loop for testing */
    head->next->next->next->next->next = head->next; 
	
	if(detectLoop(head))
		printf("Found Loop\n");
	else
		printf("Not Found");
	return 0; 
} 

