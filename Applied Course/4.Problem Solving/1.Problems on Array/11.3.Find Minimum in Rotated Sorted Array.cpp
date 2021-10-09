#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l,i,n=nums.size();
        for(i=0;i<n-1;i++)
            if(nums[i]>nums[i+1])
                break;
        return nums[(i+1)%n];
    }
};
int main()
{
    // https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
    return 0;
}