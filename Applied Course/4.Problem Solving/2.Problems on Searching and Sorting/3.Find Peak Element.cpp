#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        for(int i=0;i<nums.size()-1;i++)
            if(nums[i]>nums[i+1])
                return i;
        return nums.size()-1;
    }
};
// Logic-2
class Solution {
public:
    int binarySeacrh(vector<int>& nums,int start,int end,int n)
    {
        int mid=(start+end)/2;
        if((mid==0 || nums[mid-1]<nums[mid]) && (mid==n-1 || nums[mid+1]<nums[mid]))
            return mid;
        else if(mid>0 && nums[mid-1]>nums[mid])
            return binarySeacrh(nums,start,mid-1,n);
        return binarySeacrh(nums,mid+1,end,n);
    }
    int findPeakElement(vector<int>& nums) 
    {
        return binarySeacrh(nums,0,nums.size()-1,nums.size());
    }
};
// Logic-3
class Solution {
public:
    int findPeakElement(vector<int>& nums) 
    {
        int start=0,end=nums.size()-1;
        while(start<end)
        {
            int mid=(start+end)/2;
            if(nums[mid]>nums[mid+1])
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
};
int main()
{
    // https://leetcode.com/problems/find-peak-element/
    // https://leetcode.com/problems/peak-index-in-a-mountain-array
    return 0;
}