#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int lmin=INT_MAX,rmax=INT_MIN;
            for(int j=0;j<i;j++)
                if(nums[j]<nums[i])
                {
                    lmin=nums[j];
                    break;
                }
            for(int j=i+1;j<n;j++)
                if(nums[i]<nums[j])
                {
                    rmax=nums[j];
                    break;
                }
            if(lmin<nums[i] && nums[i]<rmax)
                return true;
        }
        return false;
    }
};
// Logic-2
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int min_index=0,low=-1,mid=-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<=nums[min_index])
                min_index=i;
            else if(mid==-1)
            {
                low=min_index;
                mid=i;
            }
            else if(nums[i]<=nums[mid])
            {
                low=min_index;
                mid=i;
            }
            else
                return true;
        }
        return false;
    }
};
int main()
{
    // https://leetcode.com/problems/increasing-triplet-subsequence/
    return 0;
}