#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        set<long> s(nums.begin(),nums.end());
        long nums_sum=0;
        long s_sum=0;
        for(auto num:nums)
            nums_sum+=num;
        for(auto ele:s)
            s_sum+=ele;
        return (3*s_sum-nums_sum)/2;
    }
};
// Logic-2
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        for(auto num:nums)
            m[num]++;
        for(auto ele:m)
            if(ele.second==1)
                return ele.first;
        return 0;
    }
};
// Logic-3
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int one=0,two=0;
        for(auto num:nums)
        {
            two|=one&num;
            one^=num;
            int non_three=~(one & two);
            one&=non_three;
            two&=non_three;
        }
        return one;
    }
};
int main()
{
    // https://leetcode.com/problems/single-number-ii/
    return 0;
}