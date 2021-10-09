#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=(n-1)/2;
        int k=0;
        int temp[n];
        for(int i=0;i<=mid;i++)
        {
            temp[k]=nums[mid-i];
            if(k+1<n)
                temp[k+1]=nums[n-1-i];
            k+=2;
        }
        for(int i=0;i<n;i++)
            nums[i]=temp[i];
    }
};
int main()
{
    // https://leetcode.com/problems/wiggle-sort-ii/
    return 0;
}