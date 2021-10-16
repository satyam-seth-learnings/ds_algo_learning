// Bubble Sort
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
		int temp,flag=0;
		for(j=0;j<n-1-i;j++)
		{
			if(A[j]>A[j+1])
			{
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	printf("\nSorted elements:");
	for(i=0;i<n;i++)
		printf(" %d",A[i]);
}
