#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max=0;
        int i=0,j=height.size()-1;
        while(i<j)
        {
            int area=(j-i)*min(height[i],height[j]);
            if(max<area)
                max=area;
            if(height[i]<height[j])
                i++;
            else
                j--;
        }
        return max;
    }
};
int main()
{
    // https://leetcode.com/problems/container-with-most-water/
    return 0;
}