#include<iostream>
using namespace std;
void merge(int arr[],int lb,int mid,int ub)
{
	int n1=mid-lb+1;
	int n2=ub-mid;
	int left[n1],right[n2];
	for(int i=0;i<n1;i++)
		left[i]=arr[lb+i];
	for(int j=0;j<n2;j++)
		right[j]=arr[mid+1+j];
	int i=0,j=0,k=lb;
	while(i<n1 && j<n2)
	{
		if(left[i]<=right[j])
		{
			arr[k]=left[i];
			i++;
		}
		else
		{
			arr[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=left[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=right[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=lb+(ub-lb)/2;
		mergeSort(arr,lb,mid);
		mergeSort(arr,mid+1,ub);
		merge(arr,lb,mid,ub);
	}
}
int main()
{
	int arr[]={7,4,2,8,2,1,5,3,6};
	int size=sizeof(arr)/sizeof(arr[0]);
	mergeSort(arr,0,size-1);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	return 0;
}
