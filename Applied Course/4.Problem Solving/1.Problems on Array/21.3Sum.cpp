#include<bits/stdc++.h>
using namespace std;
// Logic-1
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int> > result;
//         for(int i=0;i<n-2;i++)
//         {
//             for(int j=i+1;j<n-1;j++)
//             {
//                 for(int k=j+1;k<n;k++)
//                 {
//                     if(nums[i]+nums[j]+nums[k]==0)
//                     {
//                         vector<int> v;
//                         v.push_back(nums[i]);
//                         v.push_back(nums[j]);
//                         v.push_back(nums[k]);
//                         sort(v.begin(),v.end());
//                         result.push_back(v);
//                     }
//                 }
//             }
//         }
//         return result;
//     }
// };
// // Logic-2
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n=nums.size();
//         set<vector<int> > result;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n-1;i++)
//         {
//             int l=i+1,r=n-1;
//             while(l<r)
//             {
//                 int sum=nums[i]+nums[l]+nums[r];
//                 if(sum==0)
//                 {
//                     vector<int> v;
//                     v.push_back(nums[i]);
//                     v.push_back(nums[l]);
//                     v.push_back(nums[r]);
//                     result.insert(v);
//                     l++;
//                     r--;
//                 }
//                 else if(sum<0)
//                     l++;
//                 else
//                     r--;
//             }
//         }
//         vector<vector<int>> ans;
//         for(auto ele:result)
//             ans.push_back(ele);
//         return ans;
//     }
// };
// Above both are not work
// Logic-3
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || nums[i]!=nums[i-1])
            {
                int l=i+1,r=n-1;
                while(l<r)
                {
                    int sum=nums[i]+nums[l]+nums[r];
                    if(sum==0)
                    {
                        result.push_back({nums[i],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1])
                            l++;
                        while(l<r && nums[r]==nums[r-1])
                            r--;
                        l++;
                        r--;
                    }
                    else if(sum>0)
                        r--;
                    else
                        l++;
                }
            }
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/3sum/
    return 0;
}