#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r=mat.size(),c=mat[0].size();
        vector<pair<int,int> > v;
        vector<int> result;
        for(int i=0;i<r;i++)
        {
            int count=accumulate(mat[i].begin(),mat[i].end(),0);
            v.push_back({count,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
            result.push_back(v[i].second);
        return result;
    }
};
// Logic-2
class Solution {
public:
    int binarySearch(vector<int>& row)
    {
        int low=0,high=row.size();
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(row[mid]==1)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r=mat.size(),c=mat[0].size();
        vector<pair<int,int> > v;
        vector<int> result;
        for(int i=0;i<r;i++)
        {
            int count=binarySearch(mat[i]);
            v.push_back({count,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
            result.push_back(v[i].second);
        return result;
    }
};
// Logic-3
class Solution {
public:
    int binarySearch(vector<int>& row)
    {
        int low=0,high=row.size();
        while(low<high)
        {
            int mid=low+(high-low)/2;
            if(row[mid]==1)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r=mat.size(),c=mat[0].size();
        priority_queue<pair<int,int> > q;
        vector<int> result;
        for(int i=0;i<r;i++)
        {
            int count=binarySearch(mat[i]);
            q.push({count,i});
            if(q.size()>k)
                q.pop();
        }
        while(q.size())
        {
            int ele=q.top().second;
            result.push_back(ele);
            q.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
    return 0;
}