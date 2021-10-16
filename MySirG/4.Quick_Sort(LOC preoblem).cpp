#include<stdio.h>
#include<conio.h>
void quick_sort(int A[],int);
int quick(int [],int,int,int,int *);
int main()
{
	int i,n,LOC;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	int A[n];
	printf("Enter the %d elements:\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);
	printf("You entered elements:\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	quick_sort(A,n);
	printf("\nSorted elements:\n");
	for(i=0;i<n;i++)
		printf("%d ",A[i]);
	getch();
}
void quick_sort(int A[],int N)
{
	int BEG,END,TOP=-1;
	int LOWER[100],UPPER[100];
	if(N>1)
	{
		TOP++;
		LOWER[TOP]=0;
		UPPER[TOP]=N-1;
	}
	while(TOP!=-1)
	{
		BEG=LOWER[TOP];
		END=UPPER[TOP];
		TOP--;
		quick(A,N,BEG,END,&LOC);
		if(BEG<LOC-1)
		{
			TOP++;
			LOWER[TOP]=BEG;
			UPPER[TOP]=LOC-1;
		}
		if(LOC+1<END)
		{
			TOP++;
			LOWER[TOP]=LOC+1;
			UPPER[TOP]=END;
		}
	}
}
void quick(int A[],int N,int BEG,int *LOC)
{
	int LEFT,RIGHT,temp;
	LEFT=BEG;
	RIGHT=END;
	*LOCPTR=BEG;
	while(A[*LOCPTR]<=A[RIGHT]&&*LOCPTR!=RIGHT)
		RIGHT;
	if(*LOCPTR==RIGHT)
		return;
step2:
	if(A[*LOCPTR]>A[RIGHT])
	{
		temp=A[*LOCPTR];
		A[*LOCPTR]=A[RIGHT];
		A[RIGHT]=temp;
		*LOCPTR=RIGHT;
	}
	goto step3;
step3:
	while(A[LEFT]<=A[*LOCPTR]&&LEFT!=*LOCPTR)
		LEFT++;
		if(*LOCPTR==LEFT)
			return;
		if(A[LEFT]>A[*LOCPTR])
		{
			temp=A[LEFT];
			A[LEFT]=A[*LOCPTR];
			A[*LOCPTR]=-temp;
			*LOCPTR=LEFT;
		}
}
