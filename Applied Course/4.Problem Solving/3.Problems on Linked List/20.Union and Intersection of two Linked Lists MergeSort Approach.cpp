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
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    return temp;
}

struct node *getUnion(struct node *head1, struct node *head2)
{
   struct node *unionList = NULL;
   int newEle;
   while(head1 && head2)
   {
      if(head1->data == head2->data)
      {
        newEle = head1->data;
        head1 = head1->next;
        head2 = head2->next;
      }
      else
      {
        if(head1->data > head2->data)
        {
          newEle = head2->data;
          head2 = head2->next;
        }
        else
        {
          newEle = head1->data;
          head1 = head1->next;
        }
      }
      unionList = insert(unionList, newEle);
   }
  for(;head1;head1=head1->next)
    unionList = insert(unionList, head1->data);
  for(;head2; head2=head2->next)
    unionList = insert(unionList, head2->data); 
  return unionList;
} 

struct node *getIntersection(struct node *head1, struct node *head2)
{
   struct node *intersectionList = NULL;
   while(head1 && head2)
   {
      if(head1->data == head2->data)
      {
        intersectionList = insert(intersectionList, head1->data);
        head1 = head1->next;
        head2 = head2->next;
      }
      else
      {
        if(head1->data > head2->data)
          head2 = head2->next;
        else
          head1 = head1->next;
      }
   }
   return intersectionList;
}
  
int main() 
{ 
  // Create list1
  struct node *head1 = NULL; 
  head1 = insert(head1, 10);
  head1 = insert(head1, 30);
  head1 = insert(head1, 20);
  head1 = insert(head1, 40);
  head1 = insert(head1, 60);
  head1 = insert(head1, 50);
  head1 = mergeSort(head1); 
  // printList(head1);

  //create list2
  struct node *head2 = NULL; 
  head2 = insert(head2, 10);
  head2= insert(head2, 20);
  head2 = insert(head2, 40);
  head2 = insert(head2, 50);
  head2 = insert(head2, 70);
  head2 = insert(head2, 5);
  head2 = mergeSort(head2);
  // printList(head2);

  //intersection of two lists
  struct node *intersectionList = getIntersection(head1, head2);
  printList(intersectionList);

  printf("\n");
  
  // union of two lists
  struct node *unionList = getUnion(head1, head2);
  printList(unionList);
 
} 