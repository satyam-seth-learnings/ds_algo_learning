#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool solve(vector<vector<char>>& board, int r, int c, int R, int C, string word, int idx){
        if(word.size() == idx) 
            return true;
        if(r<0 || r>=R || c<0 || c>=C || board[r][c]=='$' || board[r][c]!=word[idx]) 
            return false;
        char ch = board[r][c];
        board[r][c] ='$';
        int ans=false;
        if(solve(board, r+1,c,R,C,word, idx+1) || solve(board, r-1,c,R,C,word, idx+1) || solve(board, r,c+1,R,C,word, idx+1) || solve(board, r,c-1,R,C,word, idx+1))
                ans = true;
        board[r][c] = ch;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int ROW = board.size(), COL= board[0].size();
        if(ROW*COL< word.size()) 
            return 0;        
        for(int i=0;i<ROW;i++){
            for(int j=0;j<COL;j++){
                if(board[i][j] == word[0]){
                    if(solve(board, i,j, ROW, COL, word, 0)) 
                        return true;
                }
            }
        }
        return false;
    }
};
int main()
{
    // https://leetcode.com/problems/word-search
    return 0;
}