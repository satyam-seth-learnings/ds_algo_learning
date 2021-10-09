#include<bits/stdc++.h>
using namespace std;
// Logic-1 Recursion T(n)=O(2^(m*n))
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1)
            return 1;
        return uniquePaths(m-1,n)+uniquePaths(m,n-1);
    }
};
// Logic-2 DP T(n)=O(mn)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[100][100];
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int j=0;j<n;j++)
            dp[0][j]=1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
        return dp[m-1][n-1];
    }
};
int main()
{
    // https://leetcode.com/problems/unique-paths/
    return 0;
}