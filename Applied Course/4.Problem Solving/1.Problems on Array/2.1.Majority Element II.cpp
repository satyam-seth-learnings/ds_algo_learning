#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int maj1=INT_MAX,maj2=INT_MAX,count1=0,count2=0;
        for(auto ele:nums)
        {
            if(maj1==ele)
                count1++;
            else if(maj2==ele)
                count2++;
            
            else
            {
                if(count1==0)
                {
                    maj1=ele;
                    count1++;
                }
                else if(count2==0)
                {
                    maj2=ele;
                    count2++;
                }
                else
                {
                    count1--;
                    count2--;
                }
            }
        }
        count1=0;
        count2=0;
        for(auto ele:nums)
        {
            if(ele==maj1)
                count1++;
            else if(ele==maj2)
                count2++;
        }
        if(count1>nums.size()/3)
            res.push_back(maj1);
        if(count2>nums.size()/3)
            res.push_back(maj2);
        return res;
    }
};
int main()
{
    // https://leetcode.com/problems/majority-element-ii/
    return 0;
}