#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *prev;
	struct node *next;
};
struct node *emplist(struct node *start,int data);
struct node *beg(struct node *start,int data);
struct node *end(struct node *start,int data);
struct node *nposition(struct node *start,int data,int position);
void disp(struct node *start);
int main()
{
	struct node *start=NULL;
	int ch,data,position;
	while(1)
	{
		printf("1.Insert in an Empty List\n");
		printf("2.Insert at beginning\n");
		printf("3.Insert at End\n");
		printf("4.Insert at nth Position\n");
		printf("5.Display\n");
		printf("6.End Program\n");
		printf("Enter Choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				if(start!=NULL)	
				{
					printf("List is not Empty\n");
					break;
				}
				printf("Enter Element: ");
				scanf("%d",&data);
				start=emplist(start,data);
				break;
			case 2:
				printf("Enter Element: ");
				scanf("%d",&data);
				start=beg(start,data);
				break;
			case 3:
				printf("Enter Element: ");
				scanf("%d",&data);
				start=end(start,data);
				break;
			case 4:
				printf("Enter Element: ");
				scanf("%d",&data);
				printf("Enter Position: ");
				scanf("%d",&position);
				start=nposition(start,data,position);
				break;
			case 5:
				disp(start);
				break;
			case 6:
				exit (0);
			default:
				printf("Worng Choice!\n");		
		}
	}
}
struct node *emplist(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->prev=NULL;
	tmp->next=NULL;
	start=tmp;
	return start;
}
struct node *beg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->next=start;
	start->prev=tmp;
	start=tmp;
	return start;
}
struct node *end(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=tmp;
	tmp->next=NULL;
	tmp->prev=p;
	return start;
}
struct node *nposition(struct node *start,int data,int position)
{
	int i;
	struct node *tmp,*p;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	if(position==1)
	{
		tmp->prev=NULL;
		tmp->next=start;
		start->prev=tmp;
		return start;	
	}
	p=start;
	for(i=1;i<position-1&&p!=NULL;i++)
	{
		p=p->next;
	}
	if(p==NULL)
	{
		printf("There are less than %d elements\n",position);
	}
	else
	{
		tmp->prev=p;
		tmp->next=p->next;
		if(p->next!=NULL)
			p->next->prev=tmp;
		p->next=tmp;
	}
	return start;
}
void disp(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	p=start;
	printf("List: \n");
	while(p!=NULL)
	{
		printf("%d\t",p->info);
		p=p->next;
	}
	printf("\n");
}
