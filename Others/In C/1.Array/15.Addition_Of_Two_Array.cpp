#include<stdio.h>
#include<conio.h>
int main()
{
	int row,col;
	printf("Enter The Number Of Rows:");
	scanf("%d",&row);
	printf("Enter The Number Of Columns:");
	scanf("%d",&col);
	int a[row][col],b[row][col],c[row][col];
	printf("Enter The %d Elements Of First Matrix:\n",row*col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			scanf("%d",&a[i][j]);
	printf("First Matrix Is:\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%d\t",a[i][j]);
		printf("\n");
	}
	printf("Enter The %d Elements Of Second Matrix:\n",row*col);
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			scanf("%d",&b[i][j]);
	printf("Second Matrix Is:\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%d\t",b[i][j]);
		printf("\n");
	}
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			c[i][j]=a[i][j]+b[i][j];
	printf("Addtion Of Two Matrix Is:\n");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
			printf("%d\t",c[i][j]);
		printf("\n");
	}
	getch();
}
