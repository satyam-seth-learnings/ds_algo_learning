#include<bits/stdc++.h>
using namespace std;
vector<int> solve(vector<int>& arr)
{
	vector<int> v;
	int n=arr.size();
	int current_max=INT_MIN;
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]>current_max)
		{
			v.push_back(arr[i]);
			current_max=arr[i];
		}
	}
	return v;
}
int main()
{
	vector<int> arr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		arr.push_back(x);
	}
	for(auto ele:solve(arr))
		cout<<ele<<" ";
	return 0;
}