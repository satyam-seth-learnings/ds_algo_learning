#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> v(k);
        unordered_map<string,int> m;
        auto compare=[](pair<string,int> x,pair<string,int> y)
        {
            if(x.second==y.second)
                return x.first.compare(y.first)<0;
            else
                return x.second>y.second;
        };
        priority_queue<pair<string,int>,vector<pair<string,int>>,decltype(compare)> min_heap(compare);
        for(auto ele:words)
            m[ele]++;
        for(auto ele:m)
        {
            min_heap.push({ele.first,ele.second});
            if(min_heap.size()>k)
                min_heap.pop();
        }
        int index=k-1;
        while(!min_heap.empty())
        {
            v[index--]=min_heap.top().first;
            min_heap.pop();
        }
        return v;
    }
};
int main()
{
    // https://leetcode.com/problems/top-k-frequent-words/
    return 0;
}