#include<bits/stdc++.h>
using namespace std;
class Solution {
public:int largestRectangleArea(vector<int>& heights) {
        vector<int> rl(heights.size(),heights.size());
        vector<int> ll(heights.size(),0);
        stack<int> temp;
        for(int i=0;i<heights.size();i++)
        {
            while(!temp.empty()&&heights[temp.top()]>heights[i])
            {
                rl[temp.top()]=i;
                temp.pop();
            }
            temp.push(i);
        }
        
        stack<int> temp1;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!temp1.empty()&&heights[temp1.top()]>heights[i])
            {
                ll[temp1.top()]=i+1;
                temp1.pop();
            }
            temp1.push(i);
        }
        int ans=0;
        for(int i=0;i<rl.size();i++)
        {
            ans=max(ans, heights[i]*(rl[i]-ll[i]));   
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<vector<int>>vec(matrix.size(),vector<int>(matrix[0].size(),0));
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i==0)
                    vec[i][j]=matrix[i][j]-'0';
                else{
                    if(matrix[i][j]=='1')
                        vec[i][j]=1+vec[i-1][j];
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<vec.size();i++)
        {
            ans=max(ans,largestRectangleArea(vec[i]));
        }
        return ans;
    }
};
int main()
{
    // https://leetcode.com/problems/maximal-rectangle
    return 0;
}