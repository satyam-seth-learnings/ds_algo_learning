#include<bits/stdc++.h>
using namespace std;
// Logic-1 Using DP T(n)=O(N^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int dp[2501];
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i] && dp[i]<dp[j]+1)
                    dp[i]=dp[j]+1;;
            }
        }
        return *max_element(dp,dp+n);
    }
};
// Logic-2 Using Binary Search T(n)=O(NlogN)
class Solution {
public:
    int CeilIndex(vector<int>& v, int l, int r, int key)
    {
        while(r-l>1)
        {
            int m=l+(r-l)/2;
            if(v[m]>=key)
                r=m;
            else
                l=m;
        }
        return r;
    }
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        vector<int> tail(nums.size(),0);
        int length=1;
        tail[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<tail[0])
                tail[0]=nums[i];
            else if(nums[i]>tail[length-1])
                tail[length++]=nums[i];
            else
                tail[CeilIndex(tail,-1,length-1,nums[i])]=nums[i];
        }
        return length;
    }
};
int main()
{
    // https://leetcode.com/problems/longest-increasing-subsequence
    return 0;
}