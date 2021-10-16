#include<stdio.h>
#include<conio.h>
int main()
{
	int n,a[100],element;
	printf("Enter the Size Of Array:");
	scanf("%d",&n);
	printf("Enter the %d ELements:\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Array Is:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nEnter Tne Element To Be Inserted:");
	scanf("%d",&element);
	n++;
	a[n-1]=element;
	printf("Array Is:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	getch();
}
