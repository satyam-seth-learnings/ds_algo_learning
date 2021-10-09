# https://leetcode.com/problems/longest-palindromic-subsequence/
# Logic-1 DP
class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s) 
        dp = [[0 for x in range(n)] for x in range(n)] 
        for i in range(n): 
            dp[i][i] = 1    
        for x in range(2, n+1): 
            for i in range(n-x+1): 
                j = i+x-1
                if s[i] == s[j] and x == 2: 
                    dp[i][j] = 2
                elif s[i] == s[j]: 
                    dp[i][j] = dp[i+1][j-1] + 2
                else: 
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j])
        return dp[0][n-1] 
# Logic-2 Recursion
def longestPalindromicSubsequnce(s,i,j):
    if i==j:
        return 1
    if s[i]==s[j] and i+1==j:
        return 2
    if s[i]==s[j]:
        return longestPalindromicSubsequnce(s,i+1,j-1)
    
    return max(longestPalindromicSubsequnce(s,i+1,j),longestPalindromicSubsequnce(s,i,j-1))