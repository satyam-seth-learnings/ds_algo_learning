#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.empty())
            return 0;
        sort(points.begin(),points.end());
        int arrows=1;
        int currentEnd=points[0][1];
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]<=currentEnd)
                currentEnd=min(currentEnd,points[i][1]);
            else
            {
                arrows++;
                currentEnd=points[i][1];
            }
        }
        return arrows;
    }
};
int main()
{
    // https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
    return 0;
}