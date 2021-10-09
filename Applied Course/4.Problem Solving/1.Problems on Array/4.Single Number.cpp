#include<bits/stdc++.h>
using namespace std;

// Logic-1
//int findOdd(int arr[],int n)
//{
//	unordered_map<int,int> m;
//	for(int i=0;i<n;i++)
//		m[arr[i]]++;
//	for(auto ele:m)
//		if(ele.second%2!=0)
//		return ele.first;
//}

// Logic-2
//int findOdd(int arr[],int n)
//{
//	for(int i=0;i<n;i++)
//	{
//		int count=0;
//		for(int j=0;j<n;j++)
//			if(arr[i]==arr[j])
//				count++;
//		if(count%2!=0)
//			return arr[i];
//	}
//}

// Logic-3
int findOdd(int arr[],int n)
{
	int x=0;
	for(int i=0;i<n;i++)
		x^=arr[i];
	return x;
}
int main()
{
//	int arr[]={5,7,2,7,5,2,5};
	int arr[]={1,2,3,2,3,1,3};
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<findOdd(arr,n);
	return 0;
}