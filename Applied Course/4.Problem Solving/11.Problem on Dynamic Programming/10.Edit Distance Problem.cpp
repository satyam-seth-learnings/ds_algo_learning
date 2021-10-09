#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int dp[501][501]={0};
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0)
                    dp[i][j]=j;
                else if(j==0)
                    dp[i][j]=i;
                else 
                {
                    if(word1[i-1]==word2[j-1])
                        dp[i][j]=dp[i-1][j-1];
                    else
                    {
                        int add=dp[i][j-1];
                        int replace=dp[i-1][j-1];
                        int remove=dp[i-1][j];   
                        dp[i][j]=1+min(min(add,replace),remove);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
int main()
{
    // https://leetcode.com/problems/edit-distance
    return 0;
}