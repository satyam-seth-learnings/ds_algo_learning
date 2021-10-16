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
	int total=0;
	for(int i=0;i<n;i++)
		total+=a[i];
	float avg=(float)total/n;
	printf("Sum Of Elements: %f",avg);
	getch();
}
