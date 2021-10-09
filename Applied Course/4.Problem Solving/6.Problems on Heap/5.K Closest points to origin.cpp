#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        sort(points.begin(),points.end(),[](vector<int> v1,vector<int> v2){return (v1[0]*v1[0]+v1[1]*v1[1])<(v2[0]*v2[0]+v2[1]*v2[1]);});
        for(int i=0;i<k;i++)
            v.push_back(points[i]);
        return v;
    }
};
// Logic-2
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> v;
        priority_queue<pair<int,vector<int>>> max_heap;
        for(int i=0;i<points.size();i++)
        {
            max_heap.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],points[i]});
            if(max_heap.size()>k)
                max_heap.pop();
        }
        while(max_heap.size())
        {
            v.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return v;
    }
};
int main()
{
    // https://leetcode.com/problems/k-closest-points-to-origin
    return 0;
}