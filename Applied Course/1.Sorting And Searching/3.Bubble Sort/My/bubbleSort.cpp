#include<iostream>
using namespace std; 
void bubbleSort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		bool swapped=false;
		for(int j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				swapped=true;
			}
		}
		if(swapped==false)
			break;
	}
}
int main()
{
	int arr[]={1,7,3,8,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,size);
	cout<<"Sorted Array:";
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	return 0;
}
