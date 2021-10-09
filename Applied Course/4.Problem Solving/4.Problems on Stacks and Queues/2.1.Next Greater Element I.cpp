#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        stack<int> stk;
        int n1=nums1.size(),n2=nums2.size();
        for(int i=n2-1;i>=0;i--)
        {
            int curr=nums2[i];
            
            while(!stk.empty() && stk.top()<=curr)
                stk.pop();
            int nextGreatest=stk.empty()?-1:stk.top();
            stk.push(curr);
            map[curr]=nextGreatest;
        }
        vector<int> res(n1,-1);
        for(int i=0;i<n1;i++){
            res[i]=map[nums1[i]];
        }
        return res;
    }
};
int main()
{
    // https://leetcode.com/problems/next-greater-element-i
    return 0;
}