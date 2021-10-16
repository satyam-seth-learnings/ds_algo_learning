#include<stdio.h>
#include<conio.h>
int main()
{
	int row1,col1,row2,col2;
	printf("Enter The Number Of Rows For First Matrix:");
	scanf("%d",&row1);
	printf("Enter The Number Of Columns For First Matrix:");
	scanf("%d",&col1);
	printf("Enter The Number Of Rows For Second Matrix:");
	scanf("%d",&row2);
	printf("Enter The Number Of Columns For Second Matrix:");
	scanf("%d",&col2);
	if(col1==row2)
	{
		int a[row1][col1],b[row2][col2],c[row1][col2];
		printf("Enter The %d Elements Of First Matrix:\n",row1*col1);
		for(int i=0;i<row1;i++)
			for(int j=0;j<col1;j++)
				scanf("%d",&a[i][j]);
		printf("First Matrix Is:\n");
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col1;j++)
				printf("%d\t",a[i][j]);
			printf("\n");
		}
		printf("Enter The %d Elements Of Second Matrix:\n",row2*col2);
		for(int i=0;i<row2;i++)
			for(int j=0;j<col2;j++)
				scanf("%d",&b[i][j]);
		printf("Second Matrix Is:\n");
		for(int i=0;i<row2;i++)
		{
			for(int j=0;j<col2;j++)
				printf("%d\t",b[i][j]);
			printf("\n");
		}
		for(int i=0;i<row1;i++)
			for(int j=0;j<col2;j++)
			{
				c[i][j]=0;
				for(int k=0;k<col1;k++)
					c[i][j]+=a[i][k]*b[k][j];
			}
		printf("Multiplication Of Two Matrix Is:\n");
		for(int i=0;i<row1;i++)
		{
			for(int j=0;j<col2;j++)
				printf("%d\t",c[i][j]);
			printf("\n");
		}
	}
	else
		printf("Can't Multiply");
	getch();
}
