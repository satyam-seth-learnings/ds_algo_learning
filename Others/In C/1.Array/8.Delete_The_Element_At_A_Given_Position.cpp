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
	int pos;
	printf("\nEnter the Position:");
	scanf("%d",&pos);
	if(pos>n||pos<0)
		printf("Invalid Position.");
	else
	{
		for(int i=pos-1;i<n-1;i++)
			a[i]=a[i+1];
		n=n-1;
		printf("Array Is:");
		for(int i=0;i<n;i++)
			printf("%d ",a[i]);
	}
	getch();
}
