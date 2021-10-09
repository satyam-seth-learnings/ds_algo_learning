// https://www.geeksforgeeks.org/find-two-missing-numbers-set-2-xor-based-solution/
#include<bits/stdc++.h>
using namespace std;
// Logic-1
// void solve(int nums[],int n,int range)
// {
// 	int arr[range]={0};
// 	for(int i=0;i<n;i++)
// 		arr[nums[i]-1]=1;
// 	for(int i=0;i<range;i++)
// 		if(!arr[i])
// 			cout<<i+1<<" ";
// }

// Logic-2
// void solve(int nums[],int n,int range)
// {
// 	int sum=range*(range+1)/2,sumNums;
// 	for(int i=0;i<n;i++)
// 		sumNums+=nums[i];
// 	int avgDiff=(sum-sumNums)/2;
// 	int lsum=0,rsum=0,lsumNums=0,rsumNums=0;
// 	for(int i=1;i<=range;i++)
// 	{
// 		if(i<=avgDiff)
// 			lsum+=i;
// 		else if(i>avgDiff)
// 			rsum+=i;
// 	}
// 	for(int i=0;i<n;i++)
// 	{
// 		if(nums[i]<=avgDiff)
// 			lsumNums+=nums[i];
// 		else if(nums[i]>avgDiff)
// 			rsumNums+=nums[i];
// 	}
// 	cout<<lsum-lsumNums<<" "<<rsum-rsumNums;
// }

// Logic-3
int solve(int arr[],int n)
{
	int range=n+2;
	int XOR=arr[0];
    for (int i=1;i<n;i++) 
        XOR^=arr[i];
    for (int i=1;i<=range;i++) 
        XOR^=i;
    int set_bit_no=XOR & ~(XOR-1);
  	int x=0,y=0;
    for (int i=0;i<n;i++) 
    { 
        if (arr[i] & set_bit_no) 
            x=x^arr[i];
        else
            y=y^arr[i];
    } 
    for (int i=1;i<=range;i++) 
    { 
        if (i & set_bit_no) 
            x=x^i;
        else
            y=y^i;
	}
	cout<<x<<" "<<y;
}
int main()
{
	int range,n;
	cin>>range>>n;
	int nums[n];
	for(int i=0;i<n;i++)
		cin>>nums[i];
	solve(nums,n,range);
	return 0;
}
