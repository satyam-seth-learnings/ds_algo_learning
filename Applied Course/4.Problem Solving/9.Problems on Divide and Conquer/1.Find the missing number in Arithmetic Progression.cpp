#include<bits/stdc++.h>
using namespace std;
// Logic-1 T(n)=O(n)
int solve(int arr[],int n,int d)
{
	for(int i=0;i<n;i++)
		if(arr[i]!=arr[0]+d*i)
			return arr[0]+d*i;
}
// Logic-2
int findMissing(int arr[],int min,int max,int d)
{
	if(min>max)
		return -1;
	int mid=min+(max-min)/2;
	if(min==max)
		if(arr[min]!=arr[0]+(d*mid))
			return arr[0]+(d*mid);
	if(arr[mid]==arr[0]+(d*mid))
		min=mid+1;
	else
		max=mid-1;
	findMissing(arr,min,max,d);
}
int main()
{
	int arr[]={0,2,4,6,10,12,14};
	int n=sizeof(arr)/sizeof(arr[0]);
	int d=2;
	cout<<solve(arr,n,d);
    cout<<findMissing(arr,0,n,d);
	return 0;
}