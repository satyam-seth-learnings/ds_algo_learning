#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),count=0;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(grid[i][j]<0)
                    count++;
        return count;
    }
};
// Logic-2
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),count=0;
        for(int i=r-1;i>=0;i--)
            for(int j=0;j<c;j++)
                if(grid[i][j]<0)
                {
                    count+=(c-j);
                    break;
                }
        return count;
    }
};
int main()
{
    // https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/
    return 0;
}