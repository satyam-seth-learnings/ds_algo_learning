// https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0#
#include <iostream>
using namespace std;
void swap(int &x,int &y)
{
    int temp=x;
    x=y;
    y=temp;
}
void reverse(int arr[],int l,int h)
{
    while(l<h)
    {
        swap(arr[l],arr[h]);
        l++;
        h--;
    }
}
void rotate(int arr[],int n,int k)
{
    if(k>n)
        k%=n;
    reverse(arr,0,k-1);
    reverse(arr,k,n-1);
    reverse(arr,0,n-1);
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n];
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
	    rotate(arr,n,k);
	    for(int i=0;i<n;i++)
	        cout<<arr[i]<<" ";
	   cout<<endl;
	}   
	return 0;
}