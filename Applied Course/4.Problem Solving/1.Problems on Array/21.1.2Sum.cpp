#include<bits/stdc++.h>
using namespace std;
// Lgoic-1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    result.push_back(i);
                    result.push_back(j);
                }
            }
        }
        return result;
    }
};
// Logic-2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                result.push_back(m[target-nums[i]]);
                result.push_back(i);
            }
            m[nums[i]]=i;
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/two-sum
    return 0;
}