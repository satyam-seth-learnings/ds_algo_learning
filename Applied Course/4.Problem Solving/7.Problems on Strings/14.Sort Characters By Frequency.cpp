#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for(char c:s)
            m[c]++;
        priority_queue<pair<int,char>> max_heap;
        for(auto p:m)
            max_heap.push({p.second,p.first});
        string result;
        while(!max_heap.empty())
        {
            pair<int,char> temp=max_heap.top();
            max_heap.pop();
            while(temp.first--)
                result+=temp.second;
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/sort-characters-by-frequency
    return 0;
}