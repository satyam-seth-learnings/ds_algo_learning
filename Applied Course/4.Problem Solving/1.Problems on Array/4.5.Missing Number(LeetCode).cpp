#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=0,x=0;
        for(int i=1;i<=nums.size();i++)
            x^=i;
        for(int i=0;i<nums.size();i++)
            ans^=nums[i];
        return x^ans;
    }
};
int main()
{
    // https://leetcode.com/problems/missing-number/
    return 0;
}