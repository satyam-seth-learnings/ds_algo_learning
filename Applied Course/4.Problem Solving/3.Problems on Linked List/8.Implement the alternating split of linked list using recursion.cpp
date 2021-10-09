// CPP code to split linked list 
#include <bits/stdc++.h> 
using namespace std; 

// Node structure 
struct Node { 
	int data; 
	struct Node* next; 
}; 

// Function to push nodes 
// into linked list 
void push(Node** head, int new_data) 
{ 
	Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->next = (*head); 
	(*head) = new_node; 
} 

// We basically remove link between 'a' 
// and its next. Similarly we remove link 
// between 'b' and its next. Then we recur 
// for remaining lists. 
void moveNode(Node* a, Node* b) 
{ 
	if (b == NULL || a == NULL) 
		return; 

	if (a->next != NULL) 
		a->next = a->next->next; 

	if (b->next != NULL) 
		b->next = b->next->next; 

	moveNode(a->next, b->next); 
} 

// function to split linked list 
void alternateSplitLinkedList(Node* head, Node** aRef, 
										Node** bRef) 
{ 
	Node* curr = head; 
	*aRef = curr; 
	*bRef = curr->next; 
	moveNode(*aRef, *bRef); 
} 

void display(Node* head) 
{ 
	Node* curr = head; 
	while (curr != NULL) { 
		printf("%d ", curr->data); 
		curr = curr->next; 
	} 
} 

// Driver code 
int main() 
{ 
	Node* head = NULL; 
	Node *a = NULL, *b = NULL; 

	push(&head, 7); 
	push(&head, 6); 
	push(&head, 5); 
	push(&head, 4); 
	push(&head, 3); 
	push(&head, 2); 
	push(&head, 1); 


	alternateSplitLinkedList(head, &a, &b); 

	printf("a : "); 
	display(a); 
	printf("\nb : "); 
	display(b); 

	return 0; 
} 
