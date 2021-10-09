#include<bits/stdc++.h>
using namespace std;
// Logic-1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        set<int> row,col;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(matrix[i][j]==0)
                {
                    row.insert(i);
                    col.insert(j);
                }
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                if(row.find(i)!=row.end() || col.find(j)!=col.end())
                    matrix[i][j]=0;
    }
};
// Logic-2
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowFlag=false,colFlag=false;
        int row=matrix.size(),col=matrix[0].size();
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i==0 && matrix[i][j]==0)
                    rowFlag=true;
                if(j==0 && matrix[i][j]==0)
                    colFlag=true;
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<row;i++)
            for(int j=1;j<col;j++)
                if(matrix[i][0]==0 || matrix[0][j]==0)
                    matrix[i][j]=0;
        if(rowFlag==true)
            for(int i=0;i<col;i++)
                matrix[0][i]=0;
        if(colFlag==true)
            for(int j=0;j<row;j++)
                matrix[j][0]=0;
    }
};
int main()
{
    // https://leetcode.com/problems/set-matrix-zeroes/
    return 0;
}