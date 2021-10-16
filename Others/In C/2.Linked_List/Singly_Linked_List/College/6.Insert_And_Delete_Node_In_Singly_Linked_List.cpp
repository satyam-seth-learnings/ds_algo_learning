#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *emplist(struct node *start,int data);
struct node *beg(struct node *start,int data);
struct node *end(struct node *start,int data);
struct node *nposition(struct node *start,int data,int position);
struct node *del(struct node *start,int data);
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
		printf("5.Delete\n");
		printf("6.Display\n");
		printf("7.End Program\n");
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
				printf("Enter the element to be deleted: ");
				scanf("%d",&data);
				start=del(start,data);
				break;				
			case 6:
				disp(start);
				break;
			case 7:
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
	tmp->link=start;
	start=tmp;
	return start;
}
struct node *beg(struct node *start,int data)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	return start;
}
struct node *end(struct node *start,int data)
{
	struct node *p,*tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->info=data;
	p=start;
	while(p->link!=NULL)
	{
		p=p->link;
	}
	p->link=tmp;
	tmp->link=NULL;
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
		tmp->link=start;
		start=tmp;
		return start;	
	}
	p=start;
	for(i=1;i<position-1&&p!=NULL;i++)
	{
		p=p->link;
	}
	if(p==NULL)
	{
		printf("There are less than %d elements\n",position);
	}
	else
	{
		tmp->link=p->link;
		p->link=tmp;
	}
	return start;
}
struct node *del(struct node *start,int data)
{
	struct node *tmp,*p;
	if(start==NULL)
	{
		printf("List is empty\n");
		return start;
	}
 /*	//Deletion of only node
	if(start->info==data)
	{
		tmp=start;
		start=NULL;
		free(tmp);
		return start;
	}  */
	//Dletion of first node
	if(start->info==data)
	{
		tmp=start;
		start=NULL;
		free(tmp);
		return start;
	}
	//Deletion in between or at the end
	p=start;
	while(p->link!=NULL)
	{
		if(p->link->info==data)
		{
			tmp=p->link;
			p->link=tmp->link;
			free(tmp);
			return start;
		}
		p=p->link;
	}
	printf("Element %d not found",data);
	return start;
}
void disp(struct node *start)
{
	struct node *p;
	if(start==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		p=start;
		printf("List: \n");
		while(p!=NULL)
		{
			printf("%d\t",p->info);
			p=p->link;
		}
		printf("\n");
	}
}
