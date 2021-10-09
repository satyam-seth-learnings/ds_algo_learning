#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double dp[27][27][102];
    int dx[8] = {-2,-2,-1,1,2,2,1,-1};
    int dy[8] = {-1,1,2,2,1,-1,-2,-2};
    int boardsize;
   double getpaths(int i,int j,int k)
   {
        if(k == 0) 
            return 1;
        if(dp[i][j][k] != -1) 
            return dp[i][j][k];
        double aux = 0.0;
        for(int l=0;l<8;l++)
        {
            int ni = i+dx[l];
            int nj = j+dy[l];
            if(ni>=0 && ni<boardsize && nj>=0 && nj<boardsize)
                aux+=getpaths(ni,nj,k-1)/8;
        }
        dp[i][j][k] = aux;
        return dp[i][j][k];
    }
    double knightProbability(int n, int k, int row, int column) {
        for(int i=0;i<27;i++)
            for(int j=0;j<27;j++)
                for(int k=0;k<102;k++)
                    dp[i][j][k] = -1;
        boardsize = n;
        return getpaths(row,column,k); 
    }
};
int main()
{
    // https://leetcode.com/problems/knight-probability-in-chessboard/
    return 0;
}