#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        bool dp[n][n];
        int cnt = 0;

        for (int g = 0; g < n; g++) 
        { 
            // Traversing by diagonal
            for (int i = 0, j = g; j < n; i++, j++) 
            {
                if (g == 0) 
                    dp[i][j] = true;  // Trivial case 
                else if (g == 1) 
                { // Trivial case
                    dp[i][j] = s[i] == s[j];
                }
                else 
                {
                    if (s[i] == s[j] && dp[i + 1][j - 1] == true) 
                        dp[i][j] = true;
                    else 
                        dp[i][j] = false;
                }
                if (dp[i][j]) 
                    cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    // https://leetcode.com/problems/palindromic-substrings/
    return 0;
}