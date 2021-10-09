#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=nums[0];
        int max_curr=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max_curr=max(nums[i],max_curr+nums[i]);
            if(max_sum<max_curr)
                max_sum=max_curr;
        }
        return max_sum;
    }
};
int main()
{
    // https://leetcode.com/problems/maximum-subarray
    return 0;
}