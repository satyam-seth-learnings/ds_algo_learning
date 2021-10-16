#include<stdio.h>
#include<conio.h>
int main()
{
	int n;
	printf("Enter the Size Of Array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the %d ELements:\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Reverse Of Array:");
	for(int i=n-1;i>=0;i--)
		printf("%d ",a[i]);
	getch();
}
