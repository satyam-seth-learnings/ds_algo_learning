#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n,int amt)
{
	int temp=0;
	int dp[101]={0};
	for(int i=1;i<amt+1;i++)
		dp[i]=INT_MAX;
	for(int i=1;i<amt+1;i++)
	{
		for(int j=1;j<n;j++)
		{
			if(arr[j]<=i)
                temp=dp[i-arr[j]];
            if(temp+1<dp[i])
                dp[i]=temp+1;
		}
	}
	return dp[amt];
}
int main()
{
	int arr[]={1,2,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<solve(arr,n,15);
	return 0;
}