#include<bits/stdc++.h>
using namespace std;
bool canPartition(int start,vector<int>& nums,bool used[],int k,int inProgressBucketSum,int targetBucketSum)
{
	if(k==1)
		return true;
	if(inProgressBucketSum==targetBucketSum)
		return canPartition(0,nums,used,k-1,0,targetBucketSum);
	for(int i=start;i<nums.size();i++)
	{
		if(!used[i])
		{
			used[i]=true;
			if(canPartition(i+1,nums,used,k,inProgressBucketSum+nums[i],targetBucketSum))
			return true;
		}
		used[i]=false;	
	}
	return false;
}
bool solve(vector<int>& nums,int k)
{
	int sum=accumulate(nums.begin(),nums.end(),0);
	if(k==0 || sum%k!=0)
		return false;
	bool used[nums.size()];
	return canPartition(0,nums,used,k,0,sum/k);
}
int main()
{
	vector<int> v;
	int k,n;
	cin>>k>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<solve(v,k);
	return 0; 
}