#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> result;
    void permutations(vector<int>& nums,int l,int r)
    {
        if(l==r-1)
            result.push_back(nums);
        else
        {
            for(int i=l;i<r;i++)
            {
                swap(nums[l],nums[i]);
                permutations(nums,l+1,r);
                swap(nums[l],nums[i]);
            }
            
        }
    }  
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        permutations(nums,0,n);
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/permutations/
    return 0;
}