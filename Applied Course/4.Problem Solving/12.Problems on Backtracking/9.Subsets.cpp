#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef vector<vector<int> > vvi;
    typedef vector<int> vi;
    void backtrack(vi &nums,vvi &res, vi v=vi(),int i=0)
    {
        if(i==nums.size())
        {
            res.emplace_back(v);
            return ;
        }
        backtrack(nums,res,v,i+1);
        v.emplace_back(nums[i]);
        backtrack(nums,res,v,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;
        backtrack(nums,res);
        return res;
    }
};
int main()
{
    // https://leetcode.com/problems/subsets/
    return 0;
}