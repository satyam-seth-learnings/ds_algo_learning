#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& arr,int sum)
{
	int l,r,i,n=arr.size();
	for(i=0;i<n-1;i++)
		if(arr[i]>arr[i+1])
			break;
	l=(i+1)%n;
	r=i;
	while(l!=r)
	{
		if(arr[l]+arr[r]==sum)
			return 1;
		else if(arr[l]+arr[r]<sum)
			l=(l+1)%n;
		else
			r=(n+r-1)%n;
	}
	return -1;
}
int main()
{
	vector<int> arr;
	int sum,n;
	cin>>sum>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		arr.push_back(x);
	}
	cout<<solve(arr,sum);
	return 0;
}