#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)
            v.insert(v.begin()+index[i],nums[i]);
        return v;   
    }
};
int main()
{
    // https://leetcode.com/problems/create-target-array-in-the-given-order/
    return 0;
}