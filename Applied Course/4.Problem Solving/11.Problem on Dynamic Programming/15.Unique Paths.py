# https://leetcode.com/problems/unique-paths/
# Logic-1 Recursion T(n)=O(2^(m*n))
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        if m==1 or n==1:
            return 1
        return self.uniquePaths(m-1,n)+self.uniquePaths(m,n-1);
# Logic-2 DP T(n)=O(mn)
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp=[[1]*n for _ in range(m)]
        for col in range(1,m):
            for row in range(1,n):
                dp[col][row]=dp[col-1][row]+dp[col][row-1]
        return dp[m-1][n-1]