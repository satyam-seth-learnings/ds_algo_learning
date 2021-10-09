#include<bits/stdc++.h>
using namespace std;
// Logic-1 O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int result=0;
        for(int i=1;i<n-1;i++)
        {
            int left=height[i];
            for(int j=0;j<i;j++)
                left=max(left,height[j]);
            int right=height[i];
            for(int j=i+1;j<n;j++)
                right=max(right,height[j]);
            result=result+min(left,right)-height[i];
        }
        return result;
    }
};
// Logic-2 O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
            return 0;
        int result=0;
        vector<int> left,right;
        left.push_back(height[0]);
        for(int i=1;i<n;i++)
            left.push_back(max(left[i-1],height[i]));
        right.push_back(height[n-1]);
        for(int i=n-2;i>=0;i--)
            right.push_back(max(right[n-2-i],height[i]));
        for(int i=0;i<n;i++)
            result+=min(left[i],right[n-i-1])-height[i];
        return result;
    }
};
// Logic-3 O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int result=0;
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && height[i]>height[s.top()])
            {
                int top_ele=s.top();
                s.pop();
                if(s.empty())
                    break;
                int distance=i-s.top()-1;
                int bounded_height=min(height[i],height[s.top()])-height[top_ele];
                result+=(distance*bounded_height);
            }
            s.push(i);
        }
        return result;
    }
};
// Logic-4 O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left_max=0,right_max=0,left=0,right=n-1,result=0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(height[left]>=left_max)
                    left_max=height[left];
                else
                    result+=(left_max-height[left]);
                left+=1;
            }
            else
            {
                if(height[right]>=right_max)
                    right_max=height[right];
                else
                    result+=(right_max-height[right]);
                right-=1;
            }
        }
        return result;
    }
};
int main()
{
    // https://leetcode.com/problems/trapping-rain-water
    return 0;
}