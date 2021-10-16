#include<stdio.h>
#include<conio.h>
int main()
{
	int n,element,pos=0;
	printf("Enter the Size Of Array:");
	scanf("%d",&n);
	int a[n];
	printf("Enter the %d ELements:\n",n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Array Is:");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\nEnter The Element To Be Search:");
	scanf("%d",&element);
	for(int i=0;i<n;i++)
		if(element==a[i])
			pos=i+1;
	if(pos==0)
		printf("Element Not Found");
	else
		printf("%d Found At Position: %d",element,pos);
	getch();
}
