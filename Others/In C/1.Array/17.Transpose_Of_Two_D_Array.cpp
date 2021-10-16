#include<stdio.h>
#include<conio.h>
int main()
{
	int row,col;
	printf("Enter The Number Of Rows:");
	scanf("%d",&row);
	printf("Enter The Number Of Columns:");
	scanf("%d",&col);
	int a[row][col],b[row][col];
	printf("Enter The %d Elements Of Matrix:\n",row*col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			scanf("%d",&a[i][j]);
	printf("Matrix Is:\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			b[i][j]=a[j][i];
	printf("Transposition Of Two Matrix Is:\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	getch();
}
