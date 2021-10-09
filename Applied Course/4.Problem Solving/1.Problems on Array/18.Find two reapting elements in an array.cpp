#include<bits/stdc++.h>
using namespace std;
// Logic-1
// void solve(int nums[],int n)
// {
// 	int range=n-2;
// 	int arr[range]={0};
//  	for(int i=0;i<n;i++)
//  		arr[nums[i]-1]++;
//  	for(int i=0;i<range;i++)
//  		if(arr[i]==2)
//  			cout<<i+1<<" ";
// }

// Logic-2
int factorial(int n)
{
	return (n==1||n==0)?1:factorial(n-1)*n;
}
void solve(int nums[],int n)
{
	int range=n-2;
	int sumRange=range*(range+1)/2;
	int prodRange=factorial(range);
	int sumNums=0,prodNums=1;
	for(int i=0;i<n;i++)
	{
		sumNums+=nums[i];
		prodNums*=nums[i];
	}
	int sum=sumNums-sumRange,prod=prodNums/prodRange;
	int diff=sqrt((sum*sum)-(4*prod));
	int first=(sum+diff)/2;
	int second=sum-first;
	cout<<first<<" "<<second;
}

// Logic-3
void solve(int arr[],int size)
{
	int Xor=arr[0];
    int set_bit_no;
    int i;  
    int n=size-2;  
    int x=0,y=0;
    for(i=1;i<size;i++)  
        Xor^=arr[i];  
    for(i=1;i<=n;i++)  
        Xor^=i;  
    set_bit_no=Xor & ~(Xor-1);  
    for(i=0;i<size;i++)  
    {  
        if(arr[i] & set_bit_no)  
        	x=x^arr[i];
        else
        	y=y^arr[i];
    }  
    for(i=1;i<=n;i++)  
    {  
        if(i & set_bit_no)  
        	x=x^i;
        else
        	y=y^i;
    }            
    cout<<"The two repeating elements are "<<y<<" "<<x;
}
int main()
{
	int n;
	cin>>n;
	int nums[n];
	for(int i=0;i<n;i++)
		cin>>nums[i];
	solve(nums,n);
	return 0;
}