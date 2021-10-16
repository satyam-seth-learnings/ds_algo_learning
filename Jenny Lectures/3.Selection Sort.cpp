// Selection Sort
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
	for(i=0;i<n-1;i++)
	{
		int min=i;
		for(j=i+1;j<n;j++)
			if(A[j]<A[min])
				min=j;
		if(min!=i)
		{
			int temp=A[i];
			A[i]=A[min];
			A[min]=temp;
		}
	}
	printf("\nSorted elements:");
	for(i=0;i<n;i++)
		printf(" %d",A[i]);
}
