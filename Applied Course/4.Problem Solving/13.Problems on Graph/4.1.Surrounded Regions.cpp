#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        // if it is not O return
        if(board[i][j]!='O')
            return;
        
        board[i][j]='R';
        // check up
        if(i>0)
            dfs(board,i-1,j);
        //check down
        if(i<board.size()-1){
            dfs(board, i+1,j);
        }
        //check left
        if(j>0)
            dfs(board,i,j-1);
        //check right
        if(j<board[0].size()-1){
            dfs(board,i,j+1);
        }
        
    }
    void solve(vector<vector<char>>& board) {
        
        // check row's first n last element
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O'){
                dfs(board, i, 0);
            }
            if(board[i][board[0].size()-1]=='O'){
                dfs(board, i, board[0].size()-1);
            }
        }
        
        //check column's top and bottom
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O')
                dfs(board, 0, j);
            if(board[board.size()-1][j]=='O')
                dfs(board, board.size()-1,j);
        }
        
        // Now replace O by X and R by O
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
                if(board[i][j]=='R')
                    board[i][j]='O';
            }
        } 
    }
};

int main()
{
    // https://leetcode.com/problems/surrounded-regions/
    return 0;
}