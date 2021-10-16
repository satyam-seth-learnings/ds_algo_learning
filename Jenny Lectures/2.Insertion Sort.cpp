// Insertion Sort
#include<stdio.h>
#include<conio.h>
int main()
{
	int n,i,j;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int A[n];
	printf("Enter the %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("You entered elements:");
	for(i=0;i<n;i++)
		printf(" %d",A[i]);
	for(i=1;i<n;i++)
	{
		int temp=A[i];
		for(j=i-1;j>=0&&A[j]>temp;j--)
			A[j+1]=A[j];
		A[j+1]=temp;
	}
	printf("\nSorted elements:");
	for(i=0;i<n;i++)
		printf(" %d",A[i]);
}
