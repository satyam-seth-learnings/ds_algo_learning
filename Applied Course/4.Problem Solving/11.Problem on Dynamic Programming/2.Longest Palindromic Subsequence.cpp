#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        int LPS[n+1][n+1];
        for(int i=0;i<n;i++)
		    LPS[i][i]=1;
        for(int ls=2;ls<=n;ls++)
        {
            for(int i=0;i<=n-ls;i++)
            {
                int j=i+ls-1;
                if(s[i]==s[j] && ls==2)
                    LPS[i][j]=2;
                else if(s[i]==s[j])
                    LPS[i][j]=LPS[i+1][j-1]+2;
                else
                    LPS[i][j]=max(LPS[i][j-1],LPS[i+1][j]);
            }
        }
        return LPS[0][n-1];
    }
};
int main()
{
    // https://leetcode.com/problems/longest-palindromic-subsequence/
    return 0;
}