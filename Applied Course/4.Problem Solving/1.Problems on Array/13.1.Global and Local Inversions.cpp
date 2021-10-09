// Logic-1
// #include<bits/stdc++.h>
// using namespace std;
// int mergeAndCount(vector<int>& A,int low,int mid,int high)
// {
// 	int count=0,i=low,j=mid+1,k=low;
// 	vector<int> temp(A);
// 	while(i<=mid && j<=high)
// 	{
// 		if(A[i]>A[j])
// 		{
// 			count+=(mid-i+1);
// 			temp[k++]=A[j++];
// 		}
// 		else
// 			temp[k++]=A[i++];
// 	}
// 	while(i<=mid)
// 		temp[k++]=A[i++];
// 	while(j<=high)
// 		temp[k++]=A[j++];
// 	A=temp;
// 	return count;
// }
// int countGlobalInversions(vector<int>& A,int low,int high)
// {
// 	if(low>=high)
// 		return 0;
// 	int mid=low+(high-low)/2;
// 	int l=countGlobalInversions(A,low,mid);
// 	int r=countGlobalInversions(A,mid+1,high);
// 	int m=mergeAndCount(A,low,mid,high);
// 	return l+r+m;
// }
// int countlocalInversions(vector<int>& A,int low,int high)
// {
// 	if(low>=high)
// 		return 0;
// 	int count=0;
// 	for(int i=low;i<high;i++)
// 		if(A[i]>A[i+1])
// 			count++;
// 	return count;
// }
// bool compareInversions(vector<int>& A)
// {
// 	int localCount=countlocalInversions(A,0,A.size()-1);
// 	int globalCount=countGlobalInversions(A,0,A.size()-1);
// 	cout<<globalCount<<" "<<localCount;
// 	return globalCount==localCount;
// }
// int main()
// {
// 	vector<int> v;
// 	int n;
// 	cin>>n;
// 	for(int i=0;i<n;i++)
// 	{
// 		int x;
// 		cin>>x;
// 		v.push_back(x);
// 	}
// 	cout<<compareInversions(v);
// 	return 0; 
// }

// Logic-2
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        for(int i=0;i<n;i++)
            if(abs(A[i]-i)>1)
                return false;
         return true;
    }
};