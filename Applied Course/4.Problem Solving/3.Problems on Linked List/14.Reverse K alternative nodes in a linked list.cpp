#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int data; 
	struct node* next; 
}; 

/*kAlternativeReverse() function Reverses alternate k nodes and 
returns the pointer to the new head node */
struct node *kAlternativeReverse(struct node *head, int k) 
{ 
	struct node* curr = head; 
	struct node* next; 
	struct node* prev = NULL; 
	int count = 0; 

	/*reverse first k nodes of the linked list */
	while (curr != NULL && count < k) 
	{ 
	next = curr->next; 
	curr->next = prev; 
	prev = curr; 
	curr = next; 
	count++; 
	} 
	
	/* Here we are pointing the head to (k+1)th node*/
	if(head != NULL) 
	head->next = curr; 

	/* We need to reverse alternate k nodes so we do not
	reverse next k nodes */
	count = 0; 
	while(count < k-1 && curr != NULL ) 
	{ 
	curr = curr->next; 
	count++; 
	} 

	/* Recursively call kAlternativeReverse() function for next k nodes */
	if(curr != NULL) 
	curr->next = kAlternativeReverse(curr->next, k); 

	/* The prev pointer holds the head*/
	return prev; 
} 

/*Insert the nodes in start of the Linked list*/
void push(struct node** head, int data) 
{ 
	struct node* newnode = (struct node*) malloc(sizeof(struct node)); 
	newnode->data = data; 
	newnode->next = (*head);	 
	(*head) = newnode; 
} 

/* Function to print linked list */
void printList(struct node *temp) 
{ 
	while(temp != NULL) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
}	 

int main(void) 
{ 
	struct node* head = NULL; 

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
	push(&head,10);

	printf("original list \n"); 
	printList(head); 
	head = kAlternativeReverse(head, 3); 

	printf("\nReversed Linked list \n"); 
	printList(head); 
	return(0); 
} 
