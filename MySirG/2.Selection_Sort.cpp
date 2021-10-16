#include<stdio.h>
#include<conio.h>
int min(int [],int,int);
int main()
{
	int i,n,temp,LOC;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int A[n];
	printf("Enter the %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("You entered elements:\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	for(i=0;i<n;i++)
	{
		LOC=min(A,i,n);
		temp=A[i];
		A[i]=A[LOC];
		A[LOC]=temp;
	}
	printf("\nSorted elements:\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	getch();
}
int min(int A[],int j,int N)
{
	int k,LOC,MIN;
	MIN=A[j];
	LOC=j;
	for(k=j+1;j<N;j++)
	{
		if(MIN>A[j])
		{
			
		MIN=A[j];
		LOC=j;
		}
	}
	return(LOC);
}
