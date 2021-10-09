#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size(),cols=board[0].size();
        int neighbors={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        vector<vector<int> > copy_board(board);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int live_neighbors=0;
                for(int k=0;k<8;k++)
                {
                    int r=i+neighbors[k][0];
                    int c=j+neighbors[k][1];
                    if((r<rows and r>=0) && (c<cols and c>=0) && copy_board[r][c]==1)
                        live_neighbors++;
                }
                if(copy_board[row][col]==1 && (live_neighbors<2 || live_neighbors>3))
                    board[row][col]=0;
                if(copy_board[row][col]==0 && live_neighbors==3)
                    board[row][col]=1;
            }
        }
    }
};
// Logic-2
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size(),cols=board[0].size();
        int neighbors[][8]={{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int live_neighbors=0;
                for(int k=0;k<8;k++)
                {
                    int r=i+neighbors[k][0];
                    int c=j+neighbors[k][1];
                    if((r<rows && r>=0) && (c<cols && c>=0) && abs(board[r][c])==1)
                        live_neighbors++;
                }
                if(board[i][j]==1 && (live_neighbors<2 || live_neighbors>3))
                    board[i][j]=-1;
                if(board[i][j]==0 && live_neighbors==3)
                    board[i][j]=2;
            }
        }
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(board[i][j]>0)
                    board[i][j]=1;
                else
                    board[i][j]=0;
            }
        }
    }
};
int main()
{
    // # https://leetcode.com/problems/game-of-life/
    return 0;
}