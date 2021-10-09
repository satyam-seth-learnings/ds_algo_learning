#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    bool findSubsetSum(vector<int>& nums,int sum)
    {
        int n=nums.size();
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                else if(j==0)
                    dp[i][j]=true;
                else if(nums[i-1]<=j)
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        return findSubsetSum(nums,sum/2);
    }
};
int main()
{
    // https://leetcode.com/problems/partition-equal-subset-sum/
    return 0;
}