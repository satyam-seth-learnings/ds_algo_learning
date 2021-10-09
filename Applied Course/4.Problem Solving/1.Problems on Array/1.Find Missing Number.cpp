//https://www.geeksforgeeks.org/find-the-missing-number/

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int MissingNumber(vector<int>& array, int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];

        cout << MissingNumber(array, n) << "\n";
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

//Logic-1
//int MissingNumber(vector<int>& array, int n) {
//    // Your code goes here
//    int sum=n*(n+1)/2;
//    for(auto ele:array)
//        sum-=ele;
//    return sum;
//}

//Logic-2
int MissingNumber(vector<int>& array, int n) {
    // Your code goes here
    int x1=1,x2=array[0];
    for(int i=2;i<=n;i++)
        x1^=i;
    for(int i=1;i<n;i++)
        x2^=array[i];
    return x1^x2;
}
