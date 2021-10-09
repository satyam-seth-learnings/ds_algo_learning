#include<bits/stdc++.h>
using namespace std;
int mergeAndCount(vector<int>& A,int low,int mid,int high)
{
	int count=0,i=low,j=mid+1,k=low;
	vector<int> temp(A);
	while(i<=mid && j<=high)
	{
		if(A[i]>A[j])
		{
			count+=(mid-i+1);
			temp[k++]=A[j++];
		}
		else
			temp[k++]=A[i++];
	}
	while(i<=mid)
		temp[k++]=A[i++];
	while(j<=high)
		temp[k++]=A[j++];
	for(int i=low;i<=high;i++)
		A[i]=temp[i];
	return count;
}
int countInversions(vector<int>& A,int low,int high)
{
	if(low>=high)
		return 0;
	int mid=low+(high-low)/2;
	int l=countInversions(A,low,mid);
	int r=countInversions(A,mid+1,high);
	int m=mergeAndCount(A,low,mid,high);
	return l+r+m;
}
int main()
{
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	cout<<countInversions(v,0,v.size()-1);
	return 0; 
}