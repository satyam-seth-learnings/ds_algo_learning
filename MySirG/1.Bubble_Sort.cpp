#include<stdio.h>
#include<conio.h>
void bubble_sort(int [],int);
int main()
{
	int i,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int A[n];
	printf("Enter the %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("You entered elements:\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	bubble_sort(A,n);
	printf("\nSorted elements:\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	getch();
}
void bubble_sort(int A[],int N)
{
	int round,i,temp,flag;
	for(round=1;round<=N-1;round++)
	{
		flag=0;
		for(i=0;i<=N-1-round;i++)
			if(A[i]>A[i+1])
			{
				flag=1;
				temp=A[i];
				A[i]=A[i+1];
				A[i+1]=temp;
			}
		if(flag==0)
			return;
	}
}
