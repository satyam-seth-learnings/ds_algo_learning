#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        int ans;
        for(auto ele:m)
            if(ele.second==1)
            {
                ans=ele.first;
                break;
            }
        return ans;
    }   
};
// Logic-2
// Bit manipulation
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) 
//     {
//         int result = 0; 
//         int x, sum; 
//         for (int i = 0; i < 32; i++) 
//         {
//             sum = 0; 
//             x = (1 << i); 
//             for (int j = 0; j < nums.size(); j++) 
//             { 
//                 if (nums[j] & x) 
//                     sum++; 
//             } 
//             if ((sum % 3) != 0) 
//                 result |= x; 
//         } 
//         return result; 
//     }
// };
  
int main()
{
    // https://leetcode.com/problems/single-number-ii/submissions/
    return 0;
}