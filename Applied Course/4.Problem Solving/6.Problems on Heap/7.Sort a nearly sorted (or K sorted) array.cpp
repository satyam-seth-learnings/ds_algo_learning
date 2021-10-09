#include<bits/stdc++.h>
using namespace std;
void sort(int arr[],int n,int k)
{
	int index=0;
	priority_queue<int,vector<int>,greater<int>> min_heap(arr,arr+k+1);
	for(int i=k+1;i<n;i++)
	{
		arr[index++]=min_heap.top();
		min_heap.pop();
		min_heap.push(arr[i]);
	}
	while(min_heap.size())
	{
		arr[index++]=min_heap.top();
		min_heap.pop();
	}
}
void print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main()
{
	int arr[]={6,5,3,2,8,10,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	sort(arr,n,k);
	cout<<"Sorted Array: ";
	print(arr,n);
	return 0;
}