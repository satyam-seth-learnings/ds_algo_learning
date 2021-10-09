#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};

/* Function to splitList() splits the list into two circular lists
	head1 holds first circular list and head2 holds second circular list
*/
void splitList(struct node *head, struct node **head1,struct node **head2) 
{ 
  struct node *slowptr = head; 
  struct node *fastptr = head;  
  
  if(head == NULL) 
  {
  	printf("Memory Error");
    return; 
   }

  while(fastptr->next != head && fastptr->next->next != head)  
  { 
     fastptr = fastptr->next->next; 
     slowptr = slowptr->next; 
  }   
  if(fastptr->next->next == head) 
    fastptr = fastptr->next;       
   /* Set the head1 pointer with the head */
  *head1 = head;     
       
	 /* Set the head2 pointer with slow pointer */
  if(head->next != head) 
    *head2 = slowptr->next; 
    
   /* Make second half circular */   
  fastptr->next = slowptr->next; 
	 /* Make first half circular */  
  slowptr->next = head;        
} 
/* Function to insert a node at the beginning of a Circular  
   linked list */
void push(struct node** head,int data)
{
	struct node* new_node=(struct node*)malloc(sizeof(struct node));
	struct node *temp = *head;
	new_node->data=data;
	new_node->next=*head;

	/* If linked list is not NULL then set the next of  
    last node */
	if(*head != NULL) 
  	{ 
    while(temp->next != *head) 
      	temp = temp->next;         
    temp->next = new_node;  
  	}

  	else
  		new_node->next=new_node;/*For the first node */

  	*head=new_node; 

}
/* Function to print nodes in a given Circular linked list */
void printList(struct node* head)
{
	struct node* temp=head;
	do
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}while(temp!=head);

	printf("\n");
}

int main()
{

	struct node* head=NULL;
	struct node* head1=NULL;
	struct node* head2=NULL;

	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);

	printList(head);

	splitList(head,&head1,&head2);

	printf("List1\n");
	printList(head1);
	printf("List2\n");
	printList(head2);
}