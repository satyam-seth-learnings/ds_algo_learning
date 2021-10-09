#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
            ans^=nums.at(i);
        return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/single-number/
    return 0;
}