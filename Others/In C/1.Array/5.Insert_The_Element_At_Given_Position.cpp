#include<stdio.h>
#include<conio.h>
int main()
{
	int n,a[100];
	printf("Enter the Size Of Array:");
	scanf("%d",&n);
	printf("Enter the %d ELements:\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Array Is:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	int pos,element;
	printf("\nEnter the Position:");
	scanf("%d",&pos);
	if(pos>n||pos<0)
		printf("Invalid Position.");
	else
	{
		printf("Enter Tne Element To Be Inserted:");
		scanf("%d",&element);
		for(int i=n-1;i>=pos-1;i--)
			a[i+1]=a[i];
		a[pos-1]=element;
		n++;
		printf("Array Is:");
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
	}
	getch();
}
