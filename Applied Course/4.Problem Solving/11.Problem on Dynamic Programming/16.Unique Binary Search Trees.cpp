#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        int dp[20]={0};
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++)
            for(int j=1;j<i+1;j++)
                dp[i]+=dp[j-1]*dp[i-j];
        return dp[n];
    }
};
int main()
{
    // https://leetcode.com/problems/unique-binary-search-trees/
    return 0;
}