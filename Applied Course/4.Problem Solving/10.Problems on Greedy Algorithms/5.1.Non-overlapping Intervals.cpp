#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static bool comp(vector<int> a,vector<int> b)
    {
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int count=1;
        int last=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {
            if(last<=intervals[i][0])
            {
                count++;
                last=intervals[i][1];
            }
        }
        return intervals.size()-count;
    }
};
int main()
{
    // https://leetcode.com/problems/non-overlapping-intervals/
    return 0;
}