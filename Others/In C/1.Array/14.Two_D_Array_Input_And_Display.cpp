#include<stdio.h>
#include<conio.h>
int main()
{
	int row,col;
	printf("Enter The Number Of Rows:");
	scanf("%d",&row);
	printf("Enter The Number Of Columns:");
	scanf("%d",&col);
	int a[row][col];
	printf("Enter The %d Elements:\n",row*col);
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
}
