#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     bool isMatch(string s, string p) {
        
        bool dp[p.length()+1][s.length()+1];
        
        for (int i=0; i <= p.length();i++)
        {
            for (int j=0;j <= s.length();j++)
            {
                dp[i][j]=false;
            }
        }
        
        dp[0][0] = true;
        
        //To handle cases where first one is *
        for (int i=0;i <= p.length();i++)
        {
            for (int j=0;j <= s.length();j++)
            {    
                if (p[i] == '*' && j==0)
                {
                    dp[i+1][j] = dp[i][j];
                }
                 if (s[j] == '*' && i==0)
                {
                    dp[i][j+1] = dp[i][j];
                }
            }
        }
        
        
        for (int i=1; i <= p.length();i++)
        {
            for (int j=1;j <= s.length();j++)
            {
                if (s[j-1] == p[i-1] ||
                    s[j-1] == '?' ||
                    p[i-1]=='?')
                {
                    dp[i][j] = dp[i-1][j-1];   
                }
                else if(s[j-1] == '*'  || p[i-1]=='*')
                {
                    dp[i][j] = (dp[i-1][j-1] || dp[i][j-1]|| dp[i-1][j]);
                }
                
            }
        }
        
        
        return dp[p.length()][s.length()];
    }
};
int main()
{
    // https://leetcode.com/problems/wildcard-matching
    return 0;
}