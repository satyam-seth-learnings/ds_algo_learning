#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 26.1
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=1;i<=nums.size();i++)
            m[i]=2;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]--;
        for(auto ele:m)
            if(ele.second==2)
                v.push_back(ele.first);
        return v;
    }
};
// Logic-2
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for(auto num:nums)
        {
            int index=abs(num)-1;
            if(nums[index]>0)
                nums[index]=-nums[index];
        }
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                v.push_back(i+1);
        return v;
                
    }
};
int main()
{
    // https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
    return 0;
}