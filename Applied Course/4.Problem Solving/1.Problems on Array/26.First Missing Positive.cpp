#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        int result=1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            if(nums[i]==result)
                result++;
        return result;
    }
};
// Logic-2
class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {
        if(find(nums.begin(),nums.end(),1)==nums.end())
            return 1;
        int n=nums.size();
        for(int i=0;i<n;i++)
            if(nums[i]<=0 || nums[i]>n)
                nums[i]=1;
        for(int i=0;i<n;i++)
        {
            int val=abs(nums[i]);
            if(val==n)
                nums[0]=-abs(nums[0]);
            else
                nums[val]=-abs(nums[val]);
        }
        for(int i=1;i<n;i++)
            if(nums[i]>0)
                return i;
        if(nums[0]>0)
            return n;
        return n+1;
    }
};
int main()
{
    // https://leetcode.com/problems/first-missing-positive/
    return 0;
}