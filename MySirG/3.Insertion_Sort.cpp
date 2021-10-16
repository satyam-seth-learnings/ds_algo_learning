#include<stdio.h>
#include<conio.h>
void insertion_sort(int [],int);
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
	insertion_sort(A,n);
	printf("\nSorted elements:\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	getch();
}
void insertion_sort(int A[],int N)
{
	int i,j,temp;
	for(i=1;i<N;i++)
	{
		temp=A[i];
		for(j=i-1;j>=0&&temp<A[j];j--)
			A[j+1]=A[j];
		A[j+1]=temp;
	}
}
