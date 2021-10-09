#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
     int count1bits(int n)
     {
        int count=0;
        while(n>0)
        {
            n&=n-1;
            count+=1;
        }
        return count;
     }
    int totalHammingDistance(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size()-1;i++)
            for(int j=i+1;j<nums.size();j++)
                result+=count1bits(nums[i]^nums[j]);
        return result;
    }
};
// Logic-2
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        for(int i=0;i<32;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
                if(nums[j]&(1<<i))
                    count+=1;
            result+=(count*(n-count));
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/total-hamming-distance
    return 0;
}