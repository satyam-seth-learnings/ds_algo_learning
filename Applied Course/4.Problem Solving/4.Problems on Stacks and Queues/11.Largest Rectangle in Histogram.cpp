#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area=0,index=0;
        while(index<heights.size())
        {
            if(s.empty() || heights[index]>=heights[s.top()])
            {
                s.push(index);
                index+=1;
            }
            else
            {
                int top_of_stack=s.top();
                s.pop();
                int current_area=heights[top_of_stack]*(!s.empty()?(index-s.top()-1):index);
                max_area=max(current_area,max_area);
            }
        }
        while(!s.empty())
        {
            int top_of_stack=s.top();
            s.pop();
            int current_area=heights[top_of_stack]*(!s.empty()?(index-s.top()-1):index);
            max_area=max(current_area,max_area);
        }
        return max_area;
    }
};
int main()
{
    // https://leetcode.com/problems/largest-rectangle-in-histogram/
    return 0;
}