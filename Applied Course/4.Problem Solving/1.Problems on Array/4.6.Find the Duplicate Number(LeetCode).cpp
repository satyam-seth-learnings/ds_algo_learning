#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto ele:m)
            if(ele.second>1)
            {
                ans=ele.first;
                break;
            }
        return ans;
    }
};
// Logic-2
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        for(int i=0;i<nums.size();i++)
        {
            int index=abs(nums[i])-1;
            if(nums[index]<0)
            {
                ans=abs(nums[i]);
                break;
            }
            nums[index]=-nums[index];
        }
        return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/find-the-duplicate-number/
    return 0;
}