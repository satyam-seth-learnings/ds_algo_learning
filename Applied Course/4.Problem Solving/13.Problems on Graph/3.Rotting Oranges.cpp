#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    int x[4]={1,-1,0,0};
    int y[4]={0,0,1,-1};
    void neighbour(int r,int s,vector<vector<int>>&grid, queue<pair<int,int>>&q)
    {
        for(int k=0;k<4;k++)
        {
            if(r+x[k]>=0 && s+y[k]>=0 && r+x[k]<grid.size() && s+y[k]<grid[0].size() && grid[r+x[k]][s+y[k]]==1)
            {
              q.push({r+x[k],s+y[k]});
              grid[r+x[k]][s+y[k]]=2;
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int time=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        int count=q.size();
        while(count>0)
        {
            for(int i=0;i<count;i++)
            {
            int r=q.front().first;
            int s=q.front().second;
            q.pop();
            neighbour(r,s,grid,q);
            }
            count=q.size();
            if(count>0) time++;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};
// Logic-2
class Solution {
public:
int orangesRotting(vector<vector<int>>& grid)  {

	 int n = grid.size(), m = grid[0].size();
	 queue <pair <int, int>> q;
	 int fresh = 0;
	 for(int i = 0; i < n; i++) {
	 	for(int j = 0; j < m; j++) {
	 		if(grid[i][j] == 2) {
	 			q.push({i, j});
	 		} else if(grid[i][j] == 1) {
	 			fresh++;
	 		}
	 	}
	 }

	 int dX[] = {0, 0, 1, -1};
	 int dY[] = {1, -1, 0, 0};
	 int total_time = 0;

	 while(!q.empty()) {
	 	if(!fresh)	break;
	 	int sz = q.size();
	 	total_time++;
	 	while(sz--) {
	 		auto cur = q.front();
	 		q.pop();
	 		for(int dir = 0; dir < 4; dir++) {
	 			int nX = cur.first + dX[dir], nY = cur.second + dY[dir];
	 			if(nX >= 0 && nX < n && nY >= 0 && nY < m && grid[nX][nY] == 1) {
	 				fresh--;
                			grid[nX][nY] = 2;
	 				q.push({nX, nY});
	 			}
	 		}	
	 	}
	 }
	 return (fresh ? -1 : total_time);
    }
};
int main()
{
    // https://leetcode.com/problems/rotting-oranges
    return 0;
}