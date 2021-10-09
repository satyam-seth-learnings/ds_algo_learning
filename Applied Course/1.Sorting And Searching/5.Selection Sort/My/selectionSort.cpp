#include<bits/stdc++.h>
using namespace std;
void selectionSort(int arr[],int n)
{
	for(int j=0;j<n-1;j++)
	{
		int iMin=j;
		for(int i=j+1;i<n;i++)
			if(arr[i]<arr[iMin])
				iMin=i;
		if(iMin!=j)
			swap(arr[j],arr[iMin]);
	}
}
void Print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main()
{
	int arr[]={7,6,9,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr,n);
	cout<<"Sorted Array: ";
	Print(arr,n);
	return 0;
}
