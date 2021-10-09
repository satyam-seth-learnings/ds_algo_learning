// https://leetcode.com/problems/intersection-of-two-linked-lists/
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
 
 
int findIntersection(struct node* list1,struct node* list2)
{
	struct node* head1=list1,*head2=list2;
	int count1=0,count2=0,diff;
	if(list1==NULL||list2==NULL)
		return -1;
	if(list1->next==NULL && list2->next==NULL)
		return -1;
 
	while(head1)
	{
		count1++;
		head1=head1->next;
	}
	while(head2)
	{
		count2++;
		head2=head2->next;
	}
 
	if(count1<count2)
	{
		diff=count2-count1;
		head1=list2;
		head2=list1;
	}
	else
	{
		diff=count1-count2;
		head1=list1;
		head2=list2;
	}
 
	for (int i = 0; i < diff; ++i)
		head1=head1->next;
 
	while(head1!=NULL && head2!=NULL)
	{
		if(head1==head2)
			return head1->data;
		head1=head1->next;
		head2=head2->next;
	}
 
	return -1;
 
 
}
 
int main()
{
	struct node *new_node;
	struct node *head1=(struct node*)malloc(sizeof(struct node));
	head1->data=1;
 
	struct node *head2=(struct node*)malloc(sizeof(struct node));
	head2->data=10;
 
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=2;
	head1->next=new_node;
 
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=3;
	head1->next->next=new_node;
 
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=20;
	head2->next=new_node;
 
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=4;
	head1->next->next->next=new_node;
	head2->next->next=new_node;
 
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=5;
	head1->next->next->next->next=new_node;
 
	head1->next->next->next->next->next=NULL;
 
	int value=findIntersection(head1,head2);
 
	printf("%d\n",value);
 
}