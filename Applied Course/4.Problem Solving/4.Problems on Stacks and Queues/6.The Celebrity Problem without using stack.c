#include <stdio.h>

int matrix[5][5]={{0,0,0},
				  {1,0,0},
			      {1,0,0}};
int knows(int a,int b)
{
	return matrix[a][b];
}
int main(void) {
	int celeb=0,n=3;
    for(int i=0;i<n;i++)
    if(knows(celeb,i)==1)
     celeb=i;
        
    for (int i = 0; i < n; i++) 
    { 
    if ( (i != celeb) && (knows(celeb,i)==1|| knows(i,celeb)!=1 ) )
           printf("-1");
    } 
    printf("%d",celeb);
	return 0;
}
