#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int n)
{
	int dp[11]={0};
	for(int i=1;i<n+1;i++)
	{
		int maxVal=INT_MIN;
		for(int j=0;j<i;j++)
		{
			maxVal=max(maxVal,arr[j]+dp[i-(j+1)]);
            dp[i]=maxVal;
		}
	}
	return dp[n];
}
int main()
{
	int arr[]={2,3,7,8,9};
	cout<<solve(arr,5);
	return 0;
}