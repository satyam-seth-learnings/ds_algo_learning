#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prod;
        for(int i=0;i<nums.size();i++)
        {
            int L=1,R=1;
            for(int j=0;j<i;j++)
                L*=nums[j];
            for(int j=i+1;j<nums.size();j++)
                R*=nums[j];
            prod.push_back(L*R);
        }
        return prod;
    }
};
// Logic-2
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int L[n],R[n];
        vector<int> prod;
        L[0]=1;
        for(int i=1;i<n;i++)
            L[i]=L[i-1]*nums[i-1];
        R[n-1]=1;
        for(int i=n-2;i>=0;i--)
            R[i]=R[i+1]*nums[i+1];
        for(int i=0;i<n;i++)
            prod.push_back(L[i]*R[i]);
        return prod;
    }
};
// Logic-3
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int L=1,R=1;
        vector<int> prod;
        prod.push_back(1);
        for(int i=1;i<n;i++)
            prod.push_back(prod[i-1]*nums[i-1]);
        for(int i=n-1;i>=0;i--)
        {
            prod[i]*=R;
            R*=nums[i];
        }
        return prod;
    }
};
int main()
{
    // https://leetcode.com/problems/product-of-array-except-self/
    return 0;
}