#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int closestSum=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<abs(closestSum-target))
                    closestSum=sum;
                if(sum<target)
                    l++;
                else
                    r--;
            }
        }
        return closestSum;
    }
};
int main()
{
    // https://leetcode.com/problems/3sum-closest/
    return 0;
}