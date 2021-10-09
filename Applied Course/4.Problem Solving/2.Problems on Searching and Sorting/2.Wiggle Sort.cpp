// https://leetcode.com/problems/wiggle-sort/
#include<bits/stdc++.h>
using namespace std;
// Logic-1
void wiggleSort(vector<int>& v)
{
	sort(v.begin(),v.end());
	for(int i=1;i<v.size()-1;i+=2)
		swap(v[i],v[i+1]);
}
// Logic-2
void wiggleSort(vector<int>& v)
{
	for(int i=1;i<v.size();i+=2)
	{
		if(i>0 && v[i]<v[i-1])
			swap(v[i],v[i-1]);
		if(i<v.size()-1 && v[i]<v[i+1])
			swap(v[i],v[i+1]);
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> nums;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		nums.push_back(x);
	}
	wiggleSort(nums);
	for(auto num:nums)
		cout<<num<<" ";
	return 0;
}