#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0=0,count1=0,count2=0;
        for(auto ele:nums)
        {
            if(ele==0)
                count0++;
            else if(ele==1)
                count1++;
            else
                count2++;
        }
        int i=0;
        while(count0)
        {
            nums[i]=0;
            count0--;
            i++;
        }
        while(count1)
        {
            nums[i]=1;
            count1--;
            i++;
        }
        while(count2)
        {
            nums[i]=2;
            count2--;
            i++;
        }
    }
};
// Logic-2
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c=0,l=0,h=nums.size()-1;
        while(c<=h)
        {
            if(nums[c]==0)
            {
                swap(nums[l],nums[c]);
                l++;
                c++;
            }
            else if(nums[c]==1)
                c++;
            else
            {
                swap(nums[c],nums[h]);
                h--;
            }
        }
    }
};
int main()
{
    // https://leetcode.com/problems/sort-colors/
    return 0;
}