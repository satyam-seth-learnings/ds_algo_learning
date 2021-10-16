#include<stdio.h>
#include<conio.h>
int main()
{
	int n,max=0;
	printf("Enter the Size Of Array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the %d ELements:\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Array Is:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	for(int i=0;i<n;i++)
		if(max<a[i])
			max=a[i];
	printf("\nMaximum Element: %d",max);
	getch();
}
