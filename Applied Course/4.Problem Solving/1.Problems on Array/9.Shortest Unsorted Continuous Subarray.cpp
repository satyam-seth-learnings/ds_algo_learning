#include<bits/stdc++.h>
using namespace std;
// Logic-1 - Time Limit Exceeded
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=n,end=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
                if(nums[i]>nums[j])
                {
                    start=min(start,i);
                    end=max(end,j);
                }
        }
        if (end-1<0)
            return 0;
        return end-start+1;
    }
};
// Logic-2
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=n,end=0;
        vector<int> v=nums;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            if(nums[i]!=v[i])
            {
                start=min(start,i);
                end=max(end,i);
            }
        if (end-1<0)
            return 0;
        return end-start+1;
    }
};
// Logic-3
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int start=n,end=0;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && nums[s.top()]>nums[i])
            {
                start=min(start,s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty())
            s.pop();
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && nums[s.top()]<nums[i])
            {
                end=max(end,s.top());
                s.pop();
            }
            s.push(i);
        }
        if(end-start>=0)
            return end-start+1;
        return 0;
    }
};
int main()
{
    // https://leetcode.com/problems/shortest-unsorted-continuous-subarray
    return 0;
}