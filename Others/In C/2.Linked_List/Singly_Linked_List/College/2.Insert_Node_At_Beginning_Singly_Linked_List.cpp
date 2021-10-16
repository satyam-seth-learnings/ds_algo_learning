#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *emplist(struct node *start,int data);
struct node *beg(struct node *start,int data);
void disp(struct node *start);
int main()
{
	struct node *start=NULL;
	int ch,data;
	while(1)
	{
		printf("1.Insert in an Empty List\n");
		printf("2.Insert at beginning\n");
		printf("3.Display\n");
		printf("4.End Program\n");
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
				disp(start);
				break;
			case 4:
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
