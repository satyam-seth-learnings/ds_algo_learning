#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int p,int q)
{
	int pivot=arr[p];
	int i=p;
	for(int j=p+1;j<=q;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i],arr[p]);
	return i;
}
void quickSort(int arr[],int p,int r)
{
	if(p<r)
	{
		int q=partition(arr,p,r);
		quickSort(arr,p,q-1);
		quickSort(arr,q+1,r);
	}
}
void Print(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main()
{
	int arr[]={7,8,9,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	quickSort(arr,0,n-1);
	cout<<"Sorted Array: ";
	Print(arr,n);
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//int partition(int arr[],int lb,int ub)
//{
//	int pivot=arr[ub];
//	int i=lb-1;
//	for(int j=lb;j<=ub-1;j++)
//	{
//		if(arr[j]<pivot)
//		{
//			i++;
//			int temp=arr[i];
//			arr[i]=arr[j];
//			arr[j]=temp;
//		}
//	}
//	int temp=arr[i+1];
//	arr[i+1]=arr[ub];
//	arr[ub]=temp;
//	return i+1;
//}
//void quickSort(int arr[],int lb,int ub)
//{
//	if(lb<ub)
//	{
//		int pi=partition(arr,lb,ub);
//		quickSort(arr,lb,pi-1);
//		quickSort(arr,pi+1,ub);
//	}
//}
//int main()
//{
//	int arr[]={12, 11, 13, 5, 6, 7};
//	int n=sizeof(arr)/sizeof(arr[0]);
//	quickSort(arr,0,n-1);
//	for(int i=0;i<n;i++)
//		cout<<arr[i]<<" ";
//	return 0;
//}
