#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(char ch:tasks)
            m[ch]++;
        priority_queue<int> max_heap;
        for(auto p:m)
            max_heap.push(p.second);
        int result=0;
        while(!max_heap.empty())
        {
            int time=0;
            vector<int> temp;
            for(int i=0;i<n+1;i++)
            {
                if(!max_heap.empty())
                {
                    temp.push_back(max_heap.top()-1);
                    max_heap.pop();
                    time++;
                }
            }
            for(auto t:temp)
                if(t)
                    max_heap.push(t);
            result+=max_heap.empty()?time:n+1;
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/task-scheduler
    return 0;
}