#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int r,int c,int nr,int nc)
    {
        grid[r][c]='0';
        if(r-1>=0 and grid[r-1][c]=='1')
            dfs(grid,r-1,c,nr,nc);
        if(r+1<nr and grid[r+1][c]=='1')
            dfs(grid,r+1,c,nr,nc);
        if(c-1>=0 and grid[r][c-1]=='1')
            dfs(grid,r,c-1,nr,nc);
        if(c+1<nc and grid[r][c+1]=='1')
            dfs(grid,r,c+1,nr,nc);
    }
    int numIslands(vector<vector<char>>& grid) {
        int nr=grid.size();
        if(nr==0)
            return 0;
        int nc=grid[0].size();
        int num_islands=0;
        for(int r=0;r<nr;r++)
        {
            for(int c=0;c<nc;c++)
            {
                if(grid[r][c]=='1')
                {
                    dfs(grid,r,c,nr,nc);
                    num_islands++;
                }
            }
        }
        return num_islands;
    }
};
int main()
{
    // https://leetcode.com/problems/number-of-islands
    return 0;
}