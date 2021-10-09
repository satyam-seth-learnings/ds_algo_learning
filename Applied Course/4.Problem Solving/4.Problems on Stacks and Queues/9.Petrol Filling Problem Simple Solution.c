#include<stdio.h>
#include<stdlib.h>

int getTour(int petrol[],int distance[], int n)
{
	int sum=0,start=0,diff=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+petrol[i]-distance[i];
            
            if(sum<0)
            {
                start=i+1;//changing start point
                diff+=sum;//storing the negative values
                sum=0;//starting again form new station
            }
        }
        return sum+diff>0? start: -1;//if sum+diff <0 which means the petrol and distance is not matched
}

int main()
{
	int petrol[4]={4,6,7,4};
	int distance[4]={6,5,3,5}; 
  
  	int value=getTour(petrol,distance,4);
  	printf("%d\n",value);
}