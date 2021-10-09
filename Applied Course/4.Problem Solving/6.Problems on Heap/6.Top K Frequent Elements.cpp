#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        vector<pair<int,int>> v(mp.begin(),mp.end());
        vector<int> result;
        sort(v.begin(),v.end(),[](pair<int,int> p1,pair<int,int> p2){return p1.second>p2.second;});
        int i=0;
        while(k--)
            result.push_back(v[i++].first);
        return result;
    }
};
// Logic-2
class Solution {
public: 
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>min_heap;
        for(auto i:mp)
        {
            min_heap.push({i.second,i.first});
            if(min_heap.size()>k)
                min_heap.pop();
        }
        vector<int> result;
        while(min_heap.size())
        {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/top-k-frequent-elements
    return 0;
}