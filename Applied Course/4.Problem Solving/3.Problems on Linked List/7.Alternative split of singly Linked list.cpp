#include<stdio.h> 
#include<stdlib.h> 

struct node 
{ 
	int data; 
	struct node* next; 
}; 

void changeNode(struct node** dest, struct node** source) ; 

/*
The alternating Elements of linkedlist are splitted into two lists with the below 
function. 1->2->3->4->5->6.......
*/
void AlternatingSplit(struct node* head, struct node** list1, struct node** list2) 
{ 

/* split the nodes of source  
    to these 'temp1' and 'temp2' lists */
struct node* temp1 = NULL; 
struct node* temp2 = NULL; 

	
struct node* curr = head; 
while (curr != NULL) 
{ 
	changeNode(&temp1, &curr); /* Move a node to list 'temp1' */
	if (curr != NULL) 
	{ 
	changeNode(&temp2, &curr); /* Move a node to list 'temp2' */
	} 
} 
*list1=temp1;
*list2=temp2;
} 
/* Take the node from the front of 
the source, and move it to the front 
of the dest. It is an error to call 
this with the source list empty.  
      
Before calling changeNode():  
source == {1, 2, 3}  
dest == {1, 2, 3}  
          
Affter calling changeNode():  
source == {2, 3}      
dest == {1, 1, 2, 3}      
*/
void changeNode(struct node** dest, struct node** source) 
{


struct node* new_Node=*source;
*source = new_Node->next; 
new_Node->next = *dest; 
*dest = new_Node; 
} 
/* Function to insert a node at  
the beginging of the linked list */
void push(struct node** head,int data)
{
    struct node* temp1_node=(struct node*)malloc(sizeof(struct node));
    if(!temp1_node)
        printf("Memory Error\n");
    temp1_node->data=data;
    temp1_node->next=*head;
    *head=temp1_node;
}
 
/*
prints the linked list
*/
void printList(struct node *temp) 
{ 
while(temp!=NULL) 
{ 
printf("%d ", temp->data); 
temp = temp->next; 
} 
} 


int main() 
{ 

struct node* head = NULL; 
struct node* head1 = NULL; 
struct node* head2 = NULL; 

push(&head, 5); 
push(&head, 4); 
push(&head, 3); 
push(&head, 2); 
push(&head, 1);									 
push(&head, 0); 

printf("\n Original linked List: "); 
printList(head); 

AlternatingSplit(head, &head1, &head2); 

printf("\n List 1 : "); 
printList(head1);			 

printf("\n List 2 : "); 
printList(head2);			 

return 0; 
} 
