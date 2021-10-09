#include<bits/stdc++.h>
using namespace std;
void MAX_HEAPIFY(int arr[],int n,int i)
{
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && arr[left]>arr[i])
		largest=left;
	else
		largest=i;
	if(right<n && arr[right]>arr[largest])
		largest=right;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		MAX_HEAPIFY(arr,n,largest);
	}
}
void BUILD_MAX_HEAP(int arr[],int n)
{
	int len=n/2-1;
	for(int i=len;i>=0;i--)
		MAX_HEAPIFY(arr,n,i);
}
void HEAP_SORT(int arr[],int n)
{
	BUILD_MAX_HEAP(arr,n);
	for(int i=n-1;i>0;i--)
	{
		swap(arr[i],arr[0]);
		n--;
		MAX_HEAPIFY(arr,n,0);
	}
}
int main()
{
	int arr[]={4,1,3,2,16,9,10,14,8,7};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"Before Sorting: ";
	for(int i:arr)
		cout<<i<<" ";
	HEAP_SORT(arr,n);
	cout<<endl<<"After Sorting: ";
	for(int i:arr)
		cout<<i<<" ";
	return 0;
}
