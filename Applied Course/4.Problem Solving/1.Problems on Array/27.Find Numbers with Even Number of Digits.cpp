#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ndigits(int n)
    {
        int count=0;
        while(n)
        {
            n/=10;
            count++;
        }
        return count%2==0;
    }
    int findNumbers(vector<int>& nums) {
        int count=0;
        for(int i=0;i<nums.size();i++)
            if(ndigits(nums[i]))
                count++;
        return count;
    }
};
int main()
{
    // https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
    return 0;
}