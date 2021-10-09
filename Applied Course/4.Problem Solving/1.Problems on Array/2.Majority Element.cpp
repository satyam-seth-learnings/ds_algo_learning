// https://www.geeksforgeeks.org/majority-element/
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int size)
{
    
    // your code here
    // Logic-1 Space Complexity - O(n)
    // map<int,int> m;
    // for(int i=0;i<size;i++)
    //     m[a[i]]++;
    // for(auto ele:m)
    //     if(ele.second>size/2)
    //         return ele.first;
    // return -1;

    // Logic-2 Space Coplexity - O(1)
    int maj,count=0;
    for(int i=0;i<size;i++)
    {
        if(count==0)
        {
            maj=a[i];
            count++;
        }
        else
        {
            if(maj==a[i])
                count++;
            else
                count--;
        }
    }
    count=0;
    for(int i=0;i<size;i++)
        if(maj==a[i])
            count++;
    if(count>size/2)
        return maj;
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends
