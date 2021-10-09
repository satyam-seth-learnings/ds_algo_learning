#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> result;
        for(auto num:nums)
            if(num!=0)
                result.push_back(num);
        for(auto num:nums)
            if(num==0)
                result.push_back(num);
        nums=result;
    }
};
// Logic-2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int last_non_zero_index=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                nums[last_non_zero_index]=nums[i];
                last_non_zero_index+=1;
            }
        }
        for(int i=last_non_zero_index;i<n;i++)
            nums[i]=0;
    }
};
int main()
{
    // https://leetcode.com/problems/move-zeroes/
    return 0;
}