#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        for(auto ele:nums1)
            v.push_back(ele);
        for(auto ele:nums2)
            v.push_back(ele);
        sort(v.begin(),v.end());
        int n=v.size();
        if(n%2!=0)
            return v[n/2];
        return (v[(n/2)-1]+v[(n/2)])/(double)2;
    }
};
// Logic-2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size(),i=0,j=0;
        vector<int> v;
        while(i<n1 && j<n2)
        {
            if(nums1[i]<=nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1)
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j<n2)
        {
            v.push_back(nums2[j]);
            j++;
        }
        int n=v.size();
        if(n%2!=0)
            return v[n/2];
        return (v[(n/2)-1]+v[(n/2)])/(double)2;
    }
};
int main()
{
    // https://leetcode.com/problems/median-of-two-sorted-arrays
    return 0;
}