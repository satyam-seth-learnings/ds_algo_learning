#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> q;
        unordered_set<int> s;
        for(int n: nums)
        {
            if(!s.count(n)) 
            {
                q.push(n);
                if(q.size()>3)
                    q.pop();
                s.insert(n);
            }
        }
        if(q.size()==2) 
            q.pop();
        return q.top();
    }
};
// Logic-2
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st;
        for(int n : nums) 
        {
            st.insert(n);
            if(st.size() > 3) 
                st.erase(st.begin());
        }
        if(st.size() == 3) 
            return *st.begin();
        return *(--st.end());
    }
};
int main()
{
    // https://leetcode.com/problems/third-maximum-number/$
    return 0;
}