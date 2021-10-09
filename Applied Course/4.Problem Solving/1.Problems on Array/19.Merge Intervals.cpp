#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool static compareInterval(vector<int>& x,vector<int>& y)
    {
        return (x[0]<y[0]);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        stack<vector<int> > s;
        sort(intervals.begin(),intervals.end(),compareInterval);
        s.push(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            vector<int> t=s.top();
            if(t[1]<intervals[i][0])
                s.push(intervals[i]);
            else if(t[1]<intervals[i][1])
            {
                t[1]=intervals[i][1];
                s.pop();
                s.push(t);
            }
        }
        intervals.clear();
        while(!s.empty()) 
        {
            vector<int> t=s.top(); 
            intervals.push_back(t);
            s.pop(); 
        } 
        return intervals;
    }
};
int main()
{
    // https://leetcode.com/problems/merge-intervals
    return 0;
}