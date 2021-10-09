#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto ele:m)
            if(ele.second==1)
                result.push_back(ele.first);
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/single-number-iii/
    return 0;
}