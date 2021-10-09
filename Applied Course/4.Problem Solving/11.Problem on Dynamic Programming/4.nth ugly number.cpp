#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[1690]={0};
        int p2=0,p3=0,p5=0;
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            int next=min(dp[p2]*2,dp[p3]*3);
            next=min(next,dp[p5]*5);
            dp[i]=next;
            if(next==dp[p2]*2)
                p2++;
            if(next==dp[p3]*3)
                p3++;
            if(next==dp[p5]*5)
                p5++;
        }
        return dp[n-1];
    }
};
int main()
{
    // https://leetcode.com/problems/ugly-number-ii
    return 0;
}