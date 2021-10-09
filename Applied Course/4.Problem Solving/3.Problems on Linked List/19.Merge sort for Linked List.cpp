#include <stdio.h>
#include <stdlib.h>
  
/* Structure of the node */
struct node { 
    int data; 
    struct node* next; 
}; 
  


struct node *divide(struct node *p)
{
  struct node *q, *start_second;
  q=p->next->next;
  while(q)
  {
    p=p->next;
    q=q->next;
    if(q)
      q=q->next;
  }
  start_second = p->next;
  p->next = NULL;
  return start_second;
}  

struct node *merge(struct node *head1, struct node *head2)
{
    struct node *mergeList, *temp;
    if(head1->data <= head2->data) {
        mergeList = head1;
        head1 = head1->next;
    }
    else {
        mergeList = head2;
        head2 = head2->next;
    }
    temp = mergeList;
    while(head1 && head2) {
        if(head1->data <= head2->data) {
            temp->next = head1;
            temp = temp->next;
            head1 = head1->next;
        }
        else {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;
        }       
    }
    temp->next = (!head1)? head2: head1;
    return mergeList; 
}

struct node *mergeSort(struct node *head)
{
  struct node *start_first, *start_second, *start_merged;
  
  if(head && head->next)/*if more than one element*/
  {
    start_first = head;
    start_second = divide(head);
    start_first = mergeSort(start_first);
    start_second = mergeSort(start_second);
    start_merged = merge(start_first, start_second);
    return start_merged;
  }
  else
    return head;
}

/*print the nexted List */
void printList(struct node *head) 
{  
  struct node *p = head; 
  for(;p;p=p->next) 
      printf("%d ", p->data);  
} 

struct node* insert(struct node* head, int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    return temp;
} 
  
int main() 
{ 
  struct node *head = NULL; 
  head = insert(head, 10);
  head = insert(head, 30);
  head = insert(head, 20);
  head = insert(head, 40);
  head = insert(head, 60);
  head = insert(head, 50);
  head = mergeSort(head); 

  printList(head); 
} 