#include<bits/stdc++.h>
using namespace std;
// Logic-1 Recursion T(n)=O(2^n)
class Solution {
public:
    int maximize_loot(vector<int>& nums,int start,int end)
    {
        if(start>end)
            return 0;
        if(start==end)
            return nums[start];
        if(start+1==end)
            return max(nums[start],nums[end]);
        return max(nums[start]+maximize_loot(nums,start+2,end),maximize_loot(nums,start+1,end));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return maximize_loot(nums,0,n-1);
    }
};
// Logic-2 Dynamic Programming T(n)=O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        int dp[100];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        return dp[n-1];
    }
};
// Logic-3 S(n)=O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        if(n==2)
            return max(nums[0],nums[1]);
        int value1=nums[0];
        int value2=max(nums[0],nums[1]);
        int max_value;
        for(int i=2;i<n;i++)
        {
            max_value=max(nums[i]+value1,value2);
            value1=value2;
            value2=max_value;
        }
        return max_value;
    }
};
int main()
{
    // https://leetcode.com/problems/house-robber/
    return 0;
}