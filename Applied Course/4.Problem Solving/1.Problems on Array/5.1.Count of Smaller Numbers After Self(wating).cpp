#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            int count=0;
            for(int j=0;j<nums.size();j++)
                if(nums[i]>nums[j])
                    count++;
            v.push_back(count);
        }
        return v;
    }
};
// Logic-2
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        vector<int> v(nums.begin(),nums.end());
        unordered_map<int,int> m;
        sort(v.begin(),v.end());
        for(int i=0;i<nums.size();i++)
            if(m.find(v[i])==m.end())
                m[v[i]]=i;
        for(int i=0;i<nums.size();i++)
            result.push_back(m[nums[i]]);
        return result;
    }
};
// Logic-3
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result(nums.size(),0);
        int temp[101]={0};
        for(int i=0;i<nums.size();i++)
            temp[nums[i]]++;
        for(int i=1;i<101;i++)
            temp[i]+=temp[i-1];
        for(int i=0;i<nums.size();i++)
            if(nums[i]>0)
                result[i]=temp[nums[i]-1];
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
    return 0;
}