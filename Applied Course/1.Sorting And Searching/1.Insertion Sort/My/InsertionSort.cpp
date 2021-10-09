#include<bits/stdc++.h>
using namespace std;
void InsertionSort(int arr[],int n)
{
	for(int j=1;j<n;j++)
	{
		int key=arr[j];
		int i=j-1;
		while(i>=0 && arr[i]>key)
		{
			arr[i+1]=arr[i];
			i--;
		}
		arr[i+1]=key;
	}
}
void Print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
int main()
{
	int a[]={6,5,3,1,8,7,2,4};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"Before Sorting: ";
	Print(a,n);
	InsertionSort(a,n);
	cout<<"After Sorting: ";
	Print(a,n);
	return 0;
}
