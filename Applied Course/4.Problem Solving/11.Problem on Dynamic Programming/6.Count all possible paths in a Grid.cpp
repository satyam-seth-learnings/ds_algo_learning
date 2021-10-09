// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Logic-1
    long long int numberOfPaths(int m, int n){
        // code here
        if (m==1 || n==1)
            return 1;
        return numberOfPaths(m-1,n)+numberOfPaths(m,n-1);
    }
    // Logic-2
    long long int numberOfPaths(int m, int n){
        // code here
        int count[m][n];
        for (int i = 0; i < m; i++)
            count[i][0] = 1;
        for (int j = 0; j < n; j++)
            count[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                count[i][j] = count[i - 1][j] + count[i][j - 1];
        }
        return count[m - 1][n - 1];
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends